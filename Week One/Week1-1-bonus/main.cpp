#include "Histogram.h"
#include <iostream>

char* inputStr()
{
	char* name;
	char buff[1024];

	std::cin.getline(buff, 1024);

	unsigned size = strlen(buff) + 1;

	name = new char[size];

	strcpy_s(name, size, buff);

	return name;
}

int main()
{
	Histogram hist;

	char* input = inputStr();

	char* test;

	while (strcmp(input,"END"))
	{

		if (!strcmp(input,"SHOW"))
		{
			hist.show();
		}

		else if (!strcmp(input, "DELETE"))
		{
			char* newName = inputStr();
			hist.deleteName(newName);
		}

		else
		{
			CountedName toAdd;
			toAdd.setName(input);
			hist.add(toAdd);
		}

		delete[] input;	
		input = inputStr();
			
	}

	std::cout << (hist.getMax()).getNumEncounters() << std::endl;

	hist.sort();

	hist.show();

	return 0;
}
