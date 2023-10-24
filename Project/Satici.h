/**
 * @file Şahan Aytekin Proje 3
 * @description Mağazadan bulunan film ve bu filmleri kiralayan ek olarak müşteri satici ile ilglili işlemler yapabilen program
 * @assignment 2. Proje Ödevi
 * @date 04.01.2023
 * @author Şahan Aytekin sahan.aytekin@stu.fsm.edu.tr
 */

#ifndef ZODEV_SATICI_H
#define ZODEV_SATICI_H

#include <iostream>
#include <string>

#include "Insan.h"

using namespace std;

class Satici : public Insan {

private:
    string saticiTelefon;;

public:
    Satici() {}

    Satici(int id, string ad, string soyad, int yas, string saticiTelefon)
            : Insan(id, ad, soyad, yas) {
        this->saticiTelefon = saticiTelefon;
    }

//----------------------------------------------------------------------------------------------------------------------

    string getSaticiTelefon() {
        return saticiTelefon;
    }

//----------------------------------------------------------------------------------------------------------------------

    void setSaticiTelefon(string saticiTelefon) {
        this->saticiTelefon = saticiTelefon;
    }

//----------------------------------------------------------------------------------------------------------------------

    void saticiBilgileri() {
        cout << "Satici ID: " << this->getId() << endl;
        cout << "Satici Ad: " << this->getAd() << endl;
        cout << "Satici Soyad: " << this->getSoyad() << endl;
        cout << "Satici Telefon: " << saticiTelefon << endl;
        cout << endl;
    }

};

#endif //ZODEV_SATICI_H