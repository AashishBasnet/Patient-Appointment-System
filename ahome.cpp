#include"ahome.h"
#include<graphics.h>
#include"layouts.h"
#include <fstream>
#include<iostream>
#include<limits>
#include<algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int AHOME::pgno = 1;

void AHOME::ptrecords(int p)
{
    pgno = p;
    settextstyle(4, 0, 2);
    setbkcolor(LIGHTGRAY);
    setcolor(CYAN);
    outtextxy(570, 77, "   Records  ");
    setbkcolor(15);
    setcolor(RED);
    outtextxy(570, 130, "Appointments");

    char userId[50], firstName[50], phoneNumber[50], department[50], date[50], timeSlot[50], tkno[50];
    ifstream appointmentFile("appointments.bin", ios::in | ios::binary);

    if (appointmentFile) {
        vector<string> records;
        string record;
        
        // Read all records from the file
        while (getline(appointmentFile, record, '\n')) {
            stringstream recordStream(record);
            recordStream.getline(userId, sizeof(userId), '\0');
            recordStream.getline(firstName, sizeof(firstName), '\0');
            recordStream.getline(tkno, sizeof(tkno), '\0');
            recordStream.getline(phoneNumber, sizeof(phoneNumber), '\0');
            recordStream.getline(department, sizeof(department), '\0');
            recordStream.getline(date, sizeof(date), '\0');
            recordStream.getline(timeSlot, sizeof(timeSlot), '\0');
            
            // Add record to vector
            records.push_back(string(userId) + '\0' + string(firstName) + '\0' + string(tkno) + '\0' + 
                               string(phoneNumber) + '\0' + string(department) + '\0' + string(date) + '\0' + 
                               string(timeSlot));
        }

        appointmentFile.close();

        if (!records.empty()) {
            const int recordsPerPage = 3; // Number of records to display per page
            int recordCount = 0; 
            int startRecord = (pgno - 1) * recordsPerPage; // Calculate the starting record for the given page
            int endRecord = startRecord + recordsPerPage; // Calculate the ending record for the given page

            // Check if the page has records to display
            if (startRecord < records.size()) {
                setfillstyle(1, 15);
                bar(200, 170, 1220, 670);

                // Display records for the current page
                int yOffset = 0; // Start y-coordinate for the first record on the current page
                for (int i = startRecord; i < endRecord && i < records.size(); ++i) {
                    stringstream recordStream(records[i]);
                    recordStream.getline(userId, sizeof(userId), '\0');
                    recordStream.getline(firstName, sizeof(firstName), '\0');
                    recordStream.getline(tkno, sizeof(tkno), '\0');
                    recordStream.getline(phoneNumber, sizeof(phoneNumber), '\0');
                    recordStream.getline(department, sizeof(department), '\0');
                    recordStream.getline(date, sizeof(date), '\0');
                    recordStream.getline(timeSlot, sizeof(timeSlot), '\0');
                    
                    int displayY = (i % recordsPerPage) * 160; // 160 pixels between records
                    dbox(210, 190 + displayY, 140, 1000);
                    setcolor(BLUE);
                    setbkcolor(15);
                    settextstyle(4, 0, 1);
                    outtextxy(230, 200 + displayY, "PATIENT'S NAME:");
                    outtextxy(230, 240 + displayY, "APPOINTMENT DATE:");
                    outtextxy(230, 280 + displayY, "CONTACT:");
                    setcolor(0);
                    outtextxy(550, 200 + displayY, firstName);
                    outtextxy(550, 240 + displayY, date);
                    outtextxy(550, 280 + displayY, phoneNumber);
                    recordCount++;
                }

                // Display navigation buttons and page number
                setcolor(0);
                if (pgno > 1) {
                    outtextxy(580, 690, "prev");
                }
                if (endRecord < records.size()) {
                    outtextxy(690, 690, "next");
                }
                setcolor(CYAN);
                char pageNumber[10];
                sprintf(pageNumber, "%d", pgno);
                outtextxy(650, 690, pageNumber);
            } 
        } else {
            // Handle case where no records are found
            setfillstyle(1, 15);
            bar(200, 170, 1220, 670);
                  dbox(350, 200, 400, 700);
                 readimagefile("images/attention.jpg", 650, 320, 750, 420);
            setcolor(BLUE);
            settextstyle(4, 0, 3);
            outtextxy(510, 470, "No current appointments");
            outtextxy(530, 510,"   have taken place.");
        }
    } else {
        cerr << "Error opening file" << endl;
    }
}



void AHOME::dtrecords(int p)
{
	pgno=p;
settextstyle(4,0,2);
setbkcolor(LIGHTGRAY);
setcolor(CYAN);
outtextxy(570,77,"   Records  ");
setbkcolor(15);
setcolor(RED);
outtextxy(600,130,"doctors");
 ifstream fin;
	  fin.open("doctor.bin", ios::in | ios::binary);
    if (fin) {
    char fileid[50];
    char filename[100];
    char filepassword[100];
    char filedepartment[50];
    char filedayshift[4][20];
    char filetimeshift[2][20];
    const int recordsPerPage = 3;
    int recordCount = 0; 
    int startRecord = (pgno - 1) * recordsPerPage; // Calculate the starting record for the given page
    int endRecord = startRecord + recordsPerPage; // Calculate the ending record for the given page

    while (recordCount < startRecord && fin.peek() != EOF) {
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
        recordCount++;
    }
        setfillstyle(1,15);
        bar(200,170,1220,670);
         // Display records for the current page
        int yOffset = 0; // Start y-coordinate for the first record on the current page
         while (recordCount < endRecord && fin.peek() != EOF) {
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
        int i = (recordCount % recordsPerPage) * 160;
        int xoffset=0;
         dbox(210, 190 + i, 140, 1000);
            setcolor(BLUE);
            setbkcolor(15);
            settextstyle(4, 0, 1);
            outtextxy(230, 200 + i, "DOCTOR NAME:");
            outtextxy(230, 225 + i, "DEPARTMENT:");
            outtextxy(230, 250 + i, "WEEK SHIFT:");
            outtextxy(230, 275 + i, "DAY SHIFT:");
            setcolor(0);
            outtextxy(500, 200 + i, filename);
            outtextxy(500, 225 + i, filedepartment);
           
                 for (int x = 0; x < 4; ++x) {
            if (filedayshift[x][0] != '\0') {
                outtextxy(500+xoffset, 250 + i, filedayshift[x]);
                xoffset+=150;
            }
        }
           xoffset=0;
            for (int x = 0; x < 2; ++x) {
            if (filedayshift[x][0] != '\0') {
                outtextxy(500+xoffset, 275 + i, filetimeshift[x] );
                xoffset+=150;
            }
        }
           
            recordCount++;
    }
    setcolor(0);
        if (pgno > 1) {
            outtextxy(580, 690, "prev");
        }
        if (fin.peek() != EOF) {
            outtextxy(690, 690, "next");
        }
        setcolor(CYAN);
        char pageNumber[10];
        sprintf(pageNumber, "%d", pgno);
        outtextxy(650, 690, pageNumber);
    fin.close();
    }
else
{
	cerr << "Error opening file for printing" << endl;
}
}


// for max page number so that next button wont click
int AHOME::getptMaxPageNumber() {
    fstream finout;
    finout.open("patient.bin", ios::in | ios::binary);

    if (finout) {
        int totalRecords = 0;
        char fileusername[50];
        char filename[100];
        char filephonenumber[20];
        char filepassword[100];

        while (finout.read(fileusername, sizeof(fileusername))) {
            finout.read(filename, sizeof(filename));
            finout.read(filephonenumber, sizeof(filephonenumber));
            finout.read(filepassword, sizeof(filepassword));
            finout.ignore(1);
            totalRecords++;
        }
        
        finout.close();

        const int recordsPerPage = 3; 
        int maxPageNumber = (totalRecords + recordsPerPage - 1) / recordsPerPage; 
        return maxPageNumber;
    } else {
        cerr << "Error opening file to calculate max page number" << endl;
        return 1; 
    }
}

// for max page number so that next button wont click
int AHOME::getdtMaxPageNumber() {
  	  ifstream fin;
	  fin.open("doctor.bin", ios::in | ios::binary);
    if (fin) {
    char fileid[50];
    char filename[100];
    char filepassword[100];
    char filedepartment[50];
    char filedayshift[4][20];
    char filetimeshift[2][20];
    int totalRecords = 0;

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
        totalRecords++;
    }
    fin.close();
     const int recordsPerPage = 3; 
        int maxPageNumber = (totalRecords + recordsPerPage - 1) / recordsPerPage; 
        return maxPageNumber;
    }
else
{
 cerr << "Error opening file to calculate max page number" << endl;
        return 1; 
}
}

void AHOME::ptrecordclick()
{
	hshowButtons=false;
	hcondition= true;
	hmouseButtonDown=false;
   while (hcondition) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

            // Check if the left mouse button is pressed
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !hmouseButtonDown) {
                hmouseButtonDown = true;

  // Check if the click is user icon
                if (p.x >= 1202 && p.x <= 1250 && p.y >= 30 && p.y <= 80) {
                    hshowButtons = !hshowButtons;
                    HdisplayButtons();
                }
                
            //prev
            if (p.x >= 580 && p.x <= 635 && p.y >= 690 && p.y <= 710)  {
            	hshowButtons=false;
            	HdisplayButtons();
                cout << "this is previous"<<endl;
                if (pgno>1)
                {
                 pgno--;
                }
                if(pgno ==1)
                {
                	setfillstyle(1,WHITE);
                	bar(578,688,640,740);
				}
                 ptrecords(pgno);
                 prevclick=true;
           }
           
           //next
             if (p.x>= 690 && p.x <= 800 && p.y >= 635 && p.y <= 710) {
             	hshowButtons=false;
             	HdisplayButtons();
                 cout << "this is next"<<endl;
                 int maxPage = getptMaxPageNumber();
                 if (pgno<maxPage)
                 {
                pgno++;
            }
                ptrecords(pgno);
                nextclick=true;
                
      }
                                                              
          // for sidebar buttons click
            if ((p.x >= 25 && p.x <= 130 && p.y >=180 && p.y <= 220) || (p.x >= 25 && p.x <= 120 && p.y >= 350 && p.y <= 390) ||  (p.x >= 25 && p.x <= 140 && p.y >= 450 && p.y <= 490) || (p.x >= 25 && p.x <= 115 && p.y >= 650 && p.y <= 690)|| (p.x >= 25 && p.x <= 120 && p.y >= 550 && p.y <= 610)) {
               hcondition = false;
            }         
       
            } 

            // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                hmouseButtonDown = false;
            }
        }
}

void AHOME::dtrecordclick()
{
	hshowButtons=false;
	hcondition= true;
	hmouseButtonDown=false;
   while (hcondition) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

            // Check if the left mouse button is pressed
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !hmouseButtonDown) {
                hmouseButtonDown = true;

  // Check if the click is user icon
                if (p.x >= 1202 && p.x <= 1250 && p.y >= 30 && p.y <= 80) {
                    hshowButtons = !hshowButtons;
                    HdisplayButtons();
                }
                
            //prev
            if (p.x >= 580 && p.x <= 635 && p.y >= 690 && p.y <= 710)  {
            	hshowButtons=false;
            	HdisplayButtons();
                cout << "this is previous"<<endl;
                if (pgno>1)
                {
                 pgno--;
                }
                if(pgno ==1)
                {
                	setfillstyle(1,WHITE);
                	bar(578,688,640,740);
				}
                 dtrecords(pgno);
                 prevclick=true;
           }
           
           //next
             if (p.x>= 690 && p.x <= 800 && p.y >= 635 && p.y <= 710) {
             	hshowButtons=false;
             	HdisplayButtons();
                 cout << "this is next"<<endl;
                 int maxPage = getdtMaxPageNumber();
                 if (pgno<maxPage)
                 {
                pgno++;
            }
                dtrecords(pgno);
                nextclick=true;
                
      }
                                                              
          // for sidebar buttons click
            if ((p.x >= 25 && p.x <= 130 && p.y >=180 && p.y <= 220) || (p.x >= 25 && p.x <= 130 && p.y >= 250 && p.y <= 290) ||  (p.x >= 25 && p.x <= 140 && p.y >= 450 && p.y <= 490) || (p.x >= 25 && p.x <= 115 && p.y >= 650 && p.y <= 690) || (p.x >= 25 && p.x <= 120 && p.y >= 550 && p.y <= 610)) {
               hcondition = false;
            }         
       
            } 

            // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                hmouseButtonDown = false;
            }
        }
}




void AHOME::HdisplayButtons() {
        if (hshowButtons) {
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


