#pragma once

#include "entity.h"

class Scareable : public Entity
{
public:
    Scareable(Entity *e) : entity{e} {}

    void onNotify(EventType eventType) override {
        if(eventType == EventType::SHAKE) {
            //entity->setVelocity(0,-20);
	    cout << "I'M SCARED!!!!" << endl; 
        }
    }
    void render(sf::RenderTarget &target, sf::RenderStates states) const override {

        entity->render(target, states);
    }
    void update(const float &dt, const float wWidth) override {
        entity->update(dt, wWidth);
    }

    void setPosition(float x, float y) override {
        entity -> setPosition(x,y);
    }

    void setVelocity(float dx, float dy) override {
        entity -> setVelocity(dx, dy);
    }
    void shake() override {};
    void move(float dx, float dy) override {};


    sf::Vector2f getPosition() override
    {
        return entity -> getPosition();
    }
    void setSpecs(sf::Color color, float radius, float x, float y) override
    {
        entity -> setSpecs(color, radius, x, y);
    }


protected:

    Entity *entity{};

};
