#pragma once

#include <iostream>
#include "entity.h"
#include "scareable.h"
#include "enemy.h"
#include "fast.h"
#include "slow.h" 
#include "sprite.h"

using std::endl;
using std::cout;

class EnemyFactory
{
public:
    static Entity *makeEntity(float x, float y)
    {
        int r = rand(0,10);
	if(r % 2 != 0)
	{	
	        
        	Entity *entity = new Sprite{275 + r, y, "blue"};//FIXME probably should do color choice elsewhere but just here for now 
		return new Scareable{new Slow{entity}}; 
	}
	else
	{
        	Entity *entity = new Sprite{x + x, y, "yellow"};
        	return new Fast{entity};
	}
    }

    //make entities vector
    static std::vector<Entity *> makeEnemies(size_t amount = 10)
    {
        std::vector<Entity *> entities{};
        for(size_t i{}; i< amount; ++i)
        {
            entities.push_back(EnemyFactory::makeEntity(i*30, 0));
        }
        return entities;
    }
};
