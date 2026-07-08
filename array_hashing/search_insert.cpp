// lc -35

#include<iostream>
#include<vector>

// Brute force approach O(n) T.c , use binary search to get O(logN)
class Solution{
public:
   int searchInsert(std::vector<int> &nums, int target){
       int res;
       if(nums[0] > target){
           res = 0;
           return res;
        }
       for(int i = 0; i < nums.size(); i++){
           if(nums[i] > target){
                   break;
                }
            if(nums[i] == target){
                return i;
            }
            if(nums[i] < target){
                res = i;
            }
        }
        res++;
        return res;
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
    int target;
    std::cout << "Enter the target: ";
    std::cin >> target;

    Solution solver;
    int result = solver.searchInsert(nums, target);

    std::cout << "Insert Index: " << result << std::endl;
    return 0;
}
