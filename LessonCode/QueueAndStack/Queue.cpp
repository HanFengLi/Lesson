////
////  main.cpp
////  Array&List
////
////  Created by 李晗峰 on 2019/12/29.
////  Copyright © 2019 lihanfeng. All rights reserved.
////
//
//#include<iostream>
//using namespace std;
//#define SIZE 100
//
///*
// 数组实现队列
// */
//typedef struct _QUEUE
//{
//    int buf[SIZE];
//    int first, last;
//    _QUEUE() {
//        first = last = 0;
//    }
//}QUEUE;
//
//bool empty(QUEUE *q) {
//    return q->first == q->last;
//}
//
//void push(QUEUE *q, int val)
//{
//    if ((q->last + 1) % SIZE == q->first) return;
//    q->buf[q->last++] = val;
//    q->last %= SIZE;
//}
//
//int pop(QUEUE *q)
//{
//    if (q->last == q->first) return -1;
//    int ret = q->buf[q->first++];
//    q->first %= SIZE;
//    return ret;
//}
//
///*
// 链表实现队列
// */
//typedef struct _NODE
//{
//    int val;
//    _NODE *next;
//    _NODE(int val) {
//        val = _val;
//        next = NULL;
//    }
//}NODE;
//
//typedef struct _QUEUE
//{
//    NODE *first;
//    NODE *last;
//    _QUEUE() {
//        first = last = NULL;
//    }
//}QUEUE;
//
//bool empty(QUEUE *q)
//{
//    return q->first = NULL;
//}
//
//void push(QUEUE *q, int val)
//{
//    NODE  *n = new NODE(val);
//    if (q->fisrt == NULL)
//    {
//        q->first = n;
//        q->last = n;
//    } else {
//        q->last->next = n;
//        q->last = n;
//    }
//}
//
//int pop(QUEUE *q)
//{
//    if (empty(q))
//        return -1;
//    NODE *tmp = q->first;
//    int ret = tmp->val;
//    q->first = q->first->next;
//    if (q->first == NULL) q->last == NULL;
//    delete tmp;
//    return ret;
//}
//
///*
// 用两个stack模拟一个queue
// */
//typedef struct
//{
//    stack<int> s1;
//    stack<int> s2;
//}QUEUE;
//
//bool empty(QUEUE *q)
//{
//    return q->s1.empty() && q->s2.empty();
//}
//
//void push(QUEUE *q, int val)
//{
//    cout<<"s1.push :"<<x<<endl;
//    q->s1.push(x);
//}
//
//int pop(QUEUE *q)
//{
//    int res = 0;
//    if (!q->s2.empty())
//    {
//        cout<<"s2.pop, ";
//        res = q->s2.top();
//        q->s2.pop();
//    } else {
//        while (!q->s1.empty())
//        {
//            q->s2.push(q->s1.top());
//            q->s1.pop();
//        }
//        cout<<"s1 move to s2,";
//        res = q->s2.top();
//        q->s2.pop();
//    }
//    cout<<"pop :"<<res<<endl;
//    return res;
//}
//
//int main(int argc, const char * argv[]) {
//
//    return 0;
//}
