/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file two-sum.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/03/25 22:53:55
 * @brief 
 *  
 **/
#include <vector>
#include <map>

// 所有答案必须自己做，要不就别做了，看别人的完全浪费时间
// 做完了之后看看别人的思路，有没有更优的算法
// 所有答案记在这里，后面放到github上面去；
// map内部使用红黑树实现，map.find的时间复杂度是O(logN)

using namespace std;

struct Data {
    int indice;
    int value;
    Data () {
    
    }
    Data(int i, int v) {
        indice = i;
        value = v;
    }
};

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, Data> mymap;
            //map<int, Data>::iterator iter;
            vector<int> res;
            for (int i = 0; i < nums.size(); i++) {
                mymap.insert(pair<int, Data>(nums[i], Data(i, target-nums[i])));
            }
            for (int i = 0; i < nums.size(); i++) {
                //iter = mymap.find(target-nums[i]);
                //if (iter != mymap.end()) {
                if (mymap.count(target-nums[i])) {
                    int j = mymap[target-nums[i]].indice;
                    if (i != j) {
                        res.push_back(i);
                        res.push_back(j);
                        return res;
                    }
                }
            }
        }
};

int main() {
    return 0;
}


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
