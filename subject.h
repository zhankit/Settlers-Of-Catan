#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>

class Observer;

class Subject {
	std::vector<Observer*> observers;
public:
	void attach(Observer *o);
	bool notifyObservers(std::string,int,int);
	virtual ~Subject() = 0;
};

#endif

