#include "Bug.h"
#include <iostream>

using namespace std;

Bug::Bug(World* aWorld, int xcoord, int ycoord) : Organism(aWorld,xcoord,ycoord), feedTicks(0)
{
}

Bug::~Bug()
{
}

void Bug::move()
{
    //checks if we find something, and if that is an ant.
    bool antEater = false;

    if((world->getAt(x,y+1) != NULL)
            && (world->getAt(x,y+1)->getType() == ANT))
    {
        delete (world->getAt(x,y+1));
        movesTo(x,y+1);
        antEater = true;
    }
    else if((world->getAt(x,y-1) != NULL)
                && (world->getAt(x,y-1)->getType() == ANT))
    {
        delete (world->getAt(x,y-1));
        movesTo(x,y-1);
        antEater = true;
    }
    else if((world->getAt(x-1,y) != NULL)
                && (world->getAt(x-1,y)->getType() == ANT))
    {
        delete (world->getAt(x-1,y));
        movesTo(x-1,y);
        antEater = true;
    }
    else if((world->getAt(x+1,y) != NULL)
                && (world->getAt(x+1,y)->getType() == ANT))
    {
        delete (world->getAt(x+1,y));
        movesTo(x+1,y);
        antEater = true;
    }


    if(antEater == true)
    {
        feedTicks = 0;
        setMoved(true);
        breedTicks++;
    }
    else
    {
        moveRandomly();
        feedTicks++;
        breedTicks++;
    }
}

void Bug::breed()
{
    if(breedTicks >= BREED_BUGS)
    {
        breedAtAdjacentCell();
    }
}

OrganismType Bug::getType() const
{
    return BUG;
}

char Bug::representation() const
{
    return 'X';
}

bool Bug::isDead() const
{
    return (feedTicks >= STARVE_BUGS);
}

void Bug::generateOffspring(int whereX, int whereY)
{
    breedTicks = 0;
    new Bug(world,whereX,whereY);
}
