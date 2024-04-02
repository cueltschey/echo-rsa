#include <stdio.h>
#include <encryption.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Testing RSA\n");
  char* test_text = "this is a testing message";
  int p, q;
  srand(time(NULL));
  p = generate_prime();
  q = generate_prime();
  int e, d, n;
  generate_keys(p, q, &e, &d, &n);
  printf("Key values: P = %d Q = %d e = %d d = %d N = %d", p, q, e, d, n);
  char* encrypted_text = malloc(strlen(test_text) + 1);
  encrypt(test_text, e, n, encrypted_text);
  printf("RSA encrypted: %s\n", encrypted_text);
  char* decrypted_text = malloc(strlen(test_text) + 1);
  decrypt(encrypted_text, d, n, decrypted_text);
  printf("RSA decrypted: %s\n", decrypted_text);
  return 0;
}
