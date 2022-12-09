//
// Created by school on 2022-12-02.
//

#ifndef EDEN_ENEMY_H
#define EDEN_ENEMY_H
#include "Character.h"
#include "Player.h"
class Player;
class Enemy: public Character{

public:
    ////////////////////////////////////////////////////////////
    /// \brief Constructs an enemy from coordinates and player reference
    ///
    /// \param coordinates  Object coordinates
    /// \param player       Reference to player object
    ////////////////////////////////////////////////////////////
    explicit Enemy(std::string const& name, 
                   sf::Vector2f const& coordinates, 
                   std::string const& texture_file, 
                   Player& player);


    ////////////////////////////////////////////////////////////
    /// \brief Takes one argument and updates the object.
    ///
    /// \sa testMe()
    /// \param delta_time Delta_time is the time interval between updates
    ////////////////////////////////////////////////////////////
/*    void update_object(sf::Time const& delta_time, std::vector<MovingObject*> relevant_objects) override;


    void collision(std::vector<MovingObject*> relevant_objects, sf::Vector2f & direction) override;*/

    //testar bara
    bool get_spawn() {return spawn;}



protected:
    Player& player;

    //Testar lite
    bool spawn{false};



};



#endif //EDEN_ENEMY_H
