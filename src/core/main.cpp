#include "Application.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
	Application app(argc, argv);
	app.loadPlugins(argc, argv);
	
	std::cout<<"exiting..."<<std::endl;
	return 0;
}
