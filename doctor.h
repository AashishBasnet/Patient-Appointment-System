#ifndef DOCTOR_H
#define DOCTOR_H

#include"dthome.h"
#include"dlogin.h"
#include"dtabout.h"

class DOCTOR:public DTHOME, public DLOGIN, public DTABOUT
{
	bool showButtons = false;
    bool condition = true;
    bool mouseButtonDown = false;
    char docid[50];
    public:
    void homestructure(char []);
    bool click();
    void displayButtons();
};

#endif
