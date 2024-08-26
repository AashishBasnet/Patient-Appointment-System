#include "admin.h"
#include "layouts.h"
#include <graphics.h>
#include<cstring>
#include<ctime>
#include<iostream>
#include<fstream>
#include<map>
#include "cursorinput.h"
using namespace std;

void ADMIN::homestructure() {
setfillstyle(1,15);
bar(0,0,1280,720);
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
setfillstyle(1,3);
bar(0,100,150,720);
settextstyle(4,0,1);
setbkcolor(CYAN);
setcolor(RED);
outtextxy(30,650,"Logout");
setcolor(15);
outtextxy(25,180,"old");
outtextxy(25,200,"records");

outtextxy(25,250,"Patient");
outtextxy(25,270,"record");
outtextxy(25,350,"Doctor");
outtextxy(25,370,"record");
outtextxy(25,450,"Add new");
outtextxy(25,470,"Doctor");
outtextxy(25,550,"Doctor");
outtextxy(25,570,"Daily");
outtextxy(25,590,"Report");
setcolor(15);
line(750,75,760,100);
setbkcolor(LIGHTGRAY);
setcolor(CYAN);
settextstyle(1,0,2);
outtextxy(140,30,"PATIENT");
outtextxy(140,60,"APPOINTMENT SYSTEM");
setcolor(CYAN);
setbkcolor(LIGHTGRAY);
}

bool ADMIN::click() {
	ptrecords(1);
	showButtons=false;
	condition= true;
   while (condition) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !mouseButtonDown) {
                mouseButtonDown = true;

  // Check if the click is user icon
                if (p.x >= 1202 && p.x <= 1250 && p.y >= 30 && p.y <= 80) {
                    showButtons = !showButtons;
                    displayButtons();
                }
                
                                // ptrecords
                if (p.x >= 25 && p.x <= 130 && p.y >= 250 && p.y <= 290) {
                    showButtons = false;
                    displayButtons(); 
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    setbkcolor(LIGHTGRAY);
                    bar(550,76,760,85);
                    ptrecords(1);
                    ptrecordclick();
                }                                                                                   
                
                //dtrecords
                if (p.x >= 25 && p.x <= 120 && p.y >= 350 && p.y <= 390) {
                	app:
                    showButtons = false;
                    displayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    setbkcolor(LIGHTGRAY);
                    bar(550,76,760,85);
                    dtrecords(1);
                    dtrecordclick();
                }
                
                //addnew doctors
                if (p.x >= 25 && p.x <= 140 && p.y >= 450 && p.y <= 490) {
                    showButtons = false;
                    displayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                     setbkcolor(LIGHTGRAY);
                    bar(550,76,760,85);
                    dsignup();
                    int a = signupclick();
                    if(a==1)
                    {
                    	int b= selectdepartment();
                    	if(b==1)
                    	{ 
						    printfile();
                    		dtrecords(1);
						}
					}
                    
                }
                
                                //dtdailyreport
                if (p.x >= 25 && p.x <= 120 && p.y >= 550 && p.y <= 610) {
                	up:
                    showButtons = false;
                    displayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    setbkcolor(LIGHTGRAY);
                    bar(550,76,760,85);
                    seerecords();
                    int a = seerecordsclick();
                    if(a==1)
                    {
                       int b = reporttable();
					   int c= reporttableclick(b);	
					   if(c==1)
					   {
					   	goto up;
					   }
					   else
					   {
					   	continue;
					   }
					}
					else
					{
						continue;
					}
                }
                
              
                //view old patient records
                 if (p.x >= 25 && p.x <= 130 && p.y >=180 && p.y <= 220) {
                 	oldup:
                    showButtons = false;
                    displayButtons(); 
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    setbkcolor(LIGHTGRAY);
                    bar(550,76,760,85);
                    viewoldrecords();
                    int a = viewoldrecordsclick();
                    if(a==1)
                    {
                    	int b = oldrectable();
                    		if(b==1)
                    		{
                    			goto oldup;
							}
							else
							{
								continue;
							}
					}
					else
					{
						continue;
					}	
                }                
                
                                //logout
                if (p.x >= 25 && p.x <= 115 && p.y >= 650 && p.y <= 690) {
                    showButtons = false;
                    displayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    setbkcolor(LIGHTGRAY);
                    bar(550,76,755,85);
                    condition=false;
                    return false;
                }
            } 

            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                mouseButtonDown = false;
            }
        }
}


    void ADMIN::seerecords()  {
    	 setfillstyle(SOLID_FILL, WHITE);
    bar(151, 101, 1280, 720);
    	 time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    int today = localTime->tm_mday;
    int tomonth = localTime->tm_mon + 1;
    int toyear = localTime->tm_year + 1900;
      memset(ch_today, 0, sizeof(ch_today));
    sprintf(ch_today, "%d-%02d-%02d", toyear, tomonth, today);
	hdbox(170,120,570,1050);
	 setfillstyle(1,LIGHTGRAY);
	  bar(570,77,720,97);
		setbkcolor(LIGHTGRAY);
    settextstyle(4, 0, 2);
    setcolor(CYAN);
    outtextxy(580, 77, "  Records");
setcolor(RED);
setbkcolor(3);
outtextxy(210,130,"Patient Record:");
setbkcolor(15);
setcolor(BLUE);
outtextxy(220,170,"select a department:");
outtextxy(220,410,"select a shift:");

          colored_button(350,240,50,200,LIGHTBLUE);
          colored_button(350,300,50,200,LIGHTBLUE);
          colored_button(570,240,50,200,LIGHTBLUE);
          colored_button(570,300,50,200,LIGHTBLUE);
          colored_button(790,240,50,200,LIGHTBLUE);
          colored_button(790,300,50,200,LIGHTBLUE);
          colored_button(350,480,50,200,LIGHTRED);
          colored_button(570,480,50,200,LIGHTRED);
          colored_button(790,480,50,200,LIGHTRED);
          button(480,580,50,400);   
    settextstyle(4, 0, 2);
    setbkcolor(CYAN);
    setcolor(15);
    outtextxy(590, 590, "See Records");
    setbkcolor(LIGHTBLUE);
    outtextxy(380, 245, "General");
     outtextxy(380, 265, "medicine");
     outtextxy(360,310,"Opthalmology");
      outtextxy(630, 250, "ENT");
       outtextxy(595, 310, "Cardiology");
         outtextxy(835, 245, "Gastro");
     outtextxy(825, 265, "Surgery");
       outtextxy(835, 305, "Neuro");
     outtextxy(825, 325, "Medicine");
     setbkcolor(LIGHTRED);
     outtextxy(390, 490, "Morning");
     outtextxy(605, 490, "Afternoon");
      outtextxy(835, 490, "Evening");
     setbkcolor(LIGHTGRAY);
}



int ADMIN::seerecordsclick() {
    memset(selectdep, 0, sizeof(selectdep));
    memset(selecttime, 0, sizeof(selecttime));
    mousebtn = false;
    showButtons = false;
    srcondition = true;
    bool mousePressed = false;

    while (srcondition) {
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(GetForegroundWindow(), &p);

        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            mousePressed = true;  
        }

        
        if (mousePressed && !(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
            mousePressed = false;  

            // User icon click
            if (p.x >= 1202 && p.x <= 1250 && p.y >= 30 && p.y <= 80) {
                showButtons = !showButtons;
                displayButtons();
            }

            // General medicine
            if (p.x >= 350 && p.x <= 550 && p.y >= 240 && p.y <= 290) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(350, 240, 50, 200, LIGHTBLUE);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(350, 240, 50, 200, LIGHTBLUE);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTBLUE);
                setcolor(15);
                outtextxy(380, 245, "General");
                outtextxy(380, 265, "medicine");
                strcpy(selectdep, "general medicine");
                delay(100);
            }

            // ENT
            if (p.x >= 570 && p.x <= 770 && p.y >= 240 && p.y <= 290) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(570, 240, 50, 200, LIGHTBLUE);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(570, 240, 50, 200, LIGHTBLUE);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTBLUE);
                setcolor(15);
                outtextxy(630, 250, "ENT");
                strcpy(selectdep, "ent");
                delay(100);
            }

            // Ophthalmology
            if (p.x >= 350 && p.x <= 550 && p.y >= 300 && p.y <= 350) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(350, 300, 50, 200, LIGHTBLUE);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(350, 300, 50, 200, LIGHTBLUE);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTBLUE);
                setcolor(15);
                outtextxy(360, 310, "Opthalmology");
                strcpy(selectdep, "opthalmology");
                cout << selectdep << endl;
                delay(100);
            }

            // Neuro
            if (p.x >= 790 && p.x <= 990 && p.y >= 300 && p.y <= 350) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(790, 300, 50, 200, LIGHTBLUE);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(790, 300, 50, 200, LIGHTBLUE);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTBLUE);
                setcolor(15);
                outtextxy(835, 305, "Neuro");
                outtextxy(825, 325, "Medicine");
                strcpy(selectdep, "neuro medicine");
                cout << selectdep << endl;
                delay(100);
            }

            // Gastro surgery
            if (p.x >= 790 && p.x <= 990 && p.y >= 240 && p.y <= 290) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(790, 240, 50, 200, LIGHTBLUE);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(790, 240, 50, 200, LIGHTBLUE);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTBLUE);
                setcolor(15);
                outtextxy(835, 245, "Gastro");
                outtextxy(825, 265, "Surgery");
                strcpy(selectdep, "gastro surgery");
                cout << selectdep << endl;
                delay(100);
            }

            // Cardiology
            if (p.x >= 570 && p.x <= 770 && p.y >= 300 && p.y <= 350) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(570, 300, 50, 200, LIGHTBLUE);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(570, 300, 50, 200, LIGHTBLUE);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTBLUE);
                setcolor(15);
                outtextxy(595, 310, "Cardiology");
                strcpy(selectdep, "cardiology");
                cout << selectdep << endl;
                delay(100);
            }

            // Morning
            if (p.x >= 350 && p.x <= 550 && p.y >= 480 && p.y <= 530) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(350, 480, 50, 200, LIGHTRED);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(350, 480, 50, 200, LIGHTRED);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTRED);
                setcolor(15);
                outtextxy(390, 490, "Morning");
                strcpy(selecttime, "7:00-11:00");
                cout << selecttime << endl;
                delay(100);
            }

            // Afternoon
            if (p.x >= 570 && p.x <= 770 && p.y >= 480 && p.y <= 530) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(570, 480, 50, 200, LIGHTRED);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(570, 480, 50, 200, LIGHTRED);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTRED);
                setcolor(15);
                outtextxy(605, 490, "Afternoon");
                strcpy(selecttime, "12:00-2:30");
                cout << selecttime << endl;
                delay(100);
            }

            // Evening
            if (p.x >= 790 && p.x <= 990 && p.y >= 480 && p.y <= 530) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(790, 480, 50, 200, LIGHTRED);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(790, 480, 50, 200, LIGHTRED);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTRED);
                setcolor(15);
                outtextxy(835, 490, "Evening");
                strcpy(selecttime, "3:15-5:00");
                cout << selecttime << endl;
                delay(100);
            }

            // See record button
            if (p.x >= 480 && p.x <= 880 && p.y >= 580 && p.y <= 630) {
                	showButtons = false;
                displayButtons(); 
               	clickedbutton(480,580,50,400);
               	setbkcolor(WHITE);
               	setfillstyle(1,WHITE);
               	bar(478,553,1000,570);
               	delay(50);
              button(480,580,50,400);   
             settextstyle(4, 0, 2);
             setbkcolor(CYAN);
             setcolor(15);
              outtextxy(590, 590, "See Records");
              if(strlen(selectdep)==0 || strlen(selecttime)==0)
              {
              	setfillstyle(1,15);
              	bar(480,550,800,572);
              	setbkcolor(15);
              	setcolor(RED);
              	outtextxy(480,550,"*Select a department and shift");
			  }
			  else
			  {
			  	srcondition=false;
			  	return 1;
			  }
            }
            
            	if ((p.x >= 25 && p.x <= 130 && p.y >=180 && p.y <= 220) || (p.x >= 25 && p.x <= 130 && p.y >= 250 && p.y <= 290) || (p.x >= 25 && p.x <= 120 && p.y >= 350 && p.y <= 390) || (p.x >= 25 && p.x <= 140 && p.y >= 450 && p.y <= 490) || (p.x >= 25 && p.x <= 115 && p.y >= 650 && p.y <= 690)) {
                srcondition = false;
                return 2;
            }
            
        }

        delay(50);
    }

}

    int ADMIN::reporttable()  {
    	
  setfillstyle(SOLID_FILL, WHITE);
    bar(151, 101, 1280, 720);
     int ycoord,zcoord ;
	 zcoord=ycoord= 320;
     char present_or_absent[50],present_or_absent2[50];

      int tkarr[50];
            int initializer=0, count=0;
            char dfirstName[50], ddepartment[50], ddate[50], dtimeSlot[50], dtkno[50];
            		  
    char ouserId[50], ofirstName[50], ophoneNumber[50], odepartment[50], odate[50], otimeSlot[50], otkno[50], ostatus[50]; 
    bool status_old = false;
    bool status_docreport= false;
    
     char auserId[50], afirstName[50], aphoneNumber[50], adepartment[50], adate[50], atimeSlot[50], atkno[50];
char p_or_a_status[50];	
bool status_found=false; 

    ifstream oldrecfile("oldrec.bin", ios::in | ios::binary);
    if (!oldrecfile) {
        cerr << "Error opening oldrec.bin file" << endl;
    }
      string orecord;
      oldrecfile.seekg(0,ios::beg);
    while (getline(oldrecfile, orecord, '\n')) {
        stringstream recordStream(orecord);
        recordStream.getline(ouserId, sizeof(ouserId), '\0');
        recordStream.getline(ofirstName, sizeof(ofirstName), '\0');
        recordStream.getline(otkno, sizeof(otkno), '\0');
        recordStream.getline(ophoneNumber, sizeof(ophoneNumber), '\0');
        recordStream.getline(odepartment, sizeof(odepartment), '\0');
        recordStream.getline(odate, sizeof(odate), '\0');
        recordStream.getline(otimeSlot, sizeof(otimeSlot), '\0');
        recordStream.getline(ostatus, sizeof(ostatus), '\0');
      

        if (strcmp(odepartment, selectdep) == 0 && strcmp(otimeSlot, selecttime) == 0 && (strcmp(odate,ch_today)==0)) {
            status_old = true;
            break;
        }
    }
    oldrecfile.close();


    if(status_old==true)
    {

     ifstream oldrecfile("oldrec.bin", ios::in | ios::binary);
    if (!oldrecfile) {
        cerr << "Error opening oldrec.bin file" << endl;
    }
    
      oldrecfile.seekg(0,ios::beg);
    while (getline(oldrecfile, orecord, '\n')) {
        stringstream recordStream(orecord);
        recordStream.getline(ouserId, sizeof(ouserId), '\0');
        recordStream.getline(ofirstName, sizeof(ofirstName), '\0');
        recordStream.getline(otkno, sizeof(otkno), '\0');
        recordStream.getline(ophoneNumber, sizeof(ophoneNumber), '\0');
        recordStream.getline(odepartment, sizeof(odepartment), '\0');
        recordStream.getline(odate, sizeof(odate), '\0');
        recordStream.getline(otimeSlot, sizeof(otimeSlot), '\0');
        recordStream.getline(ostatus, sizeof(ostatus), '\0');

        if (strcmp(odepartment, selectdep) == 0 && strcmp(otimeSlot, selecttime) == 0 && strcmp(odate,ch_today)==0) {
        	
                     if (strcmp(ostatus, "true") == 0) {
                    strcpy(present_or_absent, "Attended");
                    setcolor(CYAN);
                } else {
                    strcpy(present_or_absent, "Not Attended");
                    setcolor(RED);
                }
                hdbox(170, 120, 570, 1050);
         setcolor(RED);
    setbkcolor(3);
    outtextxy(210, 130, "Patient's attendance:");
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, 2);
    rectangle(200, 270, 1180, 580);
    line(200, 310, 1180, 310);
    line(360, 271, 360, 580);
    line(920, 271, 920, 580);
    setbkcolor(WHITE);
      setcolor(0);
    outtextxy(380, 185, selectdep);
    outtextxy(900, 185, ch_today);
    outtextxy(300, 220, selecttime);
    setcolor(BLUE);
    setbkcolor(WHITE);
    outtextxy(200, 185, "Department:");
    outtextxy(800, 185, "Date:");
    outtextxy(200, 220, "Shift:");
    outtextxy(210, 280, "Token no");
    outtextxy(555, 280, "Patient's Name");
    outtextxy(950, 280, "Status");
    setcolor(15);
    setbkcolor(LIGHTBLUE);
    outtextxy(597, 640, "Confirm >");
    colored_button(530, 625, 50, 300, LIGHTBLUE);
                setbkcolor(15);
                setcolor(0);
                outtextxy(220, ycoord, otkno);           
                outtextxy(375, ycoord, ofirstName);   
				if(strcmp(present_or_absent, "Not Attended")==0)   
				{ setcolor(RED);
                outtextxy(950, ycoord, present_or_absent);
            }
            		if(strcmp(present_or_absent, "Not Attended")!=0)   
				{ setcolor(BLUE);
                outtextxy(950, ycoord, present_or_absent);
            }
                ycoord += 20;
        }
    }

    oldrecfile.close();
    return 1;
	}
	else
	{
		 ifstream docrecfile("ptapprec.bin", ios::in | ios::binary);
            docrecfile.seekg(0, ios::beg);
            if (!docrecfile) {
             cerr << "Error opening file" << endl;
			}
            string drecord;
            while (getline(docrecfile, drecord, '\n')) {
            stringstream recordStream(drecord);
            recordStream.getline(dfirstName, sizeof(dfirstName), '\0');
            recordStream.getline(dtkno, sizeof(dtkno), '\0');
            recordStream.getline(ddepartment, sizeof(ddepartment), '\0');
            recordStream.getline(ddate, sizeof(ddate), '\0');
            recordStream.getline(dtimeSlot, sizeof(dtimeSlot), '\0'); 
                char extracted_date[3];
           strncpy(extracted_date, ddate + strlen(ddate) - 2, 2);
           extracted_date[2] = '\0'; 
           int extracted_dateInt = atoi(extracted_date);
           if((strcmp(ddepartment,selectdep)==0) && (strcmp(dtimeSlot,selecttime)==0) && (strcmp(ddate,ch_today)==0))
           {
            status_docreport=true;
            break;
           }
            } 
        docrecfile.close();
          if(status_docreport==true)
          {
          	 ifstream docrecfile("ptapprec.bin", ios::in | ios::binary);
            docrecfile.seekg(0, ios::beg);
            if (!docrecfile) {
              cerr << "Error opening file" << endl;	
            }
            while (getline(docrecfile, drecord, '\n')) {
            stringstream recordStream(drecord);
            recordStream.getline(dfirstName, sizeof(dfirstName), '\0');
            recordStream.getline(dtkno, sizeof(dtkno), '\0');
            recordStream.getline(ddepartment, sizeof(ddepartment), '\0');
            recordStream.getline(ddate, sizeof(ddate), '\0');
            recordStream.getline(dtimeSlot, sizeof(dtimeSlot), '\0'); 
                char extracted_date[3];
           strncpy(extracted_date, ddate + strlen(ddate) - 2, 2);
           extracted_date[2] = '\0'; 
           int extracted_dateInt = atoi(extracted_date);
           if((strcmp(ddepartment,selectdep)==0) && (strcmp(dtimeSlot,selecttime)==0) && (strcmp(ddate,ch_today)==0))
           {
              tkarr[initializer]= atoi(dtkno);
              initializer+=1;
             count+=1;
           }
            } 
        docrecfile.close();
        
         ifstream appointmentfile("appointments.bin", ios::in | ios::binary);
         if (!appointmentfile) {
    cerr << "Error opening appointments.bin file" << endl;
  }


        fstream newfile("oldrec.bin", ios::out | ios::app | ios::binary);
        if (!newfile) {
    cerr << "Error opening temp.bin file" << endl;
             }

        string arecord;
        int i ,tknum;

          appointmentfile.seekg(0, ios::beg);
        while (getline(appointmentfile, arecord, '\n')) {
        	i=0;
        	tknum=0;
            stringstream recordStream(arecord);
            recordStream.getline(auserId, sizeof(auserId), '\0');
            recordStream.getline(afirstName, sizeof(afirstName), '\0');
            recordStream.getline(atkno, sizeof(atkno), '\0');
            recordStream.getline(aphoneNumber, sizeof(aphoneNumber), '\0');
            recordStream.getline(adepartment, sizeof(adepartment), '\0');
            recordStream.getline(adate, sizeof(adate), '\0');
            recordStream.getline(atimeSlot, sizeof(atimeSlot), '\0');
            tknum= atoi(atkno);
            status_found=false;
    if(strcmp(adepartment,selectdep)==0 && strcmp(atimeSlot,selecttime)==0 && (strcmp(adate,ch_today)==0))
     {
     	for(i=0;i<count;i++)
     	{
     		if(tknum==tkarr[i]){
     		status_found=true;	
			 }
			 if(status_found==true)
			 {
			 	strcpy(p_or_a_status,"true");
			 	break;
			 }
		 }
		 if(!status_found)
		 {
		 	strcpy(p_or_a_status,"false");
		 }
        }
        
           newfile.seekp(0, ios::end);
            newfile.write( auserId, strlen( auserId) + 1);
    newfile.write(afirstName, strlen(afirstName) + 1);
  newfile.write(atkno, strlen(atkno) + 1);
    newfile.write(aphoneNumber, strlen(aphoneNumber) + 1);
                newfile.write(adepartment, strlen(adepartment) + 1);
                newfile.write(adate, strlen(adate) + 1);
               newfile.write(atimeSlot, strlen(atimeSlot) + 1);
               newfile.write(p_or_a_status, strlen(p_or_a_status) + 1);
             newfile.put('\n');   
              }
         appointmentfile.close();
         newfile.close();  
		 
     ifstream oldrecfile("oldrec.bin", ios::in | ios::binary);
    if (!oldrecfile) {
        cerr << "Error opening oldrec.bin file" << endl;
    }
  

      oldrecfile.seekg(0,ios::beg);
    while (getline(oldrecfile, orecord, '\n')) {
        stringstream recordStream(orecord);
        recordStream.getline(ouserId, sizeof(ouserId), '\0');
        recordStream.getline(ofirstName, sizeof(ofirstName), '\0');
        recordStream.getline(otkno, sizeof(otkno), '\0');
        recordStream.getline(ophoneNumber, sizeof(ophoneNumber), '\0');
        recordStream.getline(odepartment, sizeof(odepartment), '\0');
        recordStream.getline(odate, sizeof(odate), '\0');
        recordStream.getline(otimeSlot, sizeof(otimeSlot), '\0');
        recordStream.getline(ostatus, sizeof(ostatus), '\0');

        if (strcmp(odepartment, selectdep) == 0 && strcmp(otimeSlot, selecttime) == 0 && strcmp(odate,ch_today)==0) {
        	
                     if (strcmp(ostatus, "true") == 0) {
                    strcpy(present_or_absent2, "Attended");
                    setcolor(CYAN);
                } else {
                    strcpy(present_or_absent2, "Not Attended");
                    setcolor(RED);
                }
                hdbox(170, 120, 570, 1050);
         setcolor(RED);
    setbkcolor(3);
    outtextxy(210, 130, "Patient's attendance:");
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, 2);
    rectangle(200, 270, 1180, 580);
    line(200, 310, 1180, 310);
    line(360, 271, 360, 580);
    line(920, 271, 920, 580);
    setbkcolor(WHITE);
    setcolor(0);
    outtextxy(380, 185, selectdep);
    outtextxy(900, 185, ch_today);
    outtextxy(300, 220, selecttime);
    setcolor(BLUE);
    setbkcolor(WHITE);
    outtextxy(200, 185, "Department:");
    outtextxy(800, 185, "Date:");
    outtextxy(200, 220, "Shift:");
    outtextxy(210, 280, "Token no");
    outtextxy(555, 280, "Patient's Name");
    outtextxy(950, 280, "Status");
    setcolor(15);
    setbkcolor(LIGHTBLUE);
    outtextxy(597, 640, "Confirm >");
    colored_button(530, 625, 50, 300, LIGHTBLUE);
                setbkcolor(15);
                setcolor(0);
                outtextxy(220, zcoord, otkno);           
                outtextxy(375, zcoord, ofirstName);   
				if(strcmp(present_or_absent2, "Not Attended")==0)   
				{ setcolor(RED);
                outtextxy(950, zcoord, present_or_absent2);
            }
            		if(strcmp(present_or_absent2, "Not Attended")!=0)   
				{ setcolor(BLUE);
                outtextxy(950, zcoord, present_or_absent2);
            }
                zcoord += 20;
        }
    }

    oldrecfile.close();
	return 1;	 
    }
    else
    {
    
    	setfillstyle(SOLID_FILL, WHITE);
    bar(151, 101, 1280, 720);
        setlinestyle(0, 0, 2);
        dbox(350, 200, 400, 700);
        setcolor(BLUE);
        setbkcolor(15);
        settextstyle(4, 0, 3);
        setlinestyle(1, 0, 3);
        readimagefile("images/attention.jpg", 625, 220, 725, 320);
        outtextxy(450, 360, "The doctor has yet to give report");
        setcolor(0);
        setbkcolor(15);
        settextstyle(4, 0, 2);
        outtextxy(525, 410, " from the time you requested!");
        setcolor(15);
        setbkcolor(LIGHTBLUE);
        outtextxy(597, 640, "Confirm >");  
        colored_button(530, 625, 50, 300, LIGHTBLUE); 
        return 2;
	}
	}    
}




int ADMIN::reporttableclick(int st)
{

    char auserId[50], afirstName[50], aphoneNumber[50], adepartment[50], adate[50], atimeSlot[50], atkno[50];
    char dfirstName[50], ddepartment[50], ddate[50], dtimeSlot[50], dtkno[50];

    mousebtn = false;
    showButtons = false;
    srcondition = true;
    bool mousePressed = false;

    while (srcondition) {
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(GetForegroundWindow(), &p);

        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            mousePressed = true;  
        }

        if (mousePressed && !(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
            mousePressed = false;

            if (p.x >= 1202 && p.x <= 1250 && p.y >= 30 && p.y <= 80) {
                showButtons = !showButtons;
                displayButtons();
            }

            if (p.x >= 530 && p.x <= 830 && p.y >= 625 && p.y <= 675) { 
                showButtons = false;
                displayButtons();
                clicked_colored_button(530,625, 50, 300,LIGHTBLUE);
                delay(100);
                colored_button(530,625, 50, 300,LIGHTBLUE);
                settextstyle(4, 0, 2);
                setcolor(15);
                setbkcolor(LIGHTBLUE);
                outtextxy(597, 640, "Confirm >");
                
                if(st==1)
                {
                	  // First file operation: ptapprec.bin
                ifstream docrecfile("ptapprec.bin", ios::in | ios::binary);
                if (!docrecfile) {
                    cerr << "Error opening ptapprec.bin file" << endl;
                }

                fstream newfile1("temp1.bin", ios::out | ios::app | ios::binary);
                if (!newfile1) {
                    cerr << "Error opening temp1.bin file" << endl;
                }

                string drecord; 
                docrecfile.seekg(0, ios::beg);
                while (getline(docrecfile, drecord, '\n')) {
                    stringstream recordStream(drecord);
                    recordStream.getline(dfirstName, sizeof(dfirstName), '\0');
                    recordStream.getline(dtkno, sizeof(dtkno), '\0');
                    recordStream.getline(ddepartment, sizeof(ddepartment), '\0');
                    recordStream.getline(ddate, sizeof(ddate), '\0');
                    recordStream.getline(dtimeSlot, sizeof(dtimeSlot), '\0'); 
                

                    if ((strcmp(ddepartment, selectdep) == 0) && (strcmp(dtimeSlot, selecttime) == 0) && (strcmp(ddate,ch_today)==0)) {
                        continue;
                    }

                    newfile1.seekp(0, ios::end);
                    newfile1.write(dfirstName, strlen(dfirstName) + 1);
                    newfile1.write(dtkno, strlen(dtkno) + 1);
                    newfile1.write(ddepartment, strlen(ddepartment) + 1);
                    newfile1.write(ddate, strlen(ddate) + 1);
                    newfile1.write(dtimeSlot, strlen(dtimeSlot) + 1);
                    newfile1.put('\n');
                }
                docrecfile.close();
                newfile1.close();
                remove("ptapprec.bin");
                rename("temp1.bin", "ptapprec.bin");

                // Second file operation: appointments.bin
                ifstream appointmentfile("appointments.bin", ios::in | ios::binary);
                if (!appointmentfile) {
                    cerr << "Error opening appointments.bin file" << endl;
                    return -1;
                }

                fstream newfile2("temp2.bin", ios::out | ios::app | ios::binary);
                if (!newfile2) {
                    cerr << "Error opening temp2.bin file" << endl;
                    return -1;
                }

                string arecord;
                appointmentfile.seekg(0, ios::beg);
                while (getline(appointmentfile, arecord, '\n')) {
                    stringstream recordStream(arecord);
                    recordStream.getline(auserId, sizeof(auserId), '\0');
                    recordStream.getline(afirstName, sizeof(afirstName), '\0');
                    recordStream.getline(atkno, sizeof(atkno), '\0');
                    recordStream.getline(aphoneNumber, sizeof(aphoneNumber), '\0');
                    recordStream.getline(adepartment, sizeof(adepartment), '\0');
                    recordStream.getline(adate, sizeof(adate), '\0');
                    recordStream.getline(atimeSlot, sizeof(atimeSlot), '\0');

                    if (strcmp(adepartment, selectdep) == 0 && strcmp(atimeSlot, selecttime) == 0 && (strcmp(adate,ch_today)==0)) {
                        continue;
                    }

                    newfile2.seekp(0, ios::end);
                    newfile2.write(auserId, strlen(auserId) + 1);
                    newfile2.write(afirstName, strlen(afirstName) + 1);
                    newfile2.write(atkno, strlen(atkno) + 1);
                    newfile2.write(aphoneNumber, strlen(aphoneNumber) + 1);
                    newfile2.write(adepartment, strlen(adepartment) + 1);
                    newfile2.write(adate, strlen(adate) + 1);
                    newfile2.write(atimeSlot, strlen(atimeSlot) + 1);
                    newfile2.put('\n');
                }
                appointmentfile.close();
                newfile2.close();
                remove("appointments.bin");
                rename("temp2.bin", "appointments.bin");
                 srcondition = false;
                return 1;
				}
				else
				{
				srcondition = false;
                return 1;
				}
            }

            if ((p.x >= 25 && p.x <= 130 && p.y >=180 && p.y <= 220) || (p.x >= 25 && p.x <= 130 && p.y >= 250 && p.y <= 290) || (p.x >= 25 && p.x <= 120 && p.y >= 350 && p.y <= 390) || (p.x >= 25 && p.x <= 140 && p.y >= 450 && p.y <= 490) || (p.x >= 25 && p.x <= 115 && p.y >= 650 && p.y <= 690)) {
                srcondition = false;
                return 2;
            }
        }

        delay(50);
    }
}


    void ADMIN::viewoldrecords()  {
    		setfillstyle(1,WHITE);
    bar(151,101,1280,720);
	hdbox(170,120,570,1050);
		setbkcolor(LIGHTGRAY);
    settextstyle(4, 0, 2);
    setcolor(CYAN);
    outtextxy(580, 77, "  Records");
setcolor(RED);
setbkcolor(3);
outtextxy(210,130,"Patient Record:");
setbkcolor(15);
setcolor(BLUE);
outtextxy(220,170,"select a department:");
outtextxy(1050,200,"Enter a");
outtextxy(1050,220,"date:");
outtextxy(220,410,"select a shift:");
setcolor(DARKGRAY);
settextstyle(1,0,1);
outtextxy(1040,250,"Year:");
textfield(1040,270,50,160);
outtextxy(1040,340,"month:");
textfield(1040,360,50,160);
outtextxy(1040,420,"day:");
textfield(1040,440,50,160);
          colored_button(350,240,50,200,LIGHTBLUE);
          colored_button(350,300,50,200,LIGHTBLUE);
          colored_button(570,240,50,200,LIGHTBLUE);
          colored_button(570,300,50,200,LIGHTBLUE);
          colored_button(790,240,50,200,LIGHTBLUE);
          colored_button(790,300,50,200,LIGHTBLUE);
          colored_button(350,480,50,200,LIGHTRED);
          colored_button(570,480,50,200,LIGHTRED);
          colored_button(790,480,50,200,LIGHTRED);
          button(480,580,50,400);   
    settextstyle(4, 0, 2);
    setbkcolor(CYAN);
    setcolor(15);
    outtextxy(590, 590, "See Records");
    setbkcolor(LIGHTBLUE);
    outtextxy(380, 245, "General");
     outtextxy(380, 265, "medicine");
     outtextxy(360,310,"Opthalmology");
      outtextxy(630, 250, "ENT");
       outtextxy(595, 310, "Cardiology");
         outtextxy(835, 245, "Gastro");
     outtextxy(825, 265, "Surgery");
       outtextxy(835, 305, "Neuro");
     outtextxy(825, 325, "Medicine");
     setbkcolor(LIGHTRED);
     outtextxy(390, 490, "Morning");
     outtextxy(605, 490, "Afternoon");
      outtextxy(835, 490, "Evening");
     setbkcolor(LIGHTGRAY);
}


int ADMIN::viewoldrecordsclick()
{
	memset(selectdep, 0, sizeof(selectdep));
    memset(selecttime, 0, sizeof(selecttime));
    memset(selectyear, 0, sizeof(selectyear));
    memset(selectmonth, 0, sizeof(selectmonth));
    memset(selectday, 0, sizeof(selectday));
    mousebtn = false;
    showButtons = false;
    srcondition = true;
    bool mousePressed = false;

    while (srcondition) {
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(GetForegroundWindow(), &p);

        // Check if the left mouse button is pressed
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            mousePressed = true;  
        }

        
        if (mousePressed && !(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
            mousePressed = false;  

            // User icon click
            if (p.x >= 1202 && p.x <= 1250 && p.y >= 30 && p.y <= 80) {
                showButtons = !showButtons;
                displayButtons();
            }

            // General medicine
            if (p.x >= 350 && p.x <= 550 && p.y >= 240 && p.y <= 290) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(350, 240, 50, 200, LIGHTBLUE);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(350, 240, 50, 200, LIGHTBLUE);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTBLUE);
                setcolor(15);
                outtextxy(380, 245, "General");
                outtextxy(380, 265, "medicine");
                strcpy(selectdep, "general medicine");
                delay(100);
            }

            // ENT
            if (p.x >= 570 && p.x <= 770 && p.y >= 240 && p.y <= 290) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(570, 240, 50, 200, LIGHTBLUE);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(570, 240, 50, 200, LIGHTBLUE);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTBLUE);
                setcolor(15);
                outtextxy(630, 250, "ENT");
                strcpy(selectdep, "ent");
                delay(100);
            }

            // Ophthalmology
            if (p.x >= 350 && p.x <= 550 && p.y >= 300 && p.y <= 350) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(350, 300, 50, 200, LIGHTBLUE);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(350, 300, 50, 200, LIGHTBLUE);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTBLUE);
                setcolor(15);
                outtextxy(360, 310, "Opthalmology");
                strcpy(selectdep, "opthalmology");
                delay(100);
            }

            // Neuro
            if (p.x >= 790 && p.x <= 990 && p.y >= 300 && p.y <= 350) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(790, 300, 50, 200, LIGHTBLUE);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(790, 300, 50, 200, LIGHTBLUE);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTBLUE);
                setcolor(15);
                outtextxy(835, 305, "Neuro");
                outtextxy(825, 325, "Medicine");
                strcpy(selectdep, "neuro");
                delay(100);
            }

            // Gastro surgery
            if (p.x >= 790 && p.x <= 990 && p.y >= 240 && p.y <= 290) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(790, 240, 50, 200, LIGHTBLUE);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(790, 240, 50, 200, LIGHTBLUE);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTBLUE);
                setcolor(15);
                outtextxy(835, 245, "Gastro");
                outtextxy(825, 265, "Surgery");
                strcpy(selectdep, "gastro surgery");
                delay(100);
            }

            // Cardiology
            if (p.x >= 570 && p.x <= 770 && p.y >= 300 && p.y <= 350) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(570, 300, 50, 200, LIGHTBLUE);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(570, 300, 50, 200, LIGHTBLUE);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTBLUE);
                setcolor(15);
                outtextxy(595, 310, "Cardiology");
                strcpy(selectdep, "cardiology");
                delay(100);
            }

            // Morning
            if (p.x >= 350 && p.x <= 550 && p.y >= 480 && p.y <= 530) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(350, 480, 50, 200, LIGHTRED);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(350, 480, 50, 200, LIGHTRED);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTRED);
                setcolor(15);
                outtextxy(390, 490, "Morning");
                strcpy(selecttime, "7:00-11:00");
                delay(100);
            }

            // Afternoon
            if (p.x >= 570 && p.x <= 770 && p.y >= 480 && p.y <= 530) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(570, 480, 50, 200, LIGHTRED);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(570, 480, 50, 200, LIGHTRED);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTRED);
                setcolor(15);
                outtextxy(605, 490, "Afternoon");
                strcpy(selecttime, "12:00-2:30");
                delay(100);
            }

            // Evening
            if (p.x >= 790 && p.x <= 990 && p.y >= 480 && p.y <= 530) {
                showButtons = false;
                displayButtons();
                clicked_colored_button(790, 480, 50, 200, LIGHTRED);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                delay(50);
                colored_button(790, 480, 50, 200, LIGHTRED);
                settextstyle(4, 0, 2);
                setbkcolor(LIGHTRED);
                setcolor(15);
                outtextxy(835, 490, "Evening");
                strcpy(selecttime, "3:15-5:00");
                delay(100);
            }
            
              //year
                if (p.x >= 1040 && p.x <= 1200 && p.y >= 270 && p.y <= 320) {
                showButtons = false;
                displayButtons();
                clickedtextfield(1040, 270, 50, 160);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                text_input(1040, 270, 50, 160, selectyear);
            }


            //month
                if (p.x >= 1040 && p.x <= 1200 && p.y >= 360 && p.y <= 410) {
                showButtons = false;
                displayButtons();
                clickedtextfield(1040, 360, 50, 160);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                text_input(1040, 360, 50, 160, selectmonth);
            }
            
            
            //day
                if (p.x >= 1040 && p.x <= 1200 && p.y >= 440 && p.y <= 490) {
                showButtons = false;
                displayButtons();
                clickedtextfield(1040, 440, 50, 160);
                setbkcolor(WHITE);
                setfillstyle(1, WHITE);
                bar(478, 553, 1000, 570);
                text_input(1040, 440, 50, 160, selectday);
            }


            // See record button
            if (p.x >= 480 && p.x <= 880 && p.y >= 580 && p.y <= 630) {
                	showButtons = false;
                displayButtons(); 
               	clickedbutton(480,580,50,400);
               	setbkcolor(WHITE);
               	setfillstyle(1,WHITE);
               	bar(478,553,1000,570);
               	delay(50);
              button(480,580,50,400);   
             settextstyle(4, 0, 2);
             setbkcolor(CYAN);
             setcolor(15);
              outtextxy(590, 590, "See Records");
              if(strlen(selectdep)==0 || strlen(selecttime)==0 || strlen(selectyear)==0 || strlen(selectday)==0 || strlen(selectmonth)==0)
              {
              	setfillstyle(1,15);
              	bar(480,550,800,572);
              	setcolor(RED);
              	setbkcolor(15);
              	outtextxy(480,550,"*Select a department and shift");
			  }
			  else
			  {
			  	srcondition=false;
			  	return 1;
			  }
            }
            
            	if ((p.x >= 25 && p.x <= 120 && p.y >= 550 && p.y <= 610) || (p.x >= 25 && p.x <= 130 && p.y >= 250 && p.y <= 290) || (p.x >= 25 && p.x <= 120 && p.y >= 350 && p.y <= 390) || (p.x >= 25 && p.x <= 140 && p.y >= 450 && p.y <= 490) || (p.x >= 25 && p.x <= 115 && p.y >= 650 && p.y <= 690)) {
                srcondition = false;
                return 2;
            }
            
        }

        delay(50);
    }
 } 
 
 
int ADMIN::oldrectable() {
    int ycoord = 320;
    char p_or_a_status[50];
    
    char ouserId[50], ofirstName[50], ophoneNumber[50], odepartment[50], odate[50], otimeSlot[50], otkno[50], ostatus[50]; 
    bool status_old = false;
    char finaldate[11]; 
    
    memset(finaldate, 0, sizeof(finaldate));
    sprintf(finaldate, "%s-%s-%s", selectyear, selectmonth, selectday);

    ifstream oldrecfile("oldrec.bin", ios::in | ios::binary);
    if (!oldrecfile) {
        cerr << "Error opening oldrec.bin file" << endl;
        return -1; 
    }

    string orecord;
    while (getline(oldrecfile, orecord, '\n')) {
        stringstream recordStream(orecord);
        recordStream.getline(ouserId, sizeof(ouserId), '\0');
        recordStream.getline(ofirstName, sizeof(ofirstName), '\0');
        recordStream.getline(otkno, sizeof(otkno), '\0');
        recordStream.getline(ophoneNumber, sizeof(ophoneNumber), '\0');
        recordStream.getline(odepartment, sizeof(odepartment), '\0');
        recordStream.getline(odate, sizeof(odate), '\0');
        recordStream.getline(otimeSlot, sizeof(otimeSlot), '\0');
        recordStream.getline(ostatus, sizeof(ostatus), '\0');

        if (strcmp(odepartment, selectdep) == 0 && strcmp(otimeSlot, selecttime) == 0 && strcmp(odate, finaldate) == 0) {
            status_old = true;
            break;
        }
    }

    oldrecfile.close();

    if (status_old) {
        // Print the data
        ifstream oldrecfile("oldrec.bin", ios::in | ios::binary);
        if (!oldrecfile) {
            cerr << "Error opening oldrec.bin file" << endl;
            return -1;
        }

        setfillstyle(1, WHITE);
        bar(151, 101, 1280, 720);   
        hdbox(170, 120, 570, 1050);
        setcolor(RED);
        setbkcolor(3);
        outtextxy(210, 130, "Patient's attendance:");
        setcolor(LIGHTGRAY);
        setlinestyle(0, 0, 2);
        rectangle(200, 270, 1180, 580);
        line(200, 310, 1180, 310);
        line(360, 271, 360, 580);
        line(920, 271, 920, 580);

        while (getline(oldrecfile, orecord, '\n')) {
            stringstream recordStream(orecord);
            recordStream.getline(ouserId, sizeof(ouserId), '\0');
            recordStream.getline(ofirstName, sizeof(ofirstName), '\0');
            recordStream.getline(otkno, sizeof(otkno), '\0');
            recordStream.getline(ophoneNumber, sizeof(ophoneNumber), '\0');
            recordStream.getline(odepartment, sizeof(odepartment), '\0');
            recordStream.getline(odate, sizeof(odate), '\0');
            recordStream.getline(otimeSlot, sizeof(otimeSlot), '\0');
            recordStream.getline(ostatus, sizeof(ostatus), '\0');

            if (strcmp(odepartment, selectdep) == 0 && strcmp(otimeSlot, selecttime) == 0 && strcmp(odate, finaldate) == 0) {
                // Determine status
                if (strcmp(ostatus, "true") == 0) {
                    strcpy(p_or_a_status, "Attended");
                    setcolor(CYAN);
                } else {
                    strcpy(p_or_a_status, "Not Attended");
                    setcolor(RED);
                }
                setbkcolor(15);
                setcolor(0);
                outtextxy(220, ycoord, otkno);           
                outtextxy(375, ycoord, ofirstName);   
				if(strcmp(p_or_a_status, "Not Attended")==0)   
				{ setcolor(RED);
                outtextxy(950, ycoord, p_or_a_status);
            }
            		if(strcmp(p_or_a_status, "Not Attended")!=0)   
				{ setcolor(BLUE);
                outtextxy(950, ycoord, p_or_a_status);
            }
                ycoord += 20;
            }
        }

        oldrecfile.close();

        // Display additional information
        setcolor(0);
        setbkcolor(15);
        outtextxy(380, 185, selectdep);
        outtextxy(900, 185, finaldate);
        outtextxy(300, 220, selecttime);
        setcolor(BLUE);
        outtextxy(200, 185, "Department:");
        outtextxy(800, 185, "Date:");
        outtextxy(200, 220, "shift:");
        outtextxy(210, 280, "Token no");
        outtextxy(555, 280, "Patient's Name");
        outtextxy(950, 280, "Status");
        setcolor(15);
        setbkcolor(LIGHTBLUE);
        outtextxy(597, 640, "Confirm >");
        colored_button(530, 625, 50, 300, LIGHTBLUE);

        return oldrectableclick();
    } else {
        // Handle no data case
        setfillstyle(1, WHITE);
        bar(151, 101, 1280, 720); 
        setlinestyle(0, 0, 2);
        dbox(350, 200, 400, 700);
        setcolor(BLUE);
        setbkcolor(15);
        settextstyle(4, 0, 3);
        setlinestyle(1, 0, 3);
        readimagefile("images/attention.jpg", 625, 220, 725, 320);
        outtextxy(530, 360, "There is no any data");
        setcolor(0);
        setbkcolor(15);
        settextstyle(4, 0, 2);
        outtextxy(500, 410, " from the time you requested!");
        setcolor(15);
        setbkcolor(LIGHTBLUE);
        outtextxy(597, 640, "Confirm >");
        colored_button(530, 625, 50, 300, LIGHTBLUE); 

        return oldrectableclick();
    }
}




int ADMIN::oldrectableclick()
{
    mousebtn = false;
    showButtons = false;
    srcondition = true;
    bool mousePressed = false;

    while (srcondition) {
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(GetForegroundWindow(), &p);

        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            mousePressed = true;  
        }

        if (mousePressed && !(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
            mousePressed = false;

            if (p.x >= 1202 && p.x <= 1250 && p.y >= 30 && p.y <= 80) {
                showButtons = !showButtons;
                displayButtons();
            }

            if (p.x >= 530 && p.x <= 830 && p.y >= 625 && p.y <= 675) { 
                showButtons = false;
                displayButtons();
                clicked_colored_button(530,625, 50, 300,LIGHTBLUE);
                delay(100);
                colored_button(530,625, 50, 300,LIGHTBLUE);
                settextstyle(4, 0, 2);
                setcolor(15);
                setbkcolor(LIGHTBLUE);
                outtextxy(597, 640, "Confirm >");
                srcondition = false;
                return 1;
            }

            if ((p.x >= 25 && p.x <= 120 && p.y >= 550 && p.y <= 610) || (p.x >= 25 && p.x <= 130 && p.y >= 250 && p.y <= 290) || (p.x >= 25 && p.x <= 120 && p.y >= 350 && p.y <= 390) || (p.x >= 25 && p.x <= 140 && p.y >= 450 && p.y <= 490) || (p.x >= 25 && p.x <= 115 && p.y >= 650 && p.y <= 690)) {
                srcondition = false;
                return 2;
            }
        }

        delay(50);
    }
}



void ADMIN::displayButtons() {
        if (showButtons) {
           setcolor(RED);
           setbkcolor(LIGHTGRAY);
		   settextstyle(4,0,1);
           outtextxy(1000,35,"Hello");
            outtextxy(1000,60,"Admin");
        } else {
            setfillstyle(1,LIGHTGRAY);
            bar(1000, 0, 1200, 100);
        }
    }
    


