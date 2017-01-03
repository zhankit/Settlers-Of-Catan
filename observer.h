#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Subject;
class Cell;

class Observer {
public:
	virtual bool notify(Subject &whoNotified,int game_start,std::string,int) = 0;  // pass the Cell that called
	virtual ~Observer() = default;
};

#endif

