#ifndef CAU_TRUC_DU_LIEU_H
#define CAU_TRUC_DU_LIEU_H

#include "BenhNhan.h"

// shortcut: Mỗi hàng chứa tối đa 100 bệnh nhân; tăng giới hạn khi cần nhiều hơn.
const int MAX_HANG_DOI = 100;

class HangDoi {
private:
    struct Nut {
        BenhNhan data;
        Nut* next;
    };
    Nut* head;
    Nut* tail;
    int soLuong;

    HangDoi(const HangDoi&) = delete;
    HangDoi& operator=(const HangDoi&) = delete;

public:
    HangDoi();
    ~HangDoi();
    bool them(BenhNhan bn);
    bool lay(BenhNhan &bn);
    bool xemDau(BenhNhan &bn);
    bool xemTaiViTri(int viTri, BenhNhan &bn);
    bool layTheoMa(int ma, BenhNhan &bn);
    bool laRong();
    int kichThuoc();
};

class HangDoiUuTien {
private:
    struct Nut {
        BenhNhan data;
        Nut* next;
    };
    Nut* head;
    int soLuong;

    HangDoiUuTien(const HangDoiUuTien&) = delete;
    HangDoiUuTien& operator=(const HangDoiUuTien&) = delete;

public:
    HangDoiUuTien();
    ~HangDoiUuTien();
    bool them(BenhNhan bn);
    bool lay(BenhNhan &bn);
    bool xemDau(BenhNhan &bn);
    bool xemTaiViTri(int viTri, BenhNhan &bn);
    bool layTheoMa(int ma, BenhNhan &bn);
    bool laRong();
    int kichThuoc();
};

class HangDoiHaiDau {
private:
    struct Nut {
        BenhNhan data;
        Nut* next;
        Nut* prev;
    };
    Nut* head;
    Nut* tail;
    int soLuong;

    HangDoiHaiDau(const HangDoiHaiDau&) = delete;
    HangDoiHaiDau& operator=(const HangDoiHaiDau&) = delete;

public:
    HangDoiHaiDau();
    ~HangDoiHaiDau();
    bool themDau(BenhNhan bn);
    bool themCuoi(BenhNhan bn);
    bool layDau(BenhNhan &bn);
    bool layCuoi(BenhNhan &bn);
    bool xemTaiViTri(int viTri, BenhNhan &bn);
    bool laRong();
    int kichThuoc();
};

#endif
