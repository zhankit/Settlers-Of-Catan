#include "loadeddice.h"
#include "time.h"
#include<stdlib.h>
#include <iostream>
using namespace std;

// CTOR
loaddice::loaddice() { loaddiceval = 0; };

// DTOR 
loaddice::~loaddice() { loaddiceval = 0; };

int loaddice::init_dice(int val)  {
	loaddiceval = val;
	return loaddiceval;
}

