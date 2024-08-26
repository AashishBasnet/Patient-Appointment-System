#include "ptappoint.h"
#include "layouts.h"
#include <graphics.h>
#include <ctime>
#include<cstring>
#include <iostream>
#include<fstream>
#include<limits>

using namespace std;
 int token_no_count=0; 
int global_token1_count1;
int global_token1_count2;
int global_token1_count3;
int global_token2_count1;
int global_token2_count2;
int global_token2_count3;
int global_token3_count1;
int global_token3_count2;
int global_token3_count3;

void filestreamfunction(char* ch)
{
	    ifstream fin;
    fin.open("doctor.bin", ios::in | ios::binary);
    if (fin) {
        char fileid[50];
        char filename[100];
        char filepassword[100];
        char filedepartment[50];
        char filedayshift[4][20];
        char filetimeshift[2][20];

        int yCoord=230;
        int PicyCoord=0;
        int count = 0;	
        while (fin.peek() != EOF && count < 3) {
            memset(fileid, '\0', sizeof(fileid));
            memset(filename, '\0', sizeof(filename));
            memset(filepassword, '\0', sizeof(filepassword));
            memset(filedepartment, '\0', sizeof(filedepartment));

            for (int c = 0; c < 4; c++) {
                filedayshift[c][0] = '\0';
            }

            for (int c = 0; c < 2; c++) {
                filetimeshift[c][0] = '\0';
            }

            fin.getline(fileid, sizeof(fileid), '\0');
            fin.getline(filename, sizeof(filename), '\0');
            fin.getline(filepassword, sizeof(filepassword), '\0');
            fin.getline(filedepartment, sizeof(filedepartment), '\0');

            for (int i = 0; i < 4; ++i) {
                fin.getline(filedayshift[i], sizeof(filedayshift[i]), '\0');
                if (strcmp(filedayshift[i], "null") == 0) {
                    filedayshift[i][0] = '\0';
                }
            }

            for (int i = 0; i < 2; ++i) {
                fin.getline(filetimeshift[i], sizeof(filetimeshift[i]), '\0');
                if (strcmp(filetimeshift[i], "null") == 0) {
                    filetimeshift[i][0] = '\0';
                }
            }

            fin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Check the department 
            if (strcmp(filedepartment,ch) == 0) {
                // Print the doctor's information
                     cout<< "Name: " << filename << "\n";
                cout << "\n\n";
                setcolor(0);
               setbkcolor(15);
               settextstyle(4,0,1);
                  outtextxy(300, yCoord, filename);
                  //----------doctor1
                  readimagefile("images/doctor.jpg",180,190+PicyCoord,280,290+PicyCoord);
                yCoord += 170; 
                PicyCoord +=170;
                count++;
            }
        }
        fin.close();
    } else {
        cerr << "Error opening file for printing" << endl;}
}
void PTAPPOINT::ptappoint(bool status, char ptname[50]) {
	userstatus=status;
	memset(user,0,sizeof(user));
	strcpy(user,ptname);
     setcolor(CYAN);
        setbkcolor(LIGHTGRAY);
        settextstyle(4, 0, 2);
        outtextxy(630, 78, "Appoint");
        setcolor(RED);
        setbkcolor(15);
        line(600, 145, 780, 145);
        outtextxy(600, 120, "Departments");

        for (int i = 0; i <= 700; i += 350) {
            dbox(200 + i, 180, 200, 270);
            dbox(200 + i, 410, 200, 270);
            button(235 + i, 335, 35, 210);
            setcolor(WHITE);
            setbkcolor(CYAN);
            outtextxy(290 + i, 340, "Consult");

            button(235 + i, 565, 35, 210);    
            setcolor(WHITE);
            setbkcolor(CYAN);
            outtextxy(290 + i, 570, "Consult");
        }
        setbkcolor(15);
        setcolor(RED);

        // general medicine
        dbox(300, 200, 70, 70);
        readimagefile("images/general medicine.jpg", 310, 210, 358, 258);
        setcolor(RED);
        settextstyle(4, 0, 1);
        outtextxy(220, 280, "General Medicine");

        // ophthalmology
        dbox(650, 200, 70, 70);
        readimagefile("images/opthamology.jpg", 660, 210, 708, 258);
        setcolor(RED);
        settextstyle(4, 0, 1);
        outtextxy(600, 280, "Opthalmology");

        // ent
        dbox(1000, 200, 70, 70);
        readimagefile("images/ent.jpg", 1010, 210, 1058, 258);
        setcolor(RED);
        settextstyle(4, 0, 1);
        outtextxy(1010, 280, "ENT");

        // cardio
        dbox(300, 430, 70, 70);
        readimagefile("images/cardiology.jpg", 310, 440, 358, 488);
        setcolor(RED);
        settextstyle(4, 0, 1);
        outtextxy(270, 520, "Cardiology");

        // gastro
        dbox(650, 430, 70, 70);
        readimagefile("images/gastro.jpg", 660, 440, 710, 488);
        setcolor(RED);
        settextstyle(4, 0, 1);
        outtextxy(590, 520, "Gastro Surgery");

        // neuro
        dbox(1000, 430, 70, 70);
        readimagefile("images/neuro.jpg", 1010, 440, 1060, 488);
        setcolor(RED);
        settextstyle(4, 0, 1);
        outtextxy(940, 520, "Neuro Medicine");
}

void PTAPPOINT::generalmedicine()
{
setfillstyle(1,WHITE);
bar(151,101,1280,720);	
setcolor(CYAN);
setbkcolor(LIGHTGRAY);
settextstyle(4,0,2);
outtextxy(630,77,"Appoint");
hdbox(170,120,570,1050);
setcolor(RED);
setbkcolor(3);
outtextxy(210,130,"General Medicine");
setcolor(LIGHTGRAY);
line(770,161,770,691);
line(171,340,770,340);
line(171,520,770,520);
button(880,410,40,280);
setbkcolor(CYAN);
setcolor(WHITE);
settextstyle(4,0,1);
outtextxy(900,420,"Book Appointment");
filestreamfunction("general medicine");
}

void PTAPPOINT::opthamology()
{
setfillstyle(1,WHITE);
bar(151,101,1280,720);	
setcolor(CYAN);
setbkcolor(LIGHTGRAY);
settextstyle(4,0,2);
outtextxy(630,77,"Appoint");
hdbox(170,120,570,1050);
setcolor(RED);
setbkcolor(3);
outtextxy(210,130,"opthamology");
setcolor(LIGHTGRAY);
line(770,161,770,691);
line(171,340,770,340);
line(171,520,770,520);
button(880,410,40,280);
setbkcolor(CYAN);
setcolor(WHITE);
settextstyle(4,0,1);
outtextxy(900,420,"Book Appointment");
filestreamfunction("opthalmology");
}

void PTAPPOINT::ent()
{
setfillstyle(1,WHITE);
bar(151,101,1280,720);	
settextstyle(4,0,2);
setbkcolor(LIGHTGRAY);
outtextxy(630,77,"Appoint");
hdbox(170,120,570,1050);
line(770,161,770,691);
line(171,340,770,340);
line(171,520,770,520);
setcolor(RED);
setbkcolor(3);
outtextxy(210,130,"E.N.T.");
button(880,410,40,280);
setbkcolor(CYAN);
setcolor(WHITE);
settextstyle(4,0,1);
outtextxy(900,420,"Book Appointment");
filestreamfunction("ent");
}

void PTAPPOINT::cardio()
{
setfillstyle(1,WHITE);
bar(151,101,1280,720);	
setcolor(CYAN);
setbkcolor(LIGHTGRAY);
settextstyle(4,0,2);
outtextxy(630,77,"Appoint");
hdbox(170,120,570,1050);
line(770,161,770,691);
line(171,340,770,340);
line(171,520,770,520);
setcolor(RED);
setbkcolor(3);
outtextxy(210,130,"Cardiology");
button(880,410,40,280);
setbkcolor(CYAN);
setcolor(WHITE);
settextstyle(4,0,1);
outtextxy(900,420,"Book Appointment");
filestreamfunction("cardiology");
}

void PTAPPOINT::gastro()
{
setfillstyle(1,WHITE);
bar(151,101,1280,720);	
setcolor(CYAN);
setbkcolor(LIGHTGRAY);
settextstyle(4,0,2);
outtextxy(630,77,"Appoint");
hdbox(170,120,570,1050);
line(770,161,770,691);
line(171,340,770,340);
line(171,520,770,520);
setcolor(RED);
setbkcolor(3);
outtextxy(210,130,"Gastro Surgery");
button(880,410,40,280);
setbkcolor(CYAN);
setcolor(WHITE);
settextstyle(4,0,1);
outtextxy(900,420,"Book Appointment");
filestreamfunction("gastro surgery");
}

void PTAPPOINT::neuro()
{
setfillstyle(1,WHITE);
bar(151,101,1280,720);	
setcolor(CYAN);
setbkcolor(LIGHTGRAY);
settextstyle(4,0,2);
outtextxy(630,77,"Appoint");
hdbox(170,120,570,1050);
line(770,161,770,691);
line(171,340,770,340);
line(171,520,770,520);
setcolor(RED);
setbkcolor(3);
outtextxy(210,130,"Neuro Medicine");
filestreamfunction("neuro medicine");
button(880,410,40,280);
setbkcolor(CYAN);
setcolor(WHITE);
settextstyle(4,0,1);
outtextxy(900,420,"Book Appointment");
filestreamfunction("neuro");
}

int PTAPPOINT::checkbookbtnclick()
{
		 bookcondition= true;
	 while (bookcondition) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

            // Check if the left mouse button is pressed
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !bookmouseButtonDown) {
                bookmouseButtonDown = true;

                                // Check if the click is on btn
                 if (p.x >= 880 && p.x <= 1160 && p.y >= 410 && p.y <= 450)
                  {
                  	bookcondition=false;
                   return 1;
				  }
				  
				    // for sidebar buttons click
            if ((p.x >= 25 && p.x <= 105 && p.y >= 250 && p.y <= 270) || (p.x >= 25 && p.x <= 125 && p.y >= 350 && p.y <= 370) ||(p.x >= 25 && p.x <= 105 && p.y >= 450 && p.y <= 470) ||(p.x >= 25 && p.x <= 125 && p.y >= 600 && p.y <= 620)|| (p.x >= 25 && p.x <= 105 && p.y >= 550 && p.y <= 570)||(p.x >= 25 && p.x <= 105 && p.y >= 650 && p.y <= 670)) {
                bookcondition = false;
            }
 
}
          // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
               bookmouseButtonDown = false;
            } 
}
}

void PTAPPOINT::timeslot()
{
   // Clear the background and set the layout
    setfillstyle(1, WHITE);
    bar(151, 101, 1280, 720);
    hdbox(170, 120, 570, 1050);
    setcolor(RED);
    setbkcolor(3);
    outtextxy(210, 130, "Choose a timeslot:");
     cout<<"meow"<<user;

    // Get the current time
    time_t currentTime = std::time(nullptr);
    tm* localTime = std::localtime(&currentTime);

    // Extract components
    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;
    int weekday = localTime->tm_wday;
    int hour = localTime->tm_hour;
    int minute = localTime->tm_min;

    // Format date components into strings
    char cyear[50];
    sprintf(cyear, "%d", year);
    char cmonth[50];
    sprintf(cmonth, "%d", month);
    char cday[50];
    sprintf(cday, "%d", day);

    // Time slot 1: Check if before 7 AM or after 5 PM
    setfillstyle(1, 15);
    bar(200, 190, 600, 300);
    settextstyle(4, 0, 4);
    setbkcolor(15);

    if (hour >= 17 && minute > 0) {
        // Move to the next day if time is before 7 AM or after 5 PM
        localTime->tm_mday += 1;
        std::mktime(localTime);
        year = localTime->tm_year + 1900;
        month = localTime->tm_mon + 1;
        day = localTime->tm_mday;
        sprintf(cyear, "%d", year);
        sprintf(cmonth, "%d", month);
        sprintf(cday, "%d", day);
        weekday = (weekday + 1) % 7;  // Adjust weekday
}
     else if (weekday == 6) {  // If today is Saturday
        // Move to the next day
        localTime->tm_mday += 1;
        mktime(localTime);
        year = localTime->tm_year + 1900;
        month = localTime->tm_mon + 1;
        day = localTime->tm_mday;
        sprintf(cyear, "%d", year);
        sprintf(cmonth, "%d", month);
        sprintf(cday, "%d", day);
        weekday = (weekday + 1) % 7;  // Adjust weekday
    }
    year1=year;
    month1=month;
    day1=day;
    setcolor(CYAN);
    outtextxy(200, 190, "[");
    outtextxy(220, 190, cyear);
    outtextxy(325, 190, "-");
    if (month < 10) {
        outtextxy(340, 190, "0");
        outtextxy(367, 190, cmonth);
    } else {
        outtextxy(335, 190, cmonth);
    }
    outtextxy(392, 190, "-");

    if (day < 10) {
        outtextxy(402, 190, "0");
        outtextxy(429, 190, cday);
    } else {
        outtextxy(402, 190, cday);
    }
    outtextxy(456, 190, "]");

    button(880, 230, 40, 280);
    setbkcolor(CYAN);
    setcolor(WHITE);
    settextstyle(4, 0, 1);
    outtextxy(900, 240, "Book Appointment");
    

    // Time slot 2: Move to the next day
    setfillstyle(1, 15);
    bar(200, 390, 600, 500);
    localTime->tm_mday += 1;
    std::mktime(localTime);
    year = localTime->tm_year + 1900;
    month = localTime->tm_mon + 1;
    day = localTime->tm_mday;
    sprintf(cyear, "%d", year);
    sprintf(cmonth, "%d", month);
    sprintf(cday, "%d", day);
    weekday = (weekday + 1) % 7;

    if (weekday == 6) {  // If it's Saturday, move to next day
        localTime->tm_mday += 1;
        mktime(localTime);
        year = localTime->tm_year + 1900;
        month = localTime->tm_mon + 1;
        day = localTime->tm_mday;
        sprintf(cyear, "%d", year);
        sprintf(cmonth, "%d", month);
        sprintf(cday, "%d", day);
        weekday = (weekday + 1) % 7;
    }

  year2=year;
    month2=month;
    day2=day;
    settextstyle(4, 0, 4);
    setbkcolor(15);
    setcolor(CYAN);
    outtextxy(200, 390, "[");
    outtextxy(220, 390, cyear);
    outtextxy(325, 390, "-");
    if (month < 10) {
        outtextxy(340, 390, "0");
        outtextxy(367, 390, cmonth);
    } else {
        outtextxy(335, 390, cmonth);
    }
    outtextxy(392, 390, "-");

    if (day < 10) {
        outtextxy(402, 390, "0");
        outtextxy(429, 390, cday);
    } else {
        outtextxy(402, 390, cday);
    }
    outtextxy(456, 390, "]");

    button(880, 410, 40, 280);
    setbkcolor(CYAN);
    setcolor(WHITE);
    settextstyle(4, 0, 1);
    outtextxy(900, 420, "Book Appointment");
    // Time slot 3: Move to the next day
    setfillstyle(1, 15);
    bar(200, 590, 600, 680);
    localTime->tm_mday += 1;
    std::mktime(localTime);
    year = localTime->tm_year + 1900;
    month = localTime->tm_mon + 1;
    day = localTime->tm_mday;
    sprintf(cyear, "%d", year);
    sprintf(cmonth, "%d", month);
    sprintf(cday, "%d", day);
    weekday = (weekday + 1) % 7;

  year3=year;
    month3=month;
    day3=day;
    if (weekday == 6) {  // If it's Saturday, move to next day
        localTime->tm_mday += 1;
        mktime(localTime);
        year = localTime->tm_year + 1900;
        month = localTime->tm_mon + 1;
        day = localTime->tm_mday;
        sprintf(cyear, "%d", year);
        sprintf(cmonth, "%d", month);
        sprintf(cday, "%d", day);
        weekday = (weekday + 1) % 7;
    }

    settextstyle(4, 0, 4);
    setbkcolor(15);
    setcolor(CYAN);
    outtextxy(200, 550, "[");
    outtextxy(220, 550, cyear);
    outtextxy(325, 550, "-");
    if (month < 10) {
        outtextxy(340, 550, "0");
        outtextxy(367, 550, cmonth);
    } else {
        outtextxy(335, 550, cmonth);
    }
    outtextxy(392, 550, "-");

    if (day < 10) {
        outtextxy(402, 550, "0");
        outtextxy(429, 550, cday);
    } else {
        outtextxy(402, 550, cday);
    }
    outtextxy(456, 550, "]");

    button(880, 590, 40, 280);
    setbkcolor(CYAN);
    setcolor(WHITE);
    settextstyle(4, 0, 1);
    outtextxy(900, 600, "Book Appointment");

    // Lines separating timeslots
    setcolor(LIGHTGRAY);
    line(171, 340, 1220, 340);
    line(171, 520, 1220, 520);
}


int PTAPPOINT::timebtnclick()
{
		 bookcondition= true;
	 while (bookcondition) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

            // Check if the left mouse button is pressed
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !bookmouseButtonDown) {
                bookmouseButtonDown = true;

                                // Check if the click is on btn1
                 if (p.x >= 880 && p.x <= 1160 && p.y >= 230 && p.y <= 270)
                  {
                  	fyear=year1;
                  	fmonth=month1;
                  	fday=day1;
                  	bookcondition=false;
                   return 1;
				  }
				  
				                                  // Check if the click is on btn2
                 if (p.x >= 880 && p.x <= 1160 && p.y >= 410 && p.y <= 450)
                  {
                  	fyear=year2;
                  	fmonth=month2;
                  	fday=day2;
                  	bookcondition=false;
                   return 1;
				  }
				  
				                                  // Check if the click is on btn3
                 if (p.x >= 880 && p.x <= 1160 && p.y >= 590 && p.y <= 630)
                  {
                  	fyear=year3;
                  	fmonth=month3;
                  	fday=day3;
                  	bookcondition=false;
                   return 1;
				  }
				  
				    // for sidebar buttons click
            if ((p.x >= 25 && p.x <= 105 && p.y >= 250 && p.y <= 270) || (p.x >= 25 && p.x <= 125 && p.y >= 350 && p.y <= 370) ||(p.x >= 25 && p.x <= 105 && p.y >= 450 && p.y <= 470) ||(p.x >= 25 && p.x <= 125 && p.y >= 600 && p.y <= 620)|| (p.x >= 25 && p.x <= 105 && p.y >= 550 && p.y <= 570)||(p.x >= 25 && p.x <= 105 && p.y >= 650 && p.y <= 670)) {
                bookcondition = false;
            }
 
}
          // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
               bookmouseButtonDown = false;
            } 
}
}


int PTAPPOINT::choosetimebtnclick()
{  cout<<"choosetimebtnclck"<<fday<<"day1:"<<day1<<endl;
		   time_t currentTime = std::time(nullptr);
    tm* localTime = std::localtime(&currentTime);
    int choose_hour = localTime->tm_hour;
    int choose_minute = localTime->tm_min;
      int appoint_day = localTime->tm_mday;
        int appoint_wkday = localTime->tm_wday;
		 bookcondition= true;
	 while (bookcondition) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

            // Check if the left mouse button is pressed
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !bookmouseButtonDown) {
                bookmouseButtonDown = true;

                                // Check if the click is on btn1
                 if (p.x >= 180 && p.x <= 500 && p.y >= 310 && p.y <= 580)
                  {
                  	if(userstatus==true && ((fday!=day1 || (fday==day1 && choose_hour<11)|| (fday==day1 && choose_hour>17))||appoint_wkday==6))
                  	{ if((fday==day1 && global_token1_count1>=1) ||(fday==day2 && global_token2_count1>=1) ||( fday==day3 && global_token3_count1>=1) )
                  	{ 
                  		strcpy(fdaytime,"morning");
                  		timeclick = 1;
                  		bookcondition=false;
                        return 1;	
					  }
				    }
				  }
			
			                     // Check if the click is on btn2
                 if (p.x >= 530 && p.x <= 850 && p.y >= 310 && p.y <= 580) 
                  {
                    if (userstatus == true &&((fday != day1 || (fday == day1 && (choose_hour < 14 || (choose_hour == 14 && choose_minute < 30)))||(fday==day1 && choose_hour>17)) || appoint_wkday==6))

                  	{
                  		 if((fday==day1 && global_token1_count2>=1) ||(fday==day2 && global_token2_count2>=1) || (fday==day3 && global_token3_count2>=1) )
                  		 {
                  		strcpy(fdaytime,"afternoon");
                  		timeclick = 2;
                  		bookcondition=false;
                         return 1;	
					  }
				    }
				
				  }
				  
				        // Check if the click is on btn3
                 if (p.x >= 880 && p.x <= 1200 && p.y >= 310 && p.y <= 580)
                  {	
                    if(userstatus==true && ((fday!=day1 || (fday==day1 && choose_hour<17)||(fday==day1 && choose_hour>17)) || appoint_wkday==6))
                  	{
                  		if ((fday == day1 && global_token1_count3 >= 1)||(fday == day2 && global_token2_count3 >= 1) ||(fday == day3 && global_token3_count3 >= 1))
						  { 
                  		strcpy(fdaytime,"evening");
                  		timeclick = 3;
                  		bookcondition=false;
                        return 1;
					}
					  
				}
				  }
				  
				    // for sidebar buttons click
            if ((p.x >= 25 && p.x <= 105 && p.y >= 250 && p.y <= 270) || (p.x >= 25 && p.x <= 125 && p.y >= 350 && p.y <= 370) ||(p.x >= 25 && p.x <= 105 && p.y >= 450 && p.y <= 470) ||(p.x >= 25 && p.x <= 125 && p.y >= 600 && p.y <= 620)|| (p.x >= 25 && p.x <= 105 && p.y >= 550 && p.y <= 570)||(p.x >= 25 && p.x <= 105 && p.y >= 650 && p.y <= 670)) {
                bookcondition = false;
            }
 
}
          // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
               bookmouseButtonDown = false;
            } 
}
}

void PTAPPOINT::confirm()
{
	 setfillstyle(1, WHITE);
    bar(151, 101, 1280, 720);
       setfillstyle(1, WHITE);
    bar(151, 101, 1280, 720);
    hdbox(170, 120, 570, 1050);
    setcolor(RED);
    setbkcolor(3);
    outtextxy(210, 130, "Confirm Appointment:");

 
 int display_token_number=0;
 char cdisplaytoken[50]= {0};
  int time_count=0;	
     sprintf(fdate, "%04d-%02d-%02d", fyear, fmonth, fday);
        char existingUsername[50];
        char dummyFname[100];
        char dummyPhonenumber[20];
        memset(existingUsername,0,sizeof(existingUsername));
    memset(dummyFname,0,sizeof(dummyFname));
	memset(dummyPhonenumber,0,sizeof(dummyPhonenumber));    
    ifstream fin;
	fin.open("patient.bin", ios::in | ios::binary);
    if (fin) {
        while (fin.read(existingUsername, sizeof(existingUsername))) {
            fin.read(dummyFname, sizeof(dummyFname));
            fin.read(dummyPhonenumber, sizeof(dummyPhonenumber));
            fin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (strcmp(existingUsername, user) == 0) {
            	strcpy(username,dummyFname);
            	strcpy(phonenumber,dummyPhonenumber);
             break;
            }
        }
            fin.close();
        }
		 else {
            cerr << "Error opening file" << endl;
        }
if(strcmp(fdaytime,"morning")==0)
{
	strcpy(apptime,"7:00-11:00");
	}    
	else if(strcmp(fdaytime,"afternoon")==0)
	{
		strcpy(apptime,"12:00-2:30");
	}
	else if(strcmp(fdaytime,"evening")==0)
	{
		strcpy(apptime,"3:15-5:00");
	}
	
	
	
    char userId[50], firstName[50], phoneNumber[50], department[50], date[50], timeSlot[50],tkno[50];
    ifstream appointmentFile("appointments.bin", ios::in | ios::binary);

    appointmentFile.seekg(0, ios::beg);
    if (appointmentFile) {
        string record;
        while (getline(appointmentFile, record, '\n')) {
            stringstream recordStream(record);
            recordStream.getline(userId, sizeof(userId), '\0');
            recordStream.getline(firstName, sizeof(firstName), '\0');
            recordStream.getline(tkno, sizeof(tkno), '\0');
            recordStream.getline(phoneNumber, sizeof(phoneNumber), '\0');
            recordStream.getline(department, sizeof(department), '\0');
            recordStream.getline(date, sizeof(date), '\0');
            recordStream.getline(timeSlot, sizeof(timeSlot), '\0');
                  char extracted_date[3];
            strncpy(extracted_date, date + 8, 2);
            extracted_date[2] = '\0'; 
            int extracted_dateInt = atoi(extracted_date);
                if (strcmp(timeSlot, "7:00-11:00") == 0 && strcmp(fdepartment,department) == 0 &&extracted_dateInt==fday&&fday==day1 && timeclick == 1) {
                time_count++;
            }
                else if(strcmp(timeSlot, "12:00-2:30") == 0 && strcmp(fdepartment,department) == 0 &&extracted_dateInt==fday&& fday==day1 && timeclick == 2) {
                time_count++;
            }
              else if(strcmp(timeSlot, "3:15-5:00") == 0 && strcmp(fdepartment,department) == 0 && extracted_dateInt==fday&&fday==day1 && timeclick == 3) {
                time_count++;
            }
            else if (strcmp(timeSlot, "7:00-11:00") == 0 && strcmp(fdepartment,department) == 0  && extracted_dateInt==fday&& fday==day2 && timeclick == 1) {
                time_count++;
            }
                else if(strcmp(timeSlot, "12:00-2:30") == 0 && strcmp(fdepartment,department) == 0 && extracted_dateInt==fday&& fday==day2 && timeclick == 2) {
                time_count++;
            }
              else if(strcmp(timeSlot, "3:15-5:00") == 0 && strcmp(fdepartment,department) == 0 && extracted_dateInt==fday&& fday==day2 && timeclick == 3) {
                time_count++;
            }
                  else if (strcmp(timeSlot, "7:00-11:00") == 0 && strcmp(fdepartment,department) == 0 && extracted_dateInt==fday&& fday==day3 && timeclick == 1) {
                time_count++;            
            }
                else if(strcmp(timeSlot, "12:00-2:30") == 0 && strcmp(fdepartment,department) == 0 && extracted_dateInt==fday&& fday==day3 && timeclick == 2) {
                time_count++;           
            }
              else if(strcmp(timeSlot, "3:15-5:00") == 0 && strcmp(fdepartment,department) == 0 && extracted_dateInt==fday&& fday==day3 && timeclick == 3) {
                time_count++;               
            }
            
        }
        appointmentFile.close();
    } else {
        cerr << "Error opening file" << endl;
    }
	 /*sprintf(cdisplaytoken, "%d", display_token_number);
       	setbkcolor(15);
    	 setcolor(0);
         outtextxy(525,350,cdisplaytoken);*/
             time_count+=1;
sprintf(tokennumber,"%d",time_count);
setcolor(RED);
setbkcolor(15);
settextstyle(4,0,1);
outtextxy(200,230,"DEPARTMENT NAME");
outtextxy(200,270,"APPOINTMENT DATE:");
outtextxy(200,310,"APPOINTMENT TIME:");
outtextxy(200,350,"TOKEN NUMBER:");
outtextxy(400,440,"PATIENT'S INFO:");
outtextxy(200,500,"PATIENT'S NAME:");
outtextxy(200,540,"CONTACT:");
setcolor(0);
outtextxy(525,230,fdepartment);
outtextxy(525,270,fdate);
char tc[50];
sprintf(tc, "%d", time_count);
outtextxy(525,310,apptime);
 outtextxy(525,350,tc);
outtextxy(525,500,username);
outtextxy(525,540,phonenumber);
button(540,610,50,300);
setbkcolor(CYAN);
setcolor(WHITE);
settextstyle(4,0,1);
outtextxy(550,625,"Confirm Appointment");
/*
setbkcolor(WHITE);
setcolor(GREEN);
outtextxy(200,490,"Appointment Booked!");
coloredbutton(540,610,50,300,RED);
setbkcolor(RED);
setcolor(WHITE);
outtextxy(550,625,"Cancel Appointment");
*/
 } 
 
 void PTAPPOINT::choosetime(){
	setfillstyle(1,WHITE);
     bar(151,101,1280,720);	
        setfillstyle(1, WHITE);
    bar(151, 101, 1280, 720);
    hdbox(170, 120, 570, 1050);
    setcolor(RED);
    setbkcolor(3);
    outtextxy(210, 130, "Choose a timeslot:");
     if(userstatus==false)
     {
          setcolor(RED);
	setbkcolor(15);
	settextstyle(4,0,2);
     outtextxy(535,600,"You are not logged in.");
     	setcolor(0);
	setbkcolor(15);
	outtextxy(535,630,"Login to proceed!");	
	 }
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);

    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;

    int hour = localTime->tm_hour;
    int minute = localTime->tm_min;

    setlinestyle(0, 0, 2);
    setbkcolor(15);
    int tokensleft;
    char c_tokensleft[50];
    
     int time1_count1=0;
	  int time1_count2=0;
	   int time1_count3=0;
	    int time2_count1=0;
		 int time2_count2=0;
		  int time2_count3=0;
		   int time3_count1=0;
		    int time3_count2=0;
	 int time3_count3=0;	
   int token1_count1=12;	
    int token1_count2=8;	
     int token1_count3=5;
       int token2_count1=12;	
    int token2_count2=8;	
     int token2_count3=5;
       int token3_count1=12;	
    int token3_count2=8;	
     int token3_count3=5;
    	
    char userId[50], firstName[50], phoneNumber[50], department[50], date[50], timeSlot[50],tkno[50];
    ifstream appointmentFile("appointments.bin", ios::in | ios::binary);

    appointmentFile.seekg(0, ios::beg);
    if (appointmentFile) {
        string record;
        while (getline(appointmentFile, record, '\n')) {
            stringstream recordStream(record);
            recordStream.getline(userId, sizeof(userId), '\0');
            recordStream.getline(firstName, sizeof(firstName), '\0');
            recordStream.getline(tkno, sizeof(tkno), '\0');
            recordStream.getline(phoneNumber, sizeof(phoneNumber), '\0');
            recordStream.getline(department, sizeof(department), '\0');
            recordStream.getline(date, sizeof(date), '\0');
            recordStream.getline(timeSlot, sizeof(timeSlot), '\0');
                  char extracted_date[3];
            strncpy(extracted_date, date + 8, 2);
            extracted_date[2] = '\0'; 
            int extracted_dateInt = atoi(extracted_date);
        
                if (strcmp(timeSlot, "7:00-11:00") == 0 && strcmp(fdepartment,department) == 0 &&extracted_dateInt==day1) {
                time1_count1++;
            }
                else if(strcmp(timeSlot, "12:00-2:30") == 0 && strcmp(fdepartment,department) == 0 &&extracted_dateInt==day1) {
                time1_count2++;
            }
              else if(strcmp(timeSlot, "3:15-5:00") == 0 && strcmp(fdepartment,department) == 0 && extracted_dateInt==day1) {
                time1_count3++;
            }
            else if (strcmp(timeSlot, "7:00-11:00") == 0 && strcmp(fdepartment,department) == 0  && extracted_dateInt==day2) {
                time2_count1++;
            }
                else if(strcmp(timeSlot, "12:00-2:30") == 0 && strcmp(fdepartment,department) == 0 && extracted_dateInt==day2) {
                time2_count2++;
            }
              else if(strcmp(timeSlot, "3:15-5:00") == 0 && strcmp(fdepartment,department) == 0 && extracted_dateInt==day2) {
                time2_count3++;
            }
                  else if (strcmp(timeSlot, "7:00-11:00") == 0 && strcmp(fdepartment,department) == 0 && extracted_dateInt==day3) {
                time3_count1++;             
            }
                else if(strcmp(timeSlot, "12:00-2:30") == 0 && strcmp(fdepartment,department) == 0 && extracted_dateInt==day3) {
                time3_count2++;               
            }
              else if(strcmp(timeSlot, "3:15-5:00") == 0 && strcmp(fdepartment,department) == 0 && extracted_dateInt==day3) {
                time3_count3++;                
            }
            
        }
        appointmentFile.close();
    } else {
        cerr << "Error opening file" << endl;
    }
	 /*sprintf(cdisplaytoken, "%d", display_token_number);
       	setbkcolor(15);
    	 setcolor(0);
         outtextxy(525,350,cdisplaytoken);*/
 token1_count1=token1_count1-time1_count1;
 token1_count2=token1_count2-time1_count2;
 token1_count3=token1_count3-time1_count3;
 token2_count1=token2_count1-time2_count1;
 token2_count2=token2_count2-time2_count2;
 token2_count3=token2_count3-time2_count3;
 token3_count1=token3_count1-time3_count1;
 token3_count2=token3_count2-time3_count2;
 token3_count3=token3_count3-time3_count3;

global_token1_count1=token1_count1;
global_token1_count2=token1_count2;
global_token1_count3=token1_count3;
global_token2_count1=token2_count1;
global_token2_count2=token2_count2;
global_token2_count3=token2_count3;
global_token3_count1=token3_count1;
global_token3_count2=token3_count2;
global_token3_count3=token3_count3;


    if (year == fyear && month == fmonth && day == fday) {
    
    if  (hour < 11 || (hour == 11 && minute == 0)) {
        // First slot: 7:00 - 11:00
        dbox(180, 310, 270, 320);
        setcolor(MAGENTA);
        settextstyle(4, 0, 4);
        outtextxy(220, 380, "[7:00-11:00]");

        settextstyle(4, 0, 2);
        setcolor(RED);
        outtextxy(240, 480, "Tokens left:");
        
        if (fday==day1)
        {
        	 tokensleft = token1_count1;
		}
		else if (fday==day2)
		{
			 tokensleft = token2_count1;
		}
		else if (fday==day3)
		{
			 tokensleft = token3_count1;
		}
       
        sprintf(c_tokensleft, "%d", tokensleft);
        outtextxy(400, 480, c_tokensleft);
    }
    else
    {  dbox(180, 310, 270, 320);
    	setcolor(RED);
        settextstyle(4, 0, 3);
        outtextxy(215, 380, "time");
        outtextxy(215, 410, "has expired!");
	}

       

      if (hour < 14 || (hour == 14 && minute <= 30)) {
        // Second slot: 12:00 - 2:30
        dbox(180 + 350, 310, 270, 320);
        setcolor(MAGENTA);
        settextstyle(4, 0, 4);
        outtextxy(220 + 350, 380, "[12:00-2:30]");

        settextstyle(4, 0, 2);
        setcolor(RED);
        outtextxy(240 + 350, 480, "Tokens left:");
        
               if (fday==day1)
        {
        	 tokensleft = token1_count2;
		}
		else if (fday==day2)
		{
			 tokensleft = token2_count2;
		}
		else if (fday==day3)
		{
			 tokensleft = token3_count2;
		}
        
        sprintf(c_tokensleft, "%d", tokensleft);
        outtextxy(400 + 350, 480, c_tokensleft);

    }
        else
    {  dbox(530, 310, 270, 320);
    	setcolor(RED);
        settextstyle(4, 0, 3);
        outtextxy(565, 380, "time");
        outtextxy(565, 410, "has expired!");
	}

   if (hour < 17 || (hour == 17 && minute == 0)) {
        // Third slot: 3:15 - 5:00
        dbox(180 + 700, 310, 270, 320);
        setcolor(MAGENTA);
        settextstyle(4, 0, 4);
        outtextxy(220 + 700, 380, "[3:15-5:00]");

        settextstyle(4, 0, 2);
        setcolor(RED);
        outtextxy(240 + 700, 480, "Tokens left:");
        
               if (fday==day1)
        {
        	 tokensleft = token1_count3;
		}
		else if (fday==day2)
		{
			 tokensleft = token2_count3;
		}
		else if (fday==day3)
		{
			 tokensleft = token3_count3;
		}
        
        sprintf(c_tokensleft, "%d", tokensleft);
        outtextxy(400 + 700, 480, c_tokensleft);
    }
}
else
{
	  // First slot: 7:00 - 11:00
        dbox(180, 310, 270, 320);
        setcolor(MAGENTA);
        settextstyle(4, 0, 4);
        outtextxy(220, 380, "[7:00-11:00]");

        settextstyle(4, 0, 2);
        setcolor(RED);
        outtextxy(240, 480, "Tokens left:");
                
        if (fday==day1)
        {
        	 tokensleft = token1_count1;
		}
		else if (fday==day2)
		{
			 tokensleft = token2_count1;
		}
		else if (fday==day3)
		{
			 tokensleft = token3_count1;
		}
       
        sprintf(c_tokensleft, "%d", tokensleft);
        outtextxy(400, 480, c_tokensleft);
        
               // Second slot: 12:00 - 2:30
        dbox(180 + 350, 310, 270, 320);
        setcolor(MAGENTA);
        settextstyle(4, 0, 4);
        outtextxy(220 + 350, 380, "[12:00-2:30]");

        settextstyle(4, 0, 2);
        setcolor(RED);
        outtextxy(240 + 350, 480, "Tokens left:");
         
               if (fday==day1)
        {
        	 tokensleft = token1_count2;
		}
		else if (fday==day2)
		{
			 tokensleft = token2_count2;
		}
		else if (fday==day3)
		{
			 tokensleft = token3_count2;
		}
        sprintf(c_tokensleft, "%d", tokensleft);
        outtextxy(400 + 350, 480, c_tokensleft);
        
                // Third slot: 3:15 - 5:00
        dbox(180 + 700, 310, 270, 320);
        setcolor(MAGENTA);
        settextstyle(4, 0, 4);
        outtextxy(220 + 700, 380, "[3:15-5:00]");

        settextstyle(4, 0, 2);
        setcolor(RED);
        outtextxy(240 + 700, 480, "Tokens left:");
        
              
               if (fday==day1)
        {
        	 tokensleft = token1_count3;
		}
		else if (fday==day2)
		{
			 tokensleft = token2_count3;
		}
		else if (fday==day3)
		{
			 tokensleft = token3_count3;
		}
        
        sprintf(c_tokensleft, "%d", tokensleft);
        outtextxy(400 + 700, 480, c_tokensleft);
    }
}

 
 bool PTAPPOINT::checkdoubleappointment()
 {
 	char dummyuserid[50],dummyFname[50],dummyPhonenumber[50],dummydepartment[50],dummydate[50],dummytime[50],dummytokenno[50];
 	ifstream fin("appointments.bin", ios::in | ios::binary);
fin.seekg(0, ios::beg);
if (fin) {
    string record;
    while (getline(fin, record, '\n')) {
        stringstream ss(record);
        ss.getline(dummyuserid, sizeof(dummyuserid), '\0');
        ss.getline(dummyFname, sizeof(dummyFname), '\0');
        ss.getline(dummytokenno, sizeof(dummytokenno), '\0');
        ss.getline(dummyPhonenumber, sizeof(dummyPhonenumber), '\0');
        ss.getline(dummydepartment, sizeof(dummydepartment), '\0');
        ss.getline(dummydate, sizeof(dummydate), '\0');
        ss.getline(dummytime, sizeof(dummytime), '\0');
        if (strcmp(dummyuserid, user) == 0) {
            fin.close();
            return false;
        }
    }
    fin.close();
    return true;
} else {
    cerr << "Error opening file" << endl;
}
}
 
 int PTAPPOINT::confirmclick()
 {     
		 bookcondition= true;
	 while (bookcondition) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

            // Check if the left mouse button is pressed
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !bookmouseButtonDown) {
                bookmouseButtonDown = true;

                                // confirm button
                 if (p.x >= 540 && p.x <= 840 && p.y >= 610 && p.y <= 660)
                  {
                  	if(checkdoubleappointment())
                  	{
                  	ofstream fout;
				   fout.open("appointments.bin", ios::out | ios::app | ios::binary);
                if (fout) {
             fout.seekp(0, ios::end);
             fout.write(user, strlen(user) + 1);
    fout.write(username, strlen(username) + 1);
    fout.write(tokennumber, strlen(tokennumber) + 1);
    fout.write(phonenumber, strlen(phonenumber) + 1);
    fout.write(fdepartment, strlen(fdepartment) + 1);
     fout.write(fdate, strlen(fdate) + 1);
     fout.write(apptime, strlen(apptime) + 1);
             fout.put('\n');
            fout.close();
            bookcondition=false;
            return 1;
        }
		 else {
            cerr << "Error opening file for writing" << endl;
        }
					  }
					  else
					  {
					  	bookcondition=false;
					  	return 2;
					  }
				  }
				  
				    // for sidebar buttons click
            if ((p.x >= 25 && p.x <= 105 && p.y >= 250 && p.y <= 270) || (p.x >= 25 && p.x <= 125 && p.y >= 350 && p.y <= 370) ||(p.x >= 25 && p.x <= 105 && p.y >= 450 && p.y <= 470) ||(p.x >= 25 && p.x <= 125 && p.y >= 600 && p.y <= 620)|| (p.x >= 25 && p.x <= 105 && p.y >= 550 && p.y <= 570)||(p.x >= 25 && p.x <= 105 && p.y >= 650 && p.y <= 670)) {
                bookcondition = false;
            }
 
}
          // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
               bookmouseButtonDown = false;
            } 
}
 }
 
 

 	void PTAPPOINT::appointsuccessandattention(bool state) {
 	    	if(state==true)
 	    	{
 	setlinestyle(0,0,2);
	dbox(350,200,400,700);
	setcolor(GREEN);
	setbkcolor(15);
	settextstyle(4,0,3);
	setlinestyle(1,0,3);
	readimagefile("images/tickicon.jpg",625,220,725,320);
     outtextxy(520,360,"you have successfully");
	setbkcolor(15);
	settextstyle(4,0,2);
	outtextxy(530,410," made an appointment!");  	
			 }
			 else
			 {
	setlinestyle(0,0,2);
	dbox(350,200,400,700);
	setcolor(BLUE);
	setbkcolor(15);
	settextstyle(4,0,3);
	setlinestyle(1,0,3);
	readimagefile("images/attention.jpg",625,220,725,320);
     outtextxy(370,360,"you have already made an appointment.");
     	setcolor(0);
	setbkcolor(15);
	settextstyle(4,0,2);
	outtextxy(500,410,"can't have 2 appointments!");   
			 }
 
	button(530,525,50,300);
	settextstyle(4,0,2);
	setbkcolor(CYAN);
	setcolor(15);
	outtextxy(615,535,"Continue");
}
 
 int PTAPPOINT::lastclick()
 {
 		 bookcondition= true;
	 while (bookcondition) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

            // Check if the left mouse button is pressed
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !bookmouseButtonDown) {
                bookmouseButtonDown = true;

                                // confirm button
                 if (p.x >= 530 && p.x <= 830 && p.y >= 525 && p.y <= 575)
                  {
                 bookcondition=false;
                 return 1;
				  }
				  
				    // for sidebar buttons click
            if ((p.x >= 25 && p.x <= 105 && p.y >= 250 && p.y <= 270) || (p.x >= 25 && p.x <= 125 && p.y >= 350 && p.y <= 370) ||(p.x >= 25 && p.x <= 105 && p.y >= 450 && p.y <= 470) ||(p.x >= 25 && p.x <= 125 && p.y >= 600 && p.y <= 620)|| (p.x >= 25 && p.x <= 105 && p.y >= 550 && p.y <= 570)||(p.x >= 25 && p.x <= 105 && p.y >= 650 && p.y <= 670)) {
                bookcondition = false;

            }
 
}
          // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
               bookmouseButtonDown = false;
            } 
}
 }


int PTAPPOINT::appointclick()
{
	memset(fdepartment,0,sizeof(fdepartment));
	ashowButtons=false;
	appmouseButtonDown=true;
	appcondition= true;
	 while (appcondition) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

            // Check if the left mouse button is pressed
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !appmouseButtonDown) {
                appmouseButtonDown = true;
                
                  // Check if the click is user icon
                if (p.x >= 1202 && p.x <= 1250 && p.y >= 30 && p.y <= 80) {
                    ashowButtons = !ashowButtons;
                    adisplayButtons();
                }

                                // Check if the click is consult1
                if (p.x >= 235 && p.x <= 445 && p.y >= 335 && p.y <= 370) {
                	 ashowButtons = false;
                    adisplayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(610,77,750,98);
                    strcpy(fdepartment,"general medicine");
                    generalmedicine();
                    int l;
                    int result=checkbookbtnclick();
                                 if(result==1)
                  { 
                  	appcondition=false;
	                timeslot();
	                int tresult= timebtnclick();
	                 if(tresult==1)
	                 {
	                 	 choosetime();
	                 	int cresult=choosetimebtnclick();
	                 	if(cresult==1)
	                 	{
	                 		confirm();
	                 		int a = confirmclick();
	                 		if(a==1)
	                      {
	                        appointsuccessandattention(true);
	                        l=lastclick();
						   if(l==1)
						   {
						   	appcondition=false;
						   	return 1;
						   }
						  }
						  else if(a==2)
						  {
						  	appointsuccessandattention(false);	
							l=lastclick();
						   if(l==1)
						   {
						   	appcondition=false;
						   	return 1;
						   }
						  }	 
					 }
                   }
                }
            }
                
                                                // Check if the click is consult2
               else if (p.x >= 585 && p.x <= 795 && p.y >= 335 && p.y <= 370) {
               	 ashowButtons = false;
                    adisplayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(610,77,750,98);
                    strcpy(fdepartment,"opthalmology");
                    opthamology();
                    int l;
                    int result=checkbookbtnclick();
                                 if(result==1)
                  { 
                  	appcondition=false;
	                timeslot();
	                int tresult= timebtnclick();
	                 if(tresult==1)
	                 {
	                 	 choosetime();
	                 	int cresult=choosetimebtnclick();
	                 	if(cresult==1)
	                 	{
	                 		confirm();
	                 		int a = confirmclick();
	                 		if(a==1)
	                      {
	                        appointsuccessandattention(true);
	                        l=lastclick();
						   if(l==1)
						   {
						   	appcondition=false;
						   	return 1;
						   }
						  }
						  else if(a==2)
						  {
						  	appointsuccessandattention(false);	
							l=lastclick();
						   if(l==1)
						   {
						   	appcondition=false;
						   	return 1;
						   }
						  }	 
					 }
                   }
                }
                }
                
                //consult3
              else if (p.x >= 935 && p.x <= 1145 && p.y >= 335 && p.y <= 370) {
              	 ashowButtons = false;
                    adisplayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(610,77,750,98);
                    strcpy(fdepartment,"ent");
                   ent();
                 int l;
                    int result=checkbookbtnclick();
                                 if(result==1)
                  { 
                  	appcondition=false;
	                timeslot();
	                int tresult= timebtnclick();
	                 if(tresult==1)
	                 {
	                 	 choosetime();
	                 	int cresult=choosetimebtnclick();
	                 	if(cresult==1)
	                 	{
	                 		confirm();
	                 		int a = confirmclick();
	                 		if(a==1)
	                      {
	                        appointsuccessandattention(true);
	                        l=lastclick();
						   if(l==1)
						   {
						   	appcondition=false;
						   	return 1;
						   }
						  }
						  else if(a==2)
						  {
						  	appointsuccessandattention(false);	
							l=lastclick();
						   if(l==1)
						   {
						   	appcondition=false;
						   	return 1;
						   }
						  }	 
					 }
                   }
                }
                }
                
                                //consult4
               else if (p.x >= 235 && p.x <= 445 && p.y >= 565 && p.y <= 600) {
               	 ashowButtons = false;
                    adisplayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(610,77,750,98);
                    strcpy(fdepartment,"cardiology");
                 cardio();
                 int l;
                    int result=checkbookbtnclick();
                                 if(result==1)
                  { 
                  	appcondition=false;
	                timeslot();
	                int tresult= timebtnclick();
	                 if(tresult==1)
	                 {
	                 	 choosetime();
	                 	int cresult=choosetimebtnclick();
	                 	if(cresult==1)
	                 	{
	                 		confirm();
	                 		int a = confirmclick();
	                 		if(a==1)
	                      {
	                        appointsuccessandattention(true);
	                        l=lastclick();
						   if(l==1)
						   {
						   	appcondition=false;
						   	return 1;
						   }
						  }
						  else if(a==2)
						  {
						  	appointsuccessandattention(false);	
							l=lastclick();
						   if(l==1)
						   {
						   	appcondition=false;
						   	return 1;
						   }
						  }	 
					 }
                   }
                }
                }
                
                                                //consult5
               else if (p.x >= 585 && p.x <= 795 && p.y >= 565 && p.y <= 600) {
               	 ashowButtons = false;
                    adisplayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(610,77,750,98);
                    strcpy(fdepartment,"gastro surgery");
                  gastro();
                  int l;
                    int result=checkbookbtnclick();
                                 if(result==1)
                  { 
                  	appcondition=false;
	                timeslot();
	                int tresult= timebtnclick();
	                 if(tresult==1)
	                 {
	                 	 choosetime();
	                 	int cresult=choosetimebtnclick();
	                 	if(cresult==1)
	                 	{
	                 		confirm();
	                 		int a = confirmclick();
	                 		if(a==1)
	                      {
	                        appointsuccessandattention(true);
	                        l=lastclick();
						   if(l==1)
						   {
						   	appcondition=false;
						   	return 1;
						   }
						  }
						  else if(a==2)
						  {
						  	appointsuccessandattention(false);	
							l=lastclick();
						   if(l==1)
						   {
						   	appcondition=false;
						   	return 1;
						   }
						  }	 
					 }
                   }
                }
                }
                
                                                //consult6
                else if (p.x >= 935 && p.x <= 1145 && p.y >= 565 && p.y <= 600) {
                 ashowButtons = false;
                    adisplayButtons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);	
                    setfillstyle(1,LIGHTGRAY);
                    bar(610,77,750,98);
                    strcpy(fdepartment,"neuro medicine");
                  neuro();
                   int l;
                    int result=checkbookbtnclick();
                                 if(result==1)
                  { 
                  	appcondition=false;
	                timeslot();
	                int tresult= timebtnclick();
	                 if(tresult==1)
	                 {
	                 	 choosetime();
	                 	int cresult=choosetimebtnclick();
	                 	if(cresult==1)
	                 	{
	                 		confirm();
	                 		int a = confirmclick();
	                 		if(a==1)
	                      {
	                        appointsuccessandattention(true);
	                        l=lastclick();
						   if(l==1)
						   {
						   	appcondition=false;
						   	return 1;
						   }
						  }
						  else if(a==2)
						  {
						  	appointsuccessandattention(false);	
							l=lastclick();
						   if(l==1)
						   {
						   	appcondition=false;
						   	return 1;
						   }
						  }	 
					 }
                   }
                }
                }
                
                	  
				    // for sidebar buttons click
            if ((p.x >= 25 && p.x <= 105 && p.y >= 250 && p.y <= 270) || (p.x >= 25 && p.x <= 105 && p.y >= 450 && p.y <= 470) ||(p.x >= 25 && p.x <= 125 && p.y >= 600 && p.y <= 620)|| (p.x >= 25 && p.x <= 105 && p.y >= 550 && p.y <= 570)||(p.x >= 25 && p.x <= 105 && p.y >= 650 && p.y <= 670)) {
        
			    appcondition = false;
            }
 

            } 
            // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                appmouseButtonDown = false;
            }
        }
}

void PTAPPOINT::adisplayButtons() {
        if (ashowButtons) {
          if(user[0]=='\0')
          {
          	setcolor(RED);
           setbkcolor(LIGHTGRAY);
		   settextstyle(4,0,1);
           outtextxy(1000,35,"USER");
            outtextxy(1000,60,"(not resistered)");
		  }
		  else
		  {
		  	setcolor(RED);
           setbkcolor(LIGHTGRAY);
		   settextstyle(4,0,1);
           outtextxy(1000,35,"hello");
            outtextxy(1000,60,user);
		  }

        } else {
            setfillstyle(1,LIGHTGRAY);
            bar(1000, 0, 1200, 100);
        }
    }
