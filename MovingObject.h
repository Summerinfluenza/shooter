//
// Created by school on 2022-12-02.
//

#ifndef EDEN_MOVINGOBJECT_H
#define EDEN_MOVINGOBJECT_H
#include "SpriteObject.h"
////////////////////////////////////////////////////////////
/// Base clas for character, projectile and everything that moves.
////////////////////////////////////////////////////////////
class MovingObject : public SpriteObject{

public:
    ////////////////////////////////////////////////////////////
    /// \brief Constructs a MovingObject from name, coordinates and texture path
    ///
    /// \param name         Object name
    /// \param coordinates  Object coordinates
    /// \param texture_file Path to a texture file
    ////////////////////////////////////////////////////////////
    explicit MovingObject(std::string type, sf::Vector2f const& coordinates, std::string const& texture_file);


    virtual void collision(std::vector<SpriteObject*> relevant_objects, sf::Vector2f & direction) = 0;


protected:
    ////////////////////////////////////////////////////////////
    /// Member data
    ////////////////////////////////////////////////////////////

    float object_speed{25};

};


#endif //EDEN_MOVINGOBJECT_H
