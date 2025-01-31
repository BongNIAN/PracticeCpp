#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include<unordered_map>
#define NOMINMAX
#include<windows.h>
#include <algorithm>
#include <chrono>
#include <thread>
#include <limits>


using namespace std::this_thread; // for sleep_for
using namespace std::chrono;     // for milliseconds
using namespace std;

// 
// 
//데코레이터 달아서 엄청난 HealthPotion 이런느낌으로?
// 플레이어 체력의 30%라면 + 20% 를 해주는느낌? 

struct PlayerHp {
    int CurrentHp = -1;
    int MaxHp = -1;
};

struct MonsterHp {
    int CurrentHp = -1;
    int MaxHp = -1;
};


//메모장에 함수숨김현상과 오버로딩 의 차이
// 그리고 해결법으로는 
// 1. 인터페이스에서의 오버로딩 , .2 구조체 
class IPlayerObserver {
public:
    virtual ~IPlayerObserver() = default;
    virtual void UpdatePlayer( PlayerHp playerHp) = 0;
};

class IMonsterObserver {
public:
    virtual ~IMonsterObserver() = default;
    virtual void UpdateMonster(const MonsterHp& monsterHp) = 0;
};

class PlayerObserver :public IPlayerObserver 
{
    void UpdatePlayer(const PlayerHp playerHp) 
    {
        drawHpBar(playerHp.CurrentHp, playerHp.MaxHp);
    }
};
class GameOverHandler :public IPlayerObserver
{
    void UpdatePlayer(PlayerHp playerHp)
    {
        if (playerHp.CurrentHp <= 0)
        {

            printBossMonster();
            PrintLine("uhahahahah");
        }
    }
};


//class IPlayerLevelObserver {
//public:
//    virtual ~IPlayerLevelObserver() = default;
//    virtual void UpdateLevel(Character* c, bool IsLevelup) = 0;
//
//};
//class LevelObserver :public IPlayerLevelObserver {
//public:
//    virtual ~LevelObserver() = default;
//    virtual void UpdateLevel(Character* c, bool IsLevelUp)
//    {
//        if (IsLevelUp)
//        {
//
//
//        }
//    }
//
//};

void PrintLine(const string& line, int delay = 50) {
    for (char c : line) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;
}

void printBossMonster() {
    cout << R"(
      ______
   .-'      `-.
  /            \
 |,  .-.  .-.  ,|
 | )(_o/  \o_)( |
 |/     /\     \|
 (_     ^^     _)
  \__|IIIIII|__/
   | \IIIIII/ |
   \          /
    `--------`
    // \\  // \\
   //   \\//   \\
  ||     \/     ||

     GAME OVER
)" << endl;
}

void printMonster() {

    cout << R"(    ,      ,        *       *
      /(.-""-.)\     *    *        *
  |\  \/      \/  /|     *
  | \ / =.  .= \ / |  
  \( \   o\/o   / )/
   \_, '-/  \-' ,_/      *       *
     /   \__/   \          *
     \ \__/\__/ /            *
   ___\ \|--|/ /___
 /`    \      /    `\     
/       '----'       \     
)" << endl;

}

void printBattleWithMonster() 
{
    cout << R"(
                     _____                     ,      ,
                  .-'     '-.                /(.-""-.)\
                 /           \           |\  \/      \/  /|
                |   .-------. |          | \ / =.  .= \ / |
                |  /         \\          \( \   o\/o   / )/
                |  |    O    ||           \_, '-/  \-' ,_/
                \  \         /              /   \__/   \
                 '. '-------'               \ \__/\__/ /
                   '.___._.'               ___\ \|--|/ /___
                 //       \\             /`    \      /    `\
                //         \\           /       '----'       \
               ||    HERO   ||          ||      GOBLIN      ||
               ||           ||          ||                 ||
               ||           ||          ||                 ||
)" << endl;
}

void PrintDeathMonster()
{
    cout << R"(
        _______
       /       \
      /         \
     |   x   x   |
     |     ^     |
      \___|_|___/       
        /     \
       /       \
)" << endl;
}

void printMonsterTestModule(shared_ptr<Monster> m)
{
    cout << "hp : " << m->GetHealth() << endl;

    cout << " attack : " << m->GetAttack() << endl;


    cout << "name : " << m->GetName() << endl;

}

void drawHpBar(int currentHp, int maxHp, int barLength = 20) {
    // Calculate the filled and empty portions of the bar
    int filledLength = (currentHp * barLength) / maxHp;
    int emptyLength = barLength - filledLength;

    // Construct the HP bar
    std::string green = "\033[42m \033[0m"; // Green block
    std::string white = "\033[47m \033[0m"; // White block
    std::string hpBar;
    std::string red = "\033[41m \033[0m";

    int filledLengthRed = static_cast<int>(barLength * 0.3);

    if (filledLength < filledLengthRed)
    {
        for (int i = 0; i < filledLength; ++i) {
            hpBar += red;
        }

    }

    else
    {
        for (int i = 0; i < filledLength; ++i) {
            hpBar += green;
        }
    }

    for (int i = 0; i < emptyLength; ++i) {
        hpBar += white;
    }

    // Print the HP bar
    std::cout << "HP: [" << hpBar << "] " << currentHp << "/" << maxHp << std::endl;
}


/**
*  cout << "Hero: ";
    drawHpBar(heroHp, heroMaxHp);
    cout << "    Monster: ";
    drawHpBar(goblinHp, goblinMaxHp);
    cout << endl;
      for (int i = 0; i < 5; ++i) {
        this_thread::sleep_for(chrono::milliseconds(1000)); // 1초 딜레이

        // 커서 이동 및 이전 출력 지우기
        cout << "\033[A\r\033[K"; // 한 줄 위로 이동 후 지우기
        cout << "\033[A\r\033[K"; // 또 한 줄 위로 이동 후 지우기

        // 체력 감소
        heroHp -= 10;
        monsterHp -= 7;

        // 업데이트된 HP 바 출력
        cout << "Hero: ";
        drawHpBar(heroHp, heroMaxHp);
        cout << "    Monster: ";
        drawHpBar(monsterHp, monsterMaxHp);
        cout << endl;
    }

*/




//
//class MonsterObserver :public IMonsterObserver
//{
//
//};







class Item {
public:
	virtual string GetName() const = 0;
	virtual void use() = 0;
    virtual ~Item() = default;
};

class HealthPotion :public Item {
public:
	HealthPotion(): name("HealthPotion"),HealthRestore(50) {}
	void use()
	{
		cout << "HealPotion" << endl;
       
      
	}

	string GetName() const
	{
		return this->name; 
	}
private :
	string name;
	int HealthRestore;

};
class AttackBoost :public Item 
{
public:
	AttackBoost() : name("AttackBoost"), AttackIncrease(50) {}
	void use()
	{
		cout << "AttackBoost" << endl;
	}

	string GetName() const
	{
		return this->name;
	}
private:
	string name;
	int AttackIncrease;

};


/**
* 
* 아이템포퀘스트 ->is  -> 진엔딩 
* 
* 100% 예외확률 100%뽑기를 시작하기전에 
* 뽑기할대 0.1%의 아이템이 
* 
*/

class ItemForQuest :public Item {
public:
    ItemForQuest() : name("ItemForQuest") {}
    string GetName() const
    {
        return this->name;
    }

    void use() {
		cout << "ItemForQuest" << endl;
	}

private:
    string name;
};

class Antidote :public Item {
public:

    void use() {
        cout << "해독제 리턴값 1 or true" << endl;
    };
private:
    string name;
};




class Character {
public:
    // Delete copy constructor and assignment operator
    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;

    // Singleton instance getter using unique_ptr
    static Character* getInstance(const string& name) {
        if (!instance) {
            instance = unique_ptr<Character>(new Character(name));
        }
        return instance.get();
    }

    void Attach(const shared_ptr<IPlayerObserver>& observer) {
        observers.push_back(observer);
    }

    // 옵저버 제거
    void Detach(const shared_ptr<IPlayerObserver>& observer) {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    // 상태 변경 시 모든 옵저버에게 알림
    void Notify() {
        for (const auto& observer : observers) {
            PlayerHp hp = { health ,maxHealth };
            observer->UpdatePlayer(hp);
        }
    }



    void displayStatus() const {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health: " << health << "/" << maxHealth << endl;
        cout << "Attack: " << attack << endl;
        cout << "Experience: " << experience << endl;
        cout << "Gold: " << gold << endl;
    }

    int getLevel() 
    {
        return this->level;
    }

    void levelUp() {
        level++;
        maxHealth += 20;
        health = maxHealth;
        attack += 5;
        cout << name << " leveled up to Level " << level << "!" << endl;
    }

    int getATK() { return attack; }


    void useItem(Item* item) {
        auto it = inventoryTest.find(item);
        if (it != inventoryTest.end() && it->second > 0) {
            item->use();
            it->second--;
            if (it->second == 0) {
                inventoryTest.erase(it);
            }
        }
        else {
            cout << "Item not available in inventory." << endl;
        }
    }

    void addItem(Item* item) {
        inventoryTest[item]++;
        inventory.push_back(item);
        cout << "Item added to inventory." << endl;
    }
    void visitshop() {
        cout << "Hello shop" << endl;
    }
    int GetHealth() { return health; }
    int GetMaxHealth() { return maxHealth; }
    void setAttack(int damage) {
        this->health -= damage;
        Notify();
    }
    void TakeDamage(int damage) 
    {
        health -= damage;
        if (health < 0) health = 0;
        Notify();
    }

private:
    // Private constructor
    Character(const string& name)
        : name(name), level(1), health(100), maxHealth(100), attack(10), experience(0), gold(0) {
    }

    static unique_ptr<Character> instance; 

    string name;
    int level;
    int health;
    int maxHealth;
    int attack;
    int experience;
    int gold;
    vector<shared_ptr<IPlayerObserver>> observers;
    unordered_map<Item*, int> inventoryTest;
    vector<Item*> inventory; 
};

// Initialize the static instance pointer
unique_ptr<Character> Character::instance = nullptr;






//이벤트확률구현 함수 
/**정확성을 위해 초기화*/
void InitializeRandom() 
{

	srand(static_cast<unsigned int>(time(0)));
}

/**min<= RandomX <= max*/
int GenerateRandom(int min, int max) 
{

	return min + (rand() % (max - min + 1));
}

//Percent
bool IsCreateEvent(int percent) 
{
	int tmp = GenerateRandom(0, 99);
	
	if (tmp < percent) { 
		
		return true;
	
	}
	

	return false;
}

string CreateGradeByCDF() {
 
    const vector<pair<int, string>> grade = 
    {
        {1, "S"},    // 1%
        {10, "A"},   // 9%
        {30, "B"},   // 20%
        {55, "C"},   // 25%
        {100, "D"}   // 45%
    };

    int RandomValue = GenerateRandom(1, 100);

    for (const auto& range : grade) {
        if (RandomValue <= range.first) {
            return range.second;
        }
    }
    return "D"; // Default case 



}



//Create MonsterClass
class Monster 
{
public:
    virtual string GetName() const = 0;
    virtual int GetHealth() const = 0;
    virtual int GetAttack() const = 0;
    virtual void TakeDamage(int damage) = 0;
    virtual shared_ptr<Item> DropItem() = 0;
    virtual ~Monster() = default;
};

//Create MonsterClass
class Goblin : public Monster 
{
public:
    Goblin(int level) 
    {
        Name = "Goblin";
        Health = level * GenerateRandom(20, 30);
        Attack = level * GenerateRandom(5, 10);
    }

    string GetName() const override
    {
        return Name;
    }

    int GetHealth() const override 
    {
        return Health;
    }

    int GetAttack() const override 
    {
        return Attack;
    }

    void TakeDamage(int damage) override 
    {
        Health -= damage;
        cout << "Goblin took " << damage << " damage. Remaining health: " << Health << endl;
    }

    shared_ptr<Item> DropItem() override 
    {
        if (IsCreateEvent(30)) {
            if (IsCreateEvent(50))
            {
                return make_shared<HealthPotion>();

            }
            else
            {
                return make_shared<AttackBoost>();
            }
        }
           
        
        cout << "I am Goblin, No Drop." << endl;
        return nullptr;
    }

private:
    string Name;
    int Health;
    int Attack;
};

//Create MonsterClass
class Troll : public Monster {
public:
    Troll(int level)
    {
        Name = "Troll";
        Health = level * GenerateRandom(20, 30);
        Attack = level * GenerateRandom(5, 10);
    }
    string GetName() const override {
        return Name;
    }

    int GetHealth() const override {
        return Health;
    }

    int GetAttack() const override {
        return Attack;
    }

    void TakeDamage(int damage) override {
        Health -= damage;
        cout << "Troll took " << damage << " damage. Remaining health: " << Health << endl;
    }

    shared_ptr<Item> DropItem() override {
        if (IsCreateEvent(30)) {
            if (IsCreateEvent(50))
            {
                return make_shared<HealthPotion>();

            }
            else
            {
                return make_shared<AttackBoost>();
            }
        }


        cout << "I am Troll, No Drop." << endl;
        return nullptr;
    }

private:
    string Name;
    int Health;
    int Attack;
};

//Create MonsterClass
class Orc : public Monster {
public:
    Orc(int level)
    {
        Name = "Orc";
        Health = level * GenerateRandom(20, 30);
        Attack = level * GenerateRandom(5, 10);
    }

    string GetName() const override {
        return Name;
    }

    int GetHealth() const override {
        return Health;
    }

    int GetAttack() const override {
        return Attack;
    }

    void TakeDamage(int damage) override {
        Health -= damage;
        cout << "Orc took " << damage << " damage. Remaining health: " << Health << endl;
    }

    shared_ptr<Item> DropItem() override {
        if (IsCreateEvent(30)) {
            if (IsCreateEvent(50))
            {
                return make_shared<HealthPotion>();

            }
            else
            {
                return make_shared<AttackBoost>();
            }
        }


        cout << "I am Orc, No Drop." << endl;
        return nullptr;
    }

private:
    string Name;
    int Health;
    int Attack;
};



//Create Abs Class
class MonsterDecorator : public Monster
{
public:
    MonsterDecorator(shared_ptr<Monster> m) : monster(move(m)) {}

    virtual ~MonsterDecorator()
    {
        cout << " byebyeDecorator" << endl;
    }
    string GetName() const override {
        return monster->GetName();
    }

    int GetHealth() const override {
        return monster->GetHealth();
    }

    int GetAttack() const override {
        return monster->GetAttack();
    }

    void TakeDamage(int damage) override {
        monster->TakeDamage(damage);
    }

    shared_ptr<Item> DropItem() override {
        return monster->DropItem();
    }

protected:
    shared_ptr<Monster> monster;
};

//이거 만일 된다면 대박신기하네;; 이게 부모가 자식을 대신할수있다의 표본인건가?
// 와 이거 대박신기하네;;
// 몬스터 데코레이터에 가상함수로 상속 다 받으면 , 부모가 자식을 대신할수있구나;
// move(m)하는 순간 소유권이 사라져서 더이상 생성자에서 m->을 사용할수가 없다.
// 따라서 부모를 호출해서 몬스터의 정보를 불러온다
//Decorate Monster 
class BossMonster : public MonsterDecorator
{
public:
    BossMonster(shared_ptr<Monster> m) : MonsterDecorator(move(m))
    {
        /* cout << "monsterAttack :     " << m->GetAttack() << endl;*/
        this->Name = "Boss" + monster->GetName();
        this->Attack = static_cast <int> (monster->GetAttack() * 1.5);
        this->Health = static_cast <int> (monster->GetHealth() * 1.5);
        cout << "BossAttack :     " << this->Attack << endl;
    }

    string GetName() const override
    {
        return Name;
    }

    int GetHealth() const override
    {
        return Health;
    }

    int GetAttack() const override
    {
        return Attack;
    }

    void TakeDamage(int damage) override
    {
        Health -= damage;
        cout << "Boss took " << damage << " damage. Remaining health: " << Health << endl;
    }

    shared_ptr<Item> DropItem() override
    {
        if (IsCreateEvent(10))
        {
            cout << "QuestItem" << endl;
            return make_shared<ItemForQuest>();
        }
        else
        {
            if (IsCreateEvent(50))
            {
                cout << "HealthPotion" << endl;
                return make_shared<HealthPotion>();
            }
            if (IsCreateEvent(40))
            {
                cout << "AttackBoost" << endl;
                return make_shared<AttackBoost>();
            }

        }


        cout << "I am Boss, No Drop." << endl;
        return nullptr;
    }

private:
    string Name;
    int Health;
    int Attack;
};

//Decorate Monster
class PoisonMonster : public MonsterDecorator
{
public:
    PoisonMonster(shared_ptr<Monster> m) : MonsterDecorator(move(m))
    {
        cout << "monsterAttack :     " << monster->GetAttack() << endl;
        Name = "Poison" + monster->GetName();
        Attack = monster->GetAttack();
        Health = monster->GetAttack();
        cout << "PoisonAttack :     " << this->Attack << endl;
    }

    string GetName() const override
    {
        return  Name;
    }

    int GetHealth() const override
    {
        return Health;
    }

    int GetAttack() const override
    {

        if (IsCreateEvent(10))
        {
            return Attack + 1; // 어택 +1 이면 독걸린것 
        }

        return Attack;
    }

    /**다시 진행할지 말지 */
    /*int PoisonAttack(bool IsPoison) const
    {
        if (IsPoison)
        {
            return Attack;
        }

        else {

        }

        return Attack;
    }
  */

    void TakeDamage(int damage) override
    {
        Health -= damage;
        cout << "Boss took " << damage << " damage. Remaining health: " << Health << endl;
    }

    shared_ptr<Item> DropItem() override
    {
        if (IsCreateEvent(10))
        {
            cout << "QuestItem" << endl;
            return make_shared<ItemForQuest>();
        }
        else
        {
            if (IsCreateEvent(50))
            {
                cout << "HealthPotion" << endl;
                return make_shared<HealthPotion>();
            }
            if (IsCreateEvent(40))
            {
                cout << "AttackBoost" << endl;
                return make_shared<AttackBoost>();
            }

        }


        cout << "I am" << this->GetName() << "No Drop." << endl;
        return nullptr;
    }

    //drop Item 모듈화시켜야할듯 ? //보스따로 Decorator따로

private:
    string Name;
    int Health;
    int Attack;
};

//Create Factory Interface
class IMonsterFactory
{
public:

    virtual shared_ptr<Monster> CreateMonster(int level) const = 0;
    virtual ~IMonsterFactory() = default;
};

//Create BossFactory Interface
class IBossMonsterFactory
{
public:

    virtual shared_ptr<Monster> CreateBossMonster(int level) const = 0;
    virtual ~IBossMonsterFactory() = default;
};

shared_ptr<Monster> CreateMonsterFunc(int level)
{
    shared_ptr<Monster> tmp;

    int MonsterType = GenerateRandom(0, 2);

    switch (MonsterType)
    {
    case 0:
        tmp = make_shared<Goblin>(level);
        cout << "MonsterFactory Create New Goblin" << endl;
        break;

    case 1:
        tmp = make_shared<Orc>(level);
        cout << "MonsterFactory Create New Orc" << endl;
        break;

    case 2:
        tmp = make_shared <Troll>(level);
        cout << "MonsterFactory Create New Troll" << endl;
        break;
    default:
        cout << "Critical Error" << endl;
    }
    return tmp;

}

//Create MonsterFactory
class MonsterFactory :public IMonsterFactory
{
public:

    shared_ptr<Monster> CreateMonster(int level) const override
    {
        shared_ptr<Monster> tmp;



        int IsPoison = GenerateRandom(1, 10);

        tmp = CreateMonsterFunc(level);

        //1~10중 1이 걸리면 10%
        if (IsPoison == 1)
        {
            tmp = make_shared<PoisonMonster>(tmp);
            cout << "MonsterFactory Create New IsPoison" << endl;
        }

        return tmp;
    }

};

//Create BossMonsterFactory
class BossMonsterFactory : public IBossMonsterFactory
{
public:

    shared_ptr<Monster> CreateBossMonster(int level) const override
    {
        shared_ptr<Monster> tmp;
        //0~2 난수 생성
        int MonsterType = GenerateRandom(0, 2);


        tmp = CreateMonsterFunc(level);
        
        //1~10중 1이 걸리면 10%

        tmp = make_shared<BossMonster>(tmp);

        cout << "Boss Name  : " << tmp->GetName() << endl;


        return tmp;

    }

};




void clearConsole() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}




class Shop {
public:
    Shop() {}
};



//배ㅔ틀 구현해놓고, 메인에서 while(1)다록 제대로 구현 
class GameManager {
public:
    GameManager(){}

    

    void test(Character *c) {
        cout << "im Gm" << c->GetHealth() << endl;
    }

    void BattleStart(Character* c)
    {


        MonsterFactory m;



        int UserSelection = 100000;
        shared_ptr<Monster>tmpMonster = m.CreateMonster(c->getLevel());
        Item* Testitem;
        PrintLine("grrrrrr");
        /*printMonsterTestModule(tmpMonster);*/
        //유저 선택지 , 아이템 선택 할건지 ? 공격할건지?
        //


        printBattleWithMonster();


        while (1) {


            sleep_for(milliseconds(300));

            cout << "1.몬스터 공격 2.인벤토리 3.도망가기  선택 : ";
            cin >> UserSelection;

            if (cin.fail() || (UserSelection != 1 && UserSelection != 2 && UserSelection != 3)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "잘못된 입력입니다. 올바른 수를 입력하세요 !" << endl;
                continue;
            }
            if (UserSelection == 1)
            {

                tmpMonster->TakeDamage(c->getATK());
                c->TakeDamage(tmpMonster->GetAttack());

                cout << "remaining MonsterHp is : " << tmpMonster->GetHealth() << endl;



                /**무승부시 gameOver */ //플레이어가 죽을 경우에는 게임오버하고 아예 끝?
                if (c->GetHealth() < 0)
                {
                    break;


                }
                else if (tmpMonster->GetHealth() < 0)
                {
                    cout << "Victory" << endl;

                    //경험치 얼마 ,골드 얼마  
                //경험치 로직 exp -------> LevelUpHandler ("레벨업을 했다라는 문구 "  status가 얼마에서 얼마로 늘어났다 ) 
                //다시 인터페이스로 
                      // 도망가면 드랍하고 , 30% 랜덤한 아이템 확률
            //레벨업구도 어떻게 할건지 
            //전두 통료시 경험치 획득,골드 획득, 
            // 


                    break;

                }



            }
            else if (UserSelection == 2)
            {
                //인벤토리 캐릭터 인벤토리 

            }
            else if (UserSelection == 3)
            {
                if (IsCreateEvent(50))
                {
                    cout << "ㅋㅋ ㅄ" << endl;
                    break;

                }
                else
                {

                    //hp잃고 도망
                    int current = c->GetHealth();
                    int lostHp = static_cast<int>(current * 0.3);
                    c->TakeDamage(lostHp);

                    //30% 잃는것 : getHelth 

                    //랜덤 아이템 잃는다 
                    // index -> 
                    if (IsCreateEvent(60))
                    {
                        GenerateRandom(1, 10); //c->inventory[i] 지우기 
                        //deleteinventory()
                    }



                    cout << "도망가기 실패" << endl;
                    continue;
                }
            }

        }

    }

  

private:
  


};

int main() {

    InitializeRandom();
    Character* c = Character::getInstance("Hero");
    BossMonsterFactory boss;
    MonsterFactory monst;
    GameManager game;
  
    auto playerObserver = make_shared<PlayerObserver>();
    auto gameOverHandler = make_shared<GameOverHandler>();
    c->Attach(gameOverHandler);
    c->Attach(playerObserver);
    

    
    c->setAttack(3);
    
    sleep_for(milliseconds(300));

    cout << "\033[A\r\033[K"; // 한 줄 위로 이동 후 지우기

    
    
    c->setAttack(3);


    //PrintDeathMonster();
    //
    //c->setAttack(3);
    ///*game.Battle(c);*/
    //sleep_for(milliseconds(2000));
    //cout << "\033[A\r\033[K"; // 한 줄 위로 이동 후 지우기
    //cout << "\033[A\r\033[K"; // 또 한 줄 위로 이동 후 지우기
    //
    //sleep_for(milliseconds(1000));

    //c->setAttack(3);
    //sleep_for(milliseconds(1000));
    //cout << "\033[A\r\033[K"; // 한 줄 위로 이동 후 지우기
    //c->setAttack(3);
    //sleep_for(milliseconds(1000));
    //cout << "\033[A\r\033[K"; // 한 줄 위로 이동 후 지우기
    //c->setAttack(3);
    //sleep_for(milliseconds(1000));
    //cout << "\033[A\r\033[K"; // 한 줄 위로 이동 후 지우기
    //c->setAttack(3);

	return 0;
}
































//
//
//cout << "Hero: ";
//drawHpBar(heroHp, heroMaxHp);
//cout << "    Monster: ";
//drawHpBar(goblinHp, goblinMaxHp);
//cout << endl;





/**
* 
* 
* PrintLine("\nThe battle begins!");
    int goblinHealth = 50;
    int heroAttack = 20;

    while (goblinHealth > 0) {
        // 히어로 공격
        PrintLine("\nHERO: \"This ends now!\"", 70);
        this_thread::sleep_for(chrono::milliseconds(500));
        PrintLine(">>> HERO slashes the GOBLIN with a mighty strike!", 50);
        goblinHealth -= heroAttack;
        if (goblinHealth > 0) {
            PrintLine("GOBLIN: \"Raaaargh! Is that all you've got?!\"", 70);
            PrintLine("GOBLIN's health: " + to_string(goblinHealth) + " HP\n", 50);
        } else {
            PrintLine("GOBLIN: \"No... this cannot be...\"", 70);
            break;
        }

        this_thread::sleep_for(chrono::seconds(1));
    }

    // 고블린 사망 연출
    PrintLine("\n>>> GOBLIN collapses to the ground, defeated.", 50);
    PrintLine("HERO: \"Rest in pieces, monster.\"", 70);

    // 엔딩 연출
    this_thread::sleep_for(chrono::seconds(2));
    PrintLine("\nThe HERO stands victorious amidst the ruins...");
    PrintLine("But the fight is far from over...");
    PrintLine("Darkness looms on the horizon...");
    PrintLine("\n[TO BE CONTINUED...]", 100);

*/













//1번 질문 : 왜 weapon은 소멸자가 하나만 구현?
/**
* 1. WeaponDecorator에서 가상 소멸자를 선언한 이유
다형성으로 객체를 삭제할 때 WeaponDecorator의 소멸자가 올바르게 호출되도록 보장.
내부적으로 감싸고 있는 Weapon 객체를 삭제하기 위해 delete weapon;을 호출.
2. BasicWeapon에서 소멸자를 선언하지 않은 이유
Weapon에서 가상 소멸자를 선언했기 때문에 다형성 삭제 시 소멸자가 자동으로 호출됨.
BasicWeapon은 추가적인 동적 자원을 관리하지 않으므로 소멸자를 명시적으로 선언할 필요가 없음.

*/








//int main() {
//
//
//	InitializeRandom();
//
//
//	return 0;
//}

//

//
//void drawOrc() {
//	std::string orcArt =   std::string battleScene = R"(
       
//
//	std::cout << orcArt << std::endl;
//}
//
//int main() {
//	int currentHp = 15;
//	int maxHp = 20;
//	drawOrc();
//	drawHpBar(currentHp, maxHp);
//
//	return 0;
//}











//#include <iostream>
//#include <thread>
//#include <chrono>
//
//using namespace std;
//using namespace std::this_thread; // for sleep_for
//using namespace std::chrono;     // for milliseconds
//
//// Function to clear the console
//void clearConsole() {
//#ifdef _WIN32
//	system("cls");
//#else
//	system("clear");
//#endif
//}
//
//// Frame 1: Closed Door
//void drawFrame1() {
//	cout << R"(
//  +-------+
//  |       |
//  |       |
//  |       |
//  |       |
//  |       |
//  +-------+
//)";
//}
//
//// Frame 2: Slightly Open Door
//void drawFrame2() {
//	cout << R"(
//  +-------+
//  |      /|
//  |     / |
//  |    /  |
//  |   /   |
//  |  /    |
//  +-------+
//)";
//}
//
//// Frame 3: Half-Open Door
//void drawFrame3() {
//	cout << R"(
//  +-------+
//  |     / |
//  |    /  |
//  |   /   |
//  |  /    |
//  | /     |
//  +-------+
//)";
//}
//
//// Frame 4: Fully Open Door
//void drawFrame4() {
//	cout << R"(
//  +-------+
//  |       |
//  |       |
//  |       |
//  |       |
//  |       |
//  +       
//)";
//}
//
//// Frame 5: Character Appears at Door
//
//// Frame 6: Character Walks Out (Step 1)
//void drawFrame6() {
//	cout << R"(
//  +-------+
//  O       
// /|\      
// / \      
//  |       |
//  |       |
//  +       
//)";
//}
//
//// Frame 7: Character Walks Out (Step 2)
//void drawFrame7() {
//	cout << R"(
//  +-------+
//          O
//         /|\
//         / \
//  |       |
//  |       |
//  +       
//)";
//}
//
//// Frame 8: Door Closes
//void drawFrame8() {
//	cout << R"(
//  +-------+
//  |       |
//  |       |
//  |       |
//  |       |
//  |       |
//  +-------+
//)";
//}
//
//// Function to animate the door opening and character walking out
//void animateDoorAndExit() {
//	clearConsole();
//	drawFrame1(); // Closed door
//	sleep_for(milliseconds(200));
//
//	clearConsole();
//	drawFrame2(); // Slightly open door
//	sleep_for(milliseconds(200));
//
//	clearConsole();
//	drawFrame3(); // Half-open door
//	sleep_for(milliseconds(200));
//
//	clearConsole();
//	drawFrame4(); // Fully open door
//	sleep_for(milliseconds(200));
//
//
//
//	clearConsole();
//	drawFrame6(); // Character steps out (Step 1)
//	sleep_for(milliseconds(500));
//
//	clearConsole();
//	drawFrame7(); // Character steps out (Step 2)
//	sleep_for(milliseconds(500));
//
//	clearConsole();
//	drawFrame8(); // Door closes
//	sleep_for(milliseconds(500));
//}
//
//int main() {
//	animateDoorAndExit();
//	return 0;
//}



/**Create S,A,B,C*/

/**
* #include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>

// SOLID 원칙 기반 클래스로 구조화
class RandomGenerator {
public:
    void InitializeRandom() {
        srand(static_cast<unsigned int>(time(0)));
    }

    int GenerateRandom(int min, int max) {
        return min + (rand() % (max - min + 1));
    }

    bool IsCreateEvent(int percent) {
        int sample = GenerateRandom(0, 99);
        return sample < percent;
    }
};

class GradeManager {
private:
    std::map<std::string, std::vector<std::string>> grade_items;
    std::vector<std::pair<std::string, int>> probabilities;
    RandomGenerator random_generator;

public:
    GradeManager() {
        // 아이템 초기화
        grade_items = {
            {"S", {"S_item1", "S_item2"}},
            {"A", {"A_item1", "A_item2", "A_item3"}},
            {"B", {"B_item1", "B_item2", "B_item3", "B_item4"}},
            {"D", {"D_item1", "D_item2", "D_item3", "D_item4", "D_item5"}}
        };

        // 확률 초기화
        probabilities = {
            {"S", 7},
            {"A", 10},
            {"B", 50},
            {"D", 33}
        };
    }

    void SetRandomGenerator(RandomGenerator& rg) {
        random_generator = rg;
    }

    std::string CreateGradeByCdf() {
        int cumulative_probability = 0;
        int random_value = random_generator.GenerateRandom(0, 99);

        for (const auto& pair : probabilities) {
            cumulative_probability += pair.second;
            if (random_value < cumulative_probability) {
                return pair.first;
            }
        }

        return "D"; // 기본값으로 D 반환
    }

    std::string PickRandomItem() {
        std::string chosen_grade = CreateGradeByCdf();

        // 선택된 등급에서 아이템 리스트 가져오기
        const std::vector<std::string>& items = grade_items[chosen_grade];

        // 랜덤 아이템 선택
        int random_index = random_generator.GenerateRandom(0, items.size() - 1);
        return items[random_index];
    }
};

int main() {
    RandomGenerator random_generator;
    random_generator.InitializeRandom();

    GradeManager grade_manager;
    grade_manager.SetRandomGenerator(random_generator);

    // 테스트 실행
    for (int i = 0; i < 10; ++i) {
        std::cout << grade_manager.PickRandomItem() << std::endl;
    }

    return 0;
}



*/