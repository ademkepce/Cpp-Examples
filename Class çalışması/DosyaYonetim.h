#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "Ogrenci.h"

using namespace std;


class DosyaYonetim
{
public:
	string AdSay(int sayi);
	string SoyadSay(int sayi);
	void RandomAtamalar(Ogrenci);
	void Kayit(Ogrenci ogr);

};



