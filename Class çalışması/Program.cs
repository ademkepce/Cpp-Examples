using System;
using System.Collections.Generic;
using System.IO;

namespace B191210058
{
    class Program
    {
        static void Main(string[] args) 
        {
            double puan;
            

            List<string> isimler = new List<string>();
            List<string> soyIsimler = new List<string>();
            List<string> numara = new List<string>();
            List<int> odev1 = new List<int>();
            List<int> odev2 = new List<int>();
            List<int> vize = new List<int>();
            List<int> final = new List<int>();
            List<int> not_etki_yuzdesi = new List<int>();

            TextWriter dosyam = new StreamWriter(@"C:\Users\ademk\OneDrive\Masaüstü\yaz.txt");

            StreamReader okunan = new StreamReader(@"C:\Users\ademk\OneDrive\Masaüstü\ögrenciler.txt");
            


            string oku = null;
            string harf = null;
            do {

                oku = okunan.ReadLine();

                if (oku!=null)
                {
                    string[] dosya = oku.Split(" ");

                    isimler.Add(dosya[0]);
                    soyIsimler.Add(dosya[1]);
                    numara.Add(dosya[2].Trim());
                    odev1.Add(Convert.ToInt32(dosya[3].Trim()));
                    odev2.Add(Convert.ToInt32(dosya[4].Trim()));
                    vize.Add(Convert.ToInt32(dosya[5].Trim()));
                    final.Add(Convert.ToInt32(dosya[6].Trim()));
                    not_etki_yuzdesi.Add(Convert.ToInt32(dosya[7].Trim()));
                }

            } while (oku!=null);


            for (int i = 0; i < isimler.Count; i++)
            {
                
                puan = odev1[i] * 0.1 + odev2[i] * 0.1 + vize[i] * 0.3 + final[i] * 0.5;

                if (puan >= 90 && puan <= 100)
                {
                    harf = "AA";
                }
                else if (puan >= 85 && puan < 90)
                {
                    harf = "BA";
                }
                else if (puan >= 80 && puan < 85)
                {
                    harf = "BB";
                }
                else if (puan >= 75 && puan < 80)
                {
                    harf = "CB";
                }
                else if (puan >= 65 && puan < 75)
                {
                    harf = "CC";
                }
                else if (puan >= 58 && puan < 65)
                {
                    harf = "DC";
                }
                else if (puan >= 50 && puan < 58)
                {
                    harf = "DD";
                }
                else if (puan >= 40 && puan < 50)
                {

                    harf = "FD";

                }
                else if (puan >= 0 && puan < 40)
                {
                    harf = "FF";

                }

                dosyam.WriteLine("ogrenci adi :" + isimler[i] + " " + soyIsimler[i] + " notu: " + harf);
                Console.WriteLine("ogrenci adi :" + isimler[i] + " " + soyIsimler[i] + " notu: " + harf);
                
            }
            
            dosyam.Close();

        }
    }
}
