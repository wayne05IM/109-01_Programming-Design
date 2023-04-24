// ===========================================================================
// Using templates to revise Character, Warrior, Wizard, and Team
// ===========================================================================
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template <typename KeyType>
class Character
{
protected:
  static const int EXP_LV = 100;
  KeyType name;
  int level;
  int exp;
  int power;
  int knowledge;
  int luck;
  void levelUp(int pInc, int kInc, int lInc);
public:
  Character(KeyType n, int lv, int po, int kn, int lu);
  virtual void beatMonster(int exp) = 0;
  virtual void print();
  KeyType getName();
};

template <typename KeyType>
Character<KeyType>::Character(KeyType n, int lv, int po, int kn, int lu) 
  : name(n), level(lv), exp(pow(lv - 1, 2) * EXP_LV), power(po), knowledge(kn), luck(lu) 
{
}

template <typename KeyType>
void Character<KeyType>::print()
{
  cout << this->name 
       << ": Level " << this->level << " (" << this->exp << "/" << pow(this->level, 2) * EXP_LV
       << "), " << this->power << "-" << this->knowledge << "-" << this->luck << "\n";
}

template <typename KeyType>
void Character<KeyType>::levelUp(int pInc, int kInc, int lInc)
{
  this->level++;
  this->power += pInc;
  this->knowledge += kInc;
  this->luck += lInc;    
}

template <typename KeyType>
KeyType Character<KeyType>::getName()
{
  return this->name;
}







template <typename KeyType>
class Warrior : public Character<KeyType>
{
private:
  static const int PO_LV = 10;
  static const int KN_LV = 5;
  static const int LU_LV = 5;
public:
  Warrior(KeyType n, int lv = 0); 
  void print();
  void beatMonster(int exp);
};

template <typename KeyType>
Warrior<KeyType>::Warrior(KeyType n, int lv) : Character<KeyType>(n, lv, lv * PO_LV, lv * KN_LV, lv * LU_LV) 
{
}

template <typename KeyType>
void Warrior<KeyType>::print()
{
  cout << "Warrior ";
  Character<KeyType>::print();
}

template <typename KeyType>
void Warrior<KeyType>::beatMonster(int exp)
{
  this->exp += exp;
  while(this->exp >= pow(this->level, 2) * Character<KeyType>::EXP_LV)
    this->levelUp(PO_LV, KN_LV, LU_LV);
}



template <typename KeyType>
class Wizard : public Character<KeyType>
{
private:
  static const int PO_LV = 4;
  static const int KN_LV = 9;
  static const int LU_LV = 7;
public:
  Wizard(KeyType n, int lv = 0); 
  void print();
  void beatMonster(int exp);
};

template <typename KeyType>
Wizard<KeyType>::Wizard(KeyType n, int lv) : Character<KeyType>(n, lv, lv * PO_LV, lv * KN_LV, lv * LU_LV) 
{
}

template <typename KeyType>
void Wizard<KeyType>::print()
{
  cout << "Wizard ";
  Character<KeyType>::print();
}

template <typename KeyType>
void Wizard<KeyType>::beatMonster(int exp)
{
  this->exp += exp;
  while(this->exp >= pow(this->level, 2) * Character<KeyType>::EXP_LV)
    this->levelUp(PO_LV, KN_LV, LU_LV);
}

















template <typename KeyType>
class Team
{
private:
  int memberCount;
  Character<KeyType>* member[10];
public:
  Team();
  ~Team();
  void addWarrior(KeyType name, int lv);
  void addWizard(KeyType name, int lv);
  void memberBeatMonster(KeyType name, int exp);
  void printMember(KeyType name);
};

template <typename KeyType>
Team<KeyType>::Team()
{
  this->memberCount = 0;
  for(int i = 0; i < 10; i++)
    member[i] = nullptr;
}

template <typename KeyType>
Team<KeyType>::~Team()
{
  for(int i = 0; i < this->memberCount; i++)
    delete this->member[i];
}

template <typename KeyType>
void Team<KeyType>::addWarrior(KeyType name, int lv) 
{
  if(memberCount < 10)
  {
    member[memberCount] = new Warrior<KeyType>(name, lv);
    memberCount++;
  }
}

template <typename KeyType>
void Team<KeyType>::addWizard(KeyType name, int lv)
{
  if(memberCount < 10)
  {
    member[memberCount] = new Wizard<KeyType>(name, lv);
    memberCount++;
  }
}

template <typename KeyType>
void Team<KeyType>::memberBeatMonster(KeyType name, int exp)
{
  for(int i = 0; i < this->memberCount; i++)
  {
    if(this->member[i]->getName() == name)
    {
      this->member[i]->beatMonster(exp);
      break;
    }
  }  
}

template <typename KeyType>
void Team<KeyType>::printMember(KeyType name)
{
  for(int i = 0; i < this->memberCount; i++)
  {
    if(this->member[i]->getName() == name)
    {
      this->member[i]->print();
      break;
    }
  }
}
// ===========================================================================
// End of using templates to revise Character, Warrior, Wizard, and Team
// ===========================================================================













// ===========================================================================
// Using vectors to revise Team
// ===========================================================================
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template <typename KeyType>
class Team
{
private:
  vector<Character<KeyType>*> member;
public:
  Team();
  ~Team();
  void addWarrior(KeyType name, int lv);
  void addWizard(KeyType name, int lv);
  void memberBeatMonster(KeyType name, int exp);
  void printMember(KeyType name);
};

template <typename KeyType>
Team<KeyType>::Team()
{
}

template <typename KeyType>
Team<KeyType>::~Team()
{
  while(this->member.size() > 0)
  {
    delete this->member.back();
    this->member.pop_back();
  }
}

template <typename KeyType>
void Team<KeyType>::addWarrior(KeyType name, int lv) 
{
  Warrior<KeyType>* wPtr = new Warrior<KeyType>(name, lv); 
  this->member.push_back(wPtr);
}

template <typename KeyType>
void Team<KeyType>::addWizard(KeyType name, int lv)
{
  Wizard<KeyType>* wPtr = new Wizard<KeyType>(name, lv); 
  this->member.push_back(wPtr);
}

template <typename KeyType>
void Team<KeyType>::memberBeatMonster(KeyType name, int exp)
{
  for(int i = 0; i < this->member.size(); i++)
  {
    if(this->member[i]->getName() == name)
    {
      this->member[i]->beatMonster(exp);
      break;
    }
  }  
}

template <typename KeyType>
void Team<KeyType>::printMember(KeyType name)
{
  for(int i = 0; i < this->member.size(); i++)
  {
    if(this->member[i]->getName() == name)
    {
      this->member[i]->print();
      break;
    }
  }
}
// ===========================================================================
// End of using vector to revise Team
// ===========================================================================







int main()
{
  Team<string> t;
  
  t.addWarrior("Alice", 1);
  t.memberBeatMonster("Alice", 10000);
  t.addWizard("Bob", 2);
  t.printMember("Alice");

  Team<int> t2;
  
  t2.addWarrior(1, 1);
  t2.memberBeatMonster(1, 10000);
  t2.addWizard(2, 2);
  t2.printMember(1);
  
  return 0;
}



