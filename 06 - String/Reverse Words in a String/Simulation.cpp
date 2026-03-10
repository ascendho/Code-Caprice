// 题目链接：https://leetcode.cn/problems/reverse-words-in-a-string/

class Solution
{
public:
    /*
     * @brief 反转字符串中的单词顺序，同时清理多余空格（原地修改，O(n) 时间）
     * @param s 输入字符串（可能包含前导/尾随/中间多个空格）
     * @return 单词顺序反转且单词间仅一个空格的结果字符串
     * 核心思路：先整体反转 → 逐个单词反转 → 原地构建结果
     */
    string reverseWords(string s)
    {
        // 1. 反转整个字符串，使单词顺序整体反转（但每个单词自身是反转的）
        reverse(s.begin(), s.end());

        int n = s.size();
        int writePos = 0; // 写指针：记录结果字符串当前填充到的位置（用于原地构建）

        // 2. 遍历字符串，逐个处理每个单词
        for (int readStart = 0; readStart < n; ++readStart)
        {
            // 跳过空格，找到单词的起始读位置
            if (s[readStart] != ' ')
            {
                // 如果不是第一个单词，在结果中写入一个空格分隔
                if (writePos != 0)
                {
                    s[writePos++] = ' ';
                }

                // 找到单词的结束读位置，并将单词字符写入结果位置
                int readEnd = readStart;
                while (readEnd < n && s[readEnd] != ' ')
                {
                    s[writePos++] = s[readEnd++]; // 边读边写，原地构建结果
                }

                // 反转当前单词，恢复其正常顺序（因为之前整个字符串被反转了）
                reverse(s.begin() + writePos - (readEnd - readStart), s.begin() + writePos);

                // 移动读指针到单词结束位置，跳过已处理的单词
                readStart = readEnd;
            }
        }

        // 3. 删除写指针之后的多余字符（即原字符串中未被使用的部分）
        s.erase(s.begin() + writePos, s.end());
        return s;
    }
};