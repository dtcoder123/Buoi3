#include <iostream>
#include <ctime>
#include <cstdlib>
#define MAX 50
using namespace std;

void CreateMatrix(int a[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = rand() % (MAX + 1);
        }
    }
}

void ShowMatrix(int a[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

void SumI(int a[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += a[i][j];
        }
        cout << "Tong dong " << i + 1 << ": " << sum << endl;
    }
}

void xuatPhanTuLonNhatTungCot(int a[MAX][MAX], int n, int m) {
    for (int j = 0; j < m; j++) {
        int max = a[0][j];
        for (int i = 1; i < n; i++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        cout << "Phan tu lon nhat cot " << j << ": " << max << endl;
    }
}

void xuatPhanTuDuongBien(int a[MAX][MAX], int n, int m) {
    cout << "Phan tu duong bien:" << endl;
    for (int j = 0; j < m; j++) {
        cout << a[0][j] << " ";
    }
    for (int i = 1; i < n - 1; i++) {
        cout << a[i][0] << " " << a[i][m - 1] << " ";
    }
    for (int j = 0; j < m; j++) {
        cout << a[n - 1][j] << " ";
    }
    cout << endl;
}

int laCucDai(int a[MAX][MAX], int n, int m, int i, int j) {
    int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    for (int k = 0; k < 8; k++) {
        int ni = i + x[k];
        int nj = j + y[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && a[i][j] <= a[ni][nj]) {
            return 0;
        }
    }
    return 1;
}

void xuatCucDai(int a[MAX][MAX], int n, int m) {
    cout << "Cac phan tu cuc dai:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (laCucDai(a, n, m, i, j)) {
                cout << a[i][j] << " ";
            }
        }
    }
    cout << endl;
}

int laHoangHau(int a[MAX][MAX], int n, int m, int i, int j) {
    for (int k = 0; k < n; k++) {
        if (a[k][j] > a[i][j]) {
            return 0;
        }
    }
    for (int k = 0; k < m; k++) {
        if (a[i][k] > a[i][j]) {
            return 0;
        }
    }
    return 1;
}

void xuatHoangHau(int a[MAX][MAX], int n, int m) {
    cout << "Cac phan tu hoang hau:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (laHoangHau(a, n, m, i, j)) {
                cout << a[i][j] << " ";
            }
        }
    }
    cout << endl;
}

int laDiemYenNgua(int a[MAX][MAX], int n, int m, int i, int j) {
    int maxDong = a[i][j];
    for (int k = 0; k < m; k++) {
        if (a[i][k] > maxDong) {
            maxDong = a[i][k];
        }
    }
    int minCot = a[i][j];
    for (int k = 0; k < n; k++) {
        if (a[k][j] < minCot) {
            minCot = a[k][j];
        }
    }
    return (a[i][j] == maxDong) && (a[i][j] == minCot);
}

void xuatDiemYenNgua(int a[MAX][MAX], int n, int m) {
    cout << "Cac phan tu diem yen ngua:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (laDiemYenNgua(a, n, m, i, j)) {
                cout << a[i][j] << " ";
            }
        }
    }
    cout << endl;
}

void xuatDongToanSoChan(int a[MAX][MAX], int n, int m) {
    cout << "Cac dong chi chua so chan:" << endl;
    for (int i = 0; i < n; i++) {
        int toanChan = 1;
        for (int j = 0; j < m; j++) {
            if (a[i][j] % 2 != 0) {
                toanChan = 0;
                break;
            }
        }
        if (toanChan) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void sapXepTangDanTungDong(int a[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            for (int k = j + 1; k < m; k++) {
                if (a[i][j] > a[i][k]) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
}

int main() {
    int n = 0, m = 0;
    int a[MAX][MAX];
    int luachon = 1;
    srand(time(0));
    while (luachon == 1) {
        cout << "Menu:" << endl;
        cout << "1. Tao ma tran." << endl;
        cout << "2. Xem ma tran." << endl;
        cout << "3. Tinh tong gia tri tung dong" << endl;
        cout << "4. Xuat phan tu lon nhat tung cot" << endl;
        cout << "5. Xuat phan tu duong bien" << endl;
        cout << "6. Xuat cac phan tu cuc dai" << endl;
        cout << "7. Xuat cac phan tu hoang hau" << endl;
        cout << "8. Xuat cac phan tu diem yen ngua" << endl;
        cout << "9. Xuat cac dong chi chua so chan" << endl;
        cout << "10. Sap xep tang dan tung dong" << endl;
        cout << "11. Thoat" << endl;
        int choice;
        cout << "Ban muon lam gi? : ";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Nhap vap so dong: ";
                cin >> n;
                cout << "Nhap vao so cot: ";
                cin >> m;
                CreateMatrix(a, n, m);
                break;
            }
            case 2: {
                if (n == 0 || m == 0) {
                    cout << "Ma tran chua duoc tao!" << endl;
                } else {
                    ShowMatrix(a, n, m);
                }
                break;
            }
            case 3: {
                if (n == 0 || m == 0) {
                    cout << "Ma tran chua duoc tao!" << endl;
                } else {
                    SumI(a, n, m);
                }
                break;
            }
            case 4: {
                if (n == 0 || m == 0) {
                    cout << "Ma tran chua duoc tao!" << endl;
                } else {
                    xuatPhanTuLonNhatTungCot(a, n, m);
                }
                break;
            }
            case 5: {
                if (n == 0 || m == 0) {
                    cout << "Ma tran chua duoc tao!" << endl;
                } else {
                    xuatPhanTuDuongBien(a, n, m);
                }
                break;
            }
            case 6: {
                if (n == 0 || m == 0) {
                    cout << "Ma tran chua duoc tao!" << endl;
                } else {
                    xuatCucDai(a, n, m);
                }
                break;
            }
            case 7: {
                if (n == 0 || m == 0) {
                    cout << "Ma tran chua duoc tao!" << endl;
                } else {
                    xuatHoangHau(a, n, m);
                }
                break;
            }
            case 8: {
                if (n == 0 || m == 0) {
                    cout << "Ma tran chua duoc tao!" << endl;
                } else {
                    xuatDiemYenNgua(a, n, m);
                }
                break;
            }
            case 9: {
                if (n == 0 || m == 0) {
                    cout << "Ma tran chua duoc tao!" << endl;
                } else {
                    xuatDongToanSoChan(a, n, m);
                }
                break;
            }
            case 10: {
                if (n == 0 || m == 0) {
                    cout << "Ma tran chua duoc tao!" << endl;
                } else {
                    sapXepTangDanTungDong(a, n, m);
                    ShowMatrix(a, n, m);
                }
                break;
            }
            case 11: {
                luachon = 0;
                break;
            }
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }
    }
    return 0;
}

