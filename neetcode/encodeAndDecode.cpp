// Design an algorithm to encode a list of strings to a single string.
// The encoded string is then decoded back to the original list of strings.
// You should aim for a solution with O(m) time for each encode() and decode()
// call and O(m+n) space, where m is the sum of lengths of all the strings and n is the number of strings.

#include <string>
#include <iostream>
#include <vector>

class Solution
{
public:
    // encode: n#str where n = str.size()
    std::string encode(std::vector<std::string> &strs)
    {
        // calculate size of output string
        size_t totalOutputSize = 0;

        // t: O(n)
        for (const std::string &s : strs)
        {
            totalOutputSize += s.size();
        }

        totalOutputSize += (2 * strs.size());

        std::string result;
        result.reserve(totalOutputSize);

        // t: O(n)
        for (const std::string &s : strs)
        {
            result.append(std::string(std::to_string(s.size()) + "#" + s));
        }

        return result;
    }

    std::vector<std::string> decode(std::string &s)
    {
        std::vector<std::string> result;

        for (int i = 0; i < s.size(); i)
        {
            size_t hashPos = s.find('#', i);
            int n = std::stoi(s.substr(i, hashPos - i));
            std::string str = s.substr(hashPos + 1, n);
            result.push_back(str);
            i += 2 + n;
        }
        return result;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> vec = {"hello", "world"};
    std::string encoded = s.encode(vec);
    std::cout << encoded << std::endl;
    std::vector<std::string> decoded = s.decode(encoded);
    for (const std::string &s : decoded)
    {
        std::cout << s << std::endl;
    }
}