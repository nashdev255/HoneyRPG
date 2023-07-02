#pragma once
#include "./Character.hpp"
#include "./Monster.hpp"

class Monster;

class Fighter : public Character {
    private:
        int exp, reqExp;
        int skillPoint;

    private:
        void buildAttackMethod();
        int calcReqExpAmount();

    public:
        Fighter() {};
        Fighter(std::string name, ElementalAttribute element, int maxhp, int atk, int def, int spd);
        virtual ~Fighter() {};

        virtual void damagedMessage(int const damagePoint);
        virtual void deadMessage();

        void attack(Monster& monster);
        void displayAttackMethods();

        // level-related
        void earnExpFromEnemy(int dropExpAmount);
        void updateReqExp();
        void updateExp();
        void updateLevel();
        void levelUp();
        void updateSkillPoint();
        void assignSkillPoint();

        // getter, setter
        int getExp() { return exp; }
        int getReqExp() { return reqExp; }
        int getSkillPoint() { return skillPoint; }

};
