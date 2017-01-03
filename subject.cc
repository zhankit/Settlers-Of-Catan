#include <iostream>
#include "subject.h"
#include "observer.h"

using namespace std;

void Subject::attach(Observer *o) {
	observers.emplace_back(o);
};

bool Subject::notifyObservers(string player_colour,int game_start, int complete_type) {
	if (complete_type == 1) {
		int obs_size = (observers.size() + 1) / 2;
		int cri_counter = 0;
		for (auto ob : observers) {
			if (cri_counter < obs_size) {
				if (ob->notify(*this, game_start, player_colour, 1)){
					return false;
				}
			}
			else {
				if (game_start == 1) {
					return true;
				}
				else if(ob->notify(*this, game_start, player_colour, 1)) {
					return true;
				}
			}
			cri_counter++;
		}
		return false;
	}
	else {
		for (auto ob : observers) {
			if (ob->notify(*this, game_start, player_colour, 2)) {
				return true;
			}
		}
		return false;
	}
};

Subject::~Subject() {};

