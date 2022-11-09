#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<cstdlib>
using namespace std;
#include <sstream>
#include<cstring>

#include<ctime>
#include"rsub.h"

using namespace std;

int main(){
    //Current date
    
     time_t now = time(0);
     tm *itm = localtime(&now);
     
     DATE cur(itm->tm_mday,itm->tm_mon,1900+itm->tm_year);
     cur.dateDisplay();
    

    string dd2;
    string mm2;
    string yy2;
    int dd1;
    int mm1;
    int yy1;
    string str;
    cout<<"ENTER THE STRING IN DD/MM/YYYY FORMAT: "<<endl;
    getline(cin,str);
    

    
    stringstream ss(str);
    if(getline(ss,dd2,'/')){
        dd1=stoi(dd2);
    }
    if(getline(ss,mm2,'/')){
       mm1=stoi(mm2);
    }
    if(getline(ss,yy2,'/')){
       yy1=stoi(yy2);
    }
    DATE prjDate(dd1,mm1,yy1);
    prjDate.dateDisplay();

    if((cur<prjDate)==1){
        cout<<"CUR DATE IS LESS"<<endl;
    }else if((cur<prjDate)==-1){
        cout<<"CUR DATE IS GREAT"<<endl;
    }else if((cur<prjDate)==0){
        cout<<"SAME"<<endl;
    }
   // cout<<dd1<<mm1<<yy1;
}
