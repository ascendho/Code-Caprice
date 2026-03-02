// 题目链接：https://leetcode.cn/problems/spiral-matrix-ii/

class Solution
{
public:
    /**
     * @brief 生成n阶顺时针螺旋矩阵（元素从1到n²依次填充）
     * @param n 矩阵的边长（正整数）
     * @return vector<vector<int>> 填充完成的n×n螺旋矩阵
     */
    vector<vector<int>> generateMatrix(int n)
    {
        // 定义矩阵的四个边界指针，控制填充范围
        int t = 0;     // 上边界：初始指向第0行
        int b = n - 1; // 下边界：初始指向最后一行（n-1行）
        int l = 0;     // 左边界：初始指向第0列
        int r = n - 1; // 右边界：初始指向最后一列（n-1列）

        // 初始化n×n的结果矩阵，所有元素默认初始化为0
        vector<vector<int>> ans(n, vector<int>(n));

        int k = 1; // 待填充的数字，从1开始逐步递增到n²
        // 循环填充：直到所有数字（1~n²）都被填入矩阵
        while (k <= n * n)
        {
            // 第一步：填充上边界行 → 从左到右（l列 → r列）
            for (int i = l; i <= r; ++i, ++k)
                ans[t][i] = k; // 填充第t行的第i列，填充后k自增
            ++t;               // 上边界向下收缩一行（该行列已填满，无需重复处理）

            // 第二步：填充右边界列 → 从上到下（t行 → b行）
            for (int i = t; i <= b; ++i, ++k)
                ans[i][r] = k; // 填充第i行的第r列，填充后k自增
            --r;               // 右边界向左收缩一列（该列已填满）

            // 第三步：填充下边界行 → 从右到左（r列 → l列）
            for (int i = r; i >= l; --i, ++k)
                ans[b][i] = k; // 填充第b行的第i列，填充后k自增
            --b;               // 下边界向上收缩一行（该行已填满）

            // 第四步：填充左边界列 → 从下到上（b行 → t行）
            for (int i = b; i >= t; --i, ++k)
                ans[i][l] = k; // 填充第i行的第l列，填充后k自增
            ++l;               // 左边界向右收缩一列（该列已填满）
        }

        // 返回最终填充完成的螺旋矩阵
        return ans;
    }
};