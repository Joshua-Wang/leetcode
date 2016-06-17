/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file MaximumProductofWordLengths.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/05/02 15:41:12
 * @brief 
 *  
 **/

#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

bool comp(const string& s1, const string& s2) {
    return s1.size() > s2.size();
}

class Solution {
    public:

        // ��Ȼ����set�����Ǹ��ӶȻ��� O(nlogn)
        bool noConfict(const string& s1, const string& s2){
            set<char> myset;
            for (int i = 0; i < s1.size(); i++) {
                myset.insert(s1[i]);
            }

            for (int i = 0; i < s2.size(); i++) {
                if (myset.count(s2[i]) != 0) {
                    return false;
                }
            }
            return true;

        }

        // ��λ����, ��Ŀ���ر�ǿ���˶���Сд��ĸ��
        int toInt(const string& ss) {
            int a = 0;
            for (int i = 0; i < ss.size(); i++) {
                int offset = ss[i] - 'a';
                a |= 1 << offset; 
            }
            return a;
        }

        int maxProduct(vector<string>& words) {
            int len = words.size();
            int res = 0;
            //sort(words.begin(), words.end(), comp); �����������������˼·�Ǵ�ģ�
            int value[len];
            for (int i = 0; i < words.size(); i++) { // �ⲿ�ֲ���Ҫ��ǰ��������ŵ���������൱����O(n3);
                value[i] = toInt(words[i]);
            }
            for (int i = 0; i < len; i++) {
                for (int j = i+1; j < len; j++) {
                    if (!(value[i] & value[j])) {
                        res = max(res, (int)(words[i].size() * words[j].size()));
                    }
                }
            }
            return res;
        }
};

int main() {
    Solution s;
    string str[] = {"a","ab","abc","d","cd","bcd","abcd"};
    vector<string> v1(str, str+7);
    cout << s.maxProduct(v1) << endl;
}

















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
