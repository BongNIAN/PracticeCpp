#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include<unordered_map>
#include<windows.h>

using namespace std;

//���ڷ����� �޾Ƽ� ��û�� HealthPotion �̷���������?
// �÷��̾� ü���� 30%��� + 20% �� ���ִ´���? 

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


class ItemForQuest :public Item {
public:
    ItemForQuest() : name("ItemForQuest") {}
    string GetName() const
    {
        return this->name;
    }

    void use() {
		cout << "ItemForQuest" << endl;
	};

private:
    string name;
};

class Antidote :public Item {
public:

    void use() {
        cout << "�ص��� ���ϰ� 1 or true" << endl;
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

    void displayStatus() const {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health: " << health << "/" << maxHealth << endl;
        cout << "Attack: " << attack << endl;
        cout << "Experience: " << experience << endl;
        cout << "Gold: " << gold << endl;
    }

    void levelUp() {
        level++;
        maxHealth += 20;
        health = maxHealth;
        attack += 5;
        cout << name << " leveled up to Level " << level << "!" << endl;
    }

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
    }

private:
    // Private constructor
    Character(const string& name)
        : name(name), level(1), health(100), maxHealth(100), attack(10), experience(0), gold(0) {
    }

    static unique_ptr<Character> instance; // Singleton instance

    string name;
    int level;
    int health;
    int maxHealth;
    int attack;
    int experience;
    int gold;

    unordered_map<Item*, int> inventoryTest; // Item and its count
    vector<Item*> inventory; // List of items in inventory
};

// Initialize the static instance pointer
unique_ptr<Character> Character::instance = nullptr;






//�̺�ƮȮ������ �Լ� 
/**��Ȯ���� ���� �ʱ�ȭ*/
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

//�̰� ���� �ȴٸ� ��ڽű��ϳ�;; �̰� �θ� �ڽ��� ����Ҽ��ִ��� ǥ���ΰǰ�?
// �� �̰� ��ڽű��ϳ�;;
// ���� ���ڷ����Ϳ� �����Լ��� ��� �� ������ , �θ� �ڽ��� ����Ҽ��ֱ���;
// move(m)�ϴ� ���� �������� ������� ���̻� �����ڿ��� m->�� ����Ҽ��� ����.
// ���� �θ� ȣ���ؼ� ������ ������ �ҷ��´�
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
            return Attack + 1; // ���� +1 �̸� ���ɸ��� 
        }

        return Attack;
    }

    /**�ٽ� �������� ���� */
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

    //drop Item ���ȭ���Ѿ��ҵ� ? //�������� Decorator����

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

        //1~10�� 1�� �ɸ��� 10%
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
        //0~2 ���� ����
        int MonsterType = GenerateRandom(0, 2);


        tmp = CreateMonsterFunc(level);
        
        //1~10�� 1�� �ɸ��� 10%

        tmp = make_shared<BossMonster>(tmp);

        cout << "Boss Name  : " << tmp->GetName() << endl;


        return tmp;

    }

};




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


//FrameWork.cpp�� ����?

class GameManager {
public:
    GameManager(Character* c)
    {
        p2 = c;

    }
    int test() {
       return  this->p2->GetHealth();
    }

private :
   Character* p2;
  

};


int main() {

    InitializeRandom();
    Character* c = Character::getInstance("Hero");
    BossMonsterFactory boss;
    MonsterFactory monst;
    for (int i = 0; i < 100; i++)
    {
        boss.CreateBossMonster(i);
    }
    for (int i = 0; i < 100; i++)
    {
        monst.CreateMonster(i);
    }

	return 0;
}

































//1�� ���� : �� weapon�� �Ҹ��ڰ� �ϳ��� ����?
/**
* 1. WeaponDecorator���� ���� �Ҹ��ڸ� ������ ����
���������� ��ü�� ������ �� WeaponDecorator�� �Ҹ��ڰ� �ùٸ��� ȣ��ǵ��� ����.
���������� ���ΰ� �ִ� Weapon ��ü�� �����ϱ� ���� delete weapon;�� ȣ��.
2. BasicWeapon���� �Ҹ��ڸ� �������� ���� ����
Weapon���� ���� �Ҹ��ڸ� �����߱� ������ ������ ���� �� �Ҹ��ڰ� �ڵ����� ȣ���.
BasicWeapon�� �߰����� ���� �ڿ��� �������� �����Ƿ� �Ҹ��ڸ� ��������� ������ �ʿ䰡 ����.

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

// SOLID ��Ģ ��� Ŭ������ ����ȭ
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
        // ������ �ʱ�ȭ
        grade_items = {
            {"S", {"S_item1", "S_item2"}},
            {"A", {"A_item1", "A_item2", "A_item3"}},
            {"B", {"B_item1", "B_item2", "B_item3", "B_item4"}},
            {"D", {"D_item1", "D_item2", "D_item3", "D_item4", "D_item5"}}
        };

        // Ȯ�� �ʱ�ȭ
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

        return "D"; // �⺻������ D ��ȯ
    }

    std::string PickRandomItem() {
        std::string chosen_grade = CreateGradeByCdf();

        // ���õ� ��޿��� ������ ����Ʈ ��������
        const std::vector<std::string>& items = grade_items[chosen_grade];

        // ���� ������ ����
        int random_index = random_generator.GenerateRandom(0, items.size() - 1);
        return items[random_index];
    }
};

int main() {
    RandomGenerator random_generator;
    random_generator.InitializeRandom();

    GradeManager grade_manager;
    grade_manager.SetRandomGenerator(random_generator);

    // �׽�Ʈ ����
    for (int i = 0; i < 10; ++i) {
        std::cout << grade_manager.PickRandomItem() << std::endl;
    }

    return 0;
}



*/