/*
 * Author: Hadiyah Ghoghari
 * Date: 03-13-2020
 */

#ifndef CHOOSER_TYPE_H
#define CHOOSER_TYPE_H

#include <iostream>
using namespace std;

enum CHOOSER_TYPE {
	/*
	 * This class is used to pick which type of 
	 * choosing algorithm to implement. 
	 */
	ML, RANDOM, HUMAN
};

inline ostream& operator <<(ostream& ostr, const CHOOSER_TYPE type) {
	switch(type)
	{
		case CHOOSER_TYPE::ML : ostr << "Machine Language" << endl;break;
		case CHOOSER_TYPE::RANDOM : ostr << "Random" << endl;break;
		case CHOOSER_TYPE::HUMAN : ostr << "Human" << endl;break;
		default: ostr << "Invalid choice" << endl;
	}

	return ostr;
}

#endif /* CHOOSER_TYPE_H */