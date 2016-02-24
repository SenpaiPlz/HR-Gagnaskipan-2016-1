#ifndef BUG_H
#define BUG_H

#include "Organism.h"
#include "World.h"

class Bug : public Organism
{
    public:

        Bug(World* aWorld, int xcoord, int ycoord);

        virtual ~Bug();

        virtual void move();

        virtual void breed();

        virtual OrganismType getType() const;

        virtual char representation() const;

        virtual bool isDead() const;


    protected:

        virtual void generateOffspring(int whereX, int whereY);

        int feedTicks;
};
#endif // BUG_H
