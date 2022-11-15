#ifndef PLAYER_H
#define PLAYER_H

#include <game_obj.h>
#include <gun.h>

class Player : public GameObject{
    Gun active, inactive;

    float health;
public:
    void swap_weapon();
    void shoot();
    void reload();
    void heal(float value);
    void damage(float damage);
};

#endif