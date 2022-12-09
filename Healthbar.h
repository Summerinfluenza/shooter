//
// Created by school on 2022-12-06.
//

#ifndef EDEN_HEALTHBAR_H
#define EDEN_HEALTHBAR_H
#include "Character.h"
#include "SpriteObject.h"

class Healthbar : public SpriteObject
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Constructs a Healthbar from a Character pointer
    ///
    /// \param character_object  Object pointer
    ////////////////////////////////////////////////////////////
    explicit Healthbar(Character& character_object);

    void update_object(sf::Time const& delta_time, std::vector<SpriteObject*> & relevant_objects) override;

    void render(sf::RenderTarget &target);

private:
    ////////////////////////////////////////////////////////////
    /// Member data
    ////////////////////////////////////////////////////////////
    Character& character_object;
    sf::RectangleShape current_health;
    sf::RectangleShape max_health;
    float bar_length{32.f};

    void init_healthbar();
};

#endif //EDEN_HEALTHBAR_H
