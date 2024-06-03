#include<iostream>
#include"Header.h"
int main()
{

	SinhVien* arraySinhVien= new SinhVien[10];


	
	docFileSinhVien(arraySinhVien);
	//int n;
//std::cout << "Nhap sl SinhVien can nhap: ";
//std::cin >> n;

	for (int i = 0; i < 3; i++) {
		std::cout << arraySinhVien[i];
        
	}
	system("pause");
	return 0;
}