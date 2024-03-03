#include <iostream>
#include <string>
using namespace std;

class car
{
    public:
    // Member Variables:
    string color;
    private:
    string vendor;
    float fuel;
    public:
    static int NumberOfCars;
    
    int carnum;
    // Methods:
    public:
    void modify_vendor(string s){
        vendor = s;

    }
    int Fleetsize();
    void drive();
    void refuel(float f);
    float getfuel();
    string getcolor();
    string getvendor(){
        return vendor;
    }
    //Constructor:
    car() : color("White") , vendor ("VW") {}
    car(string c, string v = "VW") : color(c), vendor(v) ,fuel(0) {
        NumberOfCars++;
        carnum++;
    }
    //constructor is always public and for the other things you can choose whether you want them to be pubic or not
    
    //Destructor:
    ~car(){
        cout << "DELETED: " << color << " " << vendor << endl;
    }
    //Destructor is not mandetory but ut should be there, a good way to justify it is to say that you dont delete everything you make but you make that thing once
};

int car::NumberOfCars = 0;
void car::drive(){
    if(fuel > 10){
        fuel = fuel - 10;
    }
}
int car::Fleetsize(){
    return NumberOfCars;
}

float car::getfuel(){
        return fuel;
}

void car::refuel(float f){
        fuel = fuel + f;
}
string car::getcolor(){
    return color;
}
class bus : public car{
bus(){

}
~bus(){
    
}
}; 
int main(int __attribute__((unused)) argc,char __attribute__((unused)) *argv[])
{
    car kl_tu_1("Green","BMW");
    kl_tu_1.modify_vendor("FORD");
    cout << kl_tu_1.getvendor() << endl;
    cout << kl_tu_1.getfuel() << endl;
    kl_tu_1.refuel(100.0);
    kl_tu_1.drive();
    kl_tu_1.drive();
    cout << kl_tu_1.getfuel() << endl;

    car * hom_mj_687 = new car("red", "toyota");
    hom_mj_687->refuel(100.0);
  
    cout<< kl_tu_1.getvendor()<< " ";
    cout<< kl_tu_1.getcolor()<<endl;
    cout << kl_tu_1.NumberOfCars<<endl;
    cout << hom_mj_687->NumberOfCars<<endl;
    car kl_tu_2("Green","BMW");
    cout << kl_tu_2.NumberOfCars<<endl;
    cout << car::NumberOfCars<<endl;
    cout << hom_mj_687->Fleetsize() <<endl;
    cout << hom_mj_687->color << endl;
    delete hom_mj_687;
    cout << kl_tu_1.getfuel()<<endl;
    
} 