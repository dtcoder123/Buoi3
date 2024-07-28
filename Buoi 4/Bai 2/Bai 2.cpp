#include <iostream>
#include <string>
#include <cctype> 
using namespace std;
string chuyenDoiChu(string s) {
    bool dauTu = true; 

    for (size_t i = 0; i < s.length(); ++i) {
        if (isspace(s[i])) {
            dauTu = true;
        } else if (dauTu) {
            s[i] = toupper(s[i]);
            dauTu = false;
        } else {
            s[i] = tolower(s[i]);
        }
    }

    return s;
}

int main() {
    string s;
    cout << "Nhap chuoi: ";
    getline(cin, s);

    string ketQua = chuyenDoiChu(s);
    cout << "Chuoi sau khi chuyen doi: " << ketQua << endl;

    return 0;
}
