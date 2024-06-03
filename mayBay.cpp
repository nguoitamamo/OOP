#include <iostream>
#include <iomanip>
#include"KhachHangMuaVe.h"

int n, m;
int** MaTranVe;

void inMaTran() {

    std::cout << std::setw(3) << " ";
    for (int j = 0; j < m; j++)
        std::cout << std::left << std::setw(3) << j + 1;
    std::cout << "\n";

    for (int i = 0; i < n; i++) {
        std::cout << std::left << std::setw(3) << char(65 + i);
        for (int j = 0; j < m; j++) {
            std::cout << std::left << std::setw(3) << MaTranVe[i][j];
        }
        std::cout << "\n";
    }
}


void menu() {
    std::cout << "1: Dat ve\n";
    std::cout << "2: Sua thong tin ve\n";
    std::cout << "3: xoa ve\n";
    std::cout << "4: in ma tran ve\n";
    std::cout << "5: in thong tin ve\n";
    std::cout << "6: thoat\n";
}
int main() {
    std::cout << "Nhap So Dong, So Cot: "; std::cin >> n >> m;


    MaTranVe = new int* [n + 1];
    VeMayBay** thongTinVe = new VeMayBay * [n];
    for (int i = 0; i < n; i++) {
        MaTranVe[i] = new int[m + 1];
        thongTinVe[i] = new VeMayBay[m];
        
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            MaTranVe[i][j] = 0;
        }
    }

    thongTinVe[0]->doc(thongTinVe[0], MaTranVe, 0, m);
    //thongTinVe[0]->doc(thongTinVe[0], MaTranVe, 0, m);
    inMaTran();

    while (true) {

        menu();
        int luaChon; std::cout << "Nhap lua chon: "; std::cin >> luaChon;
        switch (luaChon) {
        case 1:
        {
            int x, y;
            std::cout << "Nhap vi tri dat ve: "; std::cin >> x >> y;
            thongTinVe[x - 1][y - 1].nhap();
            thongTinVe[x - 1][y - 1].xuat();
            MaTranVe[x - 1][y - 1] = 1;
            break;
        }
        case 4: {
            inMaTran();
            break;
        }
        case 5:
        {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    thongTinVe[i][j].xuat();
                }
            }
        }

        }

    }




    for (int i = 0; i < n; i++) {
        delete[] MaTranVe[i];
        delete[] thongTinVe[i];
    }

    delete[] MaTranVe; MaTranVe = nullptr;
    delete[] thongTinVe; thongTinVe = nullptr;

    return 0;
}
