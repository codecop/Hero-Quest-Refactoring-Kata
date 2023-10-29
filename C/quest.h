
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
// extern struct Player player;

extern char* amuletItemName;
extern char* amuletItemKind;
extern int amuletItemPower;

struct Item {
    char* amuletItemName;
    char* amuletItemKind;
    int amuletItemPower;
};
// extern struct Item item;

void playerToString(char* result, //
                    const char* playerName,
                    int playerHealth,
                    int playerStrength,
                    int playerMagic,
                    int playerCraftingSkill);

void playerFallsDown(int* playerHealth, int* playerStrength);

void itemToString(char* result, //
                  const char* itemName,
                  const char* itemKind,
                  int itemPower);

void itemReduceByUsage(char* itemKind, int* itemPower);

void itemApplyEffectToPlayer(const char* itemName,
                             const char* itemKind,
                             int itemPower,
                             int* playerHealth,
                             int* playerStrength,
                             int* playerMagic);

void itemRepair(int* itemPower, int playerCraftingSkill);
