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
        // 定义哈希集合，存储已经访问过的节点指针
        // 核心作用：记录每个节点是否被遍历过，判断是否进入环
        unordered_set<ListNode *> visited;

        // 遍历链表，直到head为空（链表无环，遍历到末尾）
        // 函数参数 ListNode *head 是一个指针的拷贝，而不是原始指针本身。
        // 因此，在函数内部修改 head 的值（如 head = head->next）不会影响到函数外部的原始指针。
        while (head)
        {
            // 检查当前节点是否已在哈希集合中：
            // 1. 若存在：说明遍历到了环的入口节点（第一次重复出现的节点），
            //           直接返回
            // 2. 若不存在：将节点加入集合，继续遍历
            if (visited.count(head))
            {
                return head;
            }

            // 将当前节点加入哈希集合，标记为已访问
            visited.insert(head);
            // 指针后移，访问下一个节点
            head = head->next;
        }

        // 遍历到链表末尾（head为空），说明无环，返回nullptr
        return nullptr;
    }
};