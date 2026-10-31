#include "../include/CauTrucDuLieu.h"

HangDoi::HangDoi() {
    head = NULL;
    tail = NULL;
    soLuong = 0;
}

HangDoi::~HangDoi() {
    while (head != NULL) {
        Nut* cu = head;
        head = head->next;
        delete cu;
    }
}

bool HangDoi::them(BenhNhan bn) {
    if (soLuong == MAX_HANG_DOI) return false;
    Nut* moi = new Nut;
    moi->data = bn;
    moi->next = NULL;
    if (head == NULL) head = moi;
    else tail->next = moi;
    tail = moi;
    soLuong++;
    return true;
}

bool HangDoi::lay(BenhNhan &bn) {
    if (laRong()) return false;
    Nut* cu = head;
    bn = cu->data;
    head = head->next;
    delete cu;
    if (head == NULL) tail = NULL;
    soLuong--;
    return true;
}

bool HangDoi::xemDau(BenhNhan &bn) {
    if (laRong()) return false;
    bn = head->data;
    return true;
}

bool HangDoi::laRong() { return soLuong == 0; }
int HangDoi::kichThuoc() { return soLuong; }

HangDoiUuTien::HangDoiUuTien() {
    head = NULL;
    soLuong = 0;
}

HangDoiUuTien::~HangDoiUuTien() {
    while (head != NULL) {
        Nut* cu = head;
        head = head->next;
        delete cu;
    }
}

bool HangDoiUuTien::them(BenhNhan bn) {
    if (soLuong == MAX_HANG_DOI) return false;
    Nut* moi = new Nut;
    moi->data = bn;
    moi->next = NULL;
    if (head == NULL || head->data < bn) {
        moi->next = head;
        head = moi;
    } else {
        Nut* hienTai = head;
        while (hienTai->next != NULL && !(hienTai->next->data < bn))
            hienTai = hienTai->next;
        moi->next = hienTai->next;
        hienTai->next = moi;
    }
    soLuong++;
    return true;
}

bool HangDoiUuTien::lay(BenhNhan &bn) {
    if (laRong()) return false;
    Nut* cu = head;
    bn = cu->data;
    head = head->next;
    delete cu;
    soLuong--;
    return true;
}

bool HangDoiUuTien::xemDau(BenhNhan &bn) {
    if (laRong()) return false;
    bn = head->data;
    return true;
}

bool HangDoiUuTien::laRong() { return soLuong == 0; }
int HangDoiUuTien::kichThuoc() { return soLuong; }

HangDoiHaiDau::HangDoiHaiDau() {
    head = NULL;
    tail = NULL;
    soLuong = 0;
}

HangDoiHaiDau::~HangDoiHaiDau() {
    while (head != NULL) {
        Nut* cu = head;
        head = head->next;
        delete cu;
    }
}

bool HangDoiHaiDau::themDau(BenhNhan bn) {
    if (soLuong == MAX_HANG_DOI) return false;
    Nut* moi = new Nut;
    moi->data = bn;
    moi->prev = NULL;
    moi->next = head;
    if (head == NULL) tail = moi;
    else head->prev = moi;
    head = moi;
    soLuong++;
    return true;
}

bool HangDoiHaiDau::themCuoi(BenhNhan bn) {
    if (soLuong == MAX_HANG_DOI) return false;
    Nut* moi = new Nut;
    moi->data = bn;
    moi->next = NULL;
    moi->prev = tail;
    if (tail == NULL) head = moi;
    else tail->next = moi;
    tail = moi;
    soLuong++;
    return true;
}

bool HangDoiHaiDau::layDau(BenhNhan &bn) {
    if (laRong()) return false;
    Nut* cu = head;
    bn = cu->data;
    head = head->next;
    if (head == NULL) tail = NULL;
    else head->prev = NULL;
    delete cu;
    soLuong--;
    return true;
}

bool HangDoiHaiDau::layCuoi(BenhNhan &bn) {
    if (laRong()) return false;
    Nut* cu = tail;
    bn = cu->data;
    tail = tail->prev;
    if (tail == NULL) head = NULL;
    else tail->next = NULL;
    delete cu;
    soLuong--;
    return true;
}

bool HangDoiHaiDau::laRong() { return soLuong == 0; }
int HangDoiHaiDau::kichThuoc() { return soLuong; }
