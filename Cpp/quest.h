
class Player {
    public:
    char* playerName;
    int playerHealth;
    int playerStrength;
    int playerMagic;
    int playerCraftingSkill;
};
extern Player player;

class Item {
    public:
    char* itemName;
    char* itemKind;
    int itemPower;
};
extern Item amulet;

void playerToString(char* result, Player player);

void playerFallsDown(Player* player);

void itemToString(char* result, Item item);

void itemReduceByUsage(Item* item);

void itemApplyEffectToPlayer(Item item, Player* player);

void itemRepair(Item* item, Player player);
