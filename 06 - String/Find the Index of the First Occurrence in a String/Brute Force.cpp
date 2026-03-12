// 题目链接：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size(); // 主串（haystack）的长度
        int m = needle.size();   // 模式串（needle）的长度

        // 特殊情况1：模式串比主串长，直接返回-1（不可能匹配）
        if (m > n)
            return -1;

        // i：主串当前遍历位置；j：模式串当前遍历位置
        int i = 0, j = 0;

        // 循环条件：主串未遍历完 且 模式串未遍历完
        while (i < n && j < m)
        {
            if (haystack[i] == needle[j])
            {
                // 当前字符匹配，继续比较下一个字符
                i++;
                j++;
            }
            else
            {
                // 字符不匹配：主串回溯到「本次匹配起始位置 + 1」，
                // 模式串重置到开头
                i = i - j + 1; // 起始位置 = i - j，所以下一个位置是 (i-j)+1
                j = 0;         // 模式串指针归0，重新开始匹配

                // 优化：如果主串剩余字符不足，提前终止循环（避免无效遍历）
                if (i > n - m)
                    break;
            }
        }

        // 匹配成功：模式串全部遍历完成（j == m），返回匹配起始位置；否则返回-1
        return (j == m) ? i - m : -1;
    }
};