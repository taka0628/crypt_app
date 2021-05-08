#include "RSA_c.hpp"
#include "dynamic_mem_c.hpp"

using namespace std;

int main(){

    string text("hoge");
    RSA_c rsa;
    rsa.create_key(1024);

    string enc_text;
    enc_text = rsa.encrypt(text);
    cout << "rsa_enc: " << rsa.str2hex(enc_text) << endl;

    string dec_text;
    dec_text = rsa.decrypt(enc_text);
    cout << "rsa_dec: " << dec_text << endl;


    return 0;
}