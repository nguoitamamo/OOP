#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>


struct KhachHang {
	int static indexID;
	std::string maKH, maMay, hoTen, date;
	int gioVao;
	std::string gioRa;
	int tongTien;
	friend std::ostream& operator << (std::ostream& out, KhachHang&);
	friend std::istream& operator >> (std::istream& in, KhachHang&);
	KhachHang() {
		maKH = std::to_string(indexID++);
	}
 
};
int KhachHang::indexID = 0;

void CalTongTien(int a, int b, int& tong) {
	if (a >= 0 && b <= 24) { tong += (b - a) * 4000; b = b - 17; }
	if (b > 0) { tong += b * 2000; }

}

void CalTongTienInNgay(int a, std::string b, int &tong) {
	int index = b.find('_');
	int soGio = stoi(b.substr(0, index));
	int soNgay = stoi(b.substr(index + 1));

	if (soNgay ==1) {
		CalTongTien(a, soGio, tong);
		return ;
	}
	else {
		CalTongTien(a, 24, tong);
		CalTongTien(0, soGio, tong);
		return;
	}
}


std::istream& operator >> (std::istream& in, KhachHang& a) {
	std::cout << "Nhap ten khach hang: ";
	in.ignore(); // Để bỏ qua ký tự newline còn lại trong bộ đệm
	std::getline(in, a.hoTen);

	std::cout << "Ngay sinh: "; in >> a.date;

	std::cout << "Nhap gio vao: "; in >> a.gioVao;
	std::cout << "Nhap gio ra ( vd: 2_1 ->so dau tien la so gio, so thu hai la so ngay ): "; in >> a.gioRa;
	std::cout << "Nhap so may: "; in >> a.maMay;

	std::vector<char> ref;
	std::stringstream ss(a.hoTen);
	std::string kq;
	while (getline(ss, kq, ' ')) ref.push_back(std::toupper(kq[0]));
	a.maKH += "_"+ a.maMay +"_";
	for (char& x : ref) a.maKH += x;
	a.tongTien = 0;
	CalTongTienInNgay(a.gioVao, a.gioRa, a.tongTien);

	return in;
}

std::ostream& operator << (std::ostream& out, KhachHang& a) {
	out << a.maKH << " " << a.maMay << " " << a.hoTen << " " << a.date << " " << a.gioVao << " " << " " << a.gioRa << " " << a.tongTien << "\n";
	return out;
}
