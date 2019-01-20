#include "gamer.h"
#include <iostream>

actions
gamer::nextAction(const std::vector<bool>& features)
{
	bool x1 = features[1] || features[2];
	bool x2 = features[3] || features[4];
	bool x3 = features[5] || features[6];
	bool x4 = features[7] || features[0];

	if (x1 && !x2)
		return RIGHT;

	if (x2 && !x3)
		return DOWN;

	if (x3 && !x4)
		return LEFT;

	if (x4 && !x1)
		return UP;

	return UP;
 }
