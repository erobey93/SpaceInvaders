#pragma once

#include <SFML/Graphics.hpp>
#include "rand.h"
#include "world.h"
#include "enemyFactory.h"
#include "ship.h"
#include "config.h"
#include "command.h"

using std:: cout;
using std:: endl;

class Game {

public:
    Game(unsigned int width = 800, unsigned int height = 600) : window{sf::VideoMode{width, height}, "Game"}
    {
        //handle space bar response
        spaceBarHandler = new ShakeCommand{&eventManager};
        inputHandler.setSpaceBarHandler(spaceBarHandler);

        //handle R & L key responses
        rightHandler = new MoveRightCommand{&eventManager};
        inputHandler.setRightHandler(rightHandler);

        leftHandler = new MoveLeftCommand{&eventManager};
        inputHandler.setLeftHandler(leftHandler);
    }
    ~Game()
    {
        delete spaceBarHandler;
        delete rightHandler;
        delete leftHandler;
    }
    void run()
    {
        World newWorld;

        //create ship
        Ship *aShip = new Ship(0, 300.f, WINDOW_HEIGHT - 150);
        newWorld.addEntity(aShip);

        //set ship as actor
        setActor(aShip);

        //create enemies
        newWorld.addEntities(EnemyFactory::makeEnemies());

        sf::Event event;

        newWorld.update(clock.restart().asSeconds(), WINDOW_WIDTH);
        while (window.isOpen()) {

            processEvents();
            t += clock.restart();
            while (t > dt) {
                t -= dt;
                processEvents();
                newWorld.update(clock.restart().asSeconds(), WINDOW_WIDTH);

            }
            render(window,newWorld);
        }
    }

    //set actor
    void setActor(Entity *setActor)
    {
        actor = setActor;
    }

private:

    void render(sf::RenderWindow & window, World aWorld) {

        // always clear!
        window.clear();

        // drawing happens here (off-screen)
        aWorld.render(window, sf::RenderStates::Default);

        // swap the display buffer (double-buffering)
        window.display();

    }
    void processEvents() {
        sf::Event event;//create event listener

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }

            Command *cmd = inputHandler.handleInput(event); //this will take the place of my event handler code in here
            if(cmd) {
                cmd->execute(actor); //this is how I specifically update just the entity that I want to update!
            }
        }
    }
    sf::RenderWindow window{};
    const int WINDOW_WIDTH = 800;
    const float WINDOW_HEIGHT = 600;
    Entity *actor{};
    Command *spaceBarHandler{};
    Command *rightHandler {};
    Command *leftHandler {};
    InputHandler inputHandler{};
    sf::Clock clock;
    sf::Time t{sf::Time::Zero}; // time
    sf::Time dt{sf::seconds(1.0f / 60.0f)}; // delta time (fixed to 60fps)
    EventManager eventManager{};

};

