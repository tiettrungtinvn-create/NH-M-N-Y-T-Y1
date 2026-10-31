#include "HangDoiBenhVien.h"
#include <iostream>
using namespace std;

HangDoiBenhVien::HangDoiBenhVien() {
    dau = 0;
    cuoi = -1;
    soLuong = 0;
    sttTuDong = 0;
}

bool HangDoiBenhVien::xepHang(int ma, string ten, int doUuTien) {
    if (soLuong == SUC_CHUA_TOI_DA || ma <= 0 || ten == "" ||
        doUuTien < 1 || doUuTien > 5) {
        return false;
    }

    BenhNhan bn;
    bn.maBenhNhan = ma;
    bn.ten = ten;
    bn.doUuTien = doUuTien;
    bn.soThuTu = sttTuDong + 1;

    if (soLuong == 0) {
        cuoi = (cuoi + 1) % SUC_CHUA_TOI_DA;
        danhSach[cuoi] = bn;
        soLuong++;
        sttTuDong++;
        return true;
    }

    int i = cuoi;
    int viTriTiepTheo = (cuoi + 1) % SUC_CHUA_TOI_DA;
    int soPhanTuDaKiemTra = 0;

    // Số ưu tiên lớn hơn đứng trước; cùng mức thì giữ thứ tự đến.
    while (soPhanTuDaKiemTra < soLuong &&
           danhSach[i].doUuTien < bn.doUuTien) {
        danhSach[viTriTiepTheo] = danhSach[i];
        viTriTiepTheo = i;
        i = (i - 1 + SUC_CHUA_TOI_DA) % SUC_CHUA_TOI_DA;
        soPhanTuDaKiemTra++;
    }

    danhSach[viTriTiepTheo] = bn;
    cuoi = (cuoi + 1) % SUC_CHUA_TOI_DA;
    soLuong++;
    sttTuDong++;
    return true;
}

bool HangDoiBenhVien::goiKham(BenhNhan &bn) {
    if (laRong()) return false;
    bn = danhSach[dau];
    dau = (dau + 1) % SUC_CHUA_TOI_DA;
    soLuong--;
    return true;
}

void HangDoiBenhVien::goiSoTuDong() {
    BenhNhan bn;
    if (!goiKham(bn)) {
        cout << "[LOA THONG BAO] Hien tai khong co benh nhan trong hang doi.\n";
        return;
    }
    cout << "[LOA THONG BAO] Xin moi benh nhan STT " << bn.soThuTu
         << " - " << bn.ten << " (Ma BN: " << bn.maBenhNhan << ")"
         << " den Phong Kham!\n";
}

bool HangDoiBenhVien::laRong() {
    return soLuong == 0;
}
