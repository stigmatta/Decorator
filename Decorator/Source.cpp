#include <iostream>
#include <string>
using namespace std;

class Hero abstract
{
protected:
	string name;
	int attack, speed, health, defense;
public:
	Hero(string n)
	{
		name = n;
	}
	string GetName()
	{
		return name;
	}
	virtual int GetAttack()abstract;
	virtual int GetSpeed()abstract;
	virtual int GetHealth()abstract;
	virtual int GetDefense()abstract;


};

class Human : public Hero
{
public:
	Human() : Hero("Human")
	{ }

	int GetAttack()override {
		return 20;
	}

	int GetSpeed()override {
		return 20;
	}

	int GetHealth()override {
		return 150;
	}

	int GetDefense()override {
		return 0;
	}
};

class HumanProfession abstract : public Human
{
protected:
	Human* human;
public:
	HumanProfession(string n, Human* human) : human(human) {
		this->name = n;
	}

};

class HumanWarrior : public HumanProfession
{
public:
	HumanWarrior(Human* human) : HumanProfession("Human-warrior", human) { }

	int GetAttack()override {
		return 20;
	}

	int GetSpeed() override {
		return 10;
	}

	int GetHealth()override {
		return 50;
	}

	int GetDefense()override {
		return 20;
	}
};

class Swordsman : public HumanProfession {
public:
	Swordsman(HumanWarrior* hw) : HumanProfession("Human-Swordsman", hw) {}

	int GetAttack()override {
		return 40;
	}

	int GetSpeed() override {
		return -10;
	}

	int GetHealth()override {
		return 50;
	}

	int GetDefense()override {
		return 40;
	}
};

class Archer : public HumanProfession {
public:
	Archer(HumanWarrior* hw) : HumanProfession("Human-Archer", hw) {}

	int GetAttack()override {
		return 20;
	}

	int GetSpeed() override {
		return 20;
	}

	int GetHealth()override {
		return 50;
	}

	int GetDefense()override {
		return 10;
	}
};

class Horseman : public HumanProfession {
public:
	Horseman(Swordsman* sw) : HumanProfession("Human-horseman", sw) {}

	int GetAttack()override {
		return 20;
	}

	int GetSpeed() override {
		return 20;
	}

	int GetHealth()override {
		return 50;
	}

	int GetDefense()override {
		return 10;
	}
};

class Elf : public Hero
{
public:
	Elf() : Hero("Elf")
	{ }
	int GetAttack()override {
		return 15;
	}

	int GetSpeed()override {
		return 30;
	}

	int GetHealth()override {
		return 100;
	}

	int GetDefense()override {
		return 0;
	}
};
class ElfProfession abstract : public Elf
{
protected:
	Elf* elf;
public:
	ElfProfession(string n, Elf* elf) : elf(elf) {
		this->name = n;
	}

};

class ElfWarrior : public ElfProfession
{
public:
	ElfWarrior(Elf* elf) : ElfProfession("Elf-warrior", elf) {};

	int GetAttack()override {
		return 20;
	}

	int GetSpeed() override {
		return -10;
	}

	int GetHealth()override {
		return 100;
	}

	int GetDefense()override {
		return 20;
	}
};

class ElfMage : public ElfProfession
{
public:
	ElfMage(Elf* elf) : ElfProfession("Elf-mage", elf) {};

	int GetAttack()override {
		return 10;
	}

	int GetSpeed() override {
		return 10;
	}

	int GetHealth()override {
		return -50;
	}

	int GetDefense()override {
		return 10;
	}
};

class Crossbowman : public ElfProfession
{
public:
	Crossbowman(ElfMage* em) : ElfProfession("Elf-crossbowman", em) {};

	int GetAttack()override {
		return 20;
	}

	int GetSpeed() override {
		return 10;
	}

	int GetHealth()override {
		return 50;
	}

	int GetDefense()override {
		return 10;
	}
};

class EvilMage : public ElfProfession
{
public:
	EvilMage(ElfMage* em) : ElfProfession("Elf-evil mage", em) {};

	int GetAttack()override {
		return 70;
	}

	int GetSpeed() override {
		return 20;
	}

	int GetHealth()override {
		return 0;
	}

	int GetDefense()override {
		return 0;
	}
};

class KindMage : public ElfProfession
{
public:
	KindMage(ElfMage* em) : ElfProfession("Elf-kind mage", em) {};

	int GetAttack()override {
		return 50;
	}

	int GetSpeed() override {
		return 30;
	}

	int GetHealth()override {
		return 100;
	}

	int GetDefense()override {
		return 30;
	}
};



void client(Hero* p)
{
	char s[100];
	sprintf_s(s, "Name: %s  Power: %d Speed: %d Health: %d Defense: %d", p->GetName().c_str(), p->GetAttack(), p->GetSpeed(), p->GetHealth(), p->GetDefense());
	cout << s << endl;
}

int main() {
	Hero* hero = new Elf();
	client(hero);

	hero = new ElfWarrior(dynamic_cast<Elf*>(hero));
	client(hero);

	hero = new Crossbowman(dynamic_cast<ElfMage*>(hero));
	client(hero);

	delete hero;

	hero = new Human();
	client(hero);

	hero = new HumanWarrior(dynamic_cast<Human*>(hero));
	client(hero);

	system("pause");
	return 0;
}