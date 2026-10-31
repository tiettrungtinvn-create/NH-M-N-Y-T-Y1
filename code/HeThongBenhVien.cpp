#include "HeThongBenhVien.h"

HeThongBenhVien::HeThongBenhVien(int sc) {
    soPhong = 0;
    sucChua = sc > 0 && sc <= MAX_HANG_DOI ? sc : MAX_HANG_DOI;
    soLuong = 0;
    sttTuDong = 0;
}

int HeThongBenhVien::timPhong(string tenPhong) {
    for (int i = 0; i < soPhong; i++)
        if (phong[i].ten == tenPhong) return i;
    return -1;
}

int HeThongBenhVien::taoPhong(string tenPhong) {
    int viTri = timPhong(tenPhong);
    if (viTri >= 0) return viTri;
    if (tenPhong.empty() || soPhong == SO_PHONG_TOI_DA) return -1;
    phong[soPhong].ten = tenPhong;
    soPhong++;
    return soPhong - 1;
}

bool HeThongBenhVien::timBenhNhan(int ma, BenhNhan &bn, int &viTriPhong, bool &capCuu) {
    for (int i = 0; i < soPhong; i++) {
        for (int j = 0; j < phong[i].hangCapCuu.kichThuoc(); j++) {
            phong[i].hangCapCuu.xemTaiViTri(j, bn);
            if (bn.maBenhNhan == ma) {
                viTriPhong = i;
                capCuu = true;
                return true;
            }
        }
        for (int j = 0; j < phong[i].hangThuong.kichThuoc(); j++) {
            phong[i].hangThuong.xemTaiViTri(j, bn);
            if (bn.maBenhNhan == ma) {
                viTriPhong = i;
                capCuu = false;
                return true;
            }
        }
    }
    return false;
}

bool HeThongBenhVien::tiepNhanVaPhanLuong(int ma, string ten, string tenPhong, int doUuTien) {
    if (ma <= 0 || ten.empty() || tenPhong.empty() || doUuTien < 1 || doUuTien > 5 || soLuong == sucChua)
        return false;
    BenhNhan daCo;
    int viTriCu;
    bool capCuuCu;
    if (timBenhNhan(ma, daCo, viTriCu, capCuuCu)) return false;
    int viTri = taoPhong(tenPhong);
    if (viTri < 0) return false;

    BenhNhan bn;
    bn.maBenhNhan = ma;
    bn.ten = ten;
    bn.phongKham = tenPhong;
    bn.doUuTien = doUuTien;
    bn.soThuTu = sttTuDong + 1;
    bool daThem = doUuTien == 1 ? phong[viTri].hangThuong.them(bn)
                                : phong[viTri].hangCapCuu.them(bn);
    if (!daThem) return false;
    sttTuDong++;
    soLuong++;
    return true;
}

bool HeThongBenhVien::chuyenKhoaCapCuuUuTien(int maBN) {
    BenhNhan bn;
    int viTriCu;
    bool capCuuCu;
    if (!timBenhNhan(maBN, bn, viTriCu, capCuuCu)) return false;
    if (bn.phongKham == "Khoa Cap Cuu" && bn.doUuTien == 999) return true;
    int viTriMoi = taoPhong("Khoa Cap Cuu");
    if (viTriMoi < 0) return false;
    if (phong[viTriMoi].hangCapCuu.kichThuoc() == MAX_HANG_DOI &&
        !(viTriCu == viTriMoi && capCuuCu)) return false;

    if (capCuuCu) phong[viTriCu].hangCapCuu.layTheoMa(maBN, bn);
    else phong[viTriCu].hangThuong.layTheoMa(maBN, bn);
    bn.phongKham = "Khoa Cap Cuu";
    bn.doUuTien = 999;
    phong[viTriMoi].hangCapCuu.them(bn);
    cout << "[THONG BAO KHAN] Da chuyen BN " << maBN << " sang Khoa Cap Cuu!\n";
    return true;
}

bool HeThongBenhVien::goiSoTuDong(string tenPhong) {
    if (laRong()) return false;
    int viTri = -1;
    bool capCuu = false;
    BenhNhan totNhat, ungVien;

    if (!tenPhong.empty()) {
        viTri = timPhong(tenPhong);
        if (viTri < 0) return false;
        capCuu = !phong[viTri].hangCapCuu.laRong();
        if (!capCuu && phong[viTri].hangThuong.laRong()) return false;
    } else {
        for (int i = 0; i < soPhong; i++) {
            if (phong[i].hangCapCuu.xemDau(ungVien) &&
                (viTri < 0 || !capCuu || totNhat < ungVien)) {
                viTri = i;
                capCuu = true;
                totNhat = ungVien;
            }
        }
        if (viTri < 0) {
            for (int i = 0; i < soPhong; i++) {
                if (phong[i].hangThuong.xemDau(ungVien) &&
                    (viTri < 0 || ungVien.soThuTu < totNhat.soThuTu)) {
                    viTri = i;
                    totNhat = ungVien;
                }
            }
        }
    }

    BenhNhan bn;
    if (capCuu) phong[viTri].hangCapCuu.lay(bn);
    else phong[viTri].hangThuong.lay(bn);
    soLuong--;
    if (lichSuGoi.kichThuoc() == MAX_HANG_DOI) {
        BenhNhan cu;
        lichSuGoi.layDau(cu);
    }
    lichSuGoi.themCuoi(bn);
    cout << "[LOA THONG BAO] Moi BN STT " << bn.soThuTu << " - " << bn.ten
         << " vao " << bn.phongKham << "!\n";
    return true;
}

int HeThongBenhVien::thoiGianChoDuKien(int maBN) {
    BenhNhan bn, dangXet;
    int viTri;
    bool capCuu;
    if (!timBenhNhan(maBN, bn, viTri, capCuu)) return -1;
    int truoc = capCuu ? 0 : phong[viTri].hangCapCuu.kichThuoc();
    if (capCuu) {
        for (int i = 0; i < phong[viTri].hangCapCuu.kichThuoc(); i++) {
            phong[viTri].hangCapCuu.xemTaiViTri(i, dangXet);
            if (dangXet.maBenhNhan == maBN) break;
            truoc++;
        }
    } else {
        for (int i = 0; i < phong[viTri].hangThuong.kichThuoc(); i++) {
            phong[viTri].hangThuong.xemTaiViTri(i, dangXet);
            if (dangXet.maBenhNhan == maBN) break;
            truoc++;
        }
    }
    return truoc * PHUT_MOI_LUOT;
}

void HeThongBenhVien::uocTinhThoiGianCho(int maBN) {
    int phut = thoiGianChoDuKien(maBN);
    if (phut < 0) cout << "[LOI] Khong tim thay BN " << maBN << " trong hang cho.\n";
    else cout << "[TRA CUU] BN " << maBN << " can cho khoang " << phut << " phut.\n";
}

void HeThongBenhVien::hienThiBangDienTu() {
    if (laRong()) {
        cout << "--- BANG DIEN TU TRONG ---\n";
        return;
    }
    cout << "--- DANH SACH CHO KHAM ---\n";
    BenhNhan bn;
    for (int i = 0; i < soPhong; i++) {
        if (phong[i].hangCapCuu.laRong() && phong[i].hangThuong.laRong()) continue;
        cout << "Phong: " << phong[i].ten << "\n";
        for (int j = 0; j < phong[i].hangCapCuu.kichThuoc(); j++) {
            phong[i].hangCapCuu.xemTaiViTri(j, bn);
            cout << "  [UU TIEN " << bn.doUuTien << "] STT " << bn.soThuTu
                 << " | Ma " << bn.maBenhNhan << " | " << bn.ten << "\n";
        }
        for (int j = 0; j < phong[i].hangThuong.kichThuoc(); j++) {
            phong[i].hangThuong.xemTaiViTri(j, bn);
            cout << "  [THUONG] STT " << bn.soThuTu << " | Ma " << bn.maBenhNhan
                 << " | " << bn.ten << "\n";
        }
    }
}

void HeThongBenhVien::thongKePhongKham(string tenPhong) {
    int viTri = timPhong(tenPhong);
    int dem = viTri < 0 ? 0 : phong[viTri].hangCapCuu.kichThuoc() + phong[viTri].hangThuong.kichThuoc();
    cout << "[THONG KE] Phong " << tenPhong << " dang co " << dem << " BN xep hang.\n";
}

void HeThongBenhVien::hienThiLichSuGoi() {
    cout << "--- LICH SU GOI ---\n";
    BenhNhan bn;
    for (int i = 0; i < lichSuGoi.kichThuoc(); i++) {
        lichSuGoi.xemTaiViTri(i, bn);
        cout << "STT " << bn.soThuTu << " | " << bn.ten << " | " << bn.phongKham << "\n";
    }
}

bool HeThongBenhVien::laRong() { return soLuong == 0; }
int HeThongBenhVien::kichThuoc() { return soLuong; }
