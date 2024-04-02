
#ifndef ENCRYPTION_H
#define ENCRYPTION_H

int is_prime(int n);

int generate_prime();

int get_gcd(int x, int y);

int modular_exponent(int base, unsigned int exponent, int modulus);

void generate_keys(int p, int q, int* e, int* d, int* n);

void encrypt(char* text, int e, int n, char* encrypted_text);

#endif
