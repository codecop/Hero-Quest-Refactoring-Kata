<?php

require_once __DIR__ . '/../vendor/autoload.php';

use CodingDojo\HeroQuest;

function run() {
    $playerName = "Conan";
    $playerHealth = 100;
    $playerStrength = 7;
    $playerMagic = 15;
    $playerCraftingSkill = 12;
    $itemName = "Healing Potion";
    $itemKind = "Health";
    $itemPower = 20;
    $enemyName = "Goblin Warlord";
    $enemyPower = 12;

    HeroQuest::$output[] = "=== QUEST BEGINNING ===\n";

    HeroQuest::$output[] = HeroQuest::playerToString($playerName, $playerHealth, $playerStrength, $playerMagic, $playerCraftingSkill);
    HeroQuest::$output[] = "";

    HeroQuest::$output[] = HeroQuest::itemToString($itemName, $itemKind, $itemPower);
    HeroQuest::$output[] = "";

    HeroQuest::$output[] = "--- Exploring the dungeon... ---\n";

    HeroQuest::playerFallsDown($playerHealth, $playerStrength);
    HeroQuest::$output[] = HeroQuest::playerToString($playerName, $playerHealth, $playerStrength, $playerMagic, $playerCraftingSkill);
    HeroQuest::$output[] = "";

    HeroQuest::$output[] = "--- Using the healing item ---\n";

    HeroQuest::itemApplyEffectToPlayer($itemName, $itemKind, $itemPower, $playerHealth, $playerStrength, $playerMagic);
    HeroQuest::$output[] = HeroQuest::playerToString($playerName, $playerHealth, $playerStrength, $playerMagic, $playerCraftingSkill);
    HeroQuest::$output[] = "";

    HeroQuest::$output[] = HeroQuest::itemToString($itemName, $itemKind, $itemPower);
    HeroQuest::$output[] = "";

    HeroQuest::$output[] = "--- Item degradation from repeated use ---\n";

    HeroQuest::itemReduceByUsage($itemKind, $itemPower);
    HeroQuest::$output[] = HeroQuest::itemToString($itemName, $itemKind, $itemPower);
    HeroQuest::$output[] = "";

    HeroQuest::itemReduceByUsage($itemKind, $itemPower);
    HeroQuest::$output[] = HeroQuest::itemToString($itemName, $itemKind, $itemPower);
    HeroQuest::$output[] = "";

    HeroQuest::$output[] = "--- Repairing the damaged item ---\n";

    HeroQuest::itemRepair($playerCraftingSkill, $itemPower);
    HeroQuest::$output[] = HeroQuest::itemToString($itemName, $itemKind, $itemPower);
    HeroQuest::$output[] = "";

    HeroQuest::$output[] = "=== ENEMY ENCOUNTER ===\n";

    HeroQuest::$output[] = HeroQuest::enemyToString($enemyName, $enemyPower);
    HeroQuest::$output[] = "";

    HeroQuest::enemyAttackPlayer($enemyName, $enemyPower, $playerStrength, $playerHealth);
    HeroQuest::$output[] = HeroQuest::playerToString($playerName, $playerHealth, $playerStrength, $playerMagic, $playerCraftingSkill);
    HeroQuest::$output[] = "";

    HeroQuest::$output[] = "--- Player retaliates ---\n";

    HeroQuest::playerChallengeEnemy($enemyName, $playerStrength, $itemPower, $enemyPower);
    HeroQuest::$output[] = HeroQuest::enemyToString($enemyName, $enemyPower);
    HeroQuest::$output[] = "";
}

if (php_sapi_name() === 'cli' && basename(__FILE__) === basename($argv[0] ?? '')) {
    HeroQuest::$output = [];
    run();
    echo implode("\n", HeroQuest::$output) . "\n";
}
