#ifndef LOADING_H
#define LOADING_H

class Loading {

public:
	int n;//集装箱数量
	int *x;//当前解
	int *bestx;//最优解
	int *w;//集装箱重量数组
	int c;//第一艘船载重量
	int cw;//当前载重量
	int bestw;//当前最优载重量
	int r;//剩余集装箱重量

	Loading(int n, int *w, int c);
	void Backtrack(int i);
};

#endif