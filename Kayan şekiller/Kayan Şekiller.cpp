#include<iostream>
#include<Windows.h>
#include<time.h>

using namespace std;

struct Sahne //Sahne yapısı.
{
	int yukseklik;
	int genislik;
	char karakter;

}sahneNesnesi;


struct LSekli//L sekli yapısı.
{
	int x;
	int y;
	int boyut;
	char karakter;

}sekilNesnesi;

void koordinatAta(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


Sahne sahneOlustur(Sahne sahne)//Sahneyi oluşturan fonksiyon.
{
	int genislikDegerleri[] = { 30,40,50 };
	char karakterler[] = { '*','#','$','+','@' };

	sahneNesnesi.genislik = genislikDegerleri[rand() % 3]; //Genislik random değeri.
	sahneNesnesi.yukseklik = rand() % 11 + 10; //Yukseklik random degeri.
	sahneNesnesi.karakter = karakterler[rand() % 5]; //Rastgele karakter atar.

	return sahneNesnesi;
}

void sahneCiz(Sahne yapi) //Sahneyi çizecek olan fonksiyon.
{
	for (int i = 0; i < yapi.genislik; i++)
	{
		cout << yapi.karakter;

	}

	for (int i = 0; i < yapi.yukseklik; i++)
	{
		koordinatAta(yapi.genislik - 1, i);
		cout << yapi.karakter;

	}

	for (int i = 0; i < yapi.genislik; i++)
	{
		koordinatAta(yapi.genislik - i - 1, yapi.yukseklik - 1);
		cout << yapi.karakter;

	}
	for (int i = 0; i < yapi.yukseklik; i++)
	{
		koordinatAta(0, yapi.yukseklik - 1 - i);
		cout << yapi.karakter;

	}


}

LSekli lSekliOlustur(LSekli nesne, Sahne sahneNesne)//L seklini oluşturan olan fonksiyon.
{

	nesne.x = rand() % (sahneNesne.genislik - nesne.boyut - 5) + 5;
	nesne.y = 3;
	nesne.boyut = rand() % 5 + 4;
	char karakterler[] = { '*','#','$','+','@' };
	nesne.karakter = karakterler[rand() % 5];

	return nesne;
}

void lSekliCiz(LSekli sekil)//L seklini çizen fonksiyon.
{

	for (int i = 0; i < sekil.boyut / 2 - 1; i++)
	{
		koordinatAta(sekil.x + i, sekil.y);
		cout << sekil.karakter;

	}

	for (int i = 0; i < sekil.boyut / 2 + 1; i++)
	{
		koordinatAta(sekil.x + sekil.boyut / 2 - 1, sekil.y + i);
		cout << sekil.karakter;

	}
	for (int i = 0; i < sekil.boyut / 2; i++)
	{
		koordinatAta(sekil.x + sekil.boyut / 2 + i - 1, sekil.y + sekil.boyut / 2 + 1);
		cout << sekil.karakter;

	}


	for (int i = 0; i < sekil.boyut / 2; i++)
	{
		koordinatAta(sekil.x + sekil.boyut - 1, sekil.y + sekil.boyut / 2 + i + 1);
		cout << sekil.karakter;

	}


	for (int i = 0; i < sekil.boyut; i++)
	{
		koordinatAta(sekil.x + sekil.boyut - 1 - i, sekil.y + sekil.boyut);
		cout << sekil.karakter;

	}

	for (int i = 0; i < sekil.boyut; i++)
	{
		koordinatAta(sekil.x, sekil.y + sekil.boyut - i);
		cout << sekil.karakter;
	}

}

LSekli lSekliAsagiGotur(LSekli gotur)//L seklinin hareketini sağlıyor.
{
	gotur.y++;

	return gotur;

}


int main()
{

	srand(time(NULL)); //Random fonksiyonunun her calismasinda farkli deger uretmesi saglaniyor.

	sahneNesnesi = sahneOlustur(sahneNesnesi);

	sekilNesnesi = lSekliOlustur(sekilNesnesi, sahneNesnesi);

	while (true)//Çizimleri sürekli çalıştıracak olan döngü.
	{
		system("cls");//Ekranı temizler.

		sahneCiz(sahneNesnesi);

		lSekliCiz(sekilNesnesi);

		sekilNesnesi = lSekliAsagiGotur(sekilNesnesi);

		if (sahneNesnesi.yukseklik == sekilNesnesi.y + sekilNesnesi.boyut + 1)
		{
			sekilNesnesi = lSekliOlustur(sekilNesnesi, sahneNesnesi);

		}

		Sleep(100);
	}
	cin.get();
}
