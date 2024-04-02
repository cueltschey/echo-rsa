#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

/*
 * Some useful info on RSA:
 * P and Q are prime numbers between 1000 and 1999
 * E and D are the public and private key respectively
 * Phi = (P - 1) * (Q - 1)
 * N = P * Q
 * E is an exponent so that GCD(E, Phi) == 0
 */


// check for a prime number
int is_prime(int pr){
    int i;
    int j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

// get a prime number randomly
int generate_prime(){
  int prime;
  do{
    prime = rand() % 1000 + 1000;
  } while(!is_prime(prime));
  return prime;
}


// calculate the greatest common denominator
int get_gcd(int a, int b){
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

// calculate (a^b % n)
int modular_exponent(int base, unsigned int exponent, int modulus){
  int result = 1;
  base = base % modulus;
  while(exponent > 0){
    if(exponent % 2 == 1){
      result = (result * base) % modulus;
    }
    exponent = exponent >> 1;
    base = (base * base) % modulus;
  }
  return result;
}

// function to generate public and private keys
void generate_keys(int p, int q, int* e, int* d, int* n){
  int phi = (p - 1) * (q - 1);
  *n = p * q;
  int k;
  k = 0;
  for (i = 2; i < t; i++)
  {
    if (t % i == 0)
        continue;
    flag = prime(i);
    if (flag == 1 && i != p && i != q)
    {
        e[k] = i;
        flag = cd(e[k]);
        if (flag > 0)
        {
            d[k] = flag;
            k++;
        }
        if (k == 99)
            break;
    }
  }
}

long int cd(long int x)
{
    long int k = 1;
    while (1)
    {
        k = k + t;
        if (k % x == 0)
            return (k / x);
    }
}

// note that this function encrypts using e as input and decrypts using d
void encrypt(char* msg, int e, int n, char* en) {
    int len = strlen(msg);
    for (int i = 0; i < len; i++) {
        int pt = msg[i];
        int ct = 1;
        for (int j = 0; j < e; j++) {
            ct = (ct * pt) % n;
        }
        en[i] = ct;
    }
    en[len] = -1;
}

// Decryption function
void decrypt(char* en, int d, int n, char* msg) {
    int i = 0;
    while (en[i] != -1) {
        int ct = en[i];
        int pt = 1;
        for (int j = 0; j < d; j++) {
            pt = (pt * ct) % n;
        }
        msg[i] = pt;
        i++;
    }
    msg[i] = -1;
}

