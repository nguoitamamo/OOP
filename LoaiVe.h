#pragma once
#include<iostream>
#include<string>
#include<utility>
#include<map>


enum LoaiVe {
  HangThuonGia= 50,
  HangPhoThong = 20
};

LoaiVe LayGiaTriLoaiVe(std::string loaiVe) {
    if( loaiVe == "HangThuongGia")
        return LoaiVe::HangThuonGia; 
    else if ( loaiVe=="HangPhoThong")
        return LoaiVe::HangPhoThong;
    else 
        std::cout << "Khong ton tai loai ve nay!\n";
    
    
}