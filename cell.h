#ifndef __cell_h__
#define __cell_h__
#include <string>
#include <vector>
#include "observer.h"
#include "subject.h"

class Cell : public Subject,public Observer{
	char colour;
	char criteria;
	char is_geese_here;   //Assignable value: Y or N
	std::string number;   //
	std::string celltype; // Assignable value:"CRITERION" or "Goal"
	std::string criteria_completed; // default value: -- // Assignable value: 'B' 'R' 'O' 'Y' followed by A M F or just B R O Y
	std::vector<std::string> source; // stores tile type(Lab lecture tut ...)
	std::vector<int> source_value;   // stores tile location(0 - 18)
public:
	// CTOR
	Cell();

	// DTOR
	virtual ~Cell();

	// METHODS
	void initcell(int,std::string);			     // initialize the cell
	void set_value_into_cell(std::string, int,char,int reset);  // initialize the value into cell
	bool complete_crit(std::string,int,int);         // Complete criteria at location
	void improve_crit(std::string);              // improve crite at location
	bool complete_goal(std::string, int,int);        // Complete goal at location


	std::string getlocation() const;	         // Get location of the criteria 
	char get_colour();							 // Get the colour of the char
	char get_geese();							 // Get the geese
	int get_criteria();					

	int find_value(int);						 // To check if the value of the dice is in the cell
	std::string get_criteria_type();			 // Get the criteria_completed
	std::string get_source(int);				 // Get the source at location

	bool notify(Subject &a,int, std::string,int) ;   // Neighbour will call this and check if it is able 
												 // the resources in the cell
	
	void print_source(); 
	std::string get_nbr(int type);
	void set_achived(int i);
	void set_completed(int i, int type);
};

#endif
