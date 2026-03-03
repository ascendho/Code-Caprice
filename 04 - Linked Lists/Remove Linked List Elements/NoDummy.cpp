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
        // 第一步：处理头节点需要被删除的情况（头节点可能连续多个等于val）
        // 用while而非if：因为删除头节点后，新的头节点可能仍等于val（比如链表[2,2,3]，val=2）
        while (head != NULL && head->val == val)
        {
            // 保存当前要删除的头节点（避免删除后指针丢失）
            ListNode *tmp = head;
            // 将头节点后移一位，指向新的候选头节点
            head = head->next;
            // 释放被删除的头节点内存，避免内存泄漏
            delete tmp;
            // 置空临时指针，避免悬空指针
            tmp = nullptr;
        }

        // 第二步：处理非头节点的删除（此时头节点一定不等于val或为NULL）
        // cur指针用于遍历链表，初始指向新的头节点
        ListNode *cur = head;
        // 循环条件：cur不为空（避免空指针访问）且cur的下一个节点不为空（有节点可检查）
        while (cur != NULL && cur->next != NULL)
        {
            // 如果cur的下一个节点值等于目标值，需要删除该节点
            if (cur->next->val == val)
            {
                // 保存要删除的节点地址
                ListNode *tmp = cur->next;
                // 跳过被删除节点：cur的next指向被删节点的下一个节点
                cur->next = cur->next->next;
                // 释放被删除节点的内存
                delete tmp;
                // 置空临时指针
                tmp = nullptr;
            }
            else
            {
                // 下一个节点无需删除，cur指针后移一位
                cur = cur->next;
            }
        }
        // 返回处理后的链表头节点（可能为NULL，比如链表所有节点都被删除）
        return head;
    }
};