/**
 * @file Şahan Aytekin Proje 3
 * @description Mağazadan bulunan film ve bu filmleri kiralayan ek olarak müşteri satici ile ilglili işlemler yapabilen program
 * @assignment 2. Proje Ödevi
 * @date 23.12.2022
 * @author Şahan Aytekin sahan.aytekin@stu.fsm.edu.tr
 */

#ifndef ZODEV_MUSTERI_H
#define ZODEV_MUSTERI_H

#include <string>

#include "Insan.h"
#include "Film.h"

using namespace std;

class Musteri : public Insan {

private:
    double bakiye;
    Film envanter[3];
    int sahipOlduguFilmAdeti = 0;

    Film oncekiKiraladigiFilmler[100];
    int eskiFilmSayisi = 0;


public:
    Musteri() {}

    Musteri(int id, string ad, string soyad, int yas, double bakiye)
            : Insan(id, ad, soyad, yas) {

        if (yas < 13) {
            if (bakiye > 100) {
                cout << "13 yas altinda olan musterilerin bakiyesi 100 TL'den fazla olamaz." << endl;
                this->bakiye = 100;
                cout << "Musteri bakiyesi 100 TL olarak ayarlandi." << endl;
                exit(1);
            }
        } else {
            this->bakiye = bakiye;
        }
    }

//----------------------------------------------------------------------------------------------------------------------

    double getBakiye() {
        return bakiye;
    }

    Film *getEnvanter() {
        return envanter;
    }

    Film getOncekiKiraladigiFilmler() {
        return oncekiKiraladigiFilmler[100];
    }

    int getSahipOlduguFilmAdeti() {
        return sahipOlduguFilmAdeti;
    }

//----------------------------------------------------------------------------------------------------------------------

    void setBakiye(double bakiye) {
        this->bakiye = bakiye;
    }

    void setEnvanter(Film envanter[]) {
        for (int i = 0; i < 3; i++) {
            this->envanter[i] = envanter[i];
        }
    }

    void setSahipOlduguFilmAdeti(int sahipOlduguFilmAdeti) {
        this->sahipOlduguFilmAdeti = sahipOlduguFilmAdeti;
    }


//----------------------------------------------------------------------------------------------------------------------

    void musteriBilgileri() {
        cout << "Musteri ID: " << this->getId() << endl;
        cout << "Musteri Ad: " << this->getAd() << endl;
        cout << "Musteri Soyad: " << this->getSoyad() << endl;
        cout << "Musteri Bakiye: " << bakiye << " TL" << endl;
        cout << "Musteri Envanter: " << endl;
        for (int i = 0; i < 3; i++) {
            if (sahipOlduguFilmAdeti == 0) {
                cout << "Envanter Bos" << endl;
                break;
            } else if (envanter[i].getFilmAdi() != "") {
                cout << "Film Adi: " << envanter[i].getFilmAdi() << endl;
            }
        }
        for (int i = 0; i < 100; i++) {
            if (eskiFilmSayisi == 0) {
                cout << "Daha once kiralanmis film yok." << endl;
                break;
            } else if (!oncekiKiraladigiFilmler[i].getFilmAdi().empty()) {
                cout << "Onceki Kiraladigi Filmler: " << oncekiKiraladigiFilmler[i].getFilmAdi() << endl;
            }
        }
        cout << endl;
    }

//----------------------------------------------------------------------------------------------------------------------

    void envanteriGoster() {
        cout << this->getAd() << " Kisisinin Envanterindeki filmler: " << endl;
        for (int i = 0; i < 3; i++) {
            if (sahipOlduguFilmAdeti == 0) {
                cout << "Envanter Bos" << endl;
                break;
            } else if (envanter[i].getFilmAdi() != "") {
                cout << "Film Adi: " << envanter[i].getFilmAdi() << endl;
                cout << "Ucreti : " << envanter[i].getkiralamaUcreti() << " TL" << endl;
            }
        }
    }

    void eskiFilmleriEkle(Film film) {
        oncekiKiraladigiFilmler[eskiFilmSayisi] = film;
        eskiFilmSayisi++;
    }

    void eskiFilmleriGoster() {
        for (int i = 0; i < eskiFilmSayisi; i++) {
            if (!oncekiKiraladigiFilmler[i].getFilmAdi().empty()) {
                cout << "Film Adi: " << oncekiKiraladigiFilmler[i].getFilmAdi() << endl;
            }
        }
    }

};

#endif //ZODEV_MUSTERI_H