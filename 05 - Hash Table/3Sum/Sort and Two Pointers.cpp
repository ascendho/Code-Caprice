// 题目链接：https://leetcode.cn/problems/3sum/

class Solution
{
public:
    // 目标：在一个数组中找到3个数形成的三元组，它们的和为0
    // 要求：三元组不能重复（即内容相同的组合只能算一个）
    // 核心思路：排序 + 固定数 a + 双指针寻找 b 和 c
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;

        // 1. 先对数组进行排序。这是使用双指针的前提，同时也极其方便去重
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            // 【剪枝优化】因为数组是有序的，如果固定的最小数 a (nums[i]) 已经大于 0，
            // 那么后面的 b 和 c 肯定也都大于 0，三者之和不可能等于 0，直接结束整个循环。
            if (nums[i] > 0)
                break;

            // 【去重 a】如果当前的 a 和上一轮的 a 相同，说明该数字作为 a 的所有可能组合
            // 在上一轮都已经找过了，为了避免生成重复的三元组，直接跳过。
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // 2. 使用双指针在剩余的数组 [i+1, n-1] 中寻找 b 和 c
            int left = i + 1;  // 左指针，代表 b
            int right = n - 1; // 右指针，代表 c

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right]; // 计算 a + b + c

                if (sum < 0)
                    // 和小于 0，说明 b 太小了，需要将左指针向右移动以增大和
                    left++;

                else if (sum > 0)
                    // 和大于 0，说明 c 太大了，需要将右指针向左移动以减小和
                    right--;
                else
                {
                    // 找到了一组和为 0 的三元组，加入结果集
                    result.push_back({nums[i], nums[left], nums[right]});

                    // 【去重 b 和 c】此时虽然找到了一个组合，但可能还有其他组合。
                    // 为了防止出现重复的三元组，需要跳过后续相同的元素

                    // 去重 b：如果下一个左指针元素和当前一样，直接跳过
                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    // 去重 c：如果上一个右指针元素和当前一样，直接跳过
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    // 找到一个正确组合并去重后，双指针同时向内收缩，继续寻找下一对可能的 b 和 c
                    left++;
                    right--;
                }
            }
        }

        return result;
    }
};