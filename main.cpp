#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip> // Untuk std::setw

using namespace std;

//! INSTANSIASI STRUCT

// DATA KELAS
struct Kelas {
  string id, namaKelas, wali, jumlahSiswa, tahunAjaran;
};
vector<Kelas> dataKelas; // Membuat vector dari data kelas

// DATA SISWA
struct Siswa {
  string nama, nis, jk, ttl, kelas;
};
vector<Siswa> dataSiswa; // Membuat vector dari data siswa


//! FUNGSI UNTUK MEMBACA DATA DARI FILE
void ambilDataKelas() {
    ifstream data("data/kelas.txt");  // Membuka file untuk dibaca
    if (!data.is_open()) { // Memastikan file berhasil dibuka
        cout << "File tidak ditemukan!" << endl;
        return;
    }
    
    string id, namaKelas, wali, jumlahSiswa, tahunAjaran;

    // Membaca data dari file
    while (data >> id >> ws) {  // Membaca ID dan mengabaikan whitespace
        getline(data, namaKelas, '\t');  // Membaca nama kelas hingga tab
        getline(data, wali, '\t');  // Membaca wali hingga tab
        getline(data, jumlahSiswa, '\t');  // Membaca jumlah siswa hingga tab
        data >> tahunAjaran >> ws; // Membaca tahun ajaran dan mengabaikan whitespace

        // Menambahkan data ke vector dataKelas
        dataKelas.push_back({id, namaKelas, wali, jumlahSiswa, tahunAjaran});
    }

    data.close();  // Menutup file setelah selesai
}

void ambilDataSiswa() {
    ifstream data("data/siswa.txt");  // Membuka file untuk dibaca
    if (!data.is_open()) { // Memastikan file berhasil dibuka
        cout << "File tidak ditemukan!" << endl;
        return;
    }

    string nama, nis, jk, ttl, kelas;

    // Membaca data dari file
    while (getline(data, nama, '\t')) {  // Membaca ID dan mengabaikan whitespace
        getline(data, nis, '\t');  // Membaca nama kelas hingga tab
        data >> jk >> ws;  // Membaca wali kelas dan mengabaikan whitespace
        data >> ttl >> ws; // Membaca jumlah siswa dan mengabaikan whitespace
        getline(data, kelas); // Membaca tahun ajaran (sampai akhir baris)
        // Menambahkan data ke vector dataKelas
        dataSiswa.push_back({nama, nis, jk, ttl, kelas});
    }

    data.close();  // Menutup file setelah selesai
}

//! FUNGSI UNTUK CETAK DATA KELAS

void cetakDataKelas() {
    ifstream file("data/kelas.txt");

    if (!file.is_open()) {
        cout << "\nFILE data/kelas.txt TIDAK DITEMUKAN!!\n";
        return;
    }

    cout << "\nDATA KELAS YANG SUDAH DI TAMBAHKAN !!\n";
    cout << string(85, '-') << endl; // Garis pemisah
    cout << left << setw(5) << "No"
            << setw(7) << "ID"
            << setw(20) << "Nama Kelas"
            << setw(25) << "Wali Kelas"
            << setw(10) << "Siswa"
            << setw(10) << "Ajaran" << endl;
    cout << string(85, '-') << endl; // Garis pemisah

    string id, namaKelas, wali, jumlahSiswa, tahunAjaran;
    int nomor = 1;
    
    // Membaca dan mencetak data dari file
    while (file >> id >> ws) {
        getline(file, namaKelas, '\t');  // Membaca nama kelas hingga tab
        getline(file, wali, '\t');  // Membaca wali kelas hingga tab
        getline(file, jumlahSiswa, '\t');  // Membaca jumlah siswa hingga tab
        file >> tahunAjaran >> ws; // Membaca tahun ajaran

        // Mencetak data kelas yang dibaca dari file
        cout<< setw(5)  << nomor++
            << setw(7) << id
            << setw(20) << namaKelas
            << setw(25) << wali
            << setw(10) << jumlahSiswa
            << setw(10) << tahunAjaran << endl;
    }

    cout << string(85, '-') << endl; // Garis pemisah

    file.close(); // Menutup file setelah selesai membaca
}

void cetakDataSiswa(vector<Siswa>& data) {

    if (data.empty()) {
    cout << "\nDATA MASIH KOSONG, SILAHKAN MASUKKAN DATA DULU!!\n";
    return;
  }

  cout << "\nDATA SISWA YANG SUDAH DI TAMBAHKAN !!\n";
  cout << string(85, '-') << endl; // Garis pemisah
  cout << left << setw(25) << "Nama Siswa"
          << setw(12) << "NIS"
          << setw(15) << "Jenis Kelamin"
          << setw(15) << "ttl"
          << setw(15) << "Kelas" << endl;
  cout << string(85, '-') << endl; // Garis pemisah

  for (const auto& Siswa : data) {
      cout << setw(25) << Siswa.nama
              << setw(12) << Siswa.nis
              << setw(15) << Siswa.jk
              << setw(15) << Siswa.ttl
              << setw(15) << Siswa.kelas << endl;
  }
  cout << string(85, '-') << endl; // Garis pemisah
}

//! FUNGSI UNTUK MENYIMPAN DATA KE FILE
void simpanDataKelas() {
  ofstream file("data/kelas.txt");

  for (const auto& item : dataKelas) {
    file << item.id << "\t"
          << item.namaKelas << "\t"
          << item.wali << "\t"
          << item.jumlahSiswa << "\t"
          << item.tahunAjaran << endl;
  }

  file.close();
}

void simpanDataSiswa() {
  ofstream file("data/siswa.txt");

  for (const auto& item : dataSiswa) {
    file << item.nama << "\t"
          << item.nis << "\t"
          << item.jk << "\t"
          << item.ttl << "\t"
          << item.kelas << endl;
  }

  file.close();
}

//! FUNGSI UNTUK MENAMBAH DATA

void tambahDataKelas() {
  Kelas d; // membuat variable dari referensi objek kelas
  cin.ignore(); // Mengabaikan newline yang tersisa di buffer
  cout << "Masukkan ID Kelas: "; getline(cin, d.id);
  cout << "Masukkan Nama Kelas: "; getline(cin, d.namaKelas);
  cout << "Masukkan Wali Kelas: "; getline(cin, d.wali);
  cout << "Masukkan Jumlah Siswa Kelas: "; cin >> d.jumlahSiswa;
  cin.ignore(); // Mengabaikan newline yang tersisa di buffer
  cout << "Masukkan Tahun Ajaran: "; getline(cin, d.tahunAjaran);
  dataKelas.push_back(d);
  simpanDataKelas();  // Menyimpan data secara langsung
  cout << "\nData Kelas Berhasil Ditambahkan Dan Disimpan kedalam file data/kelas.txt !!" << endl;
}

void tambahDataSiswa() {
  Siswa d; // membuat variable dari referensi objek kelas
  cin.ignore(); // Mengabaikan newline yang tersisa di buffer
  cout << "Masukkan Nama : "; getline(cin, d.nama);
  cout << "Masukkan NIS : "; getline(cin, d.nis);
  cout << "Masukkan Jenis Kelamin : "; getline(cin, d.jk);
  cout << "Masukkan TTL [tgl-bln-thn] : "; cin >> d.ttl;
  cin.ignore(); // Mengabaikan newline yang tersisa di buffer
  cout << "Masukkan Kelas Siswa : "; getline(cin, d.kelas);
  dataSiswa.push_back(d);
  simpanDataSiswa();  // Menyimpan data secara langsung
  cout << "\nData Kelas Berhasil Ditambahkan Dan Disimpan kedalam file data/siswa.txt !!" << endl;
}

//! FUNGSI UNTUK MENGUBAH DATA

void ubahDataKelas() {
  if (dataKelas.empty()) {
    cout << "\nTidak ada data yang tersedia untuk diubah." << endl;
    return;
  }
  cetakDataKelas();

  int index;
  cout << "Masukkan nomor data yang ingin diubah (mulai dari 1): ";
  cin >> index;

  if (index < 1 || index > dataKelas.size()) {
      cout << "Nomor tidak Valid!" << endl;
      return;
  }

  Kelas& d = dataKelas[index - 1];
  cin.ignore(); // Mengabaikan newline yang tersisa di buffer
  cout << "Masukkan ID Kelas: "; getline(cin, d.id);
  cout << "Masukkan Nama Kelas: "; getline(cin, d.namaKelas);
  cout << "Masukkan Wali Kelas: "; getline(cin, d.wali);
  cout << "Masukkan Jumlah Siswa: "; cin >> d.jumlahSiswa;
  cin.ignore(); // Mengabaikan newline yang tersisa di buffer
  cout << "Masukkan Tahun Ajaran: "; getline(cin, d.tahunAjaran);
  simpanDataKelas();  // Menyimpan data secara langsung
  cout << "Data Kelas berhasil di Ubah!" << endl;
}

void ubahDataSiswa() {
  if (dataSiswa.empty()) {
    cout << "\nTidak ada data yang tersedia untuk diubah." << endl;
    return;
  }
  cetakDataSiswa(dataSiswa);

  int index;
  cout << "Masukkan nomor data yang ingin diubah (mulai dari 1): ";
  cin >> index;

  if (index < 1 || index > dataSiswa.size()) {
      cout << "Nomor tidak Valid!" << endl;
      return;
  }

  Siswa& d = dataSiswa[index - 1];
  cin.ignore(); // Mengabaikan newline yang tersisa di buffer
  cout << "Masukkan nama Siswa : "; getline(cin, d.nama);
  cout << "Masukkan NIS : "; getline(cin, d.nis);
  cout << "Masukkan Jenis Kelamin : "; getline(cin, d.jk);
  cout << "Masukkan ttl [tgl-bln-thn] : "; getline(cin, d.ttl);
  cout << "Masukkan Kelas: "; getline(cin, d.kelas);
  simpanDataSiswa();  // Menyimpan data secara langsung
  cout << "Data Siswa berhasil di Ubah!" << endl;
}

//! FUNGSI UNTUK MENGHAPUS DATA
void hapusDataKelas() {
    if (dataKelas.empty()) {
        cout << "Tidak ada data untuk dihapus!!" << endl;
        return;
    }
    cetakDataKelas();
    int index;
    cout << "Masukkan data yang ingin dihapus (mulai dari 1): ";
    cin >> index;
    if (index < 1 || index > dataKelas.size()) {
        cout << "Nomor tidak valid" << endl;
        return;
    }

    dataKelas.erase(dataKelas.begin() + index - 1);
    simpanDataKelas();  // Menyimpan data secara langsung
    cout << "\nData Berhasil Dihapus!!\n" << endl;
}

void hapusDataSiswa() {
    if (dataSiswa.empty()) {
        cout << "Tidak ada data untuk dihapus!!" << endl;
        return;
    }
    cetakDataSiswa(dataSiswa);
    int index;
    cout << "Masukkan data yang ingin dihapus (mulai dari 1): ";
    cin >> index;
    if (index < 1 || index > dataSiswa.size()) {
        cout << "Nomor tidak valid" << endl;
        return;
    }

    dataSiswa.erase(dataSiswa.begin() + index - 1);
    simpanDataSiswa();  // Menyimpan data secara langsung
    cout << "\nData Berhasil Dihapus!!\n" << endl;
}

void templateForm(int a, string b) {
  cout << string(a,'-') << endl;
  cout << "Menu Pengelolaan Data "<< b << endl;
  cout << string(a,'-') << endl;
  cout << "1. Tambah Data "<<b<<
        "\n2. Ubah Data " <<b<<
        "\n3. Hapus Data " <<b<<
        "\n4. Tampilkan Data "<<b<<
        "\n5. Kembali ke menu utama\n";
}

//! Program Utama

int main() {
  int pilih;
  bool kembaliKeMenuUtama = false;

  ambilDataKelas();  // Mengambil data dari file saat program dimulai
  ambilDataSiswa();  // Mengambil data dari file saat program dimulai

  do {
  // Menu utama
  cout << "===============================\n";
  cout << "PROJEK MANAJEMEN DATA SEKOLAH\n";
  cout << "===============================\n";
  cout << "1. Data Kelas\n";
  cout << "2. Data Siswa\n";
  cout << "3. Keluar\n";
  cout << "Pilih Menu [1-3]: "; 
  cin >> pilih;

  switch (pilih) {
    case 1:
        // Mengelola data Kelas
        do {
            // ambilDataKelas();
            templateForm(28, "Kelas");
            int pilihKelas;
            cout << "Pilih menu: "; cin >> pilihKelas;
            switch (pilihKelas) {
                case 1: tambahDataKelas(); break;
                case 2: ubahDataKelas(); break;
                case 3: hapusDataKelas(); break;
                case 4: cetakDataKelas(); break;
                case 5: kembaliKeMenuUtama = true; break; // Kembali ke menu utama
                default: cout << "Pilihan tidak valid!" << endl;
            }
        } while (!kembaliKeMenuUtama);  // Loop berlanjut hingga kembali ke menu utama
        break;

    case 2:
        // Mengelola data Siswa
        do {
            templateForm(28, "Siswa");
            int pilihSiswa;
            cout << "Pilih menu: "; cin >> pilihSiswa;
            switch (pilihSiswa) {
                case 1: tambahDataSiswa(); break;
                case 2: ubahDataSiswa(); break;
                case 3: hapusDataSiswa(); break;
                case 4: cetakDataSiswa(dataSiswa); break;
                case 5: kembaliKeMenuUtama = true; break; // Kembali ke menu utama
                default: cout << "Pilihan tidak valid!" << endl;
            }
        } while (!kembaliKeMenuUtama);  // Loop berlanjut hingga kembali ke menu utama
        break;

    case 3:
        cout << "Terima kasih! Program selesai.\n";
        break;

    default:
        cout << "Pilihan tidak valid!" << endl;
    }

    // Reset flag kembaliKeMenuUtama untuk loop berikutnya
    kembaliKeMenuUtama = false;

  } while (pilih != 3);  // Loop kembali ke menu utama hingga pilih 3 untuk keluar
  
  return 0;
}
