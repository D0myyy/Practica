#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int minID = 30;

void Sarcina1(){
    ifstream Toys("Toys.txt");
    string lineToys;
    while(getline(Toys, lineToys)){
        istringstream iss(lineToys);
        string name, category;
        int price, quantity, ID;
        iss >> name >> price >> quantity >> category >> ID;
        //cout << name << " " << price << " " << quantity << " " << category << " " << ID << endl;
        cout << left << setw(20) << name
             << setw(10) << price
             << setw(10) << quantity
             << setw(15) << category
             << setw(5) << ID << endl;
        }
        cout << endl;
}

void Sarcina2(){
    ifstream Manufacturer("Manufacturer.txt");
    string lineManufacturer;
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
}

void Sarcina3(){
    ofstream Toys("Toys.txt", ios::app);
    // Creare variabile
    string name, category;
    int price, quantity, ID;

    // Introducerea de la tastatura a detaliilor despre jucaria noua
    cout << "Introdu numele jucariei: ";
    cin >> name;
    cout << "Introdu pretul jucariei: ";
    cin >> price;
    cout << "Introdu cantitatea jucariei: ";
    cin >> quantity;
    cout << "Introdu categoria (fete/baieti/copii_mici) jucariei: ";
    cin >> category;
    while(category != "fete" && category != "baieti" && category != "copii_mici"){
        cout << "Alege o categorie valida" << endl;
        cout << "Introdu categoria (fete/baieti/copii_mici) jucariei: ";
        cin >> category;
    }
    // Adauga informatia la fisier
    Toys << name << " " << price << " " << quantity << " " << category;
}

void Sarcina4(){
    ofstream Manufacturer("Manufacturer.txt", ios::app);
    // Creare variabile
    string name, country;
    minID++;

    // Introducerea de la tastatura a detaliilor despre jucaria noua
    cout << "Introdu numele producatorului: ";
    cin >> name;
    cout << "Introdu tara producatorului: ";
    cin >> country;
    // Adauga informatia la fisier
    Manufacturer << minID << " " << name << " " << country;
}

int Sarcina5(){
    ifstream Toys("Toys.txt");
    ofstream temp("temp.txt");

    if (!Toys || !temp) {
        cout << "Errouarie" << endl;
        return 1;
    }

    string target;
    cout << "Introdu numele jucariei pe care o doresti stearsa: ";
    cin >> target;

    string line;
    while (getline(Toys, line)) {
        if (line.find(target) != 0) {
            temp << line << endl;
        }
    }

    Toys.close();
    temp.close();

    // Schimbam cu locurile
    remove("Toys.txt");
    rename("temp.txt", "Toys.txt");
}

void Sarcina6(){

}

void Sarcina7(){

}

void Sarcina8(){

}

void Sarcina9(){

}

void Sarcina10(){

}

void Sarcina11(){

}

void Sarcina12(){

}

int main(){
    ifstream Toys("Toys.txt");
    string lineToys;

    ifstream Manufacturer("Manufacturer.txt");
    string lineManufacturer;
    if(!Toys || !Manufacturer){
        cout << "Errare" << endl;
        return 1;
    }


    // Incepere program cu prezentarea obiectivelor:
    cout << "<------------------------------------------------|    MENIU    |-------------------------------------------------->" << endl << endl;
    cout << "1. Afisarea informatiilor despre toate jucariile" << endl;
    cout << "2. Afisarea informatiilor despre toti producatorii" << endl;
    cout << "3. Adaugarea informatiilor despre o jucarie noua" << endl;
    cout << "4. Adaugarea informatiilor despre un nou producator" << endl;
    cout << "5. Stergerea informatiilor despre o jucarie, numele a fost introdus de la tastatura" << endl;
    cout << "6. Stergerea informatiilor despre un producator, numele a fost introdus de la tastatura" << endl;
    cout << "7. Editarea informatiilor despre o jucarie, numele a fost introdus de la tastatura" << endl;
    cout << "8. Editarea informatiilor despre un producator, numele a fost introdus de la tastatura" << endl;
    cout << "9. Denumirile tuturor producatorilor si numarul de tipuri de jucarii fabricate de fiecare" << endl;
    cout << "10. Afisarea pe ecran in ordine alfabetica a tuturor denumirilor jucariilor destinate celor mici" << endl;
    cout << "11. Afisarea pe ecran a informatiilor despre jucaria cea mai scumpa si cea mai ieftina" << endl;
    cout << "12. Afisarea pe ecran a pretului mediu al tuturor jucariilor din categoria specificata" << endl << endl;
    cout << "<----------------------------------------------------------------------------------------------------------------->" << endl << endl;

    // Oferirea utilizatorului de a alege obiectivul:
    int input;
    cin >> input;
    cout << endl;

    // Citirea inputului si oferirea informatiei declarand functia
    switch(input){
        case 1:
            Sarcina1();
            break;
        case 2:
            Sarcina2();
            break;
        case 3:
            Sarcina3();
            break;
        case 4:
            Sarcina4();
            break;
        case 5:
            Sarcina5();
            break;
        case 6:
            Sarcina6();
            break;
        case 7:
            Sarcina7();
            break;
        case 8:
            Sarcina8();
            break;
        case 9:
            Sarcina9();
            break;
        case 10:
            Sarcina10();
            break;
        case 11:
            Sarcina11();
            break;
        case 12:
            Sarcina12();
            break;
    }
    Toys.close();
    Manufacturer.close();
    main();
    return 0;
}
