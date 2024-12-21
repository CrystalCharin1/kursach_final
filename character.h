#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#define MAX_NAME_LENGTH 100 // создание макроса, который при компиляции заменится на 100
#define MAX_HISTORY_LENGTH 1000 // создание макроса, который при компиляции заменится на 1000

class Character {
public:
    char firstName[MAX_NAME_LENGTH]; // Имя персонажа
    char lastName[MAX_NAME_LENGTH];  // Фамилия персонажа
    float height;                    // Рост
    float weight;                    // Вес
    char history[MAX_HISTORY_LENGTH]; // История персонажа
};

#endif // CHARACTER_H_INCLUDED