#ifndef ANT_H
#define ANT_H

#include "Organism.h"
#include "World.h"

class Ant : public Organism
{
    public:

        Ant(World* aWorld, int xcoord, int ycoord);

        virtual ~Ant();

        virtual void move();

        virtual void breed();

        virtual OrganismType getType() const;

        virtual char representation() const;

        virtual bool isDead() const;


    protected:

        virtual void generateOffspring(int whereX, int whereY);

};

#endif // ANT_H
