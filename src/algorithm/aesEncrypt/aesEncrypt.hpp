/*
#pragma once

#include <QCoreApplication>
#include <QString>
#include <QByteArray>
#include <QDebug>

#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

class AESCipher
{
public:
    AESCipher(const QByteArray &key)
    {
        Q_ASSERT(key.size() == 32);
        encryptionKey = key;
        RAND_bytes(iv, AES_BLOCK_SIZE);
    }

    QByteArray encrypt(const QByteArray &plaintext)
    {
        EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
        EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, reinterpret_cast<const unsigned char*>(encryptionKey.data()), iv);

        int ciphertextLen = plaintext.size() + AES_BLOCK_SIZE;
        QByteArray ciphertext(ciphertextLen, 0);

        int len;
        EVP_EncryptUpdate(ctx, reinterpret_cast<unsigned char*>(ciphertext.data()), &len, reinterpret_cast<const unsigned char*>(plaintext.data()), plaintext.size());
        int ciphertextFinalLen = len;
        EVP_EncryptFinal_ex(ctx, reinterpret_cast<unsigned char*>(ciphertext.data()) + len, &len);
        ciphertextFinalLen += len;

        EVP_CIPHER_CTX_free(ctx);

        ciphertext.resize(ciphertextFinalLen);

        QByteArray ivAndCiphertext(iv, AES_BLOCK_SIZE);
        ivAndCiphertext.append(ciphertext);

        return ivAndCiphertext;
    }

    QByteArray decrypt(const QByteArray &ciphertext)
    {
        if (ciphertext.size() < AES_BLOCK_SIZE)
        {
            return QByteArray();
        }

        QByteArray extractedIv = ciphertext.left(AES_BLOCK_SIZE);
        QByteArray actualCiphertext = ciphertext.mid(AES_BLOCK_SIZE);

        EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
        EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, reinterpret_cast<const unsigned char*>(encryptionKey.data()), reinterpret_cast<const unsigned char*>(extractedIv.data()));

        int plaintextLen = actualCiphertext.size();
        QByteArray plaintext(plaintextLen, 0);

        int len;
        EVP_DecryptUpdate(ctx, reinterpret_cast<unsigned char*>(plaintext.data()), &len, reinterpret_cast<const unsigned char*>(actualCiphertext.data()), actualCiphertext.size());
        int plaintextFinalLen = len;
        EVP_DecryptFinal_ex(ctx, reinterpret_cast<unsigned char*>(plaintext.data()) + len, &len);
        plaintextFinalLen += len;

        EVP_CIPHER_CTX_free(ctx);

        plaintext.resize(plaintextFinalLen);

        return plaintext;
    }

private:
    QByteArray encryptionKey;
    unsigned char iv[AES_BLOCK_SIZE];
};
*/
