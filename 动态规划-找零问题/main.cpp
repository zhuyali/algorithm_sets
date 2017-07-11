#include <iostream>
#include <string>
#include <fstream.h>

#define MAX 100000

int change(int j, int t[], int n);

void main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n = 0;
	int j = 0;
	int *t=new int[3];

	fin>>n;
	for(int i = 0; i < n; i++) 
		fin>>t[i];
	fin>>j;
	int result = 0;

	result = change(j, t, n);
	fout<<result;
}

//j������������t[n]�������Ӳ�ҵ���ֵ��n�����м�����ֵ
int change(int j, int t[], int n) {
	
	//�����洢����<=j����Ǯ��
	int *result = new int[j];

	//��ʼ��result����
	for(int k = 0; k < j; k++) {
		result[k] = MAX;
	}

	//������ֵΪ�±��result��ʼ��Ϊ1
	for(int i = 0; i < n; i++) {
		result[t[i] - 1] = 1;
	}

	for(int x = 0; x < j; x++) {

		if(result[x] != MAX)
			continue;

		for(int m = 0; m <= (int)(x/2); m++) {
			int ano = x - m -1;
			if(ano < 0)
				break;
			int temp = result[m] + result[ano];
			if(temp < result[x])
				result[x] = temp;
		}
	}

	return result[j - 1];
}