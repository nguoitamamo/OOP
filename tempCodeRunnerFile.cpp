
    KhoiTaoDS(l);
    // mở file lên
    ifstream filein("SINHVIEN.txt");
    if (!filein.is_open())
    {
        cout << "fail\n";
        exit(1);
    }
    cout << "HNT\n";
    Doc_Danh_Sach_SinhVien(filein, l);
    XuatDanhSachSinhVien(l);