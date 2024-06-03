#pragma once
#include<iostream>
#include<sstream>
#include<fstream>



struct SinhVien {
public:
	
	std::string ten, ma;
	int date;

	SinhVien() {}
	SinhVien(std::string ten, std::string ma, int date) {
		this->ten = ten;
		this->ma = ma;
		this->date = date;
	}
	friend std::ostream operator >> (std::ostream, SinhVien);
	friend std::istream& operator << (std::istream& , SinhVien&);

	void ghiSinhVienToFile(SinhVien a);
	void docSinhVien


};


std::ostream operator >> (std::ostream out, SinhVien a) {


}

std::istream& operator << (std::istream& in, SinhVien& a) {
	std::cout << "Nhập tên sinh viên: "; in >> a.ten;
	std::cout << "Nhập mã sinh vien: "; in >> a.ma;
	std::cout << "Nhập ngày sinh: "; in >> a.date;
	return in;

}

void SinhVien::ghiSinhVienToFile(SinhVien a) {
	std::ofstream os;
	os.open("SinhVien.txt", std::ios::out);

	if (!os.is_open()) { std::cout << "Mở file Fail!"; return; }

	os << a.ten << "," << a.ma << "," << a.date << "\n";


}

