// 题目链接：https://leetcode.cn/problems/reverse-linked-list/

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
    ListNode *reverseList(ListNode *head)
    {
        // prev 指针：记录当前节点的前驱节点，初始化为 nullptr（反转后原头节点变为尾节点，其 next 为 nullptr）
        ListNode *prev = nullptr;
        // curr 指针：记录当前正在处理的节点，初始化为链表头节点
        ListNode *curr = head;

        // 遍历整个链表，直到 curr 为空（遍历到原链表末尾）
        while (curr != nullptr)
        {
            // 1. 保存后继节点：
            // 先把 curr 的下一个节点保存到 next 指针中，
            // 因为下一步要修改 curr->next，若不保存就会丢失后续链表的引用
            ListNode *next = curr->next;

            // 2. 反转指针：
            // 将当前节点 curr 的 next 指针指向前驱节点 prev，完成当前节点的反转
            curr->next = prev;

            // 3. 指针后移，为下一轮迭代做准备：
            // prev 指针后移到当前节点 curr
            prev = curr;
            // curr 指针后移到之前保存的 next 节点
            curr = next;
        }

        // 当循环结束时，curr 为 nullptr，prev 指向原链表的最后一个节点，也就是反转后新链表的头节点
        return prev;
    }
};