//
// Created by super on 5/10/23.
//

#ifndef COWBOY_VS_NINJA_A1_TRAINEDNINJA_HPP
#define COWBOY_VS_NINJA_A1_TRAINEDNINJA_HPP

#include "Ninja.hpp"

namespace ariel{
    class TrainedNinja: public Ninja{
    private:
        int speed;
    public:
        TrainedNinja(const string& name, const Point position);
    };
}

#endif //COWBOY_VS_NINJA_A1_TRAINEDNINJA_HPP
