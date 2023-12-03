#ifndef CAST128
#define CAST128

#include <cstdint>
#include <bitset>

struct cast128 {
    typedef uint32_t sBlock[256];

    uint64_t encrypt(uint64_t msg, uint64_t key[2]);
    uint64_t decrypt(uint64_t msg, uint64_t key[2]);

    private:
    uint64_t process(uint64_t msg, uint64_t key[2], bool to_encrypt);
    static const sBlock S1;
    static const sBlock S2;
    static const sBlock S3;
    static const sBlock S4;
    static const sBlock S5;
    static const sBlock S6;
    static const sBlock S7;
    static const sBlock S8;
};

#endif
