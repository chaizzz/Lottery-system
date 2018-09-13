#include <iostream>
#include <string>
#include "Vector"
#include <ctime>
#include <unistd.h>
#include <fstream>
#include <cstdlib>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		std::cerr << "Usage error!" << std::endl;
		return 1;
	}

	srand(time(NULL));

	std::ifstream in(argv[1]);

	if(!in)
	{
		std::cout << "打开 "<< argv[1] <<" 失败"<<std::endl;
		return 2;
	}

	std::string name;
	Vector<std::string> names;	

	while(1)
	{
		in >> name;
		if(!in) break;
		names.push_back(name);
	}
	
	std::cout << "共有" << names.size() << "人 \n";
	std::cout << "即将开始抽取.....\n";
	sleep(1);
	int n, i;

	for(i = 0; i < 20; ++i)
	{
		system("clear");
		n = rand() % names.size();

		std::cout << names[n] << std::endl;
		usleep(i * i * 500);
	}

	return 0;
}
