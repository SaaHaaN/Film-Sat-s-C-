/**
 * @file Şahan Aytekin Proje 3
 * @description Mağazadan bulunan film ve bu filmleri kiralayan ek olarak müşteri satici ile ilglili işlemler yapabilen program
 * @assignment 2. Proje Ödevi
 * @date 04.01.2023
 * @author Şahan Aytekin sahan.aytekin@stu.fsm.edu.tr
 */
#include "Magaza.h"
#include "Musteri.h"
#include "Satici.h"
#include "Film.h"
#include "Tur.h"

using namespace std;

int main() {

    Magaza magaza("Sahan Film Kiralama", "Istanbul Bakirkoy", "0532 321 88 88");
    magaza.magazaBilgileri();

    //------------------------------------------------------------------------------------------------------------------

    Satici satici1(1, "Ali", "Yilmaz", 30, "0532 123 45 67");
    Satici satici2(2, "Halil", "Kaya", 30, "0532 543 52 24");

    // Mağazaya Satici Ekleme
    magaza.saticiEkle(satici1);
    magaza.saticiEkle(satici2);
//    magaza.saticiListele();

    //------------------------------------------------------------------------------------------------------------------

    // Mağazaya Müşteri Ekleme Müşteri Silme Kontrol
    Musteri Ahmet(10, "Ahmet", "Mutlu", 21, 1000);
    Musteri Ayse(11, "Ayse", "Yilmaz", 20, 2000);
    Musteri Emre(12, "Emre", "Balik", 21, 1000);
    Musteri Merve(13, "Merve", "Kaya", 13, 200);

    //Yaş kontrolü bakiye için
//    Musteri Mert(14, "Mert", "Kaya", 11, 150);

    //Magazaya Müşteri Ekleme
    magaza.musteriEkle(Ahmet);
    magaza.musteriEkle(Ayse);
    magaza.musteriEkle(Emre);
//    magaza.musteriListele();

    //------------------------------------------------------------------------------------------------------------------

    Film film1(41, "Star Wars 3: Sith'in Intikami", 2005, 2, 99, 18, Tur("BilimKurgu"));
    Film film2(42, "Star Wars 4: Yeni Bir Umut", 1974, 20, 59, 18, Tur("BilimKurgu"));
    Film film3(43, "Avatar", 2009, 5, 59, 18, Tur("BilimKurgu"));
    Film film4(44, "Titanic", 1997, 10, 49, 18, Tur("Romantik"));
    Film film5(45, "Marvel Avengers: Infinity War", 2018, 10, 79, 13, Tur("Aksiyon"));
    Film film6(46, "Marvel Avengers: Endgame", 2019, 10, 89, 13, Tur("Aksiyon"));
    Film film7(47, "Curella", 2021, 10, 59, 13, Tur("Komedi"));

    Film film8(48, "Kung Fu Panda", 2008, 10, 59, Tur("Komedi"));

    // Mağazaya Film Ekleme
    magaza.filmEkle(film1);
    magaza.filmEkle(film2);
    magaza.filmEkle(film3);
    magaza.filmEkle(film4);
    magaza.filmEkle(film5);
    magaza.filmEkle(film6);
    magaza.filmEkle(film7);

    magaza.filmEkle(film8); // Yaş sınırı olmayan film

    magaza.filmListele();

    //------------------------------------------------------------------------------------------------------------------

    //Film varken eklerse stok artar ve stok guncelleme
//    film1.filmBilgileri();
//    magaza.filmEkle(film1);
//    film1.filmBilgileri();

//    film3.filmBilgileri();
//    magaza.filmStokGuncelle(film3, 3);
//    film3.filmBilgileri();

    //Film silme ve yokken silersen hata verir
//    magaza.filmSil(film6);
//    magaza.filmSil(film6);
//    magaza.filmListele();

    //------------------------------------------------------------------------------------------------------------------

//    film5.filmBilgileri();
//    magaza.filmKiralamaUcretiGuncelle(film4, 75);

    //------------------------------------------------------------------------------------------------------------------
    //Film kiralayıp , iade etme ve değişen bakıyeyi kontrol etme
//    magaza.bakiyeSorgula(Ahmet); //ilk bakiye
//    film3.filmBilgileri(); // ilk film stok
//
//    magaza.filmKirala(film3, Ahmet);
//    magaza.bakiyeSorgula(Ahmet); //bakıye düşmesi kontrol
//    film3.filmBilgileri(); // stok düşmesi kontrol
//
//    magaza.filmIadeEt(film3, Ahmet);
//    film3.filmBilgileri(); //stok artması kontrol
//    magaza.bakiyeSorgula(Ahmet); //bakıye artması kontrol
//
//    magaza.filmKirala(film1, Emre);
//    film1.filmBilgileri();
//    magaza.bakiyeSorgula(Emre);

    //------------------------------------------------------------------------------------------------------------------

    //Sahip olmadığı filma iade edememe kontrol.. Tekil çalıştırma
//    magaza.filmIadeEt(film7, Emre);

    //------------------------------------------------------------------------------------------------------------------

    //Musteri Arama
//    magaza.musteriAra(10);
//    magaza.musteriAra("Ahmet");
    //Satici Arama
//    magaza.saticiAra(1);
//    magaza.saticiAra("ali");

    //Film Arama
//    magaza.filmAra(40);

    //------------------------------------------------------------------------------------------------------------------

    //Film Stok Güncelleme
//    film1.filmBilgileri();
//    magaza.filmStokGuncelle(film1, 10);
//    film1.filmBilgileri();

    //Film Kiralama Ücreti Güncelleme
//    film4.filmBilgileri();
//    magaza.filmKiralamaUcretiGuncelle(film4, 100);
//    film4.filmBilgileri();

    //------------------------------------------------------------------------------------------------------------------

    //Musteri Silme
//    magaza.filmKirala(film1, Ahmet);
//    magaza.musteriSil(Ahmet);
//    magaza.filmIadeEt(film1, Ahmet);
//    magaza.musteriSil(Ahmet);
//    magaza.musteriSil(Ahmet);

    //------------------------------------------------------------------------------------------------------------------

    //Film Silme
//    magaza.filmSil(film1);
//    magaza.filmSil(film1);

    //------------------------------------------------------------------------------------------------------------------

    //SaticiSilme
//    magaza.saticiSil(satici1);
//    magaza.saticiSil(satici1);

    //------------------------------------------------------------------------------------------------------------------

    //Magaza içi durumları listeleme
//    magaza.magazaDurumu();
//    magaza.magazaSaticiListesi();
//    magaza.magazaMusteriListesi();
//    magaza.magazaFilmListesi();

    //Tüm Kiralanan Filmler
//    magaza.filmKirala(film1, Ahmet);
//    magaza.filmKirala(film2, Ahmet);
//    magaza.filmKirala(film3, Ahmet);
//
//    magaza.filmKirala(film3, Ayse);
//    magaza.filmKirala(film4, Ayse);
//
//    magaza.filmKirala(film5, Emre);
//    magaza.kiralananFilmler();

    //------------------------------------------------------------------------------------------------------------------

    //Magazadaki kiralanmış filmeri listeleme
//    magaza.filmKirala(film1, Ahmet);
//    magaza.filmKirala(film2, Ahmet);
//    magaza.filmKirala(film3, Ahmet);
//    magaza.filmKirala(film4, Ahmet);




    //------------------------------------------------------------------------------------------------------------------
    return 0;
}