/*Выполнил работу Терсков Кирилл 302ИС-22
Название проекта "Proga"
12.12.2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "character.h"
#include "location.h"
#include "item.h"
#include "npc.h"
#include "func.h"
#include <locale.h>

#ifdef _WIN32
#include <windows.h>
#endif
// создание макросов, которые при компиляции примут указанные значения
#define MAX_NAME_LENGTH 100
#define MAX_CHARACTERS 10
#define MAX_ITEMS 10
#define MAX_NPCS 10

int main() { // главный модуль
    setlocale(LC_ALL, "ru_RU.UTF-8"); // установка поддержки русского языка

    // Изменение кодировки консоли в Windows
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    // объявление переменных
    Character characters[MAX_CHARACTERS];
    Location locations[MAX_CHARACTERS];
    Item items[MAX_ITEMS];
    NPC npcs[MAX_NPCS];
    int characterCount = 0, locationCount = 0, itemCount = 0, npcCount = 0;
    char filename[MAX_NAME_LENGTH];
    int vibor = 0;

    while (1) { // цикл который будет работать, пока значение не поменяется на False(0)
        show_menu(); // вызов функции меню
        scanf("%d", &vibor); // обработка ввода пользователя
        switch (vibor)
        {
        case 1: // если ввод был 1, то будет активирован данный кейс, который выводит информацию о программе
                printf("Программа Proga предназначена для сохранения ифнормации о персонажей, локаций, предметов и Npc, а также для просмотра информации из файла\n");
                break;
            case 2: // если ввод был 2, то будет активирован данный кейс, который выводит информацию о разработчике
                printf("Программу разработал Терсков Кирилл из 302ИС-22\n");
                break;
            case 3: // если ввод был 3, то будет активирован данный кейс, который вызывает функцию о вводе и сохранения информации
                printf("Введите имя файла для сохранения: ");
                scanf("%s", filename);
                processChoice(filename, characters, characterCount, locations, locationCount, items, itemCount, npcs, npcCount);
                break;
            case 4: // если ввод был 4, то будет активирован данный кейс, который вызывает функцию о поиске и выводе информации из файла
                printf("Введите имя файла для отображения: ");
                scanf("%s", filename);
                searchAndDisplayFile(filename);
                break;
            case 5: // если ввод был 5, то будет активирован данный кейс и программа завершиться
                printf("Выход из программы.\n");
                Sleep(2000);
                return 0;
            default: // если вводится значения не от 1 - 5, то выдаёт ошибку
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    }

    return 0;
}