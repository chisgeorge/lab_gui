#pragma once
#include <vector>
class Observer {
public:
	virtual void update() = 0;
};

class Observable {
	std::vector<Observer*> observers;
public:
	void add_observer(Observer* observer) {
		observers.push_back(observer);
	}
	void remove_observer(Observer* observer) {
		std::vector<Observer*>::iterator position = std::find(observers.begin(), observers.end(), observer);
		if (position != observers.end())
			observers.erase(position);
	}
protected:
	virtual void notify() {
		for (auto& object : observers) {
			object->update();
		}
	}
};