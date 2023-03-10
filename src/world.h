#pragma once

#include <iostream>
#include "entity.h"
#include "enemyFactory.h"
#include "enemy.h"
#include "ship.h"
#include "string"
#include "eventManager.h"

using std::string;

class World
{
public:
    World() {}
    ~World() {
    };

    void addEntity(Entity *entity)
    {
        entities.push_back(entity);
	eventManager.addListener(entity); 
    }

    void update(const float &dt, const float wWidth)
    {
        for(auto *entity : entities)
        {
            entity -> update( dt, wWidth);

        }
    }
    void render(sf::RenderTarget& target, sf::RenderStates states) const
    {
        for(const auto& entity : entities)
        {
            entity->render(target,states);
        }

    }
    //add shapes to world vector
    void addEntities(const std::vector<Entity*> &entities)
    {
        for(auto entity : entities)
        {
            addEntity(entity);
        }
    }

private:
    std::vector<Entity*> entities;
    EventManager eventManager{}; 
};
