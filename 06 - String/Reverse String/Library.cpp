// 题目链接：https://leetcode.cn/problems/reverse-string/

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        // ranges::reverse：C++20 std::ranges 库提供的原地反转函数
        // 功能：直接反转传入的序列（此处为vector<char>），无需手动实现双指针/循环
        // 优势：代码极简，可读性高，底层实现与手动双指针逻辑一致（效率无差异）
        ranges::reverse(s);
    }
};

/*
 * std::reverse：传统标准库反转函数，需传入迭代器区间 [begin, end)
 * 作用：反转 [s.begin(), s.end()) 范围内的所有元素，原地修改
 * std::reverse(s.begin(), s.end());
 *
 */