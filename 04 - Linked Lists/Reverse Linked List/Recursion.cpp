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
        // 递归终止条件：
        // 1. head == nullptr：空链表，直接返回空
        // 2. head->next == nullptr：到达链表最后一个节点（反转后的新头节点）
        if (!head || !head->next)
        {
            return head;
        }

        // 递归递推：处理当前节点的下一个节点，直到找到反转后的新头节点
        // newHead 最终会指向原链表的最后一个节点（反转后的新头节点）
        ListNode *newHead = reverseList(head->next);

        // 递归回溯：核心反转逻辑
        // 1. 将当前节点的下一个节点的 next 指针指向当前节点（反转指针）
        // 比如原链表是 1->2->3，此时 head=2，head->next=3，执行后 3->2
        head->next->next = head;
        // 2. 将当前节点的 next 指针置空（避免形成环，同时作为新链表的尾节点）
        // 比如 head=2 时，执行后 2->nullptr；回溯到 head=1 时，执行后 1->2（最终 3->2->1）
        head->next = nullptr;

        // 返回反转后的新头节点（始终是原链表的最后一个节点）
        return newHead;
    }
};

// 以链表 1->2->3->nullptr 为例

// 递的过程（深入到链表末尾）
/*
    reverseList(1) → 调用 reverseList(2)
    reverseList(2) → 调用 reverseList(3)
    reverseList(3) → 触发终止条件（3->next=nullptr），返回 3（newHead=3）
*/

// 归的过程（从末尾往回反转指针）
/*
    // 第一步回溯：处理 head=2
    head->next->next = head → 3->next = 2（链表变为 1->2<-3）
    head->next = nullptr → 2->next = nullptr（链表变为 1->2<-3，2 是临时尾节点）
    返回 newHead=3

    // 第二步回溯：处理 head=1
    head->next->next = head → 2->next = 1（链表变为 1<-2<-3）
    head->next = nullptr → 1->next = nullptr（链表变为 null<-1<-2<-3，1 是最终尾节点）
    返回 newHead=3
*/