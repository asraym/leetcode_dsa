#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string encode(std::vector<std::string>& strs) {
        std::string result = "";
        std::vector<int> sizes;
        for(const std::string& s: strs){
            sizes.push_back(s.size());
        }
        for(int sz: sizes){
            result += std::to_string(sz) + ',';
        }
        result += '#';
        for(const std::string& s: strs){
            result += s;
        }
        return result;
    }

    std::vector<std::string> decode(std::string& s) {
        if(s.empty()) return {};
        std::vector<int> sizes;
        std::vector<std::string> result;
        int i = 0;
        
        while(s[i] != '#'){
            std::string curr = "";
            
            while(s[i] != ','){
                curr += s[i];
                i++;
            }
            sizes.push_back(std::stoi(curr));
            i++;
        }
        i++;  
        for(int sz: sizes){
            result.push_back(s.substr(i, sz));
            i += sz;
        }
        return result;
    }
};

int main() {
    Solution solver;
    int count = 0;

    std::cout << "Enter number of strings to encode: ";
    if (!(std::cin >> count) || count < 0) {
        std::cout << "Invalid count!\n";
        return 1;
    }
    std::cin.ignore();

    std::vector<std::string> input_strs(count);
    if (count > 0) {
        std::cout << "Enter your " << count << " strings (press Enter after each):\n";
        for (int i = 0; i < count; i++) {
            std::getline(std::cin, input_strs[i]);
        }
    }

    std::string encoded_str = solver.encode(input_strs);
    std::cout << "\n[Your Encoded Output]: \"" << encoded_str << "\"\n";

    std::vector<std::string> decoded_strs = solver.decode(encoded_str);
    
    std::cout << "\n[Your Decoded Output]:\n";
    for (size_t i = 0; i < decoded_strs.size(); i++) {
        std::cout << i + 1 << ": \"" << decoded_strs[i] << "\"\n";
    }

    if (input_strs == decoded_strs) {
        std::cout << "\nSUCCESS: Original and Decoded strings match perfectly!\n";
    } else {
        std::cout << "\nFAILURE: Decoded strings do not match original input.\n";
    }

    return 0;
}

