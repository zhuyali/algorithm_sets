#ifndef LOADING_H
#define LOADING_H

class Loading {

public:
	int n;//��װ������
	int *x;//��ǰ��
	int *bestx;//���Ž�
	int *w;//��װ����������
	int c;//��һ�Ҵ�������
	int cw;//��ǰ������
	int bestw;//��ǰ����������
	int r;//ʣ�༯װ������

	Loading(int n, int *w, int c);
	void Backtrack(int i);
};

#endif