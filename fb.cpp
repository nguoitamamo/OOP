#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct Date
{
    string day;
    string month;
    string year;
};

struct SinhVien
{
    string hoten;
    string mssv;
    Date ngaysinh;
    float dtb;
};

struct Node
{
    SinhVien data;
    Node *pNext = nullptr;
};

Node *KhoiTaoNode(const SinhVien &x)
{
    Node *p = new Node;
    p->data = x;
    p->pNext = nullptr;
    return p;
}

void Insert(Node *&head, const SinhVien &a)
{
    Node *p = KhoiTaoNode(a);
    if (head == nullptr)
    {
        head = p;
    }
    else
    {
        Node *tmp = head;
        while (tmp->pNext != nullptr)
        {
            tmp = tmp->pNext;
        }
        tmp->pNext = p;
    }
}

void ReadDate(const string &ns, Date &date)
{
    stringstream ss(ns);
    getline(ss, date.day, '/');
    getline(ss, date.month, '/');
    ss >> date.year;
}

void ReadDanhSachSinhVien(Node *&head, ifstream &filein)
{
    string line;
    while (getline(filein, line))
    {
        stringstream ss(line);
        SinhVien sv;
        getline(ss, sv.hoten, ',');

        getline(ss, sv.mssv, ',');
        string ns;
        getline(ss, ns, ',');
        ReadDate(ns, sv.ngaysinh);
        filein.seekg(1, ios::cur);
        // ss.ignore();
        ss >> sv.dtb;
        Insert(head, sv);
    }
}

void Xuat(const SinhVien &sv)
{
    cout << "\nHo ten: " << sv.hoten;
    cout << "\nMa so sinh vien: " << sv.mssv;
    cout << "\nNgay sinh: " << sv.ngaysinh.day << "/" << sv.ngaysinh.month << "/" << sv.ngaysinh.year;
    cout << "\nDiem trung binh: " << fixed << setprecision(1) << setiosflags(ios::showpoint) << sv.dtb;
    cout << endl;
}

void XuatDanhSachSinhVien(const Node *head)
{
    const Node *current = head;
    int dem = 1;
    while (current != nullptr)
    {
        cout << "Sinh vien thu " << dem++ << endl;
        Xuat(current->data);
        current = current->pNext;
    }
}

int Size(const Node *head)
{
    int cnt = 0;
    for (const Node *p = head; p != nullptr; p = p->pNext)
    {
        cnt++;
    }
    return cnt;
}

int main()
{
    Node *head = nullptr;

    // Mở fileg+
    ifstream filein("SINHVIEN.txt");
    if (!filein.is_open())
    {
        cout << "Khong the mo file.\n";
        return 1;
    }

    ReadDanhSachSinhVien(head, filein);

    cout << "So luong sinh vien: " << Size(head) << endl;
    XuatDanhSachSinhVien(head);

    // Đóng file
    filein.close();

    system("pause");
    return 0;
}
