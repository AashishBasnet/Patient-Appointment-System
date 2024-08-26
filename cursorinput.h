#ifndef CURSORINPUT_H
#define CURSORINPUT_H

#include "layouts.h"
#include <graphics.h>
#include <iostream>
#include <string>
#include <vector>
//#include <cstdlib> 

using namespace std;


char* text_input(int x1, int y1, int h, int w, char* initialInput);
char* pwtext_input(int x1, int y1, int h, int w, char* initialInput) ;
char*  max_char_text_input(int x1, int y1, int h, int w, char* initialInput, int maxChars);

#endif
