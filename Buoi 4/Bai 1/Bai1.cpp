#include <iostream>
#include <string>

using namespace std;

bool kiemtrachuoi(const string& s) {
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cout << "Nhap chuoi: ";
    cin >> s;

    if (kiemtrachuoi(s)) {
        cout << "Chuoi chua toan ky so." << endl;
    } else {
        cout << "Chuoi khong chua toan ky so." << endl;
    }

    return 0;
}



