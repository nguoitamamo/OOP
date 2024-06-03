#include<iostream>
#include <string>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>
#include<algorithm>


class People {
private:
	std::string name;
	int age;
	std::string nickname;
public:
	People() {
		name = "";
		age = 0;
		nickname = "";
	}
	People(std::string name, int age, std::string nickname);
	friend std::ostream& operator << (std::ostream&, People);
	friend std::istream& operator >> (std::istream&, People&);
	std::string getName() {
		return this->name;
	}
	int getage() {
		return this->age;
	}
	std::string getNickaname() {
		return this->nickname;
	}

	People& operator = (People& h) {
		this->name = h.name;
		this->age = h.age;
		this->nickname = h.nickname;
		return h;
	}  
	//People(People& h) {
	//	this->name = h.name;
	//	this->age = h.age;
	//	this->nickname = h.nickname;
	//}
};

People::People(std::string name, int age, std::string nickname) {
	this->name = name;
	this->age = age;
	this->nickname = nickname;
}
std::ostream& operator << (std::ostream& out, People a) {
	out << std::left << std::setw(20) << a.name << std::left << std::setw(7) << a.age << std::left << std::setw(7) << a.nickname;
	return out;
}


std::istream& operator >> (std::istream& in, People& a) {
	std::cout << "Name: "; getline(in, a.name);
	std::cout << "Age: ";  in >> a.age;
	std::cout << "NickName: "; in >> a.nickname;
	return in;
}

class Sinhvien :public People {
private:
	float gpa;
	std::string xl;
	std::string mssv;
public:
	Sinhvien() {
	Sinhvien:People();
		gpa = 0;
		xl = "";
		mssv = "";
	}
	Sinhvien(People d, float gpa, std::string xl, std::string mssv) : People(d) {
		this->gpa = gpa;
		this->xl = xl;
		this->mssv = mssv;
	}
	friend std::ostream& operator << (std::ostream& out, Sinhvien a) {
		out << static_cast<People>(a) << std::left << std::setw(7) << a.gpa << std::left << std::setw(7) << a.xl << std::left << std::setw(7) << a.mssv << "\n";
		return out;
	}
	friend std::istream& operator >> (std::istream& in, Sinhvien& a);
	void setGpa(float gpa) {
		this->gpa = gpa;
	}
	
	float getGpa() {
		return this->gpa;
	}
	std::string getXl() {
		return this->xl;
	}
	std::string getMssv() {
		return this->mssv;
	}
	Sinhvien& operator=( Sinhvien& h) {
		People(*this) = People::operator =(h);
		this->gpa = h.gpa;
		this->xl = h.xl;
		this->mssv = h.mssv;
		return h;
	}
	/*Sinhvien(Sinhvien& h): People(h) {
		this->gpa = h.gpa;
		this->xl = h.xl;
		this->mssv = h.mssv;
	}*/

};
std::vector< std::vector< Sinhvien> >* ds = new std::vector< std::vector< Sinhvien> >;
std::vector< Sinhvien> v;
 
std::ifstream fs("input_ds.txt");
std::ofstream os("output_ds.txt");

std::string randd(std::string s) {
	while (s.length() != 7) {
		s += std::to_string(rand() % 10);
	}
	return s;
}



std::istream& operator >> (std::istream& in, Sinhvien& a) {
	in >> static_cast<People&>(a);
	in.ignore();
	std::cout << "Gpa: ";  in >> a.gpa;
	std::cout << "Xep loai: "; in >> a.xl;
	std::string MSSV = randd("");
	Sinhvien x{ People( a.getName(), a.getage(), a.getNickaname()), a.gpa, a.xl, MSSV};
	v.push_back(x);
	ds->push_back(v);
	v.clear();

	
	return in;
}



void inds() {
	for (auto& x : *ds) {
		for (auto& sv : x) {
			std::cout << "\n" << sv;
		}
	}
}


int main()
{

	

	Sinhvien a;
	std::cin >> a;
	Sinhvien b(a);
	
	std::cout << b;
	return 0;
}
