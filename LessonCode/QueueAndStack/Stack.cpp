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
// 数组实现栈
// */
//typedef struct _STACK
//{
//    int buf[SIZE];
//    int sp;
//    _STACK(){ sp = 0; }
//}STACK;
//
//bool empty(STACK *s)
//{
//    return s->sp == 0;
//}
//
//void push(STACK *s, int val)
//{
//    if (sp == SIZE) return;
//    s->buf[s->sp++] = val;
//}
//
//int pop(STACK *s)
//{
//    if (empty(s)) return -1;
//    return s->buf[--s->sp];
//}
//
///*
// 链表实现栈
// */
//typedef struct _STACK
//{
//    NODE *sp;
//    _STACK() { sp = NULL; }
//}STACK;
//
//bool empty(STACK *s)
//{
//    return s->sp == NULL;
//}
//
//void push(STACK *s, int val)
//{
//    NODE *n = new NODE(val);
//    n->next = s->sp;
//    s->sp = n;
//}
//
//int pop(STACK *s)
//{
//    if (empty(s)) return -1;
//    NODE *tmp = s->sp;
//    int ret = tmp->val;
//    s->sp = s->sp->next;
//    delete tmp
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
///*
// 栈判断符号平衡
// */
//bool balance_symbol(const char *str)
//{
//    stack<char> s;
//    for (int i = 0;i < strlen(str);i++)
//    {
//        int c = str[i];
//        switch (c) {
//            case '(':
//            case '[':
//            case '{':
//                s.push(c);
//                break;
//            case ')':
//                if (!s.empty() && s.top() == '(') s.pop();
//                else return false;
//                break;
//            case ']':
//                if (!s.empty() && s.top() == '[') s.pop();
//                else return false;
//                break;
//            case '}':
//                if (!s.empty() && s.top() == '{') s.pop();
//                else return false;
//                break;
//            default:
//                break;
//        }
//    }
//    return s.empty();
//}
//
///*
// 栈计算后缀表达式
// */
//bool is_num(char c)
//{
//    return c >= '0' && c <= '9';
//}
//
//int lv(char c)
//{
//    if (c == '(' || c == ')') return 0;
//    if (c == '+' || c == '-') return 1;
//    if (c == '*' || c == '/') return 2;
//    return -1;
//}
//
//void calc(stack<int> *val, char c)
//{
//    int n2 = val.top(); val.pop();
//    int n1 = val.top(); val.pop();
//    switch (c) {
//        case '+':
//            val.push(n1+n2);
//            break;
//        case '-':
//            val.push(n1-n2);
//            break;
//        case '*':
//            val.push(n1*n2);
//            break;
//        case '/':
//            val.push(n1/n2);
//            break;
//        default:
//            break;
//    }
//}
//
//void calc_postfix(const char *str)
//{
//    cout<<str<<" = ";
//    stack<int> val;
//    for (int i = 0;i < strlen(str);i++)
//    {
//        if (is_num(str[i])) val.push(str[i] - '0');
//        else calc(&val, str[i]);
//    }
//    cout<<val.top()<<endl;
//}
//
//int main(int argc, const char * argv[]) {
//
//    return 0;
//}
