#ifndef PTAPPOINT_H
#define PTAPPOINT_H

class PTAPPOINT {
	//bool appshowButtons = false;
	char user[50],username[50],phonenumber[50];
	char tokennumber[50];
	bool userstatus;
    bool appcondition;
    bool appmouseButtonDown ;
    bool bookcondition;
    bool bookmouseButtonDown;
    bool ashowButtons;
    int timeclick;
    int fyear,fmonth,fday;
    char fdepartment[50],fdate[50],fdaytime[50],apptime[50];
    bool appointmentstatus;
    int year1;
    int month1;
    int day1;
    //-------
     int year2;
    int month2;
    int day2;
    //--------
    int year3;
    int month3;
    int day3;
    

public:
    // Declarations for APPOINT class
    void ptappoint(bool,char[]);
    int appointclick();
    void generalmedicine();
    void opthamology();
    void ent();
    void cardio();
    void gastro();
    void neuro();
    void timeslot();
    void choosetime();
    int timebtnclick();
    int choosetimebtnclick();
    int checkbookbtnclick();
    void adisplayButtons();
    void confirm();
    int confirmclick();
    bool checkdoubleappointment();
    void appointsuccessandattention(bool);
    int lastclick();
};

#endif // APPOINT_H


