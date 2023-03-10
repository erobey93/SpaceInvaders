#pragma once

#include "eventManager.h"

using std::cout;

class Command
{
public:
    virtual ~Command() {};
    virtual void execute(Entity *entity) = 0;
};

class ShakeCommand : public Command
{
public:

    ShakeCommand(EventManager *eventManager) : eventManager{eventManager} {}

    virtual void execute(Entity *entity) override
    {
        eventManager->notify(EventType::SHAKE);
        entity->shake();
    }
private:
    EventManager *eventManager{};
};

//left movement
class MoveLeftCommand : public Command
{
public:
    MoveLeftCommand(EventManager *eventManager) : eventManager{eventManager} {}
    virtual void execute(Entity *entity) override
    {
        eventManager->notify(EventType::LEFT);
        entity->setVelocity(-5.0,0);//if left arrow key set negative velocity
    }
private:
    EventManager *eventManager{};
};

//right movement
class MoveRightCommand : public Command
{
public:
    MoveRightCommand(EventManager *eventManager) : eventManager{eventManager} {}

    virtual void execute(Entity *entity) override
    {
        eventManager->notify(EventType::RIGHT);
        entity->setVelocity(8.0,0);//if right arrow key set positive velocity
    }
private:
    EventManager *eventManager{};

};


//take in input and
class InputHandler
{
public:
    Command *handleInput(const sf::Event &event)
    {
        if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::Space) {
                return spaceBarCommand;
            }
            else if (event.key.code == sf::Keyboard::Right)
            {
                return moveRightCommand;
            }
            else if( event.key.code == sf::Keyboard::Left)
            {
                return moveLeftCommand;
            }
        }
        return nullptr;
    }

    void setSpaceBarHandler(Command *command)
    {
        spaceBarCommand = command;
    }

    void setRightHandler(Command *command)
    {
        moveRightCommand = command;

    }
    void setLeftHandler(Command *command)
    {
        moveLeftCommand = command;

    }


private:
    Command *spaceBarCommand{};
    Command *moveRightCommand{};
    Command *moveLeftCommand{};
};
