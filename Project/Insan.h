/**
 * @file Şahan Aytekin Proje 3
 * @description Mağazadan bulunan film ve bu filmleri kiralayan ek olarak müşteri satici ile ilglili işlemler yapabilen program
 * @assignment 2. Proje Ödevi
 * @date 04.01.2023
 * @author Şahan Aytekin sahan.aytekin@stu.fsm.edu.tr
 */

#ifndef ZODEV_INSAN_H
#define ZODEV_INSAN_H

#include <string>

using namespace std;

class Insan {

private:
    int id;
    string ad;
    string soyad;
    int yas;

public:
    Insan() {}

    Insan(int id, string ad, string soyad, int yas) {
        this->id = id;
        this->ad = ad;
        this->soyad = soyad;
        this->yas = yas;
    }

    int getId() {
        return id;
    }

    string getAd() const {
        return ad;
    }

    string getSoyad() {
        return soyad;
    }

    int getYas() const {
        return yas;
    }

//----------------------------------------------------------------------------------------------------------------------

    void setAd(string ad) {
        this->ad = ad;
    }

    void setSoyad(string soyad) {
        this->soyad = soyad;
    }

    void setYas(int yas) {
        this->yas = yas;
    }
};

#endif //ZODEV_INSAN_H