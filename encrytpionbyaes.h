#ifndef ENCRYTPIONBYAES_H
#define ENCRYTPIONBYAES_H

#pragma once

#include <string>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/files.h>
#include <cryptopp/osrng.h>
#include <cryptopp/hex.h>

class FileCryptor {
public:
    FileCryptor(const std::string& filePath);
    FileCryptor(const FileCryptor& other);
    ~FileCryptor();

    void generateKeyAndIV();
    void encrypt();
    void decrypt();

private:
    std::string vfilepath;
    void loadKeyAndIV();
    void saveKeyAndIV();

    CryptoPP::AutoSeededRandomPool prng;
    CryptoPP::byte key[CryptoPP::AES::DEFAULT_KEYLENGTH];
    CryptoPP::byte iv[CryptoPP::AES::BLOCKSIZE];
    const std::string filePath;
};

#endif // ENCRYTPIONBYAES_H
