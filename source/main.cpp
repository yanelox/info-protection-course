#include "cast128.h"
#include <iostream>

int main() {
    cast128 alg;

    uint64_t key[2];
    key[0] = 0x0123456712345678;
    key[1] = 0x234567893456789A;

    uint64_t msg = 0x0123456789ABCDEF;

    uint64_t encoded_msg = alg.encrypt(msg, key);
    uint64_t decoded_msg = alg.decrypt(encoded_msg, key);

    std::cout << "------------Test 1--------------" << std::endl;
    std::cout << "Message: 0x" << std::hex << msg << std::endl;
    std::cout << "Encoded: 0x" << std::hex << encoded_msg << std::endl;
    std::cout << "Decoded: 0x" << std::hex << decoded_msg << std::endl;

    std::cout << "------------Test 2--------------" << std::endl;
    uint64_t a[2], b[2];
    a[0] = 0x0123456712345678;
    b[0] = 0x0123456712345678;
    a[1] = 0x234567893456789A;
    b[1] = 0x234567893456789A;

    for (int i = 0; i < 1000000; ++i) {
        a[0] = alg.encrypt(a[0], b);
        a[1] = alg.encrypt(a[1], b);

        b[0] = alg.encrypt(b[0], a);
        b[1] = alg.encrypt(b[1], a);
    }

    std::cout << "a: " << std::hex << a[0] << " " << a[1] << std::endl;
    std::cout << "a: " << std::hex << b[0] << " " << b[1] << std::endl;
}
