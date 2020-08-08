#ifndef TAG_H
#define TAG_H

#include <iostream>
#include <string>
#include <map>

namespace tag {
    class Room {
    private:
        const char *description;
        int descriptionLength;
        std::map<std::string, Room *> rooms;

    public:
        Room(const char *description="") {
            this->description = description;
        }

        void linkRoom(Room *room, std::string branchDirection, std::string rootDirection) {
            this->rooms[branchDirection] = room;
            room->rooms[rootDirection] = this;
        }

        const char * getDescription() {
            return this->description;
        }

        void printDescriptionFull() { // prints the full description with descriptions of rooms to north, east, south, and west
            std::cout << "You are in " << this->getDescription() << std::endl;
            for(std::pair<std::string, Room *> iter : this->rooms) {
                std::cout << iter.first << " there is " << iter.second->getDescription() << std::endl;
            }
            // if(hasRoom[NORTH]) { std::cout << "To the north there is " << this->rooms[NORTH]->getDescription() << std::endl; }
            // if(hasRoom[EAST])  { std::cout << "To the east there is "  <<  this->rooms[EAST]->getDescription() << std::endl; }
            // if(hasRoom[SOUTH]) { std::cout << "To the south there is " << this->rooms[SOUTH]->getDescription() << std::endl; }
            // if(hasRoom[WEST])  { std::cout << "To the west there is "  <<  this->rooms[WEST]->getDescription() << std::endl; }
        }
    };

    class Engine {
    private:
        Room startRoom;
        Room rooms[100];
        int vlength = 0;

    public:
        Engine() {}

        void setStartRoom(const char *startRoomDescription) {
            startRoom = Room(startRoomDescription);
        }

        Room * getStartRoom() {
            return &startRoom;
        }

        Room * addRoom(const char *description) {
            rooms[vlength] = Room(description);
            vlength ++;
            return &rooms[vlength-1];
        }

        void linkRooms(Room *rootRoom, Room *branchRoom, std::string branchDirection, std::string rootDirection) {
            rootRoom->linkRoom(branchRoom, branchDirection, rootDirection);
        }

        std::string getInput() {
            std::string input;
            std::getline(std::cin, input);
            return input;
        }

        void run() {
            std::string input;
            while(true) {
                input = getInput();
            }
        }
    };
}

#endif