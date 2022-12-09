#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <cmath>

class SpriteObject
{
    public:
    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ////////////////////////////////////////////////////////////
    SpriteObject();

    ////////////////////////////////////////////////////////////
    /// \brief Constructs a MovingObject from name, coordinates and texture path
    ///
    /// \param name         Object name
    /// \param coordinates  Object coordinates
    /// \param texture_file Path to a texture file
    ////////////////////////////////////////////////////////////
    explicit SpriteObject(std::string type, sf::Vector2f const& coordinates, std::string const& texture_file);

    ////////////////////////////////////////////////////////////
    /// \brief A virtual default destructor.
    ///
    /// Deletes object when called.
    ////////////////////////////////////////////////////////////
    virtual ~SpriteObject() = default;


    ////////////////////////////////////////////////////////////
    /// \brief A normal member taking no arguments. Returns the object sprite.
    /// \return sf::Sprite
    ////////////////////////////////////////////////////////////
    sf::Sprite get_sprite() { return object_sprite; }

    ////////////////////////////////////////////////////////////
    /// \brief A normal member taking no arguments. Returns the object texture.
    /// \return sf::Texture
    ////////////////////////////////////////////////////////////
    sf::Texture get_texture() { return object_texture; }

    ////////////////////////////////////////////////////////////
    /// \brief A normal member taking no arguments. Returns the object type.
    /// \return string
    ////////////////////////////////////////////////////////////
    std::string get_type() { return object_type; }

    virtual bool get_terminate() {return terminate;}

    ////////////////////////////////////////////////////////////
    /// \brief A virtual member. Takes two argument and updates the object.
    ///
    /// \sa testMe()
    /// \param delta_time Delta_time is the time interval between updates
    /// \param relevant_object Updates object against relevant objects for this class
    ////////////////////////////////////////////////////////////
    virtual void update_object(sf::Time const& delta_time, std::vector<SpriteObject*> & relevant_objects) = 0;


    protected:
    std::string object_type{};
    sf::Sprite object_sprite{};
    sf::Texture object_texture{};
    bool terminate{false};
    sf::Vector2f window_size{1024.f, 768.f};


};




#endif