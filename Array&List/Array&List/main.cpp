//
//  main.cpp
//  Array&List
//
//  Created by lihanfeng on 2019/11/13.
//  Copyright © 2019 lihanfeng. All rights reserved.
//

#include<iostream>
using namespace std;

// 将两个有序数组p排列为一个有序数组
void merge(int a[], int m, int b[], int n, int c[], int s) {
    if (s < (m + n)) {
        return ;
    }
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < m) {
        c[k++] = a[i++];
    }
    while (j < n) {
        c[k++] = b[j++];
    }
}

// 数组元素翻转
void reverse(int a[], int m) {
    int s = 0, e = m - 1;
    while (s < e) {
        swap(a[s], a[e]);
        s++;
        e--;
    }
}

int main(int argc, const char * argv[]) {

    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6, 8};
    int *c = new int[7];
    merge(a, 3, b, 4, c, 7);
    reverse(c, 7);
    for (int i = 0; i < 7; i++) {
        std::cout << c[i] << endl;
    }
    return 0;
}
