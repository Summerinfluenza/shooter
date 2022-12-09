//
// Created by school on 2022-12-02.
//

#ifndef EDEN_PLAYER_H
#define EDEN_PLAYER_H
#include "Character.h"
#include "Enemy.h"
#include "Projectile.h"


class Player: public Character{

public:
    ////////////////////////////////////////////////////////////
    /// \brief Constructs a Player from coordinates
    ///
    /// \param coordinates  Object coordinates
    ////////////////////////////////////////////////////////////
    explicit Player(sf::Vector2f const& coordinates);

    ////////////////////////////////////////////////////////////
    /// \brief Takes two argument and updates the object.
    ///
    /// \sa testMe()
    /// \param delta_time Delta_time is the time interval between updates
    /// \param relevant_object Updates object against relevant objects for this class
    ////////////////////////////////////////////////////////////
    void update_object(sf::Time const& delta_time, std::vector<SpriteObject*> & relevant_objects) override;

    ////////////////////////////////////////////////////////////
    /// \brief Takes one argument and spawns a projectile object
    ///
    /// \sa testMe()
    /// \param mouse_pos Spawning projectile moving towards mouse position
    /// \return A projectile pointer
    ////////////////////////////////////////////////////////////
    void ranged_attack(sf::Vector2f const& mouse_pos, std::vector<SpriteObject*> & relevant_objects);

    void collision(std::vector<SpriteObject*> relevant_objects, sf::Vector2f & direction) override;

    ////////////////////////////////////////////////////////////
    /// Checks what key was pressed.
    ///
    /// Checks if and which key has been pressed regarding player movement and sets the boolean corresponding to
    /// that key(move) to the parameter pressed.
    ///
    /// @param key Stores information about what key has been pressed or released by the user.
    /// @param pressed Stores true if key was pressed and false if key was released.
    ////////////////////////////////////////////////////////////
    void handle_player_input(sf::Keyboard::Key key, bool pressed);
private:

    ////////////////////////////////////////////////////////////
    /// Member data
    ////////////////////////////////////////////////////////////
    bool key_w{};
    bool key_s{};
    bool key_a{};
    bool key_d{};

    ////////////////////////////////////////////////////////////
    /// \brief Takes one arguments and checks for collision with game_window.
    ///
    /// \sa testMe()
    /// \param move Move is a char representing positing in wasd.
    /// \return Boolean if object reaches the game_window limits.
    ////////////////////////////////////////////////////////////
    bool out_of_bounds(const char& move);

    ////////////////////////////////////////////////////////////
    /// \brief Takes four arguments and check for user commands and moves player sprite
    ///
    /// \sa testMe()
    /// \param key_w Checking if keybinding W is pressed
    /// \param key_s Checking if keybinding S is pressed
    /// \param key_a Checking if keybinding A is pressed
    /// \param key_d Checking if keybinding D is pressed
    ////////////////////////////////////////////////////////////
    sf::Vector2f move_object(sf::Time const& delta_time);

    void update_texture();
};



#endif //EDEN_PLAYER_H
