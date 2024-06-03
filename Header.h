#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>

struct SinhVien {
	std::string ma, hoten;
	int date;
	friend std::ostream& operator <<  (std::ostream& out, SinhVien);
	friend std::istream& operator >> (std::istream& in, SinhVien&);.
	void ghiFileSinhVien(SinhVien& a);
};


std::ostream& operator << (std::ostream& out, SinhVien a) {
	out << a.ma << " " << a.hoten << " " << a.date << "\n"; 
	return out;
}
std::istream& operator >> (std::istream& in, SinhVien& a) {
   // in.ignore();
	std::cout << "Nhap ma: "; in >> a.ma;
	std::cout << "Nhap ho ten: "; in >> a.hoten;
	in.ignore();
	std::cout << "Nhap ngay sinh: "; in >> a.date;
	return in;
}


void SinhVien::ghiFileSinhVien(SinhVien& a) {
	std::ofstream of("onputSinhVien.txt", std::ios::app);
	if (!of.is_open()) return;
	of << a.ma << "#" << a.hoten << "#" << a.date << "\n";
}

void docFileSinhVien(SinhVien* &a) {
	std::ifstream fs("onputSinhVien.txt", std::ios::in);
	if (!fs.is_open()) return;
	std::string line;
	std::vector<std::string> vtmp;
	int index = 0;
	while (getline(fs, line)) {
		std::stringstream ss(line);
		std::string stmp;
		while (getline(ss, stmp, '#')) {
			vtmp.push_back(stmp);
		}
		if (vtmp.size() == 3) {
			a[index].ma = vtmp[0]; a[index].hoten = vtmp[1]; a[index].date = stoi(vtmp[2]);
			index++;
			vtmp.clear();
		}
	}


}