#include "dtabout.h"
#include "dlogin.h"
#include "layouts.h"
#include <graphics.h>
#include<iostream>
#include<fstream>
#include<limits>

using namespace std;

void DTABOUT::dtabout(char doid[50]) {
	setfillstyle(1,WHITE);
    bar(151,101,1280,720);
	setbkcolor(LIGHTGRAY);
    settextstyle(4, 0, 2);
    setcolor(CYAN);
    outtextxy(580, 77, "About Doc");
	hdbox(170,120,570,1050);
    setcolor(RED);
    setbkcolor(3);
    outtextxy(210,130,"About Doctor:");
	readimagefile("images/doctor.jpg",180,205,280,305);
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

            if (strcmp(fileid, doid) == 0) {
                     cout<< "Name: " << filename << "\n";
                setcolor(0);
               setbkcolor(15);
               settextstyle(4,0,1);
                  outtextxy(300, 190, filename);
                   outtextxy(470, 230,filedepartment);
                   int  xshift=0;
                   int tshift=0;
                          for (int i = 0; i < 4; ++i) {
            if (filedayshift[i][0] != '\0') {
                outtextxy(470+xshift,270,filedayshift[i]);
                xshift+=170;
            }
        }
                      for (int i = 0; i < 2; ++i) {
            if (filetimeshift[i][0] != '\0') {
                outtextxy(470+tshift,310,filetimeshift[i]);
                tshift+=170;
            }
        }
                   setbkcolor(15);
                   setcolor(CYAN);
                outtextxy(300, 230,"Department:");     
               outtextxy (300,270,"Day Shifts: ");
               outtextxy (300,310, "Time Shifts: ");             
            }
        }
        fin.close();
    } else {
        cerr << "Error opening file for printing" << endl;}
}
