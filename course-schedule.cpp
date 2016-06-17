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

// �Ƚ��ټ���ͼ����
// ��ʵ�����ж�����ͼ����û�л�
// ˼·�����Ȱ��������Ϊ0�ĵ������У�Ȼ�󲻶�pop��
// ���ýڵ���ָ��ĵ����ȼ�1�������ʱ�õ����Ϊ0���������У�ֱ������Ϊ�գ������ʱ������Ȳ�Ϊ0�ĵ㣬��ô�����л���

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
