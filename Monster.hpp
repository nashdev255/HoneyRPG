#pragma once
#include "./GeneralMethod.hpp"
#include "./Character.hpp"
#include "./Fighter.hpp"

class Fighter;

class Monster : public Character {
    private:

    public:
        Monster() {};
        Monster(std::string name, ElementalAttribute element, int maxhp, int atk, int def, int spd);
        virtual ~Monster() {};

        virtual void damagedMessage(int const damagePoint);
        virtual void deadMessage();

        void initAttackMethod();
        void randomAttack(Fighter& fighter);

};

inline Monster :: Monster(std::string const name, ElementalAttribute const element, int const maxhp, int const atk, int const def, int const spd) : Character(name, element, maxhp, atk, def, spd) {
    this->initAttackMethod();
}
