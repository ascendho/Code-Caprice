// 题目链接：https://leetcode.cn/problems/two-sum/

class Solution
{
public:
    // 功能：在数组nums中找到两个数，使其和等于target，返回这两个数的下标（题目保证有且仅有一个有效解）
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 获取数组nums的长度，避免多次调用size()提升效率
        int size = nums.size();

        // 外层循环：遍历数组，将每个元素作为第一个候选数（下标为i）
        for (int i = 0; i < size; i++)
        {
            // 内层循环：遍历i之后的元素作为第二个候选数（下标为j）
            // j从i+1开始：避免重复检查同一组元素（如i=0,j=1和i=1,j=0），减少无效计算
            for (int j = i + 1; j < size; j++)
                // 检查两个候选数的和是否等于目标值
                if (nums[i] + nums[j] == target)
                    // 找到解，直接返回两个下标（题目保证唯一解，找到即退出）
                    return vector<int>{i, j};
        }

        // 题目明确有且仅有一个解，此处返回空数组仅为满足函数语法要求
        return {};
    }
};