#include "../include/CauTrucDuLieu.h"
#include <iostream>
using namespace std;

BenhNhan taoBenhNhan(int ma, int uuTien, int stt) {
    BenhNhan bn;
    bn.maBenhNhan = ma;
    bn.ten = "Benh nhan mau";
    bn.phongKham = "P101";
    bn.doUuTien = uuTien;
    bn.soThuTu = stt;
    return bn;
}

bool kiemTra(bool dung, string tenCa) {
    if (!dung) cout << "LOI: " << tenCa << '\n';
    return dung;
}

int main() {
    BenhNhan bn;
    HangDoi thuong;
    if (!kiemTra(!thuong.lay(bn), "HangDoi rong")) return 1;
    for (int i = 1; i <= 100; i++)
        if (!kiemTra(thuong.them(taoBenhNhan(i, i % 5 + 1, i)), "HangDoi them")) return 1;
    if (!kiemTra(!thuong.them(taoBenhNhan(101, 1, 101)), "HangDoi day")) return 1;
    if (!kiemTra(thuong.xemDau(bn) && bn.maBenhNhan == 1 &&
                 thuong.kichThuoc() == 100, "HangDoi xem dau")) return 1;
    for (int i = 1; i <= 80; i++) {
        if (!kiemTra(thuong.lay(bn) && bn.maBenhNhan == i, "HangDoi FIFO")) return 1;
    }
    for (int i = 101; i <= 180; i++)
        if (!kiemTra(thuong.them(taoBenhNhan(i, 1, i)), "HangDoi them sau khi lay bot")) return 1;
    for (int i = 81; i <= 180; i++) {
        if (!kiemTra(thuong.lay(bn) && bn.maBenhNhan == i, "HangDoi FIFO sau khi lay bot")) return 1;
    }
    if (!kiemTra(thuong.laRong(), "HangDoi lay het")) return 1;
    if (!kiemTra(thuong.them(taoBenhNhan(181, 1, 181)) &&
                 thuong.lay(bn) && bn.maBenhNhan == 181 && thuong.laRong(),
                 "HangDoi them lai sau khi rong")) return 1;
    thuong.them(taoBenhNhan(1, 1, 1));
    thuong.them(taoBenhNhan(2, 1, 2));
    thuong.them(taoBenhNhan(3, 1, 3));
    if (!kiemTra(thuong.layTheoMa(2, bn) && bn.maBenhNhan == 2 &&
                 thuong.layTheoMa(3, bn) && bn.maBenhNhan == 3 &&
                 thuong.layTheoMa(1, bn) && bn.maBenhNhan == 1 &&
                 thuong.laRong(), "HangDoi xoa giua cuoi dau")) return 1;

    HangDoiUuTien uuTien;
    if (!kiemTra(!uuTien.lay(bn), "HangDoiUuTien rong")) return 1;
    for (int i = 1; i <= 100; i++)
        if (!kiemTra(uuTien.them(taoBenhNhan(i, i % 5 + 1, i)), "HangDoiUuTien them")) return 1;
    if (!kiemTra(!uuTien.them(taoBenhNhan(101, 5, 101)), "HangDoiUuTien day")) return 1;
    if (!kiemTra(uuTien.xemDau(bn) && bn.doUuTien == 5 &&
                 uuTien.kichThuoc() == 100, "HangDoiUuTien xem dau")) return 1;
    for (int muc = 5; muc >= 1; muc--) {
        for (int i = 1; i <= 100; i++) {
            if (i % 5 + 1 == muc) {
                if (!kiemTra(uuTien.lay(bn) && bn.maBenhNhan == i,
                             "Uu tien va FIFO cung muc")) return 1;
            }
        }
    }
    if (!kiemTra(uuTien.laRong(), "HangDoiUuTien lay het")) return 1;
    uuTien.them(taoBenhNhan(1, 2, 1));
    uuTien.them(taoBenhNhan(2, 5, 2));
    uuTien.them(taoBenhNhan(3, 3, 3));
    if (!kiemTra(uuTien.layTheoMa(3, bn) && bn.maBenhNhan == 3 &&
                 uuTien.lay(bn) && bn.maBenhNhan == 2 &&
                 uuTien.lay(bn) && bn.maBenhNhan == 1,
                 "HangDoiUuTien xoa giua giu thu tu")) return 1;

    HangDoiHaiDau haiDau;
    if (!kiemTra(!haiDau.layDau(bn) && !haiDau.layCuoi(bn), "HangDoiHaiDau rong")) return 1;
    if (!kiemTra(haiDau.themDau(taoBenhNhan(1, 1, 1)) &&
                 haiDau.themCuoi(taoBenhNhan(2, 1, 2)) &&
                 haiDau.themDau(taoBenhNhan(3, 1, 3)), "HangDoiHaiDau them hai dau")) return 1;
    if (!kiemTra(haiDau.layDau(bn) && bn.maBenhNhan == 3, "HangDoiHaiDau lay dau")) return 1;
    if (!kiemTra(haiDau.layCuoi(bn) && bn.maBenhNhan == 2, "HangDoiHaiDau lay cuoi")) return 1;
    if (!kiemTra(haiDau.layDau(bn) && bn.maBenhNhan == 1, "HangDoiHaiDau con lai")) return 1;
    for (int i = 1; i <= 100; i++)
        if (!kiemTra(haiDau.themCuoi(taoBenhNhan(i, 1, i)), "HangDoiHaiDau day")) return 1;
    if (!kiemTra(!haiDau.themDau(taoBenhNhan(101, 1, 101)), "HangDoiHaiDau chan tran")) return 1;
    for (int i = 1; i <= 80; i++)
        if (!kiemTra(haiDau.layDau(bn) && bn.maBenhNhan == i, "HangDoiHaiDau lay bot")) return 1;
    for (int i = 101; i <= 180; i++)
        if (!kiemTra(haiDau.themCuoi(taoBenhNhan(i, 1, i)), "HangDoiHaiDau them sau khi lay bot")) return 1;
    for (int i = 81; i <= 180; i++)
        if (!kiemTra(haiDau.layDau(bn) && bn.maBenhNhan == i, "HangDoiHaiDau lay sau khi them")) return 1;
    if (!kiemTra(haiDau.themDau(taoBenhNhan(181, 1, 181)) &&
                 haiDau.layCuoi(bn) && bn.maBenhNhan == 181 && haiDau.laRong(),
                 "HangDoiHaiDau them lai sau khi rong")) return 1;

    cout << "HangDoi, HangDoiUuTien, HangDoiHaiDau: OK\n";
    return 0;
}
