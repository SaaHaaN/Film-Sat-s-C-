/**
 * @file Şahan Aytekin Proje 3
 * @description Mağazadan bulunan film ve bu filmleri kiralayan ek olarak müşteri satici ile ilglili işlemler yapabilen program
 * @assignment 2. Proje Ödevi
 * @date 04.01.2023
 * @author Şahan Aytekin sahan.aytekin@stu.fsm.edu.tr
 */

#ifndef ZODEV_MAGAZA_H
#define ZODEV_MAGAZA_H

#include <iostream>
#include <string>

#include "Musteri.h"
#include "Satici.h"
#include "Film.h"

using namespace std;

class Magaza {
private:
    string magazaAdi;
    string magazaAdres;
    string magazaTelefon;

    Satici saticiListesi[10];
    int saticiSayisi = 0;

    Musteri musteriListesi[50];
    int musteriSayisi = 0;

    Film filmListesi[100];
    int filmSayisi = 0;

    int kiralananFilmSayisi = 0;

    Film kiralananFilmListesi[200];

public:
    Magaza() {}

    Magaza(string magazaAdi, string magazaAdres, string magazaTelefon) {
        this->magazaAdi = magazaAdi;
        this->magazaAdres = magazaAdres;
        this->magazaTelefon = magazaTelefon;
    }

//----------------------------------------------------------------------------------------------------------------------

    string getMagazaAdi() {
        return magazaAdi;
    }

    string getMagazaAdres() {
        return magazaAdres;
    }

    string getMagazaTelefon() {
        return magazaTelefon;
    }

    Musteri *getMusteriListesi() {
        return musteriListesi;
    }

    int getKiralananFilmSayisi() {
        return kiralananFilmSayisi;
    }

//----------------------------------------------------------------------------------------------------------------------

    void setMagazaAdi(string magazaAdi) {
        this->magazaAdi = magazaAdi;
    }

    void setMagazaAdres(string magazaAdres) {
        this->magazaAdres = magazaAdres;
    }

    void setMagazaTelefon(string magazaTelefon) {
        this->magazaTelefon = magazaTelefon;
    }

    void setKiralananFilmSayisi(int kiralananFilmSayisi) {
        this->kiralananFilmSayisi = kiralananFilmSayisi;
    }

    void magazaBilgileri() {
        cout << "Magaza Adi: " << magazaAdi << endl;
        cout << "Magaza Adres: " << magazaAdres << endl;
        cout << "Magaza Telefon: " << magazaTelefon << endl;
        cout << endl;
    }

//----------------------------------------------------------------------------------------------------------------------

    void saticiEkle(Satici satici) {
        for (int i = 0; i < 10; i++) {
            if (saticiListesi[i].getId() == satici.getId()) {
                cout << "Bu ID'ye sahip bir satici zaten var!" << endl;
                return;
            } else if (saticiSayisi == 10) {
                cout << "Satici listesi dolu!" << endl;
                return;
            } else if (saticiListesi[i].getId() == 0) {
                saticiListesi[i] = satici;
                saticiSayisi++;
                return;
            }
        }
    }

    void saticiSil(Satici satici) {
        bool b = false;
        for (int i = 0; i < 10; i++) {
            if (saticiSayisi == 0) {
                cout << "Musteri listesi bos!" << endl;
                break;
            } else {
                if (saticiListesi[i].getId() == satici.getId()) {
                    saticiListesi[i] = Satici();
                    saticiSayisi--;
                    cout << "Satici silindi!" << endl;
                    b = true;
                    break;
                }
            }
        }
        if (!b) {
            cout << "Boyle bir satici yok!" << endl;
        }
    }

    void saticiListele() {
        for (int i = 0; i < 10; i++) {
            if (saticiListesi[i].getId() != 0) {
                saticiListesi[i].saticiBilgileri();
            }
        }
    }

//----------------------------------------------------------------------------------------------------------------------

    void musteriEkle(Musteri musteri) {
        for (int i = 0; i < 50; i++) {
            if (musteriListesi[i].getId() == musteri.getId()) {
                cout << "Bu ID'ye sahip bir musteri zaten var!" << endl;
                return;
            } else if (musteriSayisi == 50) {
                cout << "Musteri listesi dolu!" << endl;
                return;
            } else if (musteriListesi[i].getId() == 0) {
                musteriListesi[i] = musteri;
                musteriSayisi++;
                return;
            }
        }
    }

    void musteriSil(Musteri musteri) {
        bool b = false;
        for (int i = 0; i < 50; i++) {
            if (musteriSayisi == 0) {
                cout << "Musteri listesi bos!" << endl;
                break;
            } else {
                if (musteriListesi[i].getId() == musteri.getId()) {

                    if (musteri.getSahipOlduguFilmAdeti() != 0) {
                        cout << "Bu musterinin kiraladigi film var! Once bu film iade edilmeli!" << endl;
                        return;
                    } else {
                        musteriListesi[i] = Musteri();
                        musteriSayisi--;
                        cout << musteri.getAd() << " adli musteri silindi!" << endl;
                        b = true;
                        break;
                    }
                }
            }
        }
        if (!b) {
            cout << "Boyle bir mustersi yok!" << endl;
        }
    }

    void musteriListele() {
        for (int i = 0; i < 50; i++) {
            if (musteriListesi[i].getId() != 0) {
                musteriListesi[i].musteriBilgileri();
            }
        }
    }

    void bakiyeSorgula(Musteri &musteri) {
        for (int i = 0; i < 50; i++) {
            if (musteriListesi[i].getId() == musteri.getId()) {
                cout << musteri.getAd() << " adli musterinin bakiyesi: " << musteriListesi[i].getBakiye() << " TL"
                     << endl;
                return;
            }
        }
    }

//----------------------------------------------------------------------------------------------------------------------

    void filmEkle(Film &film) {
        for (int i = 0; i < 100; i++) {
            if (filmListesi[i].getFilmID() == film.getFilmID()) {
                cout << "Bu ID'ye sahip bir film zaten var!" << endl;

                int secim;
                cout << "Film zaten mevcut stok arttirmak istermisin? (1 Evet / 2 Hayir) " << endl;
                cin >> secim;
                if (secim == 1) {
                    int stok;
                    cout << "Stok miktarini giriniz: " << endl;
                    cin >> stok;

                    filmStokGuncelle(film, stok);
                    filmAyarla(filmListesi[i]);
                    cout << "Film stogu arttirildi!" << endl;

                } else if (secim == 2) {
                    cout << "Film stogu arttirilamadi!" << endl;

                } else {
                    cout << "Bir hata olustu!" << endl;
                }
                return;

            } else if (filmSayisi == 100) {
                cout << "Film listesi dolu!" << endl;
                return;

            } else if (filmListesi[i].getFilmID() == 0) {
                filmListesi[i] = film;
                filmSayisi++;
                return;
            }
        }
    }

    void filmSil(Film film) {
        bool b = false;
        for (int i = 0; i < 100; i++) {
            if (filmSayisi == 0) {
                cout << "Film listesi bos!" << endl;
                break;
            } else {
                if (filmListesi[i].getFilmID() == film.getFilmID()) {
                    filmListesi[i] = Film();
                    filmSayisi--;
                    cout << "Film silindi!" << endl;
                    b = true;
                    break;
                }
            }
        }
        if (!b) {
            cout << "Boyle bir film yok!" << endl;
        }
    }

    void filmListele() {
        for (int i = 0; i < 100; i++) {
            if (filmListesi[i].getFilmAdi() != "") {
                filmListesi[i].filmBilgileri();
            }
        }
    }


    void filmStokGuncelle(Film &film, int stok) {
        for (int i = 0; i < 100; i++) {
            if (filmListesi[i].getFilmID() == film.getFilmID()) {
                film.setFilmStok(film.getFilmStok() + stok);
                filmAyarla(filmListesi[i]);
                return;
            }
        }
    }

    void filmKiralamaUcretiGuncelle(Film &film, double ucret) {
        for (int i = 0; i < 100; i++) {
            if (filmListesi[i].getFilmID() == film.getFilmID()) {
                film.setkiralamaUcreti(ucret);
                filmAyarla(filmListesi[i]);
                return;
            }
        }
    }

//----------------------------------------------------------------------------------------------------------------------

    void magazaDurumu() {
        cout << "Satici sayisi: " << saticiSayisi << endl;
        cout << "Musteri sayisi: " << musteriSayisi << endl;
        cout << "Film sayisi: " << filmSayisi << endl;
        cout << "Su ana kadar toplam kiralanan film adeti: " << kiralananFilmSayisi << endl;
    }

    void magazaFilmListesi() {
        cout << "Film listesi: " << endl;
        for (int i = 0; i < 100; i++) {
            if (filmListesi[i].getFilmID() != 0) {
                cout << "Film Adi: " << filmListesi[i].getFilmAdi() << endl;
            }
        }
        cout << endl;
    }

    void magazaMusteriListesi() {
        cout << "Musteri Listesi: " << endl;
        for (int i = 0; i < 50; i++) {
            if (musteriListesi[i].getId() != 0) {
                cout << "Musteri Adi " << musteriListesi[i].getAd() << endl;
            }
        }
        cout << endl;
    }

    void magazaSaticiListesi() {
        cout << "Satici Listesi: " << endl;
        for (int i = 0; i < 10; i++) {
            if (saticiListesi[i].getId() != 0) {
                cout << "Satici Adi " << saticiListesi[i].getAd() << endl;
            }
        }
        cout << endl;
    }

    void kiralananFilmler() {
        cout << "Kiralanan Film Listesi: " << endl;
        for (int i = 0; i < 100; i++) {
            if (kiralananFilmListesi[i].getFilmID() != 0) {
                cout << "Film Adi: " << kiralananFilmListesi[i].getFilmAdi() << endl;
            }
        }
        if (kiralananFilmSayisi == 0) {
            cout << "Kiralanan film yok!" << endl;
        }
        cout << endl;
    }
//----------------------------------------------------------------------------------------------------------------------

    void filmKirala(Film &film, Musteri &musteri) {
        if (musteri.getBakiye() < film.getkiralamaUcreti()) {
            cout << "Yetersiz bakiye" << endl;
        } else if (musteri.getSahipOlduguFilmAdeti() >= 3) {
            cout << "En fazla 3 film kiralanabilir" << endl;
        } else if (film.getFilmStok() == 0) {
            cout << "Film stokta bulunmamaktadir" << endl;
        } else if (film.getYasKisitlamasi() > musteri.getYas()) {
            cout << "Film izleme yas kisitlamasina uymuyorsunuz" << endl;
        } else {
            musteri.setBakiye(musteri.getBakiye() - film.getkiralamaUcreti());
            film.setFilmStok(film.getFilmStok() - 1);
            musteri.getEnvanter()[musteri.getSahipOlduguFilmAdeti()] = film;
            musteri.setSahipOlduguFilmAdeti(musteri.getSahipOlduguFilmAdeti() + 1);
            cout << musteri.getAd() << " adli musteri " << film.getFilmAdi() << " adli Film kiralandi" << endl;
            kiralananFilmSayisi++;

            musteriAyarlara(musteri);
            filmAyarla(film);

            kiralananFilmListesi[kiralananFilmSayisi] = film;

        }
    }


    void filmIadeEt(Film &film, Musteri &musteri) {
        for (int i = 0; i < musteri.getSahipOlduguFilmAdeti(); ++i) {
            if (musteri.getEnvanter()[i].getFilmID() == film.getFilmID()) {
                musteri.setBakiye(musteri.getBakiye() + film.getkiralamaUcreti());
                film.setFilmStok(film.getFilmStok() + 1);
                musteri.getEnvanter()[i] = Film();
                musteri.setSahipOlduguFilmAdeti(musteri.getSahipOlduguFilmAdeti() - 1);
                cout << musteri.getAd() << " adli musteri " << film.getFilmAdi() << " adli Film iade edildi" << endl;

                for (int i = 0; i < musteriSayisi; ++i) {
                    if (musteriListesi[i].getId() == musteri.getId()) {
                        musteriListesi[i] = musteri;
                    }
                }

                musteri.eskiFilmleriEkle(film);

                musteriAyarlara(musteri);
                filmAyarla(film);
                return;
            }
        }
        cout << "Bu filmi kiralamadiginiz icin iade edemezsiniz" << endl;
    }

    void filmGeriVer(Film &film, Musteri &musteri) {
        for (int i = 0; i < musteri.getSahipOlduguFilmAdeti(); ++i) {
            if (musteri.getEnvanter()[i].getFilmID() == film.getFilmID()) {
                musteri.setBakiye(musteri.getBakiye() + (film.getkiralamaUcreti() * 0.2));
                film.setFilmStok(film.getFilmStok() + 1);
                musteri.getEnvanter()[i] = Film();
                musteri.setSahipOlduguFilmAdeti(musteri.getSahipOlduguFilmAdeti() - 1);
                cout << musteri.getAd() << " adli musteri " << " adli Film iade edildi" << endl;

                for (int i = 0; i < musteriSayisi; ++i) {
                    if (musteriListesi[i].getId() == musteri.getId()) {
                        musteriListesi[i] = musteri;
                    }
                }

                musteri.eskiFilmleriEkle(film);

                musteriAyarlara(musteri);
                filmAyarla(film);
                return;
            }
        }
    }

//----------------------------------------------------------------------------------------------------------------------

    void musteriAra(string ad) {
        stringToAllLower(ad);
        for (int i = 0; i < musteriSayisi; ++i) {
            string str = musteriListesi[i].getAd();
            if (stringToAllLower(str) == ad) {
                cout << "ID'si " << musteriListesi[i].getId() << " olan " << musteriListesi[i].getAd()
                     << " adli musteri bulundu" << endl;
                return;
            }
        }
        cout << "Musteri bulunamadi" << endl;
    }

    void musteriAra(int id) {
        for (int i = 0; i < musteriSayisi; ++i) {
            if (musteriListesi[i].getId() == id) {
                cout << "ID'si " << musteriListesi[i].getId() << " olan " << musteriListesi[i].getAd()
                     << " adli musteri bulundu" << endl;
                return;
            }
        }
        cout << "Musteri bulunamadi" << endl;
    }

    void saticiAra(int id) {
        for (int i = 0; i < saticiSayisi; ++i) {
            if (saticiListesi[i].getId() == id) {
                cout << "ID'si " << saticiListesi[i].getId() << " olan " << saticiListesi[i].getAd()
                     << " adli satici bulundu" << endl;
                return;
            }
        }
        cout << "Satici bulunamadi" << endl;
    }

    void saticiAra(string ad) {
        stringToAllLower(ad);
        for (int i = 0; i < saticiSayisi; ++i) {
            string str = saticiListesi[i].getAd();
            if (stringToAllLower(str) == ad) {
                cout << "ID'si " << saticiListesi[i].getId() << " olan " << saticiListesi[i].getAd()
                     << " adli musteri bulundu" << endl;
                return;
            }
        }
        cout << "Satici bulunamadi" << endl;
    }

    void filmAra(int id) {
        for (int i = 0; i < filmSayisi; ++i) {
            if (filmListesi[i].getFilmID() == id) {
                cout << "ID'si " << filmListesi[i].getFilmID() << " olan " << filmListesi[i].getFilmAdi()
                     << " adli film bulundu" << endl;
                return;
            }
        }
        cout << "Film bulunamadi" << endl;
    }

//----------------------------------------------------------------------------------------------------------------------

//Arraydeki degerleri denkleştirmek için yazılan fonksiyon
    void musteriAyarlara(Musteri &musteri) {
        for (int i = 0; i < musteriSayisi; ++i) {
            if (musteriListesi[i].getId() == musteri.getId()) {
                musteriListesi[i] = musteri;
            }
        }
    }

//Arraydeki degerleri denkleştirmek için yazılan fonksiyon
    void filmAyarla(Film &film) {
        for (int i = 0; i < filmSayisi; ++i) {
            if (filmListesi[i].getFilmID() == film.getFilmID()) {
                filmListesi[i] = film;
            }
        }
    }

    static string stringToAllLower(string &str) {
        string s = str;
        for (int i = 0; i < str.length(); ++i) {
            str[i] = tolower(s[i]);
        }
        return str;
    }

};

#endif //ZODEV_MAGAZA_H