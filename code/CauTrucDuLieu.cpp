#include "../include/CauTrucDuLieu.h"

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

PriorityQueue::PriorityQueue() {
    head = NULL;
    soLuong = 0;
}

PriorityQueue::~PriorityQueue() {
    while (head != NULL) {
        Node* cu = head;
        head = head->next;
        delete cu;
    }
}

bool PriorityQueue::them(BenhNhan bn) {
    if (soLuong == MAX_HANG_DOI) return false;
    Node* moi = new Node;
    moi->data = bn;
    moi->next = NULL;
    if (head == NULL || head->data < bn) {
        moi->next = head;
        head = moi;
    } else {
        Node* hienTai = head;
        while (hienTai->next != NULL && !(hienTai->next->data < bn))
            hienTai = hienTai->next;
        moi->next = hienTai->next;
        hienTai->next = moi;
    }
    soLuong++;
    return true;
}

bool PriorityQueue::lay(BenhNhan &bn) {
    if (laRong()) return false;
    Node* cu = head;
    bn = cu->data;
    head = head->next;
    delete cu;
    soLuong--;
    return true;
}

bool PriorityQueue::xemDau(BenhNhan &bn) {
    if (laRong()) return false;
    bn = head->data;
    return true;
}

bool PriorityQueue::laRong() { return soLuong == 0; }
int PriorityQueue::kichThuoc() { return soLuong; }

Deque::Deque() {
    head = NULL;
    tail = NULL;
    soLuong = 0;
}

Deque::~Deque() {
    while (head != NULL) {
        Node* cu = head;
        head = head->next;
        delete cu;
    }
}

bool Deque::themDau(BenhNhan bn) {
    if (soLuong == MAX_HANG_DOI) return false;
    Node* moi = new Node;
    moi->data = bn;
    moi->prev = NULL;
    moi->next = head;
    if (head == NULL) tail = moi;
    else head->prev = moi;
    head = moi;
    soLuong++;
    return true;
}

bool Deque::themCuoi(BenhNhan bn) {
    if (soLuong == MAX_HANG_DOI) return false;
    Node* moi = new Node;
    moi->data = bn;
    moi->next = NULL;
    moi->prev = tail;
    if (tail == NULL) head = moi;
    else tail->next = moi;
    tail = moi;
    soLuong++;
    return true;
}

bool Deque::layDau(BenhNhan &bn) {
    if (laRong()) return false;
    Node* cu = head;
    bn = cu->data;
    head = head->next;
    if (head == NULL) tail = NULL;
    else head->prev = NULL;
    delete cu;
    soLuong--;
    return true;
}

bool Deque::layCuoi(BenhNhan &bn) {
    if (laRong()) return false;
    Node* cu = tail;
    bn = cu->data;
    tail = tail->prev;
    if (tail == NULL) head = NULL;
    else tail->next = NULL;
    delete cu;
    soLuong--;
    return true;
}

bool Deque::laRong() { return soLuong == 0; }
int Deque::kichThuoc() { return soLuong; }
