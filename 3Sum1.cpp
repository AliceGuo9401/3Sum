#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) return {};
    int flag(0);  //标志是否存在vector<int> triplet
    vector<vector<int>> allTriplets;
    sort(nums.begin(), nums.end());                   //按非递减排序
    for (int i = 0; i < nums.size() - 2; ++i) {
        if (i != 0) {                                 //忽略重复的triplet[0]
            if (nums[i] == nums[i - 1])
                continue;                             //continue终止最近的循环中的当前迭代，开始下一次迭代
        }

        int target = 0 -nums[i];
        int left(i + 1), right(nums.size() - 1);      //两端向中间遍历
        while (left < right) {
            int targetTemp = nums[left] + nums[right];
            if (targetTemp < target)
                do                                    //忽略重复的triplet[1]
                    ++left;
                while (nums[left] == nums[left - 1]); //do - while语句

            else if (targetTemp > target)
                do                                    //忽略重复的triplet[2]
                    --right;
                while (nums[right] == nums[right + 1]);

            else if (targetTemp == target) {
                vector<int> triplet{nums[i], nums[left], nums[right]};
                allTriplets.push_back(triplet);
                flag = 1;   //存在vector<int> triplet
                do                                    //忽略重复的triplet[1] ~ [2]
                    ++left;
                while (nums[left] == nums[left - 1] && left <= right);
                do
                    --right;
                while (nums[right] == nums[right + 1] && left <= right);

            }
        }
    }
    if (flag == 1)
        return allTriplets;
    else if (flag ==0)
        return {};
}
int main() {
    vector<int> nums{-2, 0, 0, 2, 2};
    vector<vector<int>> allTriplets = threeSum(nums);
    for (int i = 0; i < allTriplets.size(); ++i) {
        for (int j = 0; j < allTriplets[i].size(); ++j)
            cout << allTriplets[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
