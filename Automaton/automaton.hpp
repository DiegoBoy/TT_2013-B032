/*
 * automaton.hpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Diego Boy
 */

#ifndef AUTOMATON_HPP_
#define AUTOMATON_HPP_


#include <algorithm>
#include <iostream>
#include <vector>
#include "cell.hpp"


using std::copy;
using std::cout;
using std::endl;
using std::reverse;
using std::vector;


template <class T>
class Automaton
{
	private:
		virtual void transition() = 0;
		virtual void init(vector<int> &, vector<int> &) = 0;

	protected:
		int total;
		vector<int> states;
		vector<int> dims;
		vector<T> lattice;
		vector<T> buffer;

	public:
		Automaton(vector<int>, vector<int>);
		virtual ~Automaton();
		virtual void update() = 0;
		virtual void draw() const = 0;
};


template <class T>
Automaton<T>::Automaton(vector<int> states, vector<int> dims)
{
	int i = 1;

	if(states.empty() || dims.empty())
	{
		cout << "Empty vector (states || dims)..." << endl;
		throw 'e';
	}

	reverse(dims.begin(), dims.end());

	for(vector<int>::iterator it = dims.begin(); it != dims.end(); it++)
	{
		i *= *it;
	}

	this->total = i;
	this->states = states;
	this->dims = dims;
}


template <class T>
Automaton<T>::~Automaton() {}


#endif /* AUTOMATON_HPP_ */
