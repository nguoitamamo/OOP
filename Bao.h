#pragma once
#include"TaiLieu.h"
#include"fstream"

class Bao :TaiLieu {
private: 
	std::string ngayPhatHanh;
public:
	Bao() {};
	Bao(std::string ma, std::string tenNhaXuatBan, int soBanPhatHanh, std::string ngayPhatHanh, int s) :TaiLieu(ma, tenNhaXuatBan, soBanPhatHanh) {
		this->ngayPhatHanh = ngayPhatHanh;
	}
	void Nhap(Bao&);
	void Xuat(Bao&);
	void doc(Bao*&a);
	std::string getMa() {
		return TaiLieu::getMa();
	}
	std::string getTenNhaXuatBan() {
		return TaiLieu::getTenNhaXuatBan();
	}
};

void Bao::Nhap(Bao& a) {
	TaiLieu::Nhap(a);
	std::cin.ignore();
	std::cout << "Nhap ngayPhatHanh: "; std::cin >> a.ngayPhatHanh;
}
void Bao::Xuat(Bao& a) {
	if (a.ma != "") {
		TaiLieu::Xuat(a);
		std::cout << "NgayPhatHanh: " << std::left << std::setw(10) << a.ngayPhatHanh << "\n";
	}
}
void Bao::doc(Bao* &a) {
	std::ifstream fs("Bao.txt", std::ios::in);
	TaiLieu::doc(fs, a);
}

