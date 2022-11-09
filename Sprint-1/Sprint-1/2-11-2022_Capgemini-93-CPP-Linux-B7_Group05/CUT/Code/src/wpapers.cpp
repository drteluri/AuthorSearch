#include <iostream>

#include <wpapers.h>
#include <rsubmissions.h>

using namespace std;



void WPapers::setPatNum(string patNum){
	this->mPatNum=patNum;
}

string WPapers::getPatNum(){
	return mPatNum;
}


