#ifndef ALOGIN_H
#define ALOGIN_H

class ALOGIN {
	
    char adminid[100];
    char password[100];
    bool logcondition;
    bool showbuttons;
    bool mousebuttondown = false;
public:
    // Declarations for LOGIN class
    void alogin();
    bool checkdata(const char* user, const char* pass);
    bool loginclick();
    void displaybuttons();
};

#endif // ALOGIN_H
