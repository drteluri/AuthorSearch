#ifndef RSUBMISSIONS_H
#define RSUBMISSIONS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class RSub {
	public:
		RSub(){};
RSub(string projId, string projTitle, string abstract, vector<string> authors) {
        this->mProjId=projId;
        this->mProjTitle=projTitle;
        this->mAbstract=abstract;
        this->mAuthors=authors;
}
		virtual ~RSub() { };
		void setProjId(string);
		void setProjTitle(string);
		void setAbstract(string);
		void setAuthor(vector<string>);
		string getProjId();
		string getProjTitle();
		string getAbstract();
		vector<string> getAuthors();
		
	protected:

		string mProjId;
		string mProjTitle;
		string mAbstract;
		vector<string> mAuthors;
	
};
#endif
	

