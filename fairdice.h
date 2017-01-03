#ifndef __fairdice_h__
#define __fairdice_h__
#include "dice.h"

class fairdice :public dice {
	int dice1;
	int dice2;
public:
	fairdice();
	virtual int init_dice(int x);
	~fairdice();
};


#endif

