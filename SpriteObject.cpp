#include "SpriteObject.h"
SpriteObject::SpriteObject()
{}

SpriteObject::SpriteObject(std::string type, sf::Vector2f const& coordinates, std::string const& texture_file)
:object_type{type}, object_sprite{}
{
    if (!object_texture.loadFromFile(texture_file))
    {
        std::cerr << "ERROR: Texture not found for: " << object_type << std::endl;
    }
    object_sprite.setTexture(object_texture);
    object_sprite.setPosition(coordinates);
}