#include "ptlogin.h"
#include "layouts.h"
#include "patient.h"
#include "cursorinput.h"
#include <fstream>
#include<iostream>
#include<cstring>
#include <graphics.h>
using namespace std;
char globalPatientID[50];
void clickFunp() {
    cout << "Logged in patient ID: " << globalPatientID << endl;
    // Use globalDoctorID as needed
}
void PTLOGIN::ptlogin() {
readimagefile("images/wuser.jpg",620,200,720,300);
          textfield(480,340,50,400);
          textfield(480,420,50,400);
          setcolor(RED);
          button(480,520,50,400);   
    setcolor(0);
    setbkcolor(15);
    settextstyle(4,0,1);
    outtextxy(480, 580, "not registered?");
    setcolor(CYAN);
     outtextxy(740, 580, "Signup");
    setcolor(LIGHTGRAY);
     settextstyle(3, 0, 1);
     setcolor(DARKGRAY);
     outtextxy(480, 320, "Username:");
     outtextxy(480, 400, "password:");
    settextstyle(4, 0, 2);
    setbkcolor(CYAN);
    setcolor(15);
    outtextxy(650, 530, "Login");
     setbkcolor(LIGHTGRAY);
     setcolor(3);
    settextstyle(4, 0, 3);
    outtextxy(625, 76, " Login");
}


char* PTLOGIN::loginclick() {
    logcondition = true; 
memset(username, 0, sizeof(username));
memset(password, 0, sizeof(password));

    while (logcondition) {
        POINT p;
        if (GetCursorPos(&p)) {
            ScreenToClient(GetForegroundWindow(), &p);

        if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {

            // username
            if (p.x >= 480 && p.x <= 880 && p.y >= 340 && p.y <= 390) {
                clickedtextfield(480, 340, 50, 400);
                   setfillstyle(1,WHITE);
                bar(478,478,1000,500);
                text_input(480, 340, 50, 400, username);
            }

            // password
            if (p.x >= 480 && p.x <= 880 && p.y >= 420 && p.y <= 470) {
                clickedtextfield(480, 420, 50, 400);
                setfillstyle(1,WHITE);
                bar(478,478,1000,500);
                pwtext_input(480, 420, 50, 400, password);
            }

            // login button
            if (p.x >= 480 && p.x <= 880 && p.y >= 520 && p.y <= 570) {
                clickedbutton(480, 520, 50, 400);
                delay(100);
                button(480, 520, 50, 400);
                if (checkdata(username, password)) {
                	setfillstyle(1,WHITE);
                	bar(479,479,880,510);
                	bar(481,341,879,389);
                	bar(481,421,879,469);
                    setcolor(RED);
                    settextstyle(3, 0, 1);
                    outtextxy(480, 480, " *welcome");
                    outtextxy(480, 480, " *welcome");
                    logcondition= false;
                    return username;
                } else {
                    setcolor(RED);
                    setbkcolor(15);
                    settextstyle(3, 0, 1);
                    outtextxy(480, 480, " *your username and password do not match. please try again");
                }
            }
            
            //for signup_text click
            
            if(p.x >= 740 && p.x <= 840 && p.y >= 580 && p.y <= 600)
            {
            	logcondition= false;
                 return "signuptext";	
			}

            // for sidebar buttons click
            if ((p.x >= 25 && p.x <= 105 && p.y >= 250 && p.y <= 270) || 
                (p.x >= 25 && p.x <= 125 && p.y >= 350 && p.y <= 370) || 
                (p.x >= 25 && p.x <= 105 && p.y >= 450 && p.y <= 470) || 
                (p.x >= 25 && p.x <= 125 && p.y >= 600 && p.y <= 620) ||
				(p.x >= 25 && p.x <= 105 && p.y >= 650 && p.y <= 670)) {
                logcondition = false;
                return "sideclick";
                
            }

            delay(10);
        }
    }
}
}

bool PTLOGIN::checkdata(const char* user, const char* pass) {
	int count=0;
  	fstream finout;
	finout.open("patient.bin", ios::in | ios::binary);
    if (finout) {
        char fileusername[50];
        char filename[100];
        char filephonenumber[20];
        char filepassword[100];
        finout.seekg(0,ios::beg);
        while (!finout.eof()) {
        	finout.read(fileusername, sizeof(fileusername));
            finout.read(filename, sizeof(filename));
            finout.read(filephonenumber, sizeof(filephonenumber));
            finout.read(filepassword, sizeof(filepassword));
             finout.ignore(1);
            if (strcmp(fileusername, user) == 0 && strcmp(filepassword,pass)==0) {
                  cout << filename << "\t" << filephonenumber << "\t" << fileusername << "\t" << filepassword << endl;
                  count+=1;
                  finout.close();
                  break;
            }
            else
            {
            	continue;
			}
}
if(count==1)
{
	return true;
}
else
{
	cout<<count;
	return false;
}
}
else
{
	cerr << "Error opening file for printing" << endl;
}
return false;
}
