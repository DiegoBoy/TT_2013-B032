/*
 * cell.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Diego Boy
 */

#include "cell.hpp"


Cell::Cell() : state(0) {}


Cell::Cell(int s) : state(s) {}


int Cell::getState() const { return state; }


void Cell::setState(int state) { this->state = state; }
