#ifndef CAU_TRUC_DU_LIEU_H
#define CAU_TRUC_DU_LIEU_H

#include "HeThongBenhVien.h"

// shortcut: Mỗi hàng chứa tối đa 100 bệnh nhân; tăng giới hạn khi cần nhiều hơn.
const int MAX_HANG_DOI = 100;

class Queue {
private:
    struct Node {
        BenhNhan data;
        Node* next;
    };
    Node* head;
    Node* tail;
    int soLuong;

    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

public:
    Queue();
    ~Queue();
    bool them(BenhNhan bn);
    bool lay(BenhNhan &bn);
    bool xemDau(BenhNhan &bn);
    bool laRong();
    int kichThuoc();
};

class PriorityQueue {
private:
    BenhNhan danhSach[MAX_HANG_DOI];
    int soLuong;

public:
    PriorityQueue();
    bool them(BenhNhan bn);
    bool lay(BenhNhan &bn);
    bool xemDau(BenhNhan &bn);
    bool laRong();
    int kichThuoc();
};

class Deque {
private:
    BenhNhan danhSach[MAX_HANG_DOI];
    int dau;
    int soLuong;

public:
    Deque();
    bool themDau(BenhNhan bn);
    bool themCuoi(BenhNhan bn);
    bool layDau(BenhNhan &bn);
    bool layCuoi(BenhNhan &bn);
    bool laRong();
    int kichThuoc();
};

#endif
