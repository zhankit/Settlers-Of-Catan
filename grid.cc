#include "grid.h"
#include "tiles.h"
#include "time.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "window.h"

using namespace std;

// HELPER FUNCTION
int stringtoint(string s) {
	int i= 0,counter = 0;
	while (s[counter] >= '0' && s[counter] <= '9') {
		i = i * 10 + (s[counter] - '0');
		counter++;
	}
	return i;
}

void Grid::draw_resources(){
	if (graphic_var) {
		window->fillRectangle(10, 40, 800, 100, 0);
		window->drawString(10, 50, players[0].get_information());
		window->drawString(10, 70, players[1].get_information());
		window->drawString(10, 90, players[2].get_information());
		window->drawString(10, 110, players[3].get_information());
	}
}

void Grid::draw_criteria(){
	if (graphic_var) {
		int colour = 1;
		// removed: , colour_counter
		window->fillRectangle(10, 700, 10, 10, 2);
		window->drawString(30, 700, "NETFLIX");

		window->fillRectangle(10, 720, 10, 10, 4);
		window->drawString(30, 720, "LAB");

		window->fillRectangle(10, 740, 10, 10, 5);
		window->drawString(30, 740, "STUDY");

		window->fillRectangle(10, 760, 10, 10, 6);
		window->drawString(30, 760, "TUTORIAL");

		window->fillRectangle(10, 780, 10, 10, 7);
		window->drawString(30, 780, "LECTURE");

		window->fillRectangle(10, 800, 10, 10, 8);
		window->drawString(30, 800, "CAFFEINE");

		// Refresh the windows
		window->fillRectangle(360, 180, 800, 800, 0);

		colour = colour_tiles(0);
		window->fillRectangle(600, 200, 90, 120, colour);

		colour = colour_tiles(1);
		window->fillRectangle(490, 265, 90, 120, colour);

		colour = colour_tiles(2);
		window->fillRectangle(710, 265, 90, 120, colour);
		// loop
		for (int i = 0; i < 3; i++) {
			colour = colour_tiles(3 + 5 * i);
			window->fillRectangle(380, 330 + i * 130, 90, 120, colour);

			colour = colour_tiles(4 + 5 * i);
			window->fillRectangle(600, 330 + i * 130, 90, 120, colour);

			colour = colour_tiles(5 + 5 * i);
			window->fillRectangle(820, 330 + i * 130, 90, 120, colour);

			colour = colour_tiles(6 + 5 * i);
			window->fillRectangle(490, 395 + i * 130, 90, 120, colour);

			colour = colour_tiles(7 + 5 * i);
			window->fillRectangle(710, 395 + i * 130, 90, 120, colour);
		}

		colour = colour_tiles(18);
		window->fillRectangle(600, 720, 90, 120, colour);



		// Draw points
		int criteria_counter = 0, goal_counter = 0;
		window->drawString(580, 195, this->getlocation(criteria_counter++, "CRITERION"));
		window->drawString(635, 195, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(690, 195, this->getlocation(criteria_counter++, "CRITERION"));
		window->drawString(580, 230, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(690, 230, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(470, 260, this->getlocation(criteria_counter++, "CRITERION"));
		window->drawString(525, 260, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(580, 260, this->getlocation(criteria_counter++, "CRITERION"));
		window->drawString(690, 260, this->getlocation(criteria_counter++, "CRITERION"));
		window->drawString(745, 260, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(800, 260, this->getlocation(criteria_counter++, "CRITERION"));

		window->drawString(470, 295, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(580, 295, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(690, 295, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(800, 295, "<" + this->getlocation(goal_counter++, "GOAL") + ">");

		for (int i = 0; i < 3; i++) {
			window->drawString(360, 330 + i * 130, this->getlocation(criteria_counter++, "CRITERION"));
			window->drawString(415, 330 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
			window->drawString(470, 330 + i * 130, this->getlocation(criteria_counter++, "CRITERION"));
			window->drawString(580, 330 + i * 130, this->getlocation(criteria_counter++, "CRITERION"));
			window->drawString(635, 330 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
			window->drawString(690, 330 + i * 130, this->getlocation(criteria_counter++, "CRITERION"));
			window->drawString(800, 330 + i * 130, this->getlocation(criteria_counter++, "CRITERION"));
			window->drawString(855, 330 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
			window->drawString(910, 330 + i * 130, this->getlocation(criteria_counter++, "CRITERION"));

			window->drawString(360, 360 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
			window->drawString(470, 360 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
			window->drawString(580, 360 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
			window->drawString(690, 360 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
			window->drawString(800, 360 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
			window->drawString(910, 360 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");

			window->drawString(360, 395 + i * 130, this->getlocation(criteria_counter++, "CRITERION"));
			window->drawString(470, 395 + i * 130, this->getlocation(criteria_counter++, "CRITERION"));
			window->drawString(525, 395 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
			window->drawString(580, 395 + i * 130, this->getlocation(criteria_counter++, "CRITERION"));
			window->drawString(690, 395 + i * 130, this->getlocation(criteria_counter++, "CRITERION"));
			window->drawString(745, 395 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
			window->drawString(800, 395 + i * 130, this->getlocation(criteria_counter++, "CRITERION"));
			window->drawString(910, 395 + i * 130, this->getlocation(criteria_counter++, "CRITERION"));

			window->drawString(360, 430 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
			window->drawString(470, 430 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
			window->drawString(580, 430 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
			window->drawString(690, 430 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
			window->drawString(800, 430 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
			window->drawString(910, 430 + i * 130, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		}

		window->drawString(360, 720, this->getlocation(criteria_counter++, "CRITERION"));
		window->drawString(415, 720, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(470, 720, this->getlocation(criteria_counter++, "CRITERION"));
		window->drawString(580, 720, this->getlocation(criteria_counter++, "CRITERION"));
		window->drawString(635, 720, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(690, 720, this->getlocation(criteria_counter++, "CRITERION"));
		window->drawString(800, 720, this->getlocation(criteria_counter++, "CRITERION"));
		window->drawString(855, 720, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(910, 720, this->getlocation(criteria_counter++, "CRITERION"));

		window->drawString(470, 750, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(580, 750, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(690, 750, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(800, 750, "<" + this->getlocation(goal_counter++, "GOAL") + ">");

		window->drawString(470, 785, this->getlocation(criteria_counter++, "CRITERION"));
		window->drawString(525, 785, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(580, 785, this->getlocation(criteria_counter++, "CRITERION"));
		window->drawString(690, 785, this->getlocation(criteria_counter++, "CRITERION"));
		window->drawString(745, 785, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(800, 785, this->getlocation(criteria_counter++, "CRITERION"));

		window->drawString(580, 825, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(690, 825, "<" + this->getlocation(goal_counter++, "GOAL") + ">");

		window->drawString(580, 850, this->getlocation(criteria_counter++, "CRITERION"));
		window->drawString(635, 850, "<" + this->getlocation(goal_counter++, "GOAL") + ">");
		window->drawString(690, 850, this->getlocation(criteria_counter++, "CRITERION"));
	}
}

void Grid::drawboard() {
	draw_resources();
	draw_criteria();
}

Grid::Grid(){
	// TO STORE THE TILESTYPE INTO TILES
	// TO SET THE RANDOM VALUE AS WELL
	graphic_var = false;

	vector<int> values ={2,3,3,4,4,5,5,6,6,8,8,9,9,10,10,11,11,12};
	vector<string> tilestype ={
		"TUTORIAL","TUTORIAL","TUTORIAL","STUDY","STUDY","STUDY","NETFLIX",
		"CAFFEINE","CAFFEINE","CAFFEINE","CAFFEINE","LAB","LAB","LAB","LAB","LECTURE",
		"LECTURE","LECTURE","LECTURE"};
	
	srand(time(0));
	int random = 19,random2 = 18;
	// CREATE A RANDOM TILES FOR THIS GAME
	for (int i = 0; i < 19; i++) {
		tiles temp;
		
		int x = rand() % (random--);
		int tile_value;
		if (tilestype.at(x) == "NETFLIX") {
			tile_value = 0;
		}
		else {
			int y = rand()% (random2--);
			tile_value = values.at(y);
			swap(values.at(y), values.back());
			values.pop_back();
		}

		temp.inittiles(tilestype.at(x), i, tile_value);
		tilesingrid.push_back(temp);
		swap(tilestype.at(x), tilestype.back());
		tilestype.pop_back();

	}
	cout << endl;

	student Player0 = student("Blue");
	student Player1 = student("Red");
	student Player2 = student("Orange");
	student Player3 = student("Yellow");
	players.push_back(Player0);
	players.push_back(Player1);
	players.push_back(Player2);
	players.push_back(Player3);

	load_dice = new loaddice();
	fair_dice = new fairdice();

	// create for the cell to put criteria
	for (int i = 0; i < 54; i++) {
		Cell temp;
		temp.initcell(i, "CRITERION");
		criterion_vectex.push_back(temp);
	}

	// create for the cell to put goal
	for (int i = 0; i < 72; i++) {
		Cell temp;
		temp.initcell(i, "GOAL");
		goal.push_back(temp);
	}

	//  Copy the value of the tiles to the Cell 
	this->reset_cells("vertexoftiles.txt",1);

	// ATTACH
	int counter = 0;
	int curr_crit, curr_attach_value;
	char curr_attach;
	string filename = "attach.txt",line, criteria;
	ifstream myfile1(filename);
	if (myfile1.is_open()) {
		while (getline(myfile1, line)) {
			istringstream word_string(line);
			while (word_string >> criteria) {
				if (counter == 0) {
					curr_crit = stringtoint(criteria);
				}
				else if (criteria == "C" || criteria == "G") {
					curr_attach = criteria[0];
				}
				else {
					curr_attach_value = stringtoint(criteria);
					if (curr_attach == 'C') {
						criterion_vectex[curr_crit].attach(&criterion_vectex[curr_attach_value]);
					}
					else if(curr_attach == 'G') {
						criterion_vectex[curr_crit].attach(&goal[curr_attach_value]);
						goal[curr_attach_value].attach(&criterion_vectex[curr_crit]);
					}
				}
				counter++;
			}
			counter = 0;
		}
	}


	// ATTACH
	counter = 0;
	filename = "attachgoal.txt";
	ifstream myfile2(filename);
	if (myfile1.is_open()) {
		while (getline(myfile2, line)) {
			istringstream word_string(line);
			while (word_string >> criteria) {
				if (counter == 0) {
					curr_crit = stringtoint(criteria);
				}else {
					curr_attach_value = stringtoint(criteria);
					goal[curr_crit].attach(&goal[curr_attach_value]);
				}
				counter++;
			}
			counter = 0;
		}
	
	}

}; // end

Grid::~Grid() {
	criterion_vectex.clear();
	goal.clear();
	tilesingrid.clear();
	players.clear();
	delete load_dice;
	delete fair_dice;
};

void Grid::graphic(bool var) {
	graphic_var = var;

	window = new Xwindow(1000, 1000);
	window->drawString(10, 15, "=============");
	window->drawString(10, 25, "PROJECT WATAN");
	window->drawString(10, 35, "=============");
}


bool Grid::win_status() {
	for(int i =0; i < 4; i++) {
		if(players[i].show_vp() >= 10) {
			cout << "Winner is student " << players[i].get_colour() << endl;
			return false;
		}
	}
	return true;
	
}

string Grid::getlocation(int i, string location) const {
	if (location == "CRITERION") {
		return criterion_vectex[i].getlocation();
	}
	else {
		return goal[i].getlocation();
	}
}

string Grid::print_player_information() {
	string s;
	for (auto it = players.begin(); it != players.end() ; it++){
		s += it->get_information();
	}
	return s;
}

string Grid::print_player_colour(int loc) {
	return players[loc].get_colour();
}

// NO PROBLEM
string Grid::print_help() const{
	string s = "";
	s += "board\nstatus\ncriteria\nachieve <goal>\ncomplete <criterion>\nimprove <criterion>\n";
	s += "trade <colour> <give> <take>\nnext\nsave\nhelp\n";
	return s;
}

string Grid::curr_criteria(int player) {
	return players[player].get_completions();
};

bool Grid::complete_criteria(int curr_player, int location, int game_start) {
	if (location <= 53 && location >= 0 && game_start) {
		if (criterion_vectex[location].complete_crit(players[curr_player].get_colour(), game_start, 1)) {
			players[curr_player].add_criterion_done(location, "Assignment");
			return true;
		}
		else {
			return false;
		}	
	}
	else if(location <= 53 && location >= 0) {
		if (criterion_vectex[location].complete_crit(players[curr_player].get_colour(), game_start, 1)) {
			if (players[curr_player].improve_build_resource("assignment")) {
				players[curr_player].add_criterion_done(location, "Assignment");
				return true;
			}
			else {
				return false;
			}
		}
		else {
			cout << "You cannot build here" << endl;
			return false;
		}
	}else {
		cout << "You cannot build here" << endl;
		return false;
	}

}

bool Grid::complete_goal(int curr_player, int location, int game_start) {
	if (location <= 71 && location >= 0) {
		if(goal[location].complete_goal(players[curr_player].get_colour(), game_start, 2)){
			if (players[curr_player].improve_build_resource("goal")) {
				return true;
			}
			else {
				return false;
			}
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
}

void Grid::improve_criteria(int curr_player, int location) {
	if (location <= 53 && location >= 0) {
		if (criterion_vectex[location].get_criteria() == 1) {
			if (players[curr_player].improve_build_resource("midterm")) {
				criterion_vectex[location].improve_crit(players[curr_player].get_colour());
				players[curr_player].add_criterion_done(location, "Midterm");
			}
		}
		else if (criterion_vectex[location].get_criteria() == 2) {
			if (players[curr_player].improve_build_resource("final")) {
				criterion_vectex[location].improve_crit(players[curr_player].get_colour());
				players[curr_player].add_criterion_done(location, "Final");
			}
		}
		else {
			cout << "Invalid command" << endl;
		}
	}
	
	draw_resources();
	draw_criteria();
}

void Grid::resources_rolled(int dice_value) {
	int counter_resource = 0;
	vector<int> resource_before_player_1 = players[0].get_resources_information();
	vector<int> resource_before_player_2 = players[1].get_resources_information();
	vector<int> resource_before_player_3 = players[2].get_resources_information();
	vector<int> resource_before_player_4 = players[3].get_resources_information();

	for (auto it : criterion_vectex) {
		if (it.get_criteria_type() != "--") {
			if (it.find_value(dice_value) != -1) {
				int location = it.find_value(dice_value);
				string resource = it.get_source(location);
				if (it.get_geese() == 'N') {
					if (it.get_colour() == 'B') {
						players[0].add_resource(resource, it.get_criteria());
						counter_resource += 1;
					}
					else if (it.get_colour() == 'R') {
						players[1].add_resource(resource, it.get_criteria());
						counter_resource += 1;
					}
					else if (it.get_colour() == 'O') {
						players[2].add_resource(resource, it.get_criteria());
						counter_resource += 1;
					}
					else if (it.get_colour() == 'Y') {
						players[3].add_resource(resource, it.get_criteria());
						counter_resource += 1;
					}
				}
			}
		}
	}

	vector<int> resource_after_player_1 = players[0].get_resources_information();
	vector<int> resource_after_player_2 = players[1].get_resources_information();
	vector<int> resource_after_player_3 = players[2].get_resources_information();
	vector<int> resource_after_player_4 = players[3].get_resources_information();
	vector<string> resources = { "victory points" ,"CAFFEINE","LAB","LECTURE", "TUTORIAL" ,"STUDY" };

	if (counter_resource == 0) {
		cout << "No students gained resources." << endl;
		return;
	}
	else {
		if (resource_before_player_1 != resource_after_player_1) {
			cout << "Student Blue gained:" << endl;
			for (int i = 1; i <= 5; i++) {
				if (resource_before_player_1[i] != resource_after_player_1[i]) {
					cout << resource_after_player_1[i] - resource_before_player_1[i] << " " << resources[i] << endl;
				}
			}
		}
		if (resource_before_player_2 != resource_after_player_2) {
			cout << "Student Red gained:" << endl;
			for (int i = 1; i <= 5; i++) {
				if (resource_before_player_2[i] != resource_after_player_2[i]) {
					cout << resource_after_player_2[i] - resource_before_player_2[i] << " " << resources[i] << endl;
				}
			}
		}
		if (resource_before_player_3 != resource_after_player_3) {
			cout << "Student Orange gained:" << endl;
			for (int i = 1; i <= 5; i++) {
				if (resource_before_player_3[i] != resource_after_player_3[i]) {
					cout << resource_after_player_3[i] - resource_before_player_3[i] << " " << resources[i] << endl;
				}
			}
		}
		if (resource_before_player_4 != resource_after_player_4) {
			cout << "Student Yellow gained:" << endl;
			for (int i = 1; i <= 5; i++) {
				if (resource_before_player_4[i] != resource_after_player_4[i]) {
					cout << resource_after_player_4[i] - resource_before_player_4[i] << " " <<  resources[i] << endl;
				}
			}
		}
	}
	resource_after_player_1.clear();
	resource_after_player_2.clear();
	resource_after_player_3.clear();
	resource_after_player_4.clear();
	resource_before_player_1.clear();
	resource_before_player_2.clear();
	resource_before_player_3.clear();
	resource_before_player_4.clear();
	resources.clear();
	draw_resources();

};

void Grid::move_geese(int move_location) {
	int counter = 0;
	for (auto it : tilesingrid) {
		if (it.get_geese() == 'Y') {
			break;
		}
		else {
			counter++;
		}
	}
	tilesingrid[counter].change_geese_status();
	tilesingrid[move_location].change_geese_status();
	this->reset_cells("vertexoftiles.txt",2);
}

void Grid::reset_cells(string filename,int reset) {
	int counter = 0, tiles_number, criteria_number;
	string criteria, line;
	ifstream myfile(filename);
	vector<int> geese_crit;
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			istringstream word_string(line);
			while (word_string >> criteria) {
				if (counter == 0) {
					tiles_number = stringtoint(criteria);
				}
				else {
					criteria_number = stringtoint(criteria);
					if (tilesingrid[tiles_number].get_geese() == 'Y') {
						geese_crit.push_back(criteria_number);
						criterion_vectex[criteria_number].set_value_into_cell(tilesingrid[tiles_number].get_tiles(), tilesingrid[tiles_number].get_val(), tilesingrid[tiles_number].get_geese(), reset); // consumes: string , int , char , int
					}
					else {
						if (geese_crit.empty()) {
							criterion_vectex[criteria_number].set_value_into_cell(tilesingrid[tiles_number].get_tiles(), tilesingrid[tiles_number].get_val(), tilesingrid[tiles_number].get_geese(), reset);
						}
						else {
							criterion_vectex[criteria_number].set_value_into_cell(tilesingrid[tiles_number].get_tiles(), tilesingrid[tiles_number].get_val(), 'N', reset);
							for (auto it : geese_crit) {
								if (it == criteria_number) {
									criterion_vectex[criteria_number].set_value_into_cell(tilesingrid[tiles_number].get_tiles(), tilesingrid[tiles_number].get_val(), 'Y', reset);
									break;
								}
							}

						}
					}
				}
				counter++;
			}
			counter = 0;
		}
	}
	geese_crit.clear();
}

void Grid::lose_resources() {
	for (int i = 0; i < 4; i++){
		players[i].lose_resources();
	}
	draw_resources();
}

void Grid::steal_resources(int player) {
	vector<string> student_to_steal;
	for (auto it : criterion_vectex) {
		if (it.get_geese() == 'Y') {
			if (it.get_colour() != '-' && it.get_colour() != players[player].get_colour()[0]) {
				if (it.get_colour() == 'B' && !(find(student_to_steal.begin(), student_to_steal.end(), "Red") != student_to_steal.end()) && players[0].total_resources() != 0) {
					student_to_steal.push_back("Blue");
				}
				else if (it.get_colour() == 'Y' && !(find(student_to_steal.begin(), student_to_steal.end(), "Red") != student_to_steal.end()) && players[3].total_resources() != 0) {
					student_to_steal.push_back("Yellow");
				}
				else if (it.get_colour() == 'O' && !(find(student_to_steal.begin(), student_to_steal.end(), "Orange") != student_to_steal.end()) && players[2].total_resources() != 0) {
					student_to_steal.push_back("Orange");
				}
				else if (it.get_colour() == 'R' && !(find(student_to_steal.begin(), student_to_steal.end(), "Red") != student_to_steal.end()) && players[1].total_resources() != 0) {
					student_to_steal.push_back("Red");
				}
			}
		}
	}// for loop
	sort(student_to_steal.begin(), student_to_steal.end());

	if (student_to_steal.size() == 0) {
		cout << "Student " << players[player].get_colour() << " has no students to steal from." << endl;
		return;
	}
	else {
		cout << "Student " << players[player].get_colour() << " can choose to steal from ";
		for (auto it : student_to_steal) {
			cout << it << ", ";
		}
		cout << endl;
	}

	cout << "Choose a student to steal from.\n<";
	string color_to_steal;
	cin >> color_to_steal;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////new added////////////////////////                                                                         //
/////////////////////////////////////////////////////////////////////////////                                  //
	while(color_to_steal != "Blue"&&color_to_steal != "Red"&& color_to_steal != "Yellow" && color_to_steal !=   "Orange") {                                                                                                // 
		cin >> color_to_steal;                                                                                 //
	}                                                                                                          //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	string result = "";
	vector<string> source_to_be_stolen = { "CAFFEINE", "LAB", "LECTURE", "TUTORIAL", "STUDY" };
	for (int i = 1; i < 6; i++) {
		if (color_to_steal == "Blue") {
			if (players[0].resource_stole(i)) {
				players[player].gain_resource(i);
				result += source_to_be_stolen[i - 1];
			}
		}
		else if (color_to_steal == "Red") {
			if (players[1].resource_stole(i)) {
				players[player].gain_resource(i);
				result += source_to_be_stolen[i - 1];
			}
		}
		else if (color_to_steal == "Orange") {
			if (players[2].resource_stole(i)) {
				players[player].gain_resource(i);
				result += source_to_be_stolen[i - 1];
			}
		}
		else if (color_to_steal == "Yellow") {
			if (players[3].resource_stole(i)) {
				players[player].gain_resource(i);
				result += source_to_be_stolen[i - 1];
			}
		}
	}
	source_to_be_stolen.clear();
	if (result == "") {
		cout << "Student " << players[player].get_colour() << " steals nothing from student " << color_to_steal << "." << endl ;
	}
	else {
		cout << "Student " << players[player].get_colour() << " steals " << result <<" from student " << color_to_steal << "." << endl;
	}

	draw_resources();
}

void Grid::trade_resources(int curr_player) {
	string player_to_trade, own_resource, trade_resource,response;
	int own_resource_pos, trade_resource_pos, player_to_trade_pos;
	cout << "Enter the player to trade:\n<" ;
	cin >> player_to_trade;

	if (player_to_trade == "Blue") {
		player_to_trade_pos = 0;
	}
	else if (player_to_trade == "Red") {
		player_to_trade_pos = 1;
	}
	else if (player_to_trade == "Orange") {
		player_to_trade_pos = 2;
	}
	else if (player_to_trade == "Yellow") {
		player_to_trade_pos = 3;
	}
	else{
		cout << "Invalid command" << endl;
		return;
	}

	if (player_to_trade_pos == curr_player) {
		cout << "Invalid command" << endl;
		return;
	}

	cout << "Enter resources offer:\n<";
	cin >> own_resource;

	if (own_resource == "CAFFEINE") {
		own_resource_pos = 1;
	}
	else if (own_resource == "LAB") {
		own_resource_pos = 2;
	}
	else if (own_resource == "LECTURE") {
		own_resource_pos = 3;
	}
	else if (own_resource == "TUTORIALS") {
		own_resource_pos = 4;
	}
	else if (own_resource == "STUDY") {
		own_resource_pos = 5;
	}
	else {
		cout << "Invalid command" << endl;
		return;
	}

	cout << "Enter resoures requested:\n<";
	cin >> trade_resource;

	if (trade_resource == "CAFFEINE") {
		trade_resource_pos = 1;
	}
	else if (trade_resource == "LAB") {
		trade_resource_pos = 2;
	}
	else if (trade_resource == "LECTURE") {
		trade_resource_pos = 3;
	}
	else if (trade_resource == "TUTORIALS") {
		trade_resource_pos = 4;
	}
	else if (trade_resource == "STUDY") {
		trade_resource_pos = 5;
	}
	else {
		cout << "Invalid command" << endl;
		return;
	}

	cout << players[curr_player].get_colour() << " offers " << player_to_trade << " one " << own_resource << " for one " << trade_resource << "." << endl;
	cout << "Does " << player_to_trade << " accept this offer?" << endl;
	cout << "Response with [ yes , no ]\n<";
	cin >> response;

	if (response == "no") {
		cout << "Nothing is traded." << endl;
	}
	else if (response == "yes") {
// switching trade_pos to make it right
		players[curr_player].trade_resource(trade_resource_pos, "offer");
		players[curr_player].trade_resource(own_resource_pos, "request");
		players[player_to_trade_pos].trade_resource(trade_resource_pos, "request");
		players[player_to_trade_pos].trade_resource(own_resource_pos, "offer");
		cout << "Traded is done" << endl;
	}
	else {
		cout << "Invalid command" << endl;
	}

	draw_resources();
};
////////////////////////////////////////////////////////////////////////////////////////
string Grid::saving() { // B R O Y
	string s = "";
	string info = "";
	string g = "";
	string c = "";
	for(int i = 0; i < 4; i++) {
		info.clear();
		g.clear();
		c.clear();
		info += "";
		g += "g ";
		c += "c ";
		info += players[i].get_caffeines();
		info += players[i].get_lab();
		info += players[i].get_lecture();
		info += players[i].get_studies();
		info += players[i].get_tutorials();
//		cout << "student class:" << endl;
//		cout << s << endl;
//		cout << "Student class method is okay" << endl;
		for(unsigned int j = 0; j < goal.size(); j++) {
			if (goal[j].get_colour() == 'B' && i == 0) {
				g += goal[j].get_nbr(0);
				g += " ";				
//				cout << "Get Nbr complete" << endl;
			} else if (goal[j].get_colour() == 'R' && i == 1) {
				g += goal[j].get_nbr(0);
				g += " ";
//				cout << "Get Nbr complete" << endl;
			} else if (goal[j].get_colour() == 'O' && i == 2) {
				g += goal[j].get_nbr(0);
				g += " ";
//				cout << "Get Nbr complete" << endl;
			} else if (goal[j].get_colour() == 'Y' && i == 3) {
				g += goal[j].get_nbr(0);
				g += " ";
//				cout << "Get Nbr complete" << endl;
			}
		} 	 info += g; 
		for (unsigned int k = 0; k < criterion_vectex.size();k++) {
			if (criterion_vectex[k].get_colour() == 'B' && i == 0) {
				c += criterion_vectex[k].get_nbr(1);
				c += " ";				
//				cout << "Get Nbr complete" << endl;
			} else if (criterion_vectex[k].get_colour() == 'R' && i == 1) {
				c += criterion_vectex[k].get_nbr(1);
				c += " ";
//				cout << "Get Nbr complete" << endl;
			} else if (criterion_vectex[k].get_colour() == 'O'&& i == 2) {
				c += criterion_vectex[k].get_nbr(1);
				c += " ";
//				cout << "Get Nbr complete" << endl;
			} else if (criterion_vectex[k].get_colour() == 'Y' && i == 3) {
				c += criterion_vectex[k].get_nbr(1);
				c += " ";
//				cout << "Get Nbr complete" << endl;
			}
		}	 info += c;
			 info += "\n";
			 s += info;
	} for(unsigned int i = 0; i < tilesingrid.size(); i++) {
		if(tilesingrid[i].get_tiles() == "CAFFEINE") {
			s += to_string(0);
			s += " ";
			s += to_string(tilesingrid[i].get_val());
			s += " ";
		} else if(tilesingrid[i].get_tiles() == "LAB") {
			s += to_string(1);
			s += " ";
			s += to_string(tilesingrid[i].get_val());
			s += " ";
		} else if(tilesingrid[i].get_tiles() == "LECTURE") {
			s += to_string(2);
			s += " ";
			s += to_string(tilesingrid[i].get_val());
			s += " ";
		} else if(tilesingrid[i].get_tiles() == "STUDY") {
			s += to_string(3);
			s += " ";
			s += to_string(tilesingrid[i].get_val());
			s += " ";
		} else if(tilesingrid[i].get_tiles() == "TUTORIAL") {
			s += to_string(4); 
			s += " "; 
			s += to_string(tilesingrid[i].get_val()); 
			s += " ";
		} else if(tilesingrid[i].get_tiles() == "NETFLIX") {
			s += to_string(5); 
			s += " "; 
			s += to_string(7);
			s += " ";
		}
	} return s;
}

void Grid::loading_resources(int caff, int lab, int lect, int stud, int tuto, int studt) {
	if( caff != -1 && lab != -1 && lect != -1 && stud != -1 &&  tuto != -1 && studt != -1)
	players[studt].set_resources(caff, lab, lect, stud, tuto);
}

void Grid::loading_goal(int location,int i){
	if(location != -1) {
		goal[location].set_achived(i);
	}
}

void Grid::loading_crit(int location, int type,int i){
	if(location != -1 && type != -1) {
		criterion_vectex[location].set_completed(i,type);
		players[i].update_VP(type);
		if (type == 1) players[i].add_criterion_done(location, "Assignment");
		else if (type == 2) players[i].add_criterion_done(location, "Midterm");
		else if (type == 3) players[i].add_criterion_done(location, "Final");
	}
}

void Grid::loading_board(int value, int type, int i){
	if(value != -1 && type != -1) {
		tilesingrid[i].pre_setup(value,type);
	}
}



////////////////////////////////////////////////////////////////////////////////////////////////

bool Grid::dicecalled(string dice_roll,int playerturn) {
	int dice_val;

	if (dice_roll == "fair") {
		dice_val = fair_dice->init_dice(0);
	} // fair_dice called
	else if (dice_roll == "load") {
		cout << "Please input value between 2 - 12\n<";
		cin >> dice_val;
//////////////////////////////////////////////////////////////////////////
//////////////new added////////////////////////                        ///
////////////////////////////////////////////////                       ///
		while(cin.fail()) {                                    ///
			cin.clear();                                               ///
			cin.ignore();                                              ///
			cin >> dice_val;                                           ///
			if(!cin.fail()) break;	                                   ///
		}                                                              ///
//////////////////////////////////////////////////////////////////////////
		if (dice_val > 12 && dice_val < 2) {
			cout << "Invalid Command" << endl;
			return false;
		}
	} // load dice called
	else {
		cout << "Invalid Command!!!" << endl;
		return false;
	} // invald command

	cout << "Dice rolled: " << dice_val << endl;

	if (dice_val != 7) {
		this->resources_rolled(dice_val);
		return true;
	}
	else {
		this->lose_resources();
		cout << "Choose where to place the GEESE.\n<";
		int geese_location;
		cin >> geese_location;
////////////////////////////////////////////////////////////////////////////////////////
//////////new added/////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
		while(cin.fail()|| (geese_location >= 19||geese_location <= -1)) {            //
			cin.clear();         
			cin.ignore();                                                             //
			cin >> geese_location;                                                    //
			if(!cin.fail() && (geese_location >= 0&&geese_location <= 18)) break;	                                                  //
		}                                                                             //
////////////////////////////////////////////////////////////////////////////////////////
		this->move_geese(geese_location);
		cout << "";
		this->steal_resources(playerturn);
		return true;
	}

}

int Grid::colour_tiles(int location) {
	if (tilesingrid[location].get_tiles() == "NETFLIX") {
		return 2;
	} // Red color	
	else if (tilesingrid[location].get_tiles() == "LAB") {
		return 4;
	}
	else if (tilesingrid[location].get_tiles() == "STUDY") {
		return 5;
	}
	else if (tilesingrid[location].get_tiles() == "LECTURE") {
		return 6;
	}
	else if (tilesingrid[location].get_tiles() == "CAFFEINE") {
		return 7;
	}else{
        return 8;
    }

}

ostream &operator<<(std::ostream &out, const Grid & this_grid) {
	int criterion_vectexcounter = 0, goalcounter = 0, tilescounter = 0 ;
	string opencol1 = "/            \\";
	string opencol2 = "/                \\";
	string closecol = "\\            /";
	string closecol2 = "\\                /";

	// 1-st line
	out << string(35,' ') << this_grid.getlocation(criterion_vectexcounter, "CRITERION") << "--" << this_grid.getlocation(goalcounter, "GOAL") << "--";
	out << this_grid.getlocation(++criterion_vectexcounter, "CRITERION") << endl;

	// 2-nd line
	out << string(35, ' ') << opencol1 << endl;

	// 3-rd line
	out << string(33, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
	out << string(6, ' ') << " 0";
	out << string(5, ' ') << this_grid.getlocation(++goalcounter, "GOAL") << endl;

	// 4-th line
	out << string(33, ' ') << "/     " << this_grid.tilesingrid[tilescounter].printer("t") << "   \\" << endl;

	// 5-th line
	out << string(20, ' ') << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
	out << "--" << this_grid.getlocation(++goalcounter, "GOAL") << "--" << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
	out << "       " << this_grid.tilesingrid[tilescounter].printer("v");
	out << string(7, ' ') << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
	out << "--" << this_grid.getlocation(++goalcounter, "GOAL") << "--" << this_grid.getlocation(++criterion_vectexcounter, "CRITERION") << endl;

	// 6-th line
	out << string(20, ' ') << opencol1 << string(5,' ') << this_grid.tilesingrid[tilescounter].printer("g") << string(6, ' ') << opencol1<< endl;

	tilescounter++;

	// 7-th line
	out << string(18, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
	out << string(6, ' ') << this_grid.tilesingrid[tilescounter].printer("i");
	out << string(5, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
	out << string(13, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
	out << string(6, ' ') << this_grid.tilesingrid[tilescounter+1].printer("i");
	out << string(5, ' ') << this_grid.getlocation(++goalcounter, "GOAL") << endl;

	// 8-th line
	out << string(18, ' ') << "/     " << this_grid.tilesingrid[tilescounter].printer("t") << string(3,' ') << "\\";
	out << string(12, ' ') << "/     " << this_grid.tilesingrid[tilescounter+1].printer("t") << string(3, ' ') << "\\" << endl;


	// Loop for middle part
	for (int i = 0; i <= 2; i++) {

		// Loop 1
		out << string(5, ' ') << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
		out << "--" << this_grid.getlocation(++goalcounter, "GOAL") << "--" << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
		out << string(7, ' ') << this_grid.tilesingrid[tilescounter].printer("v");
		out << string(7, ' ') << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
		out << "--" << this_grid.getlocation(++goalcounter, "GOAL") << "--" << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
		out << string(7, ' ') << this_grid.tilesingrid[tilescounter+1].printer("v");
		out << string(7, ' ') << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
		out << "--" << this_grid.getlocation(++goalcounter, "GOAL") << "--" << this_grid.getlocation(++criterion_vectexcounter, "CRITERION") << endl;


		// Loop 2
		out << string(5, ' ') << opencol1 << string(5, ' ') << this_grid.tilesingrid[tilescounter].printer("g") << string(6, ' ');
		out <<  opencol1 << string(5, ' ') << this_grid.tilesingrid[tilescounter+1].printer("g") << string(6, ' ') << opencol1 << endl;
		tilescounter += 2;

		// Loop 3
		out << string(3, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
		out << string(6, ' ') << this_grid.tilesingrid[tilescounter].printer("i");
		out << string(5, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
		out << string(13, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
		out << string(6, ' ') << this_grid.tilesingrid[tilescounter+1].printer("i");
		out << string(5, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
		out << string(13, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
		out << string(6, ' ') << this_grid.tilesingrid[tilescounter+2].printer("i");
		out << string(5, ' ') << this_grid.getlocation(++goalcounter, "GOAL") << endl;

		// Loop 4
		out << string(3, ' ') <<  "/     " << this_grid.tilesingrid[tilescounter].printer("t") << string(3, ' ') << "\\";
		out << string(12, ' ') <<  "/     " << this_grid.tilesingrid[tilescounter + 1].printer("t") << string(3, ' ') << "\\";
		out << string(12, ' ') << "/     " << this_grid.tilesingrid[tilescounter + 2].printer("t") << string(3, ' ') << "\\" << endl;

		// Loop 5 
		out << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
		out << string(7, ' ') << this_grid.tilesingrid[tilescounter].printer("v") << string(7, ' ') << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
		out << "--" << this_grid.getlocation(++goalcounter, "GOAL") << "--" << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
		out << string(7, ' ') << this_grid.tilesingrid[tilescounter+1].printer("v") << string(7, ' ') << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
		out << "--" << this_grid.getlocation(++goalcounter, "GOAL") << "--" << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
		out << string(7, ' ') << this_grid.tilesingrid[tilescounter+2].printer("v") << string(7, ' ') << this_grid.getlocation(++criterion_vectexcounter, "CRITERION") << endl;

		// Loop 6
		out << string(3, ' ') << "\\     " << this_grid.tilesingrid[tilescounter].printer("g") << string(6, ' ') << "/"
			<< string(12, ' ') << "\\     " << this_grid.tilesingrid[tilescounter+1].printer("g") << string(6, ' ') << "/"
			<< string(12, ' ') << "\\     " << this_grid.tilesingrid[tilescounter+2].printer("g") << string(6, ' ') << "/" << endl;

		tilescounter += 3;

		// Loop 7
		out << string(3, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
		out << string(13, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
		out << string(6, ' ') << this_grid.tilesingrid[tilescounter].printer("i");
		out << string(5, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
		out << string(13, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
		out << string(6, ' ') << this_grid.tilesingrid[tilescounter+1].printer("i");
		out << string(5, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
		out << string(13, ' ') << this_grid.getlocation(++goalcounter, "GOAL") << endl;

		// Loop 8
		out << string(5, ' ') << closecol << "     " << this_grid.tilesingrid[tilescounter].printer("t") << string(3, ' ')
			<< closecol << "     " << this_grid.tilesingrid[tilescounter+1].printer("t") << string(3, ' ') << closecol << endl;

	} // END OF LOOP

	// Same as first 8-th line but inverted
	out << string(5, ' ') << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
	out << "--" << this_grid.getlocation(++goalcounter, "GOAL") << "--" << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
	out << string(7, ' ') << this_grid.tilesingrid[tilescounter].printer("v");
	out << string(7, ' ') << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
	out << "--" << this_grid.getlocation(++goalcounter, "GOAL") << "--" << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
	out << string(7, ' ') << this_grid.tilesingrid[tilescounter + 1].printer("v");
	out << string(7, ' ') << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
	out << "--" << this_grid.getlocation(++goalcounter, "GOAL") << "--" << this_grid.getlocation(++criterion_vectexcounter, "CRITERION") << endl;

	// Last 8-th line
	out << string(18, ' ') << "\\     " << this_grid.tilesingrid[tilescounter].printer("g") << string(6, ' ')
		<< "/" << string(12, ' ') << "\\     " << this_grid.tilesingrid[tilescounter].printer("g") << string(6, ' ') << "/" << endl;
	tilescounter += 2; 

	// Last 7-th line
	out << string(18, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
	out << string(13, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
	out << string(6, ' ') << this_grid.tilesingrid[tilescounter].printer("i");
	out << string(5, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
	out << string(13, ' ') << this_grid.getlocation(++goalcounter, "GOAL") << endl;

	// Last 6-th line
	out << string(20, ' ') << closecol << "     " << this_grid.tilesingrid[tilescounter].printer("t") << string(3, ' ') << closecol << endl;

	// Last 5-th line
	out << string(20, ' ') << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
	out << "--" << this_grid.getlocation(++goalcounter, "GOAL") << "--" << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
	out << string(7, ' ') << this_grid.tilesingrid[tilescounter].printer("v");
	out << string(7, ' ') << this_grid.getlocation(++criterion_vectexcounter, "CRITERION");
	out << "--" << this_grid.getlocation(++goalcounter, "GOAL") << "--" << this_grid.getlocation(++criterion_vectexcounter, "CRITERION") << endl;


	// Last 4-th line
	out << string(33, ' ') << "\\     " << this_grid.tilesingrid[tilescounter].printer("g") << string(6, ' ') << "/"<< endl;

	// Last 3-rd line
	out << string(33, ' ') << this_grid.getlocation(++goalcounter, "GOAL");
	out << string(13, ' ') << this_grid.getlocation(++goalcounter, "GOAL") << endl;

	// Last 2-nd line
	out << string(35, ' ') << closecol << endl;

	// Last 1-st line
	out << string(35, ' ') << this_grid.getlocation(++criterion_vectexcounter, "CRITERION") << "--" << this_grid.getlocation(++goalcounter, "GOAL") << "--";
	out << this_grid.getlocation(++criterion_vectexcounter, "CRITERION") << endl;

	return out;
}

