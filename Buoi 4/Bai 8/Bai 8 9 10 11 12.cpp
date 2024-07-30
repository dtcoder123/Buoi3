#include <iostream>
#include <string>

using namespace std;

// Ham tim vi tri xuat hien cua chuoi s2 trong s1, neu khong co thi noi s2 vao cuoi s1
void findAndAppend(string s1, string s2) {
    int found = -1;
    for (size_t i = 0; i <= s1.length() - s2.length(); ++i) {
        if (s1.substr(i, s2.length()) == s2) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        cout << "Chuoi s2 xuat hien tai vi tri: " << found << endl;
    } else {
        s1 += s2;
        cout << "Chuoi s2 khong xuat hien trong s1. Chuoi moi la: " << s1 << endl;
    }
}

// Ham chen chuoi strInsert vao chuoi str tai vi tri vt
void insertString(string &str, string strInsert, int vt) {
    if (vt >= 0 && vt <= str.length()) {
        str = str.substr(0, vt) + strInsert + str.substr(vt);
        cout << "Chuoi sau khi chen: " << str << endl;
    } else {
        cout << "Vi tri chen khong hop le." << endl;
    }
}

// Ham xoa tat ca cac ky tu cho truoc khoi chuoi
void removeCharacter(string &str, char ch) {
    string result;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] != ch) {
            result += str[i];
        }
    }
    str = result;
    cout << "Chuoi sau khi xoa ky tu '" << ch << "': " << str << endl;
}

// Ham kiem tra chuoi chi chua ky tu so
bool isNumeric(const string &str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}

// Ham tim va in ra nhung chuoi chi chua ky tu so trong mang cac chuoi
void findNumericStrings(string arr[], int n) {
    for (int i = 0; i < n; ++i) {
        if (isNumeric(arr[i])) {
            cout << arr[i] << endl;
        }
    }
}

// Ham tinh so phep bien doi de chuyen chuoi s1 thanh s2
int minDistance(const string &s1, const string &s2) {
    int m = s1.size(), n = s2.size();
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s1, s2, str, strInsert;
    char ch;
    int vt, n;

    // Bai toan 1
    cout << "Nhap chuoi s1: ";
    getline(cin, s1);
    cout << "Nhap chuoi s2: ";
    getline(cin, s2);
    findAndAppend(s1, s2);

    // Bai toan 2
    cout << "\nNhap chuoi str: ";
    getline(cin, str);
    cout << "Nhap chuoi can chen strInsert: ";
    getline(cin, strInsert);
    cout << "Nhap vi tri can chen vt: ";
    cin >> vt;
    cin.ignore(); // Clear newline character from the buffer
    insertString(str, strInsert, vt);

    // Bai toan 3
    cout << "\nNhap chuoi: ";
    getline(cin, str);
    cout << "Nhap ky tu can xoa: ";
    cin >> ch;
    cin.ignore(); // Clear newline character from the buffer
    removeCharacter(str, ch);

    // Bai toan 4
    cout << "\nNhap so luong chuoi: ";
    cin >> n;
    string* arr = new string[n];
    cin.ignore(); // Clear newline character from the buffer
    cout << "Nhap cac chuoi: ";
    for (int i = 0; i < n; ++i) {
        getline(cin, arr[i]);
    }
    cout << "Cac chuoi chi chua ky tu so la: " << endl;
    findNumericStrings(arr, n);

    delete[] arr; // Giai phong bo nho cap phat dong

    // Bai toan 5
    cout << "\nNhap chuoi s1: ";
    getline(cin, s1);
    cout << "Nhap chuoi s2: ";
    getline(cin, s2);
    int result = minDistance(s1, s2);
    cout << "So phep bien doi can thiet: " << result << endl;

    return 0;
}

