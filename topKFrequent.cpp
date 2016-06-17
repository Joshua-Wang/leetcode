/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file topKFrequent.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/05/02 14:30:55
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef pair<int, int> P; // 活用typedef

struct Order {
    bool operator()(P p1, P p2) {
        return p1.second < p2.second;
    }
};

class Solution {
    public:

        vector<int> topKFrequent(vector<int>& nums, int k) {
            map<int, int> frequents;
            for (int i = 0; i < nums.size(); i++) {
                if (frequents.count(nums[i]) == 0) {
                    frequents[nums[i]] = 1;
                } else {
                    frequents[nums[i]]++; // map的value可以直接修改；
                }
            }
            priority_queue<P, vector<P>, Order> myqueue; // 要用Order类来初始化；
            map<int, int>::iterator iter;
            for (iter = frequents.begin(); iter != frequents.end(); iter++) {
                myqueue.push(*iter);    
            }
            vector<int> res;
            for (int i = 0; i < k; i++) {
                pair<int, int> top = myqueue.top();
                res.push_back(top.first);
                myqueue.pop();
            }
            return res; 
        }
};

int main() {
    int a[] = {1,1,1,2,2,3};
    vector<int> v1(a, a+6); //vector 可以用数组初始化；
    Solution s;
    vector<int> res = s.topKFrequent(v1, 2);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}

















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
