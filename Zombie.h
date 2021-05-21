#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

using std::string;
using std::ostream;

class Zombie
{
	private:
		char color;
		string colorCode;

	public:
		Zombie();
		Zombie(char color);

		char getColor();

		friend ostream& operator << (ostream& out, const Zombie& zombie);
		friend bool operator== (const Zombie& zombie1, const Zombie& zombie2);
};
#endif