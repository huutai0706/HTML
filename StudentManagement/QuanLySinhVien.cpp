#include "QuanLySinhVien.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <limits>
using namespace std;

// Thêm sinh viên mới vào danh sách
void themSinhVien(vector<SinhVien>& danhSach) {
    string maSV, hoTen, lop;
    int tuoi;
    float diemTB;

    cout << "Nhap ma so sinh vien: ";
    getline(cin >> ws, maSV);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    
    // Kiểm tra và xử lý lỗi nhập tuổi
    while (true) {
        cout << "Nhap tuoi: ";
        if (cin >> tuoi) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Giờ dòng này sẽ hoạt động
            break;
        } else {
            cout << "Du lieu khong hop le. Vui long nhap mot so nguyen.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    cout << "Nhap lop: ";
    getline(cin, lop);
    
    // Kiểm tra và xử lý lỗi nhập điểm
    while (true) {
        cout << "Nhap diem trung binh: ";
        if (cin >> diemTB) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Giờ dòng này sẽ hoạt động
            break;
        } else {
            cout << "Du lieu khong hop le. Vui long nhap mot so thuc.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    SinhVien sv(maSV, hoTen, tuoi, lop, diemTB);
    danhSach.push_back(sv);
    cout << "Them thanh cong!\n";
}

// Hiển thị danh sách sinh viên
void hienThiDanhSach(const vector<SinhVien>& danhSach) {
    if (danhSach.empty()) {
        cout << "Danh sach trong.\n";
        return;
    }

    cout << left << setw(10) << "MaSV" << setw(25) << "Ho Ten"
         << setw(6) << "Tuoi" << setw(10) << "Lop"
         << setw(10) << "DiemTB" << endl;

    for (const auto& sv : danhSach) {
        cout << left << setw(10) << sv.getMaSV()
             << setw(25) << sv.getHoTen()
             << setw(6) << sv.getTuoi()
             << setw(10) << sv.getLop()
             << setw(10) << sv.getDiemTB() << endl;
    }
}

// Tìm kiếm sinh viên theo mã số
void timKiemTheoMa(const vector<SinhVien>& danhSach, const string& maSV) {
    bool timThay = false;
    for (const auto& sv : danhSach) {
        if (sv.getMaSV() == maSV) {
            cout << "Tim thay sinh vien:\n";
            cout << "Ho ten: " << sv.getHoTen() << ", Lop: " << sv.getLop()
                 << ", DiemTB: " << sv.getDiemTB() << endl;
            timThay = true;
            break;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay sinh vien co ma: " << maSV << endl;
    }
}

// Xoá sinh viên theo mã số
void xoaSinhVien(vector<SinhVien>& danhSach, const string& maSV) {
    for (auto it = danhSach.begin(); it != danhSach.end(); ++it) {
        if (it->getMaSV() == maSV) {
            danhSach.erase(it);
            cout << "Da xoa sinh vien co ma: " << maSV << endl;
            return;
        }
    }
    cout << "Khong tim thay sinh vien de xoa.\n";
}

// Sắp xếp danh sách theo điểm trung bình giảm dần
void sapXepTheoDiemTB(vector<SinhVien>& danhSach) {
    sort(danhSach.begin(), danhSach.end(), [](const SinhVien& a, const SinhVien& b) {
        return a.getDiemTB() > b.getDiemTB(); // Giảm dần
    });
    cout << "Da sap xep danh sach theo diem trung binh (giam dan).\n";
}

// Ghi danh sách ra file
void ghiFile(const vector<SinhVien>& danhSach, const string& tenFile) {
    ofstream outFile(tenFile);
    if (!outFile.is_open()) {
        cerr << "Khong the mo file de ghi.\n";
        return;
    }

    for (const auto& sv : danhSach) {
        outFile << sv.getMaSV() << "|"
                << sv.getHoTen() << "|"
                << sv.getTuoi() << "|"
                << sv.getLop() << "|"
                << sv.getDiemTB() << endl;
    }

    outFile.close();
    cout << "Da luu danh sach vao file.\n";
}

// Đọc danh sách từ file
void docFile(vector<SinhVien>& danhSach, const string& tenFile) {
    ifstream inFile(tenFile);
    if (!inFile.is_open()) {
        cerr << "Khong tim thay file de doc.\n";
        return;
    }

    danhSach.clear(); // Xoá dữ liệu cũ

    string line;
    while (getline(inFile, line)) {
        string maSV, hoTen, lop;
        int tuoi = 0;
        float diemTB = 0.0;

        size_t pos = 0;

        // Lấy mã số sinh viên
        pos = line.find("|");
        maSV = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Lấy họ tên
        pos = line.find("|");
        hoTen = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Lấy tuổi
        pos = line.find("|");
        try {
            tuoi = stoi(line.substr(0, pos));
        } catch (const invalid_argument& e) {
            cerr << "Loi chuyen doi du lieu (tuoi): " << e.what() << ". Bo qua dong nay.\n";
            continue;
        }
        line.erase(0, pos + 1);

        // Lấy lớp
        pos = line.find("|");
        lop = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Lấy điểm trung bình
        try {
            diemTB = stof(line);
        } catch (const invalid_argument& e) {
            cerr << "Loi chuyen doi du lieu (diemTB): " << e.what() << ". Bo qua dong nay.\n";
            continue;
        }

        SinhVien sv(maSV, hoTen, tuoi, lop, diemTB);
        danhSach.push_back(sv);
    }

    inFile.close();
    cout << "Da doc danh sach tu file.\n";
}