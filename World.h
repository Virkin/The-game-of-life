#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

class World
{
	private:
		static const int MAX_X = 150;
		static const int MAX_Y = 38;

		char id_live = 'o';
		char id_dead = ' ';

		char before[MAX_Y][MAX_X];
		char after[MAX_Y][MAX_X];

	public:
		World(int nb_live);
		~World();

		void Initialization(int nb_life);

		void Move();
		int Neighboor_Counting(int nb_neighboor, int posi, int posj);
		int Check_InMap(int posi, int posj);
		int Check_Life(int posi, int posj, int nb_life);

		void Display();
};