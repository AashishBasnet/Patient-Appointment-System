#include "doctor.h"
#include "layouts.h"
#include <graphics.h>
#include <fstream>
#include<iostream>

using namespace std;

void DOCTOR::homestructure(char did[50]) {
	memset(docid,0,sizeof(docid));
	strcpy(docid,did);
	setfillstyle(1,WHITE);
    bar(0, 0, 1280, 720);
    setfillstyle(1, LIGHTGRAY);
    bar(0, 0, 1280, 100);
    readimagefile("images/dhasico.jpg", 5, 1, 105, 99);
    readimagefile("images/user.jpg", 1202, 32, 1250, 80);
setcolor(0);
setlinestyle(0,0,1);
line(0,100,550,100);
line(550,99,560,75);
line(561,75,750,75);
line(760,100,1280,100);
setfillstyle(1,3);
bar(0,100,150,720);
settextstyle(4,0,1);
setbkcolor(CYAN);
setcolor(15);
    outtextxy(7,250,"Dashboard");
    outtextxy(10,350,"About Doc");
    outtextxy(10,550,"Change");
    outtextxy(10,570,"Password");
    outtextxy(10,450,"Patient");
    outtextxy(10,470,"Attended");
    setcolor(RED);
    outtextxy(25,650,"Logout");
setcolor(15);
line(750,75,760,100);
setbkcolor(LIGHTGRAY);
setcolor(CYAN);
settextstyle(1,0,2);
outtextxy(140,30,"PATIENT");
outtextxy(140,60,"APPOINTMENT SYSTEM");
}

bool DOCTOR::click() {
	dtabout(docid);
	 char firstName[50],department[50], date[50], timeSlot[50],tkno[50];
	showButtons=false;
	condition=true;
   while (condition) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

            // Check if the left mouse button is pressed
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !mouseButtonDown) {
                mouseButtonDown = true;

  // Check if the click is user icon
                if (p.x >= 1202 && p.x <= 1250 && p.y >= 30 && p.y <= 80) {
                    showButtons = !showButtons;
                    displayButtons();
                }
                
                                // dashboard
                if (p.x >= 7 && p.x <= 130 && p.y >= 250 && p.y <= 290) {
                    showButtons = false;
                    displayButtons(); 
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(589,77,750,98);
                    dthome1();
                    int a=ptrecordfillclick(docid);
                    if(a==1)
                    {
                    	dthome2();
                    	int b=ptnamefillclick();
                    	if(b==1)
                    	{
                         attendance_list();
                         int c= attendance_listclick();
                         if (c==1)
                         {
                         	dtabout(docid);
						 }
						}
						else if (b==0)
						{
							dtabout(docid);
						}
					}
					else
					{
						continue;
					}
                }                                                                                   
                
                //personalinfo
                if (p.x >= 10 && p.x <= 120 && p.y >= 350 && p.y <= 390) {
                    showButtons = false;
                    displayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(589,77,750,98);
                    dtabout(docid);
                }
                
                                //change password
                if (p.x >= 10 && p.x <= 137 && p.y >= 550 && p.y <= 601 ){
                    showButtons = false;
                    displayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(589,77,750,98);
                    changepassword(docid);
                    changepasswordclick();
                }
                
                
                                 //patient attended today
                if (p.x >= 10 && p.x <= 137 && p.y >= 450 && p.y <= 501 ){
                    showButtons = false;
                    displayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(589,77,750,98);
                    viewpatientlist(1);
                    viewpatientlistclick();
                }
                
                
                
                                //logout
                if (p.x >= 25 && p.x <= 115 && p.y >= 650 && p.y <= 690) {
                    showButtons = false;
                    displayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(589,77,750,98);
                    condition=false;
                    return false;
                }
                
            } 

            // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                mouseButtonDown = false;
            }
}
}



void DOCTOR::displayButtons() {
        if (showButtons) {
           setcolor(RED);
           setbkcolor(LIGHTGRAY);
		   settextstyle(4,0,1);
            outtextxy(1000,60,docid);
        } else {
            setfillstyle(1,LIGHTGRAY);
            bar(1000, 0, 1200, 100);
        }
    }
    




