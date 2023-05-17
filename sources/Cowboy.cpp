//
// Created by super on 5/10/23.
//
#include "Cowboy.hpp"
#include <iostream>
using namespace ariel;
using namespace std;

Cowboy::Cowboy(const string& name, const Point position): Character(position, 110, name), bullets(6){}

int Cowboy::getBullets() const{
    return bullets;
}

void Cowboy::shoot(Character* target){
    if(target == nullptr){
        throw invalid_argument("target cannot be null");
    }
    if(this == target){
        throw invalid_argument("you cannot shoot yourself");
    }
    if(this->isAlive()){
        if(bullets > 0){
            bullets--;
            target->hit(10);
        }
        else{
            reload();
        }
    }
}

bool Cowboy::hasBullets() const{
    return (bullets > 0);
}

void Cowboy::reload(){
    bullets = 6;
}