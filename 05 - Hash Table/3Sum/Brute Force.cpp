// 题目链接：https://leetcode.cn/problems/3sum/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int size = nums.size();
        vector<vector<int>> ans;

        // 1. 修正循环变量错误：j/k的终止条件和自增变量改为自身
        // 2. 保证i<j<k，避免重复排列（如i=0,j=1和i=1,j=0）
        for (int i = 0; i < size; ++i)
            for (int j = i + 1; j < size; ++j)
                // j从i+1开始，避免重复
                for (int k = j + 1; k < size; ++k)
                    // k从j+1开始
                    // 3. 条件：三数之和为0（索引i<j<k已保证i!=j!=k，无需额外判断）
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        // 4. 修正：存储数值而非索引（题目要求返回数值三元组）
                        vector<int> tmp = {nums[i], nums[j], nums[k]};
                        ans.push_back(tmp);
                    }

        // 5. 去重：题目要求不能有重复的三元组
        // 步骤：先排序每个三元组 → 整体排序 → 去重
        for (auto &triplet : ans)
            sort(triplet.begin(), triplet.end());

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};