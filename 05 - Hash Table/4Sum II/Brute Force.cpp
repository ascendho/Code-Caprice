// 题目链接：https://leetcode.cn/problems/4sum-ii/

class Solution
{
public:
    /**
     * @brief 四数相加 II：暴力解法（提前计算部分和优化）
     * @note 题目保证四个数组长度相同，均为 n
     *       时间复杂度仍为 O(n^4)，但减少了重复加法计算，略微提升执行效率
     *       核心优化：提前计算 nums1[i]+nums2[j]，避免内层两层循环重复计算该和
     *
     */
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                     vector<int> &nums4)
    {
        // 题目保证四数组长度相同，统一用n表示
        int n = nums1.size();
        // 满足条件的元组计数
        int count = 0;

        // 四层循环：提前计算前两数之和，减少内层重复计算
        for (int i = 0; i < n; ++i)
            // 遍历nums1
            for (int j = 0; j < n; ++j)
            { // 遍历nums2
                // 核心优化点：提前计算 nums1[i]+nums2[j] 的和
                // 原暴力解法中，内层k/l循环的每次迭代都会重新计算这个和，现在只算一次
                int sumAB = nums1[i] + nums2[j];

                for (int k = 0; k < n; ++k)
                    // 遍历nums3
                    for (int l = 0; l < n; ++l)
                        // 遍历nums4
                        // 直接用提前计算的sumAB，避免重复加法
                        if (sumAB + nums3[k] + nums4[l] == 0)
                            count++;
            }

        return count;
    }
};