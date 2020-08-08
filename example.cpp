#include "textAdventureGameEngine.h"

int main(int argv, char **argc) {
    tag::Engine engine;
    engine.setStartRoom("a forest");
    tag::Room *clearing = engine.addRoom("a clearing");
    engine.linkRooms(engine.getStartRoom(), clearing, "north");
    
    std::cout << "Hello World. This is a text adventure game." << std::endl;
    std::string input;
    bool invalidInput = true;
    // char **subinput;
    // int sublength;
    // std::string delimiter = " ";
    // size_t pos = 0;
    // std::string token;
    // while ((pos = input.find(delimiter)) != std::string::npos) {
    //     token = input.substr(0, pos);
    //     std::cout << token << std::endl;
    //     input.erase(0, pos + delimiter.length());
    // }
    
    while(true) {
        invalidInput = true;
        engine.getPlayerRoom()->printDescriptionFull();
        input = engine.getInput();

        if(input=="exit") {
            std::exit(0);
        } else if(input.substr(0, 2)=="go") {
            for(std::pair<std::string, tag::Room *> iter : engine.getPlayerRoom()->getRooms()) {
                if(input.length() >= 3+iter.first.length() && input.substr(3, 3+iter.first.length()) == iter.first) {
                    engine.setPlayerRoom(iter.second);
                    invalidInput = false;
                }
            }
        }
        if(invalidInput) {
            std::cout << "I'm sorry, I don't understand that\n";
        }
    }

    return 0;
}