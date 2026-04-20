/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 2
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama (NIM)          : Pascal Baihaqi Syarif (13224027)
 *   Nama File           : soal1.c
 *   Deskripsi           : Sistem pemulihan data yang hilang berdasarkan pembacaan nilai valid terdekat.
 *                          Output sistem berupa data yang telah di recover, dan juga max_sum data array
 * 
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
  
int main() {
    int n;
    scanf("%d", &n);
    int weather[n];
    int temp_weather[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weather[i]);
        temp_weather[i] = weather[i];

    }
    printf("RECOVERED ");
    for (int i = 0; i < n; i++)
    {
        if (weather[i] == -1)
        {
            int temp_kiri = -1;
            int temp_kanan = -1;
            for (int j = i; j < n; j++)
            {
                if (weather[j] != -1)
                {
                    temp_kanan = weather[j];
                    break;
                }
            }
            for (int j = i; j >= 0; j--)
            {
                if (weather[j] != -1)
                {
                    temp_kiri = weather[j];
                    break;
                }
            }
            if (temp_kanan!=-1 && temp_kiri!=-1)
            {
                weather[i] = (int)floor((temp_kanan+temp_kiri)/2);
            }
            else if (temp_kiri!=-1 && temp_kanan==-1)
            {
                weather[i] = temp_kiri;
            }
            else if (temp_kiri==-1 && temp_kanan != -1)
            {
                weather[i] = temp_kanan;
            }
            else
            {
                weather[i] = 0;
            }
        }
        if (i != n-1)
        {
            printf("%d ", weather[i]);
        }
        else
        {
            printf("%d\n", weather[i]);
        }
        
        sum = sum + weather[i];
    }
    printf("MAX_SUM %d", sum);
    
}
