package codingdojo;

import java.util.Objects;

public class HeroQuest {

    public static String playerToString(String playerName, int playerHealth, int playerStrength, int playerMagic, int playerCraftingSkill) {
        return String.format("%s's Attributes:\nHealth: %d\nStrength: %d\nMagic: %d\nCrafting Skill: %d\n",
                playerName, playerHealth, playerStrength, playerMagic, playerCraftingSkill);
    }

    public static void playerFallsDown(QuestData questData) {
        System.out.println("Player drops off a cliff.");

        if (questData.getPlayerStrength() < 5) {
            questData.setPlayerHealth(questData.getPlayerHealth() - 10);
            System.out.println("Player's strength is too small. Health decreases by 10.");
        }
    }

    public static String itemToString(String itemName, String itemKind, int itemPower) {
        return String.format("Item: %s\nKind: %s\nPower: %d\n", itemName, itemKind, itemPower);
    }

    public static void itemReduceByUsage(QuestData questData) {
        System.out.println(String.format("Using the item with kind '%s' and power %d", questData.getItemKind(), questData.getItemPower()));

        questData.setItemPower(questData.getItemPower() / 2);

        if (questData.getItemPower() == 0) {
            questData.setItemKind("Junk");
        }

    }

    public static void itemApplyEffectToPlayer(QuestData data) {
        System.out.println(String.format("Applying the effect of %s (%s):", data.getItemName(), data.getItemKind()));

        if (Objects.equals(data.getItemKind(), "Health")) {
            data.setPlayerHealth(data.getPlayerHealth() + data.getItemPower());
        } else if (Objects.equals(data.getItemKind(), "Strength")) {
            data.setPlayerStrength(data.getPlayerStrength() + data.getItemPower());
        } else if (Objects.equals(data.getItemKind(), "Magic")) {
            data.setPlayerMagic(data.getPlayerMagic() + data.getItemPower());
        } else {
            // ignore unknown item kind
        }
    }

    public static void itemRepair(QuestData questData) {
        System.out.println("Using the repair skill to fix the item:");

        int repairAmount = -5 + ((questData.getPlayerCraftingSkill() * 2) + 1);

        questData.setItemPower(questData.getItemPower() + repairAmount);

        System.out.println(String.format("Repaired the item by %d points. Item's Durability: %d", repairAmount, questData.getItemPower()));
    }
}