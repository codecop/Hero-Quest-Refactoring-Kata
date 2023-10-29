#include <stdio.h>
#include <stdlib.h> /* rand */
#include <time.h>

#include "quest.h"

int main(void)
{
    srand(time(0));

    char result[256];
    playerToString(result, player);
    printf("Player at begin\n%s\n", result);

    itemToString(result, amulet);
    printf("Player found an item\n%s\n", result);

    itemApplyEffectToPlayer(amulet, &player);
    itemReduceByUsage(&amulet);

    playerToString(result, player);
    printf("Player now\n%s\n", result);

    itemToString(result, amulet);
    printf("Item now\n%s\n", result);

    printf("Player tries to repair item...\n");
    itemRepair(&amulet, player);
    itemToString(result, amulet);
    printf("Item now\n%s\n", result);

    return 0;
}
