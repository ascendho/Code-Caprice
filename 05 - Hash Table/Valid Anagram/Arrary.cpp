// 题目链接：https://leetcode.cn/problems/valid-anagram/

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // 1. 获取第一个字符串的长度
        //  （后续已校验两字符串长度相等，可共用该变量）
        const int strLen = s.size();

        // 前置校验：长度不同的字符串不可能是字母异位词，直接返回false
        if (strLen != t.size())
            return false;

        // 定义常量：小写英文字母的数量
        //        （消除魔数26，提升代码可维护性）
        const int ALPHABET_COUNT = 26;

        // 初始化字符计数数组：
        // 索引0-25分别对应字母a-z，初始值全为0
        int charCount[ALPHABET_COUNT] = {0};

        // 2. 遍历两个字符串，对字符出现次数进行计数/抵消
        for (int idx = 0; idx < strLen; ++idx)
        {
            // s中的字符：对应位置计数+1
            charCount[s[idx] - 'a']++;

            // t中的字符：对应位置计数-1
            charCount[t[idx] - 'a']--;
        }

        // 3. 校验计数数组：若所有位置都为0，说明字符种类和次数完全匹配
        for (int charIdx = 0; charIdx < ALPHABET_COUNT; ++charIdx)
            // 只要有一个字符的计数不为0，说明不是字母异位词
            if (charCount[charIdx] != 0)
                return false;

        // 所有字符计数都为0，确认是字母异位词
        return true;
    }
};