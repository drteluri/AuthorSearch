#ifndef CONFERENCE_H
#define CONFERENCE_H

#include <iostream>
#include <ctime>
#include <blogs.h>
#include <rpapers.h>
#include <wpapers.h>
#include <articles.h>
#include <rsubmissions.h>
#include <vector>
using namespace std;

class Conf{
	public:
		Conf(string, string);
		~Conf();
		void setName(string);
		void setLoc(string);
		void setTime(time_t);
		
		string getName();
		string getLoc();
		time_t getTime();
		
		void display() const;
		void addSubmissions(string);
		int GetCountOfSubmissions(string);
		void GetSubmissions(string author);
		RSub * readInputFileInfo(string) ;

		void writeErrorLog(string msg);
		void writeSuccessLog();
		
private:
		string mName;
		string mLoc;
		time_t mTime;
		
		vector <RSub *> mSubmissions;
		
};

#endif


