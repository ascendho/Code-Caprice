// 题目链接：https://leetcode.cn/problems/intersection-of-two-arrays/

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // 优化点：优先用更短的数组构建哈希集合，减少内存占用和构建时间
        if (nums1.size() > nums2.size())
            // 递归交换参数，复用逻辑
            return intersection(nums2, nums1);

        // 1. 将nums1去重存入哈希集合，用于快速查找
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        // 2. 存储交集结果（自动去重，避免重复元素）
        unordered_set<int> result_set;

        // 3. 遍历nums2，查找在nums_set中存在的元素
        for (int num : nums2)
            // 若元素在nums_set中存在，加入结果集合
            if (nums_set.find(num) != nums_set.end())
                result_set.insert(num);

        // 4. 将结果集合转为vector返回
        return vector<int>(result_set.begin(), result_set.end());
    }
};