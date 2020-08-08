#include "textAdventureGameEngine.h"

int main(int argv, char **argc) {
    tag::Engine engine;
    engine.setStartRoom("a forest");
    tag::Room *clearing = engine.addRoom("a clearing");
    engine.linkRooms(engine.getStartRoom(), clearing, tag::NORTH);
    
    std::cout <<
    "Hello World. This is a text adventure game." << std::endl;
    engine.run();
}