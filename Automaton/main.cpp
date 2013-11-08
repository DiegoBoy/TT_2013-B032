/*
 * main.cpp
 *
 *  Created on: Nov 4, 2013
 *      Author: Diego Boy
 */

#include <unistd.h>
#include "life.hpp"
#include <iostream>


using std::cout;
using std::endl;


int main()
{
	int x = 10;
	int y = 15;
	int n = 30;

	try
	{
		Life ac(x, y, n);

		for(int i = 0; i < 50; i++)
		{
			ac.draw();
			ac.update();
			sleep(2);
			cout << endl;
		}
	}
	catch(char c)
	{
		cout << c << endl;
		return 1;
	}



	return 0;
}
