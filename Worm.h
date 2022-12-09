//
// Created by oscarronndahl on 2022-12-08.
//

#ifndef EDEN_WORM_H
#define EDEN_WORM_H
#include "Enemy.h"

class Worm : public Enemy {

public:
    explicit Worm(sf::Vector2f const& coordinates, Player& player);

    ////////////////////////////////////////////////////////////
    /// \brief Takes one argument and updates the object.
    ///
    /// \sa testMe()
    /// \param delta_time Delta_time is the time interval between updates
    ////////////////////////////////////////////////////////////
    void update_object(sf::Time const &delta_time, std::vector<SpriteObject *> & relevant_objects) override;


    void collision(std::vector<SpriteObject *> relevant_objects, sf::Vector2f &direction) override;


};
#endif //EDEN_WORM_H
