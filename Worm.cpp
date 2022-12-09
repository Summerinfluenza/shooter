//
// Created by oscarronndahl on 2022-12-08.
//
#include "Worm.h"


Worm::Worm(sf::Vector2f const& coordinates, Player& player)
: Enemy("worm", coordinates, "./textures/enemy/worm.png" ,player)
{
    object_speed *= 2;
    set_max_health(20);
    set_current_health(20);
}

void Worm::update_object(sf::Time const& delta_time, std::vector<SpriteObject*> & relevant_objects)
{
    sf::Vector2f player_pos = player.get_sprite().getPosition();

    // Calculates enemies direction towards player.
    sf::Vector2f enemy_direction = (player_pos - object_sprite.getPosition());
    float mag = sqrtf(enemy_direction.x * enemy_direction.x +
                      enemy_direction.y * enemy_direction.y);
    if (mag != 0)
    {
        enemy_direction /= mag;
    }
    collision(relevant_objects, enemy_direction);
    if (current_health <= 0)
    {
        terminate = true;
    }

    object_sprite.move(object_speed * enemy_direction * delta_time.asSeconds());
}



void Worm::collision(std::vector<SpriteObject*> relevant_objects, sf::Vector2f & direction)
{
    sf::FloatRect enemy_bound_box = object_sprite.getGlobalBounds();

    sf::FloatRect next_move = enemy_bound_box;
    next_move.top += direction.y;
    next_move.left += direction.x;

    auto it = relevant_objects.begin();
    while (it != relevant_objects.end())
    {
        if (*it != this)
        {
            sf::FloatRect object_bound = (*it)->get_sprite().getGlobalBounds();
            if ( next_move.intersects(object_bound) )
            {
                if ((*it)->get_type() == "player")
                {
                    take_damage(max_health);  //Nu försvinner healthbaren också.
                    static_cast<Character*>(*it)->take_damage(20);
                    break;
                }

                else if ((*it)->get_type() == "wall" || (*it)->get_type() == "worm")
                {
                    if (object_sprite.getPosition().x + 16.f > (*it)->get_sprite().getPosition().x)
                    {
                        object_sprite.setPosition(object_sprite.getPosition().x + 1, object_sprite.getPosition().y);
                        direction.x = 0;
                    }
                    if (object_sprite.getPosition().x < (*it)->get_sprite().getPosition().x + 16.f)
                    {
                        object_sprite.setPosition(object_sprite.getPosition().x - 1, object_sprite.getPosition().y);
                        direction.x = 0;
                    }
                    
                    if (object_sprite.getPosition().y + 16.f < (*it)->get_sprite().getPosition().y)
                    {
                        object_sprite.setPosition(object_sprite.getPosition().x, object_sprite.getPosition().y - 1);
                        direction.y = 0;
                    }
                    
                    if (object_sprite.getPosition().y > (*it)->get_sprite().getPosition().y + 16.f)
                    {
                        object_sprite.setPosition(object_sprite.getPosition().x, object_sprite.getPosition().y + 1);
                        direction.y = 0;
                    }
                    break;
                }
            }
        }
        it++;
    }
}