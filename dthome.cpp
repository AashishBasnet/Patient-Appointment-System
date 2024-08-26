#include "dthome.h"
#include "dlogin.h"
#include "layouts.h"
#include <graphics.h>
#include"cursorinput.h"
#include <cstring>
#include <iostream>
#include<graphics.h>
#include<fstream>
#include<limits>
#include<ctime>
#include<string>

using namespace std;
void DTHOME::dthome1() {
	setfillstyle(1,WHITE);
    bar(151,101,1280,720);
    setcolor(CYAN);
    setbkcolor(LIGHTGRAY);
    settextstyle(4, 0, 2);
    outtextxy(580, 77, "Dashboard");
	hdbox(170,120,570,1050);
setcolor(RED);
setbkcolor(3);
outtextxy(210,130,"Patient's attendance:");
setcolor(0);
setbkcolor(15);
outtextxy(300,285,"Department:");
outtextxy(405,365,"Date:");
outtextxy(405,445,"shift:");
setcolor(LIGHTGRAY);

textfield(480,280,50,400);
textfield(520,360,40,60);
textfield(610,360,40,60);
textfield(690,360,40,120);
textfield(480, 440, 50, 400);
outtextxy(530,370,"DD");
outtextxy(615,370,"MM");
outtextxy(695,370,"YYYY");
	button(530,525,50,300);
	settextstyle(4,0,2);
	setbkcolor(CYAN);
	setcolor(15);
	outtextxy(615,535,"Continue");
}

int DTHOME::ptrecordfillclick(char drid[50]) {
	   memset(did,0,sizeof(did));
	   strcpy(did,drid);

    
  time_t currentTime = std::time(nullptr);
tm* localTime = std::localtime(&currentTime);

int atyear = localTime->tm_year + 1900;
int atmonth = localTime->tm_mon + 1;
int atday = localTime->tm_mday;
int athour = localTime->tm_hour;
int atminute = localTime->tm_min;

char curyear[50];
sprintf(curyear, "%04d", atyear); 

char curmonth[50];
sprintf(curmonth, "%02d", atmonth); 

char curday[50];
sprintf(curday, "%02d", atday);
    char chyear[50];
    char chmonth[50];
    char chday[50];
		   char fileid[50];
        char filename[100];
        char filepassword[100];
        char filedepartment[50];
        char filedayshift[4][20];
        char filetimeshift[2][20];
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
    ifstream fin;
    fin.open("doctor.bin", ios::in | ios::binary);
    if (fin) {
        while (fin.peek() != EOF) {
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

            if (strcmp(fileid, did) == 0) {
            	     strcpy(docpass,filepassword);
                     strcpy(docdep,filedepartment);
        }           
            }
        
        fin.close();
    } else {
        cerr << "Error opening file for printing" << endl;}
      

		
	char year[50],month[50],day[50];
memset(pdepartment, 0, sizeof(pdepartment));
memset(pname, 0, sizeof(pname));
memset(ptkno, 0, sizeof(ptkno));
memset(tdate, 0, sizeof(tdate));
memset(ttime, 0, sizeof(ttime));
memset(year, 0, sizeof(year));
memset(month, 0, sizeof(month));
memset(day, 0, sizeof(day));
count=0;
mousebtndwn=false;
	psigncondition = true;
    while (psigncondition) {
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(GetForegroundWindow(), &p);
        if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !mousebtndwn) {
        mousebtndwn=true;
        cout<<"testing testing";
            // department
            if (p.x >= 480 && p.x <= 880 && p.y >= 280 && p.y <= 330) {
                clickedtextfield(480,280,50,400);
                setfillstyle(1, WHITE);
                    bar(499, 669, 1000, 800);
                text_input(480, 280, 50, 400, pdepartment);
            }

            // day
            if (p.x >= 520 && p.x <= 580 && p.y >= 360 && p.y <= 400) {
                clickedtextfield(520,360,40,60);
                setfillstyle(1, WHITE);
                    bar(499, 669, 1000, 800);
                max_char_text_input(520,360,40,60,day,2);
            }
            
            // month
            if (p.x >= 610 && p.x <= 670 && p.y >= 360 && p.y <= 400) {
                clickedtextfield(610,360,40,60);
               setfillstyle(1, WHITE);
                        bar(499, 669, 1000, 800);
                max_char_text_input(610,360,40,60,month,2);
            }

            // year
            if (p.x >= 690 && p.x <= 810 && p.y >= 360 && p.y <= 400) {
                clickedtextfield(690,360,40,120);
                setfillstyle(1, WHITE);
                     bar(499, 669, 1000, 800);
               max_char_text_input(690,360,40,120,year,4);
            }

            // shift
            if (p.x >= 480 && p.x <= 880 && p.y >= 440 && p.y <= 490) {
                clickedtextfield(480, 440, 50, 400);
                setfillstyle(1, WHITE);
                  bar(499, 669, 1000, 800);
                text_input(480, 440, 50, 400, ttime);
            }
 
            //continue button
               if (p.x >= 530 && p.x <= 830 && p.y >= 525 && p.y <= 575) {
               	  cout<<"\n\n\nfdep:"<<docdep<<endl;
               	    strcpy(chyear,year);
               	     strcpy(chmonth,month);
               	      strcpy(chday,day);
                if (strlen(pdepartment)==0 && strlen(day)==0 && strlen(year)==0 && strlen(month)==0 && strlen(ttime)==0) {
                	bar(500,505,920,522);
                    setcolor(RED);
                    setbkcolor(15);
                    outtextxy(500, 502, "*fill all the reuired fields");
                }
				else if (strcmp(docdep,pdepartment)!=0)
				{     bar(500,505,920,522);
					  setcolor(RED);
                    setbkcolor(15);
                    outtextxy(500, 505, "*Enter correct department name");
				 } 
				 
else if (
    (strcmp(ttime, "morning") == 0 && (athour < 11 || (athour == 11 && atminute == 0))) ||
    (strcmp(ttime, "afternoon") == 0 && (athour < 14 || (athour == 14 && atminute < 30))) ||
    (strcmp(ttime, "evening") == 0 && (athour < 17 || (athour == 17 && atminute == 0)))
    )
		/*		  else if  (
    (strcmp(ttime, "morning") == 0 && athour < 7) ||
    (strcmp(ttime, "afternoon") == 0 && (athour < 12 )) ||
    (strcmp(ttime, "evening") == 0 && (athour < 15 || (athour == 15 && atminute < 15))) ||
    (strcmp(ttime, "morning") != 0 && strcmp(ttime, "afternoon") != 0 && strcmp(ttime, "evening") != 0)
     )*/
     /*else if  (
    (strcmp(ttime, "morning") == 0 && (athour < 7 || athour > 17)) ||
    (strcmp(ttime, "afternoon") == 0 && (athour < 12 || athour > 17 || (athour == 17 && atminute > 0) || (athour == 12 && atminute < 30))) ||
    (strcmp(ttime, "evening") == 0 && (athour < 15 || athour > 17 || (athour == 15 && atminute < 15))) ||
    (strcmp(ttime, "morning") != 0 && strcmp(ttime, "afternoon") != 0 && strcmp(ttime, "evening") != 0)
)*/

				 {
				 	bar(500,505,920,522);				 	
				 	setcolor(RED);
                    setbkcolor(15);
                    outtextxy(500, 505, "*Enter correct shift");
				 }
				 else if ((strcmp(chyear,curyear)!=0) || (strcmp(chmonth,curmonth)!=0)||(strcmp(chday,curday)!=0))
				 {
				 	bar(500,505,920,522);
					setcolor(RED);
                    setbkcolor(15);
                    outtextxy(500, 505, "*Enter correct date");
				 }
				 else{
                    setfillstyle(1, WHITE);
                      bar(499, 669, 1000, 800);
                     sprintf(tdate, "%s-%s-%s", year, month, day);
                    if(strcmp(ttime,"morning")==0)
                    {
                    	strcpy(ttime,"7:00-11:00");
					}              
					else if(strcmp(ttime,"evening")==0){
						strcpy(ttime,"3:15-5:00");
					}
				    else if (strcmp(ttime,"afternoon")==0)
                    {                                   
                    	strcpy(ttime,"12:00-2:30");
					}
					 psigncondition= false; 
					 return 1;
            }
            }
            // for sidebar buttons click
            if ((p.x >= 10 && p.x <= 120 && p.y >= 350 && p.y <= 390) || (p.x >= 25 && p.x <= 115 && p.y >= 650 && p.y <= 690) || (p.x >= 10 && p.x <= 137 && p.y >= 550 && p.y <= 601 )) {
                psigncondition = false;
                return 2;
            }
        }
         // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                mousebtndwn = false;
            }
    }
}

 void DTHOME::dthome2() {

	setfillstyle(1,WHITE);
    bar(151,101,1280,720);    	
hdbox(170,120,570,1050);
setcolor(RED);
setbkcolor(3);
outtextxy(210,130,"Patient's attendance:");
setcolor(0);
setbkcolor(15);
setcolor(LIGHTGRAY);
textfield(480, 440, 50, 400);
textfield(480, 360, 50, 400);
button(530,525,50,300);
colored_button(950,625,50,250,LIGHTBLUE);
	settextstyle(4,0,2);
	setbkcolor(CYAN);
	setcolor(15);
	outtextxy(625,535,"Submit");
		setbkcolor(LIGHTBLUE);
	outtextxy(1005,640,"Confirm >");
	setbkcolor(15);
	  settextstyle(3, 0, 1);
       setcolor(DARKGRAY);
       outtextxy(480, 340, "Token number:");
       outtextxy(480, 420, "Patient's name:");
}

bool DTHOME::checkrecord()
{
	count+=1;
	char firstName[50],department[50], date[50], timeSlot[50],tkno[50];
    fstream appointmentFile("ptapprec.bin", ios::in | ios::binary);
              appointmentFile.seekg(0, ios::beg);
             if (appointmentFile) {
             string record;
             while (getline(appointmentFile, record, '\n')) {
            stringstream recordStream(record);
            recordStream.getline(firstName, sizeof(firstName), '\0');
            recordStream.getline(tkno, sizeof(tkno), '\0');
            recordStream.getline(department, sizeof(department), '\0');
            recordStream.getline(date, sizeof(date), '\0');
            recordStream.getline(timeSlot, sizeof(timeSlot), '\0'); 
            if(strcmp(department,pdepartment)==0 && strcmp (date,tdate)==0 && strcmp(timeSlot,ttime)==0)
            {	
             appointmentFile.close();
			return true; 
			}      
            } 
        appointmentFile.close();
        return false;
    }
    else {
        cerr << "Error opening file" << endl;
    }	
}

bool DTHOME::pptcheckrecord( char name[50], char tko[50])
{     
	    time_t currentTime = std::time(nullptr);
    tm* localTime = std::localtime(&currentTime);

    
    int today = localTime->tm_mday;
	   char userId[50], firstName[50], phoneNumber[50], department[50], date[50], timeSlot[50],tkno[50];
	   
    ifstream appointmentFile("appointments.bin", ios::in | ios::binary);

    appointmentFile.seekg(0, ios::beg);
    if (appointmentFile) {
        string record;
        int i=0;
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
            if((strcmp(firstName,pname)==0) && (strcmp (tkno,tko)==0) && (strcmp(pdepartment,department)==0)&&(strcmp(timeSlot,ttime)==0) &&(today==extracted_dateInt))  
            {
              appointmentFile.close();
             return true;
			}      
            } 
        appointmentFile.close();
        return false;
    }
    else {
        cerr << "Error opening file" << endl;
    }	
}



int DTHOME::ptnamefillclick() {	
memset(pname, 0, sizeof(pname));
memset(ptkno, 0, sizeof(ptkno));
mousebtndwn=false;
	psigncondition = true;
    while (psigncondition) {
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(GetForegroundWindow(), &p);
        if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !mousebtndwn) {
        mousebtndwn=true;
            // name
            if (p.x >= 480 && p.x <= 880 && p.y >= 440 && p.y <= 490) {
                clickedtextfield(480,440,50,400);
                setfillstyle(1, WHITE);
                    bar(499, 584, 1000, 615);
                text_input(480,440,50,400, pname);
            }

            // token no.
            if (p.x >= 480 && p.x <= 880 && p.y >= 360 && p.y <= 410) {
                clickedtextfield(480, 360, 50, 400);
                setfillstyle(1, WHITE);
                bar(499, 584, 1000, 615);
                text_input(480, 360, 50, 400, ptkno);
            }
  
            // submit
            if (p.x >= 530 && p.x <= 830 && p.y >= 520 && p.y <= 575) { 
              clickedbutton(530,525, 50, 300);
                setfillstyle(1, WHITE);
                bar(499, 584, 1000, 615);
                delay(40);
                button(530,525, 50, 300);
                settextstyle(4,0,2);
              	setbkcolor(CYAN);
	            setcolor(15);
	            outtextxy(625,535,"Submit");
	            bool pptrcheck=pptcheckrecord(pname,ptkno);
	            bool ptnostatus=false;
	            bool st=checkrecord();
	    
	            if(st==true && count==1)
	            { 
				setfillstyle(1,15);
				  bar(500,505,920,522);
					setcolor(RED);
                    setbkcolor(WHITE);
                    delay(100);
	             	outtextxy(500, 505, "*data is already given");
	             	psigncondition= false; 
	             	return 0;
	            }
	            
	           if (strlen(pname)==0 && strlen(ptkno)==0 ) {
	           	setfillstyle(1,15);
	           	bar(500,505,920,522);
                    setcolor(RED);
                    setbkcolor(WHITE);
                    outtextxy(500, 505, "*fill all the required fields");
                } 
                else
                {  
	
				if(pptrcheck==true)
				{
						 setfillstyle(1, WHITE);
				bar(482,362,878,408);
                bar(482,442,878,488);	
                setcolor(GREEN);
                    setbkcolor(WHITE);
                    outtextxy(500, 505, "*data stored enter next data!");
                  	ofstream fout;
				   fout.open("ptapprec.bin", ios::out | ios::app | ios::binary);
                if (fout) {
             fout.seekp(0, ios::end);
             fout.write(pname, strlen(pname) + 1);
    fout.write(ptkno, strlen(ptkno) + 1);
    fout.write(pdepartment, strlen(pdepartment) + 1);
    fout.write(tdate, strlen(tdate) + 1);
    fout.write(ttime, strlen(ttime) + 1);
             fout.put('\n');
            fout.close();
        }
		 else {
            cerr << "Error opening file for writing" << endl;
          }			
				}
				else
				{   setfillstyle(1,15);
				    bar(500,505,920,522);
					setcolor(RED);
                    setbkcolor(WHITE);
	             	outtextxy(500, 505, "*please enter correct data");	
				}

        }	
                memset(pname, 0, sizeof(pname));
                memset(ptkno, 0, sizeof(ptkno));
        button(530,525, 50, 300);
			}

            //continue button
               if (p.x >= 950 && p.x <= 1200 && p.y >= 625 && p.y <= 675) {
               	clickedbutton(950,625,50,250);
               	setfillstyle(1, WHITE);
                bar(499, 584, 1000, 615);
                delay(40);
                button(950,625,50,250);
                settextstyle(4,0,2);
	            setcolor(15);
		        setbkcolor(CYAN);
	            outtextxy(1005,640,"Confirm >");
				psigncondition= false; 
				return 1;
            }
            // for sidebar buttons click
            if ((p.x >= 10 && p.x <= 120 && p.y >= 350 && p.y <= 390) || (p.x >= 25 && p.x <= 115 && p.y >= 650 && p.y <= 690)) {
                psigncondition = false;
            }

            delay(10);
        }
         // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                mousebtndwn = false;
            }
    }
}


void DTHOME::attendance_list()
{
		    time_t currentTime = std::time(nullptr);
    tm* localTime = std::localtime(&currentTime);

    
    int today_for_att = localTime->tm_mday;
		setfillstyle(1,WHITE);
    bar(151,101,1280,720);   
	hdbox(170,120,570,1050);
setcolor(RED);
setbkcolor(3);
outtextxy(210,130,"Patient's attendance:");
setcolor(LIGHTGRAY);
setlinestyle(0,0,2);
rectangle(200,270,1180,580);
line(200,310,1180,310);
line(360,271,360,580);
char clists[50];
int ycoord=0;
setcolor(0);
setbkcolor(15);

    ifstream patientFile("ptapprec.bin", ios::in | ios::binary);
    if (patientFile) {
        char patientName[50];
        char patientToken[20];
        char patientDepartment[50];
        char appointmentDate[20];
        char appointmentTime[20];

        // Read each field individually in a loop
        while (true) {
            patientFile.getline(patientName, sizeof(patientName), '\0');
            patientFile.getline(patientToken, sizeof(patientToken), '\0');
            patientFile.getline(patientDepartment, sizeof(patientDepartment), '\0');
            patientFile.getline(appointmentDate, sizeof(appointmentDate), '\0');
            patientFile.getline(appointmentTime, sizeof(appointmentTime), '\0');

            if (patientFile.eof()) {
                break; 
            }
            
           char extracted_date[3];
           strncpy(extracted_date, appointmentDate + strlen(appointmentDate) - 2, 2);
           extracted_date[2] = '\0'; 
           int extracted_dateInt = atoi(extracted_date);
            if ((strcmp(patientDepartment, pdepartment) == 0) && (strcmp(appointmentTime,ttime)==0)&& (extracted_dateInt==today_for_att)) {
                outtextxy(375, 320 + ycoord, patientName);
                outtextxy(220,320+ycoord,patientToken);
                ycoord += 20;
            }
        }

        patientFile.close();
    } else {
        cerr << "Error opening file for reading" << endl;
    }


/*
for (int lists=0;lists<=11;lists++)
{
	sprintf(clists,"%d",lists+1);
if (lists<9)
{
outtextxy(220,320+ycoord,"0");
outtextxy(240,320+ycoord,clists);
}
else if(lists>=9)
{
	outtextxy(220,320+ycoord,clists);
}
outtextxy(375,320+ycoord,"patient name");
ycoord+=20;
}*/
setcolor(0);
setbkcolor(15);
outtextxy(380,185,pdepartment);
outtextxy(900,185,tdate);
outtextxy(300,220,ttime);
setcolor(BLUE);
outtextxy(200,185,"Department:");
outtextxy(800,185,"Date:");
outtextxy(200,220,"shift:");
outtextxy(210,280,"Token no");
outtextxy(555,280,"Patient's Name");
setcolor(15);
setbkcolor(LIGHTBLUE);
outtextxy(597,640,"Confirm >");
colored_button(530,625, 50, 300,LIGHTBLUE);
}


int DTHOME::attendance_listclick()
{
mousebtndwn=false;
	psigncondition = true;
    while (psigncondition) {
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(GetForegroundWindow(), &p);
        if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !mousebtndwn) {
        mousebtndwn=true;
          
            //continue button
              if (p.x >= 530 && p.x <= 830 && p.y >= 625 && p.y <= 675) { 
               	clicked_colored_button(530,625, 50, 300,LIGHTBLUE);
               	setfillstyle(1, WHITE);
                bar(499, 584, 1000, 615);
                delay(40);
                colored_button(530,625, 50, 300,LIGHTBLUE);
                settextstyle(4,0,2);
	            setcolor(15);
		        setbkcolor(CYAN);
	            outtextxy(597,640,"Confirm >");
				psigncondition= false; 
				return 1;
            }
            
            // for sidebar buttons click
            if ((p.x >= 10 && p.x <= 120 && p.y >= 350 && p.y <= 390) || (p.x >= 25 && p.x <= 115 && p.y >= 650 && p.y <= 690)) {
                psigncondition = false;
            }

            delay(10);
        }
         // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                mousebtndwn = false;
            }
    }
}


    void DTHOME::changepassword(char drid[50])  {
    	  memset(did,0,sizeof(did));
	   strcpy(did,drid);
    setfillstyle(1,WHITE);
    bar(151,101,1280,720); 	
	hdbox(170,120,570,1050);
	  settextstyle(4, 0, 2);
	  setbkcolor(LIGHTGRAY);
    setcolor(CYAN);
    outtextxy(583, 77, "Password");
setcolor(RED);
setbkcolor(3);
outtextxy(210,130,"Change Password:");
readimagefile("images/change.jpg",620,200,720,300);
          textfield(480,340,50,400);
          textfield(480,420,50,400);
          setcolor(RED);
          button(480,520,50,400);   
    setcolor(LIGHTGRAY);
     settextstyle(3, 0, 1);
     setbkcolor(15);
     setcolor(DARKGRAY);
     outtextxy(480, 320, "New Password:");
     outtextxy(480, 400, "Confirm Password:");
    settextstyle(4, 0, 2);
    setbkcolor(CYAN);
    setcolor(15);
    outtextxy(550, 530, "Change Password");
     setbkcolor(LIGHTGRAY);
}




 void DTHOME::changepasswordclick()
 {
 	memset(newpassword, 0, sizeof(newpassword));
memset(connewpassword, 0, sizeof(connewpassword));
 char fileid[50];
    char filename[100];
    char filepassword[100];
    char filedepartment[50];
    char filedayshift[4][20];
    char filetimeshift[2][20];
mousebtndwn=false;
	psigncondition = true;
    while (psigncondition) {
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(GetForegroundWindow(), &p);
        if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !mousebtndwn) {
        mousebtndwn=true;
        
            // newpassword
            if (p.x >= 480 && p.x <= 880 && p.y >= 340 && p.y <= 390) {
                clickedtextfield(480,340,50,400);
                setfillstyle(1, WHITE);
                    bar(484, 484, 1000, 505);
                text_input(480,340,50,400, newpassword);
            }

            // confirm newpassword
            if (p.x >= 480 && p.x <= 880 && p.y >= 420 && p.y <= 470) {
                clickedtextfield(480, 420, 50, 400);
                setfillstyle(1, WHITE);
                bar(484, 484, 1000, 505);
                text_input(480, 420, 50, 400, connewpassword);
            }


            // change password button
            if (p.x >= 480 && p.x <= 880 && p.y >= 520 && p.y <= 570) { 
                clickedbutton(480,520, 50, 400);
                setfillstyle(1, WHITE);
                bar(484, 484, 1000, 505);
                button(480,520, 50, 400);
                settextstyle(4, 0, 2);
                setbkcolor(CYAN);
                setcolor(15);
                outtextxy(550, 530, "Change Password");
                if(newpassword[0] == '\0' || connewpassword[0] == '\0')
                {
                	setcolor(RED);
                    setbkcolor(WHITE);
	             	outtextxy(500, 485, "*please fill all field");	
				}
      else if(strcmp(newpassword,connewpassword)==0)
	  {
	  	 ifstream fin;
	  fin.open("doctor.bin", ios::in | ios::binary);
	  ofstream fout;
	  fout.open("tempo.bin", ios::out | ios::app | ios::binary);
    if (fin) {
    	fin.seekg(0, ios::beg);
    while (fin.peek() != EOF) {
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
        if (fin.fail()) { cout<<"fail\n";
		}
        fin.getline(filename, sizeof(filename), '\0');
        if (fin.fail()) { cout<<"fail\n";
		}
        fin.getline(filepassword, sizeof(filepassword), '\0');
        if (fin.fail()) { cout<<"fail\n";
		}
        fin.getline(filedepartment, sizeof(filedepartment), '\0');
        if (fin.fail())  { cout<<"fail\n";
		}

        for (int i = 0; i < 4; ++i) {
            fin.getline(filedayshift[i], sizeof(filedayshift[i]), '\0');
            if (fin.fail())  { cout<<"fail\n";
		}
            if (strcmp(filedayshift[i], "null") == 0) {
                filedayshift[i][0] = '\0';
            }
        }

        for (int i = 0; i < 2; ++i) {
            fin.getline(filetimeshift[i], sizeof(filetimeshift[i]), '\0');
            if (fin.fail()) { cout<<"fail\n";
		}
            if (strcmp(filetimeshift[i], "null") == 0) {
                filetimeshift[i][0] = '\0';
            }
        }
        fin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (strcmp(fileid, did) == 0) {
                strcpy(filepassword,newpassword);
            }
            
                if (fout) {
            fout.seekp(0, ios::end);
            fout.write( fileid, strlen( fileid) + 1);
    fout.write(filename, strlen(filename) + 1);
    fout.write(filepassword, strlen(filepassword) + 1);
    fout.write(filedepartment, strlen(filedepartment) + 1);
        for (int i = 0; i < 4; i++) {
        	if(filedayshift[i][0]=='\0')
        	{
        		strcpy(filedayshift[i],"null");
			}
                fout.write(filedayshift[i], strlen(filedayshift[i]) + 1);
        }
        for (int i = 0; i < 2; ++i) {
        	if(filetimeshift[i][0]=='\0')
        	{
        		strcpy(filetimeshift[i],"null");
			}
                fout.write(filetimeshift[i], strlen(filetimeshift[i]) + 1);
        }
             fout.put('\n');
        }
    }
        fin.close();
        fout.close();
        remove("doctor.bin");
        rename("tempo.bin", "doctor.bin");
        setbkcolor(WHITE);
        setfillstyle(1,WHITE);
        bar(482,422,878,468);
        bar(482,342,878,388);
        psigncondition=false;
		 }
		 else {
            cerr << "Error opening file" << endl;
        }
				 }
				 
				 else
				 {
				 	setcolor(RED);
                    setbkcolor(WHITE);
	             	outtextxy(500, 485, "*please enter same password");	
							}           
	       }
	       
	       
            // for sidebar buttons click
            if ((p.x >= 10 && p.x <= 120 && p.y >= 350 && p.y <= 390) || (p.x >= 10 && p.x <= 120 && p.y >= 350 && p.y <= 390) || (p.x >= 25 && p.x <= 115 && p.y >= 650 && p.y <= 690)) {
                psigncondition = false;
            }

            delay(10);
        }
         // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                mousebtndwn = false;
            }
    }
 }

