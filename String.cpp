#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<algorithm>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<map>
using namespace std;

class Peopel {
private:
	string name, address, birthday;
public:
	Peopel() {
		name = address = birthday = "0";
	}
	Peopel(string name, string address, string birthday) {
		this->name = name;
		this->address = address;
		this->birthday = birthday;
	}
	void nhap();
	void in();
	string  getName() {
		return this->name;
	}
	string getAddress() {
		return this->address;
	}
	string  getBirthday() {
		return this->birthday;
	}

};

void Peopel::nhap() {
	cin.ignore();
	cout << "Nhap ten : "; getline(cin, name);
	cout << "Nhap address: "; getline(cin, address);
	cout << "Nhap birthday: "; getline(cin, birthday);
}

string MSSV(string s) {
	while (s.length() < 10) {
		s += to_string(rand() % 10);
	}
	return s;
}

class Sinhvien : public Peopel {
private:
	float gpa;
	string mssv;
public:
	Sinhvien() {
		Peopel::Peopel();
		gpa = 0;
		mssv = "0";
	}
	Sinhvien(string name, string address, string birthday, float gpa, string mssv) : Peopel(name, address, birthday) {
		this->gpa = gpa;
		this->mssv = mssv;
	}
	void nhap();
	void in();
	void Delete(string s);
	void change(string s);
	void setGpa(float new_gpa) {
		this->gpa = new_gpa;
	}
	void doc();
	float getGpa() {
		return this->gpa;
	}
	
	//friend bool operator < (Sinhvien&, Sinhvien&);

	void ghi(Sinhvien);
};

vector < vector <Sinhvien> >* ds = new vector< vector <Sinhvien> >;
vector < Sinhvien > tmp;
map<string, int> mp;

void Sinhvien::ghi(Sinhvien a) {

	ofstream os("ouput.txt", ios::app);
	string boder = string(20 * 5 + 12, '-');
	os.seekp(0, ios::end); // di chuyển con trỏ đến cuối file 
	if (os.tellp() == 0) { // để lấy vị trí hiện tại của con trỏ 
		os << boder << "\n";
		os << left << "| " << setw(20) << "Name" << "| " << setw(20) << "Address" << "| " << setw(20) << "Birthday" << "| "
			<< setw(20) << "MSSV" << "| " << setw(20) << "GPA" << " |" << "\n";

		os << boder << "\n";
	}
	os << left << "| " << setw(20) << a.getName() << "| " << setw(20) << a.getAddress() << "| "
		<< setw(20) << a.getBirthday() << "| " << setw(20) << a.mssv << "| " << setw(20) << a.gpa << " |" << "\n";
	os << boder << "\n";
	os.close();
}
void Sinhvien::doc() {

	ifstream fs("input.txt");
	if (!fs.is_open()) {
		cout << "NO\n";
		return;
	}
	else {

		string line;
		vector< string > v;
		while (getline(fs, line)) {
			stringstream ss(line);
			string elem;
			while (getline(ss, elem, '#')) {
				v.push_back(elem);
			}
			if (v.size() == 4) {
				
				string s = MSSV("");
				mp[s]++;
				while (mp[s] != 1) {
				    s = MSSV("");
					mp[s]++;
				}
				
				Sinhvien x{ v[0], v[1], v[2], stof(v[3]) , s };
				x.ghi(x);
				tmp.push_back(x);
				v.clear();

			}

		}

		ds->push_back(tmp);
		tmp.clear();
	}
	fs.close();
}

void Sinhvien::nhap() {
	Peopel::nhap();
	cout << "Nhap gpa: "; cin >> gpa;
	mssv = MSSV("");
	while (mp[mssv] != 1) {
		mssv = MSSV("");
		mp[mssv]++;
	}

	Sinhvien x{ getName(), getAddress(), getBirthday(), gpa, mssv };
	x.ghi(x);
	tmp.push_back(x);
	ds->push_back(tmp);
	tmp.clear();
}
void Sinhvien::in() {
	cout << left << "| " << setw(20) << getName() << "| " << setw(20) << getAddress() << "| "
		<< setw(20) << getBirthday() << "| " << setw(20) << mssv << "| " << setw(20) << gpa << " |" << "\n";
}
void Sinhvien::Delete(string s) {

	for (int i = 0; i < ds->size(); i++) {
		for (int j = 0; j < ds->at(i).size(); j++) {
			if (ds->at(i).at(j).mssv == s) {
				ds->at(i).erase(ds->at(i).begin() + j);
				// Hoặc ds->at(i).at(j) = Sinhvien(); để xóa đối tượng sinh viên.
			}
		}
	}
}

void inds() {
	if (ds->size() == 0) {
		cout << "NO\n";
		return;
	}
	string boder = string(20 * 5 + 12, '-');
	cout << boder << "\n";
	cout << left << "| " << setw(20) << "Name" << "| " << setw(20) << "Address" << "| " << setw(20) << "Birthday" << "| "
		<< setw(20) << "MSSV" << "| " << setw(20) << "GPA" << " |" << "\n";
	for (auto& elem : *ds) {
		for (auto& sv : elem) {
			cout << boder << "\n";
			sv.in();
		}
		cout << boder << "\n";
	}

}
void Sinhvien::change(string s) {
	float new_gpa;
	cout << "Nhap gpa can sua: "; cin >> new_gpa;
	for (int i = 0; i < ds->size(); i++) {
		for (int j = 0; j < ds[i].size(); j++) {
			if (ds[i][j][j].mssv == s) {
				ds[i][j][j].setGpa(new_gpa);
			}
		}
	}
}
void Menu() {
	cout << "-----------------\n";
	cout << "1: Nhap: \n";
	cout << "2: Xoa: \n";
	cout << "3: Sua:\n";
	cout << "4: sap xep\n";
	cout << "5: Thoat:\n";
	
	cout << "-----------------\n";
}
//bool cmp(Sinhvien &a, Sinhvien &b) {
//	if (a.getGpa() != b.getGpa()) return a.getGpa() < b.getGpa();
//	else {
//		return a.getName() < b.getName();
//	}
//}
//bool operator < (Sinhvien& a, Sinhvien& b) {
//	if (a.getGpa() != b.getGpa()) return a.getGpa() < b.getGpa();
//	else {
//		return  a.getName() < b.getName();
//	}
//}
int main()
{

	int n1; std::cin >> n1;


	Sinhvien a;

	bool check = true;

	a.doc();

	while (check) {
		Menu();
		int x; cout << "Lua chon: "; cin >> x;
		if (x == 1) {
			int n; cin >> n;
			while (n--) {
				a.nhap();
			}
		}
		else if (x == 2) {
			inds();
			cout << "Nhap mssv can xoa: "; string s; cin >> s;
			a.Delete(s);
		}
		else if (x == 3) {
			inds();
			break;
			cout << "Nhap mssv can sua: "; string s; cin >> s;
			a.change(s);
		}
		//else if (x == 4) {
		//	sort(ds->begin(), ds->end(), cmp);
		//	//sort(ds->begin(), ds->end());
		//}
		else {
			check = false;
		}
	}
	return 0;
}