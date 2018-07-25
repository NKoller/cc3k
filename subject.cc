#include "subject.h"
#include "observer.h"

void Subject::setState(State newS) {
		s = newS;
}

void Subject::attach(Observer *o) {
		observers.emplace_back(o);
}

void Subject::notifyObservers() {
		for (auto &ob : observers) {
				if (ob) ob->notify(*this);
		}
}

State Subject::getState() const {
		return s;
}

Subject::~Subject() {}
