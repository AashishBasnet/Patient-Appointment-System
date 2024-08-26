#ifndef DLOGIN_H
#define DLOGIN_H

class DLOGIN {
    char doctorid[100];
    char password[100];
    bool logcondition;
    bool showbuttons;
    bool mousebuttondown = false;

public:

    void dlogin();
    bool checkdata(const char* user, const char* pass);
    char* loginclick();
    void displaybuttons();
};

#endif // DLOGIN_H

