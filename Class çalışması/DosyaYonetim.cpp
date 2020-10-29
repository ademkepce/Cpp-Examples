#include "DosyaYonetim.h"

using namespace std;

string DosyaYonetim::AdSay(int sayi)
{
	string isim;
	ifstream oku;
	oku.open("isimler.txt");
	if (oku.is_open())
	{
		for (int i = 0; i < sayi; i++)
		{
			oku >> isim;
		}
		return isim;
	}
	oku.close();

}

void DosyaYonetim::RandomAtamalar(Ogrenci ogr)
{
	ogr.setAd(AdSay(rand() % 4945));
	ogr.setSoyAd(SoyadSay(rand() % 278));
	ogr.setNumara("100");
}

string DosyaYonetim::SoyadSay(int sayi)
{
	string soyad;
	ifstream oku;
	oku.open("soyisimler.txt");
	if (oku.is_open())
	{
		for (int i = 0; i < sayi; i++)
		{
			oku >> soyad;
		}
		return soyad;
	}
	oku.close();
}


void DosyaYonetim::Kayit(Ogrenci ogr)
{
	ofstream yaz;
	yaz.open("kayýtlar.txt");
	if (yaz.is_open())
	{
		yaz << ogr.getAd() << ogr.getSoyAd() << ogr.getNumara() << endl;
	}
	yaz.close();


}
