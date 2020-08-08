#ifndef TAG_H
#define TAG_H

#include <iostream>
#include <string>

namespace tag {
    enum Direction {
        NORTH=0, EAST=1, SOUTH=2, WEST=3
    };

    class Room {
    private:
        const char *description;
        int descriptionLength;
        Room *rooms[4];
        bool hasRoom[4] = {false};

    public:
        Room(const char *description="", int descriptionLength=0) {
            this->description = description;
            this->descriptionLength = descriptionLength;
        }

        void linkRoom(Room *room, Direction branchDirection) {
            this->rooms[branchDirection] = room;
            int rootDirection = branchDirection + (((branchDirection) > 1) ? -2 : 2);
            room->rooms[rootDirection] = this;
            this->hasRoom[branchDirection] = true;
            room->hasRoom[rootDirection] = true;
        }

        const char * getDescription() {
            return this->description;
        }

        void printDescriptionFull() { // prints the full description with descriptions of rooms to north, east, south, and west
            std::cout << "You are in " << this->getDescription() << std::endl;
            if(hasRoom[NORTH]) { std::cout << "To the north there is " << this->rooms[NORTH]->getDescription() << std::endl; }
            if(hasRoom[EAST])  { std::cout << "To the east there is "  <<  this->rooms[EAST]->getDescription() << std::endl; }
            if(hasRoom[SOUTH]) { std::cout << "To the south there is " << this->rooms[SOUTH]->getDescription() << std::endl; }
            if(hasRoom[WEST])  { std::cout << "To the west there is "  <<  this->rooms[WEST]->getDescription() << std::endl; }
        }
    };

    class Engine {
    private:
        Room startRoom;
        Room rooms[100];
        int vlength = 0;

    public:
        Engine() {}

        void setStartRoom(const char *startRoomDescription, int startRoomDescriptionLength=0) {
            startRoom = Room(startRoomDescription, startRoomDescriptionLength);
        }

        Room * getStartRoom() {
            return &startRoom;
        }

        Room * addRoom(const char *description, int descriptionLength=0) {
            rooms[vlength] = Room(description, descriptionLength);
            vlength ++;
            return &rooms[vlength-1];
        }

        void linkRooms(Room *rootRoom, Room *branchRoom, Direction branchDirection) {
            rootRoom->linkRoom(branchRoom, branchDirection);
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