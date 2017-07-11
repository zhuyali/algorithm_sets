#include <fstream>

using namespace std;

#include "fifo.h"

void fifo::simulate(string inFile) {

	string outFile;

	if(inFile == "arbitrary.run") 
		outFile = "arbitrary.out";
	else if(inFile == "bigfirst.run") 
		outFile = "bigfirst.out";
	else {
		cout<<"文件不存在";
		exit(0);
	}

	loadworkload(inFile);
	ofstream out(outFile.c_str());

	bool boolean = false;
	int totalJobs = 0;
	int latency = 0;
	int seconds = 0;
	int counter = 0;//计时器

	out<<"FIFO Simulation"<<endl<<endl;

	for(counter = counter; ; counter++) {
	
		if(workload.empty() && wait.empty())
			break;

		while(true && !workload.empty())  
		{
			event e =workload.front();
			job j = e.getjob();
		   	if(e.arrival_time() == counter) {
				totalJobs++;
				out<<"\tArriving: "<<j.getnumpages()<<" pages from "<<j.getuser()
					<<" at "<<counter<<" seconds"<<endl;
				wait.push(e);
			    workload.pop();
			}
			else
				break;
		}

		if(!wait.empty())
		{
			event e1 = wait.front();
			job j1 = e1.getjob();

			if(boolean == true)
			{
				if(seconds >= e1.arrival_time())
					seconds += j1.getnumpages() * seconds_per_page;
				else
					seconds = e1.arrival_time() + j1.getnumpages() * seconds_per_page;
			}
					
			if(counter >= seconds)
			{
				boolean = true;
				wait.pop();
				if(wait.empty() == false) 
				{
					event e2 = wait.front();
				    job j2 = e2.getjob();
			    	out<<"\tServicing: "<<j2.getnumpages()<<" pages from "<<j2.getuser()
					    <<" at "<<counter<<" seconds"<<endl;
					latency += counter - e2.arrival_time();
				}						    
			}
			else
			{
				boolean = false;
			}
		}
	}

	out<<endl;
	out<<"\tTotal jobs:"<<totalJobs<<endl;
	out<<"\tAggregate latency:"<<latency<<" seconds"<<endl;
	out<<"\tMean latency:"<<(double)latency/totalJobs<<" seconds"<<endl;
	out.close();
	cout<<"成功运行完毕!"<<endl;

}

fifo::~fifo() {}





