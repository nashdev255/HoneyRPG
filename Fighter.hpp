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

        void selectAttackMethod(Monster& monster);
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
        int getExp();
        void setExp(int exp);
        int getReqExp();
        void setReqExp(int reqExp);
        int getSkillPoint();
        void setSkillPoint(int skillPoint);

};

