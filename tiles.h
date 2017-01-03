#ifndef __tile_h__
#define __tile_h__
#include <string>

class tiles {

	// VARIABLE FOR TILES
	int number, value; // number ranges from 0 - 18 representing location, value represents actual value of resources
	std::string tilestype; // eg: Lab Tutorials lecture ...
	char is_geese_here; // Y or N

public:
	// CTOR
	tiles();

	// DTOR
	~tiles();

	// METHOD
	void inittiles(std::string ,int,int);
	int get_val() const;
	std::string printer(std::string) const;
	std::string get_tiles() const;
	char get_geese() const;
	void change_geese_status();
	void pre_setup(int val, int type);
};


#endif

