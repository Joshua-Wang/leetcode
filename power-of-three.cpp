/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file power-of-three.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/04/19 20:33:06
 * @brief 
 *  
 **/
#include <iostream>
#include <math.h>


// All about the math.
class Solution {
    public:
        bool isPowerOfThree(int n) {
            double res = log10(n) / log10(3);
            return (int)res == res;
        }
};



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
