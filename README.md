# NH-M-N-Y-T-Y1
Hệ thống Xếp hàng Khám bệnh & Cấp cứu Bệnh viện

## Cấu trúc dữ liệu C++ cơ bản

`include/CauTrucDuLieu.h` (Head) khai báo ba lớp và `code/CauTrucDuLieu.cpp` (Body) cài đặt bằng các cấu trúc C++ cơ bản:

- `HangDoi` (Queue): danh sách liên kết đơn với `head`, `tail`, `next`; thêm cuối, lấy đầu theo FIFO.
- `HangDoiUuTien` (Priority Queue): danh sách liên kết đơn có thứ tự; mức số lớn hơn được gọi trước, cùng mức thì số thứ tự nhỏ hơn đi trước.
- `HangDoiHaiDau` (Deque): danh sách liên kết hai chiều, thêm và lấy ở cả đầu lẫn cuối.

Mỗi hàng chứa tối đa 100 bệnh nhân. Khi đầy, hàm thêm trả về `false`; khi rỗng, hàm lấy trả về `false`. Bệnh nhân được định nghĩa trong `code/HeThongBenhVien.h`. Bản `code/hang_doi_co_ban/` là ví dụ console độc lập, không dùng chung trong cùng chương trình với ba lớp trên.

Kiểm tra từ thư mục gốc dự án:

```powershell
$env:Path = "C:\msys64\ucrt64\bin;$env:Path"
g++ -std=c++17 tests/CauTrucDuLieu_test.cpp code/CauTrucDuLieu.cpp -o cau_truc_du_lieu_test.exe
.\cau_truc_du_lieu_test.exe
```

Chương trình in `HangDoi, HangDoiUuTien, HangDoiHaiDau: OK` khi các ca kiểm tra đạt.
