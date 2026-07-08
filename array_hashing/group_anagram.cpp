//lc 49 

#include <bits/stdc++.h>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<std::string>> gr_an(std::vector<std::string> &strs) {
        std::unordered_map<std::string, std::vector<std::string>> mp;
        for (std::string s : strs) {
            std::string key = s;
            std::sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        std::vector<std::vector<std::string>> result;
        for (auto pair : mp) {
            result.push_back(pair.second);
        }
        return result;
    }
};

int main() {
    int n;
    std::cout << "Enter the number of strings: \n";
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Invalid vector size\n";
        return 1;
    }
    
    std::vector<std::string> strs(n); 
    std::cout << "Enter the strings separated by space:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> strs[i];
    }

    Solution solver;
    std::vector<std::vector<std::string>> result = solver.gr_an(strs);
    
    for (size_t i = 0; i < result.size(); i++) { 
        std::cout << "Anagram Group " << i + 1 << ": ";
        for (const std::string& item : result[i]) {
            std::cout << "[" << item << "] ";
        }
        std::cout << "\n";
    }
    return 0;
}
    
