#include "patient.h"
#include "layouts.h"
#include <graphics.h>
#include <cstring>

bool PATIENT::homestructure() {
	setfillstyle(1,WHITE);
    bar(0, 0, 1280, 720);
    setfillstyle(1, LIGHTGRAY);
    bar(0, 0, 1280, 100);
    setfillstyle(1, CYAN);
    bar(0, 100, 150, 720);
    readimagefile("images/dhasico.jpg", 5, 1, 105, 99);
    readimagefile("images/user.jpg", 1202, 32, 1250, 80);
    setcolor(0);
    setlinestyle(0, 0, 1);
    line(0, 100, 600, 100);
    line(600, 99, 610, 75);
    line(611, 75, 750, 75);
    line(760, 100, 1280, 100);
    setcolor(15);
    line(750, 75, 760, 100);
    setbkcolor(LIGHTGRAY);
    setcolor(CYAN);
    settextstyle(1, 0, 2);
      outtextxy(140, 30, "PATIENT");
        outtextxy(140, 60, "APPOINTMENT SYSTEM");
    setcolor(RED);
    setcolor(WHITE);
    setbkcolor(CYAN);
    settextstyle(4,0,1);
    outtextxy(25,250,"Home");
    outtextxy(25,350,"Appoint");
    outtextxy(25,450,"About");
    outtextxy(25,600,"Signup");
    outtextxy(25,550,"Login");
    setcolor(RED);
    outtextxy(25,650,"Exit");
    bool status= click();
    return status;
}


bool PATIENT::click() {
	pthome();
	bool logstatus = true;
	memset(user,0,sizeof(user));
	condition = true;
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
                
                                // home
                if (p.x >= 25 && p.x <= 105 && p.y >= 250 && p.y <= 270) {
                    showButtons = false;
                    int a=0;
                    displayButtons(); 
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(610,77,750,98);
                    pthome();
                    a=homebtnclick();
                    if(a==1)
                    {
                    	goto app;
					}
                }
                //appoint
                if (p.x >= 25 && p.x <= 125 && p.y >= 350 && p.y <= 370) {
                	app:
                    showButtons = false;
                    displayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(610,77,750,98);
					ptappoint(false,""); 
					appointclick();
                }
                
                //about
                if (p.x >= 25 && p.x <= 105 && p.y >= 450 && p.y <= 470) {
                    showButtons = false;
                   displayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(610,77,750,98);
					ptabout(); 
                    
                }
                
                                //signup
                if (p.x >= 25 && p.x <= 125 && p.y >= 600 && p.y <= 620) {
                	signup:
                    showButtons = false;
					int a=0;
                    displayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(610,77,750,98);
				    ptsignup(); 
					a = signupclick();
                    if(a==1)
                    {
                    	goto login;
					}
                    printfile();
                }
                
                                                //login
                if (p.x >= 25 && p.x <= 105 && p.y >= 550 && p.y <= 570) {
                	login:
                    showButtons = false;
                    displayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(610,77,750,98);
                    memset(user,0,sizeof(user));
					ptlogin();
					strcpy(user,loginclick());
				if(strcmp(user,"sideclick")==0)
				{
					continue;
				}
				else if(strcmp(user,"signuptext")==0)
				{
					goto signup;
				}
				else if(strlen(user) != 0)
				 {
				 	condition = false;
				 	ptdashboard(user);
				 	logstatus = dashboardclick(); 
				 	if(logstatus == false)
				 	{
				 	   homestructure();	
					}
				 }
				 else
				 {
				 	continue;
				 }
                }
                
                //exit
                if(p.x >= 25 && p.x <= 105 && p.y >= 650 && p.y <= 670)
                {
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

void PATIENT::displayButtons() {
        if (showButtons) {
           setcolor(RED);
           setbkcolor(LIGHTGRAY);
		   settextstyle(4,0,1);
           outtextxy(1000,35,"USER");
            outtextxy(1000,60,"(not resistered)");
        } else {
            setfillstyle(1,LIGHTGRAY);
            bar(1000, 0, 1200, 100);
        }
    }
    

