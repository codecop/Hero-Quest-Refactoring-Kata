#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h> 

#include "quest.h"
#include <cmocka.h>

const char* testPlayerName = "Conan";
int testPlayerHealth = 100;
int testPlayerStrength = 20;
int testPlayerMagic = 10;
int testPlayerCraftingSkill = 10;

struct Player testPlayer = {
    .playerName = "Conan",
    .playerHealth = 100,
    .playerStrength = 20,
    .playerMagic = 10,
    .playerCraftingSkill = 10
};

const char* testItemName = "Amulet of Strength";
char* testItemKind = "Strength";
int testItemPower = 10;

struct Item testItem = {
    .itemName = "Amulet of Strength",
    .itemKind = "Strength",
    .itemPower = 10
};

static void test_playerToString(void** state)
{
    (void)state;

    char result[256];
    playerToString(result, testPlayerName, testPlayerHealth, testPlayerStrength,
                   testPlayerMagic, testPlayerCraftingSkill, testPlayer);

    const char* expected =
        "Conan's Attributes:\nHealth: 100\nStrength: 20\nMagic: 10\nCrafting "
        "Skill: 10\n";
    assert_string_equal(result, expected);
}

static void test_playerFallsDown(void** state)
{
    (void)state;

    testPlayerStrength = 3;
    testPlayer.playerStrength = 3;
    playerFallsDown(&testPlayerHealth, &testPlayerStrength, &testPlayer);

    // old assert_int_equal(testPlayerHealth, 90);
    assert_int_equal(testPlayer.playerHealth, 90);
    testPlayerStrength = 20; // reset
    testPlayerHealth = 100;  // reset
    testPlayer.playerStrength = 20; // reset
    testPlayer.playerHealth = 100;  // reset
}

static void test_playerFallsDownNoDamage(void** state)
{
    (void)state;

    playerFallsDown(&testPlayerHealth, &testPlayerStrength, &testPlayer);

    assert_int_equal(testPlayerHealth, 100);
    assert_int_equal(testPlayer.playerHealth, 100);
}

static void test_itemToString(void** state)
{
    (void)state;

    char result[256];
    itemToString(result, testItemName, testItemKind, testItemPower, testItem);

    const char* expected =
        "Item: Amulet of Strength\nKind: Strength\nPower: 10\n";
    assert_string_equal(result, expected);
}

static void test_itemReduceByUsage(void** state)
{
    (void)state;

    itemReduceByUsage(testItemKind, &testItemPower, &testItem);

    // old assert_int_equal(testItemPower, 5);
    // old assert_string_equal(testItemKind, "Strength");
    testItemPower = 10; // reset
    assert_int_equal(testItem.itemPower, 5);
    assert_string_equal(testItem.itemKind, "Strength");
    testItem.itemPower = 10; // reset
}

static void test_itemReduceByUsageToJunk(void** state)
{
    (void)state;

    testItemPower = 1;
    char itemKind[10] = "Strength";
    testItem.itemPower = 1;
    testItem.itemKind = itemKind;
    itemReduceByUsage(itemKind, &testItemPower, &testItem);

    // old assert_int_equal(testItemPower, 0);
    // old assert_string_equal(itemKind, "Junk");
    testItemPower = 10; // reset
    assert_int_equal(testItem.itemPower, 0);
    assert_string_equal(testItem.itemKind, "Junk");
    testItem.itemPower = 10; // reset
    testItem.itemKind = "Strength";
}

static void test_itemApplyEffectToPlayer(void** state)
{
    (void)state;

    itemApplyEffectToPlayer(testItemName, testItemKind, testItemPower,
                            &testPlayerHealth, &testPlayerStrength, &testPlayerMagic, testItem, &testPlayer);

    // old assert_int_equal(testPlayerStrength, 30);
    testPlayerStrength = 20; // reset
    assert_int_equal(testPlayer.playerStrength, 30);
    testPlayer.playerStrength = 20; // reset
}

static void test_itemApplyEffectToPlayerJunk(void** state)
{
    (void)state;

    char itemKind[10] = "Junk";
    testItem.itemKind = itemKind;
    itemApplyEffectToPlayer(testItemName, "Junk", testItemPower, &testPlayerHealth,
                            &testPlayerStrength, &testPlayerMagic, testItem, &testPlayer);

    // old assert_int_equal(testPlayerStrength, 20);
    assert_int_equal(testPlayer.playerStrength, 20);
    testItem.itemKind = "Strength";
}

static void test_itemRepair(void** state)
{
    (void)state;

    srand(5); // control the random value
    itemRepair(&testItemPower, testPlayerCraftingSkill, &testItem, testPlayer);

    // old assert_int_equal(testItemPower, 26);
    testItemPower = 10; // reset
    assert_int_equal(testItem.itemPower, 26);
    testItem.itemPower = 10; // reset
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_playerToString),
        cmocka_unit_test(test_playerFallsDownNoDamage),
        cmocka_unit_test(test_playerFallsDown),
        cmocka_unit_test(test_itemToString),
        cmocka_unit_test(test_itemReduceByUsage),
        cmocka_unit_test(test_itemReduceByUsageToJunk),
        cmocka_unit_test(test_itemApplyEffectToPlayer),
        cmocka_unit_test(test_itemApplyEffectToPlayerJunk),
        cmocka_unit_test(test_itemRepair),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
