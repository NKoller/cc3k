#include "subject.h"

void Subject::attach(Observer *o) {
	observers.emplace_back(o);
}

void Subject::notifyObservers() const {
	for (auto &ob : observers) {
		ob->notify(*this);
	}
}

State Subject::getState() const {
	return s;
}

Subject::~Subject() {}
