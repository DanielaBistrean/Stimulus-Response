#ifndef SQUARE_H
#define SQUARE_H 1

enum SquareType
{
	SOLID, 
	OK
};

class square
{
public:
	square(SquareType st = OK);
	SquareType getType();
	void setType(SquareType st);

private:
	SquareType m_type;
};

#endif
