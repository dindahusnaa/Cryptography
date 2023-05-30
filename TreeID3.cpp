#include <iostream>
#include <string>

using namespace std;
int main (){
	int UN, Toefl, TPA;
	int j,k,l,a=1, b=2, c=3;

	cout<< "        	SPBM					 \n" << endl;
	cout<< " Seleksi Penerimaan Mahasiswa Baru  \n"<< endl;
	cout<< "------------------------- \n";
			
	cout << "Kategori Nilai UN: \n" ; 
	cout << "1. Tinggi \n" ;
	cout << "2. Sedang \n"; 
	cout << "3. Rendah \n"; 
	cout << "Jawaban Anda : "; 
	cin >> UN ;
	
	cout << "Kategori Toefl: \n" ; 
	cout << "1. Bagus \n" ;
	cout << "2. Cukup \n"; 
	cout << "3. Kurang \n"; 
	cout << "Jawaban Anda : "; 
	cin >> Toefl ;
	
	cout << "Kategori TPA: \n" ; 
	cout << "1. Baik \n" ;
	cout << "2. Buruk \n"; 
	cout << "Jawaban Anda : "; 
	cin >> TPA ;
		
	//if else untuk menghitung hasil
	if (UN=1,Toefl=1, TPA=1) //1 tinggi-bagus-baik
		{
		cout << "Selamat Anda Diterima dalam Seleksi Penerimaan Mahasiswa Baru" ;
		}
	else if (UN=1,Toefl=1, TPA=2)//2 tinggi-bagus-buruk
		{
	cout << "Mohon maaf anda belum diterima dalam Seleksi Penerimaan Mahasiswa Baru. Tetap Semangat" ;
	}
	else if (UN=1, Toefl=2, TPA=1)//3 tinggi-cukup-baik
		{
		cout << "Selamat Anda Diterima dalam Seleksi Penerimaan Mahasiswa Baru" ;
		} 
	else if (UN=1, Toefl=2, TPA=2)//4 tinggi-cukup-buruk
		{
		cout << "Selamat Anda Diterima dalam Seleksi Penerimaan Mahasiswa Baru" ;
		}
	else if (UN=1, Toefl=3, TPA=1)//5 tinggi-kurang-baik
		{
		cout << "Selamat Anda Diterima dalam Seleksi Penerimaan Mahasiswa Baru" ;
		}
	else if (UN=1, Toefl=3, TPA=2)//6 tinggi-kurang-buruk
		{
		cout << "Mohon maaf anda belum diterima dalam Seleksi Penerimaan Mahasiswa Baru. Tetap Semangat" ;
		}
	else if (UN=2, Toefl=1, TPA=1)//7 sedang-bagus-baik
		{
		cout << "Selamat Anda Diterima dalam Seleksi Penerimaan Mahasiswa Baru" ;
		}
	else if (UN=2, Toefl=1, TPA=2)//8 sedang-bagus-buruk
		{
	cout << "Mohon maaf anda belum diterima dalam Seleksi Penerimaan Mahasiswa Baru. Tetap Semangat" ;		
		}
	else if (UN=2, Toefl=2, TPA=1)//9 sedang-cukup-baik
		{
		cout << "Selamat Anda Diterima dalam Seleksi Penerimaan Mahasiswa Baru" ;
		}
	else if (UN=2, Toefl=2, TPA=2)//10 sedang-cukup-buruk
		{
		cout << "Mohon maaf anda belum diterima dalam Seleksi Penerimaan Mahasiswa Baru. Tetap Semangat" ;	
		}
	else if (UN=2, Toefl=3, TPA=1)//11 sedang-kurang-baik
		{
		cout << "Selamat Anda Diterima dalam Seleksi Penerimaan Mahasiswa Baru" ;
		}	
	else if (UN=2, Toefl=3, TPA=2)//12 sedang-kurang-buruk
		{
		cout << "Mohon maaf anda belum diterima dalam Seleksi Penerimaan Mahasiswa Baru. Tetap Semangat" ;
		}
	else if (UN=3, Toefl=1, TPA=1)//13 rendah-bagus-baik
		{
		cout << "Selamat Anda Diterima dalam Seleksi Penerimaan Mahasiswa Baru" ;
		}
	else if (UN=3, Toefl=1, TPA=2)//14 rendah-bagus-buruk
		{
	cout << "Mohon maaf anda belum diterima dalam Seleksi Penerimaan Mahasiswa Baru. Tetap Semangat" ;
	}
	else if (UN=3, Toefl=2, TPA=1)//15 rendah-cukup-baik
		{
		cout << "Selamat Anda Diterima dalam Seleksi Penerimaan Mahasiswa Baru" ;
		}	
	else if (UN=3, Toefl=2, TPA=2)//16 rendah-cukup-buruk
		{
	cout << "Mohon maaf anda belum diterima dalam Seleksi Penerimaan Mahasiswa Baru. Tetap Semangat" ;
		}
	else if (UN=3, Toefl=3, TPA=1)//17 rendah-kurang-baik
		{
		cout << "Selamat Anda Diterima dalam Seleksi Penerimaan Mahasiswa Baru" ;
		}
	else if (UN=3, Toefl=3, TPA=3)//18 rendah-kurang-buruk
		{
			cout << "Mohon maaf anda belum diterima dalam Seleksi Penerimaan Mahasiswa Baru. Tetap Semangat" ;
		}
	return 0;
}
