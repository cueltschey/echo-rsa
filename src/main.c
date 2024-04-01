#include <stdio.h>
#include <encryption.h>

int main() {
  printf("Testing RSA\n");
  char* test_text = "this is a testing message";
  int p, q;
  p = generate_prime();
  q = generate_prime();
  int e, d, n;
  generate_keys(p, q, &e, &d, &n);
  encrypt(test_text, e, n);
  printf("RSA encrypted: %s\n", test_text);
  encrypt(test_text, d, n);
  printf("RSA decrypted: %s\n", test_text);
  return 0;
}
