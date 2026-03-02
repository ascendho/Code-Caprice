// 题目链接：https://leetcode.cn/problems/binary-search/

/**
 * @brief 二分查找（左闭右闭区间 [left, right] 版本）
 * 适用于有序且无重复元素的数组，查找目标值的索引
 */
class Solution
{
public:
    /**
     * @param nums 有序的整数数组（升序）
     * @param target 需要查找的目标值
     * @return 找到则返回目标值在数组中的索引，未找到返回 -1
     */
    int search(vector<int> &nums, int target)
    {
        // 初始化左指针：指向数组第一个元素
        int left = 0;
        // 初始化右指针：指向数组最后一个元素（左闭右闭区间）
        int right = nums.size() - 1;

        // 循环条件：左指针 <= 右指针（区间内还有元素可查找）
        while (left <= right)
        {
            // 计算中间索引：(right - left)/2 + left 避免 left+right 整数溢出
            int mid = (right - left) / 2 + left;
            // 获取中间位置的元素值
            int num = nums[mid];

            // 找到目标值，直接返回索引
            if (num == target)
            {
                return mid;
            }
            // 中间值大于目标值：目标值在左半区间，收缩右边界
            else if (num > target)
            {
                right = mid - 1;
            }
            // 中间值小于目标值：目标值在右半区间，收缩左边界
            else
            {
                left = mid + 1;
            }
        }

        // 循环结束未找到目标值，返回 -1
        return -1;
    }
};