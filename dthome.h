#ifndef DTHOME_H
#define DTHOME_H


class DTHOME {
	char pdepartment[50],tdate[50],ttime[50];
	char pname[50], ptkno[50];
	bool psigncondition,mousebtndwn;
	int count=0;
	char did[50];
	int tk[25];
	char newpassword[100], connewpassword[100];
	char docdep[50],docpass[100];
     char patdep[50];
public:
    // Declarations for HOME class
    void dthome1();
    bool pptcheckrecord ( char[], char []);
    void dthome2();
    int ptrecordfillclick(char[]); 
    int ptnamefillclick(); 
    bool checkrecord();
    void attendance_list();
    int attendance_listclick();
    void changepassword(char []);
    void changepasswordclick();
	};

#endif // HOME_H
