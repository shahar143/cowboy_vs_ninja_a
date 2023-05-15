//
// Created by super on 5/10/23.
//

#ifndef COWBOY_VS_NINJA_A1_TEAM_HPP
#define COWBOY_VS_NINJA_A1_TEAM_HPP

#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"


namespace ariel{
    class Team{
    private:
        Character** warriors;
        Character* leader;
        int size = 0; //number of warriors in the team
    public:
        Team(Character* leader);
        ~Team();

        void add(Character* character);

        void attack(Team* team);

        void choose_closest_to_leader();

        Character* find_closest_victim(Team* team);

        int stillAlive() const;

        void print() const;

    };
}

#endif //COWBOY_VS_NINJA_A1_TEAM_HPP
