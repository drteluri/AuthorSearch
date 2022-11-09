#ifndef ARTICLES_H
#define ARTICLES_H

#include <iostream>
#include <rsubmissions.h>

using namespace std;

class Articles:public RSub{
	public:
Articles(string sampleSize, string testSite){
        this->mSampleSize=sampleSize;
        this->mTestSite=testSite;
        this->mSubmissionType = SubmissionType::Article;
}
~Articles(){
}
		void setSampleSize(string);
		void setTestSite(string);
		string getSampleSize();
		string getTestSize();
		void display() const{
			RSub::display();
			cout << "Sample-Size: " << mSampleSize << endl;
			cout << "Test Site: " << mTestSite << endl;
}

	private:
		string mSampleSize;
		string mTestSite;
};
#endif
