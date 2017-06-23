#include <iostream>
#include <array>

bool isAnagram(int& x, int& y){
    std::array<int, 10> num1{0},num2{0};
    std::string         n1 = std::to_string(x);
    std::string         n2 = std::to_string(y);
    
    if(n1.size() != n2.size())
        return false;
    else{
        for(auto i = 0; i < n1.size(); ++i){
            num1[n1[i]-'0']++;
            num2[n2[i]-'0']++;
        }
    }
    return num1 == num2;
}

int main(){
    auto num1 = 125874;
    auto num2 = 251748;
    std::cout << isAnagram(num1, num2) << std::endl;
    return 0;
}