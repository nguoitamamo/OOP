#pragma once
#include"TaiLieu.h"
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
class Sach : TaiLieu {
private: 
	std::string tenTacGia;
	int soTrang;
public:
	Sach() {};
	Sach(std::string ma, std::string tenNhaXuatBan, int soBanPhatHanh, std::string tenTacGia, int soTrang) :TaiLieu(ma, tenNhaXuatBan, soBanPhatHanh) {
		this->tenTacGia = tenTacGia;
		this->soTrang = soTrang;
	}
	void Nhap(Sach&);
	void Xuat(Sach&);
	void doc(Sach*&a);
	std::string getMa() {
		return TaiLieu::getMa();
	}
	std::string getTenNhaXuatBan() {
		return TaiLieu::getTenNhaXuatBan();
	}

};

void Sach::Nhap(Sach& a) {
	TaiLieu::Nhap(a);
	std::cin.ignore();
	std::cout << "Nhap tenTacGia: "; std::getline(std::cin, a.tenTacGia); 
	std::cout << "Nhap soTrang: "; std::cin >> soTrang;
}
void Sach::Xuat(Sach& a) {
	if (a.ma != "") {
		TaiLieu::Xuat(a);
		std::cout << "TenTacGia: " << std::left << std::setw(10) << a.tenTacGia << "SoTrang: " << std::left << std::setw(10) << a.soTrang << "\n";
	}
}



void Sach::doc(Sach* &a) {
	std::ifstream fs("Sach.txt", std::ios::in);
	TaiLieu::doc(fs, a);
}


bool operator < ( Sach& a,  Sach& b) {
	return (a.getMa() < b.getMa()) ? a.getMa() < b.getMa() : a.getTenNhaXuatBan() < b.getTenNhaXuatBan();
}