#include "Sinif.h"


using namespace std;

Sinif::Sinif()
{
	sinifIsmi = SinifAdiOlustur();
	toplamSinifSayisi++;
}

void Sinif::OgrenciEkle(Ogrenci ogr)
{

	sinifMevcudu[ogrenciSayisi] = ogr;

}

void Sinif::OgrenciSil(Ogrenci ogr)
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

string Sinif::SinifAdiOlustur()
{
	char harf;
	harf = rand() % 25 + 65;
	string ad = to_string(++toplamSinifSayisi + harf);
	return ad;
}

