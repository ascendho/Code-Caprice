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
        // 动态创建虚拟头节点
        struct ListNode *dummyHead = new ListNode(0, head);
        struct ListNode *temp = dummyHead;

        while (temp->next != NULL)
        {
            if (temp->next->val == val)
            {
                // 【额外优化】工程中删除节点时也需释放其内存
                // 保存要删除的节点指针，便于后续释放内存
                ListNode *toDelete = temp->next;
                temp->next = temp->next->next;

                // 释放被删除节点的内存
                delete toDelete;
            }
            else
            {
                temp = temp->next;
            }
        }

        // 先保存新的头节点（避免delete后指针失效）
        ListNode *newHead = dummyHead->next;
        delete dummyHead;    // 释放虚拟头节点的内存
        dummyHead = nullptr; // 避免悬空指针

        return newHead;
    }
};