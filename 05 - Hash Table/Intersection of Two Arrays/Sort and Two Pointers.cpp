// 题目链接：https://leetcode.cn/problems/intersection-of-two-arrays/

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // 1. 对两个数组排序：将无序数组转为有序，为双指针遍历打基础
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // 2. 初始化变量：数组长度、双指针、结果数组
        int length1 = nums1.size(), length2 = nums2.size();

        // 分别指向nums1和nums2的当前遍历位置
        int index1 = 0, index2 = 0;

        // 存储最终交集结果（保证元素唯一）
        vector<int> intersection;

        // 3. 双指针遍历两个有序数组，直到其中一个指针越界
        while (index1 < length1 && index2 < length2)
        {
            // 取出当前指针指向的元素，避免重复访问数组（提升可读性）
            int num1 = nums1[index1];
            int num2 = nums2[index2];

            if (num1 == num2)
            {
                // 核心去重逻辑：
                // - 结果数组为空时，直接添加
                // - 结果数组非空时，仅当当前元素≠最后一个元素时添加（避免重复）
                if (intersection.empty() || num1 != intersection.back())
                    intersection.push_back(num1);

                // 找到公共元素，两个指针同时后移
                index1++;
                index2++;
            }
            else if (num1 < num2)
                // num1更小，nums1的指针后移（找更大的元素匹配num2）
                index1++;
            else
                // num2更小，nums2的指针后移（找更大的元素匹配num1）
                index2++;
        }

        // 4. 返回最终的交集结果
        return intersection;
    }
};