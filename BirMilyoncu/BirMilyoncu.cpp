#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> // getche() fonksiyonu için
using namespace std;

struct Mal {
    string malAd;
    float malFiyat;
    int malStok;
};

const int MAX_MAL = 100; // Maksimum mal kapasitesi
const string dosyaAdi = "BirMilyoncu.txt"; // Verilerin kaydedileceði dosya adý

void malEkle(Mal stokListesi[], int& malSayisi);
void malSilme(Mal stokListesi[], int& malSayisi);
void malListele(Mal stokListesi[], int malSayisi);
void malGuncelle(Mal stokListesi[], int malSayisi);
void dosyadanOku(Mal stokListesi[], int& malSayisi);
void dosyayaYaz(Mal stokListesi[], int malSayisi);

int main() {
    Mal stokListesi[MAX_MAL];    // Maksimum 100 mal için yer ayýrýr
    int malSayisi = 0;           // Baþlangýçta 0 mal var
    dosyadanOku(stokListesi, malSayisi); // Baþlangýçta dosyadaki verileri oku
    char secim, anaMenuSecim;

    do {
        system("cls"); // Ekraný temizler
        cout << "|----------------------------------------------|" << endl;
        cout << "|------Bir Milyoncu Furkan'a Hoþgeldiniz-------|" << endl;
        cout << "|----------Yapacaðýnýz Ýþlemi Seçiniz----------|" << endl;
        cout << "|---------------- 1-) Mal Ekleme --------------|" << endl;
        cout << "|---------------- 2-) Mal Silme ---------------|" << endl;
        cout << "|---------------- 3-) Mal Güncelleme ----------|" << endl;
        cout << "|---------------- 4-) Mal Listeleme -----------|" << endl;
        cout << "|----------------------------------------------|" << endl;
        cout << "|---------------Seçiminizi Giriniz ------------|" << endl;

        secim = getche(); // Ýþlem seçimi yapýlýr
        cout << endl;

        switch (secim) {
            case '1': {
                cout << "\nMal Ekleme Ýþlemi Seçildi." << endl;
                malEkle(stokListesi, malSayisi);
                break;
            }
            case '2': {
                cout << "\nMal Silme Ýþlemi Seçildi." << endl;
                malSilme(stokListesi, malSayisi);
                break;
            }
            case '3': {
                cout << "\nMal Güncelleme Ýþlemi Seçildi." << endl;
                malGuncelle(stokListesi, malSayisi);
                break;
            }
            case '4': {
                cout << "\nMal Listeleme Ýþlemi Seçildi." << endl;
                malListele(stokListesi, malSayisi);
                break;
            }
            default: {
                cout << "\nGeçersiz seçim yaptýnýz. Lütfen tekrar deneyin." << endl;
                break;
            }
        }

        cout << "\nAna Menüye Dönmek Ýster misiniz? (E,e / H,h): ";
        anaMenuSecim = getche(); // Ana menüye dönme seçimi
        cout << endl;

    } while (anaMenuSecim == 'E' || anaMenuSecim == 'e');

    dosyayaYaz(stokListesi, malSayisi); // Program sonlandýrýldýðýnda verileri dosyaya kaydeder
    return 0;
}

void malEkle(Mal stokListesi[], int& malSayisi) {
    if (malSayisi >= MAX_MAL) {
        cout << "Stok Kapasitesi Dolu. Mal Ekleyemezsiniz." << endl;
        system("pause");
        return;
    }

    cout << "\nMal Adý: ";
    cin >> stokListesi[malSayisi].malAd;

    cout << "\nMal Fiyatý: ";
    cin >> stokListesi[malSayisi].malFiyat;

    cout << "\nStok Miktarý: ";
    cin >> stokListesi[malSayisi].malStok;

    malSayisi++;
    cout << "\nÜrün Baþarýyla Eklendi!\n";
    system("pause");

    dosyayaYaz(stokListesi, malSayisi); // Ekleme sonrasýnda dosyayý günceller
}

void malSilme(Mal stokListesi[], int& malSayisi) {
    if (malSayisi == 0) {
        cout << "Silinecek Mal Yok. Stoklar Boþ!" << endl;
        system("pause");
        return;
    }

    cout << "Stokta Bulunan Ürünler:" << endl;
    for (int i = 0; i < malSayisi; i++) {
        cout << i + 1 << ". Mal: " << stokListesi[i].malAd << endl;
    }

    int sil;
    cout << "\nSilmek Ýstediðiniz Ürünün Numarasýný Giriniz: ";
    cin >> sil;

    if (sil < 1 || sil > malSayisi) {
        cout << "Bu Numarada Bir Ürün Bulunmamaktadýr." << endl;
        system("pause");
        return;
    }

    for (int i = sil - 1; i < malSayisi - 1; i++) {
        stokListesi[i] = stokListesi[i + 1];
    }

    malSayisi--;
    cout << "Ürününüz Silindi." << endl;
    system("pause");

    dosyayaYaz(stokListesi, malSayisi); // Silme sonrasýnda dosyayý günceller
}

void malGuncelle(Mal stokListesi[], int malSayisi) {
    if (malSayisi == 0) {
        cout << "Güncellenecek Mal Yok. Stoklar Boþ!" << endl;
        system("pause");
        return;
    }

    cout << "Stokta Bulunan Ürünler:" << endl;
    for (int i = 0; i < malSayisi; i++) {
        cout << i + 1 << ". Mal: " << stokListesi[i].malAd << endl;
    }

    int guncelle;
    cout << "\nGüncellemek Ýstediðiniz Ürünün Numarasýný Giriniz (1-" << malSayisi << "): ";
    cin >> guncelle;

    if (guncelle < 1 || guncelle > malSayisi) {
        cout << "Bu Numarada Bir Ürün Bulunmamaktadýr." << endl;
        system("pause");
        return;
    }

    int malIndex = guncelle - 1;
    char secim;

    cout << "\nMal Adý: " << stokListesi[malIndex].malAd << endl;
    cout << "Mal Fiyatý: " << stokListesi[malIndex].malFiyat << endl;
    cout << "Stok Miktarý: " << stokListesi[malIndex].malStok << endl;

    cout << "\nHangi Bilgiyi Güncellemek Ýstersiniz?" << endl;
    cout << "1-) Mal Adý" << endl;
    cout << "2-) Mal Fiyatý" << endl;
    cout << "3-) Stok Miktarý" << endl;
    cout << "Seçiminizi Giriniz: ";
    cin >> secim;

    switch (secim) {
        case '1': {
            cout << "Yeni Mal Adý: ";
            cin >> stokListesi[malIndex].malAd;
            cout << "Mal Adý Baþarýyla Güncellendi!" << endl;
            break;
        }
        case '2': {
            cout << "Yeni Mal Fiyatý: ";
            cin >> stokListesi[malIndex].malFiyat;
            cout << "Mal Fiyatý Baþarýyla Güncellendi!" << endl;
            break;
        }
        case '3': {
            cout << "Yeni Stok Miktarý: ";
            cin >> stokListesi[malIndex].malStok;
            cout << "Stok Miktarý Baþarýyla Güncellendi!" << endl;
            break;
        }
        default: {
            cout << "Geçersiz Seçim Yaptýnýz!" << endl;
            break;
        }
    }

    dosyayaYaz(stokListesi, malSayisi); // Güncelleme sonrasýnda dosyayý günceller
    system("pause");
}

void malListele(Mal stokListesi[], int malSayisi) {
    if (malSayisi == 0) {
        cout << "Stokta Ürün Yok." << endl;
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
        cout << "Dosya açýlýrken bir hata oluþtu!" << endl;
        return;
    }

    while (dosya >> stokListesi[malSayisi].malAd >> stokListesi[malSayisi].malFiyat >> stokListesi[malSayisi].malStok) {
        malSayisi++;
        if (malSayisi >= MAX_MAL) break;
    }

    dosya.close();
}

void dosyayaYaz(Mal stokListesi[], int malSayisi) {
    ofstream dosya(dosyaAdi.c_str(), ios::trunc); // Dosyayý baþtan yazmak için
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

