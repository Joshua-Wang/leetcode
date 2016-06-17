/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
/**
 * @file bitwise-and.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/03/26 19:01:29
 * @brief 
 *  
 **/


// 不要急着写代码，考虑清楚所有情况再写，自己多准备一些用例，看看对不对；
// Time limit excede ...

#include <math.h>

class Solution {
    private :
        const int bitSize = 32;
    public:
        void getBits(int resBits[], int data) {
            int i = 0;
            while (data) {
                resBits[i] = data & 1;
                data = data >> 1;
                i++;
            }
        }

        bool checkNis1(int data, int offset) {
            data = data >> offset;
            return data & 1;
        
        }

        void getDataFromBits(int resBits[], int& res) {
            int tmp = 0;
            for (int i = 0; i < bitSize; i++) {
                if (resBits[i]) {
                    tmp += pow(2, i);
                }
            }
            res = tmp;
            
        }
        int rangeBitwiseAndTimeLimit(int m, int n) {
            int resBits[bitSize] = {0};
            getBits(resBits, m);

            for (int i = 0; i < bitSize; i++) {
                if (resBits[i]) {
                    for (int j = m+1; j <= n; j++) {
                        if (!checkNis1(j, i)) {
                            resBits[i] = 0;
                            break;
                        }
                    }
                }    
            }
            int res = 0;
            getDataFromBits(resBits, res);
            return res;
        }
        int rangeBitwiseAnd(int m, int n) {
            // 看了网上的思路，其实是找m, n 的共同前缀 1，而且1必须在相同位上；
            // 考的就是算法啊，很精妙；
            int offset = 0;
            while (m != n) {
                m >>= 1;
                n >>= 1;
                offset++;
            }
            return m << offset;
        }

};

int main() {
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
