#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    ifstream Toys("Toys.txt");
    string lineToys;

    ifstream Manufacturer("Manufacturer.txt");
    string lineManufacturer;

    if(!Toys || !Manufacturer){
        cerr << "Eruare" << endl;
        return 1;
    }

    while(getline(Toys, lineToys)){
        istringstream iss(lineToys);
        string name, category;
        int price, quantity, ID;
        iss >> name >> price >> quantity >> category >> ID;
        cout << name << " " << price << " " << quantity << " " << category << " " << ID << endl;
    }

    while(getline(Manufacturer, lineManufacturer)){
        istringstream iss(lineManufacturer);
        string name, category;
        int price, quantity, ID;
        iss >> name >> price >> quantity >> category >> ID;
        cout << name << " " << price << " " << quantity << " " << category << " " << ID << endl;
    }

    Toys.close();
    Manufacturer.close();
    return 0;
}
