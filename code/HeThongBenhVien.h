#ifndef HE_THONG_BENH_VIEN_H
#define HE_THONG_BENH_VIEN_H

#include <iostream>
#include <string>
#include "../include/CauTrucDuLieu.h"
using namespace std;

const int SO_PHONG_TOI_DA = 10;
const int PHUT_MOI_LUOT = 15;

struct PhongKham {
    string ten;
    HangDoi hangThuong;
    HangDoiUuTien hangCapCuu;
};

class HeThongBenhVien {
private:
    PhongKham phong[SO_PHONG_TOI_DA];
    int soPhong;
    int sucChua;
    int soLuong;
    int sttTuDong;
    HangDoiHaiDau lichSuGoi;

    int timPhong(string tenPhong);
    int taoPhong(string tenPhong);
    bool timBenhNhan(int ma, BenhNhan &bn, int &viTriPhong, bool &capCuu);

public:
    HeThongBenhVien(int sc);
    bool tiepNhanVaPhanLuong(int ma, string ten, string tenPhong, int doUuTien);
    bool chuyenKhoaCapCuuUuTien(int maBN);
    bool goiSoTuDong(string tenPhong = "");
    int thoiGianChoDuKien(int maBN);
    void uocTinhThoiGianCho(int maBN);
    void hienThiBangDienTu();
    void thongKePhongKham(string tenPhong);
    void hienThiLichSuGoi();
    bool laRong();
    int kichThuoc();
};

#endif
