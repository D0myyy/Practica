#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

void addToy(string name, int price, int quantity, string category, int ID){

}

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
        //cout << name << " " << price << " " << quantity << " " << category << " " << ID << endl;
        cout << left << setw(15) << name
             << setw(10) << price
             << setw(10) << quantity
             << setw(15) << category
             << setw(5) << ID << endl;
    }
    cout << endl;

    while(getline(Manufacturer, lineManufacturer)){
        istringstream iss(lineManufacturer);
        string name, country;
        int ID;
        iss >> ID >> name >> country;
        //cout << ID << " " << name << " " << country << endl;
        cout << left << setw(5) << ID
             << setw(15) << name
             << setw(15) << country << endl;
    }
    cout << endl;

    Toys.close();
    Manufacturer.close();
    return 0;
}
