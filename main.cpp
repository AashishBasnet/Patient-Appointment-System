#include <iostream>
#include <stdlib.h>
#include<conio.h>
#include<cstring>
#include<graphics.h>
#include"layouts.h"
#include"patient.h"
#include"doctor.h"
#include"admin.h"

void mainclick();

void mainstructure()
{
setfillstyle(1,15);
bar(0,0,1280,720);
setbkcolor(15);
settextstyle(1,0,3);
setcolor(CYAN);
outtextxy(520,80,"WELCOME TO");
settextstyle(1,0,4);
setcolor(CYAN);
outtextxy(235,120,"PATIENT APPOINTMENT SYSTEM");
setcolor(RED);
setlinestyle(0,0,2);
line(80,180,1180,180);
dbox(80,200,450,1130);
setcolor(0);
settextstyle(1,0,3);
outtextxy(520,230,"Select your role!");
dbox(100,300,300,300);
dbox(500,300,300,300);
dbox(890,300,300,300);

button(130,520,50,250);
button(530,520,50,250);
button(920,520,50,250);

settextstyle(4,0,1);
setbkcolor(CYAN);
setcolor(0);
outtextxy(190,532,"DOCTOR");
outtextxy(600,532,"PATIENT");
outtextxy(1000,532,"ADMIN");
readimagefile("images/exit.jpg",1220,660,1270,710);
readimagefile("images/doctor.jpg",200,360,300,460);
readimagefile("images/patient.jpg",610,360,710,460);
readimagefile("images/admin.jpg",1010,360,1110,460);
mainclick();	
}

void mainclick()
{
    bool astatus, pstatus;
    char did[50];
    bool alogstatus,dlogstatus;
    bool mcondition = true;
	bool mouseButtonDown = false;
while (mcondition) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

            // Check if the left mouse button is pressed
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !mouseButtonDown) {
                mouseButtonDown = true;

                // Check if the click is within the admin icon area
                if (p.x >= 920 && p.x <= 1170 && p.y >= 520 && p.y <= 570) {                
                    ADMIN a;
                    alog:
                    	astatus=false;
                    	alogstatus=true;
                    a.alogin();
                    astatus=a.loginclick();
                    if(astatus==true)
                    {  
                    	a.homestructure();
                    	alogstatus=a.click();
                    	if(alogstatus==false)
                    	{
                    		goto alog;
						}
					}
					else
					{
						mainstructure();
					}
                }

                // Check if the click is within the patient icon area
                else if (p.x >= 530 && p.x <= 780 && p.y >= 520 && p.y <= 570) {
                    PATIENT p;
                    pstatus = true;
                    pstatus = p.homestructure();
                    if(pstatus == false)
                    {
                        mainstructure();
					}
                }
            
                // Check if the click is within the doctor icon area
               else if (p.x >= 130 && p.x <= 380 && p.y >= 520 && p.y <= 570) {                                   
                    DOCTOR d;
                    dlog:
                    dlogstatus=true;
                    memset(did,0,sizeof(did));
                    d.dlogin();
                    strcpy(did,d.loginclick());
                    if(strcmp(did,"false")==0)
                    {
                       mainstructure();
					}
					else
					{	
						d.homestructure(did);
                    	dlogstatus=d.click();
                    	if(dlogstatus==false)
                    	{
                    		goto dlog;
						}
					}
                }
                
			   else if (p.x >= 1220 && p.x <= 1270 && p.y >= 660 && p.y <= 710)  
			   {
			   	mcondition=false;
			   	exit (0);
			   }
            }

            // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                mouseButtonDown = false;
            }
        }	
}

int main(int argc, char** argv) {
initwindow(1280,720,"Patient Appointment System");
  mainstructure();
getch();
	return 0;
}
