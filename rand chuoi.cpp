#include"graphics.h"


int main() {
	initwindow(640, 480); // khởi tạo cửa sổ đồ họa có kích thước 640x480
	line(0, 0, 100, 100); // vẽ đoạn thẳng từ (0, 0) đến (100, 100)
	getch(); // chờ người dùng nhấn phím để kết thúc chương trình
	closegraph(); // đóng cửa sổ đồ họa
	return 0;
}
