#include <iostream>
using namespace std;

class bidangDatar {
private:
    int x; //variabel untuk menyimpan input dari lingkaran maupun bujursangkar
public:
    bidangDatar() { //constructor
        x = 0;
    }
    
    virtual void input() {} // fungsi yang menerima input dan mengirim input melalui fungsi setX untuk disimpan di x
    
    virtual float Luas(int a) { return 0; } //fungsi untuk menghitung luas
    
    virtual float Keliling(int a) { return 0; } //fungsi untuk menghitung keliling
    
    void setX(int a) { //fungsi untuk memberi/mengirim nilai pada x
        this->x = a;
    }
    
    int getX() { //fungsi untuk membaca/mengambil nilai dalam x
        return x;
    }
};

class Lingkaran : public bidangDatar {
public:
    void input() {
        int r;
        cout << "Masukkan jari-jari lingkaran: ";
        cin >> r;
        setX(r);
    }
    
    float Luas(int r) {
        return 3.14 * r * r;
    }
    
    float Keliling(int r) {
        return 2 * 3.14 * r;
    }
};

class Bujursangkar : public bidangDatar {
public:
    void input() {
        int sisi;
        cout << "Masukkan panjang sisi bujursangkar: ";
        cin >> sisi;
        setX(sisi);
    }
    
    float Luas(int sisi) {
        return sisi * sisi;
    }
    
    float Keliling(int sisi) {
        return 4 * sisi;
    }
};

int main() {
    bidangDatar* bd; // pointer objek polymorphic
    
// Membuat objek Lingkaran
cout << "Lingkaran dibuat" << endl;

bd = new Lingkaran();

// Memanggil metode 'input()' dari objek 'bd'
bd->input();

// Mendapatkan nilai jari-jari lingkaran dan disimpan dalam variabel 'r'
int r = bd->getX();
cout << "Luas Lingkaran = " << bd->Luas(r) << endl;
cout << "Keliling Lingkaran = " << bd->Keliling(r) << endl;

delete bd;

    
    // Membuat objek Bujursangkar
cout << "Bujursangkar dibuat" << endl;

// objek baru dengan nama 'bd' instance kelas Bujursangkar
bd = new Bujursangkar();

// Memanggil metode 'input()'objek 'bd' untuk memasukkan nilai sisi bujursangkar
bd->input();

// Mendapatkan nilai sisi bujursangkar dan menyimpannya dalam variabel 'sisi'
int sisi = bd->getX();
cout << "Luas Bujursangkar = " << bd->Luas(sisi) << endl;
cout << "Keliling Bujursangkar = " << bd->Keliling(sisi) << endl;

delete bd;

return 0;

}
