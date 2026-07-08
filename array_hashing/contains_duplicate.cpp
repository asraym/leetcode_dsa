//217 on leetcode 

#include<iostream>
#include<vector>
#include<unordered_set>

class Solution{
public:
    bool containsDuplicate(std::vector<int>& nums){
        std::unordered_set<int> seen;
        for(int num : nums){
            if(seen.contains(num)){
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

int main(){
    int n;
    std::cout << "Enter the n.o of elements: ";
    if(!(std::cin >> n) || n <= 0){
        std::cout << "Invalid array size. \n" ;
        return 1;
    }

    std::vector<int> nums(n);
    std::cout << "Enter elements seperated by spaces : ";
    for(int i = 0; i < n; i++){
        std::cin >> nums[i];
    }

    Solution solver;
    bool hasDuplicate = solver.containsDuplicate(nums);

    std::cout << "Output: " << (hasDuplicate ? "True" : "False") << "\n";

    return 0;
}
