//
// Created by super on 5/10/23.
//

#include "Character.hpp"
#include <iostream>
using namespace ariel;
using namespace std;

Character::Character(const Point& position, int hp, const string& name):position(position), hp(hp), name(name){}

const Point& Character::getLocation() const{
    return position;
}

int Character::getHp() const{
    return hp;
}
const string& Character::getName() const{
    return name;
}

bool Character::isAlive() const{
    if(hp > 0){
        return true;
    }
    return false;
}

bool Character::getInTeam() const{
    return inTeam;
}

double Character::distance(const Character* other) const{
    return position.distance(other->getLocation());
}

string Character::print() const{
    return name + " " + position.print() + " " + to_string(hp);
}

void Character::hit(int damage){
    hp -= damage;
}
