// 题目链接：https://leetcode.cn/problems/4sum-ii/

class Solution
{
public:
    /**
     * @brief 四数相加 II：统计满足 nums1[i] + nums2[j] + nums3[k] + nums4[l] = 0 的元组数量
     *
     * 解题思路：
     * 1.  分治：将四数之和拆分为 (nums1[i] + nums2[j]) + (nums3[k] + nums4[l]) = 0
     * 2.  哈希表：用哈希表存储前两数组所有和的出现次数
     * 3.  查表：遍历后两数组的所有和，在哈希表中查找其相反数的出现次数并累加
     *
     */
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        // 统计满足条件的元组总数
        int totalCount = 0;

        // 哈希表：key = nums1[i] + nums2[j] 的和，value = 该和出现的次数
        unordered_map<int, int> sumABMap;

        // 第一步：遍历 nums1 和 nums2，统计所有两数之和的出现次数
        for (int a : nums1)
            for (int b : nums2)
                sumABMap[a + b]++;

        // 第二步：遍历 nums3 和 nums4，计算 c + d，查找 -(c + d) 在哈希表中的次数并累加
        for (int c : nums3)
            for (int d : nums4)
                if (sumABMap.find(-(c + d)) != sumABMap.end())
                    totalCount += sumABMap[-(c + d)];

        return totalCount;
    }
};