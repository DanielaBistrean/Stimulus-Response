#ifndef WORLD_H
#define WORLD_H 1

#include <memory>

#include "gamer.h"
#include "square.h"

enum orientation : int;

class gamer;

// the world holds the player position and reference
class world
{
public:
	world(int x, int y);
	~world();
	void setUserPos(std::unique_ptr<gamer>&& gamer, int gamer_x, int gamer_y);
	void Print();
	bool nextStep();
	void setSpecialPos(SquareType st, int x, int y, bool value = true);
	bool positionIsValid(int x, int y);
private:
	int m_x, m_y;
	square** m_matrix;
	int m_gamer_x, m_gamer_y;
	std::unique_ptr<gamer> m_gamer;
};

#endif
