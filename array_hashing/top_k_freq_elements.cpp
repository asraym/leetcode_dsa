//lc 347

#include<iostream>
#include<vector>
#include<unordered_map>

class Solution{
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k){
        int n = nums.size();
        std::unordered_map<int,int> count;
        for(int num: nums){
            count[num]++;
        }
        std::vector<std::vector<int>> buckets(n+1);
        for(auto& [num, freq]: count){
            buckets[freq].push_back(num);
        }
        std::vector<int> result;
        for(int i = n; i >= 0; i--){
            for(int num: buckets[i]){
                result.push_back(num);
                if(result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solver;
    int size = 0;
    int k = 0;

    std::cout << "Enter the total number of elements in the array: ";
    if (!(std::cin >> size) || size <= 0) {
        std::cout << "Invalid array size!\n";
        return 1;
    }

    std::vector<int> nums(size);
    std::cout << "Enter " << size << " space-separated integers:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> nums[i];
    }

    std::cout << "Enter the value of K (how many top frequent elements you want): ";
    std::cin >> k;

    if (k <= 0 || k > size) {
        std::cout << "Invalid value for K! It must be between 1 and " << size << ".\n";
        return 1;
    }

   
    std::vector<int> result = solver.topKFrequent(nums, k);

    std::cout << "\nThe top " << k << " most frequent element(s): ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
