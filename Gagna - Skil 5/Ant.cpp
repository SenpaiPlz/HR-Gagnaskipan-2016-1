#include "Ant.h"

Ant::Ant(World* aWorld, int xcoord, int ycoord) : Organism(aWorld,xcoord,ycoord)
{
}

Ant::~Ant()
{
}

void Ant::move()
{
    moveRandomly();
    breedTicks++;
}

void Ant::breed()
{
    if(breedTicks >= BREED_ANTS)
    {
        breedAtAdjacentCell();
    }
}

OrganismType Ant::getType() const
{
    return ANT;
}

char Ant::representation() const
{
    return 'o';
}

bool Ant::isDead() const
{
    return false;
}

void Ant::generateOffspring(int whereX, int whereY)
{
    breedTicks = 0;
    new Ant(world,whereX,whereY);
}
