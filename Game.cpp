//
// Created by school on 2022-12-02.
//

#include "Game.h"
///Default constructor.
// Väntar med denna, tills vi bestämt mera hur spelet ska laddas.
Game::Game()
        :game_window(sf::VideoMode(1024, 768), "Eden's Last Stand")
{
    player_object = new Player(sf::Vector2f(game_window.getSize().x / 2, game_window.getSize().y / 2));
    all_objects.push_back(player_object);

    create_map("level.txt");
    for (auto object : all_objects)
    {
        if (object->get_type() == "worm" || 
            object->get_type() == "lilith" ||
            object->get_type() == "player")
        {
            all_objects.push_back(new Healthbar(static_cast<Character&>(*object)));
        }
    }
}

Game::~Game()
{
    for (auto & object : all_objects)
    {
        delete object;
    }
}

void Game::create_map(std::string filename)
{
    std::ifstream map{filename};
    char object_char{};

    int tile_size{16};
    int row{};
    int col{};
    sf::Vector2f position{};

    while (map >> object_char)
    {

        position.x = static_cast<float>(col * tile_size);
        position.y = static_cast<float>(row * tile_size);

        switch( object_char )
        {
            case 'w':
                all_objects.push_back(new Worm(position, *player_object));
                break;
            case '#':
                all_objects.push_back(new Wall(position));
                break;
            case 'l':
                all_objects.push_back(new Lilith(position, *player_object));
                break;

        }
        ++col;
        if (col % 64 == 0)
        {
            col = 0;
            ++row;
        }
    }
}

////////////////////////////////////////////////////////////
/// Member methode that runs the game loop.
///
/// The fundamental functionality of run() is to execute the game loop in a way that ensures a seamless gaming experience.
/// It´s doing so by tracking the time of each iteration(tick) of the loop. Then on that data adjust the amount of times
/// it process events and update game objects before rendering the frame to the window.
///
/// @see process_events() update() render()
////////////////////////////////////////////////////////////
void Game::run()
{
    sf::Clock clock;
    sf::Time time_since_last_update{sf::Time::Zero};
    sf::Time time_per_frame = sf::seconds(1.f / 60.f);

    while (game_window.isOpen())
    {
        sf::Cursor cursor;
        if (cursor.loadFromSystem(sf::Cursor::Cross))
        {
            game_window.setMouseCursor(cursor);
        }

        process_events();
        time_since_last_update += clock.restart();
        while (time_since_last_update > time_per_frame)
        {
            time_since_last_update -= time_per_frame;
            process_events();
            update(time_per_frame);
        }
        render();

        if (player_object->get_current_health() == 0)
        {
            game_window.close();
        }
    }
}

////////////////////////////////////////////////////////////
/// Handles user input.
///
/// Methode that checks for incoming input messages by polling for events. If any, stores all information about that
/// individual input one by one in a Event object. Later either implement desired functionality corresponding to that
/// input or passing the data on to other methods to implement the code.
///
/// @see handle_player_input() Player::ranged_attack()
////////////////////////////////////////////////////////////
void Game::process_events()
{
    //
    sf::Event event{};
    sf::Vector2f mouse_pos = sf::Vector2f(sf::Mouse::getPosition(game_window));
    while( game_window.pollEvent(event))
    {
        switch( event.type )
        {
            case sf::Event::KeyPressed:
                player_object->handle_player_input(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                player_object->handle_player_input(event.key.code, false);
                break;

            case sf::Event::Closed:
                game_window.close();
                break;

            case sf::Event::MouseButtonPressed:
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    player_object->ranged_attack(mouse_pos, all_objects);
                }
        }
    }
}

////////////////////////////////////////////////////////////
/// Updates game logic.
///
/// In charge of updating all objects of the game. Doing so by iterate object vectors and
/// calling virtual update methode for all elements or destructing objects that is no longer desired.
///
/// @param delta_time The constant time for a frame in the game.
////////////////////////////////////////////////////////////
void Game::update(sf::Time delta_time)
{
    for (auto & it : all_objects)
    {
        it->update_object(delta_time, all_objects);
    }
    
    remove_terminate_objects();
}

////////////////////////////////////////////////////////////
/// Render the frames to the screen.
///
/// Retrieving all objects of the game and saves them in a vector. Then iterate the vector
/// and draw each object to the back screen. Before done displaying the screen on to the window.
///
/// @see get_all_objects()
////////////////////////////////////////////////////////////
void Game::render()
{
    game_window.clear(sf::Color::Black);

    for (auto & object : all_objects)
    {
        if (object->get_type() == "healthbar")
        {
            static_cast<Healthbar* >(object)->render(game_window);
        }
        else
        {
            game_window.draw(object->get_sprite());
        }
    }

    game_window.display();
}

void Game::remove_terminate_objects()
{
    help_remove_terminate_object(all_objects);
}

template <typename T>
void Game::help_remove_terminate_object(T & vec)
{
    auto it = vec.begin();
    while (it != vec.end())
    {
        if ((*it)->get_terminate())
        {
            delete *it;
            it = vec.erase(it);
        }
        else
        {
            ++it;
        }
    }
}