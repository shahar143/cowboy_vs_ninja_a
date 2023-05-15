//
// Created by super on 5/10/23.
//

#include "Ninja.hpp"
#include <iostream>
using namespace ariel;
using namespace std;

Ninja::Ninja(const Point position, int hp, const string& name, int speed):Character(position, hp, name), speed(speed){}

int Ninja::getSpeed() const{
    return speed;
}

void Ninja::slash(Character* target){
    if(this->isAlive() && this->distance(target) <= 1){
        target->hit(40);
    }
}

void Ninja::move(Character* target){
    if(this->isAlive()){
        this->position = this->position.moveTowards(this->position, target->getLocation(), speed);
    }
}
