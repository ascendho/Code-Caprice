// 题目链接：https://leetcode.cn/problems/remove-element/

// 双指针解法
class Solution {
public:
    /**
     * @brief 原地移除数组中所有等于val的元素，并返回新数组的长度
     * @param nums 待处理的整数数组（引用传递，原地修改）
     * @param val 需要移除的目标值
     * @return int 移除元素后数组的新长度，且数组前return个元素为非val值
     */
    int removeElement(vector<int>& nums, int val) {
        // 获取数组的原始长度
        int n = nums.size();
        // 左指针：指向新数组（非val元素）的待填充位置
        int left = 0;
        
        // 右指针：遍历整个原始数组，寻找非val元素
        for (int right = 0; right < n; right++) {
            // 当右指针找到非val元素时
            if (nums[right] != val) {
                // 将该元素填充到左指针位置（覆盖原位置）
                nums[left] = nums[right];
                // 左指针右移，准备填充下一个非val元素
                left++;
            }
            // 若右指针找到val元素，直接跳过，左指针不移动
        }
        
        // 左指针的最终位置即为新数组的长度（所有非val元素的个数）
        return left;
    }
};