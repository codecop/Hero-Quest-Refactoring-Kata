
struct Player {
    char* playerName;
    int playerHealth;
    int playerStrength;
    int playerMagic;
    int playerCraftingSkill;
};
extern struct Player player;

struct Item {
    char* itemName;
    char* itemKind;
    int itemPower;
};
extern struct Item amulet;

void playerToString(char* result, struct Player player);

void playerFallsDown(struct Player* player);

void itemToString(char* result, struct Item item);

void itemReduceByUsage(struct Item* item);

void itemApplyEffectToPlayer(struct Item item, struct Player* player);

void itemRepair(struct Item* item, struct Player player);
