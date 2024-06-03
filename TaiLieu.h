#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>

class TaiLieu {
protected: std::string ma, tenNhaXuatBan;
    	 int soBanPhatHanh;
public: 
    TaiLieu() {};
    TaiLieu(std::string ma, std::string tenNhaXuatBan, int soBanPhatHanh) {
        this->ma = ma;
        this->tenNhaXuatBan = tenNhaXuatBan;
        this->soBanPhatHanh = soBanPhatHanh;
    }
    void Nhap(TaiLieu&);
    void Xuat(TaiLieu&);
	template<class T> 
    void doc(std::ifstream &fs, T*&);
	
	std::string getMa() { return this->ma; }
	std::string getTenNhaXuatBan() { return this->tenNhaXuatBan; }


};

void TaiLieu::Nhap(TaiLieu& a) {
    std::cout << "Nhap ma: "; std::cin >> a.ma;
    std::cin.ignore();
    std::cout << "Nhap tenNhaXuatBan: "; std::getline(std::cin ,a.tenNhaXuatBan);
    std::cout << "Nhap soBanPhatHanh: "; std::cin >> a.soBanPhatHanh;
}

void TaiLieu::Xuat(TaiLieu& a) {
    std::cout << "Ma: " << std::left << std::setw(10) << a.ma << "TenNhaXuatBan: " << std::left << std::setw(20) << a.tenNhaXuatBan << "SoBanPhatHanh: " << std::left << std::setw(10) << a.soBanPhatHanh;
}
template<class T>
void TaiLieu::doc(std::ifstream& fs, T* &a) {
	if (!fs.is_open()) return;
	std::string line;
	std::vector<std::string> ref;
	int index = 0;
	while (getline( fs, line)) {
		std::stringstream ss(line);
		std::string tmp;
		while (std::getline(ss, tmp, '#')) {
			ref.push_back(tmp);
		}
		if (ref.size() == 5) {
			T t = T(ref[0], ref[1], stoi(ref[2]), ref[3], stoi(ref[4]));
			a[index] = t;
			index++;
			ref.clear();
		}
	}
}
template<class T>
bool cmp(T& a, T& b) {
	return (a.getMa() < b.getMa()) ? a.getMa() < b.getMa() : a.getTenNhaXuatBan() < b.getTenNhaXuatBan();
}