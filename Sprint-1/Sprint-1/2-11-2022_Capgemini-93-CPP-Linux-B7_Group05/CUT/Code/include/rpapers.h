#ifndef RPAPERS_H
#define RPAPERS_H

#include <iostream>
#include <rsubmissions.h>

using namespace std;

class RPapers:public RSub{
	public:
	RPapers(vector<string> refBooks, vector<string>refArticles, vector<string> refChapters) {
        this->mRefBooks = refBooks;
        this->mRefArticles = refArticles;
        this->mRefChapters = refChapters;
        this->mSubmissionType = SubmissionType::ResearchPaper;
}
~RPapers() {
}
		void setRefBooks(vector<string>);
		void setRefArticles(vector<string>);
		void setRefChapters(vector<string>);
		vector<string> getRefBooks();
		vector<string> getRefArticles();
		vector<string> getRefChapters();
		void display() const {
			RSub::display();
			for (unsigned long int i = 0; i < mRefBooks.size(); i++) {
				cout << "Book " << i + 1 << ": " << mRefBooks[i] << endl;
			}
			for (unsigned long int i = 0; i < mRefArticles.size(); i++) {
				cout << "Article " << i + 1 << ": " << mRefArticles[i] << endl;
			}
			for (unsigned long int i = 0; i < mRefChapters.size(); i++) {
				cout << "Chapter " << i + 1 << ": " << mRefChapters[i] << endl;
			}
		}

	private:
		vector<string> mRefBooks;
		vector<string> mRefArticles;
		vector<string> mRefChapters;
};
#endif
