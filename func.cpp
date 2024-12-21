#include <stdio.h>
#include "item.h"
#include "character.h"
#include "location.h"
#include "npc.h"
#include "func.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
#include <unistd.h>
#endif

// создание макросов, которые при компиляции примут указанные значения
#define MAX_HISTORY_LENGTH 1000 
#define MAX_DESCRIPTION_LENGTH 500
#define MAX_ITEM_TYPE_LENGTH 50
#define MAX_LOCATION_NAME_LENGTH 50
#define MAX_ITEM_NAME_LENGTH 100
#define MAX_LOCATION_TYPE_LENGTH 50
#define MAX_NPC_NAME_LENGTH 100
#define MAX_NPCS 10
#define MAX_CHARACTERS 100
#define MAX_LOCATIONS 100
#ifndef MAX_ITEMS
#define MAX_ITEMS 10
#endif
#define MAX_NAME_LENGTH 100
#ifndef MAX_DESCRIPTION_LENGTH
#define MAX_DESCRIPTION_LENGTH 1000
#endif

// объявление переменных
Character characters[MAX_CHARACTERS];
int characterCount = 0;

NPC npcs[MAX_NPCS];
int npcCount = 0;

Location locations[MAX_LOCATIONS];
int locationCount = 0;

Item items[MAX_ITEMS];
int itemCount = 0;

void inputCharacter(Character *character_p) { //  функция отвечает за ввод информации о персонаже
    printf("Введите имя персонажа: ");
    scanf("%s", character_p->firstName);
    printf("Введите фамилию персонажа: ");
    scanf("%s", character_p->lastName);
    printf("Введите рост (в метрах): ");
    scanf("%f", &character_p->height);
    printf("Введите вес (в килограмах): ");
    scanf("%f", &character_p->weight);
    printf("Введите историю персонажа: ");
    
    while (getchar() != '\n');

    fgets(character_p->history, MAX_HISTORY_LENGTH, stdin);
}

void inputLocation(Location *location_p) { //  функция отвечает за ввод информации о локации
    printf("Введите тип локации: ");
    scanf("%s", location_p->type);
    printf("Введите название локации: ");
    scanf("%s", location_p->name_loc);
    printf("Введите размер локации (в км^2): ");
    scanf("%f", &location_p->size);
    printf("Введите описание локации: ");
    
    while (getchar() != '\n');

    fgets(location_p->description, MAX_DESCRIPTION_LENGTH, stdin);
    
    locations[locationCount++] = *location_p;
}

void inputItem(Item *item_p) { // функция отвечает за ввод информации о предмете
    printf("Введите тип предмета: ");
    scanf("%s", item_p->type);
    printf("Введите название предмета: ");
    scanf("%s", item_p->name_item);
    printf("Введите кол-во предметов: ");
    scanf("%d", &item_p->quantity);
    
    items[itemCount++] = *item_p;
}

void inputNPC(NPC *npc_p) { // функция отвечает за ввод информации о Npc
    printf("Введите имя NPC: ");
    scanf("%s", npc_p->name_npc);
    
    if (locationCount > 0) {
        printf("Выберите локацию (0 to %d):\n", locationCount - 1);
        for (int i = 0; i < locationCount; i++) {
            printf("%d: %s\n", i, locations[i].name_loc);
        }
        int locIndex;
        scanf("%d", &locIndex);
        npc_p->location = locations[locIndex];
    } else {
        inputLocation(&npc_p->location);
    }

    printf("Введите кол-во предметов у NPC: ");
    scanf("%d", &npc_p->itemCount);
    
    while (getchar() != '\n');

    for (int i = 0; i < npc_p->itemCount; i++) {
        if (itemCount > 0) {
            printf("Выберете предмет (0 to %d):\n", itemCount - 1);
            for (int j = 0; j < itemCount; j++) {
                printf("%d: %s\n", j, items[j].name_item);
            }
            int itemIndex;
            scanf("%d", &itemIndex);
            npc_p->items[i] = items[itemIndex];
        } else {
            inputItem(&npc_p->items[i]);
        }
    }
}

void saveToFile(const char *filename, Character *characters, int characterCount, Location *locations, int locationCount, Item *items, int itemCount, NPC *npcs, int npcCount) { // функция отвечает за сохранение данных в файл
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return;
    }

    for (int i = 0; i < characterCount; i++) {
        fprintf(file, "Character: %s %s, Height: %.2f, Weight: %.1f, History: %s\n",
                characters[i].firstName, characters[i].lastName,
                characters[i].height, characters[i].weight, characters[i].history);
    }

    for (int i = 0; i < locationCount; i++) {
        fprintf(file, "Location: %s, Location name: %s, Size: %.2f, Description: %s\n",
                locations[i].type, locations[i].name_loc, locations[i].size, locations[i].description);
    }

    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "Item: %s, Name: %s, Quantity: %d\n",
                items[i].type, items[i].name_item, items[i].quantity);
    }

    for (int i = 0; i < npcCount; i++) {
        fprintf(file, "NPC: %s, Location: %s, ItemCount: %d\n",
                npcs[i].name_npc, npcs[i].location.name_loc, npcs[i].itemCount);
        for (int j = 0; j < npcs[i].itemCount; j++) {
            fprintf(file, "  Item %d: %s\n", j + 1, npcs[i].items[j].name_item);
        }
    }

    fclose(file);
}

void show_menu() { // функция отвечает за меню
    printf(
        "\n+-----------------------------+\n"
        "1 - Информация о приложение\n"
        "2 - Информация о создателе приложения\n"
        "3 - Начать программу\n"
        "4 - Показать информацию из файла\n"
        "5 - Выйти\n"
        "+----------------------------+\n");
}

void searchAndDisplayFile(const char *filename) { // функция отвечает за поиск файла и вывод информации из файла
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Файл %s не найден или не может быть открыт.\n", filename);
        return;
    }

    printf("Содержимое файла %s:\n", filename);
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

char choice;
void processChoice(const char *filename, Character *characters, int characterCount, Location *locations, int locationCount, Item *items, int itemCount, NPC *npcs, int npcCount) { // функция отвечает за выбор о создание ещё одного персонажа, локации, предмета и Npc
    do { 
        if (characterCount < MAX_CHARACTERS) {
            inputCharacter(&characters[characterCount]);
            characterCount++;
        } else {
            printf("Maximum number of characters reached.\n");
            break;
        }
        printf("Do you want to enter another character? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    do { 
        if (locationCount < MAX_LOCATIONS) {
            inputLocation(&locations[locationCount]);
            locationCount++;
        } else {
            printf("Maximum number of locations reached.\n");
            break;
        }
        printf("Do you want to enter another location? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    do {
        if (itemCount < MAX_ITEMS) {
            inputItem(&items[itemCount]);
            itemCount++;
        } else {
            printf("Maximum number of items reached.\n");
            break;
        }
        printf("Do you want to enter another item? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    do {
        if (npcCount < MAX_NPCS) {
            inputNPC(&npcs[npcCount]);
            npcCount++;
        } else {
            printf("Maximum number of NPCs reached.\n");
            break;
        }
        printf("Do you want to enter another NPC? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    saveToFile(filename, characters, characterCount, locations, locationCount, items, itemCount, npcs, npcCount);
}