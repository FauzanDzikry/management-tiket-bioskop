#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <iomanip>
#include <algorithm>
#include <windows.h>
#include <random>
#include <ctime>
#include <fstream>
#include <stack>

using namespace std;

string kursi[30];
string kodefilm;
int jmlhtiket;
int idorder = 1;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
stack<string> riwayatTiket;

struct Film
{
    string kodefilm;
    string judul;
    string genre;
    string jamtayang;
    string durasi;
    short theater;
    double harga;
};

// fungsi create film
void createFilm(list<Film> &film, const string &kodefilm, const string &judul, const string &genre, const string &jamtayang, const string &durasi, short theater, double harga)
{
    Film newFilm;
    newFilm.kodefilm = kodefilm;
    newFilm.judul = judul;
    newFilm.genre = genre;
    newFilm.jamtayang = jamtayang;
    newFilm.durasi = durasi;
    newFilm.theater = theater;
    newFilm.harga = harga;

    film.push_back(newFilm);
}

// tabel film
void readFilm(const list<Film> &film)
{
    cout << endl
         << endl;
    cout << "\t";
    SetConsoleTextAttribute(h, 14);
    cout << left << setw(12) << "Kode Film"
         << left << setw(30) << "Judul Film"
         << left << setw(12) << "Genre"
         << left << setw(16) << "Jam Tayang"
         << left << setw(16) << "Durasi(menit)"
         << left << setw(9) << "Theater"
         << left << setw(12) << "Harga Tiket"
         << endl;
    cout << "\t==========================================================================================================" << endl;
    for (const Film &f : film)
    {
        cout << "\t";
        SetConsoleTextAttribute(h, 7);
        cout << left << setw(12) << f.kodefilm
             << left << setw(30) << f.judul
             << left << setw(12) << f.genre
             << left << setw(16) << f.jamtayang
             << left << setw(16) << f.durasi
             << left << setw(9) << f.theater
             << left << setw(12) << f.harga
             << endl;
    }
    SetConsoleTextAttribute(h, 14);
    cout << "\t==========================================================================================================" << endl;
}

// fungsi menampilkan film untuk customer
void readFilmForCustomer(const list<Film> &film)
{
    cout << endl
         << endl;
    cout << "\t";
    SetConsoleTextAttribute(h, 14);
    cout << left << setw(12) << "Kode Film"
         << left << setw(30) << "Judul Film"
         << left << setw(10) << "Theater"
         << left << setw(16) << "Jam Tayang"
         << left << setw(12) << "Harga Tiket"
         << endl;
    cout << "\t================================================================================" << endl;
    for (const Film &f : film)
    {
        cout << "\t";
        SetConsoleTextAttribute(h, 7);
        cout << left << setw(12) << f.kodefilm
             << left << setw(30) << f.judul
             << left << setw(10) << f.theater
             << left << setw(16) << f.jamtayang
             << left << setw(12) << f.harga
             << endl;
    }
    SetConsoleTextAttribute(h, 14);
    cout << "\t================================================================================" << endl;
}

// edit film
void updateFilm(list<Film> &film)
{
    cout << "\n\n\tMasukkan Kode Film yang ingin diedit : ";
    cin >> kodefilm;
    cin.ignore();

    for (Film &f : film)
    {
        if (f.kodefilm == kodefilm)
        {
            SetConsoleTextAttribute(h, 11);
            cout << "\n\n\tMasukkan data baru untuk film dengan kode " << kodefilm << endl;
            SetConsoleTextAttribute(h, 7);

            cout << "\n\tMasukkan Judul Film    : ";
            getline(cin, f.judul);
            cout<<endl;

            cout << "\tMasukkan Genre         : ";
            getline(cin, f.genre);
            cout<<endl;

            cout << "\tMasukkan Jam Tayang    : ";
            getline(cin, f.jamtayang);
            cout<<endl;

            cout << "\tMasukkan Durasi(menit) : ";
            getline(cin, f.durasi);
            cout<<endl;

            cout << "\tMasukkan Theater       : ";
            cin >> f.theater;
            cout<<endl;

            cout << "\tMasukkan Harga Tiket   : ";
            cin >> f.harga;
            cout<<endl;

            SetConsoleTextAttribute(h, 10);
            cout << "\n\tFilm berhasil diperbarui!" << endl;
            SetConsoleTextAttribute(h, 7);
            getch();
            return;
        }
        else
        {
            SetConsoleTextAttribute(h, 12);
            cout << "\n\tFilm dengan Kode Film tersebut tidak ditemukan!" << endl;
            SetConsoleTextAttribute(h, 7);
            getch();
        }
    }
}

// fungsi hapus film
void deleteFilm(list<Film> &film, const string &kodefilm)
{
    auto it = film.begin();
    while (it != film.end())
    {
        if (it->kodefilm == kodefilm)
        {
            it = film.erase(it);
            SetConsoleTextAttribute(h, 12);
            cout << "\n\tFilm berhasil dihapus!" << endl;
            SetConsoleTextAttribute(h, 7);
            getch();
            return;
        }
        else
        {
            ++it;
        }
    }
    SetConsoleTextAttribute(h, 12);
    cout << "\n\tFilm dengan Kode Film tersebut tidak ditemukan." << endl;
    getch();
}

// fungsi memilih film berdasarkan kode film
void pilihFilmByKode(const list<Film> &film)
{
    char pilih;
    do
    {
        SetConsoleTextAttribute(h, 7);
        cout << "\n\n\tMasukkan Kode Film untuk memilih film : ";
        getline(cin, kodefilm);

        for (const Film &f : film)
        {
            if (f.kodefilm == kodefilm)
            {
                system("cls");
                SetConsoleTextAttribute(h, 14);
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t" << f.judul << endl;
                cout << "\t\t\t\t\t\t\t\t\t============================" << endl;
                cout << "\t\t\t\t\t\t\t\t\t Genre          : " << f.genre << endl;
                cout << "\t\t\t\t\t\t\t\t\t Durasi (menit) : " << f.durasi << endl;
                cout << "\t\t\t\t\t\t\t\t\t Jam Tayang     : " << f.jamtayang << endl;
                cout << "\t\t\t\t\t\t\t\t\t Theater        : " << f.theater << endl;
                cout << "\t\t\t\t\t\t\t\t\t Harga Tiket    : " << f.harga << endl;
                cout << "\t\t\t\t\t\t\t\t\t============================" << endl;
                SetConsoleTextAttribute(h, 7);
                return;
                break;
            }
        }
        SetConsoleTextAttribute(h, 12);
        cout << "\n\tFilm dengan Kode Film tersebut tidak ditemukan!" << endl;
    } while (true);
}

// fungsi memabandingkan jam tayang antar film
bool compareByJamTayang(const Film &film1, const Film &film2)
{
    return film1.jamtayang < film2.jamtayang;
}

// sorting film berdasarkan jam tayang
void sortFilmsByJamTayang(list<Film> &film)
{
    film.sort(compareByJamTayang);
}

// password
string getPassword()
{
    string inputpass;
    char chr;

    while ((chr = _getch()) != '\r')
    {
        if (chr == '\b')
        {
            if (!inputpass.empty())
            {
                inputpass.erase(inputpass.size() - 1);
                cout << "\b \b";
            }
        }
        else
        {
            inputpass.push_back(chr);
            cout << "*";
        }
    }

    cout << endl;
    return inputpass;
}

// denah duduk
void denahDuduk()
{
    SetConsoleTextAttribute(h, 14);
    cout << "\n\t\t\t\tDenah Kursi Theater\n\n";
    cout << "\tE  ||  ";
    for (int i = 0; i < 10; i++)
    {
        cout << "E" << i + 1 << "  |  ";
    }
    cout << endl
         << endl;
    cout << "\tD  ||  ";
    for (int i = 0; i < 10; i++)
    {
        cout << "D" << i + 1 << "  |  ";
    }
    cout << endl
         << endl;
    cout << "\tC  ||  ";
    for (int i = 0; i < 10; i++)
    {
        cout << "C" << i + 1 << "  |  ";
    }
    cout << endl
         << endl;
    cout << "\tB  ||  ";
    for (int i = 0; i < 10; i++)
    {
        cout << "B" << i + 1 << "  |  ";
    }
    cout << endl
         << endl;
    cout << "\tA  ||  ";
    for (int i = 0; i < 10; i++)
    {
        cout << "A" << i + 1 << "  |  ";
    }
    cout << endl
         << endl;
}

string tanggal()
{
    time_t now = time(nullptr);
    tm *localTime = localtime(&now);

    char date[80];
    strftime(date, sizeof(date), "%A, %d-%m", localTime);
    return date;
}

string dateTime()
{
    time_t now = time(nullptr);
    tm *localTime = localtime(&now);

    char datetime[80];
    strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", localTime);
    return datetime;
}

void cetakTiket(const list<Film> &film)
{
    SetConsoleTextAttribute(h, 10);
    cout << "\n\n\tTiket berhasil dicetak";
    SetConsoleTextAttribute(h, 7);
    cout << ",tiket dapat dilihat di ";
    SetConsoleTextAttribute(h, 14);
    cout << "\"ticket/ticket.txt\"" << endl;
    SetConsoleTextAttribute(h, 7);
    cout << "\t-------------------------------------------------------------" << endl;
    for (const Film &f : film)
    {
        if (f.kodefilm == kodefilm)
        {
            for (int i = 0; i < jmlhtiket; i++)
            {
                string txtiket = "ticket/ticket " + to_string(idorder) + ".txt";
                ofstream tkt(txtiket);

                tkt << "==================================" << endl;
                tkt << "\tJawir Cinema" << endl;
                tkt << "----------------------------------" << endl;
                if (idorder < 10)
                {
                    tkt << "Id order : 00" << idorder << endl;
                }
                else if (idorder < 100)
                {
                    tkt << "Id order : 0" << idorder << endl;
                }
                else
                {
                    tkt << "Id order : " << idorder << endl;
                }
                tkt << "Judul : " << f.judul << endl;
                tkt << "Tanggal : ";
                tkt << tanggal();
                tkt << endl;
                tkt << "Jam tayang : " << f.jamtayang << endl;
                tkt << "Kursi : " << kursi[i] << endl;
                tkt << "Studio : " << f.theater << endl;
                tkt << "Harga : " << f.harga << endl;
                tkt << "----------------------------------" << endl;
                tkt << dateTime();
                tkt << "\n==================================\n";
                tkt.close();
                idorder += 1;
                riwayatTiket.push(txtiket);
            }
            return;
        }
    }
}

void ticketHistory()
{
    stack<string> tempStack;
    SetConsoleTextAttribute(h, 14);
    cout << "\n\n\tRiwayat Tiket : \n";
    cout << "\t-------------------------\n";
    int count = 1;

    while (!riwayatTiket.empty())
    {
        cout << "\t" << count << ". " << riwayatTiket.top() << endl;
        tempStack.push(riwayatTiket.top());
        riwayatTiket.pop();
        count++;
    }

    while (!tempStack.empty())
    {
        riwayatTiket.push(tempStack.top());
        tempStack.pop();
    }
}

int main()
{
    list<Film> film;
    char pilih;
    string pass = "asdf", inputpass;
    long va;
    double total, bayar, kembalian;

    random_device rd;
    mt19937 rndm(rd());
    rndm.seed(static_cast<unsigned>(time(0)));

    cout << "\n";
    SetConsoleTextAttribute(h, 9);
    cout << "\t\t\t\t\t\t\t\t====================================" << endl;
    cout << "\t\t\t\t\t\t\t\t||";
    SetConsoleTextAttribute(h, 14);
    cout << " Selamat Datang di Jawir Cinema ";
    SetConsoleTextAttribute(h, 9);
    cout << "||" << endl;
    cout << "\t\t\t\t\t\t\t\t====================================" << endl;
    SetConsoleTextAttribute(h, 7);
    cout << endl;
    SetConsoleTextAttribute(h, 14);
    cout << "\t\t\t\t\t\t\t  Program ini dibuat untuk management film bioskop";
    SetConsoleTextAttribute(h, 9);
    getch();
    system("cls");

    // loading
    int bar1 = 177, bar2 = 219;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t";
    SetConsoleTextAttribute(h, 14);
    cout << "Please wait...";
    SetConsoleTextAttribute(h, 9);
    cout << "\n\n\t\t\t\t\t\t\t";
    for (int i = 0; i < 50; i++)
        cout << (char)bar1;
    cout << "\r";
    cout << "\t\t\t\t\t\t\t";

    for (int i = 0; i < 50; i++)
    {
        cout << (char)bar2;
        Sleep(100);=
    }
    system("cls");

    do
    {
    passwordsalah:
        SetConsoleTextAttribute(h, 7);
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Login sebagai :\n";
        cout << "\t\t\t\t\t\t\t\t       ===================================\n";
        SetConsoleTextAttribute(h, 10);
        cout << "\t\t\t\t\t\t\t\t\t  (1). Customer\n";
        SetConsoleTextAttribute(h, 14);
        cout << "\t\t\t\t\t\t\t\t\t  (2). Admin\n";
        SetConsoleTextAttribute(h, 12);
        cout << "\t\t\t\t\t\t\t\t\t  (3). Kembali\n";
        SetConsoleTextAttribute(h, 7);
        cout << "\t\t\t\t\t\t\t\t       ===================================\n";
        cout << "\n\t\t\t\t\t\t\t\t\t    Masukkan Pilihan Anda : ";
        cin >> pilih;
        cin.ignore();

        if (pilih == '1')
        {
        custmenu:
            system("cls");
            sortFilmsByJamTayang(film);
            readFilmForCustomer(film);
            Film f;
            if (!film.empty())
            {
            konfirmasi:
                SetConsoleTextAttribute(h, 14);
                cout << "\n\n\tIngin melanjutkan proses? (y/t) : ";
                cin >> pilih;
                if (pilih == 'y' || pilih == 'Y')
                {
                    pass;
                }
                else if (pilih == 't' || pilih == 'T')
                {
                    system("cls");
                    goto passwordsalah;
                }
                else
                {
                    SetConsoleTextAttribute(h, 12);
                    cout << "\n\tPilihan tidak tersedia!\n";
                    goto konfirmasi;
                }

                cin.ignore();
                pilihFilmByKode(film);
                do
                {
                    SetConsoleTextAttribute(h, 7);
                    cout << "\n\t\t\t\t\t\t\t\t\t  Beli tiket (y/t) : ";
                    cin >> pilih;
                    cout << endl;
                    if (pilih == 'y' || pilih == 'Y')
                    {
                        cout << "\t\t\t\t\t\t\t\t       Jumlah tiket yang dibeli : ";
                        cin >> jmlhtiket;
                        system("cls");
                        denahDuduk();
                        SetConsoleTextAttribute(h, 7);
                        for (int i = 0; i < jmlhtiket; i++)
                        {
                            cout << "\tKursi customer " << i + 1 << " : ";
                            cin >> kursi[i];
                            SetConsoleTextAttribute(h, 7);
                            cout << endl;
                        }
                    metodepemb:
                        system("cls");
                        SetConsoleTextAttribute(h, 14);
                        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t         Pembayaran" << endl;
                        cout << "\t\t\t\t\t\t\t\t\t==============================" << endl;
                        SetConsoleTextAttribute(h, 11);
                        cout << "\t\t\t\t\t\t\t\t\t  (1). Cash" << endl;
                        cout << "\t\t\t\t\t\t\t\t\t  (2). BCA Virtual Account" << endl;
                        SetConsoleTextAttribute(h, 14);
                        cout << "\t\t\t\t\t\t\t\t\t==============================" << endl;
                        do
                        {
                            SetConsoleTextAttribute(h, 7);
                            cout << "\t\t\t\t\t\t\t\t\t    Pilih pembayaran : ";
                            cin >> pilih;
                            if (pilih == '1')
                            {
                                system("cls");
                                // Cash
                                for (const Film &f : film)
                                {
                                    total = f.harga * jmlhtiket;
                                }
                                SetConsoleTextAttribute(h, 10);
                                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t         CASH" << endl
                                     << endl;
                                SetConsoleTextAttribute(h, 7);
                                cout << "\t\t\t\t\t\t\t\t\t  Total bayar : " << total << endl;
                                do
                                {
                                    cout << "\t\t\t\t\t\t\t\t\t  Bayar       : ";
                                    cin >> bayar;
                                    if (bayar >= total)
                                    {
                                        kembalian = bayar - total;
                                        SetConsoleTextAttribute(h, 14);
                                        cout << "\t\t\t\t\t\t\t\t\t  Kembalian   : " << kembalian << endl;
                                        SetConsoleTextAttribute(h, 7);
                                        break;
                                    }
                                    else
                                    {
                                        SetConsoleTextAttribute(h, 12);
                                        cout << "\n\t\t\t\t\t\t\t\t\t  Pembayaran tidak mencukupi!\n"
                                             << endl;
                                        SetConsoleTextAttribute(h, 12);
                                    }
                                } while (true);
                                break;
                            }
                            else if (pilih == '2')
                            {
                                // virtual account
                                system("cls");
                                uniform_int_distribution<long long> dist(1000000000000, 9999999999999);
                                long long va = dist(rndm);
                                SetConsoleTextAttribute(h, 14);
                                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t         BCA VIRTUAL ACCOUNT" << endl
                                     << endl;
                                SetConsoleTextAttribute(h, 7);
                                cout << "\t\t\t\t\t\t\t\t\tNomor Virtual Account : ";
                                SetConsoleTextAttribute(h, 3);
                                cout << va << endl;
                                do
                                {
                                    SetConsoleTextAttribute(h, 7);
                                    cout << "\n\t\t\t\t\t\t\t\t\tSudah bayar (y/t) : ";
                                    cin >> pilih;
                                    if (pilih == 'y' || pilih == 'Y')
                                    {
                                        SetConsoleTextAttribute(h, 10);
                                        cout << "\n\n\t\t\t\t\t\t\t\t\t         Pembayaran berhasil!\n";
                                        SetConsoleTextAttribute(h, 7);
                                        break;
                                    }
                                    else if (pilih == 't' || pilih == 'T')
                                    {
                                        cout << "\n\t\t\t\t\t\t\t\t\tIngin merubah metode pembayaran ? (y/t) : ";
                                        cin >> pilih;
                                        if (pilih == 'y' || pilih == 'Y')
                                        {
                                            goto metodepemb;
                                        }
                                        else if (pilih == 't' || pilih == 'T')
                                        {
                                            SetConsoleTextAttribute(h, 12);
                                            cout << "\n\t\t\t\t\t\t\t\t\tSegera lakukan pembayaran!" << endl;
                                            SetConsoleTextAttribute(h, 14);
                                        }
                                    }
                                    else
                                    {
                                        SetConsoleTextAttribute(h, 12);
                                        cout << "\n\t\t\t\t\t\t\t\t\tPilihan tidak tersedia!\n";
                                        SetConsoleTextAttribute(h, 12);
                                    }
                                } while (true);
                                break;
                            }
                            else
                            {
                                SetConsoleTextAttribute(h, 12);
                                cout << "\n\t\t\t\t\t\t\t\t\tMetode pembayaran tidak tersedia!\n"
                                     << endl;
                                SetConsoleTextAttribute(h, 14);
                            }
                        } while (true);
                        getch();
                        system("cls");
                        SetConsoleTextAttribute(h, 3);
                        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t     Tekan ENTER untuk mencetak tiket";
                        SetConsoleTextAttribute(h, 7);
                        getch();
                        system("cls");

                        // cetak tiket
                        cin.ignore();
                        cetakTiket(film);
                        getch();
                        system("cls");
                        goto passwordsalah;
                    }
                    else if (pilih == 't' || pilih == 'T')
                    {
                        cin.ignore();
                        goto custmenu;
                    }
                } while (true);
            }
            else
            {
                SetConsoleTextAttribute(h, 12);
                cout << "\n\tFilm belum atau tidak tersedia!, tekan ENTER untuk diarahkan kembali ke halaman awal.";
                SetConsoleTextAttribute(h, 12);
                getch();
                system("cls");
                goto passwordsalah;
            }
        }
        // ADMIN
        else if (pilih == '2')
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tMasukkan password : ";
            inputpass = getPassword();
            if (inputpass != pass)
            {
                SetConsoleTextAttribute(h, 12);
                cout << "\n\t\t\t\t\t\t\t\t\tUps! Password salah!" << endl;
                SetConsoleTextAttribute(h, 7);
                getch();
                system("cls");
                goto passwordsalah;
            }
            do
            {
            admin:
                system("cls");
                readFilm(film);

                cout << "\n\n";
                SetConsoleTextAttribute(h, 10);
                cout << "\t(1). Input Film\n";
                cout << "\t(2). Edit Film\n";
                SetConsoleTextAttribute(h, 12);
                cout << "\t(3). Hapus Film\n";
                SetConsoleTextAttribute(h, 10);
                cout << "\t(4). Riwayat Pembelian\n";
                SetConsoleTextAttribute(h, 12);
                cout << "\t(5). Kembali\n\n";
                SetConsoleTextAttribute(h, 7);
                cout << "\t Pilih aksi : ";
                cin >> pilih;
                cin.ignore();
                if (pilih == '1')
                {
                    system("cls");
                    Film f;
                    SetConsoleTextAttribute(h, 14);
                    cout << "\n  Masukkan Kode Film     : ";
                    SetConsoleTextAttribute(h, 7);
                    getline(cin, f.kodefilm);
                    cout << endl;

                    SetConsoleTextAttribute(h, 14);
                    cout << "  Masukkan Judul Film    : ";
                    SetConsoleTextAttribute(h, 7);
                    getline(cin, f.judul);
                    cout << endl;

                    SetConsoleTextAttribute(h, 14);
                    cout << "  Masukkan Genre         : ";
                    SetConsoleTextAttribute(h, 7);
                    getline(cin, f.genre);
                    cout << endl;

                    SetConsoleTextAttribute(h, 14);
                    cout << "  Masukkan Jam Tayang    : ";
                    SetConsoleTextAttribute(h, 7);
                    getline(cin, f.jamtayang);
                    cout << endl;

                    SetConsoleTextAttribute(h, 14);
                    cout << "  Masukkan Durasi(menit) : ";
                    SetConsoleTextAttribute(h, 7);
                    getline(cin, f.durasi);
                    cout << endl;

                    SetConsoleTextAttribute(h, 14);
                    cout << "  Masukkan Theater       : ";
                    SetConsoleTextAttribute(h, 7);
                    cin >> f.theater;
                    cout << endl;

                    SetConsoleTextAttribute(h, 14);
                    cout << "  Masukkan Harga Tiket   : ";
                    SetConsoleTextAttribute(h, 7);
                    cin >> f.harga;
                    cout << endl;

                    film.push_back(f);
                }
                else if (pilih == '2')
                {
                    if (!film.empty())
                    {
                        updateFilm(film);
                    }
                    else
                    {
                        SetConsoleTextAttribute(h, 12);
                        cout << "\n\tFilm belum tersedia, tekan ENTER untuk diarahkan kembali ke halaman admin";
                        SetConsoleTextAttribute(h, 12);
                        getch();
                        system("cls");
                        goto admin;
                    }
                }

                else if (pilih == '3')
                {
                    cout << "\n\n\tMasukkan Kode Film untuk menghapus Film : ";
                    getline(cin, kodefilm);
                    deleteFilm(film, kodefilm);
                }
                else if (pilih == '4')
                {
                    system("cls");
                    ticketHistory();
                    SetConsoleTextAttribute(h, 7);
                    cout << "\n\tApakah kamu ingin menghapus riwayat pembelian tiket? (y/t): ";
                    cin >> pilih;
                    if (pilih == 'y' || pilih == 'Y')
                    {
                        while (!riwayatTiket.empty())
                        {
                            riwayatTiket.pop();
                        }
                        SetConsoleTextAttribute(h, 10);
                        cout << "\n\tRiwayat tiket berhasil dihapus." << endl;
                        SetConsoleTextAttribute(h, 7);
                    }
                    else
                    {
                        SetConsoleTextAttribute(h, 11);
                        cout << "\n\tRiwayat tiket tidak jadi dihapus." << endl;
                        SetConsoleTextAttribute(h, 7);
                    }
                    getch();
                    system("cls");
                }

                else if (pilih == '5')
                {
                    system("cls");
                    goto passwordsalah;
                }
                else
                {
                    SetConsoleTextAttribute(h, 12);
                    cout << "\n\tPilihan tidak tersedia!";
                    SetConsoleTextAttribute(h, 7);
                    getch();
                }
            } while (true);
        }
        else if (pilih == '3')
        {
            break;
        }
        else
        {
            SetConsoleTextAttribute(h, 12);
            cout << "\n\t\t\t\t\t\t\t\t\t    Pilihan tidak tersedia!";
            SetConsoleTextAttribute(h, 7);
            getch();
            system("cls");
            goto passwordsalah;
        }
        break;
    } while (true);
    return 0;
}
