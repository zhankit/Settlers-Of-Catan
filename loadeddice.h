#ifndef __loadeddice_h__
#define __loadeddice_h__
#include "dice.h"
class loaddice :public dice {
	int loaddiceval;
public:
	loaddice();
	virtual int init_dice(int);
	~loaddice();
};


#endif

