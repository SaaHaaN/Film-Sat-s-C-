/**
 * @file Şahan Aytekin Proje 3
 * @description Mağazadan bulunan film ve bu filmleri kiralayan ek olarak müşteri satici ile ilglili işlemler yapabilen program
 * @assignment 2. Proje Ödevi
 * @date 04.01.2023
 * @author Şahan Aytekin sahan.aytekin@stu.fsm.edu.tr
 */

#ifndef ZODEV_FILM_H
#define ZODEV_FILM_H

#include <iostream>
#include <string>

#include "Tur.h"

using namespace std;

class Film : public Tur {
private:
    int filmID;
    string filmAdi;
    int yapimYili;
    int filmStok;
    double kiralamaUcreti;
    int yasKisitlamasi;

public:
    Film() {}

    Film(int filmID, string filmAdi, int yapimYili, int filmStok, double kiralamaUcreti, Tur filmTur)
            : Tur(filmTur) {
        this->filmID = filmID;
        this->filmAdi = filmAdi;
        this->yapimYili = yapimYili;
        this->filmStok = filmStok;
        this->kiralamaUcreti = kiralamaUcreti;
    }

    Film(int filmID, string filmAdi, int yapimYili, int filmStok, double kiralamaUcreti, int yasKisitlamasi,
         Tur filmTur)
            : Tur(filmTur) {
        this->filmID = filmID;
        this->filmAdi = filmAdi;
        this->yapimYili = yapimYili;
        this->filmStok = filmStok;
        this->kiralamaUcreti = kiralamaUcreti;
        this->yasKisitlamasi = yasKisitlamasi;
    }

//----------------------------------------------------------------------------------------------------------------------

    int getFilmID() {
        return filmID;
    }

    string getFilmAdi() {
        return filmAdi;
    }

    int getYapimYili() {
        return yapimYili;
    }

    int getFilmStok() {
        return filmStok;
    }

    double getkiralamaUcreti() {
        return kiralamaUcreti;
    }


    int getYasKisitlamasi() {
        return yasKisitlamasi;
    }

//----------------------------------------------------------------------------------------------------------------------

    void setFilmID(int filmID) {
        this->filmID = filmID;
    }

    void setFilmAdi(string filmAdi) {
        this->filmAdi = filmAdi;
    }

    void setYapimYili(int yapimYili) {
        this->yapimYili = yapimYili;
    }

    void setFilmStok(int filmStok) {
        this->filmStok = filmStok;
    }

    void setkiralamaUcreti(double kiralamaUcreti) {
        this->kiralamaUcreti = kiralamaUcreti;
    }


    void setYasKisitlamasi(int yasKisitlamasi) {
        this->yasKisitlamasi = yasKisitlamasi;
    }

//----------------------------------------------------------------------------------------------------------------------

    void filmBilgileri() {
        cout << "Film ID: " << getFilmID() << endl;
        cout << "Film Adi: " << getFilmAdi() << endl;
        cout << "Film Yapim Yili: " << getYapimYili() << endl;
        cout << "Film Stok: " << filmStok << endl;
        cout << "Film Kiralama Ucreti: " << getkiralamaUcreti() << " TL" << endl;
        if (yasKisitlamasi != 0) {
            cout << "Film Yas Kisitlamasi: " << getYasKisitlamasi() << endl;
        }
        cout << "Film Tur: " << this->getTurAdi() << endl;
        cout << endl;
    }

};

#endif //ZODEV_FILM_H