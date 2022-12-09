//
// Created by school on 2022-12-02.
//

#include "Character.h"
#include "Healthbar.h"

Character::Character(std::string const& type, sf::Vector2f const& coordinates, std::string const& texture_file)
: MovingObject(type, coordinates, texture_file)
{
}

void Character::attack() const
{
    int x{};
}

void Character::take_damage(float const& num)
{
    current_health -= (num - armor);
    if (current_health < 0)
    {
        set_current_health(0);
    }
}
