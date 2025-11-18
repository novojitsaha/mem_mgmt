// Given two strings s and t, return true if the two strings are anagrams of each other,
//  otherwise return false.
// Recommended time complexity O(n + m) where n and m are length of string s and t respectively
// Recommended space complexity O(1)

#include <string>
#include <iostream>
class Solution
{
public:
    bool isAnagram(const std::string &s, const std::string &t)
    {
        if (s.size() != t.size())
            return false;

        int freq[26] = {0};

        for (const char c : s)
        {
            freq[c - 'a']++;
        }

        for (const char c : t)
        {
            freq[c - 'a']--;
        }

        for (const int i : freq)
        {
            if (i != 0)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    std::string s = "racecar";
    std::string t = "carrace";
    std::cout << sol.isAnagram(s, t) << std::endl;
}