#include "HeThongBenhVien.h"
void HeThongBenhVien::sapXepUuTien() {
    for (int i = 0; i < soLuong - 1; ++i) {
        for (int j = i + 1; j < soLuong; ++j) {
            if (danhSach[i].doUuTien < danhSach[j].doUuTien) {
                BenhNhan temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
}
HeThongBenhVien::HeThongBenhVien(int sc) {
    sucChua = sc;
    danhSach = new BenhNhan[sucChua];
    soLuong = 0;
    sttTuDong = 0;
}
HeThongBenhVien::~HeThongBenhVien() {
    delete[] danhSach;
}

void HeThongBenhVien::tiepNhanVaPhanLuong(int ma, string ten, string phong, int doUuTien) {
    if (soLuong >= sucChua) return;

    sttTuDong++;
    BenhNhan bn;
    bn.maBenhNhan = ma;
    bn.ten = ten;
    bn.phongKham = phong;
    bn.doUuTien = doUuTien;
    bn.soThuTu = sttTuDong;

    danhSach[soLuong] = bn;
    soLuong++;
    sapXepUuTien();
}

void HeThongBenhVien::chuyenKhoaCapCuuUuTien(int maBN) {
    for (int i = 0; i < soLuong; ++i) {
        if (danhSach[i].maBenhNhan == maBN) {
            danhSach[i].phongKham = "Khoa Cap Cuu";
            danhSach[i].doUuTien = 999;
            sapXepUuTien();
            cout << "[THONG BAO KHAN] Da chuyen BN " << maBN << " sang Khoa Cap Cuu!\n";
            return;
        }
    }
    cout << "[LOI] Khong tim thay ma benh nhan " << maBN << "\n";
}
void HeThongBenhVien::goiSoTuDong() {
    if (laRong()) return;

    BenhNhan bn = danhSach[0];
    for (int i = 0; i < soLuong - 1; ++i) {
        danhSach[i] = danhSach[i + 1];
    }
    soLuong--;

    cout << "[LOA THONG BAO] Moi BN STT " << bn.soThuTu << " - " << bn.ten
         << " vao " << bn.phongKham << "!\n";
}

void HeThongBenhVien::uocTinhThoiGianCho(int maBN) {
    int thoiGianKhamTrungBinh = 15;
    for (int i = 0; i < soLuong; ++i) {
        if (danhSach[i].maBenhNhan == maBN) {
            int thoiGianCho = i * thoiGianKhamTrungBinh;
            cout << "[TRA CUU] BN " << danhSach[i].ten << " can cho khoang "
                 << thoiGianCho << " phut.\n";
            return;
        }
    }
}
