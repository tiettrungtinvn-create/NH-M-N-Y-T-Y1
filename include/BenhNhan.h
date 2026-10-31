#ifndef BENH_NHAN_H
#define BENH_NHAN_H

#include <string>
using namespace std;

struct BenhNhan {
    int maBenhNhan;
    string ten;
    string phongKham;
    int doUuTien;
    int soThuTu;

    // Số lớn hơn được ưu tiên; cùng mức thì số thứ tự nhỏ hơn đi trước.
    bool operator<(const BenhNhan& khac) const {
        if (doUuTien != khac.doUuTien) return doUuTien < khac.doUuTien;
        return soThuTu > khac.soThuTu;
    }
};

#endif
