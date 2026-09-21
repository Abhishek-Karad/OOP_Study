#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<deque>
#include<climits>
#include<numeric>

using namespace std;

/*
Problem Statement:
Vehicle Rental System

Design a vehicle rental system using OOP.

Requirements:
1. Create a base Vehicle class with:
   - ID, brand, model, rent per day, availability.
   - Vehicle state must be encapsulated using private members.
   - Support renting and returning vehicles.
   - Provide getters for vehicle information.

2. Create derived classes:
   - Car: has number of seats.
   - Truck: has ton capacity.

3. Different vehicle types can have different rental calculations:
   - Car: rentPerDay × days.
   - Truck: (rentPerDay × days) + (tonCapacity × 100).

4. Vehicle should define a common interface for:
   - Rental calculation.
   - Displaying vehicle details.

5. Use OOP concepts:
   - Encapsulation: private vehicle data with controlled access.
   - Inheritance: Car and Truck inherit from Vehicle.
   - Abstraction: calculateRent() is a pure virtual function.
   - Polymorphism: Vehicle* can refer to Car/Truck and invoke their
     overridden calculateRent() and displayDetails() methods.
*/

class Vehicle{
    private:
    int v_Id;
    string Brand;
    string Model;
    int rent_per_day;
    bool isAvailable;

    public:
    Vehicle(int id,string Brand,string Model,int rentperday){
        this->v_Id=id;
        this->Brand=Brand;
        this->rent_per_day=rentperday;
        this->Model=Model;
        this->isAvailable=true;
    };

    void rent(){
        if(isAvailable==false){
            cout<<"Vehicle already in use"<<endl;
            return;
        }
        int days=0;
        cout<<"Enter number of days rented"<<endl;
        cin>>days;
        cout<<"Rental Bill : "<<calculateRent(days)<<endl;
        isAvailable=false;
       
    };

    //This will be overridden in each child class
    virtual double calculateRent(int days)=0;

    void returnVehicle(){
        if(isAvailable==true){
            cout<<"Vehicle is already available"<<endl;
            return;
        }
        isAvailable=true;
        cout<<"Vehicle returned successfully"<<endl;
    };  

    virtual void displayDetails(){
        cout<<"Id: "<<getId()<<endl;
        cout<<"Name: "<<getModel()<<endl;
        cout<<"Status: "<<getAvailability()<<endl;
      
    };

     //Getters and Setters
    int getId(){
       return v_Id;

    };

    string getBrand(){
        return Brand;
    };
    string getModel(){
        return Model;

    };
    int getRentPerDay(){
        return rent_per_day;

    };
    bool getAvailability(){
        return isAvailable;
    };
    
};


class Car : public Vehicle {
private:
    int numberOfSeats;

public:
    Car(int id, string brand, string model, int rentPerDay, int seats)
        : Vehicle(id, brand, model, rentPerDay) {
        
        numberOfSeats = seats;
    }

    int getSeats() {
        return numberOfSeats;
    }

    void displayDetails() override{
        Vehicle::displayDetails();
        cout<<"Number of seats "<<numberOfSeats<<endl;
        cout<<"_________________________________"<<endl;
    }


    //independent rent calculation based on car purely not comman 
    double calculateRent(int days)override {
        return getRentPerDay()*days;
    }


};

class Truck: public Vehicle{
    private:
    int TonnCapacity;

    public:
    Truck(int id, string brand,string model,int rentPerDay,int TonnCapcity):Vehicle(id,brand,model,rentPerDay){
        TonnCapacity=TonnCapcity;
    }


    void displayDetails() override {
        Vehicle::displayDetails();

        cout << "Ton Capacity: "<< TonnCapacity << endl;
        cout<<"_________________________________"<<endl;
    }

    double calculateRent(int days)override{
        return getRentPerDay()*days+TonnCapacity*100;
    }
};


int main() {

    Vehicle* v1 = new Car(1, "Audi", "Audi A4", 1000, 5);
    Vehicle* v2 = new Truck(2, "Tata", "Tata 407", 5000, 10);

    v1->displayDetails();
    v2->displayDetails();

    cout << "---- Car Rental ----" << endl;
    v1->rent();

    cout << "---- Truck Rental ----" << endl;
    v2->rent();

    cout << "Car Available: "
         << v1->getAvailability() << endl;

    cout << "Truck Available: "
         << v2->getAvailability() << endl;

    // delete v1;
    // delete v2;

    return 0;
}