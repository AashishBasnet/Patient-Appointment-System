#include "ptsignup.h"
#include "layouts.h"
#include <graphics.h>
#include <fstream>
#include "cursorinput.h"
#include <cstring>

using namespace std;

void PTSIGNUP::ptsignup() {
    textfield(480, 180, 50, 400);
    textfield(480, 260, 50, 400);
    textfield(480, 340, 50, 400);
    textfield(480, 420, 50, 400);
    textfield(480, 500, 50, 400);
    button(480, 600, 50, 400);
    setcolor(0);
    setbkcolor(15);
    settextstyle(4,0,1);
    outtextxy(490, 670, "already registered?");
    setcolor(CYAN);
    outtextxy(750, 670, "Login");
    settextstyle(3, 0, 1);
    setcolor(DARKGRAY);
    setbkcolor(WHITE);
    outtextxy(480, 160, "Name:");
    outtextxy(480, 240, "Username:");
    outtextxy(480, 320, "Phone No:");
    outtextxy(480, 400, "Password:");
    outtextxy(480, 480, "Confirm Password:");
    settextstyle(4, 0, 2);
    setbkcolor(CYAN);
    setcolor(15);
    outtextxy(630, 610, "SignUp");
    setbkcolor(LIGHTGRAY);
    setcolor(3);
    settextstyle(4, 0, 3);
    outtextxy(620, 76, "SignUp");
}

int PTSIGNUP::signupclick() {
    bool mousebtndwn = false;
    char confirmPassword[100];
    memset(confirmPassword, 0, sizeof(confirmPassword));
    memset(fname, 0, sizeof(fname));
    memset(username, 0, sizeof(username));
    memset(password, 0, sizeof(password));
    memset(phonenumber, 0, sizeof(phonenumber));
    signcondition = true;

    while (signcondition) {
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(GetForegroundWindow(), &p);

        if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !mousebtndwn) {
            mousebtndwn = true;

            // Name
            if (p.x >= 480 && p.x <= 880 && p.y >= 180 && p.y <= 230) {
                clickedtextfield(480, 180, 50, 400);
                setfillstyle(1, WHITE);
                bar(520, 559, 1200, 595);
                text_input(480, 180, 50, 400, fname);
            }

            // Username
            if (p.x >= 480 && p.x <= 880 && p.y >= 260 && p.y <= 310) {
                clickedtextfield(480, 260, 50, 400);
                setfillstyle(1, WHITE);
                bar(520, 559, 1200, 595);
                text_input(480, 260, 50, 400, username);
            }

            // Phone number
            if (p.x >= 480 && p.x <= 880 && p.y >= 340 && p.y <= 390) {
                clickedtextfield(480, 340, 50, 400);
                setfillstyle(1, WHITE);
                bar(520, 559, 1200, 595);
                text_input(480, 340, 50, 400, phonenumber);
            }

            // Password
            if (p.x >= 480 && p.x <= 880 && p.y >= 420 && p.y <= 470) {
                clickedtextfield(480, 420, 50, 400);
                setfillstyle(1, WHITE);
                bar(520, 559, 1200, 595);
                pwtext_input(480, 420, 50, 400, password);
            }

            // Confirm password
            if (p.x >= 480 && p.x <= 880 && p.y >= 500 && p.y <= 550) {
                clickedtextfield(480, 500, 50, 400);
                setfillstyle(1, WHITE);
                bar(520, 559, 1200, 595);
                pwtext_input(480, 500, 50, 400, confirmPassword);
                if (strcmp(confirmPassword, password) != 0) {
                    setcolor(RED);
                    setbkcolor(15);
                    outtextxy(530, 560, "*passwords don't match.");
                } else {
                    setfillstyle(1, WHITE);
                    bar(520, 559, 1200, 595); // Clear pw not match message
                }
            }

            // Signup button
            if (p.x >= 480 && p.x <= 880 && p.y >= 600 && p.y <= 650) {
                bool usernameExists = false;
                clickedbutton(480, 600, 50, 400);
                delay(100);
                button(480, 600, 50, 400);

                if (strcmp(confirmPassword, password) != 0) {
                    setcolor(RED);
                    setbkcolor(15);
                    outtextxy(530, 560, "*passwords don't match");
                    continue;
                } else if (fname[0] == '\0' || username[0] == '\0' || password[0] == '\0' || confirmPassword[0] == '\0') {
                    setcolor(RED);
                    setbkcolor(15);
                    outtextxy(530, 560, "*fill all the required fields");
                    continue;
                } else if (strlen(phonenumber) != 10 || !isdigit(phonenumber[0])) {
                    setcolor(RED);
                    setbkcolor(15);
                    outtextxy(530, 560, "* Enter a valid phone number");
                    continue;
                } else {
                    // Check if username already exists
                    fstream finout;
                    finout.open("patient.bin", ios::in | ios::out | ios::app | ios::binary);
                    if (finout) {
                        char existingUsername[50];
                        char dummyFname[100];
                        char dummyPhonenumber[20];
                        char dummyPassword[100];
                        while (finout.read(existingUsername, sizeof(existingUsername))) {
                            finout.read(dummyFname, sizeof(dummyFname));
                            finout.read(dummyPhonenumber, sizeof(dummyPhonenumber));
                            finout.read(dummyPassword, sizeof(dummyPassword));
                            finout.ignore(1);
                            if (strcmp(existingUsername, username) == 0) {
                                usernameExists = true;
                                break;
                            }
                        }
                        if (usernameExists) {
                            setcolor(RED);
                            outtextxy(530, 560, "*username already exists");
                            delay(10);
                        } else {
                            finout.clear();
                            finout.seekp(0, ios::end);
                            finout.write(username, sizeof(username));
                            finout.write(fname, sizeof(fname));
                            finout.write(phonenumber, sizeof(phonenumber));
                            finout.write(password, sizeof(password));
                            finout.put('\n');
                            finout.close();
                            cout << "Patient added successfully" << endl;
                            setfillstyle(1, WHITE);
                            bar(481, 181, 879, 229);
                            bar(481, 261, 879, 309);
                            bar(481, 341, 879, 389);
                            bar(481, 421, 879, 469);
                            bar(481, 501, 879, 549);
                            setcolor(RED);
                            outtextxy(530, 560, "*signup successful");
                            signcondition = false;
                        }
                        finout.close();
                    } else {
                        cerr << "Error opening file for writing" << endl;
                    }
                }
            }

            // Check if login link is clicked
            if (p.x >= 750 && p.x <= 850 && p.y >= 670 && p.y <= 700) {
                signcondition = false;
                return 1;
            }

            // Check if any sidebar button is clicked
            if (p.x >= 25 && p.x <= 105 && p.y >= 250 && p.y <= 270 ||
                p.x >= 25 && p.x <= 125 && p.y >= 350 && p.y <= 370 ||
                p.x >= 25 && p.x <= 105 && p.y >= 450 && p.y <= 470 ||
                p.x >= 25 && p.x <= 105 && p.y >= 550 && p.y <= 570 ||
                p.x >= 25 && p.x <= 105 && p.y >= 650 && p.y <= 670) {
                signcondition = false;
            }

            delay(10);
        }

        // Check if the left mouse button is released
        if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
            mousebtndwn = false;
        }
    }
}



void PTSIGNUP::printfile() {
    fstream finout;
    finout.open("patient.bin", ios::in | ios::out | ios::app | ios::binary);
    if (finout) {
        char fileusername[50];
        char filename[100];
        char filephonenumber[11];  // 11 to accommodate 10 digits + null terminator
        char filepassword[100];
        
        while (finout.read(fileusername, sizeof(fileusername))) {
            finout.read(filename, sizeof(filename));
            finout.read(filephonenumber, 10);  // Read exactly 10 digits
            filephonenumber[10] = '\0';  // Null-terminate the phone number
            finout.read(filepassword, sizeof(filepassword));
            finout.ignore(1);
            
            // Validate that phone number is exactly 10 digits
            bool isValidPhoneNumber = true;
            for (int i = 0; i < 10; i++) {
                if (!isdigit(filephonenumber[i])) {
                    isValidPhoneNumber = false;
                    break;
                }
            }

            if (strcmp(fileusername, username) == 0 && isValidPhoneNumber) {
                cout << filename << "\t" << filephonenumber << "\t" << fileusername << "\t" << filepassword << endl;
                finout.close();
                return;
            }
        }
        finout.close();
    } else {
        cerr << "Error opening file for printing" << endl;
    }
}


