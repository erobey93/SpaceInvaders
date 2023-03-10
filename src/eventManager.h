#pragma once

enum EventType {SHAKE,FAST,SLOW,SHOOT,TAUNT, RIGHT, LEFT}; //actions

class Listener {
public:
    virtual void onNotify(EventType eventType) {}
    virtual ~Listener() {}
};

class EventManager {
public:
    void addListener(Listener *listener) {
        listeners.push_back(listener);
    }

    void notify(EventType eventType) {
        for(auto listener : listeners)
        {
            listener->onNotify(eventType);
        }
    }
protected:
    std::vector<Listener *> listeners{};
};
