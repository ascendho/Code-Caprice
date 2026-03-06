// 题目链接：https://leetcode.cn/problems/valid-anagram/

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // 前置校验：长度不同的字符串不可能是字母异位词，直接返回false
        if (s.length() != t.length())
            return false;

        // 初始化字符计数数组：长度26对应a-z，初始值全为0
        // 使用vector而非数组，更符合C++现代编程风格，且无需手动管理内存
        vector<int> table(26, 0);

        // 第一阶段：统计字符串s中每个字符的出现次数
        for (auto &ch : s)
            // 字符ch减去'a'得到0-25的索引，对应a-z，计数+1
            table[ch - 'a']++;

        // 第二阶段：用字符串t抵消计数，并提前终止无效判断
        for (auto &ch : t)
        {
            // 字符ch对应的计数-1
            table[ch - 'a']--;

            // 关键优化：若计数<0，说明t中该字符数量多于s，直接返回false
            // 无需遍历完整个字符串，提前终止，减少不必要的计算
            if (table[ch - 'a'] < 0)
                return false;
        }

        // 所有字符计数抵消后无负数，且长度相等 → 必然是字母异位词
        return true;
    }
};