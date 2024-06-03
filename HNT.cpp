#include <iostream>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <limits>

void getstr(char *str, int n)
{
    while (1)
    {
        std::cin.get(str, n);
        if (str[0])
            break;
        else
        {
            std::cin.ignore();
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // xóa toàn bộ dấu enter có trong bộ nhớ đệm
}

int main()
{

    // std::ostringstream buffer;
    // std::streambuf *oldclogbuffer = std::clog.rdbuf(buffer.rdbuf());

    // std::clog << "HNT\n";

    // std::string logdata = buffer.str();

    // std::clog.rdbuf(oldclogbuffer);

    // std::cout << "du lieu trong buffer : " << logdata << "\n";

    // char buf[100];
    // std::ofstream fs("Output.txt");

    // if (fs.is_open())
    // {
    //     std::ostream prn(fs.rdbuf());
    //     prn << "\n Tong " << (1 + 2);
    //     prn << "\n Hieu " << (1 - 2);
    //     prn.flush();
    //     fs.close();
    //     std::cout << "Data has been written to the fs successfully.\n";
    // }
    // else
    // {
    //     std::cout << "Failed to open the fs.\n";
    // }

    // std::string line;
    // std::ifstream fs("name.txt");

    // while (getline(fs, line))
    // {

    //     std::ostringstream buffer;
    //     std::streambuf *oldclodbuf = std::clog.rdbuf(buffer.rdbuf());

    //     std::clog << line;

    //     std::string data = buffer.str();
    //     std::clog.rdbuf(oldclodbuf);
    //     std::cout << data << "\n";
    // }

    char ht[25];
    memset(ht, '0', sizeof(ht));
    for (int i = 0; i < 25; i++)
    {
        if (ht[i] == '0')
        {
            std::cout << ht[i];
        }
    }
    std::cout << "\n";
    getstr(ht, 25);

    for (int i = 0; i < 25; i++)
    {
        if (ht[i] != '0')
        {
            std::cout << ht[i];
        }
    }
    std::cout << "\n";
    return 0;
}
