#include <iostream>
#include <time.h>
#include <stdlib.h>
#define MAX 50
using namespace std;

void CreateMatrix(int a[][MAX], int n, int m) {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = rand() % (MAX + 1);
        }
    }
} 

void ShowMatrix(int a[][MAX], int n, int m) {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] <<"\t";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    int a[MAX][MAX];
    int luachon = 1;
    srand(time(0));
    
    while(luachon == 1) {
        cout <<"Menu:"<< endl;
        cout <<"1. Tao ma tran."<< endl;
        cout <<"2. Xem ma tran."<< endl;
        
        int choice;
        cout << "Ban muon lam gi? : ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                cout << "Nhap vap so dong: ";
                cin >> n;
                cout << "Nhap vao so cot: ";
                cin >> m;   
                CreateMatrix(a, n, m);
                break;
            }
            case 2: {
                ShowMatrix(a, n, m);
                break;
            }    
            default:
                break;
        }
    }
    
    return 0;
}
