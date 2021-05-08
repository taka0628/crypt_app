#include "../../sha1_c.hpp"

using namespace std;

int main()
{
    SHA_c sh;
    string result = sh.sha1_cal("hogehoge");
    cout << "sha1: " << sh.str2hex(result) << endl;

    result = sh.sha2_cal("hogehoge", SHA_c::SHA2_bit::SHA_224);
    cout << "sha224: " << sh.str2hex(result) << endl;

    result = sh.sha2_cal("hogehoge", SHA_c::SHA2_bit::SHA_256);
    cout << "sha256: " << sh.str2hex(result) << endl;

    result = sh.sha2_cal("hogehoge", SHA_c::SHA2_bit::SHA_384);
    cout << "sha384: " << sh.str2hex(result) << endl;

    result = sh.sha2_cal("hogehoge", SHA_c::SHA2_bit::SHA_512);
    cout << "sha384: " << sh.str2hex(result) << endl;
}