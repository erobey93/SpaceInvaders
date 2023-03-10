#pragma once

#include "entity.h"


class Slow : public Entity
{
public:
    Slow(Entity *e) : entity{e} {
        onNotify(SLOW);
    }

    void onNotify(EventType eventType) override {
        if(eventType == EventType::SLOW) {
            entity -> setVelocity(0.5, 0);
            //entity -> setSpecs(sf::Color::Yellow, 20.f, 275, 50);
        }
    }
    void render(sf::RenderTarget &target,sf::RenderStates state ) const override {

        entity->render(target, state);
    }
    void update(const float &dt, const float wWidth) override {
        if(patrollingLeft)
        {
            vX = 0.05;//move left
            x -= vX;
            position = entity->getPosition();

            if(position.x <= 0.f)
            {
                x = 0;
                patrollingLeft = false;
            }
        }
        else if (!patrollingLeft)
        {
            position = entity->getPosition();
            vX = 0.05f; //move right
            x += vX;

            if(position.x >= wWidth - 400)
            {
                //x = wWidth - 400;
                patrollingLeft = true;
            }
        }
        entity -> move(x,y);

    }

    void setPosition(float x, float y) override {
        entity -> setPosition(x,y);
    }

    void setVelocity(float dx, float dy) override {
        entity -> setVelocity(dx, dy);
    }

    void move(float dx, float dy) override {
        entity->move(dx, dy);
    }

    void shake () override {};

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
    sf::Vector2f position{};
};

