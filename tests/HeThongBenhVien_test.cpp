#include "../code/HeThongBenhVien.h"

bool kiemTra(bool dung, string tenCa) {
    if (!dung) cout << "LOI: " << tenCa << "\n";
    return dung;
}

int main() {
    HeThongBenhVien ht(5);
    if (!kiemTra(ht.tiepNhanVaPhanLuong(1, "A", "Noi", 1), "tiep nhan A")) return 1;
    if (!kiemTra(!ht.tiepNhanVaPhanLuong(1, "Trung ma", "Noi", 1), "trung ma")) return 1;
    if (!kiemTra(ht.tiepNhanVaPhanLuong(2, "B", "Noi", 1), "tiep nhan B")) return 1;
    if (!kiemTra(ht.tiepNhanVaPhanLuong(3, "C", "Noi", 3), "tiep nhan cap cuu")) return 1;
    if (!kiemTra(ht.tiepNhanVaPhanLuong(4, "D", "Ngoai", 1), "phan luong Ngoai")) return 1;
    if (!kiemTra(ht.tiepNhanVaPhanLuong(5, "E", "Ngoai", 5), "cap cuu Ngoai")) return 1;
    if (!kiemTra(!ht.tiepNhanVaPhanLuong(6, "F", "Noi", 1), "hang day")) return 1;
    if (!kiemTra(ht.kichThuoc() == 5 && ht.thoiGianChoDuKien(1) == 15 &&
                 ht.thoiGianChoDuKien(2) == 30 && ht.thoiGianChoDuKien(3) == 0 &&
                 ht.thoiGianChoDuKien(4) == 15 && ht.thoiGianChoDuKien(5) == 0,
                 "thoi gian cho theo phong va uu tien")) return 1;
    if (!kiemTra(ht.goiSoTuDong("Noi") && ht.thoiGianChoDuKien(3) == -1 &&
                 ht.thoiGianChoDuKien(1) == 0 && ht.thoiGianChoDuKien(2) == 15,
                 "cap cuu truoc FIFO")) return 1;
    if (!kiemTra(ht.chuyenKhoaCapCuuUuTien(2) && ht.thoiGianChoDuKien(2) == 0 &&
                 ht.thoiGianChoDuKien(1) == 0, "chuyen khoa cap cuu")) return 1;
    if (!kiemTra(!ht.chuyenKhoaCapCuuUuTien(999), "khong co benh nhan")) return 1;
    if (!kiemTra(ht.goiSoTuDong() && ht.thoiGianChoDuKien(2) == -1, "uu tien 999")) return 1;
    if (!kiemTra(ht.goiSoTuDong() && ht.thoiGianChoDuKien(5) == -1, "uu tien 5")) return 1;
    if (!kiemTra(ht.goiSoTuDong("Noi") && ht.thoiGianChoDuKien(1) == -1, "FIFO Noi")) return 1;
    if (!kiemTra(ht.goiSoTuDong() && ht.thoiGianChoDuKien(4) == -1 && ht.laRong(),
                 "goi het")) return 1;
    if (!kiemTra(!ht.goiSoTuDong(), "hang rong")) return 1;
    ht.hienThiLichSuGoi();

    HeThongBenhVien cungMuc(4);
    cungMuc.tiepNhanVaPhanLuong(11, "A", "Nhi", 3);
    cungMuc.tiepNhanVaPhanLuong(12, "B", "Nhi", 5);
    cungMuc.tiepNhanVaPhanLuong(13, "C", "Nhi", 3);
    if (!kiemTra(cungMuc.goiSoTuDong() && cungMuc.thoiGianChoDuKien(12) == -1,
                 "muc cao hon di truoc")) return 1;
    if (!kiemTra(cungMuc.goiSoTuDong() && cungMuc.thoiGianChoDuKien(11) == -1 &&
                 cungMuc.thoiGianChoDuKien(13) == 0, "FIFO cung muc")) return 1;
    cout << "HeThongBenhVien: OK\n";
    return 0;
}
