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
	cout<<endl<<"���Ž�Ϊ��"<<result<<endl;
}

//j������������t[n]�������Ӳ�ҵ���ֵ��n�����м�����ֵ
int change(int j, int t[], int n) {

	cout<<"����change";

	int num = 0;
	int **c, **temp;
	c = new int*[j];
	temp = new int*[j];
	for(int s = 0; s < j; s++) {
		c[s]=new int[n];
		temp[s]=new int[n];
	}
	bool *flag = new bool[j];
	//���ȳ�ʼ������������ʱ����
	for(int f = 0; f < j; f++) {
		for(int k = 0; k < n; k++) {
			//cout<<"�����ʼ������";
			c[f][k] = 0;
			temp[f][k] = 0;
			flag[k] = false;
		}
	}
	//i�����У�m������
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
			//��֮ǰ��������ӣ��ó�����
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


