#ifndef QUANLYSINHVIEN_H
#define QUANLYSINHVIEN_H

#include <vector>
#include <string>
#include "SinhVien.h"

// Thêm sinh viên mới
void themSinhVien(std::vector<SinhVien>& danhSach);

// Hiển thị toàn bộ danh sách sinh viên
void hienThiDanhSach(const std::vector<SinhVien>& danhSach);

// Tìm kiếm sinh viên theo mã số
void timKiemTheoMa(const std::vector<SinhVien>& danhSach, const std::string& maSV);

// Xoá sinh viên khỏi danh sách theo mã số
void xoaSinhVien(std::vector<SinhVien>& danhSach, const std::string& maSV);

// Sắp xếp sinh viên theo điểm trung bình giảm dần
void sapXepTheoDiemTB(std::vector<SinhVien>& danhSach);

// Ghi danh sách sinh viên ra file
void ghiFile(const std::vector<SinhVien>& danhSach, const std::string& tenFile);

// Đọc danh sách sinh viên từ file
void docFile(std::vector<SinhVien>& danhSach, const std::string& tenFile);

#endif // QUANLYSINHVIEN_H
