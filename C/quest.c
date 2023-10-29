#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "quest.h"

char* playerName = "Conan";
int playerHealth = 100;
int playerStrength = 20;
int playerMagic = 10;
int playerCraftingSkill = 10;

struct Player player = {
    .playerName = "Conan",
    .playerHealth = 100,
    .playerStrength = 20,
    .playerMagic = 10,
    .playerCraftingSkill = 10
};

void playerToString(char* result, //
                    const char* playerName,
                    int playerHealth,
                    int playerStrength,
                    int playerMagic,
                    int playerCraftingSkill, struct Player player)
{
    sprintf(result,
            "%s's Attributes:\nHealth: %d\nStrength: %d\nMagic: %d\nCrafting "
            "Skill: %d\n",
            player.playerName, player.playerHealth, player.playerStrength, player.playerMagic, player.playerCraftingSkill);
}

void playerFallsDown(int* playerHealth, int* playerStrength, struct Player* player)
{
    printf("Player drops off a cliff.\n");

    if (player->playerStrength < 5) {
        player->playerHealth -= 10;
        printf("Player's strength is too small. Health decreases by 10.\n");
    }
}

char* amuletItemName = "Amulet of Strength";
char* amuletItemKind = "Strength";
int amuletItemPower = 10;

struct Item amulet = {
    .itemName = "Amulet of Strength",
    .itemKind = "Strength",
    .itemPower = 10
};

void itemToString(char* result, //
                  const char* itemName,
                  const char* itemKind,
                  int itemPower, struct Item item)
{
    sprintf(result, "Item: %s\nKind: %s\nPower: %d\n", item.itemName, item.itemKind, item.itemPower);
}

void itemReduceByUsage(char* itemKind, int* itemPower, struct Item* item)
{
    printf("Using the item with kind '%s' and power %d\n", item->itemKind, item->itemPower);

    item->itemPower /= 2;

    if (item->itemPower == 0) {
        strcpy(item->itemKind, "Junk");
    }
}

void itemApplyEffectToPlayer(const char* itemName,
                             const char* itemKind,
                             int itemPower,
                             int* playerHealth,
                             int* playerStrength,
                             int* playerMagic, struct Item item, struct Player* player)
{
    printf("Applying the effect of %s (%s):\n", itemName, itemKind);

    if (strcmp(itemKind, "Health") == 0) {
        *playerHealth += itemPower;
    }
    else if (strcmp(itemKind, "Strength") == 0) {
        *playerStrength += itemPower;
    }
    else if (strcmp(itemKind, "Magic") == 0) {
        *playerMagic += itemPower;
    }
    else {
        // ignore unknown item kind
    }
}

void itemRepair(int* itemPower, int playerCraftingSkill, struct Item* item, struct Player player)
{
    printf("Using the repair skill to fix the item:\n");

    int repairAmount = rand() % (playerCraftingSkill * 2) + 1;

    *itemPower += repairAmount;

    printf("Repaired the item by %d points. Item's Durability: %d\n", repairAmount, *itemPower);
}
