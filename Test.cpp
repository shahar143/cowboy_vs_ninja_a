//
// Created by super on 5/15/23.
//

#include "sources/Team.hpp"
#include "doctest.h"
#include <unistd.h>


using namespace ariel;

TEST_CASE("one Character cannot be in 2 different teams") {
    Character* c1 = new Cowboy("c1", Point(1,0));
    Character* c2 = new Cowboy("c2", Point(2,0));
    Team t1(c1);
    Team t2(c2);
    CHECK_THROWS(t1.add(c1));
}

TEST_CASE("Team cannot have more than 10 members") {
    Character* c1 = new Cowboy("c1", Point(1,0));
    Character* c2 = new Cowboy("c2", Point(2,0));
    Character* c3 = new Cowboy("c3", Point(3,0));
    Character* c4 = new Cowboy("c4", Point(5,0));
    Character* c5 = new Cowboy("c5", Point(6,0));
    Character* c6 = new Cowboy("c6", Point(7,0));
    Character* c7 = new Cowboy("c7", Point(8,0));
    Character* c8 = new Cowboy("c8", Point(9,0));
    Character* c9 = new Cowboy("c9", Point(10,0));
    Character* c10 = new Cowboy("c10", Point(11,0));
    Character* c11 = new Cowboy("c11", Point(12,0));
    Team t1(c1);
    t1.add(c2);
    t1.add(c3);
    t1.add(c4);
    t1.add(c5);
    t1.add(c6);
    t1.add(c7);
    t1.add(c8);
    t1.add(c9);
    t1.add(c10);
    CHECK_THROWS(t1.add(c11));
}

TEST_CASE("Cowboy cannot kill himself"){
    Cowboy* c1 = new Cowboy("c1", Point(1,0));
    CHECK_THROWS(c1->shoot(c1));
}

TEST_CASE("YoungNinja cannot kill himself"){
    YoungNinja* c1 = new YoungNinja("c1", Point(1,0));
    CHECK_THROWS(c1->slash(c1));
}

TEST_CASE("TrainedNinja cannot kill himself"){
    TrainedNinja* c1 = new TrainedNinja("c1", Point(1,0));
    CHECK_THROWS(c1->slash(c1));
}

TEST_CASE("OldNinja cannot kill himself"){
    OldNinja* c1 = new OldNinja("c1", Point(1,0));
    CHECK_THROWS(c1->slash(c1));
}

TEST_CASE("Cowboy can shoot a Ninja and Ninja can slash a Cowboy"){
    Cowboy* c1 = new Cowboy("c1", Point(1,0));
    Ninja* c2 = new YoungNinja("c2", Point(2,0));

    Cowboy* c3 = new Cowboy("c3", Point(3,0));
    Ninja* c4 = new TrainedNinja("c4", Point(4,0));

    Cowboy* c5 = new Cowboy("c5", Point(5,0));
    Ninja* c6 = new OldNinja("c6", Point(6,0));

    c1->shoot(c2);
    CHECK(c2->getHp() == 100);
    c2->slash(c1);
    CHECK(c1->getHp() == 60);

    c3->shoot(c4);
    CHECK(c4->getHp() == 100);
    c4->slash(c3);
    CHECK(c3->getHp() == 80);

    c5->shoot(c6);
    CHECK(c6->getHp() == 100);
    c6->slash(c5);
    CHECK(c5->getHp() == 110);
}

TEST_CASE("when a Character kills another Character, the other Character is actually dead"){
    Cowboy* c1 = new Cowboy("c1", Point(1,0));
    Ninja* c2 = new YoungNinja("c2", Point(2,0));
    Cowboy* c3 = new Cowboy("c3", Point(3,0));
    Ninja* c4 = new TrainedNinja("c4", Point(4,0));
    Ninja* c6 = new OldNinja("c6", Point(6,0));

    while(c2->isAlive()) c1->shoot(c2);
    CHECK(c2->getHp() <= 0);
    CHECK(c2->isAlive() == false);

    while(c3->isAlive()) c1->shoot(c3);
    CHECK(c3->getHp() <= 0);
    CHECK(c3->isAlive() == false);

    while(c4->isAlive()) c1->shoot(c4);
    CHECK(c4->getHp() <= 0);
    CHECK(c4->isAlive() == false);

    while(c6->isAlive()) c1->shoot(c6);
    CHECK(c6->getHp() <= 0);
    CHECK(c6->isAlive() == false);
}

TEST_CASE("Cowboy/Ninja cannot shoot/slash himself"){
    Cowboy* c1 = new Cowboy("c1", Point(1,0));
    Ninja* c2 = new YoungNinja("c2", Point(2,0));
    Ninja* c4 = new TrainedNinja("c4", Point(4,0));
    Ninja* c6 = new OldNinja("c6", Point(6,0));

    CHECK_THROWS(c1->shoot(c1));
    CHECK_THROWS(c2->slash(c2));
    CHECK_THROWS(c4->slash(c4));
    CHECK_THROWS(c6->slash(c6));
}

TEST_CASE("Cowboy/Ninja cannot shoot/slash a nullptr"){
    Cowboy* c1 = new Cowboy("c1", Point(1,0));
    Ninja* c2 = new YoungNinja("c2", Point(2,0));
    Ninja* c4 = new TrainedNinja("c4", Point(4,0));
    Ninja* c6 = new OldNinja("c6", Point(6,0));

    CHECK_THROWS(c1->shoot(nullptr));
    CHECK_THROWS(c2->slash(nullptr));
    CHECK_THROWS(c4->slash(nullptr));
    CHECK_THROWS(c6->slash(nullptr));
}

TEST_CASE("a Team cannot attack itself"){
    Cowboy* c1 = new Cowboy("c1", Point(1,0));
    Cowboy* c2 = new Cowboy("c2", Point(2,0));
    YoungNinja* c3 = new YoungNinja("c3", Point(3,0));
    Team t1(c1);
    t1.add(c2);
    t1.add(c3);
    CHECK_THROWS(t1.attack(&t1));
}

