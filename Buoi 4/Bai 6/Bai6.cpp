#include <iostream>
#include <string>

using namespace std;

// S? lu?ng sinh vi�n t?i da
const int MAX_STUDENTS = 100;

// C?u tr�c d? luu th�ng tin sinh vi�n
struct Student {
    string name;
    int age;
    string student_id;
};

// H�m nh?p th�ng tin sinh vi�n
void inputStudentList(Student students[], int& n) {
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore(); // B? qua k� t? newline c�n l?i trong b? d?m

    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        cout << "Ten: ";
        getline(cin, students[i].name);
        cout << "Tuoi: ";
        cin >> students[i].age;
        cin.ignore(); // B? qua k� t? newline c�n l?i trong b? d?m
        cout << "Ma sinh vien: ";
        getline(cin, students[i].student_id);
    }
}

// H�m hi?n th? danh s�ch sinh vi�n
void displayStudentList(const Student students[], int n) {
    cout << "\nDanh sach sinh vien:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Ten: " << students[i].name << ", Tuoi: " << students[i].age << ", Ma sinh vien: " << students[i].student_id << '\n';
    }
}

// H�m �p d?ng thu?t to�n Brute Force d? t�m chu?i P trong chu?i T
void bruteForceSearch(const string& T, const string& P) {
    int n = T.length();
    int m = P.length();
    bool found = false;

    cout << "Vi tri cua chuoi P trong chuoi T:\n";
    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && T[i + j] == P[j]) {
            j++;
        }
        if (j == m) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay chuoi P trong chuoi T.";
    }
    cout << '\n';
}

int main() {
    Student students[MAX_STUDENTS];
    int n;

    inputStudentList(students, n);
    displayStudentList(students, n);

    string T, P;
    cout << "\nNhap chuoi T: ";
    cin >> T;
    cout << "Nhap chuoi P: ";
    cin >> P;

    bruteForceSearch(T, P);

    return 0;
}

