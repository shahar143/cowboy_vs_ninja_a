//
// Created by super on 5/10/23.
//

#include "Team.hpp"
#include <iostream>
#include <limits>
#include <unistd.h>
using namespace ariel;
using namespace std;

#define MAX_WARRIORS 10

Team::Team(Character* leader){
    if(leader == nullptr){
        throw invalid_argument("leader cannot be null");
    }
    this->leader = leader;
    this->warriors = new Character*[MAX_WARRIORS];
    for(int i = 0; i < MAX_WARRIORS; i++){
        warriors[i] = nullptr;
    }
    warriors[0] = leader;
    size = 1;
}

Team::~Team(){
    for(int i = 0; i < MAX_WARRIORS; i++){
        if(warriors[i] != nullptr){
            delete warriors[i];
        }
    }
    delete[] warriors;
}

int Team::stillAlive() const{
    int counter = 0;
    for(int i = 0; i < MAX_WARRIORS; i++){
        if(warriors[i] != nullptr && warriors[i]->isAlive()){
            counter++;
        }
    }
    return counter;
}

void Team::add(Character* character){
    if(size == MAX_WARRIORS){
        throw invalid_argument("Team is full");
    }
    if(character->getInTeam()){
        throw invalid_argument("Character already in another team");
    }
    for (int i = 0; i < MAX_WARRIORS; i++){
        if(character == warriors[i]){
            throw invalid_argument("Character already in this team");
        }
    }
    for(int i = 0; i < MAX_WARRIORS; i++){
        if(warriors[i] != nullptr && character->getName() == warriors[i]->getName()){
            throw invalid_argument("you cannot have two characters with the same name in the same team");
        }
    }
    for(int i = 0; i < MAX_WARRIORS; i++){
        if(warriors[i] == nullptr){
            warriors[i] = character;
            break;
        }
    }
    size++;
}

void Team::choose_closest_to_leader(){
    int temp = 0;
    if(leader != nullptr && !leader->isAlive()){ //THE LEADER IS DEAD!!!!!!!!!!!!!
        Character* candidate = nullptr;
        double mindist = numeric_limits<double>::max();
        for(int i = 1; i < MAX_WARRIORS; i++){
            if(warriors[i] != nullptr && warriors[i]->isAlive()){
                if(leader->distance(warriors[i]) < mindist){
                    candidate = warriors[i];
                    temp = i;
                    mindist = leader->distance(warriors[i]);
                }
            }
        }
        warriors[0] = candidate;
        leader = candidate;
        warriors[temp] = nullptr;
    }
}

Character* Team::find_closest_victim(Team* team){
    double mindist = numeric_limits<double>::max();
    Character* victim = warriors[0];
    for(int i = 0; i < team->size; i++){
        if(team->warriors[i] != nullptr && team->warriors[i]->isAlive()){
            if(leader->distance(team->warriors[i]) < mindist){
                victim = team->warriors[i];
                mindist = leader->distance(team->warriors[i]);
            }
        }
    }
    return victim;
}


void Team::attack(Team* team) {
    if (team == this) {
        throw invalid_argument("Team can't attack itself");
    }
    while(team->stillAlive() && this->stillAlive()){
        if (!leader->isAlive()){
            choose_closest_to_leader();
        }
        Character* victim = find_closest_victim(team);
        if(victim->isAlive() == false){
            cout << "victim is dead" << endl;
            continue;
        }
        for(int i = 0; i < MAX_WARRIORS; i++){
            if(warriors[i] == nullptr){
                continue;
            }
            if(warriors[i]->isAlive()){
                Cowboy* cowboy = dynamic_cast<Cowboy*>(warriors[i]);
                if(cowboy != nullptr){
                    if(cowboy->hasBullets()){
                        cowboy->shoot(victim);
                        if(!victim->isAlive()){
                            break; //victim is dead
                        }
                    }
                    else{
                        cowboy->reload();
                    }
                }
                YoungNinja* youngNinja = dynamic_cast<YoungNinja*>(warriors[i]);
                if(youngNinja != nullptr){
                    if(warriors[i]->distance(victim) <= 1){
                        youngNinja->slash(victim);
                        if(!victim->isAlive()){
                            break; //victim is dead
                        }
                    }
                    else{
                        youngNinja->move(victim);
                    }
                }
                TrainedNinja* trainedNinja = dynamic_cast<TrainedNinja*>(warriors[i]);
                if(trainedNinja != nullptr){
                    if(warriors[i]->distance(victim) <= 1){
                        trainedNinja->slash(victim);
                        if(!victim->isAlive()){
                            break; //victim is dead
                        }
                    }
                    else{
                        trainedNinja->move(victim);
                    }
                }
                OldNinja* oldNinja = dynamic_cast<OldNinja*>(warriors[i]);
                if(oldNinja != nullptr){
                    if(warriors[i]->distance(victim) <= 1){
                        oldNinja->slash(victim);
                        if(!victim->isAlive()){
                            break; //victim is dead
                        }
                    }
                    else{
                        oldNinja->move(victim);
                    }
                }
            }
        }
    }
}

void Team::print() const{
    cout << "Team Leader: " << leader->getName() << endl;
    cout << "Team Members: " << endl;
    for(int i = 0; i < MAX_WARRIORS; i++){
        if(warriors[i] != nullptr && warriors[i]->isAlive()){
            cout << "name " << warriors[i]->getName() << " ";
            cout << "hp " << warriors[i]->getHp() << " ";
            Cowboy* cowboy = dynamic_cast<Cowboy*>(warriors[i]);
            if(cowboy != nullptr){
                cout << "bullets: " << cowboy->hasBullets() << endl;
            }
            else{
                cout << endl;
            }
        }
    }
}