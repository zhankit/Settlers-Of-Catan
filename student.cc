#include "student.h"
#include <iostream>
#include <string>
using namespace std;

// CTOR
student::student(string colour) :colour{ colour } {
	// SET THE RESOURCES IN THIS ORDER
	resources = { "victory points" ,"CAFFEINE","LAB","LECTURE", "TUTORIAL" ,"STUDY" };
	resourcesnumber = { 0,0,0,0,0,0,0};

};

student::~student() {
	resources.clear();
	resourcesnumber.clear();
	criteria.clear();
	//criterianumber.clear();

}

string student::get_colour() const {
	return colour;
}

string student::get_information() const {
	string s = "" + colour + " has ";
	s += to_string(resourcesnumber[0]) + " victory points, ";
	s += to_string(resourcesnumber[1]) + " caffeines, ";
	s += to_string(resourcesnumber[2]) + " labs, ";
	s += to_string(resourcesnumber[3]) + " lectures, ";
	s += to_string(resourcesnumber[4]) + " tutorials, ";
	s += "and " + to_string(resourcesnumber[5]) + " studies.\n";
	return s;
}


string student::get_caffeines() const {
	string s = "";
	return s += to_string(resourcesnumber[1]) + " "; // caffeines,
}
string student::get_lab() const {
	string s = "";
	return s += to_string(resourcesnumber[2]) + " "; //  labs,
}
string student::get_lecture() const {
	string s = "";
	return s += to_string(resourcesnumber[3]) + " "; //lectures,
}
string student::get_studies() const {
	string s = "";
	return s +=  to_string(resourcesnumber[5]) + " "; // studies
}
string student::get_tutorials() const {
	string s = "";
	return s += to_string(resourcesnumber[4]) + " "; // tutorials,
}



string student::get_completions() const {
	string s = colour + " has completed:\n";
	for (unsigned int i = 0; i < criteria.size(); i++) {
		s += to_string(criterianumber[i]);
		s += " ";
		s += criteria.at(i) + '\n';
	}

	return s;
}

void student::add_resource(string resource, int crit_scale) {
	if (resource == "CAFFEINE") {
		resourcesnumber[1] += crit_scale;
	}
	else if (resource == "LAB") {
		resourcesnumber[2] += crit_scale;
	}
	else if (resource == "LECTURE") {
		resourcesnumber[3] += crit_scale;
	}
	else if (resource == "TUTORIAL") {
		resourcesnumber[4] += crit_scale;
	}
	else if (resource == "STUDY") {
		resourcesnumber[5] += crit_scale;
	}
};

void student::do_trade(int i) {
}

void student::lose_resources() {
	int totalresourceslost = 0;
	vector<int> total_resource_lost;
	for (int i = 1; i < 6; i++) {
		int resource_lost = 0;
		if (resourcesnumber[i] >= 10) {
			resource_lost = resourcesnumber[i] / 2;
			totalresourceslost += resource_lost;
			resourcesnumber[i] -= resource_lost;
			total_resource_lost.push_back(resource_lost);
		}
		else {
			total_resource_lost.push_back(resource_lost);
		}
	}

	cout << "Student " << colour << " loses " << totalresourceslost << " resources to the geese.";
	if (totalresourceslost != 0) {
		cout << "They lost: " << endl;
		for (int i = 1; i < 6; i++) {
			if (total_resource_lost[i - 1] != 0) {
				cout << total_resource_lost[i - 1] << " " << resources[i] << endl;
			}
		}
	}
	else {
		cout << endl;
	}



	total_resource_lost.clear();
};

int student::total_resources() {
	int total_resources = 0;
	for (int i = 1; i < 6; i++) {
		total_resources += resourcesnumber[i];
	}
	return total_resources;
}


bool student::resource_stole(int location) {
	if (resourcesnumber[location] == 0) {
		return false;
	} // Nothing to steal
	else {
		bool probability_lose = (rand() % 100) < ((this->resourcesnumber[location] * 100) /this->total_resources());
		if (probability_lose) {
			resourcesnumber[location] -= 1;
			return true;
		}// If lose then lost 1 
		else {
			return false;
		}// nothing lose
	}
};

void student::gain_resource(int location) {
	resourcesnumber[location] += 1;
};

void student::add_criterion_done(int location, string crit_type) {
	int switcher = true;
	for (unsigned int i = 0; i < criterianumber.size(); i++) {
		if (criterianumber[i] == location) {
			cout << "true";
			criteria[i] = crit_type;
			switcher = false;
			break;
		}
	}
	if (switcher) {
		string temp = crit_type;
		criteria.push_back(temp);
		criterianumber.push_back(location);
		resourcesnumber[0] += 1;
	}
}

void student::trade_resource(int sources_location, std::string type_in_out) {
	if (type_in_out == "offer") {
		resourcesnumber[sources_location] += 1;
	}
	else {
		resourcesnumber[sources_location] -= 1;
	}
}

vector<int> student::get_resources_information() {
	return resourcesnumber;
}

bool student::improve_build_resource(string build_type) {
	if (build_type == "assignment") {
		if (resourcesnumber[1] >= 1 && resourcesnumber[2] >= 1 && resourcesnumber[3] >= 1 && resourcesnumber[4] >= 1) {
			resourcesnumber[1] -= 1;
			resourcesnumber[2] -= 1;
			resourcesnumber[3] -= 1;
			resourcesnumber[4] -= 1;
			resourcesnumber[0] += 1;
			return true;
		}
		else {
			cout << "You do not have enough resources." << endl;
			return false;
		}
	}
	else if (build_type == "midterm") {
		if (resourcesnumber[3] >= 2 && resourcesnumber[5] >= 3) {
			resourcesnumber[3] -= 2;
			resourcesnumber[5] -= 3;
			resourcesnumber[0] += 1;
			return true;
		}
		else {
			cout << "You do not have enough resources." << endl;
			return false;
		}
	}
	else if (build_type == "final") {
		if (resourcesnumber[1] >= 3 && resourcesnumber[2] >= 2 && resourcesnumber[3] >= 2 && resourcesnumber[4] >= 1 && resourcesnumber[5] >= 2) {
			resourcesnumber[1] -= 3;
			resourcesnumber[2] -= 2;
			resourcesnumber[3] -= 2;
			resourcesnumber[4] -= 1;
			resourcesnumber[5] -= 2;
			resourcesnumber[0] += 1;
			return true;
		}
		else {
			cout << "You do not have enough resources." << endl;
			return false;
		}
	}
	else if (build_type == "goal") {
		if (resourcesnumber[4] >= 1 && resourcesnumber[5] >= 1) {
			resourcesnumber[4] -= 1;
			resourcesnumber[5] -= 1;
			return true;
		}
		else {
			cout << "You do not have enough resources" << endl;
			return false;
		}
	}
	else {
		return false;
	}
}



int student::show_vp() {
	return resourcesnumber[0];
}

void student::set_resources(int caff, int lab, int lect, int stud, int tuto) {
	resourcesnumber[1] = caff;
	resourcesnumber[2] = lab;
	resourcesnumber[3] = lect;
	resourcesnumber[4] = tuto;
	resourcesnumber[5] = stud;
}

void student::update_VP(int type) {
	if(type == 1) {
		resourcesnumber[0] += 1;
	} else if (type == 2) {
		resourcesnumber[0] += 2;
	} else if (type == 3) {
		resourcesnumber[0] += 3;
	}
}
/*
void student::update_CT(int location,int type){
	if(type == 1) {
		criteria[location] = "Assignment";
		criterianumber[location] = location;
	} else if(type == 2) {
		criteria[location] = "Midterm";
		criterianumber[location] = location;
	} else if(type == 3) {
		criteria[location] = "Final";
		criterianumber[location] = location;
	}
} */

