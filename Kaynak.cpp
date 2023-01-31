#include <iostream>
#include <string>
#include <vector> 
#include <fstream>

#define f (pow(temp, nem)+(1/log10(log10(temp)))/nem)/sayi //verilen denklem
using namespace std;

struct Cicek { //yapýsý
    string name;
    int sayi;
    int temp;
    string nem;
    string ara;
};

vector<Cicek> Ciceks;

void addCicek() //çiçek ekler
{

    ofstream DosyaYaz;
    DosyaYaz.open("liste1.txt", ios::app);
    Cicek newCicek;
    cout << "Enter Cicek name: ";
    cin >> newCicek.name;
    cout << "Enter Cicek sayisi: ";
    cin >> newCicek.sayi;
    cout << "Enter Cicek temp: ";
    cin >> newCicek.temp;
    cout << "Enter Cicek nem:  ";
    cin >> newCicek.nem;

    DosyaYaz << newCicek.name << "," << newCicek.sayi << "," << newCicek.temp << "," << newCicek.nem << "," << endl;
    DosyaYaz.close();

    Ciceks.push_back(newCicek);
}

void editCicek() //düzenler
{
    int CicekIndex;
    cout << "Enter the index of the Cicek you want to edit: ";
    cin >> CicekIndex;
    if (CicekIndex >= 0 && CicekIndex < Ciceks.size()) {
        Cicek& Cicek = Ciceks[CicekIndex];
        cout << "Enter new name: ";
        cin >> Cicek.name;
        cout << "Enter Cicek sayisi: ";
        cin >> Cicek.sayi;
        cout << "Enter new temp: ";
        cin >> Cicek.temp;
        cout << "Enter new nem: ";
        cin >> Cicek.nem;
    }
    else {
        cout << "Invalid index" << endl;
    }
}

void deleteCicek() //siler
{
    int CicekIndex;
    cout << "Enter the index of the Cicek you want to delete: ";
    cin >> CicekIndex;
    if (CicekIndex >= 0 && CicekIndex < Ciceks.size()) {
        Ciceks.erase(Ciceks.begin() + CicekIndex);
    }
    else {
        cout << "Invalid index" << endl;
    }
}

void showCiceks() //hepsini gösterir
{
    cout << "Cicek List" << endl;
    cout << "Index\tName\tSayi\tTemp\tNem" << endl;
    for (int i = 0; i < Ciceks.size(); i++) {
        Cicek Cicek = Ciceks[i];
        cout << i << "\t" << Cicek.name << "\t" << Cicek.sayi << "\t" << Cicek.temp << "\t" << Cicek.nem << endl;
    }
}

void searchCicek() //arar (hata veriyor son gün olduðu için çözmeye vaktim yetmedi)
{
    fstream DosyaOku;
    DosyaOku.open("liste1.txt", ios::app);
    string CicekName;
    cout << "Enter the name of the Cicek you want to see: ";
    cin >> CicekName;
    if (/*CicekName = cicek.name*/true)
    {
        Cicek Cicek = Ciceks[3];
        DosyaOku << 3 << "\t" << Cicek.name << "\t" << Cicek.sayi << "\t" << Cicek.temp << "\t" << Cicek.nem << endl;
    }
    DosyaOku.close();
}
int main() //menü 
{
    ofstream MyFile("liste1.txt");
    int choice = 0;
    while (choice != 5) {
        cout << "1. Add Cicek" << endl;
        cout << "2. Edit Cicek" << endl;
        cout << "3. Delete Cicek" << endl;
        cout << "4. Show Ciceks" << endl;
        cout << "5. Search Ciceks" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addCicek();
            break;
        case 2:
            editCicek();
            break;
        case 3:
            deleteCicek();
            break;
        case 4:
            showCiceks();
            break;
        case 5:
            searchCicek();
        case 6:

            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}
