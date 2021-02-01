#include <iostream>
#include <string>
#include<stdlib.h>
#include <Windows.h>
#include <iomanip>
using namespace std;
#include "deklaracje.h";

//wyœwietlanie siatki do instrukcji gry
void wyswietl() {
	string siatka[3][3] = { { "1", "2", "3" }, { "4","5","6" },{"7","8","9"} };
	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {
			cout <<" "<<siatka[i][j] << "  ";
		
		}
		cout << endl;
	}
}
//wyœwietlanie siatki w wybranym fromacie
void wyswietl_siatke(string ** siatka2) {
	cout << "     |     |     " << endl;
	cout << "  " << siatka2[0][0] << "  |  " << siatka2[0][1] << "  |  " << siatka2[0][2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << siatka2[1][0] << "  |  " << siatka2[1][1] << "  |  " << siatka2[1][2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << siatka2[2][0] << "  |  " << siatka2[2][1] << "  |  " << siatka2[2][2] << endl;

	cout << "     |     |     " << endl << endl;
}
//sprawdzanie ka¿dego pola czy nie jest zajête
bool sprawdz_czy_puste(string** plansza, string znak, int ruch) {

	if (ruch == 1) {
		if (plansza[0][0] == "X" || plansza[0][0] == "O") {
			return false;
		}
		else {
			plansza[0][0] == znak;
			return true;
		}
	}

	if (ruch == 2) {
		if (plansza[0][1] == "X" || plansza[0][1] == "O") {
			return false;
		}
		else {
			plansza[0][1] == znak;
			return true;
		}
	}

	if (ruch == 3) {
		if (plansza[0][2] == "X" || plansza[0][2] == "O") {
			return false;
		}
		else {
			plansza[0][2] == znak;
			return true;
		}
	}

	if (ruch == 4) {
		if (plansza[1][0] == "X" || plansza[1][0] == "O") {
			return false;
		}
		else {
			plansza[1][0] == znak;
			return true;
		}
	}

	if (ruch == 5) {
		if (plansza[1][1] == "X" || plansza[1][1] == "O") {
			return false;
		}
		else {
			plansza[1][1] == znak;
			return true;
		}
	}

	if (ruch == 6) {
		if (plansza[1][2] == "X" || plansza[1][2] == "O") {
			return false;
		}
		else {
			plansza[1][2] == znak;
			return true;
		}
	}
	if (ruch == 7) {
		if (plansza[2][0] == "X" || plansza[2][0] == "O") {
			return false;
		}
		else {
			plansza[2][0] == znak;
			return true;
		}
	}
	if (ruch == 8) {
		if (plansza[2][1] == "X" || plansza[2][1] == "O") {
			return false;
		}
		else {
			plansza[2][1] == znak;
			return true;
		}
	}
	if (ruch == 9) {
		if (plansza[2][2] == "X" || plansza[2][2] == "O") {
			return false;
		}
		else {
			plansza[2][2] == znak;
			return true;
		}
	}
    }
//przypisanie numeru pola do ka¿dego pola w siatce (tablica wielowymiarowa)
	void zapisz(string** plansza, int ruch, string gracz) {
		if (ruch == 1) {
			plansza[0][0] = gracz;
		}
		else if (ruch == 2) {
			plansza[0][1] = gracz;
		}
		else if (ruch == 3) {
			plansza[0][2] = gracz;
		}
		else if (ruch == 4) {
			plansza[1][0] = gracz;
		}
		else if (ruch == 5) {
			plansza[1][1] = gracz;
		}
		else if (ruch == 6) {
			plansza[1][2] = gracz;
		}
		else if (ruch == 7) {
			plansza[2][0] = gracz;
		}
		else if (ruch == 8) {
			plansza[2][1] = gracz;
		}
		else if (ruch == 9) {
			plansza[2][2] = gracz;
		}
	}

	void koniec(string** plansza, string nickname, string z) {
		char litera_s = 0x98;
		char litera_a = 0xa5;
		char litera_e = 0xa9;

		//sprawdzanie zwyciêzcy w kolumnie
		if ((plansza[0][0]==z && plansza[1][0]==z && plansza[2][0]==z) || 
			(plansza[0][1] == z && plansza[1][1] == z && plansza[2][1] == z) ||
			(plansza[0][2] == z && plansza[1][2] == z && plansza[2][2] == z)){
			wyswietl_siatke(plansza);
			Sleep(500); //zatrzymanie planszy na pó³ sekundy
			cout << endl;
			cout << nickname << " jeste" << litera_s << " zwyci" << litera_e << "zc" << litera_a << "!\n ";

			exit(0); //zakoñczenie programu
		}
		//sprawdzanie zwyciêzcy w wierszu - poziom
		else if((plansza[0][0] == z && plansza[0][1] == z && plansza[0][2] == z) ||
			(plansza[1][0] == z && plansza[1][1] == z && plansza[1][2] == z) ||
			(plansza[2][0] == z && plansza[2][1] == z && plansza[2][2] == z)) {
			wyswietl_siatke(plansza);
			Sleep(500); //zatrzymanie planszy na pó³ sekundy
			cout << endl;
			cout << nickname << " jeste" << litera_s << " zwyci" << litera_e << "zc" << litera_a << "!\n ";

			exit(0); //zakoñczenie programu
			
		}
		//sprawdzanie zwyciêzcy na skosach
		else if ((plansza[0][0] == z && plansza[1][1] == z && plansza[2][2] == z) ||
			(plansza[0][2] == z && plansza[1][1] == z && plansza[2][0] == z)) {
			wyswietl_siatke(plansza);
			Sleep(500); //zatrzymanie planszy na pó³ sekundy
			cout << nickname << " jeste"<<litera_s<< " zwyci"<<litera_e<<"zc"<<litera_a<<"!\n ";
			exit(0); //zakoñczenie programu
		}
		// sprawdzenie czy plansza jest pusta
		int licznik = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (plansza[i][j] == "-") {
					licznik++;
				}
			}
		}
		//og³oszenie remisu (gdy wczeœniej program nie znalaz³ zwyciêzcy i wszystkie pola s¹ zajête)
		if (licznik == 0) {
			wyswietl_siatke(plansza);
			cout << "To jest remis!";
			exit(0); //zakoñczenie programu
		}

	}

