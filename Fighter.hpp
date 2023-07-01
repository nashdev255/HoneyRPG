#pragma once
#include "./Character.hpp"
#include "./Monster.hpp"

class Monster;

class Fighter : public Character {
    private:
        int exp, reqExp;
        int skillPoint;

    private:
        int calcReqExpAmount();

    public:
        Fighter() {};
        Fighter(std::string name, ElementalAttribute element, int maxhp, int atk, int def, int spd);
        virtual ~Fighter() {};

        virtual void damagedMessage(int const damagePoint);
        virtual void deadMessage();

        void initAttackMethod();
        void selectAttack(Monster& monster);

        // level-related
        void earnExpFromEnemy(int dropExpAmount);
        void updateReqExp();
        void updateExp();
        void updateLevel();
        void levelUp();
        void updateSkillPoint();

        // getter, setter
        int getExp();
        void setExp(int exp);
        int getReqExp();
        void setReqExp(int reqExp);
        int getSkillPoint();
        void setSkillPoint(int skillPoint);

};

inline Fighter :: Fighter(std::string const name, ElementalAttribute const elementalAttribute, int const maxhp, int const atk, int const def, int const spd) : Character(name, elementalAttribute, maxhp, atk, def, spd) {
    this->exp = 0;
    this->updateReqExp();
    this->initAttackMethod();
}

inline int Fighter :: getSkillPoint() {
    return this->skillPoint;
}

inline void Fighter :: setSkillPoint(int skillPoint) {
    this->skillPoint = skillPoint;
}
