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
    Queue thuong;
    if (!kiemTra(!thuong.lay(bn), "Queue rong")) return 1;
    for (int i = 1; i <= 100; i++)
        if (!kiemTra(thuong.them(taoBenhNhan(i, i % 5 + 1, i)), "Queue them")) return 1;
    if (!kiemTra(!thuong.them(taoBenhNhan(101, 1, 101)), "Queue day")) return 1;
    if (!kiemTra(thuong.xemDau(bn) && bn.maBenhNhan == 1 &&
                 thuong.kichThuoc() == 100, "Queue xem dau")) return 1;
    for (int i = 1; i <= 80; i++) {
        if (!kiemTra(thuong.lay(bn) && bn.maBenhNhan == i, "Queue FIFO")) return 1;
    }
    for (int i = 101; i <= 180; i++)
        if (!kiemTra(thuong.them(taoBenhNhan(i, 1, i)), "Queue them sau khi lay bot")) return 1;
    for (int i = 81; i <= 180; i++) {
        if (!kiemTra(thuong.lay(bn) && bn.maBenhNhan == i, "Queue FIFO sau khi lay bot")) return 1;
    }
    if (!kiemTra(thuong.laRong(), "Queue lay het")) return 1;
    if (!kiemTra(thuong.them(taoBenhNhan(181, 1, 181)) &&
                 thuong.lay(bn) && bn.maBenhNhan == 181 && thuong.laRong(),
                 "Queue them lai sau khi rong")) return 1;

    PriorityQueue uuTien;
    if (!kiemTra(!uuTien.lay(bn), "Priority Queue rong")) return 1;
    for (int i = 1; i <= 100; i++)
        if (!kiemTra(uuTien.them(taoBenhNhan(i, i % 5 + 1, i)), "Priority Queue them")) return 1;
    if (!kiemTra(!uuTien.them(taoBenhNhan(101, 5, 101)), "Priority Queue day")) return 1;
    if (!kiemTra(uuTien.xemDau(bn) && bn.doUuTien == 5 &&
                 uuTien.kichThuoc() == 100, "Priority Queue xem dau")) return 1;
    for (int muc = 5; muc >= 1; muc--) {
        for (int i = 1; i <= 100; i++) {
            if (i % 5 + 1 == muc) {
                if (!kiemTra(uuTien.lay(bn) && bn.maBenhNhan == i,
                             "Uu tien va FIFO cung muc")) return 1;
            }
        }
    }
    if (!kiemTra(uuTien.laRong(), "Priority Queue lay het")) return 1;

    Deque haiDau;
    if (!kiemTra(!haiDau.layDau(bn) && !haiDau.layCuoi(bn), "Deque rong")) return 1;
    if (!kiemTra(haiDau.themDau(taoBenhNhan(1, 1, 1)) &&
                 haiDau.themCuoi(taoBenhNhan(2, 1, 2)) &&
                 haiDau.themDau(taoBenhNhan(3, 1, 3)), "Deque them hai dau")) return 1;
    if (!kiemTra(haiDau.layDau(bn) && bn.maBenhNhan == 3, "Deque lay dau")) return 1;
    if (!kiemTra(haiDau.layCuoi(bn) && bn.maBenhNhan == 2, "Deque lay cuoi")) return 1;
    if (!kiemTra(haiDau.layDau(bn) && bn.maBenhNhan == 1, "Deque con lai")) return 1;
    for (int i = 1; i <= 100; i++)
        if (!kiemTra(haiDau.themCuoi(taoBenhNhan(i, 1, i)), "Deque day")) return 1;
    if (!kiemTra(!haiDau.themDau(taoBenhNhan(101, 1, 101)), "Deque chan tran")) return 1;
    for (int i = 1; i <= 80; i++)
        if (!kiemTra(haiDau.layDau(bn) && bn.maBenhNhan == i, "Deque lay bot")) return 1;
    for (int i = 101; i <= 180; i++)
        if (!kiemTra(haiDau.themCuoi(taoBenhNhan(i, 1, i)), "Deque them sau khi lay bot")) return 1;
    for (int i = 81; i <= 180; i++)
        if (!kiemTra(haiDau.layDau(bn) && bn.maBenhNhan == i, "Deque lay sau khi them")) return 1;
    if (!kiemTra(haiDau.themDau(taoBenhNhan(181, 1, 181)) &&
                 haiDau.layCuoi(bn) && bn.maBenhNhan == 181 && haiDau.laRong(),
                 "Deque them lai sau khi rong")) return 1;

    cout << "Queue, Priority Queue, Deque: OK\n";
    return 0;
}
