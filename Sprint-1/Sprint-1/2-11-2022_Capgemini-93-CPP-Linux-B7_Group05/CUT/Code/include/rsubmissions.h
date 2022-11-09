#ifndef RSUBMISSIONS_H
#define RSUBMISSIONS_H

#include <iostream>
#include <vector>

using namespace std;
enum SubmissionType
{
	ResearchPaper = 1,
	WhitePaper = 2,
	Article = 3,
	Blog = 4,
};
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
		virtual void display() const{
		cout << "Project ID: " << mProjId << endl;
		cout << "Project title: " << mProjTitle << endl;
		cout << "Abstarct: " << mAbstract << endl;
		cout << "Authors: " << endl;
		for (auto it=mAuthors.begin(); it != mAuthors.end(); ++it) {
			cout << *it << "\t";
		}
		cout << endl;
		}
		SubmissionType mSubmissionType;
	protected:

		string mProjId;
		string mProjTitle;
		string mAbstract;
		vector<string> mAuthors;
	
};
#endif
	

