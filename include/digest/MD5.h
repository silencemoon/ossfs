/*
 * @file MD5.h
 * @brief MD5 digest algorithm
 *
 * @version 1.0
 * @date Sun Sep 23 16:22:49 2012
 *
 * @copyright Copyright (C) 2012 UESTC
 * @author shiwei<shiwei2012@gmail.com>
 */

#ifndef digest_MD5_H_
#define digest_MD5_H_

#include <string>

#include <openssl/md5.h>

namespace ossfs
{


class MD5
{
public:
    static const unsigned int DIGEST_LENGTH;
    static const unsigned int HEX_DIGEST_LENGTH;

public:
    MD5();

    ~MD5();

    /**
     * @brief get hash value in hex in one call
     *
     * @param data
     *
     * @return hash value in hex, empty if failed
     */
    static std::string md5(const std::string &data);

    /**
     * @brief Initialize MD5 context
     *
     * @return 
     */
    bool init();

    /**
     * @brief Transform data for hash value computing.
     *
     * @param data
     *
     * @return 
     */
    bool update(const std::string &data);

    /**
     * @brief Finalize the computing.
     *
     * @return 
     */
    bool final();

    /**
     * @brief get raw digest after init, update and final
     *
     * @return
     */
    std::string digest() const;

    /**
     * @brief get digest in hex format
     *
     * @return
     */
    std::string digestHex() const;

private:
    MD5_CTX _ctx;
    unsigned char *_md;
};



}  // namespace ossfs


#endif  // digest_MD5_H_

