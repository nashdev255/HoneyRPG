#include "ElementalAttribute.hpp"

void ElementalAttribute :: initElementNames() {
    // forを使った初期化
    // std::string elementNames[Geo+1] = { "None", "Pyro", "Hydro", "Anemo", "Electro", "Dendro", "Cyro", "Geo" };
    // for(int i=0;i<Geo+1;i++) {
    //     this->elementNames.insert(std::make_pair(static_cast<this->elementNames>(i), elementNames[i]));
    // }

    // forを使わずに初期化
    this->elementNames.insert(std::make_pair(None, GeneralMethod::colorString(Cream, "None")));
    this->elementNames.insert(std::make_pair(Pyro, GeneralMethod::colorString(Red, "Pyro")));
    this->elementNames.insert(std::make_pair(Hydro, GeneralMethod::colorString(Blue, "Hydro")));
    this->elementNames.insert(std::make_pair(Anemo, GeneralMethod::colorString(White, "Anemo")));
    this->elementNames.insert(std::make_pair(Electro, GeneralMethod::colorString(Purple, "Electro")));
    this->elementNames.insert(std::make_pair(Dendro, GeneralMethod::colorString(Green, "Dendro")));
    this->elementNames.insert(std::make_pair(Cyro, GeneralMethod::colorString(Sky, "Cyro")));
    this->elementNames.insert(std::make_pair(Geo, GeneralMethod::colorString(Brown, "Geo")));
}

ElementalReaction ElementalAttribute :: ElementalReact(ElementalAttributeList otherElement) {
    // std::cout << this->getElementAsString(this->element) << ':' << this->getElementAsString(otherElement) << std::endl;
    if(this->canNoneReactBy(otherElement)) return NoneReact;
    if(this->canSaturateBy(otherElement)) return Saturate;
    if(this->canEvaporateBy(otherElement)) return Evaporate;
    if(this->canMeltBy(otherElement)) return Melt;
    if(this->canElectrocuteBy(otherElement)) return Electrocute;
    if(this->canBloomBy(otherElement)) return Bloom;
    return NoneReact;
}

bool ElementalAttribute :: canNoneReactBy(ElementalAttributeList otherElement) {
    // None + Any = NoneReact
    return (this->element == None || otherElement == None);
}

bool ElementalAttribute :: canSaturateBy(ElementalAttributeList otherElement) {
    // None + None = not Saturate(=NoneReact)
    if(this->element == None) return false;
    if(otherElement == None) return false;
    // Same Elements = Saturate
    return (this->element == otherElement);
}

bool ElementalAttribute :: canEvaporateBy(ElementalAttributeList otherElement) {
    // Pyro + Hydro = Evaporate
    return ((this->element == Pyro) && (otherElement == Hydro)) || ((otherElement == Hydro) && (this->element == Pyro));
}

bool ElementalAttribute :: canMeltBy(ElementalAttributeList otherElement) {
    // Pyro + Cyro = Melt
    return ((this->element == Pyro) && (otherElement == Cyro)) || ((this->element == Cyro) && (otherElement == Pyro));
}

bool ElementalAttribute :: canElectrocuteBy(ElementalAttributeList otherElement) {
    // Electro + Hydro = Electroctue
    return ((this->element == Electro) && (otherElement == Hydro)) || ((this->element == Hydro) && (otherElement == Electro));
}

bool ElementalAttribute :: canBloomBy(ElementalAttributeList otherElement) {
    // Dendro + Hydro = Bloom
    return ((this->element == Dendro) && (otherElement == Hydro)) || ((this->element == Hydro) && (otherElement == Dendro));
}

std::string ElementalAttribute :: getElementAsString(ElementalAttributeList element) {
    const std::string elementName = this->elementNames.at(element);
    return elementName;
}
