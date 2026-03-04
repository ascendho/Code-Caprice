// 题目链接：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 1. 创建虚拟头节点，统一处理头节点被删除的边界情况
        ListNode *dummy = new ListNode(0, head);

        // 2. 初始化栈：利用栈的“后进先出”特性，存储所有节点（包括虚拟头）
        stack<ListNode *> stk;
        ListNode *cur = dummy; // 遍历指针，初始指向虚拟头节点

        // 3. 将链表所有节点依次入栈
        while (cur)
        {
            stk.push(cur);   // 当前节点入栈
            cur = cur->next; // 指针后移，遍历下一个节点
        }

        // 4. 弹出栈顶n个节点：此时栈顶即为要删除节点的前驱节点
        // （栈底是dummy，栈顶是原链表尾节点，弹出n个后，栈顶是倒数第n+1个节点）
        for (int i = 0; i < n; ++i)
        {
            stk.pop();
        }

        // 5. 获取要删除节点的前驱节点
        ListNode *prev = stk.top();

        // 6. 删除目标节点：跳过要删除的节点，修改前驱节点的next指针
        prev->next = prev->next->next;

        // 7. 保存新链表头节点（避免delete dummy后指针失效）
        ListNode *ans = dummy->next;

        // 8. 释放虚拟头节点内存，避免内存泄漏（工程开发必备）
        delete dummy;
        dummy = nullptr; // 置空，避免悬空指针

        // 9. 返回删除节点后的新链表头节点
        return ans;
    }
};