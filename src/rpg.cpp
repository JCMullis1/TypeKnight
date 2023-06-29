#include <iostream>
#include <fstream>
#include "rpg.h"

using namespace std;

Armor::Armor(int price, int armr_value, int ac) {
        price_value = price;
        armr_val = armr_value;
        armr_class = ac;
}

Weapon::Weapon(int price, int dmg_min, int dmg_max, int armr_class_mod, string modifier) {
        price_value = price;
        damage_min = dmg_min;
        damage_max = dmg_max;
        ac_modifier = armr_class_mod;
        mod = modifier;
}

// from d_structs
vector<Entity*> objArr;

// the parameters are all of the equipment slots
Entity::Entity(int health, int mna, int spd, string arg_name, bool arg_is_player, Weapon slot_lhnd, Weapon slot_rhnd, Armor slot_hd, Armor slot_cht, Armor slot_lgs, Armor slot_ft, Armor slot_gnt, Armor slot_shl, Armor slot_pen, Armor slot_rng1, Armor slot_rng2) {
        int temp_ac;
        int temp_def;
        curr_health = health;
        max_health = health;
        mana = mna;
        speed = spd;
        name = arg_name;
        is_player = is_player;
        wpn_left = slot_lhnd;
        wpn_right = slot_rhnd;
        armr_head = slot_hd;
        armr_chest = slot_cht;
        armr_legs = slot_lgs;
        armr_feet = slot_ft;
        armr_hands = slot_gnt;
        armr_shoulders = slot_shl;
        armr_pendant = slot_pen;
        armr_ring1 = slot_rng1;
        armr_ring2 = slot_rng2;


        int temp_wpn_ac = (wpn_left.ac_modifier + wpn_right.ac_modifier)/2;
        if (temp_wpn_ac) {
                temp_ac = (temp_wpn_ac + armr_head.armr_class + armr_chest.armr_class + armr_legs.armr_class + armr_feet.armr_class + armr_hands.armr_class + armr_shoulders.armr_class)/7;
        } else {
                temp_ac = (armr_head.armr_class + armr_chest.armr_class + armr_legs.armr_class + armr_feet.armr_class + armr_hands.armr_class + armr_shoulders.armr_class)/6;
        }
        ac = temp_ac;
        objArr.push_back(this);
}

// D_STRUCTS CPP FILE
/*f
TestObj::TestObj(int dataValue, string instName) {
        data = dataValue;
        name = instName;

        objArr.push_back(this);
}
*/

// quick sort algo
int arrPartition(vector<Entity*> &vec, int startInd, int endInd) {
        int pivot = vec[endInd]->speed;
        int leftIndex = startInd;

        for (int i = startInd; i < endInd; i++) {
                // sorts greatest to smallest, to reverse just change # if (vec[i]->speed < pivot) instead of greater than
                if (vec[i]->speed > pivot) {
                        // swapping
                        Entity *temp = vec[i];
                        vec[i] = vec[leftIndex];
                        vec[leftIndex] = temp;
                        leftIndex++;
                }
        }

        Entity *temp = vec[endInd];
        vec[endInd] = vec[leftIndex];
        vec[leftIndex] = temp;

        cout << endl;
        return leftIndex;
}

void quickSort(vector<Entity*> &vec, int startInd, int endInd) {
        if (startInd < endInd) {
                cout << endl;
                int partInd = arrPartition(vec, startInd, endInd);
                quickSort(vec, startInd, (partInd-1)); // recursive calls
                quickSort(vec, (partInd+1), endInd); // recursive calls
        }
}
// -^


Battle::Battle(string sel_map) {

    battle_map = sel_map;


}
