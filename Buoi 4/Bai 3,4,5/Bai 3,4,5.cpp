#include <iostream>

using namespace std;

// Ham xoa khoang trang thua trong chuoi
void chuanHoaChuoi(const char* input, char* output) {
    int j = 0;
    bool inWord = false;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != ' ') {
            if (inWord && j > 0) {
                output[j++] = ' ';
            }
            while (input[i] != ' ' && input[i] != '\0') {
                output[j++] = input[i++];
            }
            inWord = true;
            if (input[i] == '\0') break;
        }
    }
    output[j] = '\0';
}

// Ham tim kiem ten trong chuoi ho ten
bool timKiemTen(const char* hoTen, const char* ten) {
    int i = 0, j = 0;
    while (hoTen[i] != '\0') {
        if (hoTen[i] == ten[j]) {
            int start = i;
            while (hoTen[i] == ten[j] && ten[j] != '\0') {
                i++;
                j++;
            }
            if (ten[j] == '\0' && (hoTen[i] == ' ' || hoTen[i] == '\0')) {
                return true;
            }
            j = 0;
        }
        while (hoTen[i] != ' ' && hoTen[i] != '\0') {
            i++;
        }
        while (hoTen[i] == ' ') {
            i++;
        }
    }
    return false;
}

// Ham cat chuoi ho ten thanh chuoi ho lot va ten
void catChuoi(const char* hoTen, char* hoLot, char* ten) {
    int len = 0;
    while (hoTen[len] != '\0') {
        len++;
    }

    int lastSpace = -1;
    for (int i = len - 1; i >= 0; i--) {
        if (hoTen[i] == ' ') {
            lastSpace = i;
            break;
        }
    }

    if (lastSpace == -1) {
        hoLot[0] = '\0';
        for (int i = 0; i <= len; i++) {
            ten[i] = hoTen[i];
        }
    } else {
        for (int i = 0; i < lastSpace; i++) {
            hoLot[i] = hoTen[i];
        }
        hoLot[lastSpace] = '\0';

        for (int i = lastSpace + 1, j = 0; i <= len; i++, j++) {
            ten[j] = hoTen[i];
        }
    }
}

int main() {
    // Vi du chuan hoa chuoi
    char chuoi[] = "   Nguyen     Van   Anh   ";
    char chuoiChuanHoa[100];
    chuanHoaChuoi(chuoi, chuoiChuanHoa);
    cout << "Chuoi chuan hoa: \"" << chuoiChuanHoa << "\"" << endl;

    // Vi du tim kiem ten
    if (timKiemTen(chuoiChuanHoa, "Anh")) {
        cout << "Ten \"Anh\" ton tai trong chuoi \"" << chuoiChuanHoa << "\"." << endl;
    } else {
        cout << "Ten \"Anh\" khong ton tai trong chuoi \"" << chuoiChuanHoa << "\"." << endl;
    }

    if (timKiemTen(chuoiChuanHoa, "Mai")) {
        cout << "Ten \"Mai\" ton tai trong chuoi \"" << chuoiChuanHoa << "\"." << endl;
    } else {
        cout << "Ten \"Mai\" khong ton tai trong chuoi \"" << chuoiChuanHoa << "\"." << endl;
    }

    // Vi du cat chuoi
    char hoLot[100], ten[100];
    catChuoi(chuoiChuanHoa, hoLot, ten);
    cout << "Ho lot: \"" << hoLot << "\", Ten: \"" << ten << "\"" << endl;

    return 0;
}

