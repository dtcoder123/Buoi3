#include <iostream>
#include <string>

bool isPalindrome(const std::string &str) {
    int left = 0;
    int right = str.length() - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}
int main() {
    std::string input;
    std::cout << "Nhap chuoi: ";
    std::getline(std::cin, input);
    
    if (isPalindrome(input)) {
        std::cout << "Chuoi nhap vao la doi xung." << std::endl;
    } else {
        std::cout << "Chuoi nhap vao khong phai la doi xung." << std::endl;
    }

    return 0;
}
