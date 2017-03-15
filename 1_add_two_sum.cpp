#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> result;
            unordered_map<int, int> map;
            for (int i=0; i < nums.size(); i++){
                int toFind = target - nums[i];
                if(map.find(toFind) != map.end()){
                    result = {map[toFind] , i};
                    return result;
                }
                map[nums[i]] = i;

            }

            return result;

        }



};
int main(){
    Solution sol;
    return 0;
}
