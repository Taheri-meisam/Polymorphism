#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
// override 
// virtual function 

class Animal {
public:
    std::string name;
    short age;
public:
     virtual void Say() {
        std::cout << "Hey, I am an animal" << std::endl;
    }
};

class Dog : public Animal{
public:
    void Say() {
        std::cout << "Hey, I am Dog and I say woof woof " << std::endl;
    }

};

class Cat : public Animal {
public:
    void Say()  {
        std::cout << " I am a Cat and I say Meew Meew" << std::endl;
    }
};

void AnimalSay(Animal& obj) {
    obj.Say();
}

void AnimalSayPtr(std::shared_ptr<Animal> object) {
    object->Say();
}


static constexpr int KEY_UP = 72;
static constexpr int KEY_DOWN = 80;
static constexpr int KEY_LEFT = 75;
static constexpr int KEY_RIGHT = 77;


int main()
{

    Animal a_Obj;
    Dog d_Obj;
    Cat c_Obj;
    a_Obj.Say();
    d_Obj.Say();
    c_Obj.Say();

    // We are passing an object to a function by reference 
    AnimalSay(a_Obj);
    AnimalSay(d_Obj);
    AnimalSay(c_Obj);
    ///
    std::cout << std::setfill('*') << std::setw(40) << " C standard pointers " << std::endl;
    Animal* a = new Animal();
    Animal* d = new Dog();
    Animal* c = new Cat();
    a->Say();
    d->Say();
    c->Say();

    delete a;
    delete d;
    delete c;

    // This is for your infromation // Smart Pointer 
    std::cout << std::setfill('*') << std::setw(40)<< "  Unique pointers " << std::endl;
    std::unique_ptr<Animal> AN(new Animal);
    std::unique_ptr<Animal> DO(new Dog);
    std::unique_ptr<Animal> CA(new Cat);

    AN->Say();
    DO->Say();
    CA->Say();
    // shared Pointers 
    std::cout << std::setfill('-') << std::setw(40) << " Shared pointers " << std::endl;
    std::shared_ptr<Animal> ANs(new Animal);
    std::shared_ptr<Animal> DOs(new Dog);
    std::shared_ptr<Animal> CAs(new Cat);

    AnimalSayPtr(ANs);
    AnimalSayPtr(DOs);
    AnimalSayPtr(CAs);
    return 0;
}

