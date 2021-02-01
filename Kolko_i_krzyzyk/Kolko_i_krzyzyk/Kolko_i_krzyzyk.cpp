#include <iostream>
#include <string>
#include<stdlib.h>
#include<iomanip>
#include <Windows.h>
#include "deklaracje.h";
using namespace std;

int main() {
	//wprowadzenie polskich znaków do gry za pomoc¹ code page 852
	char litera_o = 0xa2;
	char litera_l = 0x88;
	char litera_z = 0xbe;
	char litera_c = 0x86;
	char litera_e = 0xa9;
	char litera_a = 0xa5;
	char litera_s = 0x98;
	char litera_zi = 0xab;
	//zmienne do ramki
	char lewy_gora = 0xc9;
	char proste = 0xcd;
	char prawy_gora = 0xbb;
	char lewy_dol = 0xc8;
	char prawy_dol = 0xbc;
	char pion = 0xba;
	//wyœwietlanie menu w pêtli umo¿liwiaj¹cej wybór dalszych kroków rozgrywki
	while (true) {
		cout <<" "<< lewy_gora << setfill(proste) << setw(16) << prawy_gora << endl;
		cout <<" "<<pion<< "K" << litera_o << litera_l << "ko i krzy" << litera_z << "yk"<<pion<< endl;
		cout << " "<<lewy_dol << setfill(proste) << setw(16) << prawy_dol << endl;
		cout << endl;
		cout << " Menu: " << endl;
		cout << endl;
		int menu_odp;
		
		cout << " 1. Instrukcja gry" << endl;
		cout << " 2. Zacznij gr"<<litera_e << endl;
		cout << " 3. Zamknij program" << endl;
		cout << endl;
		cout << " Wybierz numer: ";
		cin >> menu_odp;
		if (menu_odp == 1) {
			system("CLS");
			cout << " _________________" << endl;
			cout << endl;
			cout <<"  Instrukcja gry "<<endl;
			cout << " _________________" << endl;
			cout << endl;
			cout << "Gracze obejmuj"<<litera_a<<" pola na przemian d"<<litera_a<<litera_z<<litera_a<<"c do obj"<<litera_e<<"cia trzech p"<<litera_o<<"l w jednej linii(pion,poziom lub skos),\nprzy jednoczesnym uniemo"<<litera_z<<"liwieniu tego samego przeciwnikowi." << endl;
			cout<<"Pole mo"<<litera_z<<"e by"<<litera_c<<" obj"<<litera_e<<"te przez jednego gracza i nie zmienia swego w"<<litera_l<<"a"<<litera_s<<"ciciela przez ca"<<litera_l<<"y przebieg gry."<< endl;
			cout << "Gracz, kt"<<litera_o<<"ry jako pierwszy wpisze nickname zaczyna rozgrywk"<<litera_e<<".\nPrzydzielony zostaje mu symbol X, natomiast drugiemu O. " << endl;
			cout << "Aby wybra"<<litera_c<<" pole w grze nale"<<litera_z<<"y wpisa"<<litera_c<<" cyfr"<<litera_e<<" od 1 do 9. Numeracja siatki: " << endl;
			cout << endl;
			wyswietl();
			int odp_2;
			cout << endl;
			cout << "* Aby zacza"<<litera_c<<" gr" << litera_e << " kilknij 2 albo powr"<<litera_o<<litera_c<< " do menu - dowolny numer * ";
			cin >> odp_2;
			if (odp_2 == 2) {
				system("CLS");//czyszczenie okna konsoli
				break;
			}
			else {
				system("CLS");//czyszczenie okna konsoli

				continue;
			}
		}
		if (menu_odp == 2) {
			system("CLS");//czyszczenie okna konsoli
			break;
		}
		if (menu_odp == 3) {
			system("CLS");//czyszczenie okna konsoli
			exit(0);
		}
		else {
			system("CLS");//czyszczenie okna konsoli
			continue;
		}
	}
	//pobranie nickname'ów od graczy
	string nickname1;
	string nickname2;
	cout << " Podaj nickname gracza pierwszego: ";
	cin >> nickname1;
	cout << endl;
	cout << " Podaj nickname gracza drugiego: ";
	cin >> nickname2;
	system("CLS");
	// inicjowanie planszy gry - tablica dyamiczna
	string** plansza = new string * [3];

	for (int i = 0; i < 3; ++i)
	{
		plansza[i] = new string[3]; //alokacja pamiêci
		for (int j = 0; j < 3; ++j) 
			plansza[i][j] = "-";
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
		 plansza[i][j];
		}
	
	}

	//ruch gracza 1
	while (true) {
		int ruchGracza1, ruchGracza2;
		while (true) {
			wyswietl_siatke(plansza);
			cout << "Ruch gracza " << nickname1 << " - podaj cyfr"<<litera_e<<" (1-9): "; //wybór numeru pola gracza pierwszego
			cin >> ruchGracza1;
			// sprawdzenie poprawnoœci wpisanej cyfry przez u¿ytkownika
			if (ruchGracza1 <= 9 && ruchGracza1 >= 1) {  
				if (sprawdz_czy_puste(plansza,"X",ruchGracza1)) {
					zapisz(plansza, ruchGracza1, "X");
					system("CLS");
					break;
				}
				else
				{
					system("CLS");//czyszczenie okna konsoli
					cout << "Zaj"<<litera_e<<"te pole! Wybierz jeszcze raz: " << endl;
					continue;
				}
			}
			else {
				system("CLS");//czyszczenie okna konsoli
				cout << "Poda"<<litera_l<<"e"<<litera_s<<" b"<<litera_l<<litera_e<<"dn"<<litera_a<<" odpowied"<<litera_zi<<"! Spr"<<litera_o<<"buj jeszcze raz: " << endl;
				continue;
			}
		}
		koniec(plansza, nickname1, "X");
		//ruch gracza 2
		while (true) {
			wyswietl_siatke(plansza);
			cout << "Ruch gracza " << nickname2 << " - podaj cyfr" << litera_e << " (1-9): ";//wybór numeru pola gracza drugiego
			cin >> ruchGracza2;
			// sprawdzenie poprawnoœci wpisanej cyfry przez u¿ytkownika
			if (ruchGracza2 <= 9 && ruchGracza2 >= 1) {
				if (sprawdz_czy_puste(plansza, "O", ruchGracza2)) {
					zapisz(plansza, ruchGracza2, "O");
					system("CLS");//czyszczenie okna konsoli
					break;
				}
				else
				{
					system("CLS");//czyszczenie okna konsoli
					cout << "Zaj" << litera_e << "te pole! Wybierz jeszcze raz: " << endl;
					continue;
				}
			}
			else {
				system("CLS");//czyszczenie okna konsoli
				cout << "Poda" << litera_l << "e" << litera_s << " b" << litera_l << litera_e << "dn" << litera_a << " odpowied" << litera_zi << "! Spr" << litera_o << "buj jeszcze raz: " << endl;
				continue;
			}
		}
		koniec(plansza, nickname2, "O");

		}

	for (int i = 0; i < 3; i++) { // zwolnienie pamiêci z tablicy dynamicznej
		delete[] plansza[i];
	}
	delete[] plansza;


	
}
