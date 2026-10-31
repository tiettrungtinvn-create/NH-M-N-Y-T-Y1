#include "../code/HeThongBenhVien.h"

bool nhapSo(int &so) {
    if (!(cin >> so)) {
        if (!cin.eof()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Vui long nhap so hop le.\n";
        }
        return false;
    }
    cin.ignore(10000, '\n');
    return true;
}

int main() {
    HeThongBenhVien heThong(100);
    while (true) {
        cout << "\n=== HE THONG XEP HANG KHAM BENH ===\n"
             << "1. Tiep nhan va phan luong\n"
             << "2. Goi so tu dong\n"
             << "3. Chuyen khoa cap cuu\n"
             << "4. Uoc tinh thoi gian cho\n"
             << "5. Bang dien tu\n"
             << "6. Thong ke phong kham\n"
             << "7. Lich su goi\n"
             << "0. Thoat\nChon: ";
        int luaChon;
        if (!nhapSo(luaChon)) {
            if (cin.eof()) break;
            continue;
        }
        if (luaChon == 0) break;

        if (luaChon == 1) {
            int ma, uuTien;
            string ten, phong;
            cout << "Ma benh nhan: ";
            if (!nhapSo(ma)) continue;
            cout << "Ho ten: ";
            getline(cin, ten);
            cout << "Phong kham: ";
            getline(cin, phong);
            cout << "Muc uu tien (1 binh thuong, 2-5 cap cuu): ";
            if (!nhapSo(uuTien)) continue;
            if (heThong.tiepNhanVaPhanLuong(ma, ten, phong, uuTien))
                cout << "Da cap STT va xep hang cho " << ten << ".\n";
            else cout << "Khong the tiep nhan: kiem tra du lieu, ma trung hoac hang day.\n";
        } else if (luaChon == 2) {
            string phong;
            cout << "Phong kham (de trong de goi tren tat ca phong): ";
            getline(cin, phong);
            if (!heThong.goiSoTuDong(phong)) cout << "Khong co benh nhan cho o phong nay.\n";
        } else if (luaChon == 3) {
            int ma;
            cout << "Ma benh nhan can chuyen: ";
            if (!nhapSo(ma)) continue;
            if (!heThong.chuyenKhoaCapCuuUuTien(ma))
                cout << "Khong tim thay benh nhan hoac khoa cap cuu da day.\n";
        } else if (luaChon == 4) {
            int ma;
            cout << "Ma benh nhan can tra cuu: ";
            if (!nhapSo(ma)) continue;
            heThong.uocTinhThoiGianCho(ma);
        } else if (luaChon == 5) {
            heThong.hienThiBangDienTu();
        } else if (luaChon == 6) {
            string phong;
            cout << "Phong kham: ";
            getline(cin, phong);
            heThong.thongKePhongKham(phong);
        } else if (luaChon == 7) {
            heThong.hienThiLichSuGoi();
        } else {
            cout << "Lua chon khong hop le.\n";
        }
    }
    return 0;
}
