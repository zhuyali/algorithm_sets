#include "Advertisement.h"
#include "Date.h"

void Advertisement::setAmount(int& amount) {
	this->amount = amount;
}

void Advertisement::setName(string& name) {
	this->name = name;
}

void Advertisement::setEmail(string& email) {
	this->email = email;
}

void Advertisement::setStart(Date& start) {
	this->start = start;
}

void Advertisement::setEnd(Date& end) {
	this->end = end;
}
	
int Advertisement::getAmount(void) const {
	return this->amount;
}

string Advertisement::getName(void) const {
	return this->name;
}

string Advertisement::getEmail(void) const {
	return this->email;
}

Date Advertisement::getStart(void) const {
	return this->start;
}

Date Advertisement::getEnd(void) const {
	return this->end;
}