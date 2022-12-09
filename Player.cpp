//
// Created by school on 2022-12-02.
//

#include "Player.h"
#include "SpriteObject.h"
class Enemy;

Player::Player(sf::Vector2f const& coordinates)
: Character("player", coordinates, "./textures/player/player_idle.png")
{
    object_speed = object_speed * 6;
    set_max_health(100);
    set_current_health(100);
}

void Player::update_object(sf::Time const& delta_time, std::vector<SpriteObject*> & relevant_objects)
{
    sf::Vector2f direction{};
    direction = move_object(delta_time);
    collision(relevant_objects, direction);
    object_sprite.move(object_speed * direction * delta_time.asSeconds());
    update_texture();
}

void Player::ranged_attack(sf::Vector2f const& mouse_pos, std::vector<SpriteObject*> & relevant_objects)
{   
    relevant_objects.push_back(new Projectile{object_sprite.getPosition() + sf::Vector2f(16.f, 16.f), mouse_pos});
}

sf::Vector2f Player::move_object(sf::Time const& delta_time)
{
    sf::Vector2f movement(0.f, 0.f);

    if (key_w && !out_of_bounds('w'))
        {
            movement.y -= 1.f;
        }

    if (key_s && !out_of_bounds('s')) 
        {
            movement.y += 1.f;
        }

    if (key_a && !out_of_bounds('a'))
        {
            movement.x -= 1.f;
        }

    if (key_d && !out_of_bounds('d'))
        {
            movement.x += 1.f;
        }
    return movement;
}

bool Player::out_of_bounds(const char& move)
{
    if (move == 'w' && object_sprite.getPosition().y < 5.f)
    {
        return true;
    }
    if (move == 's' && object_sprite.getPosition().y > window_size.y - 32)
    {
        return true;
    }
    if (move == 'a' && object_sprite.getPosition().x < 5.f)
    {
        return true;
    }
    if (move == 'd' && object_sprite.getPosition().x > window_size.x - 32)
    {
        return true;
    }
    return false;
}


void Player::collision(std::vector<SpriteObject*> relevant_objects, sf::Vector2f & direction)
{
    sf::FloatRect current_object_bound = object_sprite.getGlobalBounds();
    sf::FloatRect next_move = current_object_bound;
    next_move.top += direction.y;
    next_move.left += direction.x;

    auto it = relevant_objects.begin();
    while (it != relevant_objects.end())
    {
        if (*it != this)
        {
            sf::FloatRect object_bound = (*it)->get_sprite().getGlobalBounds();
            if ( next_move.intersects(object_bound) )
            {
                if (object_sprite.getPosition().x + 16.f > (*it)->get_sprite().getPosition().x)
                {
                    object_sprite.setPosition(object_sprite.getPosition().x + 1, object_sprite.getPosition().y);
                    direction.x = 0;
                }
                if (object_sprite.getPosition().x < (*it)->get_sprite().getPosition().x + 16.f)
                {
                    object_sprite.setPosition(object_sprite.getPosition().x - 1, object_sprite.getPosition().y);
                    direction.x = 0;
                }
                    
                if (object_sprite.getPosition().y + 16.f < (*it)->get_sprite().getPosition().y)
                {
                    object_sprite.setPosition(object_sprite.getPosition().x, object_sprite.getPosition().y - 1);
                    direction.y = 0;
                }
                    
                if (object_sprite.getPosition().y > (*it)->get_sprite().getPosition().y + 16.f)
                {
                    object_sprite.setPosition(object_sprite.getPosition().x, object_sprite.getPosition().y + 1);
                    direction.y = 0;
                }
                break;
            
            }
        }
        it++;
    }
}

void Player::handle_player_input(sf::Keyboard::Key key, bool pressed)
{
    if (key == sf::Keyboard::W)
        key_w = pressed;
    else if (key == sf::Keyboard::S)
        key_s = pressed;
    else if (key == sf::Keyboard::A)
        key_a = pressed;
    else if (key == sf::Keyboard::D)
        key_d = pressed;

}

void Player::update_texture()
{
    if (key_w)
    {
        object_texture.loadFromFile("./textures/player/player_up.png");
    }
    else if (key_d)
    {
        object_texture.loadFromFile("./textures/player/player_right.png");
    }
    else if (key_a)
    {
        object_texture.loadFromFile("./textures/player/player_left.png");
    }
    else
    {
        object_texture.loadFromFile("./textures/player/player_idle.png");
    }
}