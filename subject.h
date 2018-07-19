#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <vector>
#include "state.h"

class Observer;
class Info;

class Subject {
	std::vector<Observer *> observers;
	State s;
protected:
	void setState(State newS);
public:
	void attach(Observer *o);
	void notifyObservers();
	State getState() const;
	virtual ~Subject() = 0;
	virtual Info getInfo() = 0;
};

#endif
