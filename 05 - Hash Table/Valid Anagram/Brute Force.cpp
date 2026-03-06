// 题目链接：https://leetcode.cn/problems/valid-anagram/

/*
    核心思路：
        1. 逐个检查 s 中的每个字符，在 t 中找到一个未被使用的匹配字符；
        2. 找到后标记该字符为 “已使用”，避免重复匹配；
        3. 如果某个字符找不到匹配，直接返回 false。
*/

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // 长度不同，直接返回false
        if (s.size() != t.size())
            return false;

        int n = s.size();

        // 标记t中哪些字符已经被匹配过，避免重复使用
        vector<bool> used(n, false);

        // 外层循环：遍历s中的每个字符
        for (int i = 0; i < n; ++i)
        {
            bool found = false;

            // 内层循环：在t中找一个未被使用的匹配字符
            for (int j = 0; j < n; ++j)
            {
                if (!used[j] && s[i] == t[j])
                {
                    used[j] = true; // 标记为已使用
                    found = true;
                    break;          // 找到后立即跳出内层循环
                }
            }
            
            // 如果当前字符找不到匹配，直接返回false
            if (!found)
                return false;
        }

        // 所有字符都找到匹配，返回true
        return true;
    }
};