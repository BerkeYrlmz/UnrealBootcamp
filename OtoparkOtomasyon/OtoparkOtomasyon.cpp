#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>

using namespace std;

const string admin_username = "Admin";
const string admin_password = "Admin";
const int num_floors = 5;
const int num_parking_spots = 10;
string parking_matrix[num_floors][num_parking_spots];

void clearScreen() {
    system("cls");
}

void displayWelcomeScreen() {
    cout << "Hoş geldiniz!" << endl;
    string username, password;
    cout << "Kullanıcı Adı: ";
    cin >> username;
    cout << "Şifre: ";
    cin >> password;

    if (username != admin_username || password != admin_password) {
        cout << "Hatalı giriş. 3 defa hatalı giriş sonucu program kapanacaktır." << endl;
        for (int i = 0; i < 3; i++) {
            Sleep(1000);
            clearScreen();
            cout << "Hatalı giriş. " << 2 - i << " deneme hakkınız kaldı." << endl;
            cout << "Kullanıcı Adı: ";
            cin >> username;
            cout << "Şifre: ";
            cin >> password;

            if (username == admin_username && password == admin_password) {
                clearScreen();
                break;
            }
        }

        if (username != admin_username || password != admin_password) {
            cout << "Çok fazla yanlış giriş yaptınız. Program kapanıyor." << endl;
            Sleep(2000);
            return;
        }
    }

    clearScreen();
    cout << "Hoş geldiniz, " << username << "!" << endl;
}

void displayMenu() {
    cout << "1. Park Halinde ki Araclarin Listesi" << endl;
    cout << "2. Park Halinde ki Araci Cikisi" << endl;
    cout << "3. Yeni Arac Girisi" << endl;
    cout << "4. Cikis" << endl;
}

void listParkedCars() {
    for (int floor = 0; floor < num_floors; floor++) {
        for (int spot = 0; spot < num_parking_spots; spot++) {
            if (parking_matrix[floor][spot] != "") {
                cout << "Kat " << floor + 1 << ", Park Yeri " << spot + 1 << ": " << parking_matrix[floor][spot] << endl;
            }
        }
    }
}

void parkCar() {
    int floor, spot;
    cout << "Kat numarasını girin (1-" << num_floors << "): ";
    cin >> floor;

    if (floor < 1 || floor > num_floors) {
        cout << "Geçersiz kat numarası." << endl;
        return;
    }

    floor--;

    cout << "Park yeri numarasını girin (1-" << num_parking_spots << "): ";
    cin >> spot;

    if (spot < 1 || spot > num_parking_spots) {
        cout << "Geçersiz park yeri numarası." << endl;
        return;
    }

    spot--;

    if (parking_matrix[floor][spot] != "") {
        cout << "Bu park yeri dolu." << endl;
        return;
    }

    cout << "Aracın plakasını girin: ";
    string plate;
    cin >> plate;

    time_t now;
    time(&now);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &now);

    parking_matrix[floor][spot] = plate;
    cout << "Aracınız " << floor + 1 << ". Kat, " << spot + 1 << ". Park yerine park edildi. Giriş zamanı: " << buffer;
}

void exitParking() {
    int floor, spot;
    cout << "Kat numarasını girin (1-" << num_floors << "): ";
    cin >> floor;

    if (floor < 1 || floor > num_floors) {
        cout << "Geçersiz kat numarası." << endl;
        return;
    }

    floor--;

    cout << "Park yeri numarasını girin (1-" << num_parking_spots << "): ";
    cin >> spot;

    if (spot < 1 || spot > num_parking_spots) {
        cout << "Geçersiz park yeri numarası." << endl;
        return;
    }

    spot--;

    if (parking_matrix[floor][spot] == "") {
        cout << "Bu park yeri boş." << endl;
        return;
    }

    string plate = parking_matrix[floor][spot];
    parking_matrix[floor][spot] = "";

    time_t now;
    time(&now);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &now);

    cout << "Araç " << floor + 1 << ". Kat, " << spot + 1 << ". Park yerinden çıktı. Çıkış zamanı: " << buffer;
}

int main() {
    displayWelcomeScreen();
    while (true) {
        displayMenu();
        int choice;
        cout << "Seçiminizi girin (1-4): ";
        cin >> choice;

        switch (choice) {
        case 1:
            listParkedCars();
            break;
        case 2:
            exitParking();
            break;
        case 3:
            parkCar();
            break;
        case 4:
            return 0;
        default:
            cout << "Geçersiz seçenek. Lütfen 1-4 arasında bir seçenek girin." << endl;
            break;
        }
    }

    return 0;
}