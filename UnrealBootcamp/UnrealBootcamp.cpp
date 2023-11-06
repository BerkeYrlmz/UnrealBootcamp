#include "UnrealBootcamp.h"

int main() {
    while (true) {
        int IslemNo;
        int Sayi1, Sayi2;
        int Sonuc = 0;

        system("CLS");
        cout << "1. Toplama Yap.." << endl;
        cout << "2. Cikarma Yap.." << endl;
        cout << "3. Carpma Yap.." << endl;
        cout << "4. Bolme Yap.." << endl;
        cout << "5. Cikis.." << endl;
        cout << "Islem No Giriniz: ";
        cin >> IslemNo;

        if (IslemNo == 5)
            break;

        switch (IslemNo) {
        case 1:
            cout << "1. Sayiyi giriniz: ";
            cin >> Sayi1;
            cout << "2. Sayiyi giriniz: ";
            cin >> Sayi2;
            Sonuc = Sayi1 + Sayi2;
            break;
        case 2:
            cout << "1. Sayiyi giriniz: ";
            cin >> Sayi1;
            cout << "2. Sayiyi giriniz: ";
            cin >> Sayi2;
            Sonuc = Sayi1 - Sayi2;
            break;
        case 3:
            cout << "1. Sayiyi giriniz: ";
            cin >> Sayi1;
            cout << "2. Sayiyi giriniz: ";
            cin >> Sayi2;
            Sonuc = Sayi1 * Sayi2;
            break;
        case 4:
            cout << "1. Sayiyi giriniz: ";
            cin >> Sayi1;
            cout << "2. Sayiyi giriniz: ";
            cin >> Sayi2;
            if (Sayi2 == 0) {
                cout << "Bolme islemi sifira bolunemez." << endl;
            }
            else {
                Sonuc = Sayi1 / Sayi2;
            }
            break;
        default:
            cout << "Gecerli bir islem no girilmedi." << endl;
            break;
        }

        if (IslemNo > 0 && IslemNo < 5) {
            cout << "Islemin Sonucu: " << Sonuc << endl;
            system("PAUSE");
        }
    }

    return 0;
}