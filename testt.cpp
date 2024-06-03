#include<iostream>
#include<fstream>
#include<ctime>
#include<string>

using namespace std;

struct date {
	int day;
	int month;
	int year;
	void operator = (const date& d) {
		day = d.day;
		month = d.month;
		year = d.year;
	}
};

class BasicInformation {
public:
	string Name;
	int EmployeeCode;
	date Birth;
	string Sex;
};

class Employee : public BasicInformation {
public:
	string HomeTown;			//Quê quán
	int Salary;					//Lương
	date JoinDate;				//Ngày gia nhập
	static int Quantity;		//Tổng số nhân viên trong công ty
	string DayOff;				//Ngày nghỉ trong tuần
};

class LeftEmployee : public BasicInformation {
public:
	date LeftDate;				//Ngày rời đi 
	static int Quantity;		//
	void Left(const Employee&);
};

class OfficeWorker : public Employee {
public:
	int Room;
	void Input();
	void Output();
	static int Quantity;
};

class ProduceWorker : public Employee {
public:
	int Norm;					//Định mức số lượng sản phẩm
	string DayOff;
	void Input();
	void Output();
	static int Quantity;
};

// Định nghĩa các thuộc tính và phương thức của LeftEmployee

int LeftEmployee::Quantity = 0;

void LeftEmployee::Left(const Employee& Human) {
	Name = Human.Name;
	EmployeeCode = Human.EmployeeCode;
	Birth = Human.Birth;
	Sex = Human.Sex;

	time_t now = time(nullptr);
	tm* timeinfo = localtime(&now);

	LeftDate.day = timeinfo->tm_mday;
	LeftDate.month = timeinfo->tm_mon + 1;
	LeftDate.year = timeinfo->tm_year + 1900;

	Quantity--;
}

// Định nghĩa các thuộc tính và phương thức của OfficeWorker

int OfficeWorker::Quantity = 0;

void OfficeWorker::Input() {

	ifstream In;
	In.open("Input.txt", ios_base::in);

	if (!In.is_open()) {
		cout << "Khong the mo file Input.txt.\n";
		In.close();
		return;
	}

	getline(In, Name);
	In >> EmployeeCode;

	In >> Birth.day >> Birth.month >> Birth.year;

	In >> Sex;
	getline(In, HomeTown);
	In >> Salary;

	time_t now = time(nullptr);
	tm* timeinfo = localtime(&now);

	JoinDate.day = timeinfo->tm_mday;
	JoinDate.month = timeinfo->tm_mon + 1;
	JoinDate.year = timeinfo->tm_year + 1900;

	In >> Room;

	Quantity++;

	In.close();
}

void OfficeWorker::Output() {

	ofstream Out;
	Out.open("Output.txt", ios_base::out);

	Out << Name << endl;
	Out << EmployeeCode << endl;

	Out << Birth.day << "/" << Birth.month << "/" << Birth.year << endl;

	Out << Sex << endl;
	Out << HomeTown << endl;
	Out << Salary << endl;

	Out << JoinDate.day << "/" << JoinDate.month << "/" << JoinDate.year << endl;

	Out << Room << endl;

	Out.close();
}

// Định nghĩa các thuộc tính và phương thức của ProduceWorker

int ProduceWorker::Quantity = 0;

void ProduceWorker::Input() {

	ifstream In;
	In.open("Input.txt", ios_base::in);

	getline(In, Name);
	In >> EmployeeCode;

	In >> Birth.day >> Birth.month >> Birth.year;

	In >> Sex;
	getline(In, HomeTown);
	In >> Salary;

	time_t now = time(nullptr);
	tm* timeinfo = localtime(&now);

	JoinDate.day = timeinfo->tm_mday;
	JoinDate.month = timeinfo->tm_mon + 1;
	JoinDate.year = timeinfo->tm_year + 1900;

	In >> Norm;

	Quantity++;

	In.close();
}

void ProduceWorker::Output() {

	ofstream Out;
	Out.open("Output.txt", ios_base::out);

	Out << Name << endl;
	Out << EmployeeCode << endl;

	Out << Birth.day << "/" << Birth.month << "/" << Birth.year << endl;

	Out << Sex << endl;
	Out << HomeTown << endl;
	Out << Salary << endl;

	Out << JoinDate.day << "/" << JoinDate.month << "/" << JoinDate.year << endl;

	Out << Norm << endl;

	Out.close();
}