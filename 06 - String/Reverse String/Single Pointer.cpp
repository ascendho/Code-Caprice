// 题目链接：https://leetcode.cn/problems/reverse-string/

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        // 获取字符数组的总长度，用于计算对称位置的索引
        int n = s.size();

        // 循环遍历数组前半部分（i < n/2）：
        // - 若n为偶数：刚好遍历前n/2个元素，交换完所有对称位置
        // - 若n为奇数：中间位置的字符无需交换，遍历到(n-1)/2即可（n/2自动向下取整）
        for (int i = 0; i < n / 2; i++)
            // 交换s[i]和s[n-1-i]：
            // i是前半部分索引，n-1-i是后半部分对应的对称索引（如i=0对应最后一位，i=1对应倒数第二位）
            swap(s[i], s[n - 1 - i]);
    }
};