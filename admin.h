#ifndef ADMIN_H
#define ADMIN_H

#include"ahome.h"
#include"alogin.h"
#include"adsignup.h"

class ADMIN: public AHOME,public ALOGIN, public ADSIGNUP
{
	bool showButtons;
    bool condition ,srcondition;
    bool mouseButtonDown = false;
    bool mousebtn;
    char selectdep[50],selecttime[50];
    char selectyear[50],selectmonth[50],selectday[50];
    char finaldate[50];
    char ch_today[50];
    
    public:
    	void homestructure();
    	bool click();
    	void seerecords();
    	int seerecordsclick();
    	void displayButtons();
    	int reporttable();
    	int reporttableclick(int);
    	void viewoldrecords();
    	int viewoldrecordsclick();
    	int oldrectable();
		int oldrectableclick();  
    	
};

#endif
