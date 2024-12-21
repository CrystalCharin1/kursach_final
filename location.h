#ifndef LOCATION_H_INCLUDED
#define LOCATION_H_INCLUDED

#define MAX_LOCATION_TYPE_LENGTH 50 // создание макроса, который при компиляции заменится на 50
#define MAX_LOCATION_NAME_LENGTH 50 // создание макроса, который при компиляции заменится на 50
#define MAX_DESCRIPTION_LENGTH 500 // создание макроса, который при компиляции заменится на 500

class Location {
public:
    char type[MAX_LOCATION_TYPE_LENGTH];        // Тип локации
    char name_loc[MAX_LOCATION_NAME_LENGTH];    // Название локации
    float size;                                 // Размер локации
    char description[MAX_DESCRIPTION_LENGTH];   // Описание локации
};

#endif // LOCATION_H_INCLUDED