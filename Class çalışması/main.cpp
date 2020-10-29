#include <iostream>
#include<time.h>
#include<string>
#include <fstream>
#include <iomanip>

using namespace std;

class Ogrenci
{
public:

	Ogrenci()
	{
		numara = 0;
	}

	string getAd()
	{
		return ad;
	}

	void setAd(string adi)
	{
		ad = adi;
	}

	string getSoyAd()
	{
		return soyAd;
	}

	void setSoyAd(string soyadi)
	{
		soyAd = soyadi;
	}


	int getNumara()
	{
		return numara;
	}

	void setNumara(int no)
	{
		numara = no;
	}



private:
	string ad;
	string soyAd;
	int numara;
};


class DosyaYonetim
{
public:
	string AdSay(int sayi)
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

	Ogrenci RandomAtamalar(Ogrenci ogr)
	{
		ogr.setAd(AdSay(rand() % 4945));
		ogr.setSoyAd(SoyadSay(rand() % 278));
		ogr.setNumara(rand() % 100 + 100);
		return ogr;
	}

	string SoyadSay(int sayi)
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


	void Kayit(Ogrenci ogr)
	{
		ofstream yaz;
		yaz.open("kayıtlar.txt");
		if (yaz.is_open())
		{
			yaz << ogr.getAd() << ogr.getSoyAd() << ogr.getNumara() << endl;
		}
		yaz.close();

	}

};

class Sinif
{
	DosyaYonetim dosya;
public:
	string sinifIsmi;
	Ogrenci sinifMevcudu[10];
	int ogrenciSayisi;

	Sinif()
	{
		ogrenciSayisi = 0;
	}

	void OgrenciEkle()
	{
		sinifMevcudu[ogrenciSayisi] = dosya.RandomAtamalar(sinifMevcudu[ogrenciSayisi]);
		ogrenciSayisi++;
	}

	void OgrenciSil(Ogrenci ogr)
	{
		int silinecekIndis = 0;
		for (int i = 0; i < sizeof(sinifMevcudu); i++)
		{
			if (sinifMevcudu[i].getNumara() == ogr.getNumara())
			{
				silinecekIndis = i;
				break;
			}
		}

		for (int i = 0; i < sizeof(sinifMevcudu) - i; i++)
		{
			sinifMevcudu[silinecekIndis + i] = sinifMevcudu[silinecekIndis + i + 1];
		}
	}

	string OgrenciYazdir(int index)
	{
		string ogrenci = "";
		ogrenci += sinifMevcudu[index].getAd();
		ogrenci += " ";

		ogrenci += sinifMevcudu[index].getSoyAd();
		ogrenci += " ";

		if (sinifMevcudu[index].getNumara() > 0)
		{
			ogrenci += to_string(sinifMevcudu[index].getNumara());
			ogrenci += " ";
		}

		return ogrenci;
	}


};

class Okul
{
public:
	int enBuyukSinif;
	int sinifSayisi;
	Sinif siniflar[10];


	Okul()
	{
		enBuyukSinif = 0;
		sinifSayisi = 0;
		string sinifAdi;
		int ogrSayisi, numara;
		string ad, soyad;
		ifstream oku;
		oku.open("kayıtlar.txt");
		if (oku.is_open())
		{
			while (!oku.eof())
			{
				oku >> sinifAdi;
				siniflar[sinifSayisi].sinifIsmi = sinifAdi;
				oku >> ogrSayisi;
				siniflar[sinifSayisi].ogrenciSayisi = ogrSayisi;
				if (ogrSayisi > enBuyukSinif)
					enBuyukSinif = ogrSayisi;
				if (ogrSayisi > 0)
				{
					for (int i = 0; i < ogrSayisi; i++)
					{
						oku >> ad >> soyad >> numara;

						siniflar[sinifSayisi].sinifMevcudu[i].setAd(ad);
						siniflar[sinifSayisi].sinifMevcudu[i].setSoyAd(soyad);
						siniflar[sinifSayisi].sinifMevcudu[i].setNumara(numara);
					}
				}
				sinifSayisi++;
			}
		}

	}


	string SinifAdiOlustur(Sinif sinif)
	{
		char harf = rand() % 25 + 65;
		sinif.sinifIsmi += to_string(sinifSayisi + 1);
		sinif.sinifIsmi += harf;

		return sinif.sinifIsmi;
	}


	void Menu()
	{
		int secim = 0;
		while (secim != 6)
		{

			cout << "1-Ogrenci Ekle" << endl;
			cout << "2-Sinif Ekle" << endl;
			cout << "3-Ogrenci Degistir" << endl;
			cout << "4-Ogrenci Sil" << endl;
			cout << "5-Sinif Sil" << endl;
			cout << "6-Cikis" << endl;

			cin >> secim;

			string sinifAdi = "";
			switch (secim)
			{
			case 1:

				cout << "Sinif Adi : ";
				cin >> sinifAdi;

				for (int i = 0; i < sizeof(siniflar); i++)
				{
					if (siniflar[i].sinifIsmi == sinifAdi)
					{
						siniflar[i].OgrenciEkle();
						break;
					}
				}
				break;
			case 2:
				siniflar[sinifSayisi].sinifIsmi = SinifAdiOlustur(siniflar[sinifSayisi]);
				sinifSayisi++;



				break;
			case 3:

				cout << "Ogrenci Numarası : ";
				int no;
				cin >> no;

				for (int i = 0; i < sinifSayisi; i++)
				{
					for (int j = 0; j < siniflar[i].ogrenciSayisi; j++)
					{
						if (siniflar[i].sinifMevcudu[j].getNumara() == no)
						{
							DosyaYonetim dosya;
							siniflar[i].sinifMevcudu[j] = dosya.RandomAtamalar(siniflar[i].sinifMevcudu[j]);

							cout << endl;
							cout << siniflar[i].sinifMevcudu[j].getAd() << endl;
							cout << siniflar[i].sinifMevcudu[j].getSoyAd() << endl;
							cout << siniflar[i].sinifMevcudu[j].getNumara() << endl;

						}

					}

				}
				break;
			case 4:
				int numara;
				cout << "Ogrenci Numarasi : ";
				cin >> numara;

				for (int i = 0; i < sinifSayisi; i++)
				{
					for (int j = 0; i <siniflar[j].ogrenciSayisi; j++)
					{
						if (siniflar[i].sinifMevcudu[j].getNumara() == numara)
						{
							
							siniflar[i].sinifMevcudu[j].setAd("");
							siniflar[i].sinifMevcudu[j].setSoyAd("");
							siniflar[i].sinifMevcudu[j].setNumara(0);

							for (int k = j; k < siniflar[i].ogrenciSayisi; k++)
							{
								siniflar[i].sinifMevcudu[k] = siniflar[i].sinifMevcudu[k + 1];
							}
							siniflar[i].ogrenciSayisi--;
						}
					}
				}
				break;

			case 5:
				
				cout << "Sinif : ";
				cin >> sinifAdi;

				for (int i = 0; i < sinifSayisi; i++)
				{
					if (siniflar[i].sinifIsmi == sinifAdi)
					{
						siniflar[i].sinifIsmi = "";
						for (int j = i; j < sinifSayisi; j++)
						{
							siniflar[i] = siniflar[i + 1];
						}
						sinifSayisi--;
					}
				}
				break;
			case 6:
				dosyayaYaz();
				break;

			default:
				break;
			}
			system("cls");
			Yazdir();
		}


	}

	char solUstKose = 201;
	char duz = 205;
	char sagUstKose = 187;
	char solAltKose = 200;
	char sagAltKose = 188;
	char dikey = 186;

	void ustYazdir()
	{

		cout << solUstKose;
		for (int i = 0; i < 23; i++)
		{
			cout << duz;
		}
		cout << sagUstKose;
	}

	void altYazdir()
	{
		cout << solAltKose;
		for (int i = 0; i < 23; i++)
		{
			cout << duz;
		}
		cout << sagAltKose;
	}

	void Yazdir()
	{
		for (int i = 0; i < sinifSayisi; i++)
		{
			ustYazdir();
		}
		cout << endl;
		for (int i = 0; i < sinifSayisi; i++)
		{
			cout << "           " << siniflar[i].sinifIsmi << "            ";
		}
		cout << endl;
		for (int i = 0; i < sinifSayisi; i++)
		{
			altYazdir();
		}
		cout << endl;

		for (int i = 0; i < sinifSayisi; i++)
		{
			if (siniflar[i].ogrenciSayisi > enBuyukSinif)
				enBuyukSinif = siniflar[i].ogrenciSayisi;
		}

		for (int i = 0; i < enBuyukSinif; i++)
		{

			for (int j = 0; j < sinifSayisi; j++)
			{
				ustYazdir();
			}
			cout << endl;

			for (int j = 0; j < sinifSayisi; j++)
			{
				cout << " " << setw(25) << left << siniflar[j].OgrenciYazdir(i);
			}
			cout << endl;
			for (int j = 0; j < sinifSayisi; j++)
			{
				altYazdir();
			}
			cout << endl;

		}
	}

	void dosyayaYaz()
	{
		ofstream dosya;

		dosya.open("kayıtlar.txt");
		if (dosya.is_open())
		{
			for (int i = 0; i < sinifSayisi; i++)
			{
				dosya << siniflar[i].sinifIsmi << endl;
				dosya << siniflar[i].ogrenciSayisi << endl;
				

				for (int j = 0; j < siniflar[i].ogrenciSayisi; j++)
				{
					dosya << siniflar[i].sinifMevcudu[j].getAd() << " " << siniflar[i].sinifMevcudu[j].getSoyAd() << " " << siniflar[i].sinifMevcudu[j].getNumara() << endl;

				}
			}

		}
		dosya.close();

	}

};


class Program
{
	Okul okl;
public:
	void Calistir()
	{
		okl.Yazdir();
		okl.Menu();


	}
};

int main()
{
	Program prog;
	prog.Calistir();

	system("PAUSE");
	return 0;
}

