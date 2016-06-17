/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file InsertInterval.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/05/08 22:23:04
 * @brief 
 *  
 **/

#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };

// 很麻烦，要考虑所有的情况
class Solution {
    public:
        vector<Interval> insert2(vector<Interval>& intervals, Interval newInterval) {
            vector<Interval> res;
            if (intervals.size() == 0) {
                res.push_back(newInterval);
                return res;
            }
            int newBegin, newEnd;
            bool findBegin = false, findEnd = false, pushNewInterval = false;
            for (int i = 0; i < intervals.size(); i++) {
                Interval item = intervals[i];
                if (!findBegin) {
                    if (item.end < newInterval.start) {
                        res.push_back(item);
                        continue;
                    }
                    if (item.start >= newInterval.start) {
                        newBegin = newInterval.start;
                    } else {
                        newBegin = item.start;
                    }
                    findBegin = true;
                    i--;
                }
                if (!findEnd) {
                    if (item.end < newInterval.end) {
                        continue;
                    }
                    if (newInterval.end < item.start) {
                        newEnd = newInterval.end;
                    } else {
                        newEnd = item.end;
                    }
                    findEnd = true;
                }                
                if (findBegin && findEnd && !pushNewInterval ) {
                    Interval new_interval(newBegin, newEnd);
                    res.push_back(new_interval);
                    pushNewInterval = true; 
                    continue;
                }
                if (findBegin && findEnd && pushNewInterval ) {
                    res.push_back(item);
                }
            }
            return res;
        }
       
        // 从网上抄过来的版本；
        // think througth 
        // 该算法太巧妙了，不然要处理很多种情况；这样其实就归纳成三种情况
        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {  
            vector<Interval> res;
            int len = intervals.size();
            for (int i = 0; i < len; i++) {
                Interval item = intervals[i];
                if (item.end < newInterval.start) {
                    res.push_back(item);
                    continue;
                }
                if (newInterval.end < item.start) {
                    res.push_back(newInterval);
                    res.insert(res.end(), intervals.begin()+i, intervals.end());
                    return res;
                }
                newInterval.start = min(newInterval.start, item.start);
                newInterval.end = max(newInterval.end, item.end);
            }
            res.push_back(newInterval);
            return res;
        }
};

int main() {
    Solution s;
    Interval i1(1,5);
    Interval i2(2,3);
    vector<Interval> intervals;
    intervals.push_back(i1);
    vector<Interval> res = s.insert(intervals, i2);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].start << "\t" << res[i].end << endl;
    }
    
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
