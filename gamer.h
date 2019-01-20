#ifndef GAMER_H
#define GAMER_H 1

#include <memory>
#include <vector>

#include "square.h"
#include "world.h"

enum actions : int
{
	RIGHT,
	LEFT,
	UP,
	DOWN
};

class gamer
{
public:
	gamer() = default;
	actions nextAction(const std::vector<bool>& features);
};

#endif
