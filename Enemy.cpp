//
// Created by school on 2022-12-02.
//

#include "Enemy.h"
#include <cmath>
#include <iostream>

Enemy::Enemy(std::string const& name, sf::Vector2f const& coordinates, std::string const& texture_file, Player& player)
: Character(name, coordinates, texture_file), player{player}
{
    set_max_health(20);
    set_current_health(20);
}


/*
void Enemy::update_object(sf::Time const& delta_time, std::vector<MovingObject*> relevant_objects)
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



    object_sprite.move(object_speed * enemy_direction * delta_time.asSeconds());
}



void Enemy::collision(std::vector<MovingObject*> relevant_objects, sf::Vector2f & direction)
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
                 //   take_damage(max_health);
                    terminate = true;
                 //   player.take_damage(20);
                    break;
                }

                else if ((*it)->get_type() == "bullet")
                {
                    //take damage maby bullet responsebillity.
                    take_damage(5);
                    if (current_health <= 0)
                    {
                        terminate = true;
                    }
                    break;
                }

                else if ((*it)->get_type() == "wall")
                {
                    direction.x = 0;
                    direction.y = 0;
                    break;
                }
            }
        }
        it++;
    }
}*/
