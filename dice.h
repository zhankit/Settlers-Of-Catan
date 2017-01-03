#ifndef __dice_h__
#define __dice_h__

class dice {

public:

	// CTOR
	dice();

	// METHOD
	virtual int init_dice(int) = 0;

	// DTOR
	virtual ~dice();
};

#endif

