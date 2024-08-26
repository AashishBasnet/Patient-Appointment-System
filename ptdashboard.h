#ifndef PTDASHBOARD_H
#define PTDASHBOARD_H

#include"pthome.h"
#include"ptappoint.h"
#include "ptabout.h"

class PTDASHBOARD: public PTHOME, public PTAPPOINT, public PTABOUT
{
	char ptname[50];
	bool dashcondition=true,cancelcondition=true;
	bool userbuttons=false,btdown;
	bool mouseDown = false;
	public:
		void ptdashboard(char[]);
		bool infodashboard();
	    bool dashboardclick();
	    void displayuserbuttons();
	    int cancelclick();
};

#endif
