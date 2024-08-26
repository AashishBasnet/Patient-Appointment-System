#ifndef PATIENT_H
#define PATIENT_H

#include"ptsignup.h"
#include"ptlogin.h"
#include"ptdashboard.h"

class PATIENT:public PTSIGNUP,public PTLOGIN, public PTDASHBOARD
{
	bool showButtons = false;
    bool condition = true;
    bool mouseButtonDown = false;
    char user[100];
    bool appointmentstatus;
    long phonenumber;
    char date[20];
    
    public:
    	bool homestructure();
    	bool click();
    	void displayButtons();
};

#endif
