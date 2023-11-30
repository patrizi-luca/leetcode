#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t non_zero_idx = 0;
        for(int i = 0;i < nums.size();i++)
            if(nums[i]!=0)
            {
                // If the current element is non-zero, swap it with the element at nonZeroIndex
                swap(nums[i], nums[non_zero_idx]);
                non_zero_idx++; //Update the non-zero index 
            }
    }
};
