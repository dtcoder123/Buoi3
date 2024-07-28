#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 100

using namespace std;

void taoMaTran(int a[MAX][MAX], int m, int n, int min, int max) {
    srand(time(0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = min + rand() % (max - min + 1);
        }
    }
}

void xuatMaTran(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

void xuatCotToanSoLe(int a[MAX][MAX], int m, int n) {
    cout << "Cac cot chi chua so le:" << endl;
    for (int j = 0; j < n; j++) {
        bool toanLe = true;
        for (int i = 0; i < m; i++) {
            if (a[i][j] % 2 == 0) {
                toanLe = false;
                break;
            }
        }
        if (toanLe) {
            cout << "Cot " << j << ": ";
            for (int i = 0; i < m; i++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int timMaxBien(int a[MAX][MAX], int m, int n) {
    int maxBien = a[0][0];
    for (int j = 0; j < n; j++) {
        if (a[0][j] > maxBien) maxBien = a[0][j];
        if (a[m-1][j] > maxBien) maxBien = a[m-1][j];
    }
    for (int i = 1; i < m-1; i++) {
        if (a[i][0] > maxBien) maxBien = a[i][0];
        if (a[i][n-1] > maxBien) maxBien = a[i][n-1];
    }
    return maxBien;
}

int demSo2(int n) {
    while (n > 0) {
        if (n % 10 == 2) return 1;
        n /= 10;
    }
    return 0;
}

int demSoChuSo2(int a[MAX][MAX], int m, int n) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (demSo2(a[i][j])) {
                dem++;
            }
        }
    }
    return dem;
}

bool laCucTieu(int a[MAX][MAX], int m, int n, int i, int j) {
    int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int k = 0; k < 8; k++) {
        int ni = i + x[k];
        int nj = j + y[k];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && a[i][j] >= a[ni][nj]) {
            return false;
        }
    }
    return true;
}

void xuatCucTieu(int a[MAX][MAX], int m, int n) {
    cout << "Cac phan tu cuc tieu:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laCucTieu(a, m, n, i, j)) {
                cout << a[i][j] << " ";
            }
        }
    }
    cout << endl;
}

void sapXepDongTangGiam(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((i % 2 == 0 && a[i][j] < a[i][k]) || (i % 2 != 0 && a[i][j] > a[i][k])) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
}

void sapXepCotTangGiam(int a[MAX][MAX], int m, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m - 1; i++) {
            for (int k = i + 1; k < m; k++) {
                if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
}

bool kiemTraZicZac(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] <= a[i][j + 1] || a[i][j] <= a[i + 1][j]) {
                return false;
            }
        }
    }
    return true;
}

void lietKeDongToanSoChan(int a[MAX][MAX], int m, int n) {
    cout << "Cac dong chi chua so chan:" << endl;
    for (int i = 0; i < m; i++) {
        bool toanChan = true;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                toanChan = false;
                break;
            }
        }
        if (toanChan) {
            cout << "Dong " << i << endl;
        }
    }
}

void lietKeDongGiamDan(int a[MAX][MAX], int m, int n) {
    cout << "Cac dong chua gia tri giam dan:" << endl;
    for (int i = 0; i < m; i++) {
        bool giamDan = true;
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] < a[i][j + 1]) {
                giamDan = false;
                break;
            }
        }
        if (giamDan) {
            cout << "Dong " << i << endl;
        }
    }
}

int timGiaTriXuatHienNhieuNhat(int a[MAX][MAX], int m, int n) {
    int maxCount = 0;
    int maxValue = a[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < n; l++) {
                    if (a[i][j] == a[k][l]) {
                        count++;
                    }
                }
            }
            if (count > maxCount) {
                maxCount = count;
                maxValue = a[i][j];
            }
        }
    }
    return maxValue;
}

void lietKeChuSoXuatHienNhieuNhat(int a[MAX][MAX], int m, int n) {
    int count[10] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int temp = a[i][j];
            while (temp > 0) {
                count[temp % 10]++;
                temp /= 10;
            }
        }
    }
    int maxCount = 0;
    for (int i = 0; i < 10; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
        }
    }
    cout << "Cac chu so xuat hien nhieu nhat:" << endl;
    for (int i = 0; i < 10; i++) {
        if (count[i] == maxCount) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void lietKeCotTongNhoNhat(int a[MAX][MAX], int m, int n) {
    int minSum = 0;
    for (int i = 0; i < m; i++) {
        minSum += a[i][0];
    }
    for (int j = 1; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += a[i][j];
        }
        if (sum < minSum) {
            minSum = sum;
        }
    }
    cout << "Cac cot co tong nho nhat:" << endl;
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += a[i][j];
        }
        if (sum == minSum) {
            cout << "Cot " << j << endl;
        }
    }
}

void hoanViHaiCot(int a[MAX][MAX], int m, int n, int i, int j) {
    for (int k = 0; k < m; k++) {
        int temp = a[k][i];
        a[k][i] = a[k][j];
        a[k][j] = temp;
    }
}

void hoanViHaiDong(int a[MAX][MAX], int m, int n, int i, int j) {
    for (int k = 0; k < n; k++) {
        int temp = a[i][k];
        a[i][k] = a[j][k];
        a[j][k] = temp;
    }
}

int main() {
    int m, n;
    int a[MAX][MAX];

    cout << "Nhap so dong m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    taoMaTran(a, m, n, 0, 20);
    cout << "Ma tran:" << endl;
    xuatMaTran(a, m, n);

    cout << "\nCac cot chi chua so le:" << endl;
    xuatCotToanSoLe(a, m, n);

    cout << "\nPhan tu lon nhat tren bien: " << timMaxBien(a, m, n) << endl;

    cout << "\nSo phan tu co chu so 2: " << demSoChuSo2(a, m, n) << endl;

    cout << "\nCac phan tu cuc tieu:" << endl;
    xuatCucTieu(a, m, n);

    cout << "\nSap xep cac dong tang/giam dan:" << endl;
    sapXepDongTangGiam(a, m, n);
    xuatMaTran(a, m, n);

    cout << "\nSap xep cac cot tang/giam dan:" << endl;
    sapXepCotTangGiam(a, m, n);
    xuatMaTran(a, m, n);

    cout << "\nKiem tra ma tran giam dan theo zic zac: " << (kiemTraZicZac(a, m, n) ? "Co" : "Khong") << endl;

    cout << "\nCac dong chi chua so chan:" << endl;
    lietKeDongToanSoChan(a, m, n);

    cout << "\nCac dong chua gia tri giam dan:" << endl;
    lietKeDongGiamDan(a, m, n);

    cout << "\nGia tri xuat hien nhieu nhat: " << timGiaTriXuatHienNhieuNhat(a, m, n) << endl;

    cout << "\nCac chu so xuat hien nhieu nhat:" << endl;
    lietKeChuSoXuatHienNhieuNhat(a, m, n);

    cout << "\nCac cot co tong nho nhat:" << endl;
    lietKeCotTongNhoNhat(a, m, n);

    cout << "\nHoan vi cot 1 va 2:" << endl;
    hoanViHaiCot(a, m, n, 1, 2);
    xuatMaTran(a, m, n);

    cout << "\nHoan vi dong 1 va 2:" << endl;
    hoanViHaiDong(a, m, n, 1, 2);
    xuatMaTran(a, m, n);

    return 0;
}

