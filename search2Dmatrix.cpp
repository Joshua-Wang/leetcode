
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    // TLE
    bool searchMatrix2(vector<vector<int> >& matrix, int target) {
    	int r = matrix.size();	
    	if (r == 0) {
    		return false;
    	}
    	int c = matrix[0].size();
    	int row_l = 0, row_r = r-1;
    	int col_l = 0, col_r = c-1;
    	for (int i = 0; i < r; i++) {
    		if (target > matrix[i][c-1]) {
    			row_l++;	
    		}	
			if (target < matrix[i][0]) {
    			row_r--;	
    		}	
    	}
    	for (int i = 0; i < c; i++) {
    		if (target > matrix[r-1][i]) {
    			col_l++;	
    		}	
			if (target < matrix[r-1][0]) {
    			col_r--;	
    		}
    	}
    	for (int i = row_l; i <= row_r; i++) {
    		for (int j = col_l; j <= col_r; j++) {
    			if (matrix[i][j] == target) {
    				return true;
    			}
    		}
    	}
    	return false; 
   }

	// 经典的算法题；
	// 很有启发的一道题，开始以为做过的题很简单，其实想了根据算法也没想出来；
	// 不能眼高手低；
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return false;
		}	
		int r = matrix.size();
		int c = matrix[0].size();
		int i = 0, j = c - 1;
		while (j >= 0 && i < r) {
			if (target == matrix[i][j]) {
				return true;
			}
			if (target > matrix[i][j]) {
				i++;	
			} else {
				j--;
			}
		}
		return false;
	}
};

int main()
{
	
}
