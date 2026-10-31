#ifndef HANG_DOI_BENH_VIEN_H
#define HANG_DOI_BENH_VIEN_H

#include <string>
using namespace std;

const int SUC_CHUA_TOI_DA = 100;

struct BenhNhan {
    int maBenhNhan;
    string ten;
    int doUuTien;
    int soThuTu;
};

class HangDoiBenhVien {
private:
    BenhNhan danhSach[SUC_CHUA_TOI_DA];
    int dau;
    int cuoi;
    int soLuong;
    int sttTuDong;

public:
    HangDoiBenhVien();
    bool xepHang(int ma, string ten, int doUuTien);
    bool goiKham(BenhNhan &bn);
    void goiSoTuDong();
    bool laRong();
};

#endif
