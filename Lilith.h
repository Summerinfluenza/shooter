//
// Created by oscarronndahl on 2022-12-08.
//

#ifndef EDEN_LILITH_H
#define EDEN_LILITH_H

#include "Enemy.h"
#include "Worm.h"
#include "Healthbar.h"

class Lilith : public Enemy 
{

public:
    explicit Lilith(sf::Vector2f const& coordinates, Player& player);

    ////////////////////////////////////////////////////////////
    /// \brief Takes one argument and updates the object.
    ///
    /// \sa testMe()
    /// \param delta_time Delta_time is the time interval between updates
    ////////////////////////////////////////////////////////////
    void update_object(sf::Time const &delta_time, std::vector<SpriteObject *> & relevant_objects) override;


    void collision(std::vector<SpriteObject *> relevant_objects, sf::Vector2f &direction) override;


    void spawn_worm(sf::Vector2f start_pos, Player& player, std::vector<SpriteObject*> & all_objects);

//    bool get_spawn() {return spawn;}

private:
    sf::Clock spawn_clock{};
//    bool spawn{false};


};


#endif //EDEN_LILITH_H
