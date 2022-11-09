#include <iostream>
#include <cstring>
#include <iterator>
#include <conference.h>
#include <fstream>
#include <pthread.h>
#include <experimental/filesystem>

using namespace std;


int GetInput()
{
	int choice;
	cin>>choice;
	return choice;
}

void DisplayOptionsMenu(){
	cout<<"Options Menu\n";
	cout<<"1. Get Submissions by author name\n";
	cout<<"0-exit\n";
	cout<<"Selection: ";
}

pthread_mutex_t myMutex;
struct arg_struct{
	string conf_name;
	string loc;
	string file;
};
void* Worker_method(void *arguments){
	pthread_mutex_lock(&myMutex);
	struct arg_struct* args = (struct arg_struct*) arguments;
	Conf* conf = new Conf(args->conf_name,args->loc);

	conf->addSubmissions(args->file); 
	conf->writeSuccessLog();
	delete conf;
	pthread_mutex_unlock(&myMutex);
	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	struct arg_struct args;
	string conf_name, loc;
	cout<<"Enter Conference Name: ";
	std::getline(std::cin>>std::ws,args.conf_name);
	cout<<"Enter Location: ";
	std::getline(std::cin>>std::ws, args.loc);
	args.file = string(argv[1]);
	pthread_t thread;
	pthread_mutex_init(&myMutex, 0);
	int result_code=pthread_create(&thread,0,Worker_method, (void*)&args);
	
	result_code=pthread_join(thread,0);
	pthread_mutex_destroy(&myMutex);

	
	return 0;
}



