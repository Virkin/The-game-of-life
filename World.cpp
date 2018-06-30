#include "World.h"

World::World(int nb_life)
{	
	Initialization(nb_life);
	Move();
}

World::~World()
{

}

void World::Initialization(int nb_life)
{
	srand(time(NULL));
	int posi,posj;

	for(int i=0; i<MAX_Y; i++)
	{
		for (int j=0; j<MAX_X; j++)
		{
			before[i][j] = ' ';
			after[i][j] = ' ';
		}
	}
	for(int i=0; i<nb_life; i++)
	{
		posi = rand()%MAX_Y;
		posj = rand()%MAX_X;
		after[posi][posj] = id_live;		
	}

	Display();
	sleep(5);
}

void World::Move()
{
	while(1)
	{
		for(int i=0; i<MAX_Y; i++)
		{
			for(int j=0; j<MAX_X; j++)
			{
				before[i][j] = after[i][j];
			}
		}

		for(int i=0; i<MAX_Y; i++)
		{
			for(int j=0; j<MAX_X; j++)
			{
				if(before[i][j] == id_dead && Neighboor_Counting(3,i,j) == 0)
				{
					after[i][j] = id_live;
				}
				else if(before[i][j] == id_live && ( Neighboor_Counting(2,i,j) == 0 || Neighboor_Counting(3,i,j) == 0))
				{
					after[i][j] = id_live;
				}
				else
				{
					after[i][j] = id_dead;
				}
			}
		}

		Display();
		sleep(1);
	}
}

int World::Neighboor_Counting(int nb_neighboor, int posi, int posj)
{
	int nb_life = 0;	

	if(Check_InMap(posi-1, posj-1) == 0)
	{
		nb_life = Check_Life(posi-1, posj-1, nb_life);
	}

	if(Check_InMap(posi-1, posj) == 0)
	{
		nb_life = Check_Life(posi-1, posj, nb_life);
	}

	if(Check_InMap(posi, posj-1) == 0)
	{
		nb_life = Check_Life(posi, posj-1, nb_life);
	}

	if(Check_InMap(posi+1, posj) == 0)
	{
		nb_life = Check_Life(posi+1, posj, nb_life);
	}

	if(Check_InMap(posi, posj+1) == 0)
	{
		nb_life = Check_Life(posi, posj+1, nb_life);
	}

	if(Check_InMap(posi+1, posj+1) == 0)
	{
		nb_life = Check_Life(posi+1, posj+1, nb_life);
	}

	if(Check_InMap(posi-1, posj+1) == 0)
	{
		nb_life = Check_Life(posi-1, posj+1, nb_life);
	}

	if(Check_InMap(posi+1, posj-1) == 0)
	{
		nb_life = Check_Life(posi+1, posj-1, nb_life);
	}

	if(nb_life == nb_neighboor)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int World::Check_InMap(int posi, int posj)
{
	if(posi >= 0 && posi < MAX_Y && posj >= 0 && posj < MAX_X)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int World::Check_Life(int posi, int posj, int nb_life)
{
	if(before[posi][posj] == id_live)
	{
		nb_life++;
	}
	return nb_life;
}

void World::Display()
{
	system("clear");
	for(int i=0; i<MAX_Y; i++)
	{
		for(int j=0; j<MAX_X; j++)
		{
			cout << after[i][j];
		}
		cout << endl;
	}
}
