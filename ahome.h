
#ifndef AHOME_H
#define AHOME_H

class AHOME{
	
	static int pgno;
	bool hshowButtons;
	bool hcondition;
	bool hmouseButtonDown;
	bool prevclick,nextclick;
	
public:
	
     void ptrecords(int); 
	 void dtrecords(int);	
	 int getptMaxPageNumber();
	 int getdtMaxPageNumber();
	 void ptrecordclick();
	 void dtrecordclick();
	 void HdisplayButtons();
};

#endif
