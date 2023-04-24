#include <iostream>
#include <string>
using namespace std;

class Entity
{
protected:
  string id;
  bool isOn; 
  bool isSer; // means nothing if isOn == false
  double lon;
  double lat;
public: 
  Entity(string id, bool isOn, bool isSer, double lon, double lat);
  void print();
};

Entity::Entity(string id, bool isOn, bool isSer, double lon, double lat)
  : id(id), isOn(isOn), isSer(isSer), lon(lon), lat(lat)
{
}

void Entity::print()
{
  cout << this->id << ": " << this->isOn << " " << this->isSer
       << " (" << this->lon << ", " << this->lat << ")" << endl;
}






class Car : public Entity
{
private:
public:
  Car(string id, bool isOn, bool isSer, double lon, double lat);
  void print();
};

Car::Car(string id, bool isOn, bool isSer, double lon, double lat)
  : Entity(id, isOn, isSer, lon, lat)
{
}

void Car::print()
{
  cout << this->id << ": ";
  if(this->isOn == true)
  {
    if(this->isSer == true)
      cout << "in-service, (";
    else
      cout << "empty, (";
    cout << this->lon << ", " << this->lat << ")";
  }
  else
    cout << "offline";
  cout << endl;
}





class Passenger : public Entity
{
private:
public:
  Passenger(string id, bool isOn, bool isSer, double lon, double lat);
  void print();
};

Passenger::Passenger(string id, bool isOn, bool isSer, double lon, double lat)
  : Entity(id, isOn, isSer, lon, lat)
{
}

void Passenger::print()
{
  cout << this->id << ": ";
  if(this->isOn == true)
  {
    if(this->isSer == true)
      cout << "in-service, (";
    else
      cout << "waiting, (";
    cout << this->lon << ", " << this->lat << ")";
  }
  else
    cout << "offline";
  cout << endl;
}












template <typename entityType>
class EntityArray
{
protected:
  int capacity;
  int cnt;
  entityType** entityPtr;
public:
  EntityArray();
  ~EntityArray();
  bool add(string id, bool isOn, bool isSer, double lon, double lat);
  void print();
};

template <typename entityType>
EntityArray<entityType>::EntityArray()
{
  this->cnt = 0;
  this->capacity = 20000;
  this->entityPtr = new entityType*[this->capacity];
}

template <typename entityType>
EntityArray<entityType>::~EntityArray()
{
  for(int i = 0; i < this->cnt; i++)
    delete this->entityPtr[i];
  delete [] this->entityPtr;
}

template <typename entityType>
bool EntityArray<entityType>::add(string id, bool isOn, bool isSer, double lon, double lat)
{
  if(this->cnt < this->capacity)
  {
    this->entityPtr[this->cnt] = new entityType(id, isOn, isSer, lon, lat);
    this->cnt++;
    return true;
  }
  else
    return false;
}

template <typename entityType>
void EntityArray<entityType>::print()
{
  for(int i = 0; i < this->cnt; i++)
    this->entityPtr[i]->print();
}














int main()
{
  EntityArray<Car> ca;
  ca.add("5HE-313", true, true, 0, 0);
  ca.add("LPA-039", true, false, 1, 1);  
  ca.print();

  EntityArray<Passenger> pa;
  pa.add("B90705023", true, true, 0, 0);
  pa.add("R94725008", true, false, 1, 1);  
  pa.print();
  
  return 0;
}

