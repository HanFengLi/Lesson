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

// 摩尔投票,假设大于等于n/2的数存在
bool mall_vote(int a[], int n) {
    int tmp = 0, count = 0;
    for (int i = 0;i < n; i++)
    {
        if (count == 0) {
            tmp = a[i];
            count++;
        } else if (tmp == a[i]) {
            count++;
        } else {
            count--;
        }
    }
    // 检查摩尔投票后剩下的那个数的数量是否大于n/2
    count = 0;
    for (int i = 0;i < n;i++)
    {
        if (tmp == a[i]) count++;
    }
    if (count > n/2) return true;
    return false;
}

typedef struct _NODE
{
    int val;
    _NODE *next;
    _NODE(int v)
    {
        val = v;
        next = NULL;
    }
}NODE;

/*
 无头节点|单向|非循环链表
 */
// 遍历链表
void trvl(NODE *h)
{
    for (NODE *i = h; i != NULL; i = i->next)
        cout<<i->val<<",";
    cout<<endl;
}

// 查找链表中的元素
bool search(NODE *h, int v)
{
    for(NODE *i = h; i != NULL; i = i->next)
        if (i->val == v)
            return true;
    return false;
}

// 在头部插入元素
NODE * insert_head(NODE *h, int v)
{
    NODE *n = new NODE(v);
    n->next = h;
    return n;
}

// 在尾部插入节点
NODE * insert_tail(NODE *h, int v)
{
    NODE *n = new NODE(v);
    if (h == NULL)
        return n;
    NODE *i = h;
    while(i->next)
        i = i->next;
    i->next = n;
    return h;
}

// 删除节点
NODE * del(NODE *h, int v)
{
    NODE *d = new NODE(0);
    d->next = h;
    NODE *i = d;
    while(i->next)
    {
        if (i->next->val == v) {
            NODE *n = i->next;
            i->next = n->next;
            delete n;
        }
        else {
            i = i->next;
        }
    }
    i = d->next;
    delete d;
    return i;
}

// 合并两个有序链表，使之继续有序
NODE * merge(NODE *h1, NODE *h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;
    
    NODE *d = new NODE(0);
    NODE *i = d;
    while (h1 && h2)
    {
        if (h1->val > h2->val)
        {
            i->next = h1;
            h1 = h1->next;
        } else {
            i ->next = h2;
            h2 = h2->next;
        }
        i = i->next;
    }
    if (h1) i->next = h1;
    if (h2) i->next = h2;
    i = d->next;
    delete d;
    return i;
}

// 有序插入链表
NODE * insert_sorted(NODE *h, int v) {
    NODE *n = new NODE(v);
    NODE *d = new NODE(0);
    d->next = h;
    NODE *i = d;
    while (i->next && i->next->val < v) {
        i = i->next;
    }
    n->next = i->next;
    i->next = n;
    i = d->next;
    delete d;
    return i;
}

// 翻转链表
NODE * reverse(NODE *h) {
    if (h == NULL || h->next == NULL) {
        return h;
    }
    NODE *d = new NODE(0);
    d->next = h;
    NODE *i = d, *j = d->next, *k;
    while (j) {
        k = j->next;
        j->next = i;
        i = j;
        j = k;
    }
    d->next->next = NULL;
    delete d;
    return i;
}

// 删除有序链表重复元素，保留一个
NODE * del_repeat_remain_one(NODE *h) {
    if (h == NULL) {
        return h;
    }
    NODE *i = h, *j = i->next;
    while(j)
    {
        if (i->val == j->val) {
            j = j->next;
        } else {
            i->next = j;
            i = j;
            j = j->next;
        }
    }
    i->next = j;
    return h;
}

// 完全删除链表的重复元素
NODE * del_repeat(NODE *h) {
    NODE *d = new NODE(0);
    d->next = h;
    NODE *i = d;
    while(i->next && i->next->next)
    {
        if (i->next->val != i->next->next->val) {
            i = i->next;
        } else {
            NODE *j = i->next->next;
            while(j && j->val == i->next->val)
                j = j->next;
            i->next = j;
        }
    }
    return d->next;
}

/*
 带头节点|双向|循环链表
 */
// 生成节点
typedef struct _NODE_H
{
    int val;
    _NODE_H *next, *prev;
}NODE_H;

NODE_H * make_node(int v) {
    NODE_H *n = new NODE_H();
    n->val = v;
    n->next = n->prev = n;
    return n;
}

// 遍历链表
void trvl_h(NODE_H *h)
{
    if (h == NULL) {
        return;
    }
    for (NODE_H *i = h->next;i != h;i = i->next)
        cout<<i->val<<",";
    cout<<endl;
}

// 查找元素
bool search_h(NODE_H *h, int v)
{
    if (h == NULL) return false;
    NODE_H *i = h->next;
    while (i != h)
    {
        if (i->val == v) return true;
        i = i->next;
    }
    return false;
}

// 头插入
NODE_H * insert_head_h(NODE_H *h, int v)
{
    NODE_H *n = make_node(v);
    if (h == NULL) h = make_node(0);
    n->next = h->next;
    n->prev = h;
    h->next->prev = n;
    h->next = n;
    return h;
}

// 尾插入
NODE_H * insert_tail_h(NODE_H *h, int v)
{
    NODE_H *n = make_node(v);
    if (h == NULL) make_node(0);
    n->next = h;
    n->prev = h->prev;
    h->prev->next = n;
    h->prev = n;
    return h;
}

// 删除元素
NODE_H * del_h(NODE_H *h, int v) {
    if (h == NULL) return h;
    for (NODE_H *i = h->next;i != h; i = i->next)
    {
        if (i->val == v)
        {
            i->next->prev = i->prev;
            i->prev->next = i->next;
            delete i;
            break;
        }
    }
    return h;
}
// k窗口最大和
// TODO

int main(int argc, const char * argv[]) {


    NODE *h = new NODE(1);
    NODE *n1 = new NODE(1);
    NODE *n2 = new NODE(2);
    NODE *n3 = new NODE(2);
    NODE *n4 = new NODE(4);
    NODE *n5 = new NODE(4);
    h->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    h = del_repeat_remain_one(h);
    trvl(h);
    return 0;
}
