#include <iostream>
#include <vector>
#include "SinhVien.h"
#include "QuanLySinhVien.h"
#include <limits>

using namespace std;

int main() {
    vector<SinhVien> danhSach;
    string tenFile = "data.txt";

    // Đọc dữ liệu từ file khi khởi động
    docFile(danhSach, tenFile);

    int luaChon;
    do {
        cout << "\n========== MENU QUAN LY SINH VIEN ==========\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Hien thi danh sach sinh vien\n";
        cout << "3. Tim sinh vien theo ma so\n";
        cout << "4. Xoa sinh vien\n";
        cout << "5. Sap xep theo diem trung binh\n";
        cout << "6. Luu danh sach vao file\n";
        cout << "0. Thoat\n";
        cout << "============================================\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        cin.ignore(); // Xoa bo dem sau khi nhap so

        switch (luaChon) {
            case 1:
                themSinhVien(danhSach);
                break;
            case 2:
                hienThiDanhSach(danhSach);
                break;
            case 3: {
                string maSV;
                cout << "Nhap ma sinh vien can tim: ";
                getline(cin, maSV);
                timKiemTheoMa(danhSach, maSV);
                break;
            }
            case 4: {
                string maSV;
                cout << "Nhap ma sinh vien can xoa: ";
                getline(cin, maSV);
                xoaSinhVien(danhSach, maSV);
                break;
            }
            case 5:
                sapXepTheoDiemTB(danhSach);
                break;
            case 6:
                ghiFile(danhSach, tenFile);
                break;
            case 0:
                ghiFile(danhSach, tenFile);
                cout << "Da luu du lieu. Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai.\n";
                break;
        }

    } while (luaChon != 0);

    return 0;
}
