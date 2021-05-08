#include "RSA_c.hpp"
#include "dynamic_mem_c.hpp"

using namespace std;

int main(){

    string text("hoge");
    RSA_c rsa;
    // rsa.create_key(512);
    rsa.set_key();

    string enc_text;
    enc_text = rsa.encrypt(text);
    cout << "rsa_enc: " << rsa.str2hex(enc_text) << endl;

    string dec_text;
    dec_text = rsa.decrypt(enc_text);
    cout << "rsa_dec: " << dec_text << endl;

    enc_text = "35de63c4c6faf2db6b7b7f18512d816b59687c6a6fa6a329922ab11f21e427b5d7d1068bac0329def190e05a61c05f94e3f50721bdbd99e38037853991a4fe4b";
    enc_text = rsa.hex2bin(enc_text);

    dec_text = rsa.decrypt(enc_text);
    cout << "rsa_dec: " << dec_text << endl;

    string pub_key;
    pub_key = rsa.get_string_key(RSA_c::KEY_STATUS::PUB_KEY);
    cout << "pubkey: " << pub_key << endl;

    string priv_key;
    priv_key = rsa.get_string_key(RSA_c::KEY_STATUS::PRIV_KEY);
    cout << "privkey: " << priv_key << endl;


    return 0;
}