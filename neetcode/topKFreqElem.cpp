// Given an integer array nums and an integer k, return the k most frequent elements within the array.
// You should aim for a solution with O(n) time and O(n) space, where n is the size of the input array.

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <array>

class Solution
{
public:
    std::vector<int> getTopKFreqElem(const std::vector<int> &nums, int k)
    {
        // {element : frequency}
        std::unordered_map<int, int> freqMap;

        //  t: O(n), s: O(n)
        for (const int &i : nums)
        {
            freqMap[i]++;
        }

        // bucket sort by frequency: bucket n will contain elements with n frequency
        std::vector<std::vector<int>> bucket(nums.size() + 1);

        // t: O(n), s: O(n)
        for (auto &[elem, freq] : freqMap)
        {
            bucket[freq].push_back(elem);
        }

        std::vector<int> result;
        result.reserve(k);
        // collect top k elements from each bucket. t: O(n), s: O(1)
        for (int i = bucket.size() - 1; i > 0 && result.size() < k; i--)
        {
            for (const int &e : bucket[i])
            {
                result.push_back(e);
                if (result.size() == k)
                    break;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums{1, 2, 2, 3, 3, 3};
    int k = 2;
    std::vector<int> result = s.getTopKFreqElem(nums, k);

    for (const int &i : result){
        std::cout << i << std::endl; 
    }
}