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

int floorNegatif(int a, int b){
    float float_a = (float)a;
    float float_b = (float)b;
    float n = (float)((float_a+float_b)/2);
    if (n - (floor((a+b)/2)) <= -0.5)
    {
        return floor((a+b)/2)-1;
    }
    else
    {
        return floor((a+b)/2);
    }
    
}

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
                if ((temp_kanan+temp_kiri)/2 <= 0)
                {
                    weather[i] = floorNegatif(temp_kiri, temp_kanan);
                }
                else
                {
                    weather[i] = (int)floor((temp_kanan+temp_kiri)/2);
                }
                
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
        
    }
    int maxSum;
    int arraySum;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            maxSum = weather[i];
        }
        arraySum = weather[i];
        if (weather[i] > maxSum)
        {
            maxSum = weather[i];
        }
        for (int j = i+1; j < n; j++)
        {
            arraySum = arraySum + weather[j];
            if (arraySum >= maxSum)
            {
                maxSum = arraySum;
            }
        }
    }
    
    printf("MAX_SUM %d", maxSum);
    
}
