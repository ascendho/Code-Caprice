// 题目链接：https://leetcode.cn/problems/valid-anagram/

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // 前置校验：长度不同的字符串不可能是字母异位词，直接返回false
        if (s.length() != t.length())
            return false;

        // 对两个字符串分别进行排序
        // 若为字母异位词，排序后字符的顺序和组合必然完全相同
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // 比较排序后的字符串是否相等，相等则为字母异位词
        return s == t;
    }
};