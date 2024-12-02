#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool part_1_is_save(std::vector <int> nums) {
    if (nums.size() == 1) return true;

    int dif = nums[0] - nums[1];
    vector <int> tmp = nums;
    sort(tmp.begin(), tmp.end());
    if (dif > 0) reverse(nums.begin(), nums.end());

    if (tmp != nums) return false;
    for (int i = 1; i < nums.size(); i ++) if (nums[i] - nums[i - 1] > 3 || nums[i] == nums[i - 1])
        return false;
    return true;
}

bool part_2_is_save(std::vector <int> nums) {
    if (part_1_is_save(nums)) return true;

    for (int i = 0; i < nums.size(); i ++) {
        vector <int> tmp;
        for (int j = 0; j < nums.size(); j ++)
            if (j != i) tmp.push_back(nums[j]);
        if (part_1_is_save(tmp)) return true;
    }

    return false;
}

int main() {
    ifstream file("input.txt");

    string line;
    int ans = 0;
    while (getline(file, line)) {
        if (line.empty()) continue;
        vector<int> nums(1);
        for (char ch: line)
            if (ch == ' ')
                nums.push_back(0);
            else
                nums.back() = nums.back() * 10 + ch - '0';
        if (part_2_is_save(nums)) ans ++; else cout << line + "\n";
    }

    cout << ans << '\n';

    return 0;
}