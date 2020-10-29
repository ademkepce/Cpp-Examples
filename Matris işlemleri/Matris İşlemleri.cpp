#include<iostream>
#include<iomanip>
#include<time.h>

using namespace std;

void Yazdir(int, int[][25]);

int main()
{
	srand(time(NULL));  //Random fonksiyonunun her calismasinda farkli deger uretmesi saglaniyor.
	int matris[25][25];  //Max boyutta matris olusturuluyor.
	int boyut = 0;
	cout << "Matris boyutu : ";
	cin >> boyut;
	while (boyut < 5 || boyut > 25)
	{
		cout << "Hatali deger girildi.Tekrar giriniz : " << endl << endl;
		cout << "Matris boyutu : ";
		cin >> boyut;
	}

	while (true)   //Program bittiginde menuye geri donecek olan dongu yapisi.
	{
		system("CLS");
		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)
			{
				matris[i][j] = rand() % 9 + 1;  //Matris elemanlarina random deger.
			}
		}

		Yazdir(boyut, matris);

		cout << "1-Sutun-Satir Degistir" << endl;
		cout << "2-Tekleri Basa Al(Satir)" << endl;
		cout << "3-Ters Cevir(Sutun)" << endl;
		cout << "4-Toplamlari Yazdir" << endl;

		int secim = 0;
		cin >> secim;

		switch (secim)
		{
		case 1:
			int satir, sutun;
			int temp, kose;

			cout << "Satir : "; cin >> satir;
			cout << "Sutun : "; cin >> sutun;
			if (satir > boyut || sutun > boyut)
			{
				cout << "Hatali giris yaptiniz !" << endl;
			}
			else
			{
				kose = 0;  //Degisen sutun ve satirin yeni yerlerinde kesisen degeri tutacak degisken.

				kose = matris[satir - 1][satir - 1] + matris[sutun - 1][sutun - 1]; //Kesisen degerler toplami.
				for (int i = 0; i < boyut; i++)   //Satir ve sutun elemanlarinin degismesi.
				{
					temp = matris[satir - 1][i];
					matris[satir - 1][i] = matris[i][sutun - 1];
					matris[i][sutun - 1] = temp;
				}
				matris[satir - 1][sutun - 1] = kose; //Kesisen degerin yerine yazilmasi.

				Yazdir(boyut, matris);

				break;
			}
		case 2:
			cout << "Satir : ";
			cin >> satir;
			if (satir > boyut || sutun > boyut)
			{
				cout << "Hatali giris yaptiniz !" << endl;
			}
			else
			{
				int index;
				index = 0;
				for (int j = 0; j < boyut; j++)
				{
					if (matris[satir - 1][j] % 2 == 1)  //Dizi elemanlarinin tek-cift kontrolu yapiliyor.
					{
						int temp = matris[satir - 1][index];     //Tek olan elemanlar dizi basina atiliyor.
						matris[satir - 1][index] = matris[satir - 1][j];
						matris[satir - 1][j] = temp;
						index++;
					}
				}
				Yazdir(boyut, matris);
			}
			break;
		case 3:

			sutun = 0;
			do
			{
				cout << "Sutun giriniz :";
				cin >> sutun;
				if (sutun > boyut)
				{
					cout << "Hatali giris.Tekrar giriniz !" << endl;
				}
			} while (sutun > boyut);

			int dizi[25];  // Istenen sutunu tutacak dizi.

			for (int i = 0; i < boyut; i++)
			{
				dizi[i] = matris[i][sutun - 1];  //Istenen sutunun diziye atilmasi.
			}
			for (int i = 0; i < boyut; i++)
			{
				matris[i][sutun - 1] = dizi[boyut - 1 - i]; // Dizideki sutunun matrise tersten yazilmasi.
			}
			Yazdir(boyut, matris);
			break;


		case 4:
			int toplam; //Toplam degeri tutacak degisken.
			toplam = 0;
			for (int i = 0; i < boyut; i++)
			{
				for (int j = 0; j < boyut; j++)
				{
					toplam += matris[i][j]; //Tum elemanlarin toplanmasi.
				}
			}
			cout << "Toplam : " << toplam << endl << endl;
			for (int i = 0; i < boyut; i++)
			{
				for (int j = 0; j < boyut; j++)
				{
					toplam -= matris[i][j]; //Her elemanin toplamdan cikarilmasi
					matris[i][j] = toplam;  //ve kalanin elemanin yerine atanmasi.
				}
			}

			Yazdir(boyut, matris);
			break;
		default:
			break;
		}

		system("PAUSE");
	}

	return 0;
}

void Yazdir(int boyut, int matris[][25])  //Yazdirma fonksiyonu.
{
	cout << "     ";
	for (int i = 0; i < boyut; i++)
	{
		cout << setw(4) << i + 1 << right;
	}
	cout << endl;
	cout << "     ";
	for (int i = 0; i < boyut; i++)
	{
		cout << "____";
	}
	cout << endl;

	for (int i = 0; i < boyut; i++)
	{
		cout << setw(3) << i + 1 << setw(2) << "|";
		for (int j = 0; j < boyut; j++)
		{
			cout << setw(4) << matris[i][j];
		}
		cout << endl << endl;
	}
}
