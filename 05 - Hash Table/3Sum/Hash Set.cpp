// 题目链接：https://leetcode.cn/problems/3sum/

class Solution
{
public:
    // 核心思路：固定 a，将寻找 b 和 c 的过程转化为“两数之和”问题，利用哈希表解决。
    // a 对应 nums[i]，c 对应 nums[k]，b 对应存入 set 中的数字。
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;

        // 1. 排序。虽然哈希表法不严格依赖排序来寻找答案，
        // 但排序是后续进行“外层去重 a”和“内层去重 c”的基础条件。
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            // 【剪枝优化】如果最小的数 a 已经大于 0，后面不可能凑出和为 0 的三元组
            if (nums[i] > 0)
                break;

            // 【外层去重 a】如果本轮 a 和上轮 a 相同，直接跳过，防止产生重复的组合
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // 声明哈希表。这个 set 的作用是记录在 i 和 k 之间遍历过的数字，作为候选的 b
            unordered_set<int> set;

            for (int k = i + 1; k < nums.size(); k++)
            {
                // 【内层去重 c 的核心逻辑】限制相同的数字最多只能出现两次（分别充当 b 和 c）
                // 为什么要这样？比如 a = -4，后面跟着[2, 2, 2, 2]。
                // 只需要用到前两个 2（-4 + 2 + 2 = 0），如果允许处理第三个 2，
                // 就会和被重新插入 set 的 2 再次匹配，产生重复的 [-4, 2, 2]。
                // 因此，当连续出现第三个相同的数字时，直接 continue 忽略。
                if (k > i + 2 && nums[k] == nums[k - 1] && nums[k - 1] == nums[k - 2])
                    continue;

                // 我们期望找到一个 b，使得 a + b + c = 0
                // 转换一下就是：b = 0 - (a + c)。此时 nums[i] 是 a，nums[k] 充当 c
                int target = 0 - (nums[i] + nums[k]);

                // 去哈希表里找，看之前有没有存过我们需要的 b
                if (set.find(target) != set.end())
                {
                    // 找到了！组合成立，加入结果集
                    result.push_back({nums[i], target, nums[k]});

                    // 【内层去重 b】找到一对匹配后，将 b 从 set 中删除！
                    // 这一步非常关键。比如 a = -4，当前有 [2, 2] 进来，匹配成功后删掉 set 里的 2。
                    // 这样如果后面再来一个 2，它就不会再去和之前的 2 匹配，从而避免重复组合。
                    set.erase(target);
                }
                else
                    // 如果没找到对应的 b，说明当前的 nums[k] 不能和之前的数配对，
                    // 那么就把它存入 set 中，作为以后其他数（未来的 c）的备胎（候选 b）
                    set.insert(nums[k]);
            }
        }

        return result;
    }
};