#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "entity.h"
using std::string;
using std::cout;
using std::endl;

class Enemy : public Entity
{
public:
    Enemy(float x, float y) : Enemy{15.0f} {

        enemy.setPosition(x, y);
        enemy.setOrigin(enemy.getRadius(), enemy.getRadius());
        enemy.setFillColor(sf::Color::Blue);
    }

    Enemy(float radius = 5.0f) : enemy{radius, 20} {

    }

    void update(const float &dt, const float wWidth) override {};

    void render(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(enemy);
    }

    void setVelocity(float uVx, float uVy) override {

        velocity.x = uVx;
        velocity.y = uVy;
    }

    void setPosition(float x, float y) override {
        enemy.setPosition(x,y);
    }

    void shake() override {
        if(timer == 0)
        {
            timer = 50;
        }

    };
    void move(float dx, float dy)
    {
        enemy.move(dx, dy);
    }

    sf::Vector2f getPosition() override {

        return enemy.getPosition();

    }
    void setSpecs(sf::Color color, float radius, float x, float y) override
    {
        enemy.setFillColor(color);
        enemy.setRadius(radius);
        enemy.setOrigin(enemy.getRadius(), enemy.getRadius());
        enemy.setPosition(x, y);
    }

protected:
    sf::CircleShape enemy{};
    sf::Texture texture; 

};
