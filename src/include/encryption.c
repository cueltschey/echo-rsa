#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

/*
 * Some useful info on RSA:
 * P and Q are prime numbers between 1000 and 1999
 * E and D are the public and private key respectively
 * Phi = (P - 1) * (Q - 1)
 * N = P * Q
 * E is an exponent so that GCD(E, Phi) == 0*/


// check for a prime number
int is_prime(int n){
  if(n <= 1) return 0;
  if(n <= 3) return 1;
  if(n % 2 == 0 | n % 3 == 0) return 0;
  for(int i = 5; i * i <= n; i += 6){
    if(n % i == 0 || n % (i + 2) == 0) return 0;
  }
  return 1;
}

// get a prime number randomly
int generate_prime(){
  srand(time(NULL));
  int prime;
  do{
    prime = rand() % 1000 + 1000;
  } while(!is_prime(prime));
  return prime;
}


// calculate the greatest common denominator
int get_gcd(int x, int y){
  if(y == 0) {
    return x;
  }
  return get_gcd(y, x % y);
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
  *e = 2;
  while(get_gcd(*e, phi) != 1){
    (*e)++;
  }
  int k = 1;
  while(1){
    if((k * phi + 1) % *e == 0){
      *d = (k * phi + 1) / *e;
      break;
    }
    k++;
  }
}

// note that this function encrypts using e as input and decrypts using d
void encrypt(char* text, int e, int n){
  int length = strlen(text);
  for(int i = 0; i < length; ++i){
    text[i] = modular_exponent(text[i], e, n);
  }
}

