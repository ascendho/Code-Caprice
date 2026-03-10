// 题目链接：https://leetcode.cn/problems/reverse-words-in-a-string/

class Solution
{
public:
    /*
     * 核心思路：
     * 1. 先清理首尾空格；
     * 2. 遍历字符串提取单词，将单词按顺序插入双端队列头部（自动实现反转）；
     * 3. 拼接队列中的单词，得到最终结果。
     */
    string reverseWords(string s)
    {
        // 1. 初始化左右指针，用于跳过首尾空格
        int left = 0, right = s.size() - 1;

        // 1.1 跳过字符串开头的所有空白字符（前导空格）
        while (left <= right && s[left] == ' ')
            ++left;

        // 1.2 跳过字符串末尾的所有空白字符（尾随空格）
        while (left <= right && s[right] == ' ')
            --right;

        // 2. 双端队列：用于存储提取的单词，通过push_front实现单词顺序反转
        deque<string> d;

        // 临时存储当前遍历到的单词
        string word;

        // 3. 遍历处理中间的字符（已跳过首尾空格）
        while (left <= right)
        {
            char c = s[left]; // 当前遍历的字符

            // 3.1 遇到空格且当前已提取到单词（说明单词结束）
            if (word.size() && c == ' ')
            {
                // 将单词移动（move）到队列头部（实现顺序反转），避免拷贝提升效率
                d.push_front(move(word));

                // 清空临时单词，准备提取下一个单词
                word = "";
            }
            // 3.2 遇到非空格字符：追加到当前单词中
            else if (c != ' ')
                word += c;

            // 3.3 遇到连续空格：word为空，直接跳过（不处理）
            // 左指针右移，继续遍历
            ++left; 
        }

        // 4. 将最后一个单词（循环结束后可能还剩一个未入队的单词）加入队列头部
        d.push_front(move(word));

        // 5. 拼接队列中的单词，生成最终结果
        string ans;

        while (!d.empty())
        {
            ans += d.front(); // 取出队列头部的单词
            d.pop_front();    // 移除已拼接的单词

            // 不是最后一个单词，添加空格分隔
            if (!d.empty())
                ans += ' ';
        }

        return ans;
    }
};