#pragma once
#include<string>
#include<fstream>
#include <iostream>


using namespace std;


class Ogrenci
{
public:

	Ogrenci();

	string getAd();

	void setAd(string adi);

	string getSoyAd();

	void setSoyAd(string soyadi);

	string getNumara();

	void setNumara(string no);

private:
	string ad;
	string soyAd;
	string numara;
};



