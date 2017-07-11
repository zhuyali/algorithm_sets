#include "Date.h"
    
ostream &operator<<(ostream& os, const Date& date) {
	os<<date.getYear()<<" "<<date.getMonth()<<" "<<date.getDay();
	return os;
}

int Date::getDay(void) const{
	return this->day;
}

int Date::getMonth(void) const{
	return this->month;
}

int Date::getYear(void) const{
	return this->year;
}

void Date::setDay(int& day) {
	this->day = day; 
}


void Date::setMonth(int& month) {
	this->month = month;
}

void Date::setYear(int& year){
	this->year = year;
}

bool Date::operator< (const Date &rhs) {
	if(this->year < rhs.getYear())
		return true;
	else if(this->year == rhs.getYear()) {
		if(this->month < rhs.getMonth())
			return true;
		else if(this->month == rhs.getMonth()) {
			if(this->day < rhs.getDay())
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}







