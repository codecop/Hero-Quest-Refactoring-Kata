#define CATCH_CONFIG_MAIN
#include <cstdlib>
#include <catch2/catch.hpp>

#include "quest.h"

Player testPlayer = {
    .playerName = "Conan",
    .playerHealth = 100,
    .playerStrength = 20,
    .playerMagic = 10,
    .playerCraftingSkill = 10
};

Item testItem = {
    .itemName = "Amulet of Strength",
    .itemKind = "Strength",
    .itemPower = 10
};

TEST_CASE("Quest")
{
    SECTION("playerToString")
    {
        char result[256];
        playerToString(result, testPlayer);

        const char* expected =
            "Conan's Attributes:\nHealth: 100\nStrength: 20\nMagic: "
            "10\nCrafting "
            "Skill: 10\n";
        REQUIRE(*result == *expected);
    }

    SECTION("playerFallsDown")
    {
        testPlayer.playerStrength = 3;

        playerFallsDown(&testPlayer);

        REQUIRE(testPlayer.playerHealth == 90);
        testPlayer.playerStrength = 20; // reset
        testPlayer.playerHealth = 100;  // reset
    }

    SECTION("playerFallsDownNoDamage")
    {
        playerFallsDown(&testPlayer);

        REQUIRE(testPlayer.playerHealth == 100);
    }

    SECTION("itemToString")
    {
        char result[256];
        itemToString(result, testItem);

        const char* expected =
            "Item: Amulet of Strength\nKind: Strength\nPower: 10\n";
        REQUIRE(*result == *expected);
    }

    SECTION("itemReduceByUsage")
    {
        itemReduceByUsage(&testItem);

        REQUIRE(testItem.itemPower == 5);
        REQUIRE(*testItem.itemKind == *"Strength");
        testItem.itemPower = 10; // reset
    }

    SECTION("itemReduceByUsageToJunk")
    {
        testItem.itemPower = 1;
        char itemKind[10] = "Strength";
        testItem.itemKind = itemKind;
        itemReduceByUsage(&testItem);

        REQUIRE(testItem.itemPower == 0);
        REQUIRE(*testItem.itemKind == *"Junk");
        testItem.itemPower = 10; // reset
        testItem.itemKind = "Strength";
    }

    SECTION("itemApplyEffectToPlayer")
    {
        testItem.itemPower = 10; // reset again, why?
        itemApplyEffectToPlayer(testItem, &testPlayer);

        REQUIRE(testPlayer.playerStrength == 30);
        testPlayer.playerStrength = 20; // reset
    }

    SECTION("itemApplyEffectToPlayerJunk")
    {
        char itemKind[10] = "Junk";
        testItem.itemKind = itemKind;
        itemApplyEffectToPlayer(testItem, &testPlayer);

        REQUIRE(testPlayer.playerStrength == 20);
        testItem.itemKind = "Strength";
    }

    SECTION("itemRepair")
    {
        srand(5); // control the random value
        itemRepair(&testItem, testPlayer);

        REQUIRE(testItem.itemPower == 26);
        testItem.itemPower = 10; // reset
    }
}
