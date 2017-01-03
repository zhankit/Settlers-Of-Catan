#include "tiles.h"
#include <iostream>
#include <string>
using namespace std;

// CTOR
tiles::tiles(){
	value = 0;
	number = 0;
	tilestype = "-";
	is_geese_here = 'N';
}

tiles::~tiles() {}

void tiles::inittiles(string name, int location,int value_input) {
	tilestype = name;
	number = location;
	value = value_input;
	if(name == "NETFLIX"){
		is_geese_here = 'Y';
	}
}

string tiles::printer(string name)const {
	if (name == "t") {
		if (tilestype == "LAB") {
			return "LAB     ";
		}
		else if (tilestype == "STUDY") {
			return "STUDY   ";
		}
		else if (tilestype == "NETFLIX") {
			return "NETFLIX ";
		}
		else if (tilestype == "LECTURE") {
			return "LECTURE ";
		}
		else {
			return tilestype;
		}
	}
	else if (name == "g") {
		if (is_geese_here == 'N') { return string(5, ' '); }
		else if (is_geese_here == 'Y') {   return "GEESE"; }
	}
	else if (name == "v") {
		string s = "";
		if (value == 0) {
			s = "  ";
			return s;
		}
		else if (value < 10) {
			s = " " + to_string(value);
			return s;
		}
		else {
			return to_string(value);
		}
	}
	else if (name == "i") {
		string s = "";
		if (number < 10) {
			s = " " + to_string(number);
			return s;
		}
		else {
			return to_string(number);
		}
	} return "";
}

string tiles::get_tiles()const {
	return tilestype;
};

int tiles::get_val() const {
	return value;
};



char tiles::get_geese() const {
	return is_geese_here;
}

void tiles::change_geese_status() {
	if (is_geese_here == 'Y') {
		is_geese_here = 'N';
	}
	else {
		is_geese_here = 'Y';
	}
}

void tiles::pre_setup(int val, int type){
	value = val;
	if(type == 0) {
		tilestype = "CAFFEINE";
	} else if(type == 1) {
		tilestype = "LAB";
	} else if(type == 2) {
		tilestype = "LECTURE";
	} else if(type == 3) {
		tilestype = "STUDY";
	} else if(type == 4) {
		tilestype = "TUTORIAL";
	} else if(type == 5) {
		tilestype = "NETFLIX";
		value = 0;
	}
}

