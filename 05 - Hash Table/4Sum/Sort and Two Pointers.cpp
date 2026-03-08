// 题目链接：https://leetcode.cn/problems/4sum/

class Solution
{
public:
    /*
     * 核心思路：排序 + 双指针法，通过两层循环固定前两个数，双指针寻找后两个数，同时剪枝和去重以优化效率
     * 时间复杂度：排序O(nlogn) + 两层循环O(n²) + 双指针O(n) = O(n²)（n为数组长度）
     * 空间复杂度：O(logn)（排序的栈空间，忽略结果存储的空间）
     */
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // 存储所有满足条件的不重复四元组
        vector<vector<int>> quadruplets;

        // 数组长度不足4，不可能存在四元组，直接返回空结果
        if (nums.size() < 4)
            return quadruplets;

        sort(nums.begin(), nums.end()); // 排序数组，为双指针法和去重操作提供基础
        int length = nums.size();       // 数组长度，用于控制循环边界

        // 外层循环：固定第一个数nums[i]，i最多到length-4（需预留3个位置给j、left、right）
        for (int i = 0; i < length - 3; i++)
        {
            // 去重：若当前数与前一个数相同，跳过以避免重复四元组
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // 剪枝：当前数+后三个最小数 > target，后续所有组合和必然更大，直接终止i循环
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;

            // 剪枝：当前数+后三个最大数 < target，当前i过小，跳过至下一个i
            if ((long)nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target)
                continue;

            // 内层循环：固定第二个数nums[j]，j从i+1开始，最多到length-3（需预留2个位置给left、right）
            for (int j = i + 1; j < length - 2; j++)
            {
                // 去重：若当前数与前一个数（j的前一个，且j>i+1）相同，跳过以避免重复四元组
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // 剪枝：当前i+j+后两个最小数 > target，后续j组合和必然更大，终止j循环
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;

                // 剪枝：当前i+j+后两个最大数 < target，当前j过小，跳过至下一个j
                if ((long)nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target)
                    continue;

                // 双指针初始化：left为第三个数起点（j+1），right为第四个数起点（数组末尾）
                int left = j + 1, right = length - 1;

                // 双指针遍历，直到left与right相遇
                while (left < right)
                {
                    // 计算四数之和，用long避免int溢出（nums[i]最大为1e9，四数之和可达4e9）
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];

                    // 找到满足条件的四元组
                    if (sum == target)
                    {
                        // 将四元组加入结果列表
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // 去重：跳过所有与当前left相同的数，避免重复四元组
                        while (left < right && nums[left] == nums[left + 1])
                            left++;

                        // 移动至下一个不同的数
                        left++;

                        // 去重：跳过所有与当前right相同的数，避免重复四元组
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        // 移动至前一个不同的数
                        right--;
                    }
                    else if (sum < target)
                        // 和过小，需要更大的数，左指针右移
                        left++;
                    else
                        // 和过大，需要更小的数，右指针左移
                        right--;
                }
            }
        }

        // 返回所有不重复的四元组
        return quadruplets;
    }
};