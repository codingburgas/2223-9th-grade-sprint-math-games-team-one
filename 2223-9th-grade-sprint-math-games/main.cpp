#include <raylib.h>
#include <iostream>
#include <bitset>
#include <stdlib.h>
using namespace std;
int currentWidth = GetScreenWidth();
int currentHeight = GetScreenHeight();
Image BG = LoadImage("resources\\MainMenuBackground.png");
Image mainMenuGui1 = LoadImage("resources\\GUI1.png");
Image mainMenuGui2 = LoadImage("resources\\GUI2.png");
Image mainMenuGui3 = LoadImage("resources\\GUI3.png");
Image optionsGui1 = LoadImage("resources\\OptionsGUI1.png");
Image optionsGui2 = LoadImage("resources\\OptionsGUI2.png");
Image optionsGui3 = LoadImage("resources\\OptionGUI3.png");
Image optionsGui4 = LoadImage("resources\\OptionsGUI4.png");
Image lvlBoxes1 = LoadImage("resources\\LVLBOX1.png");
Image lvlBoxes2 = LoadImage("resources\\LVLBOX2.png");
Image lvlBoxes3 = LoadImage("resources\\LVLBOX3.png");
Image firstLevelBG = LoadImage("resources\\FirstLevelBG.png");
Image firstAbilitySelect = LoadImage("resources\\Ability_1.png");
Image secondAbilitySelect = LoadImage("resources\\Ability_2.png");
Image thirdAbilitySelect = LoadImage("resources\\Ability_3.png");
Image fourthAbilitySelect = LoadImage("resources\\Ability_4.png");
Image mEnemyIdle = LoadImage("resources\\mushroomIdle.png");
Image mEnemyHit = LoadImage("resources\\mushroomHit.png");
Image characterIdle = LoadImage("resources\\characterIdle.png");
Image characterDead = LoadImage("resources\\charDead.png");
Image characterCastFire = LoadImage("resources\\charSpellFire.png");
Image characterSwingFire = LoadImage("resources\\charSwingFire.png");
Image fireSpell = LoadImage("resources\\fireSpell.png");
Image characterCastWater = LoadImage("resources\\charSpellWater.png");
Image characterSwingWater = LoadImage("resources\\charSwingWater.png");
Image waterSpell = LoadImage("resources\\waterSpell.png");
Image BattleBoxOne = LoadImage("resources\\BattleBox1.png");
Image BattleBoxTwo = LoadImage("resources\\BattleBox2.png");
Image BattleBoxThree = LoadImage("resources\\BattleBox3.png");
Image healthF = LoadImage("resources\\healthFull.png");
Image health_75 = LoadImage("resources\\health75.png");
Image healthH = LoadImage("resources\\healthHalf.png");
Image health_25 = LoadImage("resources\\health25.png");
Image health_12 = LoadImage("resources\\health12.png");
Image health_0 = LoadImage("resources\\health0.png");
Image mushroomSwing = LoadImage("resources\\mushroomSwing.png");
Image mushroomCast = LoadImage("resources\\mushroomCast.png");
Image greenMagic = LoadImage("resources\\greenMagic.png");
Image characterHit = LoadImage("resources\\characterHit.png");
Image mushroomDead = LoadImage("resources\\mushroomDead.png");
Image winAbility1 = LoadImage("resources\\winAbility1.png");
Image winAbility2 = LoadImage("resources\\winAbility2.png");
Image winAbility3 = LoadImage("resources\\winAbility3.png");
Image winAbility4 = LoadImage("resources\\winAbility4.png");
Image winAbility5 = LoadImage("resources\\winAbility5.png");
Image goblinIdle = LoadImage("resources\\gIdle.png");
Image goblinHit = LoadImage("resources\\gHit.png");
Image goblinAtk2 = LoadImage("resources\\gAttack.png");
Image goblinDed = LoadImage("resources\\gDead.png");
Image goblinAtk1 = LoadImage("resources\\gSwing.png");
Image slash1 = LoadImage("resources\\windSlashattack.png");
Image skeletonIdle = LoadImage("resources\\skeletonIdle.png");
Image skeletonSwing = LoadImage("resources\\skeletonSwing.png");
Image skeletonAttack = LoadImage("resources\\skeletonAttack.png");
Image skeletonHit = LoadImage("resources\\skeletonHit.png");
Image skeletonDead = LoadImage("resources\\skeletonDeath.png");
Image textBox = LoadImage("resources\\questionTextBox.png");
Vector2 magicPosition;
Vector2 mPositionTemp = magicPosition;
bool isPlayersTurn = true;
bool isInMM = true; // check if player is in main menu
bool isInOptions = false; // check if player is in options
bool isInLVLSelect = false; // check if player is in level select
bool isInFirstLevel = false; // check if player is in first level
bool isInSecondLevel = false; // check if player is in second level
bool isInThirdLevel = false; // check if player is in third level

int hasBeatenBattle = false;

void mainMenu(Texture2D menuBG, Texture2D menuGUI) { // Switch to Main Menu Function
    BeginDrawing();
    ClearBackground(LIGHTGRAY);
    DrawTexture(menuBG, 0, 0, WHITE);
    DrawTexture(menuGUI, GetScreenWidth() / 3, GetScreenHeight() / 4.8, WHITE);
    DrawText("Start A New Game", 1130, 425, 40, BLACK);
    DrawText("Options", 1210, 535, 50, BLACK);
    DrawText("Exit", 1260, 650, 50, BLACK);
    DrawText("Welcome", 250, 350, 150, DARKBLUE);
    DrawText("To", 450, 500, 130, DARKBLUE);
    DrawText("Binarnia", 250, 600, 150, DARKBLUE);
    EndDrawing();
}
void selectLevel(Texture2D menuBG, Texture2D menuGUI) // Switch to Select Level Menu Function
{
    BeginDrawing();
    DrawTexture(menuBG, 0, 0, WHITE);
    DrawTexture(menuGUI, GetScreenWidth() / 9, GetScreenHeight() / 6, WHITE);
    ClearBackground(GREEN);
    DrawText("Select A Level:", 750, 150, 60, BLACK);
    DrawText("1", GetScreenWidth() / 2.64, GetScreenHeight() / 2.12, 60, BLACK);
    DrawText("2", GetScreenWidth() / 2.02, GetScreenHeight() / 2.12, 60, BLACK);
    DrawText("3", GetScreenWidth() / 1.63, GetScreenHeight() / 2.12, 60, BLACK);
    EndDrawing();
}

void optionsMenu(Texture2D menuBG, Texture2D menuGUI) { // Switch to Options Menu Function

    BeginDrawing();
    DrawTexture(menuBG, 0, 0, WHITE);
    DrawTexture(menuGUI, GetScreenWidth() / 8, GetScreenHeight() / 3.5, WHITE);
    DrawText("Options Menu:", GetScreenWidth() / 2.55, GetScreenHeight() / 5, 60, WHITE);
    DrawText("Toggle FullScreen", GetScreenWidth() / 2.5, GetScreenHeight() / 2.55, 40, BLACK);
    DrawText("Get GitHub Repo Link", GetScreenWidth() / 2.5, GetScreenHeight() / 2, 38, BLACK);
    DrawText("Credits", GetScreenWidth() / 2.2, GetScreenHeight() / 1.65, 45, BLACK);
    DrawText("Back to Menu", GetScreenWidth() / 2.35, GetScreenHeight() / 1.4, 40, BLACK);
    EndDrawing();
}
void creditScreen() // Switch to credit screen function
{
    bool credits = true;
    while (credits) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Scrum Trainer - Iva Nedkova", GetScreenWidth() / 4, GetScreenHeight() / 3, 30, WHITE);
        DrawText("QA Engineer - Valentin Pendashev", GetScreenWidth() / 4, GetScreenHeight() / 2.7, 30, WHITE);
        DrawText("Front End development - Bojidar Dukov/Todor Ivanov", GetScreenWidth() / 4, GetScreenHeight() / 2.4, 30, WHITE);
        DrawText("Back End development - Bojidar Dukov/Todor Ivanov", GetScreenWidth() / 4, GetScreenHeight() / 2.1, 30, WHITE);
        DrawText("Menu/Level Backgrounds - @pixilpokko (pixilart.com)", GetScreenWidth() / 4, GetScreenHeight() / 1.9, 30, WHITE);
        DrawText("Monster Enemies - @LuizMelo (itch.io)", GetScreenWidth() / 4, GetScreenHeight() / 1.7, 30, WHITE);
        DrawText("Press Any Key To Exit Credits", GetScreenWidth() / 4, GetScreenHeight() / 1.15, 30, WHITE);
        EndDrawing();
        if (GetKeyPressed())
        {
            credits = false;
        }
    }

}
void StartLevel(Texture2D menuBG, Texture2D ability, Texture2D character, Texture2D enemy, Texture2D pHealth, Texture2D eHealth, Texture2D BattleBox)
{

    BeginDrawing();
    DrawTexture(menuBG, 0, 0, WHITE);
    if (isInFirstLevel) DrawText("Level 1", GetScreenWidth() / 2.2, GetScreenHeight() / 10, 70, WHITE);
    if (isInSecondLevel) DrawText("Level 2", GetScreenWidth() / 2.2, GetScreenHeight() / 10, 70, WHITE);
    if (isInThirdLevel) DrawText("Level 3", GetScreenWidth() / 2.2, GetScreenHeight() / 10, 70, WHITE);

    if (isPlayersTurn)
    {
        DrawText("Turn: Player", GetScreenWidth() / 12, GetScreenHeight() / 10, 70, GREEN);
    }
    else {
        DrawText("Turn: Enemy", GetScreenWidth() / 12, GetScreenHeight() / 10, 70, RED);
    }
    DrawTexture(ability, GetScreenWidth() / 15, GetScreenHeight() / 4, WHITE);
    DrawTexture(character, GetScreenWidth() / 4, GetScreenHeight() / 2, WHITE);
    DrawTexture(enemy, GetScreenWidth() / 1.4, GetScreenHeight() / 2, WHITE);
    DrawTexture(pHealth, GetScreenWidth() / 4.4, GetScreenHeight() / 2.2, WHITE);
    DrawTexture(eHealth, GetScreenWidth() / 1.45, GetScreenHeight() / 2.15, WHITE);
    DrawTexture(BattleBox, GetScreenWidth() / 1.5, GetScreenHeight() / 15, WHITE);
    DrawText("1", GetScreenWidth() / 1.45, GetScreenHeight() / 10, 60, BLACK);
    DrawText("2", GetScreenWidth() / 1.29, GetScreenHeight() / 10, 60, BLACK);
    DrawText("3", GetScreenWidth() / 1.16, GetScreenHeight() / 10, 60, BLACK);
    DrawText("Back To Menu", GetScreenWidth() / 1.68, GetScreenHeight() / 1.12, 40, BLACK);
    switch (hasBeatenBattle)
    {
    case 1:DrawText("Next Battle", GetScreenWidth() / 1.68 - 320, GetScreenHeight() / 1.12, 40, BLACK); break;
    case 2:DrawText("Next Level", GetScreenWidth() / 1.68 - 320, GetScreenHeight() / 1.12, 40, BLACK); break;
    default: break;
    }
    ClearBackground(GREEN);
    EndDrawing();
}

void castMagic(Texture2D menuBG, Texture2D ability, Texture2D character, Texture2D enemy, Texture2D magic, Texture2D pHealth, Texture2D eHealth, Texture2D BattleBox)
{

    BeginDrawing();
    DrawTexture(menuBG, 0, 0, WHITE);
    if (isInFirstLevel) DrawText("Level 1", GetScreenWidth() / 2.2, GetScreenHeight() / 10, 70, WHITE);
    if (isInSecondLevel) DrawText("Level 2", GetScreenWidth() / 2.2, GetScreenHeight() / 10, 70, WHITE);
    if (isInThirdLevel) DrawText("Level 3", GetScreenWidth() / 2.2, GetScreenHeight() / 10, 70, WHITE);
    if (isPlayersTurn)
    {
        DrawText("Turn: Player", GetScreenWidth() / 12, GetScreenHeight() / 10, 70, GREEN);
    }
    else {
        DrawText("Turn: Enemy", GetScreenWidth() / 12, GetScreenHeight() / 10, 70, RED);
    }
    DrawTexture(BattleBox, GetScreenWidth() / 1.5, GetScreenHeight() / 15, WHITE);
    DrawTexture(ability, GetScreenWidth() / 15, GetScreenHeight() / 4, WHITE);
    DrawTexture(character, GetScreenWidth() / 4, GetScreenHeight() / 2, WHITE);
    DrawTexture(enemy, GetScreenWidth() / 1.4, GetScreenHeight() / 2, WHITE);
    DrawTexture(pHealth, GetScreenWidth() / 4.4, GetScreenHeight() / 2.2, WHITE);
    DrawTexture(eHealth, GetScreenWidth() / 1.45, GetScreenHeight() / 2.15, WHITE);
    DrawText("1", GetScreenWidth() / 1.45, GetScreenHeight() / 10, 60, BLACK);
    DrawText("2", GetScreenWidth() / 1.29, GetScreenHeight() / 10, 60, BLACK);
    DrawText("3", GetScreenWidth() / 1.16, GetScreenHeight() / 10, 60, BLACK);
    DrawText("Back To Menu", GetScreenWidth() / 1.68, GetScreenHeight() / 1.12, 40, BLACK);
    DrawTextureV(magic, magicPosition, WHITE);
    EndDrawing();
}
bool binaryCalculations(Texture2D menuBG, Texture2D ability, Texture2D character, Texture2D enemy, Texture2D pHealth, Texture2D eHealth, Texture2D BattleBox, Texture2D tBox)
{
    BeginDrawing();
    DrawTexture(menuBG, 0, 0, WHITE);
    DrawText("Level 1", GetScreenWidth() / 2.2, GetScreenHeight() / 10, 70, WHITE);
    if (isPlayersTurn)
    {
        DrawText("Turn: Player", GetScreenWidth() / 12, GetScreenHeight() / 10, 70, GREEN);
    }
    else {
        DrawText("Turn: Enemy", GetScreenWidth() / 12, GetScreenHeight() / 10, 70, RED);
    }
    DrawTexture(ability, GetScreenWidth() / 15, GetScreenHeight() / 4, WHITE);
    DrawTexture(character, GetScreenWidth() / 4, GetScreenHeight() / 2, WHITE);
    DrawTexture(enemy, GetScreenWidth() / 1.4, GetScreenHeight() / 2, WHITE);
    DrawTexture(pHealth, GetScreenWidth() / 4.4, GetScreenHeight() / 2.2, WHITE);
    DrawTexture(eHealth, GetScreenWidth() / 1.45, GetScreenHeight() / 2.15, WHITE);
    DrawTexture(BattleBox, GetScreenWidth() / 1.5, GetScreenHeight() / 15, WHITE);
    DrawText("1", GetScreenWidth() / 1.45, GetScreenHeight() / 10, 60, BLACK);
    DrawText("2", GetScreenWidth() / 1.29, GetScreenHeight() / 10, 60, BLACK);
    DrawText("3", GetScreenWidth() / 1.16, GetScreenHeight() / 10, 60, BLACK);
    DrawText("Back To Menu", GetScreenWidth() / 1.68, GetScreenHeight() / 1.12, 40, BLACK);
    switch (hasBeatenBattle)
    {
    case 1:DrawText("Next Battle", GetScreenWidth() / 1.68 - 320, GetScreenHeight() / 1.12, 40, BLACK); break;
    case 2:DrawText("Next Level", GetScreenWidth() / 1.68 - 320, GetScreenHeight() / 1.12, 40, BLACK); break;
    default: break;
    }
    DrawTexture(BattleBox, GetScreenWidth() / 1.5, GetScreenHeight() / 15, WHITE);
    DrawTexture(tBox, GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 200, WHITE);
    string binary = std::bitset<8>(128).to_string(); //to binary
    cout << binary << "\n";
    srand(time(NULL));
    unsigned long decimal = std::bitset<8>(binary).to_ulong(); //to int
    cout << decimal << "\n";

    srand(time(NULL));
    long int num[3] = { rand() % 128, rand() % 128 }, randomNum[2] = { rand() % 3 + 1 , rand() % 3 + 1 };
    float percent = 0;
    bitset<8> answer;
    char sign = '0';
    switch (randomNum[0])
    {
    case 1: num[2] = num[0] | num[1]; sign = '|'; break;
    case 2: num[2] = num[0] & num[1]; sign = '&'; break;
    case 3: num[2] = num[0] ^ num[1]; sign = '^'; break;
    default: break;
    }
    cout << bitset<8>(num[0]) << ' ' << sign << ' ' << bitset<8>(num[1]) << " = ????????";
    cout << "\nThe Missing Number Is?\n";
    cin >> answer;
    if (answer == bitset<8>(num[2]))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    ClearBackground(GREEN);
    EndDrawing();
}
bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}



int main()
{
    InitWindow(currentWidth, currentHeight, "First Game");
    int menuState = 0;
    int enemyHealthCounter = 0;
    int playerHealthCounter = 0;
    int battleCounter = 0;
    SetTargetFPS(100);
    ImageResize(&BG, 1920, 1080);
    ImageResize(&characterHit, 120, 220);
    ImageResize(&characterIdle, 120, 220);
    ImageResize(&characterCastFire, 144, 226);
    ImageResize(&healthF, 230, 45);
    ImageResize(&health_75, 230, 45);
    ImageResize(&healthH, 230, 45);
    ImageResize(&mushroomSwing, 144, 226);
    ImageResize(&mushroomCast, 144, 226);
    ImageResize(&health_25, 230, 45);
    ImageResize(&health_12, 230, 45);
    ImageResize(&health_0, 230, 45);
    ImageResize(&characterSwingFire, 200, 226);
    ImageResize(&winAbility1, 1416, 779);
    ImageResize(&winAbility2, 1416, 779);
    ImageResize(&winAbility3, 1416, 779);
    ImageResize(&winAbility4, 1416, 779);
    ImageResize(&winAbility5, 1416, 779);
    ImageResize(&firstLevelBG, 1920, 1080);
    ImageResize(&characterSwingWater, 200, 226);
    ImageResize(&characterCastWater, 144, 226);
    ImageResize(&goblinIdle, 144, 226);
    ImageResize(&goblinAtk1, 144, 226);
    ImageResize(&goblinAtk2, 300, 232);
    ImageResize(&goblinHit, 144, 226);
    ImageResize(&goblinDed, 200, 300);
    ImageResize(&skeletonIdle, 144, 226);
    ImageResize(&skeletonAttack, 144, 226);
    ImageResize(&skeletonSwing, 200, 232);
    ImageResize(&skeletonHit, 144, 226);
    ImageResize(&skeletonDead, 200, 300);
    bool eDead = 0;
    Texture2D mainBG = LoadTextureFromImage(BG);
    Texture2D menuSelect1 = LoadTextureFromImage(mainMenuGui1);
    Texture2D menuSelect2 = LoadTextureFromImage(mainMenuGui2);
    Texture2D menuSelect3 = LoadTextureFromImage(mainMenuGui3);
    Texture2D lvlSelect1 = LoadTextureFromImage(lvlBoxes1);
    Texture2D lvlSelect2 = LoadTextureFromImage(lvlBoxes2);                // Loading Textures in Main Function
    Texture2D lvlSelect3 = LoadTextureFromImage(lvlBoxes3);
    Texture2D optionSelect1 = LoadTextureFromImage(optionsGui1);
    Texture2D optionSelect2 = LoadTextureFromImage(optionsGui2);
    Texture2D optionSelect4 = LoadTextureFromImage(optionsGui4);
    Texture2D optionSelect3 = LoadTextureFromImage(optionsGui3);
    Texture2D firstLvlBG = LoadTextureFromImage(firstLevelBG);
    Texture2D abilityOne = LoadTextureFromImage(firstAbilitySelect);
    Texture2D abilityTwo = LoadTextureFromImage(secondAbilitySelect);
    Texture2D abilityThree = LoadTextureFromImage(thirdAbilitySelect);
    Texture2D abilityFour = LoadTextureFromImage(fourthAbilitySelect);
    Texture2D mushroomEnemyIdle = LoadTextureFromImage(mEnemyIdle);
    Texture2D mushroomEnemyHit = LoadTextureFromImage(mEnemyHit);
    Texture2D charIdle = LoadTextureFromImage(characterIdle);
    Texture2D charDead = LoadTextureFromImage(characterDead);
    Texture2D charCastFire = LoadTextureFromImage(characterCastFire);
    Texture2D charSwingFire = LoadTextureFromImage(characterSwingFire);
    Texture2D fSpell = LoadTextureFromImage(fireSpell);
    Texture2D battleBox1 = LoadTextureFromImage(BattleBoxOne);
    Texture2D battleBox2 = LoadTextureFromImage(BattleBoxTwo);
    Texture2D battleBox3 = LoadTextureFromImage(BattleBoxThree);
    Texture2D healthFull = LoadTextureFromImage(healthF);
    Texture2D health75 = LoadTextureFromImage(health_75);
    Texture2D healthHalf = LoadTextureFromImage(healthH);
    Texture2D health25 = LoadTextureFromImage(health_25);
    Texture2D health12 = LoadTextureFromImage(health_12);
    Texture2D health0 = LoadTextureFromImage(health_0);
    Texture2D mSwing = LoadTextureFromImage(mushroomSwing);
    Texture2D mCast = LoadTextureFromImage(mushroomCast);
    Texture2D gSpell = LoadTextureFromImage(greenMagic);
    Texture2D cHit = LoadTextureFromImage(characterHit);
    Texture2D mDead = LoadTextureFromImage(mushroomDead);
    Texture2D wAbility1 = LoadTextureFromImage(winAbility1);
    Texture2D wAbility2 = LoadTextureFromImage(winAbility2);
    Texture2D wAbility3 = LoadTextureFromImage(winAbility3);
    Texture2D wAbility4 = LoadTextureFromImage(winAbility4);
    Texture2D wAbility5 = LoadTextureFromImage(winAbility5);
    Texture2D charCastWater = LoadTextureFromImage(characterCastWater);
    Texture2D charSwingWater = LoadTextureFromImage(characterSwingWater);
    Texture2D wSpell = LoadTextureFromImage(waterSpell);
    Texture2D gIdle = LoadTextureFromImage(goblinIdle);
    Texture2D gAtk1 = LoadTextureFromImage(goblinAtk1);
    Texture2D gAtk2 = LoadTextureFromImage(goblinAtk2);
    Texture2D gHit = LoadTextureFromImage(goblinHit);
    Texture2D gDead = LoadTextureFromImage(goblinDed);
    Texture2D slash = LoadTextureFromImage(slash1);
    Texture2D sIdle = LoadTextureFromImage(skeletonIdle);
    Texture2D sAtk1 = LoadTextureFromImage(skeletonSwing);
    Texture2D sAtk2 = LoadTextureFromImage(skeletonAttack);
    Texture2D sHit = LoadTextureFromImage(skeletonHit);
    Texture2D sDead = LoadTextureFromImage(skeletonDead);
    Texture2D tBox = LoadTextureFromImage(textBox);
    Texture2D playerCurrentHealth = healthFull;
    Texture2D enemyCurrentHealth = healthFull;
    Texture2D currentBattle = battleBox1;
    Texture2D currentAbility;



    while (!WindowShouldClose()) // Game loop
    {
        if (isInMM) {

            switch (menuState) // Menu Switch Statement
            {
            case 0: mainMenu(mainBG, menuSelect1); break;
            case 1: mainMenu(mainBG, menuSelect2); break;
            case 2: mainMenu(mainBG, menuSelect3); break;
            }

            switch (GetKeyPressed()) //Main Menu Navigation
            {
            case KEY_UP: if (menuState == 0) menuState = 2; else menuState--; break;
            case KEY_DOWN:  if (menuState == 2) menuState = 0; else menuState++; break;
            }

            if (IsKeyPressed(KEY_ENTER)) // Menu Button Select Check
            {

                isInMM = false;
                switch (menuState)
                {
                case 0: selectLevel(mainBG, lvlSelect1); isInLVLSelect = true; menuState = 0; break;
                case 1: optionsMenu(mainBG, optionSelect1); isInOptions = true; menuState = 0; break;
                case 2: CloseWindow();
                }
            }

        }
        if (isInOptions) {  // Options Menu

            switch (menuState)
            {
            case 0: optionsMenu(mainBG, optionSelect1); break;
            case 1: optionsMenu(mainBG, optionSelect2); break;
            case 2: optionsMenu(mainBG, optionSelect3); break;
            case 3: optionsMenu(mainBG, optionSelect4); break;
            case 4: isInOptions = false; isInMM = true;  mainMenu(mainBG, menuSelect1); menuState = 0; break;
            }

            switch (GetKeyPressed()) //Options Menu Navigation
            {
            case KEY_UP: if (menuState == 0) menuState = 3; else menuState--; break;
            case KEY_DOWN:  if (menuState == 3) menuState = 0; else menuState++; break;
            }

            if (IsKeyPressed(KEY_ENTER)) // Options Button Select Check
            {
                isInMM = false;
                switch (menuState)
                {
                case 0: ToggleFullscreen(); break;
                case 1: SetClipboardText("https://github.com/codingburgas/2223-9th-grade-sprint-math-games-team-one"); break;
                case 2: creditScreen(); break;
                case 3: isInOptions = false; isInMM = true;  mainMenu(mainBG, menuSelect1); menuState = 0; break;
                }
            }

        }
        if (isInLVLSelect)
        {

            switch (menuState)
            {
            case 0: selectLevel(mainBG, lvlSelect1); break;
            case 1: selectLevel(mainBG, lvlSelect2); break;
            case 2: selectLevel(mainBG, lvlSelect3); break;
            }

            switch (GetKeyPressed()) //Level Select Navigation
            {
            case KEY_LEFT: if (menuState == 0) menuState = 2; else menuState--; break;
            case KEY_RIGHT:  if (menuState == 2) menuState = 0; else menuState++; break;
            }

            if (IsKeyPressed(KEY_ENTER)) // Level Select
            {
                switch (menuState)
                {
                case 0: isInLVLSelect = false; isInFirstLevel = true; StartLevel(firstLvlBG, abilityOne, charIdle, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                case 1: isInLVLSelect = false; isInSecondLevel = true; StartLevel(firstLvlBG, abilityOne, charIdle, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                case 2: isInLVLSelect = false; isInThirdLevel = true; StartLevel(firstLvlBG, abilityOne, charIdle, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                }
                menuState = 0;
            }

        }
        if (isInFirstLevel) // First Level
        {
            switch (playerHealthCounter) // health switch when damaged
            {
            case 0: playerCurrentHealth = healthFull; break;
            case 1: playerCurrentHealth = health75; break;
            case 2: playerCurrentHealth = healthHalf; break;
            case 3: playerCurrentHealth = health25; break;
            case 4: playerCurrentHealth = health0; break;
            }
            switch (enemyHealthCounter)
            {
            case 0: enemyCurrentHealth = healthFull; break;
            case 1: enemyCurrentHealth = health75; break;
            case 2: enemyCurrentHealth = healthHalf; break;
            case 3: enemyCurrentHealth = health25; break;
            case 4: enemyCurrentHealth = health0; break;
            }
            switch (battleCounter)
            {
            case 0: currentBattle = battleBox1; break;
            case 1: currentBattle = battleBox2; break;
            case 2: currentBattle = battleBox3; break;
            }

            if (isPlayersTurn)
            {
                switch (menuState)
                {
                case 0: currentAbility = abilityOne;  StartLevel(firstLvlBG, currentAbility, charIdle, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                case 1: currentAbility = abilityTwo;  StartLevel(firstLvlBG, currentAbility, charIdle, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                case 2: currentAbility = abilityThree;  StartLevel(firstLvlBG, currentAbility, charIdle, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                case 3: currentAbility = abilityFour;  StartLevel(firstLvlBG, currentAbility, charIdle, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                }
                switch (GetKeyPressed()) //Spell Navigation
                {
                case KEY_LEFT: if (menuState == 0) menuState = 3; else menuState--; break;
                case KEY_RIGHT:  if (menuState == 3) menuState = 0; else menuState++; break;
                }
                if (IsKeyPressed(KEY_ENTER))
                {
                    switch (menuState)
                    {
                    case 0: WaitTime(0.1); //FIRE SPELL
                        magicPosition.x = (GetScreenWidth() / 3.5);
                        magicPosition.y = GetScreenHeight() / 2;
                        StartLevel(firstLvlBG, currentAbility, charCastFire, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                        if (binaryCalculations(firstLvlBG, currentAbility, charCastFire, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle, tBox))
                        {
                            StartLevel(firstLvlBG, currentAbility, charSwingFire, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                            while (magicPosition.x < (GetScreenWidth()) / 1.5)
                            {

                                magicPosition.x += (0.0125 * GetScreenWidth()); // magic movement while loop
                                WaitTime(0.025);
                                castMagic(firstLvlBG, currentAbility, charSwingFire, mushroomEnemyIdle, fSpell, playerCurrentHealth, enemyCurrentHealth, currentBattle);

                            }
                            enemyHealthCounter++;
                            StartLevel(firstLvlBG, currentAbility, charIdle, mushroomEnemyHit, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                            switch (enemyHealthCounter)
                            {
                            case 0: enemyCurrentHealth = healthFull; break;
                            case 1: enemyCurrentHealth = health75; break;
                            case 2: enemyCurrentHealth = healthHalf; break;
                            case 3: enemyCurrentHealth = health25; break;
                            case 4: enemyCurrentHealth = health0; break;
                            }
                            StartLevel(firstLvlBG, currentAbility, charIdle, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                            magicPosition = mPositionTemp;
                        } isPlayersTurn = false; break;
                    case 1:  // WATER SPELL
                        WaitTime(0.1);
                        magicPosition.x = (GetScreenWidth() / 3.5);
                        magicPosition.y = GetScreenHeight() / 2;
                        StartLevel(firstLvlBG, currentAbility, charCastWater, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                        WaitTime(0.2);

                        StartLevel(firstLvlBG, currentAbility, charCastWater, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                        if (binaryCalculations(firstLvlBG, currentAbility, charCastWater, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle, tBox))
                        {
                            StartLevel(firstLvlBG, currentAbility, charSwingWater, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                            while (magicPosition.x < (GetScreenWidth()) / 1.5)
                            {

                                magicPosition.x += (0.0125 * GetScreenWidth()); // magic movement while loop
                                WaitTime(0.025);
                                castMagic(firstLvlBG, currentAbility, charSwingWater, mushroomEnemyIdle, wSpell, playerCurrentHealth, enemyCurrentHealth, currentBattle);

                            }
                            StartLevel(firstLvlBG, currentAbility, charIdle, mushroomEnemyHit, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                            enemyHealthCounter++;
                            switch (enemyHealthCounter)
                            {
                            case 0: enemyCurrentHealth = healthFull; break;
                            case 1: enemyCurrentHealth = health75; break;
                            case 2: enemyCurrentHealth = healthHalf; break;
                            case 3: enemyCurrentHealth = health25; break;
                            case 4: enemyCurrentHealth = health0; break;
                            }
                            StartLevel(firstLvlBG, currentAbility, charIdle, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                            magicPosition = mPositionTemp;
                        } isPlayersTurn = false; break;
                    case 2: if (binaryCalculations(firstLvlBG, currentAbility, charIdle, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle, tBox))
                    {
                        playerHealthCounter -= 2;
                    }
                          switch (playerHealthCounter) // health switch when damaged
                          {
                          case 0: playerCurrentHealth = healthFull; break;
                          case 1: playerCurrentHealth = health75; break;
                          case 2: playerCurrentHealth = healthHalf; break;
                          case 3: playerCurrentHealth = health25; break;
                          case 4: playerCurrentHealth = health0; break;
                          }
                          isPlayersTurn = false;
                          break;
                    case 3: isInFirstLevel = false; menuState = 0; mainMenu(mainBG, menuSelect1); isInMM = true; enemyHealthCounter = 0; playerHealthCounter = 0; battleCounter = 0; break;
                    }
                }
            }
            else
            {
                if (enemyHealthCounter < 4) { //Monster Spell
                    WaitTime(1);
                    magicPosition.x = (GetScreenWidth() / 1.55);
                    magicPosition.y = GetScreenHeight() / 2;
                    StartLevel(firstLvlBG, currentAbility, charIdle, mSwing, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                    WaitTime(0.2);
                    StartLevel(firstLvlBG, currentAbility, charIdle, mCast, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                    WaitTime(0.1);
                    while (magicPosition.x > (GetScreenWidth()) / 4)
                    {

                        magicPosition.x -= (0.0125 * GetScreenWidth()); // magic movement while loop
                        WaitTime(0.025);
                        castMagic(firstLvlBG, currentAbility, charIdle, mushroomEnemyIdle, gSpell, playerCurrentHealth, enemyCurrentHealth, currentBattle);

                    }
                    StartLevel(firstLvlBG, currentAbility, cHit, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                    playerHealthCounter++;
                    if (playerHealthCounter == 4)
                    {
                        while (isInFirstLevel)
                        {

                            switch (playerHealthCounter) // health switch when damaged
                            {
                            case 0: playerCurrentHealth = healthFull; break;
                            case 1: playerCurrentHealth = health75; break;
                            case 2: playerCurrentHealth = healthHalf; break;
                            case 3: playerCurrentHealth = health25; break;
                            case 4: playerCurrentHealth = health0; break;
                            }
                            switch (menuState)
                            {
                            case 0: currentAbility = abilityOne;  StartLevel(firstLvlBG, currentAbility, charDead, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                            case 1: currentAbility = abilityTwo;  StartLevel(firstLvlBG, currentAbility, charDead, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                            case 2: currentAbility = abilityThree;  StartLevel(firstLvlBG, currentAbility, charDead, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                            case 3: currentAbility = abilityFour;  StartLevel(firstLvlBG, currentAbility, charDead, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                            }
                            switch (GetKeyPressed()) //Spell Navigation
                            {
                            case KEY_LEFT: if (menuState == 0) menuState = 3;  else menuState--; break;
                            case KEY_RIGHT:  if (menuState == 3) menuState = 0;  else menuState++; break;
                            }
                            if (IsKeyPressed(KEY_ENTER))
                            {
                                switch (menuState)
                                {
                                case 3: isInFirstLevel = false; menuState = 0; mainMenu(mainBG, menuSelect1); isInMM = true; playerHealthCounter = 0; battleCounter = 0; isPlayersTurn = true;  break;
                                }
                            }
                        }
                    }
                    else
                    {
                        StartLevel(firstLvlBG, currentAbility, charIdle, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                    }


                }
                else
                {
                    hasBeatenBattle = true;
                    if (battleCounter >= 2)
                    {
                        hasBeatenBattle = 2;
                    }
                    enemyHealthCounter = 0;
                    while (!isPlayersTurn)
                    {
                        switch (menuState)
                        {
                        case 0: currentAbility = wAbility1;  StartLevel(firstLvlBG, currentAbility, charIdle, mDead, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                        case 1: currentAbility = wAbility2;  StartLevel(firstLvlBG, currentAbility, charIdle, mDead, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                        case 2: currentAbility = wAbility3;  StartLevel(firstLvlBG, currentAbility, charIdle, mDead, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                        case 3: currentAbility = wAbility4;  StartLevel(firstLvlBG, currentAbility, charIdle, mDead, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                        case 4: currentAbility = wAbility5;  StartLevel(firstLvlBG, currentAbility, charIdle, mDead, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                        }
                        switch (GetKeyPressed()) //Spell Navigation
                        {
                        case KEY_LEFT: if (menuState == 0) menuState = 4;  else menuState--; break;
                        case KEY_RIGHT:  if (menuState == 4) menuState = 0;  else menuState++; break;
                        }
                        if (IsKeyPressed(KEY_ENTER))
                        {
                            switch (menuState)
                            {
                            case 3: battleCounter++; menuState = 0;  isPlayersTurn = true; break;
                            case 4: isInFirstLevel = false; menuState = 0; mainMenu(mainBG, menuSelect1); isInMM = true; playerHealthCounter = 0; battleCounter = 0; isPlayersTurn = true;  break;
                            }
                        }
                    }
                    hasBeatenBattle = false;
                }
                isPlayersTurn = true;
            }
        }
        if (isInSecondLevel) // Second Level
        {
            switch (playerHealthCounter) // health switch when damaged
            {
            case 0: playerCurrentHealth = healthFull; break;
            case 1: playerCurrentHealth = health75; break;
            case 2: playerCurrentHealth = healthHalf; break;
            case 3: playerCurrentHealth = health25; break;
            case 4: playerCurrentHealth = health0; break;
            }
            switch (enemyHealthCounter)
            {
            case 0: enemyCurrentHealth = healthFull; break;
            case 1: enemyCurrentHealth = health75; break;
            case 2: enemyCurrentHealth = healthHalf; break;
            case 3: enemyCurrentHealth = health25; break;
            case 4: enemyCurrentHealth = health0; break;
            }
            switch (battleCounter)
            {
            case 0: currentBattle = battleBox1; break;
            case 1: currentBattle = battleBox2; break;
            case 2: currentBattle = battleBox3; break;
            }

            if (isPlayersTurn)
            {
                switch (menuState)
                {
                case 0: currentAbility = abilityOne;  StartLevel(firstLvlBG, currentAbility, charIdle, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                case 1: currentAbility = abilityTwo;  StartLevel(firstLvlBG, currentAbility, charIdle, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                case 2: currentAbility = abilityThree;  StartLevel(firstLvlBG, currentAbility, charIdle, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                case 3: currentAbility = abilityFour;  StartLevel(firstLvlBG, currentAbility, charIdle, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                }
                switch (GetKeyPressed()) //Spell Navigation
                {
                case KEY_LEFT: if (menuState == 0) menuState = 3; else menuState--; break;
                case KEY_RIGHT:  if (menuState == 3) menuState = 0; else menuState++; break;
                }
                if (IsKeyPressed(KEY_ENTER))
                {
                    switch (menuState)
                    {
                    case 0: WaitTime(0.1); //FIRE SPELL
                        magicPosition.x = (GetScreenWidth() / 3.5);
                        magicPosition.y = GetScreenHeight() / 2;
                        StartLevel(firstLvlBG, currentAbility, charCastFire, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                        WaitTime(0.2);

                        if (binaryCalculations(firstLvlBG, currentAbility, charCastFire, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle, tBox))
                        {
                            StartLevel(firstLvlBG, currentAbility, charSwingFire, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                            while (magicPosition.x < (GetScreenWidth()) / 1.5)
                            {

                                magicPosition.x += (0.0125 * GetScreenWidth()); // magic movement while loop
                                WaitTime(0.025);
                                castMagic(firstLvlBG, currentAbility, charSwingFire, gIdle, fSpell, playerCurrentHealth, enemyCurrentHealth, currentBattle);

                            }
                            enemyHealthCounter++;
                            StartLevel(firstLvlBG, currentAbility, charIdle, gHit, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                            switch (enemyHealthCounter)
                            {
                            case 0: enemyCurrentHealth = healthFull; break;
                            case 1: enemyCurrentHealth = health75; break;
                            case 2: enemyCurrentHealth = healthHalf; break;
                            case 3: enemyCurrentHealth = health25; break;
                            case 4: enemyCurrentHealth = health0; break;
                            }
                            StartLevel(firstLvlBG, currentAbility, charIdle, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                            magicPosition = mPositionTemp;
                        } isPlayersTurn = false;  break;
                    case 1:  // WATER SPELL
                        WaitTime(0.1);
                        magicPosition.x = (GetScreenWidth() / 3.5);
                        magicPosition.y = GetScreenHeight() / 2;
                        StartLevel(firstLvlBG, currentAbility, charCastWater, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                        WaitTime(0.2);
                        if (binaryCalculations(firstLvlBG, currentAbility, charCastWater, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle, tBox))
                        {
                            StartLevel(firstLvlBG, currentAbility, charSwingWater, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                            while (magicPosition.x < (GetScreenWidth()) / 1.5)
                            {

                                magicPosition.x += (0.0125 * GetScreenWidth()); // magic movement while loop
                                WaitTime(0.025);
                                castMagic(firstLvlBG, currentAbility, charSwingWater, gIdle, wSpell, playerCurrentHealth, enemyCurrentHealth, currentBattle);

                            }
                            StartLevel(firstLvlBG, currentAbility, charIdle, gHit, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                            enemyHealthCounter++;
                            switch (enemyHealthCounter)
                            {
                            case 0: enemyCurrentHealth = healthFull; break;
                            case 1: enemyCurrentHealth = health75; break;
                            case 2: enemyCurrentHealth = healthHalf; break;
                            case 3: enemyCurrentHealth = health25; break;
                            case 4: enemyCurrentHealth = health0; break;
                            }
                            StartLevel(firstLvlBG, currentAbility, charIdle, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                            magicPosition = mPositionTemp;
                        }   isPlayersTurn = false; break;
                    case 2: if (binaryCalculations(firstLvlBG, currentAbility, charIdle, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle, tBox))
                    {
                        playerHealthCounter -= 2;
                    }
                          switch (playerHealthCounter) // health switch when damaged
                          {
                          case 0: playerCurrentHealth = healthFull; break;
                          case 1: playerCurrentHealth = health75; break;
                          case 2: playerCurrentHealth = healthHalf; break;
                          case 3: playerCurrentHealth = health25; break;
                          case 4: playerCurrentHealth = health0; break;
                          }
                          isPlayersTurn = false;
                          break;
                    case 3: isInSecondLevel = false; menuState = 0; mainMenu(mainBG, menuSelect1); isInMM = true; enemyHealthCounter = 0; playerHealthCounter = 0; battleCounter = 0; break;
                    }
                }
            }
            else
            {
                if (enemyHealthCounter < 4) { //Monster Spell
                    WaitTime(1);
                    magicPosition.x = (GetScreenWidth() / 1.55);
                    magicPosition.y = GetScreenHeight() / 2;
                    StartLevel(firstLvlBG, currentAbility, charIdle, gAtk1, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                    WaitTime(0.2);
                    StartLevel(firstLvlBG, currentAbility, charIdle, gAtk2, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                    WaitTime(0.1);
                    while (magicPosition.x > (GetScreenWidth()) / 4)
                    {

                        magicPosition.x -= (0.0125 * GetScreenWidth()); // magic movement while loop
                        WaitTime(0.025);
                        castMagic(firstLvlBG, currentAbility, charIdle, gIdle, slash, playerCurrentHealth, enemyCurrentHealth, currentBattle);

                    }
                    StartLevel(firstLvlBG, currentAbility, cHit, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                    playerHealthCounter++;
                    if (playerHealthCounter == 4)
                    {
                        while (isInSecondLevel)
                        {

                            switch (playerHealthCounter) // health switch when damaged
                            {
                            case 0: playerCurrentHealth = healthFull; break;
                            case 1: playerCurrentHealth = health75; break;
                            case 2: playerCurrentHealth = healthHalf; break;
                            case 3: playerCurrentHealth = health25; break;
                            case 4: playerCurrentHealth = health0; break;
                            }
                            switch (menuState)
                            {
                            case 0: currentAbility = abilityOne;  StartLevel(firstLvlBG, currentAbility, charDead, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                            case 1: currentAbility = abilityTwo;  StartLevel(firstLvlBG, currentAbility, charDead, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                            case 2: currentAbility = abilityThree;  StartLevel(firstLvlBG, currentAbility, charDead, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                            case 3: currentAbility = abilityFour;  StartLevel(firstLvlBG, currentAbility, charDead, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                            }
                            switch (GetKeyPressed()) //Spell Navigation
                            {
                            case KEY_LEFT: if (menuState == 0) menuState = 3;  else menuState--; break;
                            case KEY_RIGHT:  if (menuState == 3) menuState = 0;  else menuState++; break;
                            }
                            if (IsKeyPressed(KEY_ENTER))
                            {
                                switch (menuState)
                                {
                                case 3: isInSecondLevel = false; menuState = 0; mainMenu(mainBG, menuSelect1); isInMM = true; enemyHealthCounter = 0; playerHealthCounter = 0; battleCounter = 0; break;
                                }
                            }
                        }
                    }
                    else
                    {
                        StartLevel(firstLvlBG, currentAbility, charIdle, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                    }

                }
                else
                {
                    hasBeatenBattle = true;
                    if (battleCounter >= 2)
                    {
                        hasBeatenBattle = 2;
                    }
                    enemyHealthCounter = 0;
                    while (!isPlayersTurn)
                    {
                        switch (menuState)
                        {
                        case 0: currentAbility = wAbility1;  StartLevel(firstLvlBG, currentAbility, charIdle, gDead, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                        case 1: currentAbility = wAbility2;  StartLevel(firstLvlBG, currentAbility, charIdle, gDead, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                        case 2: currentAbility = wAbility3;  StartLevel(firstLvlBG, currentAbility, charIdle, gDead, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                        case 3: currentAbility = wAbility4;  StartLevel(firstLvlBG, currentAbility, charIdle, gDead, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                        case 4: currentAbility = wAbility5;  StartLevel(firstLvlBG, currentAbility, charIdle, gDead, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                        }
                        switch (GetKeyPressed()) //Spell Navigation
                        {
                        case KEY_LEFT: if (menuState == 0) menuState = 4;  else menuState--; break;
                        case KEY_RIGHT:  if (menuState == 4) menuState = 0;  else menuState++; break;
                        }
                        if (IsKeyPressed(KEY_ENTER))
                        {
                            switch (menuState)
                            {
                            case 3: battleCounter++; menuState = 0;  isPlayersTurn = true; break;
                            case 4: isInSecondLevel = false; menuState = 0; mainMenu(mainBG, menuSelect1); isInMM = true; playerHealthCounter = 0; battleCounter = 0; isPlayersTurn = true;  break;
                            }
                        }
                    }
                    hasBeatenBattle = false;
                }
                isPlayersTurn = true;
            }
        }
        if (isInThirdLevel) // Third Level
        {
            switch (playerHealthCounter) // health switch when damaged
            {
            case 0: playerCurrentHealth = healthFull; break;
            case 1: playerCurrentHealth = health75; break;
            case 2: playerCurrentHealth = healthHalf; break;
            case 3: playerCurrentHealth = health25; break;
            case 4: playerCurrentHealth = health0; break;
            }
            switch (enemyHealthCounter)
            {
            case 0: enemyCurrentHealth = healthFull; break;
            case 1: enemyCurrentHealth = health75; break;
            case 2: enemyCurrentHealth = healthHalf; break;
            case 3: enemyCurrentHealth = health25; break;
            case 4: enemyCurrentHealth = health0; break;
            }
            switch (battleCounter)
            {
            case 0: currentBattle = battleBox1; break;
            case 1: currentBattle = battleBox2; break;
            case 2: currentBattle = battleBox3; break;
            }

            if (isPlayersTurn)
            {
                switch (menuState)
                {
                case 0: currentAbility = abilityOne;  StartLevel(firstLvlBG, currentAbility, charIdle, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                case 1: currentAbility = abilityTwo;  StartLevel(firstLvlBG, currentAbility, charIdle, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                case 2: currentAbility = abilityThree;  StartLevel(firstLvlBG, currentAbility, charIdle, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                case 3: currentAbility = abilityFour;  StartLevel(firstLvlBG, currentAbility, charIdle, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                }
                switch (GetKeyPressed()) //Spell Navigation
                {
                case KEY_LEFT: if (menuState == 0) menuState = 3; else menuState--; break;
                case KEY_RIGHT:  if (menuState == 3) menuState = 0; else menuState++; break;
                }
                if (IsKeyPressed(KEY_ENTER))
                {
                    switch (menuState)
                    {
                    case 0: WaitTime(0.1); //FIRE SPELL
                        magicPosition.x = (GetScreenWidth() / 3.5);
                        magicPosition.y = GetScreenHeight() / 2;
                        StartLevel(firstLvlBG, currentAbility, charCastFire, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                        WaitTime(0.2);
                        StartLevel(firstLvlBG, currentAbility, charCastFire, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                        if (binaryCalculations(firstLvlBG, currentAbility, charCastFire, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle, tBox))
                        {
                            while (magicPosition.x < (GetScreenWidth()) / 1.5)
                            {

                                magicPosition.x += (0.0125 * GetScreenWidth()); // magic movement while loop
                                WaitTime(0.025);
                                castMagic(firstLvlBG, currentAbility, charSwingFire, sIdle, fSpell, playerCurrentHealth, enemyCurrentHealth, currentBattle);

                            }
                            enemyHealthCounter++;
                            StartLevel(firstLvlBG, currentAbility, charIdle, sHit, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                            switch (enemyHealthCounter)
                            {
                            case 0: enemyCurrentHealth = healthFull; break;
                            case 1: enemyCurrentHealth = health75; break;
                            case 2: enemyCurrentHealth = healthHalf; break;
                            case 3: enemyCurrentHealth = health25; break;
                            case 4: enemyCurrentHealth = health0; break;
                            }
                            StartLevel(firstLvlBG, currentAbility, charIdle, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                            magicPosition = mPositionTemp;
                        } isPlayersTurn = false;  break;
                    case 1:  // WATER SPELL
                        WaitTime(0.1);
                        magicPosition.x = (GetScreenWidth() / 3.5);
                        magicPosition.y = GetScreenHeight() / 2;
                        StartLevel(firstLvlBG, currentAbility, charCastWater, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                        WaitTime(0.2);
                        StartLevel(firstLvlBG, currentAbility, charCastWater, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                        if (binaryCalculations(firstLvlBG, currentAbility, charCastFire, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle, tBox))
                        {
                            while (magicPosition.x < (GetScreenWidth()) / 1.5)
                            {

                                magicPosition.x += (0.0125 * GetScreenWidth()); // magic movement while loop
                                WaitTime(0.025);
                                castMagic(firstLvlBG, currentAbility, charSwingWater, sIdle, wSpell, playerCurrentHealth, enemyCurrentHealth, currentBattle);

                            }
                            StartLevel(firstLvlBG, currentAbility, charIdle, gHit, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                            enemyHealthCounter++;
                            switch (enemyHealthCounter)
                            {
                            case 0: enemyCurrentHealth = healthFull; break;
                            case 1: enemyCurrentHealth = health75; break;
                            case 2: enemyCurrentHealth = healthHalf; break;
                            case 3: enemyCurrentHealth = health25; break;
                            case 4: enemyCurrentHealth = health0; break;
                            }
                            StartLevel(firstLvlBG, currentAbility, charIdle, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                            magicPosition = mPositionTemp;
                        } isPlayersTurn = false; break;
                    case 2: if (binaryCalculations(firstLvlBG, currentAbility, charIdle, mushroomEnemyIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle, tBox))
                    {
                        playerHealthCounter -= 2;
                    }
                          switch (playerHealthCounter) // health switch when damaged
                          {
                          case 0: playerCurrentHealth = healthFull; break;
                          case 1: playerCurrentHealth = health75; break;
                          case 2: playerCurrentHealth = healthHalf; break;
                          case 3: playerCurrentHealth = health25; break;
                          case 4: playerCurrentHealth = health0; break;
                          }
                          isPlayersTurn = false;
                          break;
                    case 3: isInThirdLevel = false; menuState = 0; mainMenu(mainBG, menuSelect1); isInMM = true; enemyHealthCounter = 0; playerHealthCounter = 0; battleCounter = 0; break;
                    }
                }
            }
            else
            {
                if (enemyHealthCounter < 4) { //Monster Spell
                    WaitTime(1);
                    magicPosition.x = (GetScreenWidth() / 1.55);
                    magicPosition.y = GetScreenHeight() / 2;
                    StartLevel(firstLvlBG, currentAbility, charIdle, sAtk1, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                    WaitTime(0.2);
                    StartLevel(firstLvlBG, currentAbility, charIdle, sAtk2, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                    WaitTime(0.1);
                    while (magicPosition.x > (GetScreenWidth()) / 4)
                    {

                        magicPosition.x -= (0.0125 * GetScreenWidth()); // magic movement while loop
                        WaitTime(0.025);
                        castMagic(firstLvlBG, currentAbility, charIdle, sIdle, slash, playerCurrentHealth, enemyCurrentHealth, currentBattle);

                    }
                    StartLevel(firstLvlBG, currentAbility, cHit, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                    playerHealthCounter++;
                    if (playerHealthCounter == 4)
                    {
                        while (isInFirstLevel)
                        {
                            switch (playerHealthCounter) // health switch when damaged
                            {
                            case 0: playerCurrentHealth = healthFull; break;
                            case 1: playerCurrentHealth = health75; break;
                            case 2: playerCurrentHealth = healthHalf; break;
                            case 3: playerCurrentHealth = health25; break;
                            case 4: playerCurrentHealth = health0; break;
                            }
                            switch (menuState)
                            {
                            case 0: currentAbility = abilityOne;  StartLevel(firstLvlBG, currentAbility, charDead, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                            case 1: currentAbility = abilityTwo;  StartLevel(firstLvlBG, currentAbility, charDead, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                            case 2: currentAbility = abilityThree;  StartLevel(firstLvlBG, currentAbility, charDead, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                            case 3: currentAbility = abilityFour;  StartLevel(firstLvlBG, currentAbility, charDead, sIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                            }
                            switch (GetKeyPressed()) //Spell Navigation
                            {
                            case KEY_LEFT: if (menuState == 0) menuState = 3;  else menuState--; break;
                            case KEY_RIGHT:  if (menuState == 3) menuState = 0;  else menuState++; break;
                            }
                            if (IsKeyPressed(KEY_ENTER))
                            {
                                switch (menuState)
                                {
                                case 3:isInThirdLevel = false; menuState = 0; mainMenu(mainBG, menuSelect1); isInMM = true; enemyHealthCounter = 0; playerHealthCounter = 0; battleCounter = 0; break;
                                }
                            }
                        }
                    }
                    else
                    {
                        StartLevel(firstLvlBG, currentAbility, charIdle, gIdle, playerCurrentHealth, enemyCurrentHealth, currentBattle);
                    }
                }
                else
                {
                    hasBeatenBattle = true;
                    if (battleCounter >= 2)
                    {
                        hasBeatenBattle = 3;
                    }
                    enemyHealthCounter = 0;
                    while (!isPlayersTurn)
                    {
                        switch (menuState)
                        {
                        case 0: currentAbility = wAbility1;  StartLevel(firstLvlBG, currentAbility, charIdle, sDead, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                        case 1: currentAbility = wAbility2;  StartLevel(firstLvlBG, currentAbility, charIdle, sDead, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                        case 2: currentAbility = wAbility3;  StartLevel(firstLvlBG, currentAbility, charIdle, sDead, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                        case 3: currentAbility = wAbility4;  StartLevel(firstLvlBG, currentAbility, charIdle, sDead, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                        case 4: currentAbility = wAbility5;  StartLevel(firstLvlBG, currentAbility, charIdle, sDead, playerCurrentHealth, enemyCurrentHealth, currentBattle); break;
                        }
                        switch (GetKeyPressed()) //Spell Navigation
                        {
                        case KEY_LEFT: if (menuState == 0) menuState = 4;  else menuState--; break;
                        case KEY_RIGHT:  if (menuState == 4) menuState = 0;  else menuState++; break;
                        }
                        if (IsKeyPressed(KEY_ENTER))
                        {
                            switch (menuState)
                            {
                            case 3: battleCounter++; menuState = 0;  isPlayersTurn = true; break;
                            case 4: isInThirdLevel = false; menuState = 0; mainMenu(mainBG, menuSelect1); isInMM = true; playerHealthCounter = 0; battleCounter = 0; isPlayersTurn = true;  break;
                            }
                        }
                    }
                    hasBeatenBattle = false;
                }
                isPlayersTurn = true;
            }
        }
    }
    return 0;
}