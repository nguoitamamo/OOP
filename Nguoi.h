#pragma once


#include<iostream>
#include<string>
#include<sstream>
#include"LoaiPhong.h"
#include<algorithm>
#include <iomanip>
#include<fstream>
#include<vector>
#include<cstring>
#include"LoaiPhong.h"


class Nguoi {
private:
	std::string hoTen, CMND, tongTien;
	int tuoi;
	int soNgayThue;
	char loaiPhongThue;
public :
	Nguoi() { };
	Nguoi(std::string ten, std::string CMND, int tuoi, int soNgayThue, char loaiPhong, std::string tien) {
		this->hoTen = hoTen;
		this->CMND = CMND;
		this->tuoi = tuoi;
		this->soNgayThue = soNgayThue;
		this->loaiPhongThue = loaiPhong;
		this->tongTien = tongTien;
	}
	void nhap();
	void xuat();
	void Xoa(Nguoi* a[], std::string CMND, int &n);
	void doc(Nguoi* &a);
	void calTongTien();
};


void Nguoi::nhap() {
	    std::cin.ignore();
		std::cout << "Nhap hoTen: "; std::getline(std::cin, hoTen);
		std::cout << "Nhap CMND: "; std::cin >> CMND;
		std::cout << "Nhap tuoi: "; std::cin >> tuoi;
		std::cout << "Nhap soNgayThue: "; std::cin >> soNgayThue;
		std::cout << "Nhap loaiPhongThue: "; std::cin >> loaiPhongThue;
	
}
void Nguoi::xuat() {
	if (this->CMND != "") {
		std::cout << "HoTen: " << std::left << std::setw(15) << hoTen << "CMND: " << std::left << std::setw(13) << CMND << "Tuoi: " << std::left << std::setw(5) << tuoi
			<< "SoNgayThue: " << std::left << std::setw(5) << soNgayThue << "LoaiPhongThue: " << std::left << std::setw(5) << loaiPhongThue << "\n";
	}
}

void Nguoi::Xoa(Nguoi* a[], std::string CMND, int &n) {
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]->CMND == CMND) {
			index = i;
			break;
		}

	}
	delete& a[index];
	for (int i = index; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	n--;

}
void Nguoi::doc(Nguoi* &a) {
	std::ifstream fs("Nguoi.txt", std::ios::in);
	if (!fs.is_open()) return;
	std::string line;
	std::vector<std::string> ref;
	int index = 0;
	while (getline(fs, line)) {
		std::stringstream ss(line);
		std::string tmp;
		while (getline(ss, tmp, '#')) {
			ref.push_back(tmp);
		}
		if (ref.size() == 6) {
		
			Nguoi t = Nguoi(ref[0], ref[1], stoi(ref[2]), stoi(ref[3]), ref[4][0], ref[5]);
			a[index] = t;
			index++;
			ref.clear();

		}
	}
}


void Nguoi::calTongTien() {
	LoaiPhong giaPhong = layGiaTriPhong(loaiPhongThue);
	tongTien = giaPhong * soNgayThue;
}
