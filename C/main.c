#include <stdio.h>
#include <stdlib.h> /* rand */
#include <time.h>

#include "quest.h"

int main(void)
{
    srand(time(0));

    char result[256];
    playerToString(result, playerName, playerHealth, playerStrength,
                   playerMagic, playerCraftingSkill, player);
    printf("Player at begin\n%s\n", result);

    itemToString(result, amuletItemName, amuletItemKind, amuletItemPower, amulet);
    printf("Player found an item\n%s\n", result);

    itemApplyEffectToPlayer(amuletItemName, amuletItemKind, amuletItemPower,
                            &playerHealth, &playerStrength, &playerMagic, amulet, &player);
    itemReduceByUsage(amuletItemKind, &amuletItemPower, &amulet);

    playerToString(result, playerName, playerHealth, playerStrength,
                   playerMagic, playerCraftingSkill, player);
    printf("Player now\n%s\n", result);

    itemToString(result, amuletItemName, amuletItemKind, amuletItemPower, amulet);
    printf("Item now\n%s\n", result);

    printf("Player tries to repair item...\n");
    itemRepair(&amuletItemPower, playerCraftingSkill, &amulet, player);
    itemToString(result, amuletItemName, amuletItemKind, amuletItemPower, amulet);
    printf("Item now\n%s\n", result);

    return 0;
}
