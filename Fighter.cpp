#include "Fighter.hpp"

Fighter :: Fighter(std::string const name, ElementalAttribute const elementalAttribute, int const maxhp, int const atk, int const def, int const spd) : Character(name, elementalAttribute, maxhp, atk, def, spd), exp(0), skillPoint(0) {
    updateReqExp();
    buildAttackMethod();
}

/**
 * 選択可能な攻撃の情報を設定する
*/
void Fighter :: buildAttackMethod() {
    const int power = atk;
    const ElementalAttributeList fighterElement = elementalAttribute.getElement();
    attackMethod[0].setParams("punchAttack", ElementalAttributeList::None, power);
    attackMethod[1].setParams("kickAttack", ElementalAttributeList::None, power*1.5);
    attackMethod[2].setParams("elementalAttack", fighterElement, power*0.8);
    attackMethod[3].setParams("elementalStorm", fighterElement, power*2);
}

/**
 * プレイヤーに選択させて攻撃する
 * 
 * @param monster 攻撃対象
*/
void Fighter :: attack(Monster& monster) {
    std::cout << "Select how to " << name << " attack." << std::endl;
    displayAttackMethods();
    
    int method = attackMethod.size()+1;

    std::cout << "> ";
    while(attackMethod.size() < method) {
        std::cin >> method;
        if(attackMethod.size() < method) {
            std::cout << "Select How to " << name << " attack." << std::endl;
            std::cout << "> ";
        }
    }
    method--;

    selectedAttackMethod = attackMethod[method];

    std::cout << name << "'s " << selectedAttackMethod.getName() << "!!!" << std::endl;
    selectedAttackMethod.action(*this, monster);
}

/**
 * 選択可能な攻撃を表示する
*/
void Fighter :: displayAttackMethods() {
    std::cout << "<methods>" << std::endl;
    for(int i=0;i<attackMethod.size();i++) {
        std::cout << i+1 << " : " << attackMethod[i].getName() << std::endl;
    }
}

/**
 * ダメージを食らった時のメッセージを表示する
*/
void Fighter :: damagedMessage(int const damagePoint) {
    std::cout << name << " took " << damagePoint << " points of damage." << std::endl;
}

/**
 * 死んだときのメッセージを表示する
*/
void Fighter :: deadMessage() {
    std::cout << name << " has ran out of energy..." << std::endl;
}

/**
 * レベルが上がるかどうか監視する
*/
void Fighter :: updateLevel() {
    while(reqExp <= exp) {
        if(level == maxLevel) break;
        updateExp();
        levelUp();
        updateReqExp();
    }
}

/**
 * 必要な経験値量を更新する
*/
void Fighter :: updateReqExp() {
    reqExp = reqExp + calcReqExpIncreaseAmount();
}

/**
 * レベルに応じて必要な経験値量を計算する
*/
int Fighter :: calcReqExpIncreaseAmount() {
    const int totalReqExpAmount = level*100;
    return totalReqExpAmount;
}

/**
 * 敵から経験値を獲得する
 * 
 * @param dropExpAmount 敵の経験値量
*/
void Fighter :: earnExpFromEnemy(int dropExpAmount) {
    exp = exp + dropExpAmount;
}

/**
 * レベルアップ時に持っている経験値を消費する
*/
void Fighter :: updateExp() {
    exp = exp - reqExp;
}

/**
 * レベルを加算し、スキルポイントを更新する
*/
void Fighter :: levelUp() {
    level++;
    std::cout << "LEVELUP!!! : " << level-1 << " > " << level << std::endl;
    earnSkillPoint();
}

/**
 * スキルポイントを獲得する
*/
void Fighter :: earnSkillPoint() {
    const int skillPointIncreaseAmount = calcSkillPointIncreaseAmount();
    const int totalSkillPoint = skillPoint + skillPointIncreaseAmount;
    std::cout << "SKILL POINTS INCREASED : " << skillPoint << " > " << totalSkillPoint << std::endl;
    skillPoint = totalSkillPoint;
}

/**
 * レベルに応じてスキルポイントを計算する
*/
int Fighter :: calcSkillPointIncreaseAmount() {
    int skillPointIncreaseAmount = 5; // 今は5に固定
    return skillPointIncreaseAmount;
}

/**
 * プレーヤーにスキルポイントを割り当てさせる
*/
void Fighter :: assignSkillPoint() {
    std::cout << "assign skill points" << std::endl;
    
}
