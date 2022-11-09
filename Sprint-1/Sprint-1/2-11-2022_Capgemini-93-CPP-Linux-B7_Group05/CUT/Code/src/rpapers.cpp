#include <iostream>

#include <rpapers.h>
#include <rsubmissions.h>

using namespace std;


RPapers::RPapers(vector<string> refBooks, vector<string>refArticles, vector<string> refChapters) {
	this->mRefBooks = refBooks;
	this->mRefArticles = refArticles;
	this->mRefChapters = refChapters;
	this->mSubmissionType = SubmissionType::ResearchPaper;
}

void RPapers::setRefBooks(vector<string> refBooks) {
	this->mRefBooks = refBooks;
}

vector<string> RPapers::getRefBooks() {
	return mRefBooks;
}

void RPapers::setRefArticles(vector<string> refArticles) {
	this->mRefArticles = refArticles;
}

vector<string> RPapers::getRefArticles() {
	return mRefArticles;
}

void RPapers::setRefChapters(vector<string> refChapters) {
	this->mRefChapters = refChapters;
}

vector<string> RPapers::getRefChapters() {
	return this->mRefChapters;
}

RPapers::~RPapers() {
}


