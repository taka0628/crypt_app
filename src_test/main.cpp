#include "../aes_c.hpp"

using namespace std;

int main(){
    aes_c aes;

    string in = "hoge";
    string out_enc;

    aes.set_key("bf6c555fe68fc8e4db7250b66e937516");
    aes.set_iv("98cdfe671a59a5c26cd3c171837a8e99");

    if(aes.get_key().size() != 32){
        cout << "key create" << endl;
        aes.create_key(128);
    }
    if(aes.get_iv().size() != 32){
        cout << "iv create" << endl;
        aes.create_iv(128);
    }
    cout << endl;
    aes.encrypt(out_enc, in, aes_c::AES_bit_e::aes_128);
    cout << "in: " << in << endl;
    aes.print_0x("in_0x: ", in);
    aes.print_0x("enc_0x: ", out_enc);
    cout << "str2hex: " << aes.str2hex(out_enc) << endl;

    cout << endl;

    string out_dec;
    string text = "0eeac683";
    string enc_bin = aes.hex2str(text);
    aes.print_0x("enc_a0x: ", out_enc);
    aes.print_0x("enc_b1x: ", enc_bin);
    cout << "enc: " << out_enc << endl;
    aes.print_0x("enc_b2x: ", enc_bin);
    cout << "bin: " << enc_bin << endl;
    aes.print_0x("enc_b3x: ", enc_bin);

    aes.decrypt(out_dec, enc_bin, aes_c::AES_bit_e::aes_128);
    // aes.decrypt(out_dec, out_enc);
    aes.print_0x("dec_0x: ", out_dec);
    cout << "dec: " << out_dec << endl;

    cout << "key: " << aes.get_key() << endl;
    cout << "iv: " << aes.get_iv() << endl;

    return 0;
}