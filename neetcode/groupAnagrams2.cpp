// Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order
// You should aim for a solution with O(m * n) time and O(m) space,
// where m is the number of strings and n is the length of the longest string.

#include <vector>
#include <string>
#include <iostream>
#include <array>
#include <unordered_map>

class Solution
{
public:
    // time complexity: O(n), space complexity: O(1)
    std::string getFreqSignature(const std::string &str)
    {

        std::string s(26, '0');

        for (const char &c : str)
        {
            int idx = c - 'a';

            int freq = s[idx] - '0';

            freq++;

            s[idx] = freq + '0';
        }

        return s;
    }

    // time complexity: O(m * n), space complexity: O(m)
    std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string> &strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> map;

        for (const std::string &s : strs)
        {
            std::string signatureStr = getFreqSignature(s);

            if (map.count(signatureStr))
            {
                map[signatureStr].push_back(s);
            }
            else
            {
                map[signatureStr] = std::vector<std::string>{s};
            }
        }

        std::vector<std::vector<std::string>> result;

        for (const auto &[key, value] : map)
        {
            result.push_back(value);
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