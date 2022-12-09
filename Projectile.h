//
// Created by school on 2022-12-02.
//

#ifndef EDEN_PROJECTILE_H
#define EDEN_PROJECTILE_H
#include "MovingObject.h"


class Projectile: public MovingObject {
public:
    ////////////////////////////////////////////////////////////
    /// \brief Constructs a Projectile from spawn position and mouse click position
    ///
    /// \param spawn_position  Object coordinates
    /// \param mouse_pos       Mouse click position to determine the direction
    ////////////////////////////////////////////////////////////
    explicit Projectile(sf::Vector2f const& spawn_position, sf::Vector2f mouse_pos);

    ////////////////////////////////////////////////////////////
    /// \brief Takes one argument and updates the object.
    ///
    /// \sa testMe()
    /// \param delta_time Delta_time is the time interval between updates
    ////////////////////////////////////////////////////////////
    void update_object(sf::Time const& delta_time, std::vector<SpriteObject*> & relevant_objects) override;

    void collision(std::vector<SpriteObject*> relevant_objects, sf::Vector2f & direction) override;

private:
    ////////////////////////////////////////////////////////////
    /// Member data
    ////////////////////////////////////////////////////////////
    sf::Vector2f direction{};
    sf::Vector2f original_position{};
};


#endif //EDEN_PROJECTILE_H
