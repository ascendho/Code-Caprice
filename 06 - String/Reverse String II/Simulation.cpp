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

/* 也可以这样：

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
        
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) 
                reverse(s.begin() + i, s.begin() + i + k );
            else 
                // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
                reverse(s.begin() + i, s.end());   
        }

        return s;
    }
};

*/