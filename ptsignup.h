#ifndef PTSIGNUP_H
#define PTSIGNUP_H

#include<iostream>
#include<cstring> 

using namespace std;

class PTSIGNUP {
   char fname[100]; 
    char username[50];
    char password[100];
    char phonenumber[20]; 
    bool signcondition;
    bool sshowButtons;
public:
    void ptsignup();
    int signupclick();
    void printfile();
    void sdisplayButtons(); 
};

#endif // PTSIGNUP_H

