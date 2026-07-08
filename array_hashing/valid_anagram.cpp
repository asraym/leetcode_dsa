//lc 242 

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

class Solution{ 
public:
    bool isAnagram(std::string s, std::string t){
        if (s.length() != t.length()){
            return false;
        }

        std::unordered_map<char, int> count;
        
        for(char ch : s){
            count[ch]++;
        }
        for(char ch : t){
            if(count.find(ch) == count.end() || count[ch] == 0){
                return false;
            }
        }

        return true;
    }
};

int main(){
    std::string s, t;
    std::cout << "Enter the first string : " << std::endl;
    std::cin >> s;
    std::cout << "Enter the second string: " << std::endl;
    std::cin >> t;

    Solution solver;
    bool result = solver.isAnagram(s, t);

    std::cout << "Output: " << (result ? "True" : "False") << "\n";
    return 0;
}

