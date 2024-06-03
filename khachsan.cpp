#include<iostream>
#include"Nguoi.h"




void menu() {
	std::cout << "1: Nhap nguoi thue\n";
	std::cout << "2: Xuat danh sach\n";
	std::cout << "3: Xoa nguoi thue\n";
	std::cout << "4: Tinh tien thue phong\n";
	std::cout << "5: thoat\n";
}


int main()
{
	int sizeDs = 10;
	Nguoi* nguoi = new Nguoi[sizeDs];
	nguoi->doc(nguoi);
	while (true) {
		menu();
		int n;
		std::cout << "Nhap lua chon: "; std::cin >> n;
		switch (n) {
		case 1: 
		{
			int m; std::cout << "Nhap so luong can nhap: "; std::cin >> m;
			for (int i = 0; i < m; i++) nguoi[i].nhap();
			break;
		}
		case 2:
		{
			for (int i = 0; i < sizeDs; i++) nguoi[i].xuat(); break;
		}
		case 3: 
		{
			std::string cmnd;
			std::cout << "Nhap so CMND can xoa: "; std::cin >> cmnd;
			nguoi->Xoa(&nguoi, cmnd, sizeDs);
			break;
		}
		case 4: {
			for (int i = 0; i < sizeDs; i++) {
				nguoi[i].calTongTien();
			}
		}
		}
	}
	delete[] nguoi;
	nguoi = nullptr;



	return 0;
}