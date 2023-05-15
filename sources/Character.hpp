//
// Created by super on 5/10/23.
//

#ifndef COWBOY_VS_NINJA_A1_CHARACTER_HPP
#define COWBOY_VS_NINJA_A1_CHARACTER_HPP
#include "Point.hpp"

namespace ariel{
    class Character{
    protected:
        Point position;
        int hp;
        string name;
        bool inTeam = false;
    public:
        Character(const Point& position, int hp, const string& name);
        virtual ~Character() = default;  //pure virtual destructor

        const Point& getLocation() const;
        int getHp() const;
        const string& getName() const;
        bool getInTeam() const;

        bool isAlive() const;
        double distance(const Character* other) const;

        string print() const;
        void hit(int damage);
    };
}

#endif //COWBOY_VS_NINJA_A1_CHARACTER_HPP
