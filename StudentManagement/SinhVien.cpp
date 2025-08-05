#include "SinhVien.h"

// Constructor mặc định
SinhVien::SinhVien() {
    maSV = "";
    hoTen = "";
    tuoi = 0;
    lop = "";
    diemTB = 0.0;
}

// Constructor đầy đủ tham số
SinhVien::SinhVien(std::string msv, std::string ht, int t, std::string l, float dtb) {
    maSV = msv;
    hoTen = ht;
    tuoi = t;
    lop = l;
    diemTB = dtb;
}

// Getter
std::string SinhVien::getMaSV() const {
    return maSV;
}

std::string SinhVien::getHoTen() const {
    return hoTen;
}

int SinhVien::getTuoi() const {
    return tuoi;
}

std::string SinhVien::getLop() const {
    return lop;
}

float SinhVien::getDiemTB() const {
    return diemTB;
}

// Setter
void SinhVien::setMaSV(std::string msv) {
    maSV = msv;
}

void SinhVien::setHoTen(std::string ht) {
    hoTen = ht;
}

void SinhVien::setTuoi(int t) {
    tuoi = t;
}

void SinhVien::setLop(std::string l) {
    lop = l;
}

void SinhVien::setDiemTB(float dtb) {
    diemTB = dtb;
}
