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
        // 定义哈希表：键=节点指针（唯一标识节点），值=bool（标记是否已访问）
        // 作用和哈希集合完全一致，只是多了一个“标记值”（无实际业务意义）
        unordered_map<ListNode *, bool> visited_map;

        // 遍历链表，直到head为空（无环）
        // 函数参数 ListNode *head 是一个指针的拷贝，而不是原始指针本身。
        // 因此，在函数内部修改 head 的值（如 head = head->next）不会影响到函数外部的原始指针。
        while (head)
        {
            // 检查哈希表中是否存在当前节点（键存在说明已访问过）
            if (visited_map.find(head) != visited_map.end())
                // 存在则说明是环的入口节点，直接返回
                return head;

            // 不存在则将节点存入哈希表，标记为已访问（值设为true即可）
            visited_map[head] = true;

            // 指针后移，访问下一个节点
            head = head->next;
        }

        // 遍历到末尾，无环返回nullptr
        return nullptr;
    }
};