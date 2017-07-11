#ifndef FIFO_H
#define FIFO_H

#include <string>
#include <queue>

using namespace std;

#include "event.h"
#include "simulator.h"

class fifo : public simulator {
  
  private:
    int number_of_pages;
	queue<event> wait;
	int seconds_per_page;

  public:
	  fifo(int seconds_per_page):simulator(seconds_per_page){this->seconds_per_page = seconds_per_page;};
	  void simulate(string file); 
	  ~fifo();
};

#endif
