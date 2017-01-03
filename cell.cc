#include <iostream>
#include "cell.h"
#include <string>
#include "observer.h"
#include "subject.h"
#include <utility>
using namespace std;


Cell::Cell(){
	colour = '-';
	criteria = '_';
	criteria_completed = "--";
}

Cell::~Cell() {
	source.clear();
	source_value.clear();
};

void Cell::initcell(int num,string type) {
	celltype = type;

	// Initialize the number with 2 space
	// 0-9 will put a space in front of the number
	if (num < 10) {
		number += " ";
		number += to_string(num);
	}
	else {
		number += to_string(num);
	}
};

void Cell::set_value_into_cell(string value_string, int val, char geese,int reset) {
	if (reset == 1) {
		source.push_back(value_string);
		source_value.push_back(val);
	}
	//cout << endl;
	//cout << " CHANGEITBITCH: " << geese << endl;
	is_geese_here = geese;
};

bool Cell::complete_crit(string player_colour, int game_start, int complete_type) {
	if (this->criteria_completed == "--") {
		if (this->notifyObservers(player_colour, game_start, complete_type)) {
			criteria = 'A';
			colour = player_colour[0];
			string replace_criteria = player_colour.substr(0, 1);
			replace_criteria += "A";
			criteria_completed = replace_criteria;
			return true;
		}
		else {
			cout << "You cannot build here" << endl;
			return false;
		}
	}
	else {
		cout << "You cannot build here" << endl;
		return false;
	}
};

void Cell::improve_crit(string player_colour) {
	if (criteria_completed[0] != player_colour[0]) {
		if (criteria_completed == "--") {
		}
		else {
		}
	}
	else if (criteria_completed[1] == 'A') {
		criteria_completed[1] = 'M';
		criteria = 'M';
	} else if (criteria_completed[1] == 'M'){
			criteria = 'F';
			criteria_completed[1] = 'F';
	} else {
	}
};

bool Cell::complete_goal(string player_colour, int game_start,int complete_type) {
	if (this->criteria_completed == "--") {
		if (this->notifyObservers(player_colour, game_start,complete_type)) {
			criteria = 'A';
			colour = player_colour[0];
			string replace_criteria = player_colour.substr(0, 1);
			replace_criteria += "A";
			criteria_completed = replace_criteria;
			return true;
		}
		else {
			cout << "You cannot build here" << endl;
			return false;
		}
	}
	else {
		cout << "You cannot build here" << endl;
		return false;
	}
};

string Cell::getlocation() const {
	string print;
	if (criteria_completed != "--" && celltype == "CRITERION") {
		return "|" + criteria_completed + "|";
	} // Criteria is taken and it is criterion
	else if (criteria_completed != "--" && celltype == "GOAL") {
		return  criteria_completed ;
	} // Criteria is taken and it is criterion
	else {
		if (celltype == "CRITERION") {
			print = "|" + number + "|";
		} // TYPE is goal
		else {
			print = number;
		} // TYPE is criterion_vectex
		return print;
	} // else : criteria is not completed yet
};

char Cell::get_colour() {
	return colour;
}

char Cell::get_geese() {
	return is_geese_here;
}

int Cell::get_criteria() {
	if (criteria == 'A') {
		return 1;
	}
	else if (criteria == 'M') {
		return 2;
	}
	else {
		return 3;
	}
}

int Cell::find_value(int value) {
	int counter = 0;
	for (auto it = source_value.begin(); it != source_value.end(); it++) {
		if (*it == value) {
			return counter;
		}
		counter++;
	}
	return -1;
}

std::string Cell::get_criteria_type() {
	return criteria_completed;
};			 // Get the criteria_completed

std::string Cell::get_source(int location) {
	return source[location];
};

void Cell::print_source() {
	int size = source.size();
	for (int i = 0; i < size; i++) {
		cout << source[i] << ": " << source_value[i] << " ";
	}
}

bool Cell::notify(Subject &a,int game_start,string player_colour, int complete_type) {
	if (complete_type == 1) {
		if (game_start) {
			if (this->celltype == "CRITERION") {
				if (criteria_completed == "--") {
					return false;
				}
				else {
					return true;
				}
			} // if this is criteria
		}
		else {
			if (this->celltype == "CRITERION") {
				if (criteria_completed == "--") {
					return false;
				}
				else {
					return true;
				}
			} // if this is criteria
			else if (this->celltype == "GOAL") {
				if (this->colour == player_colour[0]) {
					return true;
				}
				else {
					return false;
				}
			} // if this is goal
		}  // check when
	}
	else {
		if (this->colour == player_colour[0]) {
			return true;
		}
		else {
			return false;
		}
	} // Check when completing the goal
	return false;
}

string Cell::get_nbr(int i) {
	string s = "";
	if(celltype == "CRITERION" && criteria_completed.size() == 2 && i == 1) {
		 s += number;
		 s += " ";
		 if(criteria_completed[1] == 'A' ) {
			 s += "1";
		 } else if(criteria_completed[1] == 'M' ) {
			 s += "2";
		 } else if(criteria_completed[1] == 'F' ) {
			 s += "3";
		 }  
		 return s;
	 } else if(celltype == "GOAL" && criteria_completed != "--" && i == 0) {
		 s += number;
		 return s;
	 } 
	return s;
}

void Cell::set_achived(int i){
	if(i == 0) {
		colour = 'B';
		criteria_completed[0] = 'B';
	} else if (i == 1) {
		colour = 'R';
		criteria_completed[0] = 'R';
	} else if (i == 2) {
		colour = 'O';
		criteria_completed[0] = 'O';
	} else if (i == 3) {
		colour = 'Y';
		criteria_completed[0] = 'Y';
	}
	criteria = 'A';
	celltype = "GOAL";
	criteria_completed += to_string(colour) + "A";
}

void Cell::set_completed(int i, int type) {
	if(i == 0) {
		colour = 'B';
		criteria_completed[0] = 'B';
	} else if (i == 1) {
		colour = 'R';
		criteria_completed[0] = 'R';
	} else if (i == 2) {
		colour = 'O';
		criteria_completed[0] = 'O';
	} else if (i == 3) {
		colour = 'Y';
		criteria_completed[0] = 'Y';
	}
	if(type == 1) {
		criteria_completed[1] = 'A';
	} else if (type == 2) {
		criteria_completed[1] = 'M';
	} else if (type == 3) {
		criteria_completed[1] = 'F';
	}
	criteria = 'A';
	celltype = "CRITERION";
}



