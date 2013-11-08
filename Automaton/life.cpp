/*
 * Life.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Diego Boy
 */

#include <algorithm>
#include <iostream>
#include "life.hpp"


using std::cout;
using std::endl;
using std::swap;


vector<int> life_states()
{
	vector<int> s(1, 0);
	s.push_back(1);

	return s;
}


vector<int> life_dims(int x, int y)
{
	vector<int> d(1, x);
	d.push_back(y);

	return d;
}


Life::Life(int x, int y, int n) : Automaton<vector<Cell>>(life_states(), life_dims(x, y))
{
	Cell c(this->states[0]);
	vector<Cell> v(x, c);
	vector<vector<Cell>> v2(y, v);

	this->lattice = v2;
	this->buffer = v2;

	vector<int> s(1, 1);
	vector<int> q(1, n);

	init(s, q);
}


void Life::init(vector<int> & s_ini, vector<int> & quantity)
{
	int s = this->states[0];
	int q = quantity[0];
	int r1, r2;
	int max_x = this->dims[1];
	int max_y = this->dims[0];

	srand(time(NULL));

	if(q >= this->total)
	{
		cout << "More cells to be initialized than total..." << endl;
		throw 'q';
	}

	while(q)
	{
		r1 = rand() % max_y;
		r2 = rand() % max_x;

		if(this->lattice[r1][r2].getState() == s)
		{
			this->lattice[r1][r2].setState(s_ini[0]);
			q--;
		}
	}
}


void Life::transition()
{
	int s, count;
	int max_x = this->dims[1];
	int max_y = this->dims[0];
	int x_m1, x_M1;
	int y_m1, y_M1;

	for(int y = 0; y < max_y; y++)
	{
		for(int x = 0; x < max_x; x++)
		{
			count = 0;
			s = this->lattice[y][x].getState();

			x_m1 = x - 1;
			x_M1 = x + 1;
			y_m1 = y - 1;
			y_M1 = y + 1;

			if(!x) x_m1 = max_x - 1;
			if(!y) y_m1 = max_y - 1;
			if(x_M1 == max_x) x_M1 = 0;
			if(y_M1 == max_y) y_M1 = 0;

			count += this->lattice[y_m1][x_m1].getState();
			count += this->lattice[y_m1][x].getState();
			count += this->lattice[y_m1][x_M1].getState();
			count += this->lattice[y][x_M1].getState();
			count += this->lattice[y][x_m1].getState();
			count += this->lattice[y_M1][x_m1].getState();
			count += this->lattice[y_M1][x].getState();
			count += this->lattice[y_M1][x_M1].getState();

			if( (!s && count == 3) || (s && (count == 2 || count == 3)) )
				this->buffer[y][x].setState(1);
			else
				this->buffer[y][x].setState(0);
		}
	}
}


void Life::update()
{
	transition();
	swap(this->lattice, this->buffer);
}


void Life::draw() const
{
	for(int i = 0; i < this->dims[0]; i++)
	{
		for(int j = 0; j < this->dims[1]; j++)
		{
			cout << this->lattice[i][j].getState() << '\t';
		}

		cout << endl;
	}
}
