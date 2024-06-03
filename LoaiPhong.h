#pragma once
enum LoaiPhong {
    A = 500,
    B = 300,
    C = 100
};

LoaiPhong layGiaTriPhong(char loaiPhong) {
    switch (loaiPhong) {
    case 'A':
        return LoaiPhong::A;
    case 'B':
        return LoaiPhong::B;
    case 'C':
        return LoaiPhong::C;
    default:
        std::cout << "Loai phong khong hop le!\n";
    }
}