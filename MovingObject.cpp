//
// Created by school on 2022-12-02.
//

#include "MovingObject.h"

#include <utility>

MovingObject::MovingObject(std::string  type, sf::Vector2f const& coor, std::string const& texture_file)
:SpriteObject(type, coor, texture_file)
{}