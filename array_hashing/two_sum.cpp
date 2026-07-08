#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twosum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        for (size_t i = 0; i < nums.size(); i++) {
            int compliment = target - nums[i];
            auto it = seen.find(compliment);
            if (it != seen.end()) {
                return {it->second, static_cast<int>(i)};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Invalid vector size.\n";
        return 1; 
    }

    std::vector<int> nums(n);
    std::cout << "Enter elements separated by space:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    int target;
    std::cout << "Enter the target: \n";
    std::cin >> target;

    Solution solver;
    std::vector<int> result = solver.twosum(nums, target);
    
    if (!(result.empty())) {
        std::cout << "Output indices: " << result[0] << " " << result[1] << "\n";
    } else {
        std::cout << "No solution found\n";
    }

    return 0;
}

