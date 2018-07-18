#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <vector>
#include "state.h"

class Observer;

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
};

#endif
