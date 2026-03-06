// 题目链接：https://leetcode.cn/problems/two-sum/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 哈希表：key = 数组元素值，value = 该元素在数组中的下标
        unordered_map<int, int> hashtable;

        // 一次遍历数组，边查找边构建哈希表
        for (int i = 0; i < nums.size(); ++i)
        {
            // 计算当前元素的“补数”：target - nums[i]
            // 若补数已在哈希表中，说明之前已遍历过该元素，两者之和为 target
            auto it = hashtable.find(target - nums[i]);

            // 找到补数，直接返回两个下标（之前元素的下标 + 当前元素的下标）
            if (it != hashtable.end())
                return {it->second, i};

            // 未找到补数，将当前元素和下标存入哈希表，供后续元素查找
            hashtable[nums[i]] = i;
        }

        // 题目保证存在唯一解，理论上不会执行到这里
        return {};
    }
};