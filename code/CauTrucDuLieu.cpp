#include "CauTrucDuLieu.h"

Queue::Queue() {
    head = NULL;
    tail = NULL;
    soLuong = 0;
}

Queue::~Queue() {
    while (head != NULL) {
        Node* cu = head;
        head = head->next;
        delete cu;
    }
}

bool Queue::them(BenhNhan bn) {
    if (soLuong == MAX_HANG_DOI) return false;
    Node* moi = new Node;
    moi->data = bn;
    moi->next = NULL;
    if (head == NULL) head = moi;
    else tail->next = moi;
    tail = moi;
    soLuong++;
    return true;
}

bool Queue::lay(BenhNhan &bn) {
    if (laRong()) return false;
    Node* cu = head;
    bn = cu->data;
    head = head->next;
    delete cu;
    if (head == NULL) tail = NULL;
    soLuong--;
    return true;
}

bool Queue::xemDau(BenhNhan &bn) {
    if (laRong()) return false;
    bn = head->data;
    return true;
}

bool Queue::laRong() { return soLuong == 0; }
int Queue::kichThuoc() { return soLuong; }

PriorityQueue::PriorityQueue() { soLuong = 0; }

bool PriorityQueue::them(BenhNhan bn) {
    if (soLuong == MAX_HANG_DOI) return false;
    int i = soLuong;
    danhSach[i] = bn;
    soLuong++;

    // Đưa bệnh nhân có ưu tiên cao lên phía đầu cây.
    while (i > 0) {
        int cha = (i - 1) / 2;
        if (!(danhSach[cha] < danhSach[i])) break;
        BenhNhan tam = danhSach[cha];
        danhSach[cha] = danhSach[i];
        danhSach[i] = tam;
        i = cha;
    }
    return true;
}

bool PriorityQueue::lay(BenhNhan &bn) {
    if (laRong()) return false;
    bn = danhSach[0];
    soLuong--;
    if (soLuong == 0) return true;
    danhSach[0] = danhSach[soLuong];

    // Đưa phần tử ở đầu xuống đúng vị trí sau khi lấy bệnh nhân.
    int i = 0;
    while (true) {
        int trai = 2 * i + 1;
        int phai = 2 * i + 2;
        int totNhat = i;
        if (trai < soLuong && danhSach[totNhat] < danhSach[trai]) totNhat = trai;
        if (phai < soLuong && danhSach[totNhat] < danhSach[phai]) totNhat = phai;
        if (totNhat == i) break;
        BenhNhan tam = danhSach[i];
        danhSach[i] = danhSach[totNhat];
        danhSach[totNhat] = tam;
        i = totNhat;
    }
    return true;
}

bool PriorityQueue::xemDau(BenhNhan &bn) {
    if (laRong()) return false;
    bn = danhSach[0];
    return true;
}

bool PriorityQueue::laRong() { return soLuong == 0; }
int PriorityQueue::kichThuoc() { return soLuong; }

Deque::Deque() {
    dau = 0;
    soLuong = 0;
}

bool Deque::themDau(BenhNhan bn) {
    if (soLuong == MAX_HANG_DOI) return false;
    dau = (dau - 1 + MAX_HANG_DOI) % MAX_HANG_DOI;
    danhSach[dau] = bn;
    soLuong++;
    return true;
}

bool Deque::themCuoi(BenhNhan bn) {
    if (soLuong == MAX_HANG_DOI) return false;
    int cuoi = (dau + soLuong) % MAX_HANG_DOI;
    danhSach[cuoi] = bn;
    soLuong++;
    return true;
}

bool Deque::layDau(BenhNhan &bn) {
    if (laRong()) return false;
    bn = danhSach[dau];
    dau = (dau + 1) % MAX_HANG_DOI;
    soLuong--;
    return true;
}

bool Deque::layCuoi(BenhNhan &bn) {
    if (laRong()) return false;
    int cuoi = (dau + soLuong - 1) % MAX_HANG_DOI;
    bn = danhSach[cuoi];
    soLuong--;
    return true;
}

bool Deque::laRong() { return soLuong == 0; }
int Deque::kichThuoc() { return soLuong; }
