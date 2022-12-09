#include "Wall.h"

Wall::Wall(sf::Vector2f const& coordinates)
: SpriteObject("wall", coordinates, "textures/static/wall.png")
{

}


void Wall::update_object(sf::Time const& delta_time, std::vector<SpriteObject*> & relevant_objects)
{
    int x{};
}