//
// Created by school on 2022-12-02.
//

#ifndef EDEN_CHARACTER_H
#define EDEN_CHARACTER_H
#include "MovingObject.h"


class Character: public MovingObject {
public:

    ////////////////////////////////////////////////////////////
    /// \brief Constructs a Character from name, coordinates and texture path
    ///
    /// \param name         Object name
    /// \param coordinates  Object coordinates
    /// \param texture_file Path to a texture file
    ////////////////////////////////////////////////////////////
     explicit Character(std::string const& type,
                        sf::Vector2f const& coordinates,
                        std::string const& texture_file);

     virtual void attack() const;

     virtual void take_damage(float const& num);

     virtual void set_current_health(float const& num) { current_health = num; }

     virtual void set_max_health(float const& num) { max_health = num; }

     virtual void set_armor(float const& num) { armor = num; }

     virtual float get_current_health() { return current_health; }

     virtual float get_max_health() { return max_health; }

protected:
    ////////////////////////////////////////////////////////////
    /// Member data
    ////////////////////////////////////////////////////////////
    float max_health{0};
    float current_health{0};
    float armor{0};

};


#endif //EDEN_CHARACTER_H
