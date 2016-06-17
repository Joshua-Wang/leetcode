#include <vector>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;

// ���õݹ��˼·��������⣬�ܶ���ѽ������ݹ�ͺ����׽⣻
class Solution {
	public:
		vector<int> diffWaysToCompute(string input) {
			int len = input.size();
			vector<int> res;
			bool flag = true;
			for (int i = 0; i < len; i++) {
				if (input[i] == '*' || input[i] == '+' || input[i] == '-') {
					flag = false;
					vector<int> left = diffWaysToCompute(input.substr(0, i));
					vector<int> right = diffWaysToCompute(input.substr(i+1, len-i));
					for (int j = 0; j < left.size(); j++) {
						for (int k = 0; k < right.size(); k++) {
							switch (input[i]) {
								case '+':
									res.push_back(left[j] + right[k]);
									break;
								case '-':
									res.push_back(left[j] - right[k]);
									break;
								case '*':
									res.push_back(left[j] * right[k]);
									break;
							}
						}
					}
				}
			}
			if (!flag) { // �������ӣ���Ϊ����ǲ��ܼ�����ֲ��������֧��
				return res;
			} else {
				res.push_back(atoi(input.c_str()));
				return res;
			}
		}
};
