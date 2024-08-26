#include"ptdashboard.h"
#include"ptlogin.h"
#include <graphics.h>
#include<cstring>
#include "layouts.h"
#include<iostream>
#include<fstream>
#include<limits>
#include<ctime>

using namespace std;
 void PTDASHBOARD::ptdashboard(char userID[50])
 {
 	memset(ptname,0,sizeof(ptname));
 	strcpy(ptname,userID);
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
        setbkcolor(CYAN);
      outtextxy(20, 650, "Logout");
setcolor(WHITE);
setbkcolor(CYAN);
settextstyle(4,0,1);
outtextxy(25,250,"Home");
outtextxy(25,350,"Appoint");
outtextxy(25,450,"About");
outtextxy(10,600,"dashboard");
 }   


bool PTDASHBOARD::infodashboard()
{
setfillstyle(1,WHITE);
bar(151,101,1280,720);	
setbkcolor(LIGHTGRAY);
setcolor(CYAN);
 settextstyle(4, 0, 3);
    outtextxy(625, 76, "Profile");
    
// Set up graphics and text styles
setbkcolor(LIGHTGRAY);
settextstyle(4, 0, 1);
outtextxy(610, 77, "Dashboard");
hdbox(170, 120, 570, 1050);
setcolor(RED);
setbkcolor(3);
outtextxy(210, 130, "Profile:");

// Display patient image
readimagefile("images/patient.jpg", 180, 205, 280, 305);
setcolor(LIGHTGRAY);
setlinestyle(0,0,2);
line(171,315,1220,315);
  char temp_fileusername[50];
// Open the patient binary file
ifstream fin;
fin.open("patient.bin", ios::in | ios::binary);
if (fin) {
    char fileusername[50];
    char filename[100];
    char filephonenumber[20];
    char filepassword[100];
    // Loop to read each record in the file
    while (fin.peek() != EOF) {
        // Initialize arrays to empty strings
        memset(fileusername, '\0', sizeof(fileusername));
        memset(filename, '\0', sizeof(filename));
        memset(filephonenumber, '\0', sizeof(filephonenumber));
        memset(filepassword, '\0', sizeof(filepassword));

        // Read data from the file
        fin.read(fileusername, sizeof(fileusername));
        fin.read(filename, sizeof(filename));
        fin.read(filephonenumber, sizeof(filephonenumber));
        fin.read(filepassword, sizeof(filepassword));

        fin.ignore(numeric_limits<streamsize>::max(), '\n');
        strcpy(temp_fileusername, fileusername);
        // Check if the patient ID matches the globalPatientID
        if (strcmp(fileusername, ptname) == 0) {
            // Display patient information on the graphics screen
            setcolor(0);
            setbkcolor(15);
            settextstyle(4, 0, 2);
             outtextxy(410,200, filename);
            outtextxy(520, 240, filephonenumber);
           
            setbkcolor(15);
            setcolor(CYAN);
             outtextxy(300, 200, "Mr./Ms. ");
            outtextxy(300, 240, "Phone Number:");
	setbkcolor(15);
    setcolor(CYAN);
     outtextxy(180, 340, "Appointment information: ");
	settextstyle(4,0,3);
	setcolor(DARKGRAY);
	readimagefile("images/not_appointed.jpg",625,400,725,500);
     outtextxy(450,540,"No appointments scheduled");
        }
    }
    fin.close();
} else {
    cerr << "Error opening file for printing" << endl;
}

  	   time_t currentTime = std::time(nullptr);
    tm* localTime = std::localtime(&currentTime);
      int appoint_day = localTime->tm_mday;
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
               if (strcmp(ptname, userId) == 0 && extracted_dateInt>=appoint_day)  {
               	setfillstyle(1,15);
               	bar(180,320,1100,600);
            setcolor(0);
            setbkcolor(15);
            settextstyle(4, 0, 2);
             outtextxy(450,400, department);
            outtextxy(450, 440, date);
              outtextxy(450, 480, timeSlot);
              outtextxy(450, 520, tkno);
            setbkcolor(15);
            setcolor(CYAN);
             outtextxy(180, 340, "Appointment information: ");
             outtextxy(180, 400, "Department Name: ");
            outtextxy(180, 440, "Appointment Date:");
            outtextxy(180, 480, "Appointment time:");
             outtextxy(180, 520, "Token Number:");
            colored_button(540,610,50,300,RED);
            setbkcolor(RED);
           setcolor(WHITE);
           settextstyle(4,0,1);
           outtextxy(550,625,"Cancel Appointment");   
           appointmentFile.close();
           return true;
        }      
        }
        appointmentFile.close();
        return false;
    } else {
        cerr << "Error opening file" << endl;
    }
}

 int PTDASHBOARD::cancelclick()
 {
 	    char userId[50], firstName[50], phoneNumber[50], department[50], date[50], timeSlot[50],tkno[50];
 	    char dummydepartment[50],dummydate[50],dummytime[50];
    int count=0;
     	 btdown=false;
		 cancelcondition= true;
	 while (cancelcondition) {

            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);
            // Check if the left mouse button is pressed
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !btdown) {
                btdown = true;
                                // cancel button
         if ((p.x >= 540 && p.x <= 840) && (p.y >= 610 && p.y <= 660))
        {
    fstream appointmentFile("appointments.bin", ios::in | ios::binary);
      ofstream tempFile("temp.bin", ios::out | ios::binary);
    appointmentFile.seekg(0, ios::beg);
    if (appointmentFile) {
        string record;
        bool found = false;
        while (getline(appointmentFile, record, '\n')) {
            stringstream recordStream(record);
            recordStream.getline(userId, sizeof(userId), '\0');
            recordStream.getline(firstName, sizeof(firstName), '\0');
            recordStream.getline(tkno, sizeof(tkno), '\0');
            recordStream.getline(phoneNumber, sizeof(phoneNumber), '\0');
            recordStream.getline(department, sizeof(department), '\0');
            recordStream.getline(date, sizeof(date), '\0');
            recordStream.getline(timeSlot, sizeof(timeSlot), '\0');
          if(strcmp(ptname,userId)==0)
          {
          	strcpy(dummydepartment,department);
          	strcpy(dummydate,date);
          	strcpy(dummytime,timeSlot);
          	found=true;
		    count=-1;
             continue;
        }
        int token = atoi(tkno);
        if(strcmp(department,dummydepartment)==0 && strcmp(date,dummydate)==0 && strcmp(timeSlot,dummytime)==0)
        {
         token+=count;	
		}
        sprintf(tkno, "%d", token);
    tempFile.write(userId, strlen(userId) + 1);
    tempFile.write(firstName, strlen(firstName) + 1);
    tempFile.write(tkno, strlen(tkno) + 1);
    tempFile.write(phoneNumber, strlen(phoneNumber) + 1);
    tempFile.write(department, strlen(department) + 1);
     tempFile.write(date, strlen(date) + 1);
     tempFile.write(timeSlot, strlen(timeSlot) + 1);
    tempFile.put('\n');
    }
    appointmentFile.close();
    tempFile.close();
         if (found) {
         	cout<<"found"<<endl;
        remove("appointments.bin");
        rename("temp.bin", "appointments.bin");
            cancelcondition=false;
            return 1;
        }
        else
        {
        	cout<<"notfound"<<endl;
           remove("temp.bin");	
           cancelcondition=false;
           return 3;
		}
    }
    }
				  
				    // for sidebar buttons click
            if ((p.x >= 25 && p.x <= 105 && p.y >= 250 && p.y <= 270) || (p.x >= 25 && p.x <= 125 && p.y >= 350 && p.y <= 370) ||(p.x >= 25 && p.x <= 105 && p.y >= 450 && p.y <= 470) ||(p.x >= 20 && p.x <= 125 && p.y >= 650 && p.y <= 670)) {
				cancelcondition = false;
            }
 
}
          // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
               btdown = false;
            }
    }
}
 

bool PTDASHBOARD::dashboardclick()
{
	ptabout();
	bool as;
	mouseDown=false;
	dashcondition=true;
   while (dashcondition) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

            // Check if the left mouse button is pressed
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !mouseDown) {
                mouseDown = true;

  // Check if the click is user icon
                if (p.x >= 1202 && p.x <= 1250 && p.y >= 30 && p.y <= 80) {
                    userbuttons = !userbuttons;
                    displayuserbuttons();
                }
                
                                // home
                if (p.x >= 25 && p.x <= 105 && p.y >= 250 && p.y <= 270) {
                    userbuttons = false;
                    displayuserbuttons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(610,77,750,98);
                    pthome();
                    int a=homebtnclick();
                    if(a==1)
                    {
                    	goto app;
					}
                }
                //appoint
                if (p.x >= 25 && p.x <= 125 && p.y >= 350 && p.y <= 370) {
                	app:
                    userbuttons = false;
                    displayuserbuttons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(610,77,750,98);
					ptappoint(true,ptname); 
					int b = appointclick();
					if(b==1)
					{
						goto das;
					}
                }
                
                //about
                if (p.x >= 25 && p.x <= 105 && p.y >= 450 && p.y <= 470) {
                    userbuttons = false;
                    displayuserbuttons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(610,77,750,98);
					ptabout(); 
                }
                
                                //logout
                if (p.x >= 20 && p.x <= 125 && p.y >= 650 && p.y <= 670) {
                    userbuttons = false;
                    displayuserbuttons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(610,77,750,98);
                    dashcondition=false;
                    return false;
                }
                
                                                //dashboard
                if (p.x >= 35 && p.x <= 105 && p.y >= 600 && p.y <= 620) {
                	das:
                    userbuttons = false;
                    displayuserbuttons();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    setfillstyle(1,LIGHTGRAY);
                    bar(610,77,750,98);
		           as= infodashboard();
		           if(as)
		           {
		           	int a;
		           a= cancelclick();
		           if(a==1||a==2)
		           {
		           	goto das;
				   }
				   }
                }
               
            } 

            // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                mouseDown = false;
            }
        }
}

void PTDASHBOARD::displayuserbuttons() {
        if (userbuttons) {
           setcolor(RED);
           setbkcolor(LIGHTGRAY);
           	outtextxy(1078,35,"hi");
           	outtextxy(1078,60,ptname);
        } 
		else {
            setfillstyle(1,LIGHTGRAY);
            bar(1000, 0, 1200, 100);
        }
    }

