#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() == 0)
        return {};
    vector<vector<int>> allTriplets;

    for (auto iter1 = nums.begin(); iter1 < nums.end() - 2; ++iter1) {
        int target = 0 - *iter1;
        for (auto iter2 = iter1 + 1; iter2 < nums.end() - 1; ++iter2) {
            int target1 = target - *iter2;
            auto iter3 = find(iter2 + 1, nums.end(), target1);  /**/
            if (iter3 != nums.end()) {
                vector<int> triplets;
                triplets.push_back(*iter1);
                triplets.push_back(*iter2);
                triplets.push_back(*iter3);
                sort(triplets.begin(), triplets.end()); //sort定义在头文件algorithm中，重排输入序列中的元素，<
                allTriplets.push_back(triplets);
            }
        }
    }
    /*消除重复：sort -> unique -> *.erase*/
    sort(allTriplets.begin(), allTriplets.end());
    auto endUnique = unique(allTriplets.begin(), allTriplets.end());  //返回指向不重复区域之后一个位置的迭代器
    allTriplets.erase(endUnique, allTriplets.end());  //erase成员删除重复
    return allTriplets;
}
int main() {
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> allTriplets = threeSum(nums);
    for (int i = 0; i < allTriplets.size(); ++i) {
        for(int j = 0; j < 3; ++j) {
            cout << allTriplets[i][j]<< ' ';
        }
        cout << endl;
    }
    return 0;
}
