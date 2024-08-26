#include "adsignup.h"
#include "layouts.h"
#include <graphics.h>
#include <fstream>
#include "cursorinput.h"
#include <cstring>
#include <iostream>
#include <limits>

using namespace std;


void ADSIGNUP::dsignup() {
    textfield(480, 260, 50, 400);
    textfield(480, 340, 50, 400);
    textfield(480, 420, 50, 400);
    textfield(480, 500, 50, 400);
    button(480, 600, 50, 400);
    settextstyle(3, 0, 1);
    setcolor(DARKGRAY);
    setbkcolor(WHITE);
    outtextxy(480, 240, "Name:");
    outtextxy(480, 320, "Id:");
    outtextxy(480, 400, "Password:");
    outtextxy(480, 480, "Confirm Password:");
    settextstyle(4, 0, 2);
    setbkcolor(CYAN);
    setcolor(15);
    outtextxy(630, 610, "NEXT");
    setbkcolor(LIGHTGRAY);
    setcolor(3);
    settextstyle(4, 0, 2);
    setbkcolor(LIGHTGRAY);
    outtextxy(570, 77, "Add Doctor");
}


int ADSIGNUP::signupclick() {
    
    char confirmPassword[100];
memset(confirmPassword, 0, sizeof(confirmPassword));
memset(dname, 0, sizeof(dname));
memset(doctorid, 0, sizeof(doctorid));
memset(password, 0, sizeof(password));
 int c;
    for (int c = 0; c < 7; c++) {
        day[c][0] = '\0';  
    }

    for (int c = 0; c < 3; c++) {
        ttime[c][0] = '\0'; 
    }
	signcondition = true;
    while (signcondition) {
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(GetForegroundWindow(), &p);
        if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
        

            // doctorname
            if (p.x >= 480 && p.x <= 880 && p.y >= 260 && p.y <= 310) {
                clickedtextfield(480, 260, 50, 400);
                setfillstyle(1, WHITE);
                bar(520, 559, 1200, 595);
                text_input(480, 260, 50, 400, dname);
            }

            // doctorid
            if (p.x >= 480 && p.x <= 880 && p.y >= 340 && p.y <= 390) {
                clickedtextfield(480, 340, 50, 400);
                setfillstyle(1, WHITE);
                bar(520, 559, 1200, 595);
				text_input(480, 340, 50, 400, doctorid);
            }

            // password
            if (p.x >= 480 && p.x <= 880 && p.y >= 420 && p.y <= 470) {
                clickedtextfield(480, 420, 50, 400);
                setfillstyle(1, WHITE);
                bar(520, 559, 1200, 595);
                pwtext_input(480, 420, 50, 400, password);
            }

            // confirm password
            if (p.x >= 480 && p.x <= 880 && p.y >= 500 && p.y <= 550) {
                clickedtextfield(480, 500, 50, 400);
                setfillstyle(1, WHITE);
                bar(520, 559, 1200, 595);
                pwtext_input(480, 500, 50, 400, confirmPassword);
                if (strcmp(confirmPassword, password) != 0) {
                    setcolor(RED);
                    outtextxy(530, 560, "*passwords don't match.");
                } else {
                    setfillstyle(1, WHITE);
                    bar(520, 559, 1200, 595); // Clear pw not match message
                }
            }

            // next button
               if (p.x >= 480 && p.x <= 880 && p.y >= 600 && p.y <= 650) {
 	            bool doctoridExists= false;
                clickedbutton(480, 600, 50, 400);
                delay(100);
                button(480, 600, 50, 400);

                if (strcmp(confirmPassword, password) != 0) {
                    setcolor(RED);
                    setbkcolor(WHITE);
                    outtextxy(530, 560, "*passwords don't match");
                    continue;
                } else if (dname[0] == '\0' || doctorid[0] == '\0' || password[0] == '\0' || confirmPassword[0] == '\0') {
                    setcolor(RED);
                    setbkcolor(WHITE);
                    outtextxy(530, 560, "*fill all the required fields");
                    continue;
                } else {
                    // Check if username already exists
                   ifstream fin;
	  fin.open("doctor.bin", ios::in | ios::binary);
    if (fin) {
    char fileid[50];
    char filename[100];
    char filepassword[100];
    char filedepartment[50];
    char filedayshift[4][20];
    char filetimeshift[2][20];

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
    
             
            if (strcmp(fileid, doctorid) == 0) {
                doctoridExists = true;
                break;
            }
        }
                    if (doctoridExists) {
                        setcolor(RED);
                        outtextxy(530, 560, "*doctorid already exists");
                        delay(10);
                    } 
					else {
                        setfillstyle(1, WHITE);
                        bar(481, 261, 879, 309);
                        bar(481, 341, 879, 389);
                        bar(481, 421, 879, 469);
                        bar(481, 501, 879, 549);
                        setcolor(RED);
                        outtextxy(530, 560, "*successful data entry");
                        fin.close();
                        signcondition = false;
                       return 1;
        }
        fin.close();
		 }
		 else {
            cerr << "Error opening file for writing" << endl;
        }
                    }
                }

            // for sidebar buttons click
            if (p.x >= 25 && p.x <= 130 && p.y >= 250 && p.y <= 290 || p.x >= 25 && p.x <= 120 && p.y >= 350 && p.y <= 390 ||p.x >= 25 && p.x <= 115 && p.y >= 650 && p.y <= 690 || (p.x >= 25 && p.x <= 120 && p.y >= 550 && p.y <= 610) || (p.x >= 25 && p.x <= 130 && p.y >=180 && p.y <= 220)) {
                signcondition = false;
            }

            delay(10);
        }
    }
}


int ADSIGNUP::selectdepartment()
{
setfillstyle(1,WHITE);
bar(151,101,1280,720);
setcolor(CYAN);
setbkcolor(15);
settextstyle(1,0,3);     
outtextxy(510,130,"Select Department!");
setbkcolor(15);
setfillstyle(1,15);
bar(500,220,830,460);
setcolor(0);  
rectangle(500,220,830,460);
//for(int linecoords=0;linecoords<240;linecoords+=40)
//{
//	line(500,220+linecoords,830,220+linecoords);
//}
outtextxy(520,230,"General Medicine");
outtextxy(520,270,"Opthamology");
outtextxy(520,310,"ENT");
outtextxy(520,350,"Cardiology");
outtextxy(520,390,"Gastro Surgery");
outtextxy(520,430,"Neuro Medicine");
 button(480,520,50,400);
    settextstyle(4, 0, 2);
    setbkcolor(CYAN);
    setcolor(15);
    outtextxy(620, 530, "NEXT");
    int p= departmentclick();
    return p;
}

int ADSIGNUP::departmentclick()
{
	bool showbtn=false;
	bool mousebtn=false;
	memset(department,0,sizeof(department));
	scondition= true;
	 while (scondition) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

            // Check if the left mouse button is pressed
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !mousebtn) {
                mousebtn = true;

  // Check if the click is user icon
                if (p.x >= 1202 && p.x <= 1250 && p.y >= 30 && p.y <= 80) {
                    showbtn = !showbtn;
                    displaybtn();
                }

                                // general medicine
                if (p.x >= 500 && p.x <= 830 && p.y >= 230 && p.y <= 250) {
                    showbtn = false;
                    displaybtn(); 
                    strcpy(department,"general medicine");
                    setfillstyle(1,WHITE);
                    bar(849,339,1150,400);
                    setcolor(RED);
                    setbkcolor(WHITE);
                    outtextxy(850,340,department);
					setfillstyle(1,LIGHTCYAN);
                    setbkcolor(WHITE);
                    setcolor(RED);
                    bar(505,220,825,260); 
                    delay(100);
                    setfillstyle(1,WHITE);
                    setbkcolor(WHITE);
                    bar(505,220,825,260); 
                    setcolor(BLACK);
                    settextstyle(1,0,3);
                    outtextxy(520,230,"General Medicine");
                }                                                                                   
                
                //opthalmology
                if (p.x >= 500 && p.x <= 830 && p.y >= 270 && p.y <= 290) {
                    showbtn = false;
                    displaybtn();
                    strcpy(department,"opthalmology"); 
                    setfillstyle(1,WHITE);
                    bar(849,339,1150,400);
                    setcolor(RED);
                    setbkcolor(WHITE);
                    outtextxy(850,340,department);
                    setfillstyle(1,LIGHTCYAN);
                    setbkcolor(WHITE);
                    setcolor(RED);
                    bar(505,260,825,300);
                    delay(100);
                    setfillstyle(1,WHITE);
                    setbkcolor(WHITE);                  
                    bar(505,260,825,300);
                    setcolor(BLACK);
                    settextstyle(1,0,3);
                    outtextxy(520,270,"Opthamology");
                }
                
                //ent
                if (p.x >= 500 && p.x <= 830 && p.y >= 310 && p.y <= 330) {
                    showbtn = false;
                    displaybtn();
                    strcpy(department,"ent"); 
                    setfillstyle(1,WHITE);
                    bar(849,339,1150,400);
                    setcolor(RED);
                    setbkcolor(WHITE);
                    outtextxy(850,340,department);
                    setfillstyle(1,LIGHTCYAN);
                    setbkcolor(WHITE);
                    setcolor(RED);
                    bar(505,300,825,340); 
                    delay(100);
                    setfillstyle(1,WHITE);
                    setbkcolor(WHITE);                   
                    bar(505,300,825,340);
                    setcolor(BLACK);
                    settextstyle(1,0,3);
                    outtextxy(520,310,"ENT");
                }
                
                                //cardiology
                if (p.x >= 500 && p.x <= 830 && p.y >= 350 && p.y <= 370) {
                    showbtn = false;
                    displaybtn();
                    strcpy(department,"cardiology");
                    setfillstyle(1,WHITE);
                    bar(849,339,1150,400);
                    setcolor(RED);
                    setbkcolor(WHITE);
                    outtextxy(850,340,department);
					setfillstyle(1,LIGHTCYAN);
                    setbkcolor(WHITE);
                    setcolor(RED);
                    bar(505,340,825,380); 
                    delay(100);
                    setfillstyle(1,WHITE);
                    setbkcolor(WHITE);                    
                    bar(505,340,825,380);
                    setcolor(BLACK);
                    settextstyle(1,0,3);
                    outtextxy(520,350,"Cardiology");
                }  
                
                      //gastro surgery
                    if (p.x >= 500 && p.x <= 830 && p.y >= 390 && p.y <= 410) {
                    showbtn = false;
                    displaybtn();
                    strcpy(department,"gastro surgery"); 
                    setfillstyle(1,WHITE);
                    bar(849,339,1150,400);
                    setcolor(RED);
                    setbkcolor(WHITE);
                    outtextxy(850,340,department);
                    setbkcolor(WHITE);
                    setcolor(RED);
                    bar(505,380,825,420); 
                    delay(100);
                    setfillstyle(1,WHITE);
                    setbkcolor(WHITE);
                    bar(505,380,825,420);
                    setcolor(BLACK);
                    settextstyle(1,0,3);
                    outtextxy(520,390,"Gastro Surgery");
                    
                }  
                
                //neuro medicicne
                    if (p.x >= 500 && p.x <= 830 && p.y >= 430 && p.y <= 450) {
                    showbtn = false;
                    displaybtn();
                    strcpy(department,"neuro medicine"); 
                    setfillstyle(1,WHITE);
                    bar(849,339,1150,400);
                    setcolor(RED);
                    setbkcolor(WHITE);
                    outtextxy(850,340,department);
                    setfillstyle(1,LIGHTCYAN);
                    setbkcolor(WHITE);
                    setcolor(RED);
                    bar(505,420,825,460); 
                    delay(100);
                    setfillstyle(1,WHITE);
                    setbkcolor(WHITE);
                    bar(505,420,825,460);
                    setcolor(BLACK);
                    settextstyle(1,0,3);
                    outtextxy(520,430,"Neuro Medicine");
                }  
                
                //next
                    if (p.x >= 480 && p.x <= 880 && p.y >= 520 && p.y <= 570) {
                    showbtn = false;
                    displaybtn();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    if(strlen(department)!=0)
                    {
                    scondition=false;
                   int p= chooseshift();
                   return p; 	
					}
					else
					{
						scondition=false;
						  settextstyle(4, 0, 2);
                            setbkcolor(WHITE);
                         setcolor(15);
                       outtextxy(800, 600, "selectdepartment");
					selectdepartment();
					delay(100);
					}
                }
				
				  
                
            } 

            // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                mousebtn = false;
            }
        }
}

int ADSIGNUP::chooseshift()
{
    setfillstyle(1,WHITE);
    bar(151,101,1280,720);
    setbkcolor(15);
  setcolor(CYAN);
    setbkcolor(15);
    settextstyle(1,0,3);
outtextxy(550,130,"Select Shift!");
setbkcolor(LIGHTRED);
setfillstyle(1,LIGHTRED);
bar(500,220,830,460);
setcolor(RED);
outtextxy(1050,650,"RESET");
for(int linecoords=0;linecoords<240;linecoords+=40)
{
	line(500,220+linecoords,830,220+linecoords);
}
rectangle(500,220,830,460);
outtextxy(520,230,"Sunday");
outtextxy(520,270,"Monday");
outtextxy(520,310,"Tuesday");
outtextxy(520,350,"Wednesday");
outtextxy(520,390,"Thursday");
outtextxy(520,430,"Friday");
 button(480,620,50,400);
    settextstyle(4, 0, 2);
    setbkcolor(CYAN);
    setcolor(15);
    outtextxy(580, 630, "ADD DOCTOR");
    setcolor(0);
    setfillstyle(1,YELLOW);
	bar(400,480,576,580);
setbkcolor(YELLOW);
outtextxy(440,520,"Morning");
    setfillstyle(1,LIGHTBLUE);
bar(576,480,752,580);
setbkcolor(LIGHTBLUE);
outtextxy(590,520,"      Day");
setfillstyle(1,LIGHTGREEN);
bar(752,480,930,580);
setbkcolor(LIGHTGREEN);
outtextxy(780,520,"  Night");
setcolor(0);
    line(576,480,576,580);
    line(752,480,752,580);
    rectangle(400,480,930,580);
    int p= shiftclick();
    return p;
}

int ADSIGNUP::shiftclick()
{  
     int c;
    for (int c = 0; c < 7; c++) {
        day[c][0] = '\0';  
    }

    for (int c = 0; c < 3; c++) {
        ttime[c][0] = '\0'; 
    }
   	bool showbtn=false;
	bool mousebtn=false;
	int d=0, t=0;
	scondition= true;
	while (scondition) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

            // Check if the left mouse button is pressed
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !mousebtn) {
                mousebtn = true;

  // Check if the click is user icon
                if (p.x >= 1202 && p.x <= 1250 && p.y >= 30 && p.y <= 80) {
                    showbtn = !showbtn;
                    displaybtn();
                }

                                // sunday
                if (p.x >= 500 && p.x <= 830 && p.y >= 230 && p.y <= 250) {
                    showbtn = false;
                    displaybtn();
					if((strcmp(day[0],"sunday")!=0)&& (strcmp(day[1],"sunday")!=0)&& (strcmp(day[2],"sunday")!=0) && (strcmp(day[3],"sunday")!=0))
					{
                    upa:
                    switch (d)
                    {
                      case 0:
					   strcpy(day[d],"sunday");
					   setfillstyle(1,WHITE);
					   bar(849,229,1100,260);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,230,day[d]);
                    	d+=1;	                    	
                    	break;
                    	
                    	case 1:
					  strcpy(day[d],"sunday");
					  	setfillstyle(1,WHITE);
					  bar(849,269,1100,300);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,270,day[d]);
                    	d+=1;	
                    	break;  
						
						case 2:
						strcpy(day[d],"sunday");
					  	setfillstyle(1,WHITE);
					    bar(849,309,1100,329);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,310,day[d]);
                    	d+=1;	
                    	break; 
						
						case 3:
						strcpy(day[d],"sunday");
					  	setfillstyle(1,WHITE);
					    bar(849,349,1100,369);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,350,day[d]);
                    	d+=1;	
                    	break;     
						
						default:
						d=0;
						goto upa;           		
					}
                }    
			}

                //monday
                if (p.x >= 500 && p.x <= 830 && p.y >= 270 && p.y <= 290) {
                	app:
                    showbtn = false;
                    displaybtn();
                    if((strcmp(day[0],"monday")!=0)&& (strcmp(day[1],"monday")!=0)&& (strcmp(day[2],"monday")!=0) && (strcmp(day[3],"monday")!=0))
                    {
                    upb:
                    switch (d)
                    {
                      case 0:
					   strcpy(day[d],"monday");
					   setfillstyle(1,WHITE);
					   bar(849,229,1100,260);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,230,day[d]);
                    	d+=1;	
                    	break;
                    	
                    	case 1:
					  strcpy(day[d],"monday");
					  	setfillstyle(1,WHITE);
					  bar(849,269,1100,300);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,270,day[d]);
                    	d+=1;	
                    	break;  
						
						case 2:
						strcpy(day[d],"monday");
					  	setfillstyle(1,WHITE);
					    bar(849,309,1100,329);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,310,day[d]);
                    	d+=1;	
                    	break; 
						
						case 3:
						strcpy(day[d],"monday");
					  	setfillstyle(1,WHITE);
					    bar(849,349,1100,369);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,350,day[d]);
                    	d+=1;	
                    	break;     
						
						default:
						d=0;
						goto upb;           		
					}
                }
            }
                
                //tuesday
                if (p.x >= 500 && p.x <= 830 && p.y >= 310 && p.y <= 330) {
                    showbtn = false;
                    int a=0;
                    displaybtn();
                    if((strcmp(day[0],"tuesday")!=0)&& (strcmp(day[1],"tuesday")!=0)&& (strcmp(day[2],"tuesday")!=0) && (strcmp(day[3],"tuesday")!=0))
                    {
                    upc:
                    switch (d)
                    {
                      case 0:
					   strcpy(day[d],"tuesday");
					   setfillstyle(1,WHITE);
					   bar(849,229,1100,260);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,230,day[d]);
                    	d+=1;	
                    	break;
                    	
                    	case 1:
					  strcpy(day[d],"tuesday");
					  	setfillstyle(1,WHITE);
					  bar(849,269,1100,300);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,270,day[d]);
                    	d+=1;	
                    	break;  
						
						case 2:
						strcpy(day[d],"tuesday");
					  	setfillstyle(1,WHITE);
					    bar(849,309,1100,329);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,310,day[d]);
                    	d+=1;	
                    	break; 
						
						case 3:
						strcpy(day[d],"tuesday");
					  	setfillstyle(1,WHITE);
					    bar(849,349,1100,369);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,350,day[d]);
                    	d+=1;	
                    	break;     
						
						default:
						d=0;
						goto upc;           		
					}
                }
            }
                
                                //wednesday
                if (p.x >= 500 && p.x <= 830 && p.y >= 350 && p.y <= 370) {
                    showbtn = false;
                    displaybtn();
                    if((strcmp(day[0],"wednesday")!=0)&& (strcmp(day[1],"wednesday")!=0)&& (strcmp(day[2],"wednesday")!=0) && (strcmp(day[3],"wednesday")!=0))
                    {
                    upd:
                    switch (d)
                    {
                      case 0:
					   strcpy(day[d],"wednesday");
					   setfillstyle(1,WHITE);
					   bar(849,229,1100,260);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,230,day[d]);
                    	d+=1;	
                    	break;
                    	
                    	case 1:
					  strcpy(day[d],"wednesday");
					  	setfillstyle(1,WHITE);
					  bar(849,269,1100,300);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,270,day[d]);
                    	d+=1;	
                    	break;  
						
						case 2:
						strcpy(day[d],"wednesday");
					  	setfillstyle(1,WHITE);
					    bar(849,309,1100,329);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,310,day[d]);
                    	d+=1;	
                    	break; 
						
						case 3:
						strcpy(day[d],"wednesday");
					  	setfillstyle(1,WHITE);
					    bar(849,349,1100,369);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,350,day[d]);
                    	d+=1;	
                    	break;     
						
						default:
						d=0;
						goto upd;           		
					}
                }  
            }
                
                      //thursday
                    if (p.x >= 500 && p.x <= 830 && p.y >= 390 && p.y <= 410) {
                    showbtn = false;
                    displaybtn();
                    if((strcmp(day[0],"thursday")!=0)&& (strcmp(day[1],"thursday")!=0)&& (strcmp(day[2],"thursday")!=0) && (strcmp(day[3],"thursday")!=0))
                    {
                    upe:
                    switch (d)
                    {
                      case 0:
					   strcpy(day[d],"thursday");
					   setfillstyle(1,WHITE);
					   bar(849,229,1100,260);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,230,day[d]);
                    	d+=1;	
                    	break;
                    	
                    	case 1:
					  strcpy(day[d],"thursday");
					  	setfillstyle(1,WHITE);
					  bar(849,269,1100,300);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,270,day[d]);
                    	d+=1;	
                    	break;  
						
						case 2:
						strcpy(day[d],"thursday");
					  	setfillstyle(1,WHITE);
					    bar(849,309,1000,329);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,310,day[d]);
                    	d+=1;	
                    	break; 
						
						case 3:
						strcpy(day[d],"thursday");
					  	setfillstyle(1,WHITE);
					    bar(849,349,1100,369);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,350,day[d]);
                    	d+=1;	
                    	break;     
						
						default:
						d=0;
						goto upe;           		
					}
                }  
            }
                
                //friday
                    if (p.x >= 500 && p.x <= 830 && p.y >= 430 && p.y <= 450) {
                    showbtn = false;
                    displaybtn();
                    if((strcmp(day[0],"friday")!=0)&& (strcmp(day[1],"friday")!=0)&& (strcmp(day[2],"friday")!=0) && (strcmp(day[3],"friday")!=0))
                    {                  						
                    upf:
                    switch (d)
                    {
                      case 0:
					   strcpy(day[d],"friday");
					   setfillstyle(1,WHITE);
					   bar(849,229,1100,260);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,230,day[d]);
                    	d+=1;	
                    	break;
                    	
                    	case 1:
					  strcpy(day[d],"friday");
					  	setfillstyle(1,WHITE);
					  bar(849,269,1100,300);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,270,day[d]);
                    	d+=1;	
                    	break;  
						
						case 2:
						strcpy(day[d],"friday");
					  	setfillstyle(1,WHITE);
					    bar(849,309,1100,329);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,310,day[d]);
                    	d+=1;	
                    	break; 
						
						case 3:
						strcpy(day[d],"friday");
					  	setfillstyle(1,WHITE);
					    bar(849,349,1100,369);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(850,350,day[d]);
                    	d+=1;	
                    	break;     
						
						default:
						d=0;
						goto upf;           		
					}
                }  
            }
                
                //morning
                    if (p.x >= 400 && p.x <= 576 && p.y >= 480 && p.y <= 580) {
                    showbtn = false;
                    displaybtn();
                    if((strcmp(ttime[0],"morning")!=0)&& (strcmp(ttime[1],"morning")!=0))
                    {
                    upg:
                    switch (t)
                    {
                      case 0:
					   strcpy(ttime[t],"morning");
					   setfillstyle(1,WHITE);
					   bar(949,479,1150,579);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(950,480,ttime[t]);
                    	t+=1;	
                    	break;
                    	
                    	case 1:
					  strcpy(ttime[t],"morning");
					  	setfillstyle(1,WHITE);
					  bar(949,579,1150,620);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(950,580,ttime[t]);
                    	t+=1;	
                    	break;     
						
						default:
						t=0;
						goto upg;           		
					}
                } 	
			}
				//afternoon
				    if (p.x >= 576 && p.x <= 752 && p.y >= 480 && p.y <= 580) {
                    showbtn = false;
                    displaybtn();
                    if((strcmp(ttime[0],"afternoon")!=0)&& (strcmp(ttime[1],"afternoon")!=0))
                    {
                    uph:
                    switch (t)
                    {
                      case 0:
					   strcpy(ttime[t],"afternoon");
					   setfillstyle(1,WHITE);
					   bar(949,479,1150,579);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(950,480,ttime[t]);
                    	t+=1;	
                    	break;
                    	
                    	case 1:
					  strcpy(ttime[t],"afternoon");
					  	setfillstyle(1,WHITE);
					  bar(949,579,1150,620);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(950,580,ttime[t]);
                    	t+=1;	
                    	break;     
						
						default:
						t=0;
						goto uph;           		
					}
                } 
			}
                
                //evening
                    if (p.x >= 752 && p.x <= 930 && p.y >= 480 && p.y <= 580) {
                    showbtn = false;
                    displaybtn();
                    if((strcmp(ttime[0],"evening")!=0)&& (strcmp(ttime[1],"evening")!=0))
                    {
                    upi:
                    switch (t)
                    {
                      case 0:
					   strcpy(ttime[t],"evening");
					   setfillstyle(1,WHITE);
					   bar(949,479,1150,579);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(950,480,ttime[t]);
                    	t+=1;	
                    	break;
                    	
                    	case 1:
					  strcpy(ttime[t],"evening");
					  	setfillstyle(1,WHITE);
					    bar(949,579,1150,620);
					    setcolor(RED);
                    	setbkcolor(WHITE);
                    	settextstyle(1,0,3);
                    	outtextxy(950,580,ttime[t]);
                    	t+=1;	
                    	break;     
						
						default:
						t=0;
						goto upi;           		
					}
                }  
            }
            
            //reset buttonouttextxy(1050,650,"RESET");
               if (p.x >= 1049 && p.x <= 1170 && p.y >= 649 && p.y <= 680)
			   {
			   	for (int c = 0; c < 7; c++) {
                   day[c][0] = '\0';  
                           }

                for (int c = 0; c < 3; c++) {
                   ttime[c][0] = '\0'; 
                      }
                      d=0;
                      t=0;
					  setfillstyle(1,WHITE);
					  bar(840,200,1150,400);
					  bar(930,450,1150,610);
				}
				 
                //add_doctor button
                    if (p.x >= 480 && p.x <= 880 && p.y >= 620 && p.y <= 670) {
                    showbtn = false;
                    displaybtn();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    if(ttime[0][0]!='\0' && day[0][0]!='\0')
                    {
                    scondition=false;
                     ofstream fout;
				   fout.open("doctor.bin", ios::out | ios::app | ios::binary);
                if (fout) {
            //finout.clear(); 
            fout.seekp(0, ios::end);
             fout.write(doctorid, strlen(doctorid) + 1);
    fout.write(dname, strlen(dname) + 1);
    fout.write(password, strlen(password) + 1);
    fout.write(department, strlen(department) + 1);
        for (int i = 0; i < 4; i++) {
        	if(day[i][0]=='\0')
        	{
        		strcpy(day[i],"null");
			}
                fout.write(day[i], strlen(day[i]) + 1);
        }
        for (int i = 0; i < 2; ++i) {
        	if(ttime[i][0]=='\0')
        	{
        		strcpy(ttime[i],"null");
			}
                fout.write(ttime[i], strlen(ttime[i]) + 1);
        }
             fout.put('\n');
            fout.close();
            cout << "Doctor added successfully" << endl;
                        setfillstyle(1, WHITE);
                        bar(481, 261, 879, 309);
                        bar(481, 341, 879, 389);
                        bar(481, 421, 879, 469);
                        bar(481, 501, 879, 549);
                        signcondition = false;
                        int p= final();
                        return p;
        }
		 else {
            cerr << "Error opening file for writing" << endl;
        }
                }
                else
                {
                	    setfillstyle(1,WHITE);
    bar(151,101,1280,720);
    setbkcolor(15);
  setcolor(CYAN);
    setbkcolor(15);
    settextstyle(1,0,3);
outtextxy(550,130,"Select Shift!");
setbkcolor(LIGHTRED);
setfillstyle(1,LIGHTRED);
bar(500,220,830,460);
setcolor(RED);
outtextxy(1050,650,"RESET");
for(int linecoords=0;linecoords<240;linecoords+=40)
{
	line(500,220+linecoords,830,220+linecoords);
}
rectangle(500,220,830,460);
outtextxy(520,230,"Sunday");
outtextxy(520,270,"Monday");
outtextxy(520,310,"Tuesday");
outtextxy(520,350,"Wednesday");
outtextxy(520,390,"Thursday");
outtextxy(520,430,"Friday");
 button(480,620,50,400);
    settextstyle(4, 0, 2);
    setbkcolor(CYAN);
    setcolor(15);
    outtextxy(580, 630, "ADD DOCTOR");
    setcolor(0);
    setfillstyle(1,YELLOW);
	bar(400,480,576,580);
setbkcolor(YELLOW);
outtextxy(440,520,"Morning");
    setfillstyle(1,LIGHTBLUE);
bar(576,480,752,580);
setbkcolor(LIGHTBLUE);
outtextxy(590,520,"      Day");
setfillstyle(1,LIGHTGREEN);
bar(752,480,930,580);
setbkcolor(LIGHTGREEN);
outtextxy(780,520,"  Night");
setcolor(0);
    line(576,480,576,580);
    line(752,480,752,580);
    rectangle(400,480,930,580);
				}
			}	
                
            } 

            // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                mousebtn = false;
            }
        }
}


int ADSIGNUP::final()
{
	setcolor(CYAN);
    setbkcolor(15);
    settextstyle(1,0,3);
outtextxy(450,350,"Doctor added Successfully!");
 button(480,420,50,400);
    settextstyle(4, 0, 2);
    setbkcolor(CYAN);
    setcolor(15);
    outtextxy(505, 430, " SEE DOCTOR RECORD");
    readimagefile("images/checkbox.jpg",620,220,720,320);
   int p= finalclick();
   return p;

}


int ADSIGNUP::finalclick()
{
		bool showbtn=false;
	bool mousebtn=false;
	scondition= true;
	 while (scondition) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

            // Check if the left mouse button is pressed
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !mousebtn) {
                mousebtn = true;

  // Check if the click is user icon
                if (p.x >= 1202 && p.x <= 1250 && p.y >= 30 && p.y <= 80) {
                    showbtn = !showbtn;
                    displaybtn();
                }
                
                //see doc rec button
                    if (p.x >= 480 && p.x <= 880 && p.y >= 420 && p.y <= 470) {
                    showbtn = false;
                    displaybtn();
                    setfillstyle(1,WHITE);
                    bar(151,101,1280,720);
                    scondition=false;
                    return 1;
                }  
                
                 // for sidebar buttons click
            if ((p.x >= 25 && p.x <= 130 && p.y >=180 && p.y <= 220) || (p.x >= 25 && p.x <= 130 && p.y >= 250 && p.y <= 290) || (p.x >= 25 && p.x <= 120 && p.y >= 350 && p.y <= 390) ||  (p.x >= 25 && p.x <= 140 && p.y >= 450 && p.y <= 490) || (p.x >= 25 && p.x <= 115 && p.y >= 650 && p.y <= 690) || (p.x >= 25 && p.x <= 120 && p.y >= 550 && p.y <= 610)) {
               scondition = false;
            }   
                
            } 

            // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                mousebtn = false;
            }
        }
}


void ADSIGNUP::printfile() {
	
	  ifstream fin;
	  fin.open("doctor.bin", ios::in | ios::binary);
    if (fin) {
    char fileid[50];
    char filename[100];
    char filepassword[100];
    char filedepartment[50];
    char filedayshift[4][20];
    char filetimeshift[2][20];

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
        cout << "Doctor ID: " << fileid << "\n"
             << "Name: " << filename << "\n"
             << "Password: " << filepassword << "\n"
             << "Department: " << filedepartment << "\n"
             << "Day Shifts: ";
        for (int i = 0; i < 4; ++i) {
            if (filedayshift[i][0] != '\0') {
                cout << filedayshift[i] << " ";
            }
        }
        cout << "\nTime Shifts: ";
        for (int i = 0; i < 2; ++i) {
            if (filetimeshift[i][0] != '\0') {
                cout << filetimeshift[i] << " ";
            }
        }
        cout << "\n\n";
    }
    fin.close();
    }
else
{
	cerr << "Error opening file for printing" << endl;
}
}

void ADSIGNUP::displaybtn() {
        if (showbtn) {
           setcolor(RED);
           setbkcolor(LIGHTGRAY);
		   settextstyle(4,0,1);
           outtextxy(1000,35,"Hello");
            outtextxy(1000,60,"Admin");
        } else {
            setfillstyle(1,LIGHTGRAY);
            bar(800, 0, 1200, 100);
        }
    }

