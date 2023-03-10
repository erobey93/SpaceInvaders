#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.h"

using std::endl;
using std::cout;

class Ship : public Entity
{
public:

    Ship(int delay, float uX, float uY) : frame(0), delay(delay) {
        x = uX;
        y=uY;
        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(50,50));
        shape.setFillColor(sf::Color::Red);

    }
    Ship(float width = 50.0f) : shape{sf::Vector2f{width, width}}
    {
        shape.setFillColor(sf::Color::Red);
    }
    //dtor
    ~Ship() override {};

    //update movement
    void update(const float &dt, const float wWidth)
    {
        auto dx = velocity.x;
        auto dy = velocity.y;

        if(timer > 0)
        {
            constexpr int speed{50};
            dx += rand(-speed, speed);
            --timer;
        }
        if(shape.getPosition().x >= wWidth)
        {
            shape.setPosition(100, y);
        }
        if(shape.getPosition().x <= 0)
        {
            shape.setPosition(wWidth, y);
        }

        shape.move(dx,dy);
    }

    //draw to screen
    void render(sf::RenderTarget &target, sf::RenderStates states) const override
    {
        target.draw(shape);
    }

    //set specs swap out in ctor
    void setPosition(float uX, float uY)
    {
        x = uX ;
        y = uY;
    }

    //TODO shoot
    void shoot()
    {
        cout << "SHOOT FIXME" << endl;
    }

    //Shake
    void shake() {
        if(timer ==0) {
            timer = 50;
        }
    }
    void setVelocity (float x, float y)
    {
        velocity.x += x;
        velocity.y -= y;
    }
    void move(float dx, float dy) override {};

    sf::Vector2f getPosition() override {
        return shape.getPosition();
    }
    
    void setSpecs(sf::Color, float, float, float){}

private:
    int frame;
    int delay;
    sf::RectangleShape shape;
    sf::Vector2f velocity{};
    int timer{};

};
