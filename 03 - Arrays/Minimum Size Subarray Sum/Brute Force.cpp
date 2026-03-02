// 题目链接：https://leetcode.cn/problems/minimum-size-subarray-sum/

class Solution
{
public:
    /**
     * @brief 暴力法寻找数组中长度最小的子数组，使其和大于等于目标值 s
     * @param s 目标和（题目中的 target）
     * @param nums 输入的正整数数组
     * @return 满足条件的最小子数组长度，不存在符合条件的子数组则返回 0
     */
    int minSubArrayLen(int s, vector<int> &nums)
    {
        // 获取数组的长度
        int n = nums.size();
        // 边界条件：如果数组为空，直接返回 0
        if (n == 0)
        {
            return 0;
        }
        // 初始化最小长度为整数最大值，用于后续更新最小符合条件的子数组长度
        int ans = INT_MAX;

        // 外层循环：遍历每个元素作为子数组的起始位置
        for (int i = 0; i < n; i++)
        {
            // 重置当前子数组的和，每次以新的i为起点时重新计算
            int sum = 0;
            // 内层循环：从起始位置i开始，向后扩展子数组的结束位置j
            for (int j = i; j < n; j++)
            {
                // 将当前元素nums[j]加入子数组和
                sum += nums[j];
                // 当子数组和大于等于目标值s时
                if (sum >= s)
                {
                    // 更新最小长度：当前子数组长度为 j - i + 1，取更小值
                    ans = min(ans, j - i + 1);
                    // 关键：找到以i为起点的最小子数组后，无需继续扩展j，直接跳出内层循环
                    break;
                }
            }
        }

        // 若ans仍为初始的INT_MAX，说明无符合条件的子数组，返回0；否则返回最小长度
        return ans == INT_MAX ? 0 : ans;
    }
};