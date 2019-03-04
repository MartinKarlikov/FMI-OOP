#include "Histogram.h"
#include <iostream>

CountedName::CountedName()
{
	name = nullptr;
	numOfEncounters = 1;
}

CountedName::~CountedName()
{
	delete[] name;
}

CountedName::CountedName(const CountedName& other)
{
	name = nullptr;
	copyStr(name, other.name);

	numOfEncounters = other.numOfEncounters;
}

CountedName & CountedName::operator=(const CountedName & other)
{
	if (this != &other)
	{
		delete[] name;
	}

	name = nullptr;
	copyStr(name, other.name);

	numOfEncounters = other.numOfEncounters;

	return *this;
}

void CountedName::setName(char * name)
{
	if (!this->name)
	{
		copyStr(this->name, name);
	}
}

void CountedName::incrCount()
{
	numOfEncounters += 1;
}

char * CountedName::getName() const
{
	char* toReturn = nullptr;
	copyStr(toReturn, name);

	return toReturn;
}

unsigned CountedName::getNumEncounters() const
{
	return numOfEncounters;
}

void copyStr(char *& dest,const char * source)
{
	if (dest)
	{
		delete[] dest;
	}

	unsigned size = strlen(source) + 1;

	dest = new char[size];

	strcpy_s(dest, size, source);
}

Histogram::Histogram()
{

	hist = nullptr;

	maxIndex = -1;

	size = 0;
}

Histogram::~Histogram()
{
	delete[] hist;
}

int Histogram::getCnt(char * name) const
{

	for (size_t i = 0; i < size; ++i)
	{
		if (!strcmp(hist[i].getName(),name))
		{
			return hist[i].getNumEncounters();
		}
	}

	return -1;
}

void Histogram::sort()
{
	for (int i = 0; i<size; i++)
	{
		for (int j = i + 1; j<size; j++)
		{
			if (hist[i].getNumEncounters() < hist[j].getNumEncounters())
			{
				std::swap(hist[i], hist[j]);
			}
		}
	}
}

CountedName Histogram::getMax() const
{

	if (maxIndex == -1)
	{
		std::cout << "There are no elements to get max from.." << std::endl;
		return CountedName();
	}

	return hist[maxIndex];
}

unsigned Histogram::getSize() const
{
	return size;
}

void Histogram::add(CountedName toAdd)
{

	for (size_t i = 0; i < size; ++i)
	{
		if (!strcmp(toAdd.getName(),hist[i].getName()))
		{

			if (maxIndex == -1
				|| hist[i].getNumEncounters() + 1 > hist[maxIndex].getNumEncounters())
			{
				maxIndex = i;
			}

			hist[i].incrCount();
			return;
		}
	}

	CountedName* tempResizeHolder = new CountedName[size + 1];

	for (size_t i = 0; i < size; ++i)
	{
		tempResizeHolder[i] = hist[i];
	}

	if (maxIndex == -1)
	{
		maxIndex = 0;
	}

	tempResizeHolder[size] = toAdd;

	delete[] hist;
	hist = tempResizeHolder;
	size++;

}

void Histogram::deleteName(char * name)
{

	bool exists = false;

	for (size_t i = 0; i < size; ++i)
	{

		if (!strcmp(name,hist[i].getName()))
		{
			exists = true;
			break;
		}

	}

	if (!exists)
	{
		std::cout << "Can't delete non existing element" << std::endl;
		return;
	}

	CountedName* tempResizeHolder = new CountedName[size - 1];

	unsigned tempIndex = 0;
	for (size_t i = 0; i < size; ++i)
	{

		if (strcmp(name,hist[i].getName()))
		{
			tempResizeHolder[tempIndex] = hist[i];
			tempIndex++;
		}

	}

	delete[] hist;
	hist = tempResizeHolder;

	size--;

}

void Histogram::show()
{

	for (size_t i = 0; i < size; i++)
	{
		std::cout << hist[i].getName() << " -  " << hist[i].getNumEncounters() << std::endl;
	}
	
}
