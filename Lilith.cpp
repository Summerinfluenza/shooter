//
// Created by oscarronndahl on 2022-12-08.
//
#include "Lilith.h"


Lilith::Lilith(sf::Vector2f const& coordinates, Player& player)
: Enemy("lilith", coordinates, "./textures/enemy/lilith.png", player)
{
    set_max_health(200);
    set_current_health(200);
}

void Lilith::update_object(sf::Time const& delta_time, std::vector<SpriteObject*> & relevant_objects)
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

    enemy_direction.x = 0;// bara för att se så worms spawnar
    enemy_direction.y = 0;// så står Lilith stilla.

    object_sprite.move(object_speed * enemy_direction * delta_time.asSeconds());

    sf::Time t = spawn_clock.getElapsedTime();
    float sec  = t.asSeconds();
    if (sec > 2)
    {
        spawn_worm(object_sprite.getPosition(), player, relevant_objects);
        spawn_clock.restart();
    }
}



void Lilith::collision(std::vector<SpriteObject*> relevant_objects, sf::Vector2f & direction)
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
                if ((*it)->get_type() == "wall")
                {
                    direction.x = 0;
                    direction.y = 0;
                    break;
                }
            }
        }
        it++;
    }
}


void Lilith::spawn_worm(sf::Vector2f start_pos, Player& player, std::vector<SpriteObject*> & all_objects)
{
    Worm* temp = new Worm(start_pos, player);

    all_objects.push_back(temp);
    all_objects.push_back(new Healthbar(static_cast<Character&>(*temp)));
}