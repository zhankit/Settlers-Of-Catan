#ifndef __student_h__
#define __student_h__

#include <vector>
#include <string>


class student {
	std::vector<std::string> resources; // type of victory point, caffeines, labs,  lectures, tutotials , studies
	std::vector<int> resourcesnumber; // value of victory point, caffeines, labs,  lectures, tutotials , studies
	std::vector<std::string> criteria; // total size 53, containing crit type
	std::vector<int> criterianumber; // total size 53, containing crit value
	std::string colour;
public:

	// CTOR
	student(std::string colour);
	
	~student();

	// Method
	std::string get_colour() const;
	std::string get_information() const;
	std::string get_completions() const;

	void add_resource(std::string,int);
	void do_trade(int);
	bool improve_build_resource(std::string);
	void lose_resources();
	int total_resources();
	void trade_resource(int sources_location, std::string type_in_out);

	void add_criterion_done(int, std::string);
	std::vector<int> get_resources_information();
	bool resource_stole(int);
	void gain_resource(int);
	
	int show_vp();
	
	std::string get_caffeines() const;
	std::string get_lab() const;
	std::string get_lecture() const;
	std::string get_studies() const;
	std::string get_tutorials() const;
	void set_resources(int caff, int lab, int lect, int stud, int tuto);
	void update_VP(int type);
//	void update_CT(int location,int type);
};

#endif

