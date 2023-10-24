/**
 * @file Şahan Aytekin Proje 3
 * @description Mağazadan bulunan film ve bu filmleri kiralayan ek olarak müşteri satici ile ilglili işlemler yapabilen program
 * @assignment 2. Proje Ödevi
 * @date 04.01.2023
 * @author Şahan Aytekin sahan.aytekin@stu.fsm.edu.tr
 */

#ifndef ZODEV_TUR_H
#define ZODEV_TUR_H

#include <string>


using namespace std;

class Tur {
private:
    string turAdi;

public:
    Tur() {}

    Tur(string turAdi) {
        this->turAdi = turAdi;
    }

    string getTurAdi() {
        return turAdi;
    }

    void setTurAdi(string turAdi) {
        this->turAdi = turAdi;
    }

};

#endif //ZODEV_TUR_H