// 题目链接：https://leetcode.cn/problems/design-linked-list/

// 单链表节点的结构体定义
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class MyLinkedList
{
public:
    // 构造函数：初始化链表
    MyLinkedList()
    {
        this->size = 0;               // 初始化链表长度为0
        this->head = new ListNode(0); // 创建虚拟头节点，值为0，简化边界操作
    }

    // 获取链表中下标为 index 的节点的值。如果下标无效，返回 -1
    int get(int index)
    {
        // 检查下标是否越界
        if (index < 0 || index >= size)
        {
            return -1;
        }
        ListNode *cur = head; // 从虚拟头节点开始遍历
        // 循环 index + 1 次，到达目标节点（虚拟头节点占了一次）
        for (int i = 0; i <= index; i++)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    // 在链表头部添加一个值为 val 的节点
    void addAtHead(int val)
    {
        addAtIndex(0, val); // 直接复用 addAtIndex 函数，在索引0处插入
    }

    // 在链表尾部添加一个值为 val 的节点
    void addAtTail(int val)
    {
        addAtIndex(size, val); // 直接复用 addAtIndex 函数，在索引size处插入（即末尾）
    }

    // 在链表中下标为 index 的节点之前插入值为 val 的节点
    // 如果 index 等于链表长度，则追加到末尾；如果 index 大于长度，不插入
    void addAtIndex(int index, int val)
    {
        // 如果下标大于链表长度，直接返回，不插入
        if (index > size)
        {
            return;
        }
        // 如果下标小于0，修正为0（插入到头部）
        index = max(0, index);
        size++; // 链表长度增加1

        ListNode *pred = head; // pred 指向插入位置的前驱节点
        // 找到第 index 个节点的前驱节点
        for (int i = 0; i < index; i++)
        {
            pred = pred->next;
        }
        // 创建新节点
        ListNode *toAdd = new ListNode(val);
        // 插入节点：新节点的 next 指向原前驱节点的 next
        toAdd->next = pred->next;
        // 前驱节点的 next 指向新节点
        pred->next = toAdd;
    }

    // 如果下标有效，删除链表中下标为 index 的节点
    void deleteAtIndex(int index)
    {
        // 检查下标是否越界
        if (index < 0 || index >= size)
        {
            return;
        }
        size--; // 链表长度减少1

        ListNode *pred = head; // pred 指向删除位置的前驱节点
        // 找到第 index 个节点的前驱节点
        for (int i = 0; i < index; i++)
        {
            pred = pred->next;
        }
        // 保存要删除的节点指针
        ListNode *p = pred->next;
        // 跳过要删除的节点：前驱节点的 next 指向被删节点的 next
        pred->next = pred->next->next;
        // 释放被删除节点的内存，避免内存泄漏
        delete p;
    }

private:
    int size;       // 链表的节点数量
    ListNode *head; // 链表的虚拟头节点指针
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */