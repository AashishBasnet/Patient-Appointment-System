#include "layouts.h"
#include <graphics.h>

//   -------------------------------------------------BUTTON----------------------------------------

void button(int x,int y, int height, int width)
{  
setcolor(CYAN);
setfillstyle(1,CYAN);
 setlinestyle(SOLID_LINE, 0, 2);
 setcolor(LIGHTGRAY);
    int radius = 10;
    setcolor(CYAN);
setfillstyle(1,CYAN);
    line(x + radius, y, x + width - radius, y);
    line(x + radius, y + height, x + width - radius, y + height);
    line(x, y + radius, x, y + height - radius);
    line(x + width, y + radius, x + width, y + height - radius);
    arc(x + radius, y + radius, 90, 180, radius);
    arc(x + width - radius, y + radius, 0, 90, radius);
    arc(x + radius, y + height - radius, 180, 270, radius);
    arc(x + width - radius, y + height - radius, 270, 360, radius);
    floodfill(x+20,y+20,CYAN);
      line(x + radius, y, x + width - radius, y);
      setcolor(0);
    line(x + radius, y + height, x + width - radius, y + height);
    line(x + width, y + radius, x + width, y + height - radius);
    arc(x + width - radius, y + height - radius, 270, 360, radius);
    arc(x + width - radius, y + radius, 0, 90, radius);
    
    setcolor(3);
    line(x, y + radius, x, y + height - radius);
    arc(x + radius, y + radius, 90, 180, radius);
    arc(x + radius, y + height - radius, 180, 270, radius);
    
}

//   -------------------------------------------------COLORED BUTTON----------------------------------------

void colored_button(int x,int y, int height, int width,int color)
{  
 setlinestyle(SOLID_LINE, 0, 2);
    int radius = 10;
    setcolor(color);
setfillstyle(1,color);
    line(x + radius, y, x + width - radius, y);
    line(x + radius, y + height, x + width - radius, y + height);
    line(x, y + radius, x, y + height - radius);
    line(x + width, y + radius, x + width, y + height - radius);
    arc(x + radius, y + radius, 90, 180, radius);
    arc(x + width - radius, y + radius, 0, 90, radius);
    arc(x + radius, y + height - radius, 180, 270, radius);
    arc(x + width - radius, y + height - radius, 270, 360, radius);
    floodfill(x+20,y+20,color);
    line(x + radius, y, x + width - radius, y);
    setcolor(0);
    line(x + radius, y + height, x + width - radius, y + height);
    line(x + width, y + radius, x + width, y + height - radius);
    arc(x + width - radius, y + height - radius, 270, 360, radius);
    arc(x + width - radius, y + radius, 0, 90, radius);
    
    setcolor(color);
    line(x, y + radius, x, y + height - radius);
    arc(x + radius, y + radius, 90, 180, radius);
    arc(x + radius, y + height - radius, 180, 270, radius);
    
}

//---------------------------------------------------------CLICKED BUTTON------------------------------------------

void clickedbutton(int x,int y, int height, int width)
{  
setcolor(CYAN);
setfillstyle(1,CYAN);
 setlinestyle(SOLID_LINE, 0, 2);
 setcolor(LIGHTGRAY);
    int radius = 10;
    setcolor(CYAN);
setfillstyle(1,CYAN);
    line(x + radius, y, x + width - radius, y);
    line(x + radius, y + height, x + width - radius, y + height);
    line(x, y + radius, x, y + height - radius);
    line(x + width, y + radius, x + width, y + height - radius);
    arc(x + radius, y + radius, 90, 180, radius);
    arc(x + width - radius, y + radius, 0, 90, radius);
    arc(x + radius, y + height - radius, 180, 270, radius);
    arc(x + width - radius, y + height - radius, 270, 360, radius);
    floodfill(x+20,y+20,CYAN);
      setcolor(3);
    line(x + radius, y + height, x + width - radius, y + height);
    line(x + width, y + radius, x + width, y + height - radius);
    arc(x + width - radius, y + height - radius, 270, 360, radius);
    arc(x + width - radius, y + radius, 0, 90, radius);
    
    setcolor(0);
     line(x + radius, y, x + width - radius, y);
    line(x, y + radius, x, y + height - radius);
    arc(x + radius, y + radius, 90, 180, radius);
    arc(x + radius, y + height - radius, 180, 270, radius);
    
}

//---------------------------------------------------------CLICKED COLORED BUTTON------------------------------------------

void clicked_colored_button(int x,int y, int height, int width,int color)
{  
 setlinestyle(SOLID_LINE, 0, 2);
    int radius = 10;
    setcolor(color);
setfillstyle(1,color);
    line(x + radius, y, x + width - radius, y);
    line(x + radius, y + height, x + width - radius, y + height);
    line(x, y + radius, x, y + height - radius);
    line(x + width, y + radius, x + width, y + height - radius);
    arc(x + radius, y + radius, 90, 180, radius);
    arc(x + width - radius, y + radius, 0, 90, radius);
    arc(x + radius, y + height - radius, 180, 270, radius);
    arc(x + width - radius, y + height - radius, 270, 360, radius);
    floodfill(x+20,y+20,color);
      setcolor(color);
    line(x + radius, y + height, x + width - radius, y + height);
    line(x + width, y + radius, x + width, y + height - radius);
    arc(x + width - radius, y + height - radius, 270, 360, radius);
    arc(x + width - radius, y + radius, 0, 90, radius);
    
    setcolor(0);
     line(x + radius, y, x + width - radius, y);
    line(x, y + radius, x, y + height - radius);
    arc(x + radius, y + radius, 90, 180, radius);
    arc(x + radius, y + height - radius, 180, 270, radius);
    
}


//   ---------------------------------------------This is for middle white box-----------------------------------

void box(int x,int y, int height, int width)
{  
 setcolor(15);
 setfillstyle(1,15);
    int radius = 20;
    x++;
    y++;
    line(x + radius, y, x + width - radius, y);
    line(x + radius, y + height, x + width - radius, y + height);
    line(x, y + radius, x, y + height - radius);
    line(x + width, y + radius, x + width, y + height - radius);
    arc(x + radius, y + radius, 90, 180, radius);
    arc(x + width - radius, y + radius, 0, 90, radius);
    arc(x + radius, y + height - radius, 180, 270, radius);
    arc(x + width - radius, y + height - radius, 270, 360, radius);
    floodfill(x+20,y+20,15);
}

//-------------------------------------------------------Log out box------------------------------------------------

void lbox(int x,int y, int height, int width)
{  
 setcolor(0);
 setfillstyle(1,LIGHTGRAY);
    int radius = 20;
    x++;
    y++;
    line(x + radius, y, x + width - radius, y);
    line(x + radius, y + height, x + width - radius, y + height);
    line(x, y + radius, x, y + height - radius);
    line(x + width, y + radius*3, x + width+10, (y + height-(radius*3)+10));
    line(x + width, (y + height-(radius*3)), x + width+10,(y + height-(radius*3)+10));
    line(x + width, y + radius*3, x + width, y + height-radius);
    line(x + width, y + radius, x + width, y + height-(radius*3));
    arc(x + radius, y + radius, 90, 180, radius);
    arc(x + width - radius, y + radius, 0, 90, radius);
    arc(x + radius, y + height - radius, 180, 270, radius);
    arc(x + width - radius, y + height - radius, 270, 360, radius);
   floodfill(x+20,y+20,0);
}


//   ---------------------------------------------------------Text field-----------------------------------------------
void textfield(int x,int y, int height, int width)
{  
   setlinestyle(SOLID_LINE, 0, 2);
 setcolor(LIGHTGRAY);
    int radius = 10;
    x++;
    y++;
    line(x + radius, y, x + width - radius, y);
    line(x + radius, y + height, x + width - radius, y + height);
    line(x, y + radius, x, y + height - radius);
    line(x + width, y + radius, x + width, y + height - radius);
    arc(x + radius, y + radius, 90, 180, radius);
    arc(x + width - radius, y + radius, 0, 90, radius);
    arc(x + radius, y + height - radius, 180, 270, radius);
    arc(x + width - radius, y + height - radius, 270, 360, radius);
}

//   ---------------------------------------------------------Text field-----------------------------------------------

void clickedtextfield(int x,int y, int height, int width)
{  
   setlinestyle(SOLID_LINE, 0, 2);
 setcolor(CYAN);
    int radius = 10;
    x++;
    y++;
    line(x + radius, y, x + width - radius, y);
    line(x + radius, y + height, x + width - radius, y + height);
    line(x, y + radius, x, y + height - radius);
    line(x + width, y + radius, x + width, y + height - radius);
    arc(x + radius, y + radius, 90, 180, radius);
    arc(x + width - radius, y + radius, 0, 90, radius);
    arc(x + radius, y + height - radius, 180, 270, radius);
    arc(x + width - radius, y + height - radius, 270, 360, radius);
}

//------------------------------------------------------------DEPARTMENT BOX---------------------------------------------------

void dbox(int x,int y, int height, int width)
{  
 setcolor(LIGHTGRAY);
 setfillstyle(1,15);
    int radius = 20;
    x++;
    y++;
    line(x + radius, y, x + width - radius, y);
    line(x + radius, y + height, x + width - radius, y + height);
    line(x, y + radius, x, y + height - radius);
    line(x + width, y + radius, x + width, y + height - radius);
    arc(x + radius, y + radius, 90, 180, radius);
    arc(x + width - radius, y + radius, 0, 90, radius);
    arc(x + radius, y + height - radius, 180, 270, radius);
    arc(x + width - radius, y + height - radius, 270, 360, radius);
    floodfill(x+20,y+20,LIGHTGRAY);
}



void hdbox(int x,int y, int height, int width)
{  
 setcolor(LIGHTGRAY);
 setfillstyle(1,15);
    int radius = 20;
    x++;
    y++;
    line(x + radius, y, x + width - radius, y);
    line(x + radius, y + height, x + width - radius, y + height);
    line(x, y + radius, x, y + height - radius);
    line(x + width, y + radius, x + width, y + height - radius);
    arc(x + radius, y + radius, 90, 180, radius);
    arc(x + width - radius, y + radius, 0, 90, radius);
    arc(x + radius, y + height - radius, 180, 270, radius);
    arc(x + width - radius, y + height - radius, 270, 360, radius);
    floodfill(x+20,y+20,LIGHTGRAY);
    
     setcolor(LIGHTGRAY);
    
 setfillstyle(1,CYAN);
     line(x + radius, y, x + width - radius, y);
    line(x + radius, y, x + width - radius, y);
    line(x, y+radius*2, x + width, y+radius*2);
   arc(x + radius, y + radius, 90, 180, radius);
   arc(x + width - radius, y + radius, 0, 90, radius);
    floodfill(x+20,y+10,LIGHTGRAY);
}



