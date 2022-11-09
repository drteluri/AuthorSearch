#include <iostream>

#include <articles.h>
#include <rsubmissions.h>

using namespace std;

void Articles::setSampleSize(string sampleSize){
	this->mSampleSize=sampleSize;
}

string Articles::getSampleSize(){
	return mSampleSize;
}

void Articles::setTestSite(string testSite){
	this->mTestSite=testSite;
}

string Articles::getTestSize(){
	return mTestSite;
}






