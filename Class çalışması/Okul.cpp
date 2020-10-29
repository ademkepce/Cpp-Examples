#include "Okul.h"

using namespace std;

Okul::Okul()
{
	sinifSayisi = 0;
	string sinifAdi;
	int ogrSayisi;
	string ad, soyad, numara;
	ifstream oku;
	oku.open("kayýtlar.txt");
	if (oku.is_open())
	{
		while (!oku.eof())
		{
			oku >> sinifAdi;
			siniflar[sinifSayisi].sinifIsmi = sinifAdi;
			oku >> ogrSayisi;
			siniflar[sinifSayisi].ogrenciSayisi = ogrSayisi;

			if (ogrSayisi > 0)
			{
				for (int i = 0; i < ogrSayisi; i++)
				{
					oku >> ad >> soyad >> numara;

					siniflar[sinifSayisi].sinifMevcudu[siniflar[sinifSayisi].ogrenciSayisi].setAd(ad);
					siniflar[sinifSayisi].sinifMevcudu[siniflar[sinifSayisi].ogrenciSayisi].setSoyAd(soyad);
					siniflar[sinifSayisi].sinifMevcudu[siniflar[sinifSayisi].ogrenciSayisi].setNumara(numara);
					siniflar[sinifSayisi].ogrenciSayisi++;
				}
			}
			sinifSayisi++;
		}
	}
}

char solUstKose = 201;
char duz = 205;
char sagUstKose = 187;
char solAltKose = 200;
char sagAltKose = 188;
char dikey = 186;

void Okul::ustYazdir()
{

	cout << solUstKose;
	for (int i = 0; i < 3; i++)
	{
		cout << duz;
	}
	cout << sagUstKose;
}

void Okul::altYazdir()
{
	cout << solAltKose;
	for (int i = 0; i < 3; i++)
	{
		cout << duz;
	}
	cout << sagAltKose;
}

void Okul::Yazdir()
{
	for (int i = 0; i < sinifSayisi; i++)
	{
		ustYazdir();
	}

	for (int i = 0; i < sinifSayisi; i++)
	{
		cout << siniflar[i].sinifIsmi;
	}

	for (int i = 0; i < sinifSayisi; i++)
	{
		altYazdir();
	}
}



