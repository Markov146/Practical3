﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Vehicle {
public:
    Vehicle(string make, string model, int year, int speed)
        : make_(make), model_(model), year_(year), speed_(speed) {}

    string GetMake() const { return make_; }
    string GetModel() const { return model_; }
    int GetYear() const { return year_; }
    int GetSpeed() const { return speed_; }

    virtual void PrintDetails() const {
        cout << "Make: " << make_ << endl;
        cout << "Model: " << model_ << endl;
        cout << "Year: " << year_ << endl;
        cout << "Speed: " << speed_ << endl;
    }

private:
    string make_;
    string model_;
    int year_;
    int speed_;
};

class Car : public Vehicle {
public:
    Car(string make, string model, int year, int speed, int num_doors, bool has_sunroof)
        : Vehicle(make, model, year, speed), num_doors_(num_doors),  {}

    int GetNumDoors() const { return num_doors_; }
     

    void PrintDetails() const override {
        Vehicle::PrintDetails();
        cout << "Количество дверей: " << num_doors_ << endl;
        
    }

private:
    int num_doors_;
    
};

class Truck : public Vehicle {
public:
    Truck(string make, string model, int year, int speed, int max_load, bool is_4x4)
        : Vehicle(make, model, year, speed), max_load_(max_load) {}

    int GetMaxLoad() const { return max_load_; }
    

    void PrintDetails() const override {
        Vehicle::PrintDetails();
        cout << "Максимальная нагрузка: " << max_load_ << endl;
       
    }

private:
    int max_load_;
    

void SortByYear(vector<Vehicle*>& vehicles, bool ascending) {
    if (ascending) {
        sort(vehicles.begin(), vehicles.end(), [](Vehicle* a, Vehicle* b) {
            return a->GetYear() < b->GetYear();
            });
    }
    else {
        sort(vehicles.begin(), vehicles.end(), [](Vehicle* a, Vehicle* b) {
            return a->GetYear() > b->GetYear();
            });
    }
}

void SortBySpeed(vector<Vehicle*>& vehicles, bool ascending) {
    if (ascending) {
        sort(vehicles.begin(), vehicles.end(), [](Vehicle* a, Vehicle* b) {
            return a->GetSpeed() < b->GetSpeed();
            });
    }
    else {
        sort(vehicles.begin(), vehicles.end(), [](Vehicle* a, Vehicle* b) {
            return a->GetSpeed() > b->GetSpeed();
            });
    }
}

vector<Vehicle*> FindByMakeAndModel(const vector<Vehicle*>& vehicles, const string& make, const string& model) {
    vector<Vehicle*> result;
    for (Vehicle* vehicle : vehicles) {
        if (vehicle->GetMake() == make && vehicle->GetModel() == model) {
            result.push_back(vehicle);
        }
    }
    return result;
}
int main() {
    Car* car1 = new Car("Audi", "A4", 2010, 100, 4, false);
    Car* car2 = new Car("Toyota", "Camry", 2005, 90, 4, true);
    Truck* truck1 = new Truck("Ford", "Mondeo", 2015, 80, 2, 5000);
    Truck* truck2 = new Truck("Lambargini", "Aventador", 2020, 70, 4, 6000);

    vector<Vehicle*> vehicles = { car1, car2, truck1, truck2 };
    SortByYear(vehicles, true);

    for (Vehicle* vehicle : vehicles) {
        vehicle->PrintDetails();
        cout << endl;
    }

    for (Vehicle* vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}﻿;
