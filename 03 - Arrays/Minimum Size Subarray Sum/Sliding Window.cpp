// 题目链接：https://leetcode.cn/problems/minimum-size-subarray-sum/

class Solution
{
public:
    /**
     * @brief 寻找数组中长度最小的子数组，使其和大于等于 target
     * @param target 目标和
     * @param nums 输入的正整数数组
     * @return 满足条件的最小子数组长度，不存在则返回 0
     */
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // 获取数组长度
        int n = nums.size();
        // 数组为空，直接返回 0
        if (0 == n)
            return 0;

        // 初始化答案为最大整数值，用于后续更新最小长度
        int ans = INT_MAX;
        // 滑动窗口的左右边界，初始都在数组起点
        int start = 0, end = 0;
        // 当前窗口内元素的和
        int sum = 0;

        // 右边界遍历整个数组
        while (end < n)
        {
            // 将右边界元素加入当前窗口和
            sum += nums[end];

            // 当窗口和 >= target 时，尝试收缩左边界以找到更短的子数组
            while (sum >= target)
            {
                // 更新最小长度：当前窗口长度为 end - start + 1
                ans = min(ans, end - start + 1);
                // 若已找到长度为 1 的子数组，不可能更短，直接跳出内层循环
                if (ans == 1)
                    break;
                // 从窗口和中减去左边界元素
                sum -= nums[start];
                // 左边界右移，收缩窗口
                start++;
            }

            // 右边界右移，扩展窗口
            end++;
        }

        // 如果 ans 仍为初始最大值，说明未找到符合条件的子数组，返回 0；否则返回最小长度
        return ans == INT_MAX ? 0 : ans;
    }
};