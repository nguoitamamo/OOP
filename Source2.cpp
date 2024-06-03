#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
void  count(int x, int y) {
	ofstream os("answer.txt");
	if (!os.is_open()) {
		cout << "no\n";
		return;
	}
	else {
		int s = 1;
		for (int i = 1; i <= y; i++) {
			s *= x + 5;
			os << "y = " << i << ": S=s* x + 5 = " << s << "\n";
		}
	}
	
}
//#define s "Dien Dien tu"
int  HamSum(int  a[], int n) {
	int i, tong = 0;
	for (i = 0; i <  n; i++) {
		tong = tong + a[i];
	}
	return tong;
}
float Mean(int a[], int n) {
	float ans = 0;
	for (int i = 0; i < n; i++) {
		ans = ans + a[i];
	}
	return ans / n;
}
int main(){
  
	//int a[3][3] = { { 12} , { 4} ,{ 20 ,23} };
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		printf("%d\t", a[i][j]);
	//		if (j == 2) printf("\n");
	//	}
	//}
	//char c[] = "DH SPKT TPHCM";
	//for (int i = 0; c[i] != '\0'; i++) {
	//	printf("&c", c[i]);
	//}
	//printf("\n%s", s);
	int a[100] = {};
	int n; scanf("%d", n);
	for (int i = 0; i < n; i++) {

	}


	return 0;
}