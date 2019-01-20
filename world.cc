#include <iostream>
#include <stdlib.h>

#include "world.h"

world::world(int x, int y)
: m_x{x}
, m_y{y}
, m_gamer_x{1}
, m_gamer_y{1}
{
	m_matrix = new square*[x];

	for (int i = 0; i < x; i++)
	{
		m_matrix[i] = new square[y];
	}
}

void
world::setUserPos(std::unique_ptr<gamer>&& gamer, int gamer_x, int gamer_y)
{
	m_gamer = std::move(gamer);
	m_gamer_x = gamer_x;
	m_gamer_y = gamer_y;
}

void
world::Print()
{
	std::cout << "World size = " << m_x << "x" << m_y << "\n";
	std::cout << "+";
	for (int y = 1; y <= m_y; y++)
	{
		std::cout << "---+";
	}
	std::cout << "\n";
	for (int x = 0; x < m_x; x++)
	{
		std::cout << "|";
		for (int y = 0; y < m_y; y++)
		{
			square& s = m_matrix[x][y];

			if ((x == m_gamer_x) && (y == m_gamer_y))
			{
				std::cout << " X ";
			}
			else
			{
				if (s.getType() == SOLID)
				{
					std::cout << "###";
				}
				else
				{
					std::cout << "   ";
				}
			}
			std::cout << "|";
		}

		std::cout << "\n";

		std::cout << "+";
		for (int y = 0; y < m_y; y++)
		{
			std::cout << "---+";
		}
		std::cout << std::endl;
	}
}

bool
world::nextStep()
{
	square& s = m_matrix[m_gamer_x][m_gamer_y];
	std::vector<bool> features(8, true);

	if (m_gamer_x-1 >= 0)
	{
		if (m_gamer_y-1 >= 0 && m_matrix[m_gamer_x-1][m_gamer_y-1].getType() == OK)
			features[0] = false;

		if (m_matrix[m_gamer_x-1][m_gamer_y].getType() == OK)
			features[1] = false;

		if (m_gamer_y+1 < m_y && m_matrix[m_gamer_x-1][m_gamer_y+1].getType() == OK)
			features[2] = false;
	}

	if (m_gamer_x+1 < m_x)
	{
		if (m_gamer_y-1 >= 0 && m_matrix[m_gamer_x+1][m_gamer_y-1].getType() == OK)
			features[6] = false;

		if (m_matrix[m_gamer_x+1][m_gamer_y].getType() == OK)
			features[5] = false;

		if (m_gamer_y+1 < m_y && m_matrix[m_gamer_x+1][m_gamer_y+1].getType() == OK)
			features[4] = false;
	}


	if (m_gamer_y+1 < m_y && m_matrix[m_gamer_x][m_gamer_y+1].getType() == OK)
		features[3] = false;

	if (m_gamer_y-1 >= 0 && m_matrix[m_gamer_x][m_gamer_y-1].getType() == OK)
		features[7] = false;

	system("clear");
	Print();
	std::cout << "features:";
	for (bool b : features)
	{
		std::cout << " " << b;
	}
	std::cout << "\n";

	actions a = m_gamer->nextAction(features);

	if (a == UP && m_gamer_x-1 >= 0 && m_matrix[m_gamer_x-1][m_gamer_y].getType() == OK)
	{
		m_gamer_x--;
		return true;
	}

	if (a == DOWN && m_gamer_x+1 < m_x && m_matrix[m_gamer_x+1][m_gamer_y].getType() == OK)
	{
		m_gamer_x++;
		return true;
	}

	if (a == LEFT && m_gamer_y-1 >= 0 && m_matrix[m_gamer_x][m_gamer_y-1].getType() == OK)
	{
		m_gamer_y--;
		return true;
	}

	if (a == RIGHT && m_gamer_y+1 < m_y && m_matrix[m_gamer_x][m_gamer_y+1].getType() == OK)
	{
		m_gamer_y++;
		return true;
	}
	
	return false;
}

void
world::setSpecialPos(SquareType st, int x, int y, bool value)
{
	square& s = m_matrix[x][y];
	s.setType(st);
}

bool
world::positionIsValid(int x, int y)
{
	if ((x < m_x && y < m_y) && (x >= 0 && y >= 0))
		return true;

	return false;
}

world::~world()
{
	for (int i = 0; i < m_x; i++)
	{
		delete [] m_matrix[i];
	}
	delete [] m_matrix;
}
