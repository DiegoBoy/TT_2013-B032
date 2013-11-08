/*
 * cell.hpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Diego Boy
 */

#ifndef CELL_HPP_
#define CELL_HPP_


class Cell
{
	private:
		int state;

	public:
		Cell();
		Cell(int);
		int getState() const;
		void setState(int);
};


#endif /* CELL_HPP_ */
