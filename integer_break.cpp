/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file integer_break.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/05/01 09:39:05
 * @brief 
 *  
 **/

#include <math.h>
#include <iostream>

using namespace std;

class Solution {
    public:
        // ����ֵһ����ÿ��ֵ����ȣ��˻������
        // ͦ���ĵ�һ�⣬����Ҫ���3��� 
        // Ϊʲô��3�� ��Ϊ4 ��2,2 �𲻲��У�5���Բ��3*2, ��5��6���Բ��3*3,
        // ���Ժ����������Ҫ����
        int integerBreak(int n) {
            if (n == 2) { return 1; }
            if (n == 3) { return 2; }
            if (n == 4) { return 4; }
            int res = 1;
            while (n >= 3) {
                res *= 3;
                n -= 3;
            }
            if (n == 0) { return res; }
            if (n == 1) { return res / 3 * 4; }
            if (n == 2) { return res * 2; }
            return 0;
        }
};

int main() {
    Solution s;
    //cout << s.integerBreak(2) << endl;
    cout << s.integerBreak(10) << endl;
    //cout << s.integerBreak(11) << endl;
    //cout << s.integerBreak(9) << endl;
    //cout << s.integerBreak(15) << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
