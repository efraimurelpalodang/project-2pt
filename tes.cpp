#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip> // Untuk std::setw

using namespace std;

//! INSTANSIASI STRUCT

// DATA KELAS
struct Kelas {
  string id,namaKelas,wali,tahunAjaran;
  int jumlahSiswa;
};
vector<Kelas> dataKelas; // Membuat vector dari data kelas

// DATA SISWA
struct Siswa {
  string nama,nis,jk,ttl,kelas;
};
vector<Siswa> dataSiswa; // Membuat vector dari data siswa


//! MEMBUAT FUNGSI UNTUK MEMBACA DATA DARI MASING-MASING STRUCT
void ambilDataKelas() {
    ifstream data("data/kelas.txt");  // Membuka file untuk dibaca
    if (!data.is_open()) { // Memastikan file berhasil dibuka
        cout << "File tidak ditemukan!" << endl;
        return;
    }
    
    string id, namaKelas, wali, tahunAjaran;
    int jumlahSiswa;

    // Membaca data dari file
    while (data >> id >> ws) {  // Membaca ID dan mengabaikan whitespace
        getline(data, namaKelas, '\t');  // Membaca nama kelas hingga tab
        data >> wali >> ws;  // Membaca wali kelas dan mengabaikan whitespace
        data >> jumlahSiswa >> ws; // Membaca jumlah siswa dan mengabaikan whitespace
        getline(data, tahunAjaran, '\t'); // Membaca tahun ajaran (sampai akhir baris)

        // Menambahkan data ke vector dataKelas
        dataKelas.push_back({id, namaKelas, wali, tahunAjaran, jumlahSiswa});
    }

    data.close();  // Menutup file setelah selesai
}

void ambilDataSiswa() {
    ifstream data("data/siswa.txt");  // Membuka file untuk dibaca
    if (!data.is_open()) { // Memastikan file berhasil dibuka
        cout << "File tidak ditemukan!" << endl;
        return;
    }

    string nama,nis,jk,ttl,kelas;

    // Membaca data dari file
    while (data >> nama >> ws) {  // Membaca ID dan mengabaikan whitespace
        getline(data, nis, '\t');  // Membaca nama kelas hingga tab
        data >> jk >> ws;  // Membaca wali kelas dan mengabaikan whitespace
        data >> ttl >> ws; // Membaca jumlah siswa dan mengabaikan whitespace
        getline(data, kelas, '\t'); // Membaca tahun ajaran (sampai akhir baris)

        // Menambahkan data ke vector dataKelas
        dataSiswa.push_back({nama,nis,jk,ttl,kelas});
    }

    data.close();  // Menutup file setelah selesai
}


//! FUNGSI UNTUK CETAK DATA KELAS

void cetakDataKelas(vector<Kelas>& data) {

  if (data.empty()) {
    cout << "\nDATA MASIH KOSONG, SILAHKAN MASUKKAN DATA DULU!!\n";
    return;
  }

  cout << "\nDATA KELAS YANG SUDAH DI TAMBAHKAN !!\n";
  cout << string(85, '-') << endl; // Garis pemisah
  cout << left << setw(15) << "ID Kelas"
          << setw(20) << "Nama Kelas"
          << setw(20) << "Wali Kelas"
          << setw(15) << "Jumlah Siswa"
          << setw(15) << "Tahun Ajaran" << endl;
  cout << string(85, '-') << endl; // Garis pemisah

  for (const auto& kelas : data) {
      cout << setw(15) << kelas.id
              << setw(20) << kelas.namaKelas
              << setw(20) << kelas.wali
              << setw(15) << kelas.jumlahSiswa
              << setw(15) << kelas.tahunAjaran << endl;
  }
  cout << string(85, '-') << endl; // Garis pemisah
}

void cetakDataSiswa(vector<Siswa>& data) {

    if (data.empty()) {
    cout << "\nDATA MASIH KOSONG, SILAHKAN MASUKKAN DATA DULU!!\n";
    return;
  }

  cout << "\nDATA SISWA YANG SUDAH DI TAMBAHKAN !!\n";
  cout << string(85, '-') << endl; // Garis pemisah
  cout << left << setw(15) << "ID Kelas"
          << setw(20) << "Nama Kelas"
          << setw(20) << "Wali Kelas"
          << setw(15) << "Jumlah Siswa"
          << setw(15) << "Tahun Ajaran" << endl;
  cout << string(85, '-') << endl; // Garis pemisah

  for (const auto& Siswa : data) {
      cout << setw(15) << Siswa.nama
              << setw(20) << Siswa.nis
              << setw(20) << Siswa.jk
              << setw(15) << Siswa.ttl
              << setw(15) << Siswa.kelas << endl;
  }
  cout << string(85, '-') << endl; // Garis pemisah
}

//! FUNGSI UNTUK NAMBAH DATA

void tambahDataKelas(vector<Kelas>& data) {
  Kelas d; // membuat variable dari referensi objek kelas
  cin.ignore(); // Mengabaikan newline yang tersisa di buffer
  cout << "Masukkan ID Kelas: "; getline(cin, d.id);
  cout << "Masukkan Nama Kelas: "; getline(cin, d.namaKelas);
  cout << "Masukkan Wali Kelas: "; getline(cin, d.wali);
  cout << "Masukkan Jumlah Siswa Kelas: "; cin >> d.jumlahSiswa;
  cin.ignore(); // Mengabaikan newline yang tersisa di buffer
  cout << "Masukkan Tahun Ajaran: "; getline(cin, d.tahunAjaran);
  data.push_back(d);
  cout << "\nData Berhasil Ditambahkan!" << endl;
}

void tambahDataSiswa(vector<Siswa>& data) {
  Siswa d; // membuat variable dari referensi objek kelas
  cin.ignore(); // Mengabaikan newline yang tersisa di buffer
  cout << "Masukkan Nama : "; getline(cin, d.nama);
  cout << "Masukkan NIS : "; getline(cin, d.nis);
  cout << "Masukkan Jenis Kelamin : "; getline(cin, d.jk);
  cout << "Masukkan TTL [tgl-bln-thn] : "; cin >> d.ttl;
  cin.ignore(); // Mengabaikan newline yang tersisa di buffer
  cout << "Masukkan Kelas Siswa : "; getline(cin, d.kelas);
  data.push_back(d);
  cout << "Data Berhasil Ditambahkan!" << endl;
}

//! FUNGSI UNTUK UBAH DATA

void ubahDataKelas(vector<Kelas>& data) {
  if (data.empty()) {
    cout << "\nTidak ada data yang tersedia untuk diubah." << endl;
    return;
  }
  cetakDataKelas(data);

  int index;
  cout << "Masukkan nomor data yang ingin diubah (mulai dari 1): ";
  cin >> index;

  if (index < 1 || index > data.size()) {
      cout << "Nomor tidak Valid!" << endl;
      return;
  }

  Kelas& d = data[index - 1];
  cin.ignore(); // Mengabaikan newline yang tersisa di buffer
  cout << "Masukkan ID Kelas: "; getline(cin, d.id);
  cout << "Masukkan Nama Kelas: "; getline(cin, d.namaKelas);
  cout << "Masukkan Wali Kelas: "; getline(cin, d.wali);
  cout << "Masukkan Jumlah Siswa: "; cin >> d.jumlahSiswa;
  cin.ignore(); // Mengabaikan newline yang tersisa di buffer
  cout << "Masukkan Tahun Ajaran: "; getline(cin, d.tahunAjaran);
  cout << "Data berhasil di Ubah!" << endl;
}

void ubahDataSiswa(vector<Siswa>& data) {
  if (data.empty()) {
    cout << "\nTidak ada data yang tersedia untuk diubah." << endl;
    return;
  }
  cetakDataSiswa(data);

  int index;
  cout << "Masukkan nomor data yang ingin diubah (mulai dari 1): ";
  cin >> index;

  if (index < 1 || index > data.size()) {
      cout << "Nomor tidak Valid!" << endl;
      return;
  }

  Siswa& d = data[index - 1];
  cin.ignore(); // Mengabaikan newline yang tersisa di buffer
  cout << "Masukkan ID Kelas: "; getline(cin, d.nama);
  cout << "Masukkan Nama Kelas: "; getline(cin, d.nis);
  cout << "Masukkan Wali Kelas: "; getline(cin, d.jk);
  cout << "Masukkan Wali Kelas: "; getline(cin, d.ttl);
  cout << "Masukkan Tahun Ajaran: "; getline(cin, d.kelas);
  cout << "Data berhasil di Ubah!" << endl;
}

// Fungsi untuk menghapus data
template <typename T>
void hapusData(vector<T>& data) {
    if (data.empty()) {
        cout << "Tidak ada data untuk dihapus!!" << endl;
        return;
    }
    // cetakDataKelas(data);
    int index;
    cout << "Masukkan data yang ingin dihapus (mulai dari 1): ";
    cin >> index;
    if (index < 1 || index > data.size()) {
        cout << "Nomor tidak valid" << endl;
        return;
    }

    data.erase(data.begin() + index - 1);
    cout << "\nData Berhasil Dihapus, jangan lupa simpan perubahan!!" << endl;
}

//! FUNGSI UNTUK MENYIMPAN DATA 
void simpanDataKelas(vector<Kelas>& data) {
  ofstream file("data/siswa.txt");

  for (const auto& item : data) {
    file << item.id << "\t"
          << item.namaKelas << "\t"
          << item.wali << "\t"
          << item.jumlahSiswa << "\t"
          << item.tahunAjaran << endl;
  }

  file.close();
  cout << "\nData Berhasil Disimpan kedalam file data/kelas.txt!!" << endl;
}

void simpanDataSiswa(vector<Siswa>& data) {
  ofstream file("data/siswa.txt");

  for (const auto& item : data) {
    file << item.nama << "\t"
          << item.nis << "\t"
          << item.jk << "\t"
          << item.ttl << "\t"
          << item.kelas << endl;
  }

  file.close();
  cout << "\nData Berhasil Disimpan kedalam file data/kelas.txt!!" << endl;
}


//! template form
void templateForm(int a, string b) {
  cout << string(a,'-') << endl;
  cout << "Menu Pengelolaan Data "<< b << endl;
  cout << string(a,'-') << endl;
  cout << "1. Tambah Data\n2. Ubah Data\n3. Hapus Data\n4. Tampilkan Data\n5. Simpan Perubahan Data\n6. Kembali\n";
}



//! program Utama

int main() {
    int pilih;
    bool kembaliKeMenuUtama = false;

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
              templateForm(28, "Kelas");
              int pilihKelas;
              cout << "Pilih menu: "; cin >> pilihKelas;
              switch (pilihKelas) {
                  case 1: tambahDataKelas(dataKelas); break;
                  case 2: ubahDataKelas(dataKelas); break;
                  case 3: hapusData(dataKelas); break;
                  case 4: cetakDataKelas(dataKelas); break;
                  case 5: simpanDataKelas(dataKelas); break;
                  case 6: kembaliKeMenuUtama = true; break; // Kembali ke menu utama
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
                  case 1: tambahDataSiswa(dataSiswa); break;
                  case 2: ubahDataSiswa(dataSiswa); break;
                  case 3: hapusData(dataSiswa); break;
                  case 4: cetakDataSiswa(dataSiswa); break;
                  case 5: simpanDataSiswa(dataSiswa); break;
                  case 6: kembaliKeMenuUtama = true; break; // Kembali ke menu utama
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

  } while (pilih != 3);  // Loop kembali ke menu utama sampai memilih "Keluar"

  return 0;
}