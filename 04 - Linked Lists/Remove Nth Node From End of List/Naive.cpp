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
    // 辅助函数：计算链表的总长度
    // 参数head：链表头节点
    // 返回值：链表的节点总数
    int getLength(ListNode *head)
    {
        int length = 0; // 初始化链表长度为0
        // 遍历链表，直到head为空（遍历完所有节点）
        while (head)
        {
            ++length;          // 每遍历一个节点，长度+1
            head = head->next; // 指针后移，访问下一个节点
        }
        return length; // 返回链表总长度
    }

    // 主函数：删除链表的倒数第n个节点
    // 参数head：原链表头节点；n：要删除的倒数节点位置
    // 返回值：删除节点后的新链表头节点
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 创建虚拟头节点dummy，值为0，next指向原头节点
        // 作用：统一处理头节点被删除的边界情况，无需单独判断
        ListNode *dummy = new ListNode(0, head);

        // 第一步：计算链表总长度
        int length = getLength(head);

        // cur指针：用于遍历到要删除节点的前驱节点，初始指向dummy
        ListNode *cur = dummy;

        // 第二步：遍历到要删除节点的前驱节点
        // 核心计算：倒数第n个节点 = 正数第 (length - n + 1) 个节点
        // 循环条件i < (length - n + 1)：让cur停在该节点的前驱位置（第 length-n 个节点）
        for (int i = 1; i < length - n + 1; ++i)
        {
            cur = cur->next; // 指针后移，找到目标前驱节点
        }

        // 第三步：删除目标节点
        // 将cur的next指针指向其下下个节点，跳过要删除的节点
        cur->next = cur->next->next;

        // 保存新链表的头节点（dummy的next），避免delete dummy后指针失效
        ListNode *ans = dummy->next;

        // 释放虚拟头节点的内存，避免内存泄漏（工程必备，算法题可省略）
        delete dummy;
        dummy = nullptr; // 置空，避免悬空指针

        // 返回删除节点后的新链表头节点
        return ans;
    }
};