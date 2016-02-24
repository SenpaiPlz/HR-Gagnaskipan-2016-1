#include <iostream>
#include "Organism.h"
#include "World.h"

// Create an organism at the given coordinates in the given world
Organism::Organism(World* aWorld, int xcoord, int ycoord) {
    world = aWorld;
    x = xcoord;
    y = ycoord;
    breedTicks = 0;
    moved = false;
    world->setAt(x, y, this);
}


void Organism::setMoved(bool hasMoved) {   // flags the organism as moved or not
    moved = hasMoved;
}

bool Organism::hasMoved() const {  // has the organism moved or not?
    return moved;
}

// Makes a random move by calling movesTo().  Called by move() in the subclasses
void Organism::moveRandomly()
{
        /*** You have to implement this function ***/
        Move tmpMov = world->randomMove();
        if((tmpMov == UP) && (world->getAt(x,y+1) == NULL) && (y+1 < WORLDSIZE))
        {
            movesTo(x,y+1);
        }
        else if ((tmpMov == DOWN) && (world->getAt(x,y-1) == NULL) && (y-1 >= 0))
        {
            movesTo(x,y-1);
        }
        else if ((tmpMov == LEFT) && (world->getAt(x-1,y) == NULL) && (x-1 >= 0))
        {
            movesTo(x-1,y);
        }
        else if ((tmpMov == RIGHT) && (world->getAt(x+1,y) == NULL) && (x+1 < WORLDSIZE))
        {
            movesTo(x+1,y);
        }
}

void Organism::movesTo(int xNew, int yNew) // moves the organism from coordinates (x,y) to (xNew,yNew)
{
        /*** You have to implement this function ***/
        world->setAt(xNew,yNew,this);
        world->setAt(x,y,NULL);
        x = xNew;
        y = yNew;
        setMoved(true);
}

void Organism::breedAtAdjacentCell()  { // breeds an organism at an adjacent cell
	// Tries to produce one new organism in UP, DOWN, LEFT, or RIGHT cell (in that order)
	// Makes sure not to breed off the grid
    // This method calls the generateOffspring() method

        /*** You have to implement this function ***/
        if((world->getAt(x,y+1) == NULL) && (y+1 < WORLDSIZE))
        {
            generateOffspring(x,y+1);
        }
        else if ((world->getAt(x,y-1) == NULL) && (y-1 >= 0))
        {
            generateOffspring(x,y-1);
        }
        else if ((world->getAt(x-1,y) == NULL) && (x-1 >= 0))
        {
            generateOffspring(x-1,y);
        }
        else if ((world->getAt(x+1,y) == NULL) && (x+1 < WORLDSIZE))
        {
            generateOffspring(x+1,y);
        }
}

bool Organism::isDead() const { // Returns true if organism is dead, false otherwise.
    return false;
}
