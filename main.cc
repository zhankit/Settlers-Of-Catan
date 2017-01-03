#include <iostream>
#include <string>
#include <stdlib.h>
#include <utility>
#include<fstream>
#include<sstream>
#include "grid.h"
#include "loadeddice.h"
#include "fairdice.h"
#include<memory>
//#include <vld.h>
using namespace std;

bool Game_on(shared_ptr<Grid> game, int seed, int& playerturn, bool& skip_init, bool game_graphic) {

	cin.exceptions(ios::eofbit);
	srand(seed);
	cout << "====================================================================================================" << endl;
	cout << "=                        WELCOME TO THE GAME OF STUDENTS OF WATAN                                  =" << endl;
	cout << "====================================================================================================" << endl;
	cout << endl;

	// =============================================================================
	// Beginning of Game
	// =============================================================================
	if (!skip_init) cout << *game << endl;
	int setup_game = 1, decrease_switch = 0;

	if (game_graphic) {
		game->drawboard();
	}
	// remove  playerturn = 0,
	string command;
	try {
		while (setup_game && !skip_init) {
			int criteria_location;
			cout << "Student " << game->print_player_colour(playerturn);
			cout << ", where do you want to complete an Assignment?" << endl;
			cout << "<";
			while (cin >> criteria_location) {
				if (!game->complete_criteria(playerturn, criteria_location, 1)) {
					//cout << "You cannot build here." << endl;
					cout << "<";
				} // If cin is invalid
				else {
					if (playerturn == 3 && !decrease_switch) { playerturn = 3; decrease_switch = 1; }
					else {
						if (decrease_switch) { playerturn--; }
						else { playerturn++; }
					}
					break;
				} // if cin is valid
			} // While loop after 8 times

			if (playerturn == -1 && decrease_switch) {
				setup_game = 0;
				playerturn = 0;
				cout << *game;
			} // Loop end here
		} // While loop
		if (skip_init) {
			cout << *game << endl;
		}
		game->draw_criteria();
		game->draw_resources();
		bool switcher = true;
		while (switcher) {
			// =============================================================================
			// First phase of game
			// COMMAND: "LOAD","FAIR" and "ROLL"
			// =============================================================================
			cout << "COMMAND: load, fair and roll" << endl;
			cout << "<";
			//		int type_dice = 0;
			//		int load_val;
			string roll = "fair";
			while (cin >> command) {
				// type_dice is 1 if load is called, 2 if fai is called
				if (command == "load") {
					roll = "load";
					if (game->dicecalled(roll, playerturn)) {
						break;
					}
				} // "load"
				else if (command == "fair") {
					roll = "fair";
					if (game->dicecalled(roll, playerturn)) {
						break;
					}
				} // "fair"
				else if (command == "roll") {
					if (game->dicecalled(roll, playerturn)) {
						break;
					}
				}
				cout << "<";
			}

			cout << "COMMAND: board, status, criteria, achieve, complete, improve, trade, save  and help" << endl;
			// =============================================================================
			// SECOND PHASE OF GAME
			// COMMAND: "BOARD", "STATUS", "CRITERIA", "ACHIEVE", "COMPLETE", "IMPROVE"
			//          "TRADE", "NEXT", "SAVE", AND "HELP
			// =============================================================================
			cout << "<";
			while (cin >> command) {
				if (command == "board") {
					cout << *game;
					game->draw_criteria();
				} // "board"
				else if (command == "status") {
					cout << game->print_player_information();
					game->draw_criteria();
				} // print "status"
				else if (command == "criteria") {
					cout << game->curr_criteria(playerturn);
				} // print "criteria"
				else if (command == "achieve") {
					int goal_location;
					cin >> goal_location;
					if (!game->complete_goal(playerturn, goal_location, 0)) {}
				} // "achieve"
				else if (command == "complete") {
					int criteria_location;
					cin >> criteria_location;
					if (!game->complete_criteria(playerturn, criteria_location, 0)) {}
					game->draw_criteria();
					game->draw_resources();
				}
				else if (command == "improve") {
					int criteria_location;
					cin >> criteria_location;
					game->improve_criteria(playerturn, criteria_location);
					if (!game->win_status()) {
						cout << "Would you like to play again?" << endl;
						string cmd;
						cin >> cmd;
						if (cmd == "N") { return false; }
						else if (cmd == "Y") { 
						return true; 
						}
					}
					game->draw_criteria();
				}
				else if (command == "trade") {
					game->trade_resources(playerturn);
					game->draw_criteria();
				}
				else if (command == "next") {
					if (playerturn == 3) { playerturn = 0; }
					else { playerturn++; }
					break;
				} // "next"
				else if (command == "save") {
					fstream file;
					string save = "save.txt";
					cout << "Please Name your save file(Default Name: save.txt)" << endl;
					cin >> save;
					if (cin.fail()) cout << "Invalid Name, using default Name" << endl;
					file.open(save, fstream::out);
					//				cout << "successfully open" << endl;
					file << playerturn << "\n";
					file << game->saving();
					cout << "Successfully save" << endl;
					file.close();
				}
				else if (command == "help") {
					cout << game->print_help();
				} // "help"
				else {
					cout << "Invalid command." << endl;
					//switcher = false;
					//break;
				}
				cout << "<";
			}

		} // While loop until game is end
	}
	catch (ios::failure &) {
		fstream file;
		file.open("back.sv", fstream::out);
		file << playerturn << "\n";
		file << game->saving();
		cout << "Eof Occur, save status to backup.sv" << endl;
		file.close();
	}
	return false;
}


int main(int argc, char* argv[]) {
	// Variable setting
	int seed = 133436;
	int turn_count = 0;
	shared_ptr<Grid> game(new Grid());
	string save;
	string board;
	bool skip_init = false;
	bool game_graphic;
	
	// Command Line Argument reading
	for (int i = 0; i < argc; i++) {
		string cd = argv[i];
		stringstream ss;
		if (cd == "-graphic"){
				game_graphic = true;
				game->graphic(game_graphic);
			}
		if (i + 1 != argc) {
			if (cd == "-seed") {
				ss << argv[i + 1];
				ss >> seed;
				//cerr << "seed set" << endl;
			} // seed
			else if (cd == "-load") {
				ss << argv[i + 1];
				ss >> save;
				ifstream file(save);
				if (file.fail()) {
					cout << "Fail to Load: " << save << endl;
					cout << "Reading Input from Screen" << endl;
					continue;
				}
				skip_init = true;
				for (int i = 0; i < 6; i++) {
					if (i == 0) {
						file >> turn_count;
						continue;
					}
					else if (i >= 1 && i <= 4) {
						string sline;
						int caff = -1;
						int lab = -1;
						int lect = -1;
						int stud = -1;
						int tuto = -1;
						int loca = -1;
						int val = -1;
						file >> caff;
						file >> lab;
						file >> lect;
						file >> stud;
						file >> tuto;
						//					cout << caff << " " << lab << " "<< lect << " "<< stud << " "<< tuto << endl;
						game->loading_resources(caff, lab, lect, stud, tuto, i - 1);
						file >> loca;
						if (file.fail()) {
							file.clear();
							file.ignore();
							while (file >> loca) {
								game->loading_goal(loca, i - 1);
							}
						}
						file.clear();
						file.ignore();
						getline(file, sline);
						stringstream sst(sline);
						while (sst >> loca) {
							if (sst >> val) {
								game->loading_crit(loca, val, i - 1);
							}
							else { break; }
						}
						continue;
					}
					else {
						string sline;
						int v = -1;
						int t = -1;
						getline(file, sline);
						stringstream sst(sline);
						int i = 0;
						while (sst >> t) {
							if (sst >> v) {
								game->loading_board(v, t, i);
								i += 1;
							}
							else { break; }
						}
					}
				}
			}
			else if (cd == "-board") {
				ss << argv[i + 1];
				ss >> board;
				int val = -1;;
				int type = -1;
				ifstream f(board);
				int i = 0;
				while (f >> type) {
					if (f >> val) {
						game->loading_board(val, type, i);
						i += 1;
					}
					else { break; }
				}
			}
		}
	}
	// Game Starting !!!!
	while (1) {
		if (Game_on(game, seed, turn_count, skip_init, game_graphic)) {
			game.reset(new Grid());
		}
		else {
			return 0;
		}
	}
	return 0;
};

