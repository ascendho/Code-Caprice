// 题目链接：https://leetcode.cn/problems/design-linked-list/

// 双向链表节点结构体定义
struct DLinkListNode
{
    int val;             // 节点存储的值
    DLinkListNode *prev; // 指向前一个节点的指针
    DLinkListNode *next; // 指向后一个节点的指针
    // 节点构造函数：初始化值，前驱/后继指针置空
    DLinkListNode(int _val) : val(_val), prev(nullptr), next(nullptr) {}
};

class MyLinkedList
{
public:
    // 构造函数：初始化双向链表（虚拟头+虚拟尾节点）
    MyLinkedList()
    {
        this->size = 0;                    // 链表实际节点数初始化为0（不含虚拟节点）
        this->head = new DLinkListNode(0); // 创建虚拟头节点（值无意义）
        this->tail = new DLinkListNode(0); // 创建虚拟尾节点（值无意义）
        head->next = tail;                 // 虚拟头的后继指向虚拟尾
        tail->prev = head;                 // 虚拟尾的前驱指向虚拟头
    }

    // 析构函数：补充工程版内存释放（算法题可省略）
    ~MyLinkedList()
    {
        DLinkListNode *cur = head;
        // 遍历释放所有节点（包括虚拟头、虚拟尾和数据节点）
        while (cur != nullptr)
        {
            DLinkListNode *next = cur->next;
            delete cur;
            cur = next;
        }
        size = 0;
        head = tail = nullptr;
    }

    // 获取下标为index的节点值，越界返回-1
    int get(int index)
    {
        // 边界检查：索引小于0或大于等于实际节点数，返回-1
        if (index < 0 || index >= size)
        {
            return -1;
        }
        DLinkListNode *curr; // 用于指向目标节点的临时指针
        // 双向遍历优化：判断从头部还是尾部遍历更近
        // 条件：index+1（从头遍历的步数） < size-index（从尾遍历的步数）
        if (index + 1 < size - index)
        {
            curr = head; // 从头节点开始遍历
            // 遍历index+1次（跳过虚拟头节点），到达目标节点
            for (int i = 0; i <= index; i++)
            {
                curr = curr->next;
            }
        }
        else
        {
            curr = tail; // 从尾节点开始遍历
            // 遍历size-index次（跳过虚拟尾节点），到达目标节点
            for (int i = 0; i < size - index; i++)
            {
                curr = curr->prev;
            }
        }
        return curr->val; // 返回目标节点的值
    }

    // 在链表头部添加节点（复用addAtIndex）
    void addAtHead(int val)
    {
        addAtIndex(0, val); // 直接在索引0处插入（虚拟头后）
    }

    // 在链表尾部添加节点（复用addAtIndex）
    void addAtTail(int val)
    {
        addAtIndex(size, val); // 在索引size处插入（虚拟尾前）
    }

    // 在索引index的节点前插入值为val的节点
    // index>size：不插入；index<0：修正为0；index=size：插入到尾部
    void addAtIndex(int index, int val)
    {
        // 索引超过链表长度，直接返回（不插入）
        if (index > size)
        {
            return;
        }
        // 索引小于0时，修正为0（插入到头部）
        index = max(0, index);

        DLinkListNode *pred, *succ; // pred：插入位置前驱节点；succ：插入位置后继节点
        // 双向遍历优化：找前驱/后继节点时，选择更近的方向
        if (index < size - index)
        {
            pred = head; // 从头遍历找前驱节点
            for (int i = 0; i < index; i++)
            {
                pred = pred->next;
            }
            succ = pred->next; // 前驱的后继即为后继节点
        }
        else
        {
            succ = tail; // 从尾遍历找后继节点
            for (int i = 0; i < size - index; i++)
            {
                succ = succ->prev;
            }
            pred = succ->prev; // 后继的前驱即为前驱节点
        }

        size++;                                        // 实际节点数+1
        DLinkListNode *toAdd = new DLinkListNode(val); // 创建新节点
        // 双向链表插入核心：修改4个指针
        toAdd->prev = pred; // 新节点前驱指向pred
        toAdd->next = succ; // 新节点后继指向succ
        pred->next = toAdd; // pred的后继指向新节点
        succ->prev = toAdd; // succ的前驱指向新节点
    }

    // 删除索引index的节点，索引越界则不操作
    void deleteAtIndex(int index)
    {
        // 边界检查：索引无效，直接返回
        if (index < 0 || index >= size)
        {
            return;
        }

        DLinkListNode *pred, *succ; // pred：删除节点的前驱；succ：删除节点的后继
        // 双向遍历优化：选择更近的方向找前驱/后继
        if (index < size - index)
        {
            pred = head; // 从头遍历找前驱节点
            for (int i = 0; i < index; i++)
            {
                pred = pred->next;
            }
            succ = pred->next->next; // 前驱的后继的后继 = 删除节点的后继
        }
        else
        {
            succ = tail; // 从尾遍历找后继节点
            // 循环次数：size - index - 1 → 等价于从尾到删除节点的后继的步数
            for (int i = 0; i < size - index - 1; i++)
            {
                succ = succ->prev;
            }
            pred = succ->prev->prev; // 后继的前驱的前驱 = 删除节点的前驱
        }

        size--;                        // 实际节点数-1
        DLinkListNode *p = pred->next; // 保存要删除的节点（避免指针丢失）
        // 双向链表删除核心：跳过删除节点，修改2个指针
        pred->next = succ; // 前驱的后继指向后继节点
        succ->prev = pred; // 后继的前驱指向前驱节点
        delete p;          // 释放删除节点的内存，避免泄漏
        p = nullptr;       // 置空，避免悬空指针
    }

private:
    int size;            // 链表实际节点数（不含虚拟头/尾）
    DLinkListNode *head; // 虚拟头节点（不存储数据，简化头部操作）
    DLinkListNode *tail; // 虚拟尾节点（不存储数据，简化尾部操作）
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