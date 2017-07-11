#include "Loading.h"

Loading::Loading(int n, int *w, int c) {
	this->n = n;
	this->w = w;
	this->c = c;
	this->r = 0;
	for(int i = 1; i <= n; i++) {
		this->r += w[i];
	}
	this->bestw = 0;
	this->cw = 0;
	this->x = new int[n+1];
	this->bestx = new int[n+1];
}

void Loading::Backtrack(int i) {
	if(i > n) {
		for(int k = 1; k <= n; k++) {
			bestx[k] = x[k];
			bestw = cw;
		}
		return;
	}

	r -= w[i];
	//ËÑË÷×ó×ÓÊ÷
	if(cw + w[i] <= c) {
		cw += w[i];
		x[i] = 1;
		Backtrack(i+1);
		cw -= w[i];
	}

	//ËÑË÷ÓÒ×ÓÊ÷
	if(cw + r >= bestw) {
		x[i] = 0;
		Backtrack(i+1);
	}
	r += w[i];
}
