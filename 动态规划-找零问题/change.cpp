#include <iostream>
#include <string>
 
using namespace std;

int change(int j, int t[], int n);

void main() {

	int n = 3;
	int t[3] = {1, 2, 5};
	int j = 9;
	int result = 0;
	result = change(j, t, n);
	cout<<endl<<"最优解为："<<result<<endl;
}

//j代表找零数，t[n]用来存放硬币的面值，n代表有几种面值
int change(int j, int t[], int n) {

	cout<<"进入change";

	int num = 0;
	int **c, **temp;
	c = new int*[j];
	temp = new int*[j];
	for(int s = 0; s < j; s++) {
		c[s]=new int[n];
		temp[s]=new int[n];
	}
	bool *flag = new bool[j];
	//首先初始化结果数组和临时数组
	for(int f = 0; f < j; f++) {
		for(int k = 0; k < n; k++) {
			//cout<<"进入初始化数组";
			c[f][k] = 0;
			temp[f][k] = 0;
			flag[k] = false;
		}
	}
	//i代表行，m代表列
	for(int i = 0; i < j; i++) {
		int value = i + 1;
		for(int m = 0; m < n; m++) {
			if(t[m] == value) {
				c[i][m] = 1;
				flag[i] = true;
				break;
			}
		}
		if(flag[i] == true) 
			continue;
		else {
			//让之前的两行相加，得出最优
			for(int row = 0; row < (int)(i/2); row++) {
				int numTemp = 0;
				for(int col = 0; col < n; col++) {
					int anoRow = i - row -1;
					cout<<"anoRow:"<<anoRow;
					temp[i][col] = c[row][col] + c[anoRow][col];
					if(row == 0) {
						num += temp[i][col];
						c[i][col] = temp[i][col];
					}
					numTemp += temp[i][col];
				}
				if(numTemp < num) {
					num = numTemp;
					for(int x = 0; x < n; x++) {
						c[i][x] = temp[i][x];
					}
				}
			}
			flag[i] = true;
		}
	}
	return num;
}


