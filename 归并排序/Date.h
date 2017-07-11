#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "Date.h"

using namespace std;

class Date;

ostream &operator<<(ostream&, const Date&);

class Date {

  private:
    int month;
    int day;
    int year;

  public:
	Date(void):year(0),month(0),day(0){};
	Date (int year, int month, int day)
		  :year(year),month(month),day(day){};
    
	virtual void setMonth(int&);	    
	virtual void setDay(int&);
	virtual void setYear(int&);
	
	virtual int getMonth(void) const;	    
	virtual int getDay(void) const;	    
	virtual int getYear(void) const;	      

    virtual bool operator< (const Date &left);

};

#endif
 