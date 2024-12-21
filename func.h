#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include "item.h"
#include "character.h"
#include "location.h"
#include "npc.h"

// Объявление функций для работы с данными

void inputCharacter(Character *character_p); // Функция для ввода данных о персонаже
void inputLocation(Location *location_p); // Функция для ввода данных о локации
void inputItem(Item *item_p); // Функция для ввода данных о предмете
void inputNPC(NPC *npc_p); // Функция для ввода данных о NPC
void saveToFile(const char *filename, Character *characters, int characterCount, Location *locations, int locationCount, Item *items, int itemCount, NPC *npcs, int npcCount); /*Функция для сохранения данных в файл
Принимает имя файла, массивы персонажей, локаций, предметов и NPC, а также их количества */
void processChoice(const char *filename, Character *characters, int characterCount, Location *locations, int locationCount, Item *items, int itemCount, NPC *npcs, int npcCount); // функция для выбора о создание ещё одного персонада, локации, предмета и npc
void show_menu(); // Функция вывода меню
void searchAndDisplayFile(const char *filename); // функция для поиска файла и вывода из него информации
#endif //FUNC_H_INCLUDED