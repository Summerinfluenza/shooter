//
// Created by school on 2022-12-02.
//

#include "Projectile.h"
#include <cmath>
#include "Character.h"

Projectile::Projectile(sf::Vector2f const& spawn_position, sf::Vector2f mouse_pos)
: MovingObject("bullet", spawn_position, "./textures/projectile/bullet.png"), original_position{spawn_position}
{
    direction = mouse_pos - spawn_position;
    float mag = sqrtf(direction.x * direction.x + direction.y * direction.y);
    if (mag != 0)
    {
        direction /= mag;
    }
}


void Projectile::update_object(sf::Time const& delta_time, std::vector<SpriteObject*> & relevant_objects)
{
    collision(relevant_objects, direction);
    object_sprite.move(object_speed * 10 * direction * delta_time.asSeconds());
    if (abs(this->get_sprite().getPosition().x - original_position.x) > 300.f ||
        abs(this->get_sprite().getPosition().y - original_position.y) > 300.f)
    {
        terminate = true;
    }
}


void Projectile::collision(std::vector<SpriteObject*> relevant_objects, sf::Vector2f & direction_d)
{
    sf::FloatRect current_object_bound = object_sprite.getGlobalBounds();
    sf::FloatRect next_move = current_object_bound;
    next_move.top += direction_d.y;
    next_move.left += direction_d.x;

    auto it = relevant_objects.begin();
    while (it != relevant_objects.end())
    {
        if (*it != this)
        {
            sf::FloatRect object_bound = (*it)->get_sprite().getGlobalBounds();
            if ( next_move.intersects(object_bound) )
            {
                if ((*it)->get_type() == "worm" || (*it)->get_type() == "lilith" )
                {
                    static_cast<Character*>(*it)->take_damage(5);
                    terminate = true;
                    break;
                }
                else if ( (*it)->get_type() == "wall" )
                {
                    terminate = true;
                    break;
                }
                
            }
        }
        it++;
    }
}