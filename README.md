Berikut langkah-langkah untuk menjalankan kode program:
1. Menyusun Kode Program:
   Pertama, pastikan kode program tersebut telah disusun dengan benar dalam satu file.
2. Kompilasi Kode Program:
   Buka terminal atau command prompt, lalu navigasikan ke direktori di mana file kode program tersebut disimpan. Kemudian, gunakan perintah kompilasi C.
3. Menjalankan Program:
   Setelah berhasil dikompilasi, jalankan program tersebut dengan mengetikkan nama file eksekusi yang telah dihasilkan.
   Program akan mulai dieksekusi dan akan menampilkan tabel hasil pengujian kinerja algoritma pengurutan seperti yang ditampilkan dalam kode program.
4. Mengamati Output:
   Program akan menampilkan tabel yang berisi jenis algoritma, jumlah bilangan yang diurutkan, dan waktu eksekusi dalam milidetik. Selain itu, program juga akan menyimpan data bilangan yang belum diurutkan serta hasil pengurutan dari setiap algoritma ke dalam file `numbersRecord.txt`.

Dengan langkah-langkah di atas, kode dapat dijalankan dan diamati hasil dari program tersebut, yang mencakup kinerja dari tiga algoritma pengurutan yang diterapkan: Bubble Sort, Selection Sort, dan Insertion Sort.
Terdapat 5 fungsi dalam kode ini, yaitu:
1. `generateRandomNumbers(int n, int *arr)`:
   Fungsi ini digunakan untuk mengisi array `arr` dengan bilangan bulat acak sebanyak `n`.

2. `bubbleSort(int n, int *arr)`:
   Fungsi ini mengimplementasikan algoritma Bubble Sort untuk mengurutkan array `arr` yang berisi `n` elemen bilangan bulat.

3. `selectionSort(int n, int *arr)`:
   Fungsi ini mengimplementasikan algoritma Selection Sort untuk mengurutkan array `arr` yang berisi `n` elemen bilangan bulat.

4. `insertionSort(int n, int *arr)`:
   Fungsi ini mengimplementasikan algoritma Insertion Sort untuk mengurutkan array `arr` yang berisi `n` elemen bilangan bulat.

5. `saveArrayToFile(char *filename, int n, int *arr, char *algorithmType, int dataSize, int isUnsorted)`:
6. Fungsi ini digunakan untuk menyimpan array bilangan bulat ke dalam sebuah file teks. Parameter `filename` adalah nama file tujuan penyimpanan, `n` adalah jumlah elemen dalam array, `arr` adalah array yang akan disimpan, `algorithmType` adalah jenis algoritma pengurutan, `dataSize` adalah ukuran data yang disimpan (jumlah elemen dalam array), dan `isUnsorted` menandakan apakah data belum diurutkan (1) atau sudah diurutkan (0).
