#ifndef GUN_H
#define GUN_H

#include <game_obj.h>

class Gun : public GameObject{
    int total_ammo;
    int current_ammo;

    float fire_rate, reload_rate;
    long last_fired, last_reload;

public:
    Ray shoot();
    void reload();

    int get_total_ammo();
    int get_current_ammo();
};

#endif