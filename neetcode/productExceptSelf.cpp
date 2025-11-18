// Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].
// Each product is guaranteed to fit in a 32-bit integer.
// Follow-up: Could you solve it in O(n) time without using the division operation?

#include <vector>
#include <iostream>

class Solution
{
public:
    // 2 linear passes resulting in O(n)
    std::vector<int> productExceptSelf(const std::vector<int> &nums)
    {
        // nums = {1,2,4,6}
        if (nums.size() == 2)
            return std::vector<int>{nums[1], nums[0]};

        std::vector<int> result(nums.size());

        // prefix pass
        result[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            result[i] = nums[i - 1] * result[i - 1];
        }

        // suffix pass
        int suffix = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            result[i] = result[i] * suffix;
            suffix *= nums[i];
        }

        return result;
    }
};

int main()
{
    std::vector<int> input = {1, 2, 4, 6};
    Solution s;
    std::vector<int> output = s.productExceptSelf(input);

    for (const int &i : output)
    {
        std::cout << i << std::endl;
    }
}