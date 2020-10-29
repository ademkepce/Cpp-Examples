#include<iostream>
#include<Windows.h>
#include<iomanip>

using namespace std;

int main()
{
	int satir, sutun;

	do
	{


		cout << "Satir icin bir deger giriniz...:";
		cin >> satir;

		while (satir > 15 || satir < 5)/*Satır değerinin 5 ve 15 arasında olup olmadığını kontrol ediyor.(5 ve 15 dahil) doğruysa devam ediyor
										 değilse hatalı olduğunu bildiriyor yeni bir değer girmemizi istiyor.*/

		{
			cout << "Satir degeri hatali tekrar giriniz...:";
			cin >> satir;
		}

		cout << "Sutun icin bir deger girniz...:";
		cin >> sutun;
		while (sutun > 40 || sutun < 5)/*Sütun değerinin 5 ve 40 arasında olup olmadığını kontrol ediyor.(5 ve 40 dahil) doğruysa devam ediyor
										 değilse hatalı olduğunu bildiriyor yeni bir değer girmemizi istiyor.*/
		{
			cout << "Sutun degeri hatali tekrar giriniz...:";

			cin >> sutun;
		}
		if (sutun != satir * 2)//Sütun değerinin satır değerinin 2 katı olup olmadığını kontrol ediyor.
		{
			cout << "Sutun sayisi satir sayisinin iki kati olmali!!!" << endl;
		}


	} while (sutun != satir * 2);//Sütun değeri satır değerinin 2 katı ise devam ediyor değilse döngü başa sarıyor.

	int boslukBir = sutun / 2 - 3;
	int boslukIki = 2;
	int boslukUc = sutun / 2 - 3;
	satir = satir - 2;


	for (int i = 0; i < sutun; i++)//Sütun değeri kadar yıldız basıyor.
	{
		cout << "*";
		Sleep(100);
	}
	cout << endl;

	for (int i = 0; i < satir; i++)//Satir değeri kadar yıldız basıyor.
	{
		cout << "*";

		for (int i = 0; i < boslukBir; i++)//İlk satırda boşluk koymuyor sonrasında 1. boşluk kısmı için boşluk sayısını birer azaltarak boşluk koyuyor.
		{
			cout << " ";

		}

		cout << "*";
		boslukBir--;
		Sleep(100);

		for (int i = 0; i < boslukIki; i++)//2. kısım için boşluk sayısı 2 artarak devam ediyor satır sayısından iki eksik olana kadar.
		{
			cout << " ";

		}

		cout << "*";
		boslukIki += 2;
		Sleep(100);


		for (int i = 0; i < boslukUc; i++)//İlk satırda boşluk koymuyor sonrasında 3. boşluk kısmı için boşluk sayısını birer azaltarak boşluk koyuyor.
		{
			cout << " ";
		}

		cout << "*";
		cout << endl;
		boslukUc--;

	}

	for (int i = 0; i < sutun; i++)//Girilen sütun değeri kadar yıldız basar.
	{
		cout << "*";
		Sleep(100);
	}
	cout << endl << endl;

	/***********************************************************************/
	boslukBir = 0;
	boslukUc = 0;
	boslukIki = sutun - 4;
	for (int i = 0; i < sutun; i++)//Girilen sütun değeri kadar yıldız basar.
	{
		cout << "*";
		Sleep(100);
	}
	cout << endl;

	for (int i = 0; i < satir; i++)//Satir değeri kadar yıldız basar.
	{
		cout << "*";

		for (int i = 0; i < boslukBir; i++)//1. boşluk kısmı için boşluk sayısı 8 boşluk olana kadar artar.
		{
			cout << " ";

		}

		cout << "*";
		boslukBir++;
		Sleep(100);

		for (int i = 0; i < boslukIki; i++)//2. kısım için boşluk sayısı 2 azalarak devam ediyor.
		{
			cout << " ";
		}

		cout << "*";
		boslukIki -= 2;
		Sleep(100);

		for (int i = 0; i < boslukUc; i++)//3. boşluk kısmı için boşluk sayısı 8 boşluk olana kadar artar.
		{
			cout << " ";
		}

		cout << "*";
		cout << endl;
		boslukUc++;


	}

	for (int i = 0; i < sutun; i++)//Sütun değeri kadar yıldız basar.
	{
		cout << "*";
		Sleep(100);
	}
	cout << endl;

}