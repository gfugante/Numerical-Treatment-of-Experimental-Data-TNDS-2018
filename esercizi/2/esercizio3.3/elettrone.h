#ifndef _elettrone_h_
#define _elettrone_h_
#include "particelle.h"
class elettrone: public particelle{
public:
	elettrone();
	~elettrone();
	void print() const;
};

#endif
