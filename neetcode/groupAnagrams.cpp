// Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order
// You should aim for a solution with O(m * n) time and O(m) space,
// where m is the number of strings and n is the length of the longest string.

// !!! This solution violates the O (m * n) time complexity.
// It has a time complexity of O (m^2 * n) because every string is compared to every other string
//  and each comparison is O (n).
// This issue is fixed in groupAnagrams2.cpp
#include <vector>
#include <iostream>
#include <string>

class Solution
{
public:
    bool isAnagram(const std::string &s1, const std::string &s2)
    {
        if (s1.length() != s2.length())
            return false;

        int freq[26] = {0};

        for (const char c : s1)
        {
            freq[c - 'a']++;
        }

        for (const char c : s2)
        {
            freq[c - 'a']--;
        }

        for (const int i : freq)
        {
            if (i > 0)
                return false;
        }
        return true;
    }

    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {

        std::vector<std::vector<std::string>> result;
        std::vector<bool> visited(strs.size(), false);

        for (int i = 0; i < strs.size(); i++)
        {
            if (!visited[i])
            {
                std::vector<std::string> v;

                v.push_back(strs[i]);
                visited[i] = true;
                for (int j = i + 1; j < strs.size(); j++)
                {
                    if (isAnagram(strs[i], strs[j]))
                    {
                        v.push_back(strs[j]);
                        visited[j] = true;
                    }
                }
                result.push_back(v);
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> input = {"act", "pots", "tops", "cat", "stop", "hat"};
    std::vector<std::vector<std::string>> output = s.groupAnagrams(input);

    for (const auto &vec : output)
    {
        for (const auto str : vec)
        {
            std::cout << str << ',' << ' ';
        }
        std::cout << std::endl;
    }
}