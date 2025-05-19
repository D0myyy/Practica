#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int maxIDM = -1;

int maxIDManufacturer(){
    ifstream file("Manufacturer.txt");

    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        int ID;
        iss >> ID;

        if (ID > maxIDM) {
            maxIDM = ID;
        }
    }

    file.close();
    maxIDM++;
    return maxIDM;
}

bool compararePrimaLitera(const string& a, const string& b) {
    string lowerA = a, lowerB = b;
    transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
    transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);
    return lowerA < lowerB;
}

void Sarcina1(){
    ifstream Toys("Toys.txt");
    string lineToys;
    while(getline(Toys, lineToys)){
        istringstream iss(lineToys);
        string name, category;
        int price, quantity, ID;
        iss >> name >> price >> quantity >> category >> ID;

        cout << left << setw(20) << name
             << setw(10) << price
             << setw(10) << quantity
             << setw(15) << category
             << setw(5) << ID << endl;
        }
        cout << endl;
        Toys.close();
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
    Manufacturer.close();
}

void Sarcina3(){
    ofstream Toys("Toys.txt", ios::app);
    // Creare variabile
    string name, category;
    int price, quantity, ID;

    // Introducerea de la tastatura a detaliilor despre jucaria noua
    cout << "Introdu numele jucariei(fara spatiu): ";
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
    cout << "Introdu codul producatorului (1-" << maxIDManufacturer() << "): ";
    cin >> ID;
    // Adauga informatia la fisier
    Toys << name << " " << price << " " << quantity << " " << category << " " << ID;
    Toys.close();
}

void Sarcina4(){
    ofstream Manufacturer("Manufacturer.txt", ios::app);
    // Creare variabile
    string name, country;

    // Introducerea de la tastatura a detaliilor despre jucaria noua
    cout << "Introdu numele producatorului(fara spatiu): ";
    cin >> name;
    cout << "Introdu tara producatorului: ";
    cin >> country;
    // Adauga informatia la fisier
    Manufacturer << maxIDManufacturer() << " " << name << " " << country;
    Manufacturer.close();
}

void Sarcina5(){
    ifstream Toys("Toys.txt");
    ofstream temp("temp.txt");

    string target;
    cout << "Introdu numele jucariei pe care doresti sa o stergi: ";
    cin >> target;

    string line;
    while (getline(Toys, line)) {
        istringstream iss(line);
        string name;
        iss >> name;

        for (char& c : name) {
            c = tolower(c);
        }
        for (char& c : target) {
            c = tolower(c);
        }
        if (name != target) {
            temp << line << endl;
        }
    }

    Toys.close();
    temp.close();

    remove("Toys.txt");
    rename("temp.txt", "Toys.txt");
}

void Sarcina6(){
    ifstream Manufacturer("Manufacturer.txt");
    ofstream temp("temp2.txt");

    string target;
    cout << "Introdu numele producatorului pe care doresti sa il stergi: ";
    cin >> target;

    string line;
    while (getline(Manufacturer, line)) {
        istringstream iss(line);
        string name;
        int ID;
        iss >> ID >> name;

        for (char& c : name) {
            c = tolower(c);
        }
        for (char& c : target) {
            c = tolower(c);
        }
        if (name != target) {
            temp << line << endl;
        }
    }

    Manufacturer.close();
    temp.close();

    remove("Manufacturer.txt");
    rename("temp2.txt", "Manufacturer.txt");
}

void Sarcina7(){
    ifstream Toys("Toys.txt");
    ofstream temp("temp3.txt");

    string target;
    cout << "Introdu numele jucariei pe care doresti sa o editezi: ";
    cin >> target;

    string line;
    while (getline(Toys, line)) {
        istringstream iss(line);
        string name;
        iss >> name;

        for (char& c : name) {
            c = tolower(c);
        }
        for (char& c : target) {
            c = tolower(c);
        }
        if (name != target) {
            temp << line << endl;
        } else {
            Sarcina3();
        }
    }

    Toys.close();
    temp.close();

    remove("Toys.txt");
    rename("temp3.txt", "Toys.txt");
}

void Sarcina8(){
    ifstream Manufacturer("Manufacturer.txt");
    ofstream temp("temp4.txt");

    string target;
    cout << "Introdu numele jucariei pe care doresti sa o editezi: ";
    cin >> target;

    string line;
    while (getline(Manufacturer, line)) {
        istringstream iss(line);
        int ID;
        string name;
        iss >> ID >> name;

        for (char& c : name) {
            c = tolower(c);
        }
        for (char& c : target) {
            c = tolower(c);
        }
        if (name != target) {
            temp << line << endl;
        } else {
            Sarcina4();
        }
    }

    Manufacturer.close();
    temp.close();

    remove("Manufacturer.txt");
    rename("temp4.txt", "Manufacturer.txt");
}

int Sarcina9(){
    map<int, string> producatori; // ID  Nume
    map<int, int> jucariiPerProducator; // ID  nr jucarii

    ifstream fileProd("Manufacturer.txt");
    if (!fileProd) {
        cout << "Eroare la deschiderea Manufacturer.txt\n";
        return 1;
    }

    string line;
    while (getline(fileProd, line)) {
        istringstream iss(line);
        int id;
        string nume, tara;
        iss >> id >> nume >> tara;
        producatori[id] = nume;
        jucariiPerProducator[id] = 0;
    }
    fileProd.close();

    ifstream fileToys("Toys.txt");
    if (!fileToys) {
        cerr << "Eroare la deschiderea Toys.txt\n";
        return 1;
    }

    while (getline(fileToys, line)) {
        istringstream iss(line);
        string name, category;
        int price, quantity, idProd;
        iss >> name >> price >> quantity >> category >> idProd;
        jucariiPerProducator[idProd]++;
    }
    fileToys.close();

    ofstream output("Total.txt");
    if (!output) {
        cerr << "Eroare la crearea Total.txt\n";
        return 1;
    }

    output << "Producatori si numarul de tipuri de jucarii fabricate:\n\n";
    for (auto& pair : producatori) {
        int id = pair.first;
        string nume = pair.second;
        output << " " << nume << ": " << jucariiPerProducator[id] << " tipuri de jucarii\n";
    }
    output << endl;
    output.close();

    return 0;
}

void Sarcina10(){
    ifstream Toys("Toys.txt");
    string lineToys;

    vector<string> NumeleToys;

    while(getline(Toys, lineToys)){
        istringstream iss(lineToys);
        string name, category;
        int price, quantity, ID;
        iss >> name >> price >> quantity >> category >> ID;

        if(category == "copii_mici"){
            NumeleToys.push_back(name);
        }
        }

        sort(NumeleToys.begin(), NumeleToys.end(), compararePrimaLitera);
        for (const string& toy : NumeleToys) {
        cout << toy << endl;
        }
        cout << endl;
        Toys.close();
}

void Sarcina11(){
    ifstream file("Toys.txt");

    string line;
    string maxName, minName, maxCategory, minCategory;
    int maxPrice = -1, minPrice = 199999999, minQuantity, minID, maxQuantity, maxID;

    while (getline(file, line)) {
        istringstream iss(line);
        string name, category;
        int price, quantity, ID;
        iss >> name >> price >> quantity >> category >> ID;

        if (price > maxPrice) {
            maxPrice = price;
            maxName = name;
            maxQuantity = quantity;
            maxCategory = category;
            maxID = ID;
        }

        if (price < minPrice) {
            minPrice = price;
            minName = name;
            minQuantity = quantity;
            minCategory = category;
            minID = ID;
        }
    }

    file.close();

    cout << left << setw(25) << "Cea mai scumpa jucarie: ";
    cout << left << setw(20) << maxName
             << setw(10) << maxPrice
             << setw(10) << maxQuantity
             << setw(15) << maxCategory
             << setw(5) << maxID << endl;
    cout << "Cea mai ieftina jucarie: ";
    cout << left << setw(20) << minName
             << setw(10) << minPrice
             << setw(10) << minQuantity
             << setw(15) << minCategory
             << setw(5) << minID << endl;
}

void Sarcina12(){
    ifstream Toys("Toys.txt");

    string line;
    double totalPrice = 0;
    double toyCount = 0;

    string target;
    cout << "Introdu categoria (fete/baieti/copii_mici) al carui mediu vrei sa il iei: ";
    cin >> target;
    while(target != "fete" && target != "baieti" && target != "copii_mici"){
        cout << "Alege o categorie valida!" << endl;
        cout << "Introdu categoria (fete/baieti/copii_mici) al carui mediu vrei sa il iei: ";
        cin >> target;
    }

    while (getline(Toys, line)) {
        istringstream iss(line);
        string name, category;
        int price, quantity, ID;
        iss >> name >> price >> quantity >> category >> ID;

        for (char& c : category) {
            c = tolower(c);
        }
        for (char& c : target) {
            c = tolower(c);
        }
        if (category == target) {
            totalPrice += price;
            toyCount++;
        }
    }

    Toys.close();

    if (toyCount > 0) {
        double average = totalPrice / toyCount;
        cout << "Mediul jucariilor din categoria '" << target << "' este: " << average << endl << endl;
    } else {
        cout << "Nu sunt jucarii!";
    }
}

int main(){
    ifstream Toys("Toys.txt");
    string lineToys;

    ifstream Manufacturer("Manufacturer.txt");
    string lineManufacturer;
    if(!Toys || !Manufacturer){
        cout << "Eruare" << endl;
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
    Toys.close();
    Manufacturer.close();

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
        default:
            cout << "Alege o optiune valida!" << endl;
            main();
            break;
    }
    main();
    return 0;
}
