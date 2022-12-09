//
// Created by school on 2022-12-02.
//

#ifndef EDEN_GAME_H
#define EDEN_GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Worm.h"
#include "Lilith.h"
#include "Projectile.h"
#include "Healthbar.h"
#include <set>
#include "Wall.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

class Game{
public:
    Game();
    ~Game();

    //Game loop
    void run();
private:
    //Methods

    //Creates a map
    void create_map(std::string filename);

    //Handles user input
    void process_events();

    //Updates games logic
    void update(sf::Time delta_time);

    //Renders the screen
    void render();

    //Check for any collision
//    static bool any_collision(std::vector<MovingObject*> const& relevant_objects);

    //Get all objects
    std::vector<SpriteObject*> get_all_objects() const;

    //Removing objects with terminate == true from object vectors 
    void remove_terminate_objects();

    template <typename T>
    void help_remove_terminate_object(T & vec);

    //Variables
    sf::RenderWindow game_window{};

    Player* player_object;
    std::vector<Healthbar*> healthbar_objects;
    std::vector<SpriteObject*> all_objects;

    //Testar tid
    sf::Clock game_clock{};


};



#endif //EDEN_GAME_H
