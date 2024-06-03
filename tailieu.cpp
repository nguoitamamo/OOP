#include<iostream>
#include"Sach.h"
#include"TapChi.h"
#include"Bao.h"
#include<algorithm>



Sach* sach = new Sach[10];
TapChi* tapChi = new TapChi[10];
Bao* arrayBao = new Bao[10];


void menu() {
	std::cout << "1: Sap xep\n";
	std::cout << "2: Tim kiem\n";
	std::cout << "3: thoat\n";
}
void inDS() {
	std::cout << "--SACH--\n";
	for (int i = 0; i < 10; i++)
		sach[i].Xuat(sach[i]);
	std::cout << "--TAPCHI--\n";
	for (int i = 0; i < 10; i++)
		tapChi[i].Xuat(tapChi[i]);
	std::cout << "--BAO--\n";
	for (int i = 0; i < 10; i++) {
		arrayBao[i].Xuat(arrayBao[i]);
	}
}
int main()
{


	sach->doc(sach);
	tapChi->doc(tapChi);
	arrayBao->doc(arrayBao);
	inDS();

	
	while (true) {
		menu();
		int n;
		std::cout << "Nhap lua chon: "; std::cin >> n;
		switch (n) {
		case 1:
		{
			std::sort(sach, sach + 10, cmp<Sach>);
			std::sort(tapChi, tapChi + 10, cmp<TapChi>);
			std::sort(arrayBao, arrayBao + 10, cmp<Bao>);
			inDS();
			break;
		}
		case 2: {
			
		}

		}
	
	}



	
	delete[] sach;
	sach = nullptr;
	delete[] tapChi;
	tapChi = nullptr;
	delete[] arrayBao;
	arrayBao = nullptr;
	return 0;
}