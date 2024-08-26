#include "pthome.h"
#include "layouts.h"
#include <graphics.h>

void PTHOME::pthome() {
        setcolor(CYAN);
        setbkcolor(LIGHTGRAY);
        settextstyle(4, 0, 2);
        outtextxy(640, 78, "Home ");
        hdbox(160, 120, 120, 1100);
        hdbox(160, 270, 300, 1100);
        readimagefile("images/doctor.jpg", 266, 325, 365, 413);
        setbkcolor(CYAN);
        setcolor(WHITE);
        settextstyle(4, 0, 2);
        outtextxy(400, 130, "Welcome to Patient Appointment System");
        outtextxy(420, 280, "Message from chief medical officer");
        setbkcolor(WHITE);
        setcolor(BLACK);
        settextstyle(1, 0, 1);
        outtextxy(180, 180, "Patient appointment system makes scheduling appointments easier and facilitates");
        outtextxy(180, 200, "easy communication between patients and doctors.");
        settextstyle(0, 0, 2);
        outtextxy(170, 450, "Dr. Rajendra Shrestha");
        outtextxy(485, 340, "As the Chief Medical Officer, I am pleased to announce");
        outtextxy(485, 370, "the launch of our new Patient appointment system.This");
        outtextxy(485, 400, "innovative platform simplifies scheduling, reduces wait");
        outtextxy(485, 430, "times, and enhances patient care by allowing you to");
        outtextxy(485, 460, "book appointments online at your convenience. Our goal");
        outtextxy(485, 490, "is to provide you with a seamless and efficient");
        outtextxy(485, 520, "health care experience. Thank you for choosing our");
        outtextxy(485,540,"hospital.");
        setcolor(LIGHTGRAY);
        line(470, 311, 470, 570);
        button(540, 610, 50, 300);
        setbkcolor(CYAN);
        setcolor(WHITE);
        settextstyle(4, 0, 2);
        outtextxy(545, 625, "Book an Appointment");
}

int PTHOME::homebtnclick()
{
	homemouseButtonDown = false;
	homecondition=true;
	 while (homecondition) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(GetForegroundWindow(), &p);

            // Check if the left mouse button is pressed
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !homemouseButtonDown) {
                homemouseButtonDown = true;
                
                

                                // Check if the click is bookanappointment
                if (p.x >= 540 && p.x <= 840 && p.y >= 610 && p.y <= 660) {
                	homecondition = false;
                 return 1;
                }
                
                	  
				    // for sidebar buttons click
            if ((p.x >= 25 && p.x <= 125 && p.y >= 350 && p.y <= 370) ||(p.x >= 25 && p.x <= 105 && p.y >= 450 && p.y <= 470) ||(p.x >= 25 && p.x <= 125 && p.y >= 600 && p.y <= 620)|| (p.x >= 25 && p.x <= 105 && p.y >= 550 && p.y <= 570)||(p.x >= 25 && p.x <= 105 && p.y >= 650 && p.y <= 670)) {
                homecondition = false;
            }
            
        } 
            // Check if the left mouse button is released
            if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
                homemouseButtonDown = false;
            }
        }
}

 
