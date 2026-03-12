// 题目链接：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution
{
public:
    void get_next(const string &T, vector<int> &next)
    {
        int m = T.size();

        // 提前分配空间，避免动态增长
        next.resize(m);

        // 第一个字符的最长前后缀为0（无真前后缀）
        next[0] = 0;

        // j 表示当前最长前后缀的长度
        int j = 0;

        // 从 i=1 开始遍历，计算每个位置的 next 值
        for (int i = 1; i < m; ++i)
        {
            // 核心：j>0 且字符不相等时，回退到 next[j-1]
            while (j > 0 && T[i] != T[j])
                j = next[j - 1];

            // 字符相等时，j 递增
            if (T[i] == T[j])
                j++;

            // 记录当前位置的最长前后缀长度
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();

        // 特殊情况：模式串比主串长，直接返回 -1
        if (m > n)
            return -1;

        vector<int> next;
        get_next(needle, next);

        int i = 0, j = 0;

        // 主循环条件为 i < n 且 j < m（合法范围）
        while (i < n && j < m)
        {
            if (haystack[i] == needle[j])
            {
                // 字符匹配，同时后移
                i++;
                j++;
            }
            else if (j > 0)
                // 字符不匹配，j 回退到 next[j-1]
                j = next[j - 1];
            else
                // j=0 时无法回退，主串指针后移
                i++;
        }

        // 匹配成功的条件是 j == m（模式串全部匹配）
        if (j == m)
            return i - m; // 计算第一个匹配的起始下标
        else
            return -1; // 匹配失败
    }
};