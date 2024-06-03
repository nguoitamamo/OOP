#include <stdio.h>

// Hàm tính trung bình cộng của mảng
float Mean(int A[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    return (float)sum / n;
}

// Hàm sắp xếp mảng theo thứ tự tăng dần
void Sort(int A[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}
int count(int x, int y) {
    int s = 1;
    for (int i = 1; i <= y; i++) {
        s = s * x + y;
    }
    return s;
}

int main() 
{
    /*    for (int i = 0; i <= 4; i++) {
            for (int j = 0; j < i; j++) {
                printf("M");
            }
            printf("\n");
        }*/
        //int i = 0, j = 0;
        //while (i < 3 && j < 4) {
        //    i++;
        //    j++;
        //}
//        //printf("%d, % d\n", i, j);
//{
//    int a[3][3] = { { 1, 2}, { 3},{3, 1} };
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//
//            printf("%d\t", a[i][j]);
//            if (j == 2) printf("\n");
//        }
//    }
        //int a[5] = { 9 , 1, 2,8, 1 };
        //int j = 0;
        //for (int i = 0; i < 4; i++) {
        //    j = i + 1;
        //    a[i] = a[j];
        //}
        //printf("%d, %d\n", a[1], a[3]);
    int n = 4;
    for (n = 8; n > 2; n -= 2) {
        printf("%d", n--);
    }
    return 0;
}
