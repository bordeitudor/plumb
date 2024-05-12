#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>

struct Location {
	char ch; // Current character
	int l, c; // Line, Chr
	File &file;

	Location(File &file)
		:file(file)
	{

	}
};

static std::ostream &operator<<(std::ostream &os, const Location& l)
{
	os << l.file.path() << ":" << l.l << ":" << l.c;
	return os;
}

#endif // LOCATION_H