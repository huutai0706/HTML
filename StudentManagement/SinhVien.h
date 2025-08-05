#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <string>

// Cấu trúc dữ liệu SinhVien
class SinhVien {
    private:
        std::string maSV;     // Mã số sinh viên
        std::string hoTen;    // Họ tên đầy đủ
        int tuoi;             // Tuổi
        std::string lop;      // Lớp học
        float diemTB;         // Điểm trung bình
    public:
        SinhVien();
        SinhVien(std::string msv, std::string ht, int t, std::string l, float dtb);

        // Getter
        std::string getMaSV() const;
        std::string getHoTen() const;
        int getTuoi() const;
        std::string getLop() const;
        float getDiemTB() const;

        // Setter
        void setMaSV(std::string msv);
        void setHoTen(std::string ht);
        void setTuoi(int t);
        void setLop(std::string l);
        void setDiemTB(float dtb); 
};

#endif // SINHVIEN_H