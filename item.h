#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#define MAX_ITEM_TYPE_LENGTH 50 // создание макроса, который при компиляции заменится на 50
#define MAX_ITEM_NAME_LENGTH 100 // создание макроса, который при компиляции заменится на 100

class Item {
public:
    char type[MAX_ITEM_TYPE_LENGTH];     // Тип предмета
    char name_item[MAX_ITEM_NAME_LENGTH]; // Название предмета
    int quantity;                        // Количество предметов
};
#endif //ITEM_H_INCLUDED