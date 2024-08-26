#ifndef PTLOGIN_H
#define PTLOGIN_H

extern char globalPatientID[50];
class PTLOGIN {
    char username[100];
    char password[100];
    bool logcondition = true;
public:
    // Declarations for LOGIN class
    void ptlogin();
    bool checkdata(const char* user, const char* pass);
    char* loginclick();
};

#endif // PTLOGIN_H
