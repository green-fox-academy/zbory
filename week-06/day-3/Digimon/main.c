#include <stdio.h>
#include <string.h>

/* Digimon database!
 * You should store the following data in a structure
 *  - the name of the digimon (which is shorter than 128 characters)
 *  - the age of the digimon (in years)
 *  - the health of the digimon (between 0-100)
 *  - the name of the tamer (which is shorter than 256 characters)
 *  - the digivolution level of the digimon (as a custom type, see below)
 *
 * You should store the digivolution level in an enumeration
 * the valid digivolution levels are:
 *  - baby
 *  - in-training
 *  - rookie
 *  - champion
 *  - ultimate
 *  - mega
 *
 * The digimons are stored in an array.
 *
 * Write the following functions:
 * 1) Get minimum health index
 *      - parameters:
 *          - array
 *          - array length
 *      - it returns the index of the minimal health digimon in the "array"
 * 2) Get same digivolution level count
 *      - parameters:
 *          - array
 *          - array length
 *          - digivolution level
 *      - it returns the count of digimons which are at "digivolution level"
 * 3) Get same tamer count
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the count of the digimons which have the same tamer as "tamer name"
 * 4) Get average health of the same tamer
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the average health of the digimons which have the same tamer as "tamer name"
 *
 * Don't forget to handle invalid inputs (NULL pointers, invalid values etc.)
 */

typedef enum digivolution {
    BABY,
    IN_TRAINING,
    ROOKIE,
    CHAMPION,
    ULTIMATE,
    MEGA
} Digivolution;

typedef struct digimon {
    char digimon_name[128];
    int age;
    int health;
    char tamer_name[256];
    Digivolution level;
} digimon_t;

int min_health_index(digimon_t *digimon_array, int size);

int count_digilevel(digimon_t *digimon_array, int size, Digivolution level);

int count_same_tamer(digimon_t *digimon_array, int size, const char *tamer_name);

float average_health_tamer(digimon_t *digimon_array, int size, const char *tamer_name);

int main()
{
    digimon_t digimons[5];
    int size = sizeof(digimons) / sizeof(digimon_t);

    strcpy(digimons[0].digimon_name, "ScarySpice");
    digimons[0].age = 19;
    digimons[0].health = 78;
    strcpy(digimons[0].tamer_name, "LordVoldemort");
    digimons[0].level = ROOKIE;

    strcpy(digimons[1].digimon_name, "SportySpice");
    digimons[1].age = 22;
    digimons[1].health = 98;
    strcpy(digimons[1].tamer_name, "TomAndJerry");
    digimons[1].level = ULTIMATE;

    strcpy(digimons[2].digimon_name, "BabySpice");
    digimons[2].age = 20;
    digimons[2].health = 66;
    strcpy(digimons[2].tamer_name, "TomAndJerry");
    digimons[2].level = CHAMPION;

    strcpy(digimons[3].digimon_name, "GingerSpice");
    digimons[3].age = 24;
    digimons[3].health = 88;
    strcpy(digimons[3].tamer_name, "DarthMaul");
    digimons[3].level = CHAMPION;

    strcpy(digimons[4].digimon_name, "PoshSpice");
    digimons[4].age = 26;
    digimons[4].health = 46;
    strcpy(digimons[4].tamer_name, "Gandalf");
    digimons[4].level = BABY;

    int lowhealth_index = min_health_index(digimons, size);
    printf("Digimon with lowest health: %s: %d\n", digimons[lowhealth_index].digimon_name,
           digimons[lowhealth_index].health);


    Digivolution find_level = CHAMPION;
    printf("There are %d digimons at Champion level\n", count_digilevel(digimons, size, find_level));

    char tamer[20] = "TomAndJerry";
    printf("Input the tamer whose digimons you want to count:");
    scanf("%s", &tamer);

    printf("The tamer %s has %d digimons\n", tamer, count_same_tamer(digimons, size, tamer));

    char tamer2[] = "TomAndJerry";
    printf("The average health of the digimons of tamer %s is %.2f\n", tamer, average_health_tamer(digimons, size, tamer2));

    return 0;
}

int min_health_index(digimon_t *digimon_array, int size)
{
    int min_value = digimon_array->health;
    int min_index = 0;
    for (int i = 0; i < size; ++i) {
        if (digimon_array[i].health < min_value) {
            min_value = digimon_array[i].health;
            min_index = i;
        }
    }
    return min_index;
}

int count_digilevel(digimon_t *digimon_array, int size, Digivolution level)
{
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (digimon_array[i].level == level) {
            count++;
        }
    }
    return count;
}

int count_same_tamer(digimon_t *digimon_array, int size, const char *tamer_name)
{
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (!strcmp(digimon_array[i].tamer_name, tamer_name)) {
            count++;
        }
    }
    return count;
}

float average_health_tamer(digimon_t *digimon_array, int size, const char *tamer_name){
    int count = 0;
    int sum_health = 0;
    for (int i = 0; i < size; ++i) {
        if (!strcmp(digimon_array[i].tamer_name, tamer_name)) {
            count++;
            sum_health += digimon_array[i].health;
        }
    }
    return sum_health / count;
}