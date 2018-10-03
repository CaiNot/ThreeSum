#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int length = nums.size();

        vector<vector<int>> result;

        if (length < 3)
            return result;

        sort(nums.begin(), nums.end());
        int last = nums[0] - 1, count = 0;
        vector<int> numFixed;
        for (int i = 0; i < length; i++) {
            if (nums[i] == last && last != 0) {
                if (count < 1) {
                    count++;
                    numFixed.push_back(nums[i]);
                }
                continue;
            } else count = 0;
            numFixed.push_back(nums[i]);
            last = nums[i];
        }
        vector<int> back;

        for (int i = 0; i < length - 2; i++) {
            for (int x = i + 1; x < length - 1; x++) {
                for (int n = x + 1; n < length; n++) {
                    if (numFixed[i] + numFixed[x] + numFixed[n] == 0) {
                        if (result.size() > 0) {
                            back = result.back();
                            if (numFixed[i] != back[0] || numFixed[x] != back[1])
                                result.push_back({numFixed[i], numFixed[x], numFixed[n]});
                        } else result.push_back({numFixed[i], numFixed[x], numFixed[n]});
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0};
    Solution s;
    auto results = s.threeSum(nums);
    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << ",";
        }
        cout << endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}