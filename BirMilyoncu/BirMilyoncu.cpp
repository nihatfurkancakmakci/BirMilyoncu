#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> // getche() fonksiyonu i�in
using namespace std;

struct Mal {
    string malAd;
    float malFiyat;
    int malStok;
};

const int MAX_MAL = 100; // Maksimum mal kapasitesi
const string dosyaAdi = "BirMilyoncu.txt"; // Verilerin kaydedilece�i dosya ad�

void malEkle(Mal stokListesi[], int& malSayisi);
void malSilme(Mal stokListesi[], int& malSayisi);
void malListele(Mal stokListesi[], int malSayisi);
void malGuncelle(Mal stokListesi[], int malSayisi);
void dosyadanOku(Mal stokListesi[], int& malSayisi);
void dosyayaYaz(Mal stokListesi[], int malSayisi);

int main() {
    Mal stokListesi[MAX_MAL];    // Maksimum 100 mal i�in yer ay�r�r
    int malSayisi = 0;           // Ba�lang��ta 0 mal var
    dosyadanOku(stokListesi, malSayisi); // Ba�lang��ta dosyadaki verileri oku
    char secim, anaMenuSecim;

    do {
        system("cls"); // Ekran� temizler
        cout << "|----------------------------------------------|" << endl;
        cout << "|------Bir Milyoncu Furkan'a Ho�geldiniz-------|" << endl;
        cout << "|----------Yapaca��n�z ��lemi Se�iniz----------|" << endl;
        cout << "|---------------- 1-) Mal Ekleme --------------|" << endl;
        cout << "|---------------- 2-) Mal Silme ---------------|" << endl;
        cout << "|---------------- 3-) Mal G�ncelleme ----------|" << endl;
        cout << "|---------------- 4-) Mal Listeleme -----------|" << endl;
        cout << "|----------------------------------------------|" << endl;
        cout << "|---------------Se�iminizi Giriniz ------------|" << endl;

        secim = getche(); // ��lem se�imi yap�l�r
        cout << endl;

        switch (secim) {
            case '1': {
                cout << "\nMal Ekleme ��lemi Se�ildi." << endl;
                malEkle(stokListesi, malSayisi);
                break;
            }
            case '2': {
                cout << "\nMal Silme ��lemi Se�ildi." << endl;
                malSilme(stokListesi, malSayisi);
                break;
            }
            case '3': {
                cout << "\nMal G�ncelleme ��lemi Se�ildi." << endl;
                malGuncelle(stokListesi, malSayisi);
                break;
            }
            case '4': {
                cout << "\nMal Listeleme ��lemi Se�ildi." << endl;
                malListele(stokListesi, malSayisi);
                break;
            }
            default: {
                cout << "\nGe�ersiz se�im yapt�n�z. L�tfen tekrar deneyin." << endl;
                break;
            }
        }

        cout << "\nAna Men�ye D�nmek �ster misiniz? (E,e / H,h): ";
        anaMenuSecim = getche(); // Ana men�ye d�nme se�imi
        cout << endl;

    } while (anaMenuSecim == 'E' || anaMenuSecim == 'e');

    dosyayaYaz(stokListesi, malSayisi); // Program sonland�r�ld���nda verileri dosyaya kaydeder
    return 0;
}

void malEkle(Mal stokListesi[], int& malSayisi) {
    if (malSayisi >= MAX_MAL) {
        cout << "Stok Kapasitesi Dolu. Mal Ekleyemezsiniz." << endl;
        system("pause");
        return;
    }

    cout << "\nMal Ad�: ";
    cin >> stokListesi[malSayisi].malAd;

    cout << "\nMal Fiyat�: ";
    cin >> stokListesi[malSayisi].malFiyat;

    cout << "\nStok Miktar�: ";
    cin >> stokListesi[malSayisi].malStok;

    malSayisi++;
    cout << "\n�r�n Ba�ar�yla Eklendi!\n";
    system("pause");

    dosyayaYaz(stokListesi, malSayisi); // Ekleme sonras�nda dosyay� g�nceller
}

void malSilme(Mal stokListesi[], int& malSayisi) {
    if (malSayisi == 0) {
        cout << "Silinecek Mal Yok. Stoklar Bo�!" << endl;
        system("pause");
        return;
    }

    cout << "Stokta Bulunan �r�nler:" << endl;
    for (int i = 0; i < malSayisi; i++) {
        cout << i + 1 << ". Mal: " << stokListesi[i].malAd << endl;
    }

    int sil;
    cout << "\nSilmek �stedi�iniz �r�n�n Numaras�n� Giriniz: ";
    cin >> sil;

    if (sil < 1 || sil > malSayisi) {
        cout << "Bu Numarada Bir �r�n Bulunmamaktad�r." << endl;
        system("pause");
        return;
    }

    for (int i = sil - 1; i < malSayisi - 1; i++) {
        stokListesi[i] = stokListesi[i + 1];
    }

    malSayisi--;
    cout << "�r�n�n�z Silindi." << endl;
    system("pause");

    dosyayaYaz(stokListesi, malSayisi); // Silme sonras�nda dosyay� g�nceller
}

void malGuncelle(Mal stokListesi[], int malSayisi) {
    if (malSayisi == 0) {
        cout << "G�ncellenecek Mal Yok. Stoklar Bo�!" << endl;
        system("pause");
        return;
    }

    cout << "Stokta Bulunan �r�nler:" << endl;
    for (int i = 0; i < malSayisi; i++) {
        cout << i + 1 << ". Mal: " << stokListesi[i].malAd << endl;
    }

    int guncelle;
    cout << "\nG�ncellemek �stedi�iniz �r�n�n Numaras�n� Giriniz (1-" << malSayisi << "): ";
    cin >> guncelle;

    if (guncelle < 1 || guncelle > malSayisi) {
        cout << "Bu Numarada Bir �r�n Bulunmamaktad�r." << endl;
        system("pause");
        return;
    }

    int malIndex = guncelle - 1;
    char secim;

    cout << "\nMal Ad�: " << stokListesi[malIndex].malAd << endl;
    cout << "Mal Fiyat�: " << stokListesi[malIndex].malFiyat << endl;
    cout << "Stok Miktar�: " << stokListesi[malIndex].malStok << endl;

    cout << "\nHangi Bilgiyi G�ncellemek �stersiniz?" << endl;
    cout << "1-) Mal Ad�" << endl;
    cout << "2-) Mal Fiyat�" << endl;
    cout << "3-) Stok Miktar�" << endl;
    cout << "Se�iminizi Giriniz: ";
    cin >> secim;

    switch (secim) {
        case '1': {
            cout << "Yeni Mal Ad�: ";
            cin >> stokListesi[malIndex].malAd;
            cout << "Mal Ad� Ba�ar�yla G�ncellendi!" << endl;
            break;
        }
        case '2': {
            cout << "Yeni Mal Fiyat�: ";
            cin >> stokListesi[malIndex].malFiyat;
            cout << "Mal Fiyat� Ba�ar�yla G�ncellendi!" << endl;
            break;
        }
        case '3': {
            cout << "Yeni Stok Miktar�: ";
            cin >> stokListesi[malIndex].malStok;
            cout << "Stok Miktar� Ba�ar�yla G�ncellendi!" << endl;
            break;
        }
        default: {
            cout << "Ge�ersiz Se�im Yapt�n�z!" << endl;
            break;
        }
    }

    dosyayaYaz(stokListesi, malSayisi); // G�ncelleme sonras�nda dosyay� g�nceller
    system("pause");
}

void malListele(Mal stokListesi[], int malSayisi) {
    if (malSayisi == 0) {
        cout << "Stokta �r�n Yok." << endl;
        system("pause");
        return;
    }

    for (int i = 0; i < malSayisi; i++) {
        cout << endl;
        cout << i + 1 << ". Mal" << endl;
        cout << "Ad: " << stokListesi[i].malAd << endl;
        cout << "Fiyat: " << stokListesi[i].malFiyat << endl;
        cout << "Stok: " << stokListesi[i].malStok << endl;
    }
    cout << endl;
}

void dosyadanOku(Mal stokListesi[], int& malSayisi) {
    ifstream dosya(dosyaAdi.c_str());
    if (!dosya) {
        cout << "Dosya a��l�rken bir hata olu�tu!" << endl;
        return;
    }

    while (dosya >> stokListesi[malSayisi].malAd >> stokListesi[malSayisi].malFiyat >> stokListesi[malSayisi].malStok) {
        malSayisi++;
        if (malSayisi >= MAX_MAL) break;
    }

    dosya.close();
}

void dosyayaYaz(Mal stokListesi[], int malSayisi) {
    ofstream dosya(dosyaAdi.c_str(), ios::trunc); // Dosyay� ba�tan yazmak i�in
    if (!dosya) {
        cout << "Dosya kaydedilemedi!" << endl;
        return;
    }

    for (int i = 0; i < malSayisi; i++) {
        dosya << stokListesi[i].malAd << " " 
              << stokListesi[i].malFiyat << " " 
              << stokListesi[i].malStok << endl;
    }

    dosya.close();
}

