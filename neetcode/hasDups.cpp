#include <unordered_set>
#include <iostream>
#include <vector>
class Solution
{
public:
    bool hasDups(const std::vector<int> &nums)
    {
        std::unordered_set<int> seen;

        for (int num : nums)
        {
            if (seen.count(num))
                return true;
            seen.insert(num);
        }
        return false;
    }
};

int main()
{
    std::vector<int> test{1, 1, 2};

    Solution s;
    bool result = s.hasDups(test);
    std::cout << result << std::endl;
}
