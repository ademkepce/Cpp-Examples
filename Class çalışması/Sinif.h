#pragma once
#include<iostream>
#include<string>
#include"Ogrenci.h"
using namespace std;

class Sinif
{
public:
	string sinifIsmi;
	int toplamSinifSayisi;
	Ogrenci sinifMevcudu[100];
	int ogrenciSayisi;

	Sinif();

	void OgrenciEkle(Ogrenci ogr);

	void OgrenciSil(Ogrenci ogr);

	string SinifAdiOlustur();

};



