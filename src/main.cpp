#include "HeThongBenhVien.h"
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    HeThongBenhVien ht(100);
    ht.tiepNhanVaPhanLuong(101, "Nguyen Van A", "Phong Kham Noi", 1);
    ht.tiepNhanVaPhanLuong(102, "Tran Thi B", "Phong Kham Ngoai", 1);
    ht.tiepNhanVaPhanLuong(103, "Le Van C", "Phong Kham Tim Mach", 2);
    ht.tiepNhanVaPhanLuong(104, "Phan Thi D", "Phong Kham Noi", 1);
    ht.hienThiBangDienTu();
    ht.uocTinhThoiGianCho(102);
    ht.thongKePhongKham("Phong Kham Noi");
    cout << "\n";
    ht.chuyenKhoaCapCuuUuTien(104);
    ht.hienThiBangDienTu();
    cout << "\n--- BAT DAU GOI KHAM ---\n";
    while (!ht.laRong()) {
        ht.goiSoTuDong();
    }
    return 0;
}

