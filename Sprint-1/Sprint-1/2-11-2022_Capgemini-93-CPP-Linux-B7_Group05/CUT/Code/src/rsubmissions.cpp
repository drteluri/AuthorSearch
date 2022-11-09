#include <iostream>

#include <vector>
#include <cstring>
#include <rsubmissions.h>

using namespace std;

void RSub::setProjId(string projId){
	this->mProjId=projId;
}

string RSub::getProjId(){
	return mProjId;
}

void RSub::setProjTitle(string projTitle){
	this->mProjTitle=projTitle;
}

string RSub::getProjTitle(){
	return mProjTitle;
}

void RSub::setAbstract(string abstract){
	this->mAbstract=abstract;
}

string RSub::getAbstract(){
	return mAbstract;
}

void RSub::setAuthor(vector<string> authors){
	this->mAuthors=authors;
}

vector<string> RSub::getAuthors(){
	return mAuthors;
}

