#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include "item.h"
#include "location.h"

#define MAX_ITEMS 10 // создание макроса, который при компиляции заменится на 10
#define MAX_NPC_NAME_LENGTH 100 // создание макроса, который при компиляции заменится на 100

class NPC {
public:
    char name_npc[MAX_NPC_NAME_LENGTH]; // Имя NPC
    Location location;                 // Локация NPC
    Item items[MAX_ITEMS];             // Предметы NPC
    int itemCount;                     // Количество предметов у NPC
};

#endif //NPC_H_INCLUDED