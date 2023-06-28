#pragma once
#include <iostream>
#include <string>
#include <map>
#include "./GeneralMethod.hpp"

enum ElementalAttributeList {
    None,
    Pyro,
    Hydro,
    Anemo,
    Electro,
    Dendro,
    Cyro,
    Geo
};

enum ElementalReaction {
    NoneReact,
    Saturate,
    Evaporate,
    Melt,
    Electrocute,
    Bloom,
};

class ElementalAttribute {
    private:
        ElementalAttributeList element;
        std::map<ElementalAttributeList, std::string> elementNames;

    private:
        void initElementNames();

        // ElementalReact
        bool canNoneReactBy(ElementalAttributeList otherElement);
        bool canSaturateBy(ElementalAttributeList otherElement);
        bool canEvaporateBy(ElementalAttributeList otherElement);
        bool canMeltBy(ElementalAttributeList otherElement);
        bool canElectrocuteBy(ElementalAttributeList otherElement);
        bool canBloomBy(ElementalAttributeList otherElement);

    public:
        // General
        ElementalAttribute() {};
        ElementalAttribute(ElementalAttributeList element);
        virtual ~ElementalAttribute() {};

        ElementalReaction ElementalReact(ElementalAttributeList otherElement);
        std::string getElementAsString(ElementalAttributeList element);

        // getter, setter
        ElementalAttributeList getElement();
        void setElement(ElementalAttributeList element);

};

inline ElementalAttribute :: ElementalAttribute(ElementalAttributeList element) {
    this->element = element;
    this->initElementNames();
}

inline ElementalAttributeList ElementalAttribute :: getElement() {
    return this->element;
}

inline void ElementalAttribute :: setElement(ElementalAttributeList element) {
    this->element = element;
}
