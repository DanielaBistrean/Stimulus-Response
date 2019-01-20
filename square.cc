#include "square.h"

SquareType
square::getType()
{
	return m_type;
}

void
square::setType(SquareType st)
{
	m_type = st;
}

square::square(SquareType st)
: m_type{st}
{}
