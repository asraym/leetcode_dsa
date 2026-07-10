#include<iostream>
#include<vector>
#include<unordered_set>

class Solution{
public:
    int lcs(std::vector<int>& nums){
        int lcs = 0;
        std::unordered_set<int> set(nums.begin(), nums.end());
        for(int num: set){
            if(set.find(num-1) == set.end()){
                int c_num = num;
                int c_streak = 1;
                while(set.find(c_num+1) != set.end()){
                    c_num += 1;
                    c_streak += 1;
                }
                lcs = std::max(lcs, c_streak);
            }
        }
        return lcs;
    }
};


int main(){
    int n;
    std::cout << "Enter the number of elements: ";
    if(!(std::cin >> n) || n <= 0){
        std::cin >> n;
    }
    std::vector<int> nums(n);
    std::cout << "Enter the elements seperated by space:" << std::endl;
    for(int i = 0; i < n; i++){
        std::cin >> nums[i];
    }
    Solution solver;
    int result = solver.lcs(nums);
    std::cout << "The number of largest common subsequence is: " << result;

    return 0;
}
