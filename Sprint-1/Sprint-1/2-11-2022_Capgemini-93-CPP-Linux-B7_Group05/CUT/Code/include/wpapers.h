#ifndef WPAPERS_H
#define WPAPERS_H

#include <iostream>
#include <rsubmissions.h>

using namespace std;

class WPapers:public RSub{
	public:
	WPapers(string patNum){
        this->mPatNum=patNum;
        this->mSubmissionType = SubmissionType::WhitePaper;
}
		~WPapers(){
}
		void setPatNum(string);
		string getPatNum();

void display() const{
        RSub::display();
        cout << "Patent Number: " << mPatNum << endl;
}


	private:
		string mPatNum;

};
#endif
