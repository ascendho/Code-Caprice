// 题目链接：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution
{
public:
    // 功能：在主串haystack中查找模式串needle的第一个匹配位置，匹配失败返回-1
    int strStr(string haystack, string needle)
    {
        int n = haystack.size(); // n：主串（haystack）的长度
        int m = needle.size();   // m：模式串（needle）的长度

        // 外层循环：遍历主串所有「可能的匹配起始位置」
        // 循环条件i + m <= n：保证从i开始有足够的字符匹配模式串（避免越界）
        for (int i = 0; i + m <= n; i++)
        {
            // 标记：当前起始位置i是否能完全匹配模式串（默认匹配成功）
            bool flag = true; 

            // 内层循环：从起始位置i开始，逐位对比主串和模式串的字符
            for (int j = 0; j < m; j++)
            {
                // 主串当前字符：haystack[i+j]（i是起始位置，j是偏移量）
                // 模式串当前字符：needle[j]
                if (haystack[i + j] != needle[j])
                {
                    flag = false; // 有字符不匹配，标记为失败
                    break;        // 无需继续对比，跳出内层循环
                }
            }

            // 如果当前起始位置i匹配成功，直接返回i（第一个匹配位置）
            if (flag)
                return i;
        }

        // 遍历完所有可能位置仍未匹配，返回-1
        return -1;
    }
};