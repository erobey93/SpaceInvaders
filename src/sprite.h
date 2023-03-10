#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "entity.h"
using std::string;
using std::cout;
using std::endl;

class Sprite : public Entity
{
public:
    Sprite(float uX, float uY, string color) {
        
	spriteColor(color); 
	sprite.setScale(sf::Vector2f(0.1f, 0.1f)); //just seeing what this does
        sprite.setTexture(texture);
        sprite.setPosition(x, 50);
    }

    void spriteColor(string color)
    {
	if(color == "green"){
        texture.loadFromFile( "./assets/alien.png",sf::IntRect());
        }

        if(color == "blue"){
        texture.loadFromFile( "./assets/blueAlien.png",sf::IntRect());
        }

        if(color == "yellow"){
        texture.loadFromFile("./assets/yellowAlien.jpg", sf::IntRect());
        }

    }
    void update(const float &dt, const float wWidth) override {};

    void render(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(sprite);
    }

    void setVelocity(float uVx, float uVy) override {

        velocity.x = uVx;
        velocity.y = uVy;
    }

    void setPosition(float x, float y) override {
        sprite.setPosition(x,y);
    }
    void shake() override {
        if(timer == 0)
        {
            timer = 50;
        }

    };
    void move(float dx, float dy)
    {
        sprite.move(dx, dy);
    }

    sf::Vector2f getPosition() override {

        return sprite.getPosition();

    }
    void setSpecs(sf::Color color, float radius, float x, float y) override
    {
        sprite.setPosition(x, y);
    }
protected:
    sf::Sprite sprite{};
    sf::Texture texture;
};
