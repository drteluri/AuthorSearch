#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include <conference.h>
#include <blogs.h>
#include <rpapers.h>
#include <wpapers.h>
#include <articles.h>
#include <rsubmissions.h>
using namespace std;

Conf::Conf(string name, string loc)
{
	this->mName = name;
	this->mLoc = loc;
	this->mTime = time(NULL);
}

void Conf::setName(string name) {
	this->mName = name;
}

string Conf::getName() {
	return mName;
}

void Conf::setLoc(string loc) {
	this->mLoc = loc;
}

string Conf::getLoc() {
	return mLoc;
}

void Conf::setTime(time_t t) {
	this->mTime = t;
}

time_t Conf::getTime() {
	return mTime;
}

void Conf::display() const {

	cout << "Conference Name: " << mName << endl;
	cout << "Conference Location: " << mLoc << endl;
	char buff[20];
	struct tm * newtime;
	time_t now;
	newtime = localtime(&now);
	strftime(buff, 20, "%Y-%m-%d %H:%M:%S", newtime);
	cout << "Conference Time::" << buff << endl;
}

void Conf::addSubmissions(string fileName) {

	/*
	1. read file
		validate file, if not valid, write project id in invalid submission file.
	2. based on properties identity submission type
	3. create submission type
	4. write project id in valid submission file.

  */
	RSub* s = readInputFileInfo(fileName);
	if (s)
		this->mSubmissions.push_back(s);
}

RSub * Conf::readInputFileInfo(string inputFile)
{
	string line;
	ifstream input;
	string projectId;
	string mProjTitle;
	string mAbstract;
	vector<string> authors;
	vector<string> refBooks;
	vector<string> refArticles;
	vector<string> refChapters;
	string patentNumber;
	string sampleSize;
	string testingSite;
	string url;
	string value;
	const char delimiter = '=';

	try {

		input.open(inputFile);
		if (!input.is_open())
		{
			throw "UNABLE TO OPEN THE INPUT FILE GIVEN!!! " ;
			return NULL;
		}
	}
	catch (...) {
	        if (input.is_open()) input.close();
	}
		string previousKey;
		while (getline(input, line)) {
			stringstream ss(line);
			string key;
			if (getline(ss, key, delimiter)) {
				if (key == "Project ID") {
					projectId = line.substr(line.find(delimiter) + 1);
				}
				else if (key == "Project Title") {
					mProjTitle = line.substr(line.find(delimiter) + 1);
				}
				else if (key == "Abstract") {
					mAbstract = line.substr(line.find(delimiter) + 1);
				}
				else if (key == "Author") {
					string name=line.substr(line.find(delimiter)+1);
					
					authors.push_back(name.substr(0,name.length()-1));
				}
				else if (key == "Reference-Book") {
					refBooks.push_back(line.substr(line.find(delimiter) + 1));
				}
				else if (key == "Reference-Article") {
					refArticles.push_back(line.substr(line.find(delimiter) + 1));
				}
				else if (key == "References-Chapter") {
					refChapters.push_back(line.substr(line.find(delimiter) + 1));
				}
				else if (key == "Patent Number") {
					patentNumber = line.substr(line.find(delimiter) + 1);
				}
				else if (key == "Sample-Size") {
					sampleSize = line.substr(line.find(delimiter) + 1);
				}
				else if (key == "Testing-Site") {
					testingSite = line.substr(line.find(delimiter) + 1);
				}
				else if (key == "URL") {
					url = line.substr(line.find(delimiter) + 1);
				}
				else {
					key = "";
					if (previousKey == "Abstract") {
						mAbstract = mAbstract.append("\n");
						mAbstract = mAbstract.append(line);
					}
				}
			}
			if(key.length() > 0)
				previousKey = key;
		}

	RSub* sub = NULL;

	if (projectId.length() == 0 || mProjTitle.length() == 0 || authors.size() == 0) {
		this->writeErrorLog("Invalid Data in : " + inputFile);
	}
	else if (url.length() > 0) {
		sub = new Blogs(url);
	}
	else if (patentNumber.length() > 0) {
		sub = new WPapers(patentNumber);
	}
	else if (sampleSize.length() > 0) {
		sub = new Articles(sampleSize, testingSite);
	}
	else if (refBooks.size() > 0) {
		sub = new RPapers(refBooks, refArticles, refChapters);
	}
	else {
		this->writeErrorLog("Invalid project : " + inputFile);
	}
	if (sub) {
		sub->setProjId(projectId);
		sub->setProjTitle(mProjTitle);
		sub->setAuthor(authors);
		sub->setAbstract(mAbstract);
		

		cout<<"submission type: "<<sub->mSubmissionType<<endl;
	}
        
	return sub;
}

void Conf::writeErrorLog(string msg) {
	ofstream myfile;
	
	myfile.open("invalidSubmissions.txt", ios::out | ios::app | ios::binary);
	if (myfile.is_open()) {
		myfile << msg << endl;
		myfile.close();
	}
	else cout << "Unable to open file";
}
void Conf::writeSuccessLog() {
	try{
	ofstream myfile;
	myfile.open("authorSubmissions.txt",ios::out | ios::app | ios::binary);
	if(!myfile.is_open())return;
	
	myfile << "Conference Name: " << mName << endl;
	myfile  << "Conference Location: " << mLoc << endl;
	char buff[20];
	struct tm * newtime;
	time_t now;
	newtime = localtime(&now);
	strftime(buff, 20, "%Y-%m-%d %H:%M:%S", newtime);
	myfile << "Conference Time::" << buff << endl;

	int cnt = 0;
	int cntResearches = 0;
	int cntWhitePapers = 0;
	int cntArticles = 0;
	int cntBlogs = 0;

	for (unsigned long int i = 0; i < (this->mSubmissions).size(); i++)
	{
		vector<string> authors = this->mSubmissions[i]->getAuthors();
		for (unsigned long int j = 0; j < authors.size(); j++){		
			myfile <<"Author: "<< authors[j]<<endl;	
		}
		cnt++;
		if (mSubmissions[i]->mSubmissionType == SubmissionType::Article)
				cntArticles++;
			else if (mSubmissions[i]->mSubmissionType == SubmissionType::Blog)
				cntBlogs++;
			else if (mSubmissions[i]->mSubmissionType == SubmissionType::ResearchPaper)
				cntResearches++;
			else if (mSubmissions[i]->mSubmissionType == SubmissionType::WhitePaper)
			cntWhitePapers++;

	}
	myfile << "Research Papers Count: " << cntResearches << endl;
	myfile  << "White Papers Count: " << cntWhitePapers << endl;
	myfile  << "Articles Count: " << cntArticles << endl;
	myfile  << "Blogs Count: " << cntBlogs << endl;
	myfile << "Total Submission Count: " << cnt << endl;
	myfile.close();
	}
		catch(...){
		cout <<"Error in writing success file."<<endl;
	}
}

void Conf::GetSubmissions(string author) {
	int cnt = 0;
	int cntResearches = 0;
	int cntWhitePapers = 0;
	int cntArticles = 0;
	int cntBlogs = 0;
	this->display();

	for (unsigned long int i = 0; i < (this->mSubmissions).size(); i++)
	{
		vector<string> authors = this->mSubmissions[i]->getAuthors();
		

		for (unsigned long int j = 0; j < authors.size(); j++){		
				if (author== authors[j]) {
				mSubmissions[i]->display();
				cnt++;
				if (mSubmissions[i]->mSubmissionType == SubmissionType::Article)
					cntArticles++;
				else if (mSubmissions[i]->mSubmissionType == SubmissionType::Blog)
					cntBlogs++;
				else if (mSubmissions[i]->mSubmissionType == SubmissionType::ResearchPaper)
					cntResearches++;
				else if (mSubmissions[i]->mSubmissionType == SubmissionType::WhitePaper)
					cntWhitePapers++;
			}
		}
	}
	cout << "Research Papers Count: " << cntResearches << endl;
	cout << "White Papers Count: " << cntWhitePapers << endl;
	cout << "Articles Count: " << cntArticles << endl;
	cout << "Blogs Count: " << cntBlogs << endl;
	cout << "Total Submission Count: " << cnt << endl;
}

int Conf::GetCountOfSubmissions(string author) {
	int cnt = 0;
	for (unsigned long int i = 0; i < this->mSubmissions.size(); i++)
	{
		vector<string> authors = this->mSubmissions[i]->getAuthors();

		for (unsigned long int j = 0; j < authors.size(); j++)
			if (authors[j] == author)
				cnt++;
	}
	cout << "Submission count: " << cnt << endl;

	return cnt;
}

Conf::~Conf() {
	for (unsigned long int i = 0; i < (this->mSubmissions).size(); i++)
	{
		delete this->mSubmissions[i];
	} 
}
