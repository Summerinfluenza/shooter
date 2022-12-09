#ifndef WALL_H
#define WALL_H

#include "SpriteObject.h"


class Wall : public SpriteObject
{
    public:
    Wall(sf::Vector2f const& coordinates);

    void update_object(sf::Time const& delta_time, std::vector<SpriteObject*> & relevant_objects);

};



#endif