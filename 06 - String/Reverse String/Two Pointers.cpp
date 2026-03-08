// 题目链接：https://leetcode.cn/problems/reverse-string/

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        // 获取字符数组的总长度，用于初始化右指针
        int n = s.size();

        // 双指针初始化：
        // 左指针 left 从数组头部（索引0）开始，右指针 right 从数组尾部（索引n-1）开始
        // 循环条件：left < right（当 left >= right 时，所有对称位置已交换完成，反转结束）
        // 每次循环：左指针右移（++left），右指针左移（--right）
        for (int left = 0, right = n - 1; left < right; ++left, --right)
            // 交换左右指针指向的字符，将对称位置的元素互换，实现反转效果
            swap(s[left], s[right]);
    }
};

/*
 * 位运算实现交换依赖异或（^）运算的三大特性（仅适用于整数 / 字符类型，char 本质是 1 字节整数）：
 * a ^ a = 0（相同值异或结果为 0）；
 * a ^ 0 = a（任何值异或 0 结果为自身）；
 * 异或满足交换律 / 结合律（a^b = b^a、a^(b^c)=(a^b)^c）。
 * ❌ 局限：仅支持整数 / 字符类型，不能用于浮点型、指针；
 * 若 left==right（同一地址），会导致值变为 0（a^a=0），但反转字符串中 left<right，无需担心。
 */

// 替换 swap(s[left], s[right]) 的位运算写法
// 前提：left < right（反转字符串场景中天然满足，避免同一地址异或导致值归零）
// s[left] ^= s[right];  // 第一步：s[left] = 原s[left] ^ 原s[right]
// s[right] ^= s[left];  // 第二步：s[right] = 原s[right] ^ (原s[left]^原s[right]) = 原s[left]
// s[left] ^= s[right];  // 第三步：s[left] = (原s[left]^原s[right]) ^ 原s[left] = 原s[right]