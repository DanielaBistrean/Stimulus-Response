#include <iostream>
#include <time.h>

#include <unistd.h>

#include "world.h"

void instructions()
{
	std::cout << "Welcome to the Stimulus Response Agent!\n\nPress any key to start the simulation ...";
	std::cin.get();
}

int
main(int argc, char const *argv[])
{
	srand(time(nullptr));

	instructions();

	std::unique_ptr<gamer> g{new gamer{}};

	world w(11, 14);
	w.setUserPos(std::move(g), 0, 0);
	
	
	w.setSpecialPos(SOLID, 0, 13);
	w.setSpecialPos(SOLID, 0, 12);
	w.setSpecialPos(SOLID, 0, 11);
	w.setSpecialPos(SOLID, 1, 13);
	w.setSpecialPos(SOLID, 1, 12);
	w.setSpecialPos(SOLID, 1, 11);
	w.setSpecialPos(SOLID, 2, 13);
	w.setSpecialPos(SOLID, 2, 12);
	w.setSpecialPos(SOLID, 2, 11);
	w.setSpecialPos(SOLID, 3, 13);
	w.setSpecialPos(SOLID, 3, 12);
	w.setSpecialPos(SOLID, 3, 11);

	w.setSpecialPos(SOLID, 7, 13);
	w.setSpecialPos(SOLID, 7, 12);
	w.setSpecialPos(SOLID, 7, 11);
	w.setSpecialPos(SOLID, 8, 13);
	w.setSpecialPos(SOLID, 8, 12);
	w.setSpecialPos(SOLID, 8, 11);
	w.setSpecialPos(SOLID, 9, 13);
	w.setSpecialPos(SOLID, 9, 12);
	w.setSpecialPos(SOLID, 9, 11);
	w.setSpecialPos(SOLID, 10, 13);
	w.setSpecialPos(SOLID, 10, 12);
	w.setSpecialPos(SOLID, 10, 11);


	w.setSpecialPos(SOLID, 9, 5);
	w.setSpecialPos(SOLID, 9, 6);
	w.setSpecialPos(SOLID, 9, 7);
	w.setSpecialPos(SOLID, 10, 5);
	w.setSpecialPos(SOLID, 10, 6);
	w.setSpecialPos(SOLID, 10, 7);

	w.setSpecialPos(SOLID, 4, 2);
	w.setSpecialPos(SOLID, 4, 3);
	w.setSpecialPos(SOLID, 5, 2);
	w.setSpecialPos(SOLID, 5, 3);
	w.setSpecialPos(SOLID, 6, 2);
	w.setSpecialPos(SOLID, 6, 3);

	w.setSpecialPos(SOLID, 4, 6);
	w.setSpecialPos(SOLID, 4, 7);
	w.setSpecialPos(SOLID, 5, 6);
	w.setSpecialPos(SOLID, 5, 7);
	w.setSpecialPos(SOLID, 6, 6);
	w.setSpecialPos(SOLID, 6, 7);

	w.setSpecialPos(SOLID, 4, 4);
	w.setSpecialPos(SOLID, 4, 5);

	do
	{
		usleep(80000);
	} while (w.nextStep());
	
	return 0;
}
