#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>

void printCurrentTime() {
    // Lấy thời gian hiện tại
    auto now = std::chrono::system_clock::now();

    // Chuyển đổi thời gian thành std::time_t để có thể định dạng
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

    // Chuyển đổi std::time_t thành std::tm một cách an toàn
    std::tm now_tm;
    localtime_s(&now_tm, &now_time_t);

    // In thời gian hiện tại
    std::cout << "Current Date and Time: "
        << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << std::endl;
}

void createSpecificTime() {
    // Tạo thời gian cụ thể sử dụng std::chrono
    std::tm timeStruct = {};
    timeStruct.tm_year = 2023 - 1900; // Năm 2023
    timeStruct.tm_mon = 4 - 1;        // Tháng 5 (tính từ 0)
    timeStruct.tm_mday = 31;          // Ngày 31
    timeStruct.tm_hour = 12;          // Giờ 12
    timeStruct.tm_min = 30;           // Phút 30
    timeStruct.tm_sec = 45;           // Giây 45

    std::time_t time = std::mktime(&timeStruct);

    // Chuyển đổi std::time_t thành std::tm một cách an toàn
    std::tm specific_tm;
    localtime_s(&specific_tm, &time);

    // In thời gian cụ thể
    std::cout << "Specific Date and Time: "
        << std::put_time(&specific_tm, "%Y-%m-%d %H:%M:%S") << std::endl;
}

int main() {
    printCurrentTime();
    createSpecificTime();

    return 0;
}
