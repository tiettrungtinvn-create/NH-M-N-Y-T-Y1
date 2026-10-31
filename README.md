# Hệ thống Xếp hàng Khám bệnh & Cấp cứu Bệnh viện

Bài tập lớn cấu trúc dữ liệu C++ theo đề tài ĐT02. Chương trình console dùng `iostream`, `string`, `struct`, `class` và con trỏ; không dùng các lớp hàng đợi có sẵn của thư viện chuẩn.

## Cấu trúc mã

- `include/BenhNhan.h`: thông tin bệnh nhân và `operator<` so sánh độ ưu tiên.
- `include/CauTrucDuLieu.h`: khai báo `HangDoi` (Queue FIFO), `HangDoiUuTien` (Priority Queue) và `HangDoiHaiDau` (Deque).
- `code/CauTrucDuLieu.cpp`: cài đặt ba cấu trúc trên bằng danh sách liên kết (`Nut`). Queue thêm ở cuối và lấy ở đầu; Priority Queue chèn theo mức ưu tiên; Deque thêm/lấy ở cả hai đầu.
- `code/HeThongBenhVien.h` và `.cpp`: tiếp nhận, phân luồng theo phòng, gọi số, chuyển khoa cấp cứu và ước tính thời gian chờ.
- `src/main.cpp`: menu thao tác với hệ thống.
- `tests/`: bài kiểm tra cấu trúc dữ liệu và nghiệp vụ.

Mức `1` là khám thường; `2` đến `5` là cấp cứu với số lớn hơn được ưu tiên trước. Chuyển khoa cấp cứu đặt mức `999`. Cùng mức ưu tiên, bệnh nhân có số thứ tự nhỏ hơn được gọi trước. Mỗi phòng có hàng thường và hàng cấp cứu riêng. Khi gọi số mà không chỉ định phòng, hệ thống chọn ca cấp cứu ưu tiên cao nhất trên tất cả phòng, rồi đến lượt thường đến sớm nhất.

Thời gian chờ dự kiến = số lượt đứng trước trong **cùng phòng** × 15 phút. Đây là ước tính tại thời điểm tra cứu; ca cấp cứu mới có thể làm thay đổi thời gian thực tế. Hệ thống chứa tối đa 100 bệnh nhân đang chờ và 10 phòng. Lịch sử gọi lưu 100 lượt gần nhất bằng Deque.

## Biên dịch và chạy

Trong PowerShell tại thư mục gốc dự án, với GCC của MSYS2 UCRT64:

```powershell
$env:Path = "C:\msys64\ucrt64\bin;$env:Path"
g++ -std=c++17 -Wall -Wextra -Wpedantic src/main.cpp code/HeThongBenhVien.cpp code/CauTrucDuLieu.cpp -o carequeue.exe
.\carequeue.exe
```

Chọn `1` để tiếp nhận bệnh nhân, `2` để gọi số, `3` để chuyển cấp cứu, `4` để tra thời gian chờ, `5` để xem bảng chờ, `6` để thống kê phòng và `7` để xem lịch sử. Để trống tên phòng ở mục gọi số nếu muốn gọi lượt tiếp theo trên toàn hệ thống.

## Kiểm tra

```powershell
g++ -std=c++17 -Wall -Wextra -Wpedantic tests/CauTrucDuLieu_test.cpp code/CauTrucDuLieu.cpp -o cau_truc_du_lieu_test.exe
.\cau_truc_du_lieu_test.exe
g++ -std=c++17 -Wall -Wextra -Wpedantic tests/HeThongBenhVien_test.cpp code/HeThongBenhVien.cpp code/CauTrucDuLieu.cpp -o he_thong_benh_vien_test.exe
.\he_thong_benh_vien_test.exe
```

`code/hang_doi_co_ban/` là ví dụ Head/Body/Main độc lập để tham khảo; không biên dịch chung với ứng dụng trên vì có `BenhNhan` riêng. `docs/HUONG_DAN_PHAN_CONG.md` là tài liệu chuyển từ dự án cũ và nhiều đường dẫn trong đó không áp dụng cho repo này. `wed/index.html` là giao diện mẫu chưa nối với chương trình C++ console.

Đây là mô hình học tập; không dùng để điều phối bệnh nhân thật hoặc thay thế đánh giá của nhân viên y tế.
