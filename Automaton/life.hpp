/*
 * Life.hpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Diego Boy
 */

#ifndef LIFE_HPP_
#define LIFE_HPP_


#include "automaton.hpp"


class Life : public Automaton<vector<Cell> >
{
	private:
		void init(vector<int> &, vector<int> &);
		void transition();

	public:
		Life(int, int, int);
		void update();
		void draw() const;
};


#endif /* LIFE_HPP_ */
