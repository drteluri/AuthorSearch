#ifndef BLOGS_H
#define BLOGS_H

#include <iostream>
#include <rsubmissions.h>

using namespace std;

class Blogs:public RSub{
	public:
		Blogs(string url){
                this->mURL=url;
                this->mSubmissionType = SubmissionType::Blog;
                }

		~Blogs() { };
		void setURL(string);
		string getURL();
		void display() const{
			RSub::display();
			cout << "Blog: " << mURL << endl;
		}
	private:
		string mURL;

};

#endif
