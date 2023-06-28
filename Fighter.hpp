#pragma once
#include "./Character.hpp"
#include "./Monster.hpp"

class Monster;

class Fighter : public Character {
    private:

    public:
        Fighter() {};
        Fighter(std::string name, ElementalAttribute element, int maxhp, int atk, int def, int spd);
        virtual ~Fighter() {};

        virtual void damagedMessage(int const damagePoint);
        virtual void deadMessage();

        void initAttackMethod();
        void selectAttack(Monster& monster);

};

inline Fighter :: Fighter(std::string const name, ElementalAttribute const elementalAttribute, int const maxhp, int const atk, int const def, int const spd) : Character(name, elementalAttribute, maxhp, atk, def, spd) {
    this->initAttackMethod();
}
