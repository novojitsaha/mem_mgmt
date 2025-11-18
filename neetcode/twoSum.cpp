// Given an array of integers nums and an integer target, return the indices i and j such that
// nums[i] + nums[j] == target and i != j.
// You may assume that every input has exactly one pair of indices i and j that satisfy the condition.
// Return the answer with the smaller index first.

//  Constraints
// 2 <= nums.length <= 1000
// -10,000,000 <= nums[i] <= 10,000,000
// -10,000,000 <= target <= 10,000,000

// You should aim for a solution with O(n) time and O(n) space, where n is the size of the input array.

#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>
class Solution
{
public:
    std::array<int, 2> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> hashMap;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (hashMap.count(complement))
            {
                return {std::min(hashMap[complement], i), std::max(hashMap[complement], i)};
            }
            hashMap[nums[i]] = i;
        }

        return {};
    };
};

int main()
{
    std::vector<int> nums = {2, 4, 6};
    int target = 8;

    Solution s;
    std::array<int, 2> result = s.twoSum(nums, target);

    for (const int i : result)
    {
        std::cout << i << " " << std::endl;
    }
}
