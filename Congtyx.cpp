
#define _CRT_SECURE_NO_WARNINGS
#include "Congtyx.h"






int main() {

	//OfficeWorker* ow;
	//ow = new OfficeWorker;

	//ProduceWorker* pw;
	//pw = new ProduceWorker;

	//LeftEmployee* le;
	//le = new LeftEmployee;

	OfficeWorker ow;
	ProduceWorker pw;


	int Choose;
	int i = 0;
	while (true) {
		system("cls");
		std::cout << "Chao mung den voi chuong trinh quan ly cong ty x, ban muon lam gi?" << endl;
		std::cout << "1. Them thanh vien" << endl;
		std::cout << "2. Xet duyet roi cong ty" << endl;
		cout << "3. Lich nghi cua doi tuong cong nhan" << endl;
		cout << "4. Hien thi danh sach nhan vien" << endl;
		cout << "5. Hien thi thong tin nhan vien" << endl;
		cout << "6. Thoat chuong trinh" << endl;
		cin >> Choose;

		switch (Choose) {
		case 1:
			system("cls");
			int choose;
			cout << "Ban muon them nhan vien o vi tri ..." << endl;
			cout << "1. Nhan vien van phong" << endl;
			cout << "2. Cong nhan san xuat" << endl;
			cout << "3. Huy them" << endl;
			cin >> choose;

			switch (choose) {
			case 1:
				//system("cls");
			
				ow.Input();
				ow.Output();
				cout << "Nhan vien van phong " << ow.Name << " da duoc them." << endl;
				//	OfficeWorker::Quantity++;
				//break;
			case 2:
				//system("cls");
				
				pw.Input();
				pw.Output();
				cout << "Cong nhan san xuat " << pw.Name << " da duoc them." << endl;
				//ProduceWorker::Quantity++;
				break;


			case 3: cout << "Da huy\n";
			}

		case 6:
			//system("cls");
			cout << "Cam on da su dung dich vu.";
			exit(0);
		}
	}

	/*
	* 
	*/

	return 0;
}