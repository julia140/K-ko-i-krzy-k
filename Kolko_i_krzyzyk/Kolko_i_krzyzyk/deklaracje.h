#pragma once
#include <iostream>
#include <string>
#include<stdlib.h>
#include <Windows.h>

using namespace std;


void wyswietl();
bool sprawdz_czy_puste(string** plansza, string znak, int ruch);
void wyswietl_siatke(string** siatka2);
void zapisz(string** plansza, int ruch, string gracz);
void koniec(string** plansza, string nickname, string z);