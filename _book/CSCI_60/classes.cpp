#include <iostream>
#include <string>
#include <stdio.h>


class Animal{  
protected:
    std::string name_;
    int age;
public:
    Animal();
    Animal(std::string name, int age);
    std::string get_name();
    int get_age();
    friend void change_values(Animal &);
protected:
    int random;
};

class Cat: public Animal{
public:
    Cat(std::string name, int age);
    std::string get_name();
    int get_age();
    void changeRandom();
    void operator += (const Cat&);
    Cat& operator=(const Cat& c);
};

void getSomething(int a);
void getSomething(std::string a);


int main(){
    Animal a("barsuk", 50);
    Cat b("timosha", 30);
    Cat c("mikle", 60);

    change_values(b);
    b.changeRandom();

    getSomething(5);
    getSomething("6.5");
    c += b;
    a = b = c;

    printf("age: %d, name: %s\n", a.get_age(), a.get_name().c_str());
    printf("age: %d, name: %s\n", b.get_age(), b.get_name().c_str());
    printf("age: %d, name: %s\n", c.get_age(), c.get_name().c_str());
    return 0;
}


Animal::Animal(){
    name_ = "";
    age = 0;
}

Animal::Animal(std::string name, int age){
    this->name_ = name;
    this->age = age;
}

std::string Animal::get_name(){
    return name_;
}

int Animal::get_age(){
    return age;
}

std::string Cat::get_name(){
    return "cat" + Animal::get_name();
}

int Cat::get_age(){
    int temp_age = Animal::get_age();
    return temp_age * 2;
}

Cat::Cat(std::string name, int age):Animal(name, age){
}

void change_values(Animal & a){
    a.age = 100;
    a.name_ = "svfsv";
}

void Cat::changeRandom(){
    random = 423;
}

void getSomething(int a){
    std::cout << a*2 << std::endl;
}

void getSomething(std::string a){
    std::cout << a << std::endl;
}

void Cat::operator += (const Cat& c){
    this->name_ += c.name_;
    this->age += c.age;
}

Cat& Cat::operator=(const Cat& c){
    name_ = c.name_;
    age = c.age;
    return *this;
}

//write a function to change the values of the object
void change_values(Animal & a){
    a.age = 100;
    a.name_ = "svfsv";
}
