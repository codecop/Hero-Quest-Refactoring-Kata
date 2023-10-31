#include <stdio.h>
#include <string.h>
#include <cstdlib>

#include "quest.h"

struct Player player = {.playerName = "Conan",
                        .playerHealth = 100,
                        .playerStrength = 20,
                        .playerMagic = 10,
                        .playerCraftingSkill = 10};

void playerToString(char* result, struct Player player)
{
    sprintf(result,
            "%s's Attributes:\nHealth: %d\nStrength: %d\nMagic: %d\nCrafting "
            "Skill: %d\n",
            player.playerName, player.playerHealth, player.playerStrength, player.playerMagic, player.playerCraftingSkill);
}

void playerFallsDown(struct Player* player)
{
    printf("Player drops off a cliff.\n");

    if (player->playerStrength < 5) {
        player->playerHealth -= 10;
        printf("Player's strength is too small. Health decreases by 10.\n");
    }
}

struct Item amulet = {
    .itemName = "Amulet of Strength",
    .itemKind = "Strength",
    .itemPower = 10};

void itemToString(char* result, struct Item item)
{
    sprintf(result, "Item: %s\nKind: %s\nPower: %d\n", item.itemName, item.itemKind, item.itemPower);
}

void itemReduceByUsage(struct Item* item)
{
    printf("Using the item with kind '%s' and power %d\n", item->itemKind, item->itemPower);

    item->itemPower /= 2;

    if (item->itemPower == 0) {
        strcpy(item->itemKind, "Junk");
    }
}

void itemApplyEffectToPlayer(struct Item item, struct Player* player)
{
    printf("Applying the effect of %s (%s):\n", item.itemName, item.itemKind);

    if (strcmp(item.itemKind, "Health") == 0) {
        player->playerHealth += item.itemPower;
    }
    else if (strcmp(item.itemKind, "Strength") == 0) {
        player->playerStrength += item.itemPower;
    }
    else if (strcmp(item.itemKind, "Magic") == 0) {
        player->playerMagic += item.itemPower;
    }
    else {
        // ignore unknown item kind
    }
}

void itemRepair(struct Item* item, struct Player player)
{
    printf("Using the repair skill to fix the item:\n");

    int repairAmount = rand() % (player.playerCraftingSkill * 2) + 1;

    item->itemPower += repairAmount;

    printf("Repaired the item by %d points. Item's Durability: %d\n", repairAmount, item->itemPower);
}
