#include "Date.h"
#include "Advertisement.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void mergePass(Advertisement input[], Advertisement output[], int s, int n, int key);
void copy(Advertisement input[], Advertisement result[], int left, int right);
void merge(Advertisement input[], Advertisement output[], int l, int m, int r, int key);
void mergeSort(Advertisement input[], int length, int key);

ifstream fin("input.txt");
ofstream fout("output.txt");

void main() {

	/*Date *start1 = new Date(2014, 10, 2);
	Date *end1 = new Date(2015, 10, 2);
	Date *start2 = new Date(2013, 10, 2);
	Date *end2 = new Date(2016, 10, 2);

	Advertisement *a1 = new Advertisement(5, "a", "2", *start1, *end1);
	Advertisement *a2 = new Advertisement(10, "b", "3", *start2, *end2);
	Advertisement *a3 = new Advertisement(4, "a", "2", *start1, *end1);
	Advertisement *a4 = new Advertisement(19, "b", "3", *start2, *end2);

	Advertisement ls[4] = {*a2, *a1, *a3, *a4};

	cout<<ls[0].getAmount();
	cout<<ls[1].getAmount();
	cout<<ls[2].getAmount();
	cout<<ls[3].getAmount();*/

	vector<Advertisement*> ads;
	int amount = 0;
    string name = "";
	string email = "";
	int yearS, monthS, dayS;
	int yearE, monthE, dayE;
    Date *start;
    Date *end;
	string keyS[5]={"Title", "Amount", "Email", "Start", "End"};
	int key = 0;

	while(!fin.eof()) {
		fin>>name;
		//cout<<name;
		if(name=="Title"||name=="Amount"||name=="Start"||name=="End"||name=="Email")
			break;
		fin>>amount>>email>>yearS>>monthS>>dayS>>yearE>>monthE>>dayE;
		//cout<<amount<<email<<yearS<<monthS<<dayS<<yearE<<monthE<<dayE;
		start = new Date(yearS, monthS, dayS);
		end = new Date(yearE, monthE, dayE);
		if(start<end) cout<<"true";
		Advertisement *ad = new Advertisement(amount, name, email, *start, *end);
		ads.push_back(ad);
	}

	for(int j = 0; j < 5; j++) {
		if(strcmp(name.c_str(),keyS[j].c_str())==0) {
			key = j + 1;
			break;
		}
	}
	Advertisement *ls = new Advertisement[ads.size()];

	for(int i = 0; i < ads.size(); i++) 
		ls[i] = *ads.at(i);
	mergeSort(ls, ads.size(), key);
}

void merge(Advertisement input[], Advertisement output[], int l, int m, int r, int key) {
	
	//cout<<endl<<key;
	/*if(m < l || r < l || r < m) {
		return;
	}*/

	int i = l; 
	int j = m+1;
	int k = l;

	while(i <= m && j <= r) {
		cout<<"ont time"<<endl;
		switch(key) {
			case 1:
				if(strcmp(input[i].getName().c_str(),input[j].getName().c_str())<=0) {
					cout<<input[i].getName()<<endl<<input[j].getName();
					cout<<endl<<strcmp(input[i].getName().c_str(),input[j].getName().c_str());
			        output[k++] = input[i++];
				}
				else{
					cout<<"进入else"<<endl;
					cout<<input[i].getName()<<endl<<input[j].getName()<<endl;
	         		output[k++] = input[j++];
				}
				break;
			case 2:
				if(input[i].getAmount() < input[j].getAmount()) 
			        output[k++] = input[i++];
	        	else 
	         		output[k++] = input[j++];
				break;
			case 3:
				if(strcmp(input[i].getEmail().c_str(),input[j].getEmail().c_str())<=0) 
			        output[k++] = input[i++];
	        	else 
	         		output[k++] = input[j++];
				break;
			case 4:
				if(input[i].getStart() < input[j].getStart()) 
			        output[k++] = input[i++];
	        	else 
	         		output[k++] = input[j++];
				break;
			case 5:
				if(input[i].getEnd() < input[j].getEnd()) 
			        output[k++] = input[i++];
	        	else 
	         		output[k++] = input[j++];
				break;
		}
	}

	if(i > m) {
		for(int q = j; q <= r; q++) 
			output[k++] = input[q];
	}
	else {
		for(int p = i; p <= m; p++) 
			output[k++] = input[p];
	}
}

void mergePass(Advertisement input[], Advertisement output[], int s, int length, int key) {

	cout<<"进入mergePass";
	int i = 0;

	while(i <= length-2*s) {
		cout<<i<<" "<<i+s-1<<" "<<i+2*s-1<<endl;
		merge(input, output, i, i+s-1, i+2*s-1, key);
		i += 2*s;
	}

	if(i+s < length) 
		merge(input, output, i, i+s-1, length-1, key);
	else {
		for(int j = i; j < length; j++) 
			output[j] = input[j];
	}
}

void mergeSort(Advertisement input[], int length, int key) {

	cout<<"进入mergeSort";
	cout<<length;
	Advertisement *temp = new Advertisement[length];
	int s = 1;//每次要合并的数组长度
	
	while(s <= length) {
		mergePass(input, temp, s, length, key);
		s += s;
		mergePass(temp, input, s, length, key);
		s += s;
	}

	for(int i = 0; i < length; i++) {
		fout<<i+1<<endl;
		fout<<" "<<input[i].getName()<<endl<<" "<<input[i].getAmount();
		fout<<endl<<" "<<input[i].getEmail()<<endl<<" "<<input[i].getStart();
		fout<<endl<<" "<<input[i].getEnd()<<endl;
	}
}


