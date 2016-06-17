/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file course-schedule.cpp
 * @author wangzhengkang(com@baidu.com)
 * @date 2016/03/30 20:17:13
 * @brief 
 *  
 **/
#include <vector>
#include <queue>

using namespace std;

// 比较少见的图的题
// 其实就是判断有向图中有没有环
// 思路：首先把所有入度为0的点加入队列，然后不断pop，
// 将该节点所指向的点的入度减1，如果此时该点入度为0，则加入队列，直至队列为空，如果此时还有入度不为0的点，那么就是有环；

class Solution {
    public:
        bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
            int in[numCourses];
            memset(in, 0, numCourses*sizeof(int));
            int graph[numCourses][numCourses];
            queue<int> myqueue;
            memset(graph, 0, numCourses*numCourses*sizeof(int));
            for (int i = 0; i < prerequisites.size(); i++) {
                pair<int, int> temp = prerequisites[i];
                in[temp.first]++;
                graph[temp.first][temp.second] = 1;
            }
            for (int i = 0; i < numCourses; i++) {
                if (!in[i]) {
                    myqueue.push(i);
                }
            }
            while (!myqueue.empty()) {
                int point = myqueue.front();
                myqueue.pop();
                for (int i = 0; i < numCourses; i++) {
                    if (graph[i][point] != 0) {
                        in[i]--;
                        if (!in[i]) {
                            myqueue.push(i);
                        }
                    }
                } 
            }
            for (int i = 0; i < numCourses; i++) {
                if (in[i]) {
                    return false;
                }
            }
            return true;

        }

};




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
