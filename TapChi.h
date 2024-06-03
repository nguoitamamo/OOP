#pragma once
#include"TaiLieu.h"

class TapChi :TaiLieu {
private: 
	std::string soPhatHanh;
	int thangPhatHanh;
public:
	TapChi() {};
    TapChi(std::string ma, std::string tenNhaXuatBan, int soBanPhatHanh, std::string soPhatHanh, int thangPhatHanh) :TaiLieu(ma, tenNhaXuatBan, soBanPhatHanh) {
		this->soPhatHanh = soPhatHanh;
		this->thangPhatHanh = thangPhatHanh;
	}
	void Nhap(TapChi&);
	void Xuat(TapChi&);
	void doc(TapChi*&a);
	std::string getMa() {
		return TaiLieu::getMa();
	}
	std::string getTenNhaXuatBan() {
		return TaiLieu::getTenNhaXuatBan();
	}
};

void TapChi::Nhap(TapChi& a) {
	TaiLieu::Nhap(a);
	std::cin.ignore();
	std::cout << "Nhap soPhatHanh: "; std::cin >> a.soPhatHanh;
	std::cout << "Nhap thangPhatHanh: "; std::cin >> a.thangPhatHanh;
}
void TapChi::Xuat(TapChi& a) {
	if (a.ma != "") {
		TaiLieu::Xuat(a);
		std::cout << "SoPhatHanh: " << std::left << std::setw(10) << a.soBanPhatHanh << "ThangPhatHanh: " << std::left << std::setw(10) << a.thangPhatHanh << "\n";
	}
}
void TapChi::doc(TapChi* &a) {
	std::ifstream fs("TapChi.txt", std::ios::in);
	TaiLieu::doc(fs, a);
}