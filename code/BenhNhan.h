// ============================================================================
// PHẦN 1/10 - BenhNhan.h : HẰNG SỐ DÙNG CHUNG + BỆNH NHÂN + NẠP CHỒNG TOÁN TỬ
// ----------------------------------------------------------------------------
// Nhiệm vụ:
//   - Khai báo các hằng số: MAX_HANG_DOI, SO_PHONG_TOI_DA, PHUT_MOI_LUOT.
//   - Khai báo struct BenhNhan (mã, tên, phòng khám, độ ưu tiên, số thứ tự).
//   - Nạp chồng operator< : "a < b" nghĩa là a có độ ưu tiên THẤP HƠN b.
//        + doUuTien lớn hơn = khẩn hơn (mức 1 = thường, 999 = khoa cấp cứu).
//        + Cùng doUuTien: số thứ tự nhỏ hơn (đến trước) được ưu tiên hơn.
//     (HeThong_GoiSo.cpp dùng đúng quy ước này khi so sánh totNhat < ungVien)
//   - Nạp chồng operator>, operator==(so theo mã) và operator<< (in thông tin).
// Phụ thuộc: không.
// ============================================================================
#ifndef BENHNHAN_H
#define BENHNHAN_H

#include <iostream>
#include <string>
using namespace std;

const int MAX_HANG_DOI = 100;      // sức chứa tối đa của mỗi hàng đợi
const int SO_PHONG_TOI_DA = 10;    // số phòng khám tối đa
const int PHUT_MOI_LUOT = 10;      // thời gian khám trung bình mỗi lượt (phút)

struct BenhNhan {
	int maBenhNhan;
	string ten;
	string phongKham;
	int doUuTien;
	int soThuTu;

	BenhNhan() : maBenhNhan(0), ten(""), phongKham(""), doUuTien(0), soThuTu(0) {}

	bool operator<(const BenhNhan& o) const {
		if (doUuTien != o.doUuTien) return doUuTien < o.doUuTien;
		return soThuTu > o.soThuTu;
	}
	bool operator>(const BenhNhan& o) const { return o < *this; }
	bool operator==(const BenhNhan& o) const { return maBenhNhan == o.maBenhNhan; }
};

inline ostream& operator<<(ostream& os, const BenhNhan& bn) {
	os << "STT " << bn.soThuTu << " | Ma " << bn.maBenhNhan << " | " << bn.ten
	   << " | " << bn.phongKham << " | uu tien " << bn.doUuTien;
	return os;
}

#endif
