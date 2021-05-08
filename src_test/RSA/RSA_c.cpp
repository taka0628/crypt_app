#include "RSA_c.hpp"
#include "dynamic_mem_c.hpp"

#define ERROR(comment) \
    printf("[ERROR]\n\t%s: %d\n\t%s\n", __func__, __LINE__, comment);

RSA_c::RSA_c()
{
    this->key_size = 0;
    this->pub_key = nullptr;
    this->priv_key = nullptr;
    this->key_pair = nullptr;
    this->PUB_FILE_NAME = "RSA_public_key";
    this->PRIV_FILE_NAME = "RSA_private_key";
}

RSA_c::~RSA_c()
{
    if (this->priv_key)
    {
        OPENSSL_free(this->priv_key);
        this->priv_key = nullptr;
    }
    if (this->pub_key)
    {
        OPENSSL_free(this->pub_key);
        this->pub_key = nullptr;
    }
    if (this->key_pair)
    {
        OPENSSL_free(this->key_pair);
        this->key_pair = nullptr;
    }
    this->key_size = 0;
}

using namespace std;

string RSA_c::encrypt(const string &in) const
{
    dynamic_mem_c buf;
    buf.d_new(RSA_size(this->pub_key));

    int out_size = RSA_public_encrypt(in.size(), (unsigned char *)in.c_str(), buf.mem, this->pub_key, RSA_PKCS1_OAEP_PADDING);
    if (out_size <= 0)
    {
        int error = ERR_get_error();
        string str_error;
        str_error = ERR_reason_error_string(error);
        printf("%s\n", str_error.c_str());
        ERROR("RSA_public_encrypt");
        return nullptr;
    }

    string result;
    buf.copy(result, out_size);

    return result;
}

string RSA_c::decrypt(const string &in) const
{
    dynamic_mem_c buf;
    buf.d_new(this->key_size);
    int out_size = RSA_private_decrypt(in.length(), (unsigned char *)in.c_str(), buf.mem, this->priv_key, RSA_PKCS1_OAEP_PADDING);
    if (out_size <= 0)
    {
        int error = ERR_get_error();
        string str_error;
        str_error = ERR_reason_error_string(error);
        printf("%s\n", str_error.c_str());
        ERROR("RSA_private_decrypt");
        return nullptr;
    }

    string result;
    buf.copy(result, out_size);

    return result;
}

void RSA_c::create_key(const uint bit)
{
    BIGNUM *bn = BN_new();
    BN_set_word(bn, RSA_F4);

    this->key_pair = RSA_new();
    RSA_generate_key_ex(this->key_pair, (int)bit, bn, NULL);
    this->key_size = bit;

    this->create_RSA_file(KEY_STATUS::PRIV_KEY, this->PRIV_FILE_NAME);
    this->create_RSA_file(KEY_STATUS::PUB_KEY, this->PUB_FILE_NAME);

    BN_free(bn);
    bn = nullptr;
}

string RSA_c::str2hex(const string &str) const
{
    stringstream buf;
    char p[10];
    for (size_t i = 0; i < str.size(); i++)
    {
        sprintf(p, "%02x", (unsigned char)str[i]);
        buf << p;
    }
    return buf.str();
}

string RSA_c::hex2bin(const string &hex) const
{
    char buf[3] = {0};
    unsigned char *bin = (unsigned char *)calloc(sizeof(char), hex.size());
    int binsize = hex.size();
    printf("binsize: %d\n", binsize);

    string result;
    result.erase(result.begin(), result.end());
    char *pch;
    memset((void *)bin, 0, hex.size());
    for (size_t i = 0; i < hex.size(); i += 2)
    {
        buf[0] = hex[i];
        buf[1] = hex[i + 1];
        pch = buf;
        bin[i / 2] = (unsigned char)strtoul(pch, NULL, 16);
        cout << "strtoil: " << strtoul(pch, NULL, 16) << endl;
        // result[i / 2] = char_out;
        // result[i / 2 + 1] = NULL;
        // result.push_back(char_out);
        result.push_back(bin[i / 2]);
    }
    free(bin);
    bin = nullptr;
    return result;
}

string RSA_c::get_pub_key() const
{

}

void RSA_c::create_RSA_file(KEY_STATUS pem_type, std::string file_name)
{
    FILE *fp = nullptr;

    if (pem_type == KEY_STATUS::PUB_KEY)
    {
        fp = fopen(file_name.c_str(), "w");
        PEM_write_RSAPublicKey(fp, this->key_pair);
        fclose(fp);

        fp = fopen(file_name.c_str(), "rb");
        PEM_read_RSAPublicKey(fp, &this->pub_key, NULL, NULL);
        fclose(fp);
    }
    else if (pem_type == KEY_STATUS::PRIV_KEY)
    {
        fp = fopen(file_name.c_str(), "w");
        PEM_write_RSAPrivateKey(fp, this->key_pair, NULL, NULL, this->key_size, NULL, NULL);
        fclose(fp);

        fp = fopen(file_name.c_str(), "rb");
        PEM_read_RSAPrivateKey(fp, &this->priv_key, NULL, NULL);
        fclose(fp);
    }

    fp = nullptr;
}
