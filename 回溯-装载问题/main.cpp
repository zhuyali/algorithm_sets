#include "Loading.h"
#include <fstream.h>

void main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int c = 0; 
	int n = 0;
	fin>>n>>c;

	int *w = new int[n+1];
	//int w[4] = {0}; 
	for(int i = 1; i <= n; i++) 
		fin>>w[i];

	Loading *load = new Loading(n, w, c);
	load->Backtrack(1);

	for(int j = 1; j <= n; j++)
		fout<<(load->bestx)[j]<<" ";
}