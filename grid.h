#ifndef __grid_h__
#define __grid_h__

#include "cell.h"
#include "tiles.h"
#include "student.h"
#include "loadeddice.h"
#include "fairdice.h"
#include <vector>
#include "window.h"


class Grid :public Cell {
	std::vector <Cell> criterion_vectex; // stores type of tile
	std::vector <Cell> goal;             // stores value of tile
	std::vector <tiles> tilesingrid;     // stores location of tile
	std::vector <student> players;       // stores info of current 4 players
	Xwindow *window;
	bool graphic_var;
	loaddice *load_dice;                 // pt to loaded dice
	fairdice *fair_dice;                 // pt to fair dice

public:
	// CTOR
	Grid();

	// DTOR
    ~Grid();
	int colour_tiles(int location); ///!!!
	void draw_criteria();
	void draw_resources();
	void graphic(bool);
	void reset_cells(std::string filename,int);
	void drawboard();

	// METHODS
	bool win_status();									 // return win there is one win player
	std::string getlocation(int x,std::string) const ;	 // 
	std::string print_player_information();				 // Print the resources of the players
	std::string print_player_colour(int);				 // Print the colour of the player
	std::string print_help() const;						 // Print the command help
	std::string curr_criteria(int player);				 // Print how many criteria does the player own

	bool complete_criteria(int player,int location,int game_start);	// Complete the criteria of player at location	
	bool complete_goal(int player, int location, int game_start);	// Complete the criteria of player at location	
	void improve_criteria(int player,int location);					// Improve the criteria of player at location
	void resources_rolled(int dice_value);
	
	std::string saving();
	void loading_resources(int caff, int lab, int lect, int stud, int tuto, int studt);
	void loading_goal(int location,int i);
	void loading_crit(int location, int type,int i);
	void loading_board(int value, int type, int i);

	void lose_resources();
	void steal_resources(int curr_player);
	void trade_resources(int curr_player);

	void move_geese(int move_location);
	


	//void trade_player(std::string player1, std::string player2, std::string resource_player1, std::string resource_player2);
	bool dicecalled(std::string dice_roll,int x);	// Fair dice

	// OPERATOR << OVERLOAD
	friend std::ostream &operator<<(std::ostream &out,const Grid &);
	
};

#endif

