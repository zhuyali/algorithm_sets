#include <iostream>
#include <string>
#include <fstream.h>

int findMedian(int x[], int y[], int length);

void main() {
	/*int x[3] = {5, 15, 18};
	int y[3] = {3, 14, 21};*/

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int length;
	fin>>length;
	int *x=new int[length];
	int *y=new int[length];

	for(int i = 0; i < length; i++) 
		fin>>x[i];

	for(int j = 0; j < length; j++) 
		fin>>y[j];

	int result = findMedian(x, y, length);
	fout<<result;
}

int findMedian(int x[], int y[], int length) {

	bool isEven = false;

	//终止条件
	if(length == 1) {
		if(x[0] <= y[0]) return x[0];
		else return y[0];
	}

	//中位数的位置
	int mid = (length + 1) / 2;
	int index = mid - 1;
//	cout<<mid;

	if((length % 2) == 0)
		isEven = true;

	if(x[index] == y[index]) {
		return x[index];
	}
	else if(x[index] < y[index]) {
		int *xTemp = new int[mid];
		int *yTemp = new int[mid];

		//当x的中位数小于y的中位数时，选择x中位数
		//之后已经y中位数之前的重复上述过程
		int temp = index;
		for(int i = 0; i < mid; i++) {	
			if(isEven) xTemp[i] = x[++temp];
			else{
				xTemp[i] = x[temp++];
				cout<<xTemp[i]<<endl;
			}
			yTemp[i] = y[i];
		}

		findMedian(xTemp, yTemp, mid);
	}
	else if(y[index] < x[index]) {
		int *xTemp = new int[mid];
		int *yTemp = new int[mid];

		//当y的中位数小于y的中位数时，选择y中位数
		//之后已经x中位数之前的重复上述过程
		int temp = index;
		for(int i = 0; i < mid; i++) {
			if(isEven) yTemp[i] = y[++temp];
			else{
				yTemp[i] = y[temp++];
				cout<<yTemp[i];
			}
			xTemp[i] = x[i];
		}

		findMedian(xTemp, yTemp, mid);
	}
}