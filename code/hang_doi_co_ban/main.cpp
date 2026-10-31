#include "HangDoiBenhVien.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (!cin || n < 1 || n > SUC_CHUA_TOI_DA) {
        cout << "So benh nhan phai tu 1 den " << SUC_CHUA_TOI_DA << ".\n";
        return 1;
    }

    HangDoiBenhVien hd;
    for (int i = 0; i < n; i++) {
        int ma, doUuTien;
        string ten;
        cin >> ma;
        cin.ignore(1000, '\n');
        getline(cin, ten);
        cin >> doUuTien;
        if (!cin || !hd.xepHang(ma, ten, doUuTien)) {
            cout << "Thong tin benh nhan khong hop le hoac hang doi da day.\n";
            return 1;
        }
    }

    while (!hd.laRong()) hd.goiSoTuDong();
    return 0;
}
