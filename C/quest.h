
extern char* playerName;
extern int playerHealth;
extern int playerStrength;
extern int playerMagic;
extern int playerCraftingSkill;

struct Player {
    char* playerName;
    int playerHealth;
    int playerStrength;
    int playerMagic;
    int playerCraftingSkill;
};
extern struct Player player;

extern char* amuletItemName;
extern char* amuletItemKind;
extern int amuletItemPower;

struct Item {
    char* itemName;
    char* itemKind;
    int itemPower;
};
extern struct Item amulet;

void playerToString(char* result, //
                    const char* playerName,
                    int playerHealth,
                    int playerStrength,
                    int playerMagic,
                    int playerCraftingSkill,
                    struct Player player);

void playerFallsDown(int* playerHealth, int* playerStrength, struct Player* player);

void itemToString(char* result, //
                  const char* itemName,
                  const char* itemKind,
                  int itemPower, struct Item item);

void itemReduceByUsage(char* itemKind, int* itemPower, struct Item* item);

void itemApplyEffectToPlayer(const char* itemName,
                             const char* itemKind,
                             int itemPower,
                             int* playerHealth,
                             int* playerStrength,
                             int* playerMagic, struct Item item, struct Player* player);

void itemRepair(int* itemPower, int playerCraftingSkill, struct Item* item, struct Player player);
