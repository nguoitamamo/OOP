#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class sinhvien {
private:
	string ma, ten, lop, email;
public:
	sinhvien() {
		ma = ten = lop = email = "";
	}
	friend istream& operator >> (istream& in, sinhvien&);
	friend ostream& operator << (ostream& out, sinhvien);
	friend bool cmp(sinhvien, sinhvien);
};
istream& operator >> (istream& in, sinhvien& a) {
	in >> a.ma;
	in.ignore();
	getline(in, a.ten);
	in >> a.lop >> a.email;
	return in;
}
ostream& operator << (ostream& out, sinhvien a) {
	out << a.ma << " " << a.ten << " " << a.lop << " " << a.email << "\n";
	return out;
}
bool cmp(sinhvien a, sinhvien b) {
	if (a.ten != b.ten) return a.ten < b.ten;
	return a.ma < b.ma;
}

int main()
{
	sinhvien a[100];
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) cout << a[i];

	return 0;
}