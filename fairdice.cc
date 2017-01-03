#include "fairdice.h"
#include "time.h"
#include<stdlib.h>
#include <iostream>
using namespace std;

// CTOR
fairdice::fairdice() {
	srand(time(NULL));
	dice1 = 0; 
	dice2 = 0; 
};


// DTOR 
fairdice::~fairdice() { dice1 = 0; dice2 = 0; };

int fairdice::init_dice(int x) {
	dice1 = rand() % 6 +1;
	dice2 = rand() % 6 +1;
	return dice1 + dice2;
}

