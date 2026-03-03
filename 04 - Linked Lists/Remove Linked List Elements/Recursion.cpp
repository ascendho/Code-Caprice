// 题目链接：https://leetcode.cn/problems/remove-linked-list-elements/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // 递归终止条件：当前节点为空（遍历到链表末尾），直接返回空
        if (head == nullptr)
        {
            return head;
        }

        // 递归递推：处理当前节点的下一个节点
        // 先把当前节点之后的所有节点处理完，返回处理后的子链表头节点
        head->next = removeElements(head->next, val);

        // 递归回溯：判断当前节点是否需要删除
        if (head->val == val)
        {
            ListNode *temp = head->next; // 保存处理后的子链表头节点
            delete head;                 // 释放当前节点的内存，避免泄漏
            head = nullptr;              // 置空，避免悬空指针
            return temp;                 // 返回下一个节点（删除当前节点）
        }
        else
        {
            return head; // 不删除，返回当前节点
        }
    }
};

/* 递归过程可视化（以链表 [1,2,6,3,6]，val=6 为例）*/

// 递的过程（从前往后）
/*
    removeElements(1,6) → 调用 removeElements(2,6)
    removeElements(2,6) → 调用 removeElements(6,6)
    removeElements(6,6) → 调用 removeElements(3,6)
    removeElements(3,6) → 调用 removeElements(6,6)
    removeElements(6,6) → 调用 removeElements(nullptr,6)
    removeElements(nullptr,6) → 返回 nullptr（终止）
*/

// 归的过程（从后往前）
/*
1. removeElements(6,6)：head->val=6 → 返回 head->next（nullptr），删除该6（工程版本）；
2. removeElements(3,6)：head->val≠6 → 返回3，且3->next = nullptr；
3. removeElements(6,6)：head->val=6 → 返回 head->next（3），删除该6（工程版本）；
4. removeElements(2,6)：head->val≠6 → 返回2，且2->next = 3；
5. removeElements(1,6)：head->val≠6 → 返回1，且1->next = 2；
*/

// 最终结果：[1,2,3]