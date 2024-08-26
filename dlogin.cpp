#include"dlogin.h"
#include"layouts.h"
#include<graphics.h>
#include"cursorinput.h"
#include<cstring>
#include<limits>
#include<fstream>
using namespace std;


void DLOGIN::dlogin()
{
setfillstyle(1,WHITE);	
bar(0,0,1280,720);
setlinestyle(1,0,3);
dbox(300,200,400,700);
setfillstyle(1,LIGHTGRAY);
bar(0,0,1280,100);
readimagefile("images/dhasico.jpg",5,1,105,99);
readimagefile("images/user.jpg",1202,32,1250,80);
setcolor(0);
setlinestyle(0,0,1);
line(0,100,550,100);
line(550,99,560,75);
line(561,75,750,75);
line(760,100,1280,100);
setbkcolor(LIGHTGRAY);
setcolor(CYAN);
settextstyle(1,0,2);
outtextxy(140,30,"PATIENT");
outtextxy(140,60,"APPOINTMENT SYSTEM");
textfield(450,290,50,400);
textfield(450,370,50,400);
button(450,470,50,400);
setbkcolor(15);
     setcolor(3);
     setbkcolor(LIGHTGRAY);
    settextstyle(4, 0, 2);
    outtextxy(600, 77, " Login");
    setbkcolor(15);
     settextstyle(3, 0, 1);
     setcolor(DARKGRAY);
     outtextxy(450, 270, "ID");
     outtextxy(450, 350, "password");
    settextstyle(4, 0, 2);
    setbkcolor(CYAN);
    setcolor(15);
    outtextxy(620, 480, "Login");
setcolor(RED);
setbkcolor(15);
settextstyle(4,0,1);
outtextxy(565,550,"x Cancel login");
}

char* DLOGIN::loginclick() {
    memset(doctorid,0,sizeof(doctorid));
    memset(password,0,sizeof(password));
    showbuttons=false;
    logcondition = true; 
    while (logcondition) {
        POINT p;
        GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

        if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !mousebuttondown){
        	mousebuttondown = true;
        	
        	 // Check if the click is user icon
                if (p.x >= 1202 && p.x <= 1250 && p.y >= 30 && p.y <= 80) {
                    showbuttons = !showbuttons;
                    displaybuttons();
                    delay(10);
                }
        	
            // doctorid
            if (p.x >= 450 && p.x <= 850 && p.y >= 290 && p.y <= 340) {
            	  showbuttons = false;
                    displaybuttons(); 
                clickedtextfield(450, 290, 50, 400);
                setfillstyle(1,WHITE);
                bar(430,430,1000,460);
                text_input(450, 290, 50, 400, doctorid);
                
            }

            // password
            if (p.x >= 450 && p.x <= 850 && p.y >= 370 && p.y <= 420) {
            	 showbuttons = false;
                    displaybuttons(); 
                clickedtextfield(450, 370, 50, 400);
                setfillstyle(1,WHITE);
                bar(430,430,1000,460);
                pwtext_input(450, 370, 50, 400, password);
            }

            // login button
            if (p.x >= 450 && p.x <= 850 && p.y >= 470 && p.y <= 520) {
            	 showbuttons = false;
                    displaybuttons(); 
                clickedbutton(450, 470, 50, 400);
                delay(100);
                button(450, 470, 50, 400);
                setfillstyle(1,WHITE);
                bar(430,430,1000,460);
                if (checkdata(doctorid, password)) {
                	setfillstyle(1,WHITE);
                	bar(479,479,880,510);
                	bar(481,341,879,389);
                	bar(481,421,879,469);
                    setcolor(RED);
                    settextstyle(3, 0, 1);
                    outtextxy(432, 432, " *welcome");
                    logcondition= false;
                    return doctorid;
                } else {
                    setcolor(RED);
                    settextstyle(3,0,1);
                    outtextxy(432, 432, " *your Id and password doesnot match. please try again");
                }
            }
            
            // for cancel login click
            if ((p.x >= 565 && p.x <= 750 && p.y >= 550 && p.y <= 570)) 
             {
             	 showbuttons = false;
                    displaybuttons(); 
             	clickedbutton(450, 470, 50, 400);
                delay(100);
                button(450, 470, 50, 400);
                logcondition = false;
                return "false";
            }

            delay(10);
        }
         if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                mousebuttondown = false;
            }
}
}

bool DLOGIN::checkdata(const char* user, const char* pass) {
    ifstream fin;
    fin.open("doctor.bin", ios::in | ios::binary);
    
    if (!fin) {
        cerr << "Error opening file" << endl;
        return false;
    }

    char fileid[50];
    char filepassword[100];

    while (fin.peek() != EOF) {
        memset(fileid, '\0', sizeof(fileid));
        memset(filepassword, '\0', sizeof(filepassword));

        fin.getline(fileid, sizeof(fileid), '\0');
        fin.ignore(numeric_limits<std::streamsize>::max(), '\0'); // Skip the name
        fin.getline(filepassword, sizeof(filepassword), '\0');

        if (strcmp(user, fileid) == 0 && strcmp(pass, filepassword) == 0) {
            fin.close();
            return true;
        }

        fin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Skip the rest of the record
    }

    fin.close();
    return false;
}


void DLOGIN::displaybuttons() {
        if (showbuttons) {
           setcolor(RED);
           setbkcolor(LIGHTGRAY);
		   settextstyle(4,0,1);
           outtextxy(1000,35,"Doctor");
            outtextxy(1000,60,"(not logged in)");
        } else {
            setfillstyle(1,LIGHTGRAY);
            bar(1000, 0, 1200, 100);
        }
    }
   
