// 题目链接：https://leetcode.cn/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 初始化快慢指针，都指向链表头节点
        ListNode *slow = head, *fast = head;

        // 遍历链表，直到快指针到达末尾（无环）或两指针相遇（有环）
        while (fast != nullptr)
        {
            // 慢指针每次走1步
            slow = slow->next;

            // 快指针每次走2步，需要先判断下一个节点是否为空，避免空指针访问
            if (fast->next == nullptr)
            {
                // 如果快指针的下一个节点为空，说明链表无环，直接返回nullptr
                return nullptr;
            }
            else
            {
                fast = fast->next->next;
            }

            // 判断快慢指针是否相遇
            if (fast == slow)
            {
                // 相遇说明链表有环，此时从链表头和相遇点同时出发两个指针
                ListNode *ptr = head;

                // 两个指针每次都走1步，它们相遇的节点就是环的入口点
                while (ptr != slow)
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }

                // 返回环的入口节点
                return ptr;
            }
        }

        // 快指针遍历到链表末尾，说明链表无环，返回nullptr
        return nullptr;
    }
};