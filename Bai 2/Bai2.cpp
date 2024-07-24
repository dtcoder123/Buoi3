#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void taoMaTran(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100;  
        }
    }
}

void xuatMaTran(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void xuatDuongCheoChinh(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i][i]);
    }
    printf("\n");
}

void xuatDuongCheoSongSong(int a[MAX][MAX], int n) {
    for (int k = 1; k < n; k++) {
        for (int i = 0, j = k; j < n; i++, j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for (int k = 1; k < n; k++) {
        for (int i = k, j = 0; i < n; i++, j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int timMaxTamGiacTren(int a[MAX][MAX], int n) {
    int max = a[0][1];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    return max;
}

void sapXepZigZag(int a[MAX][MAX], int n) {
    int temp[MAX * MAX];
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[index++] = a[i][j];
        }
    }

    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (temp[i] > temp[j]) {
                int tmp = temp[i];
                temp[i] = temp[j];
                temp[j] = tmp;
            }
        }
    }

    index = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                a[i][j] = temp[index++];
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                a[i][j] = temp[index++];
            }
        }
    }
}

void sapXepDuongCheoChinh(int a[MAX][MAX], int n) {
    int temp[MAX];

    for (int i = 0; i < n; i++) {
        temp[i] = a[i][i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                int tmp = temp[i];
                temp[i] = temp[j];
                temp[j] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        a[i][i] = temp[i];
    }
}

int main() {
    int n;
    int a[MAX][MAX];
    int choice;
    int initialized = 0;

    srand(time(0));

    while (1) {
        printf("Menu:\n");
        printf("1. Tao ma tran\n");
        printf("2. Xuat ma tran\n");
        printf("3. Xuat cac phan tu tren duong cheo chinh\n");
        printf("4. Xuat cac phan tu thuoc duong cheo song song voi duong cheo chinh\n");
        printf("5. Tim phan tu lon nhat thuoc tam giac tren cua duong cheo chinh\n");
        printf("6. Sap xep ma tran theo zig-zag\n");
        printf("7. Sap xep duong cheo chinh tang dan\n");
        printf("8. Thoat\n");
        printf("Ban muon lam gi? : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap cap cua ma tran (n >= 5): ");
                scanf("%d", &n);
                if (n < 5) {
                    printf("Cap cua ma tran phai lon hon hoac bang 5.\n");
                } else {
                    taoMaTran(a, n);
                    initialized = 1;
                    printf("Ma tran ngau nhien da duoc tao.\n");
                }
                break;
            case 2:
                if (!initialized) {
                    printf("Ma tran chua duoc tao!\n");
                } else {
                    printf("Ma tran ngau nhien:\n");
                    xuatMaTran(a, n);
                }
                break;
            case 3:
                if (!initialized) {
                    printf("Ma tran chua duoc tao!\n");
                } else {
                    printf("Cac phan tu tren duong cheo chinh:\n");
                    xuatDuongCheoChinh(a, n);
                }
                break;
            case 4:
                if (!initialized) {
                    printf("Ma tran chua duoc tao!\n");
                } else {
                    printf("Cac phan tu thuoc duong cheo song song voi duong cheo chinh:\n");
                    xuatDuongCheoSongSong(a, n);
                }
                break;
            case 5:
                if (!initialized) {
                    printf("Ma tran chua duoc tao!\n");
                } else {
                    int max = timMaxTamGiacTren(a, n);
                    printf("Phan tu lon nhat thuoc tam giac tren cua duong cheo chinh: %d\n", max);
                }
                break;
            case 6:
                if (!initialized) {
                    printf("Ma tran chua duoc tao!\n");
                } else {
                    printf("Ma tran sau khi sap xep zig-zag:\n");
                    sapXepZigZag(a, n);
                    xuatMaTran(a, n);
                }
                break;
            case 7:
                if (!initialized) {
                    printf("Ma tran chua duoc tao!\n");
                } else {
                    printf("Duong cheo chinh sau khi sap xep tang dan:\n");
                    sapXepDuongCheoChinh(a, n);
                    xuatMaTran(a, n);
                }
                break;
            case 8:
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}

