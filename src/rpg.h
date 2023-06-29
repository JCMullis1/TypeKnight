#ifndef RPG_H_INCLUDED
#define RPG_H_INCLUDED
#include <vector>
#include <fstream>

using namespace std;

class Armor {
    public:
        int price_value;
        int armr_val;
        int armr_class;
        Armor(int price = 0, int armr_value = 0, int ac = 13);
};

class Weapon {
    public:
        int price_value;
        int damage_min, damage_max;
        int ac_modifier;
        string mod;

        Weapon(int price = 0, int dmg_min = 1, int dmg_max = 3, int armr_class_mod = 0, string modifier = "");
};

class Entity {
    public:
        string name;
        bool is_player = false;
        int curr_health;
        int max_health;
        int mana;
        int speed;
        int defense;
        int ac;
        Weapon wpn_left, wpn_right;
        Armor armr_head, armr_chest, armr_legs, armr_feet,
        armr_hands, armr_shoulders, armr_pendant, armr_ring1, armr_ring2;

        Entity(int health = 30, int mna = 30, int spd = 15, string arg_name = "N/A", bool arg_is_player = false, Weapon slot_lhnd = Weapon(), Weapon slot_rhnd = Weapon(), Armor slot_hd = Armor(), Armor slot_cht = Armor(), Armor slot_lgs = Armor(), Armor slot_ft = Armor(), Armor slot_gnt = Armor(), Armor slot_shl = Armor(), Armor slot_pen = Armor(), Armor slot_rng1 = Armor(), Armor slot_rng2 = Armor());
};

// D_STRUCTS HEADER
extern vector<Entity*> objArr;

// quick sort algo
int arrPartition(vector<Entity*> &vec, int startInd, int endInd);
void quickSort(vector<Entity*> &vec, int startInd, int endInd);
// -^

class Battle {
    public:
        string battle_map;
        Battle(string sel_map);
};

#endif // RPG_H_INCLUDED
