#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <vector>
#include "state.h"

class Observer;
struct Info;

class Subject {
	State s;
protected:
	std::vector<Observer *> observers;
	void setState(State newS);
public:
	void attach(Observer *o);
	void notifyObservers();
	State getState() const;
	virtual ~Subject() = 0;
	//virtual Info getInfo();
};

#endif
