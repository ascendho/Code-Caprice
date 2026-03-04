// 题目链接：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x, next(nullptr)) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 创建虚拟头节点 dummy，值为0，next指针指向原链表头节点
        // 作用：统一处理头节点需要被删除的特殊情况，避免额外的边界判断
        ListNode *dummy = new ListNode(0, head);

        // 定义快慢指针，初始都指向虚拟头节点
        ListNode *fast = dummy, *slow = dummy; // 快指针，用于先向前移动

        // 第一步：快指针先移动 n 步
        // 这样快指针和慢指针之间就保持了 n 个节点的间距
        while (n--)
        {
            fast = fast->next;
        }

        // 第二步：快慢指针同时移动，直到快指针到达链表末尾
        // 此时，慢指针恰好停在要删除节点的前一个节点
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // 第三步：删除目标节点
        // 将慢指针的 next 指针直接指向它下下个节点，从而跳过要删除的节点
        slow->next = slow->next->next;

        // 保存新的头节点（虚拟头节点的下一个节点）
        ListNode *ans = dummy->next;
        // 释放虚拟头节点的内存，避免内存泄漏（算法题中可省略，但工程中必须添加）
        delete dummy;
        dummy = nullptr; // 置空，避免悬空指针

        // 返回新的链表头节点
        return ans;
    }
};