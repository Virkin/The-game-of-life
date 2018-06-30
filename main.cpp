#include "World.h"

int main()
{
	int nbCell;
	World * world;
	
	cout << "Nb cell : ";
	cin >> nbCell;

	cout << nbCell << endl;

	world = new World(nbCell);

	return 0;
}