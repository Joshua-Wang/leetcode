/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/

/**
 * @file implemete-stack-using-queue.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/05/06 22:04:02
 * @brief 
 *  
 **/

#include <queue>
#include <stack>

using namespace std;

// 挺无聊的题，不过能用一个队列的实现应该是最高效的；
// push O(1), pop O(n) , top O(n)
// 题目简单但是陷阱很多，做完了要自己多想测试用例；
class Stack {
    private:
        queue<int> myqueue;
    public:
        void push(int x) {
            myqueue.push(x);
        }

        void pop() {
            int len = myqueue.size();
            for (int i = 1; i < len; i++) {
                int num = myqueue.front();
                myqueue.pop();
                myqueue.push(num);
            }
            myqueue.pop();
        }

        int top() {
            int len = myqueue.size();
            for (int i = 1; i < len; i++) {
                int num = myqueue.front();
                myqueue.pop();
                myqueue.push(num);
            }
            int res = myqueue.front();
            myqueue.pop();
            myqueue.push(res);
            return res;
        }

        bool empty() {
            return myqueue.empty();
        }
};

class Queue {
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        void push(int x) {
            while (!s2.empty()) {
                int num = s2.top();
                s2.pop();
                s1.push(num);
            }
            s1.push(x);
        }

        void pop(void) {
            while (!s1.empty()) {
                int num = s1.top();
                s1.pop();
                s2.push(num);
            }
            return s2.pop();
        }

        int peek(void) {
            while (!s1.empty()) {
                int num = s1.top();
                s1.pop();
                s2.push(num);
            }
            return s2.top();
        }

        bool empty(void) {
            return s1.empty() && s2.empty();
        }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
