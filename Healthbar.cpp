//
// Created by school on 2022-12-06.
//

#include "Healthbar.h"


Healthbar::Healthbar(Character& character)
:character_object{character}
{
    object_type = "healthbar";
    if (character.get_type() == "lilith")
    {
        bar_length *= 2;
    }
    init_healthbar();
}

void Healthbar::init_healthbar()
{
    float frac = character_object.get_current_health() / character_object.get_max_health();

    current_health.setSize(sf::Vector2f(frac * bar_length, 5.f));
    
    current_health.setFillColor(sf::Color::Red);

    if (character_object.get_type() == "player")
    {
        current_health.setFillColor(sf::Color::Green);
    }
    current_health.setPosition(character_object.get_sprite().getPosition().x, 
                               character_object.get_sprite().getPosition().y - 20);

    max_health.setSize(sf::Vector2f(bar_length, 5.f));
    max_health.setFillColor(sf::Color::Transparent);
    max_health.setOutlineThickness(2);
    max_health.setOutlineColor(sf::Color(100, 100, 100));
    max_health.setPosition(current_health.getPosition());
}

void Healthbar::update_object(sf::Time const& delta_time, std::vector<SpriteObject*> & relevant_objects)
{
    float frac = character_object.get_current_health() / character_object.get_max_health();

    if (character_object.get_current_health() <= 0)
    {
        terminate = true;
        return;
    }
    current_health.setSize(sf::Vector2f(frac * bar_length, 5.f));

    current_health.setPosition(character_object.get_sprite().getPosition().x, 
                               character_object.get_sprite().getPosition().y - 20);
                               
    max_health.setPosition(current_health.getPosition());
}

void Healthbar::render(sf::RenderTarget &target)
{
    target.draw(current_health);
    target.draw(max_health);

}
