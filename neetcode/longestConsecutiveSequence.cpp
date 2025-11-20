// Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.
// A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element.
// The elements do not have to be consecutive in the original array.
// You must write an algorithm that runs in O(n) time.

#include <vector>
#include <unordered_set>
#include <iostream>
class Solution
{
public:
    int longestConsecutive(std::vector<int> &nums)
    {

        std::unordered_set<int> set;

        // t: O(n), s:O(n)
        for (const int &i : nums)
        {
            set.insert(i);
        }

        // num is start if num - 1 doesn't exist
        std::vector<int> starts;
        starts.reserve(nums.size());

        // t: O(n), s:O(n)
        for (const int &i : nums)
        {
            if (!set.count(i - 1))
            {
                starts.push_back(i);
            }
        }

        int longest{0};
        // t: O(n), s:O(n)
        for (const int &s : starts)
        {
            int current = s;
            int currentLongest{1};
            while (true)
            {
                current++;
                if (!set.count(current))
                {
                    break;
                }
                currentLongest++;
            }

            if (currentLongest > longest)
            {
                longest = currentLongest;
            }
        }

        return longest;
    }
};

int main()
{
    std::vector<int> nums = {2, 20, 4, 10, 3, 4, 5};
    std::vector<int> nums2 = {0, 3, 2, 5, 4, 6, 1, 1};
    Solution s;
    std::cout << s.longestConsecutive(nums2) << std::endl;
}
