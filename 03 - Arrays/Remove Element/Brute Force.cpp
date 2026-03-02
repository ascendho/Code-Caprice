// 题目链接：https://leetcode.cn/problems/remove-element/

// 暴力解法
class Solution {
public:
    /**
     * @brief 暴力法原地移除数组中所有等于val的元素，并返回新数组的长度
     * @param nums 待处理的整数数组（引用传递，原地修改）
     * @param val 需要移除的目标值
     * @return int 移除元素后数组的新长度
     */
    int removeElement(vector<int>& nums, int val) {
        // 初始化数组的有效长度（初始为原始长度）
        int size = nums.size();
        
        // 遍历数组，i为当前检查的元素下标
        for (int i = 0; i < size; i++) {
            // 发现当前元素是需要移除的目标值val
            if (nums[i] == val) { 
                // 从i+1位置开始，将后续所有元素向前移动一位，覆盖当前的val
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                // 关键：元素集体前移后，原i+1位置的元素现在到了i位置，需要重新检查i
                i--; 
                // 数组有效长度减1（移除了一个val元素）
                size--; 
            }
        }
        // 最终的有效长度即为移除val后的数组长度
        return size;
    }
};