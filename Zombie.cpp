#include "Zombie.h"

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::equal_to;

Zombie::Zombie()
{
	this->color = 'R';
	this->colorCode = "31";
}

Zombie::Zombie(char color)
{
	this->color = color;

	// Determine color code
	switch (color)
	{
	case 'R':
		this->colorCode = "31";
		break;
	case 'Y':
		this->colorCode = "33";
		break;
	case 'G':
		this->colorCode = "32";
		break;
	case 'B':
		this->colorCode = "34";
		break;
	case 'M':
		this->colorCode = "35";
		break;
	case 'C':
		this->colorCode = "36";
		break;
	}
}

char Zombie::getColor()
{
	return this->color;
}

ostream& operator << (ostream& out, const Zombie& zombie)
{
	out << "\033[" << zombie.colorCode << "m[" << zombie.color << "]\033[0m";
	return out;
}

bool operator== (const Zombie& zombie1, const Zombie& zombie2)
{
	return (zombie1.color == zombie2.color);
}