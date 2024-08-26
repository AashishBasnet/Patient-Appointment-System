#include "ptabout.h"
#include "layouts.h"
#include <graphics.h>


void PTABOUT::ptabout() {
     setcolor(CYAN);
        setbkcolor(LIGHTGRAY);
        settextstyle(4, 0, 2);
        outtextxy(640, 78, "About ");
        hdbox(160, 120, 550, 1100);
        setbkcolor(CYAN);
        setcolor(WHITE);
        settextstyle(4, 0, 2);
        outtextxy(470, 130, "About Patient Appointment System");
        setcolor(BLACK);
        setbkcolor(WHITE);
        outtextxy(200, 200, "Welcome to our Patient Appointment System, a user-friendly platform ");
        outtextxy(200, 230, "developed to simplify the process of scheduling and managing healthcare");
        outtextxy(200, 260, "appointments. Our mission is to enhance the patient experience by providing");
        outtextxy(200, 290, "an easy and efficient way to book appointments with healthcare providers.");
        outtextxy(200, 320, "We aim to make healthcare access more convenient for everyone.");
        outtextxy(200, 380, "Contacts:");
        outtextxy(200, 440, "Email:  Patient_appoint_system@gmail.com");
        outtextxy(200, 470, "Phone:  01-4432267");
        outtextxy(200, 530, "Our Website:  www.patientappointmentsystem.com.");
}

