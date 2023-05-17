//
// Created by super on 5/10/23.
//

#ifndef COWBOY_VS_NINJA_A1_NINJA_HPP
#define COWBOY_VS_NINJA_A1_NINJA_HPP

#include "Character.hpp"

namespace ariel{
    class Ninja: public Character{
    private:
        int speed;
    public:
        Ninja(const Point position, int hp, const string& name, int speed);
        ~Ninja() = default;

        int getSpeed() const;

        void slash(Character* target);

        void move(Character* target);
    };
}

#endif //COWBOY_VS_NINJA_A1_NINJA_HPP
