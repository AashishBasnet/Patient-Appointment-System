#ifndef ADSIGNUP_H
#define ADSIGNUP_H



class ADSIGNUP {
    char dname[100]; 
    char doctorid[50];
    char password[100];
	char department[50];
	char day[4][20]; 
	char ttime[2][20];
    bool signcondition;
    bool scondition;
    bool showbtn;
public:
    void dsignup();
    int selectdepartment();
    int final();
    int chooseshift();
    int signupclick();
    int departmentclick();
    int shiftclick();
    int finalclick();
    void printfile();
    void displaybtn();
};

#endif // ADSIGNUP_H
