#ifndef ADVERTISEMENT_H
#define ADVERTISEMENT_H

#include "Date.h"

using namespace std;

class Advertisement;

class Advertisement {

  private:
      int amount;
      string name;
	  string email;
	  Date start; 
	  Date end;

  public:

	  Advertisement(void):amount(0),name(""),email(""),start(*(new Date())),end(*(new Date())){};
	  Advertisement(int amount, string name, string email, Date start, Date end)
		  :amount(amount), name(name), email(email), start(start), end(end){};

	  virtual void setAmount(int&);	    
   	  virtual void setName(string&);
	  virtual void setEmail(string&);
	  virtual void setStart(Date&);
	  virtual void setEnd(Date&);
	
	  virtual int getAmount(void) const;	    
	  virtual string getName(void) const;	    
	  virtual string getEmail(void) const;	    
	  virtual Date getStart(void) const;	    
	  virtual Date getEnd(void) const;	    

};

#endif