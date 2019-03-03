#pragma once

void copyStr(char*& dest,const char  * source);

class CountedName
{

public:

	CountedName();
	~CountedName();

	CountedName(const CountedName& other);

	CountedName& operator=(const CountedName& other);

	void setName(char* name);
	void incrCount();

	char* getName() const;
	unsigned getNumEncounters() const;

private:

	char* name;
	unsigned numOfEncounters;
};

class Histogram
{

public:

	Histogram();
	~Histogram();

	void sort();

	int getCnt(char* name) const;
	CountedName getMax() const;
	unsigned getSize() const;
	
	void add(CountedName name);
	void deleteName(char* name);

	void show();

private:

	CountedName* hist;
	int maxIndex;
	unsigned size;

};