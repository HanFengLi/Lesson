////
////  main.cpp
////  Array&List
////
////  Created by lihanfeng on 2019/11/13.
////  Copyright © 2019 lihanfeng. All rights reserved.
////
//
//#include<iostream>
//using namespace std;
//
//// 将两个有序数组p排列为一个有序数组
//void merge(int a[], int m, int b[], int n, int c[], int s) {
//    if (s < (m + n)) {
//        return ;
//    }
//    int i = 0, j = 0, k = 0;
//    while (i < m && j < n) {
//        if (a[i] < b[j]) {
//            c[k++] = a[i++];
//        } else {
//            c[k++] = b[j++];
//        }
//    }
//    while (i < m) {
//        c[k++] = a[i++];
//    }
//    while (j < n) {
//        c[k++] = b[j++];
//    }
//}
//
//// 数组元素翻转
//void reverse(int a[], int m) {
//    int s = 0, e = m - 1;
//    while (s < e) {
//        swap(a[s], a[e]);
//        s++;
//        e--;
//    }
//}
//
//// 摩尔投票,假设大于等于n/2的数存在
//bool mall_vote(int a[], int n) {
//    int tmp = 0, count = 0;
//    for (int i = 0;i < n; i++)
//    {
//        if (count == 0) {
//            tmp = a[i];
//            count++;
//        } else if (tmp == a[i]) {
//            count++;
//        } else {
//            count--;
//        }
//    }
//    // 检查摩尔投票后剩下的那个数的数量是否大于n/2
//    count = 0;
//    for (int i = 0;i < n;i++)
//    {
//        if (tmp == a[i]) count++;
//    }
//    if (count > n/2) return true;
//    return false;
//}
//
//
//// k窗口最大和
//// TODO
//
//int main(int argc, const char * argv[]) {
//
//    return 0;
//}
