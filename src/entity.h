#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "rand.h"
#include "eventManager.h" 

class Entity : public Listener
{
public:
    Entity() : x(0), y(0) {};
    virtual ~Entity() {};

    virtual void update(const float &dt, const float wWidth) = 0;
    virtual void setVelocity(float x, float y) = 0; 
    virtual void render(sf::RenderTarget& target, sf::RenderStates state) const=0;
    virtual void setPosition(float x, float y) = 0; 
    virtual void shake()= 0;
    virtual void move(float dx, float dy) = 0; 
    virtual sf::Vector2f getPosition() = 0;
    virtual void setSpecs(sf::Color, float, float, float) = 0; 

protected:
    float x = 0;
    float y = 0;
    float vX = 0;
    float vY = 0; 
    bool patrollingLeft;
    sf::Vector2f velocity{};
    int timer{};


};

