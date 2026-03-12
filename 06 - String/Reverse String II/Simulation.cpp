// 题目链接：https://leetcode.cn/problems/reverse-string-ii/

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int n = s.size();

        // 按 2k 为步长遍历整个字符串
        for (int i = 0; i < n; i += 2 * k)
        {
            // 确定反转的结束位置：取 i+k 和字符串末尾的较小值
            int reverseEnd = min(i + k, n);

            // 反转 [i, reverseEnd) 区间的字符
            reverse(s.begin() + i, s.begin() + reverseEnd);
        }

        return s;
    }
};