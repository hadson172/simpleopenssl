#ifndef SEVERALGH_SO_PRECALCULATED_H_
#define SEVERALGH_SO_PRECALCULATED_H_

#include <string>
#include <vector>

namespace so { namespace ut { namespace data {

const static std::string signedText = "test_test_foobar";

// openssl ecparam -name secp256k1 -genkey -noout -out secp256k1-key.pem
const static std::string secp256k1PrivKeyPem = R"(-----BEGIN EC PRIVATE KEY-----
MHQCAQEEILN0LpgGaItTy9e/Jxmat+lHS8NgONqTylUVQ8LxhuD1oAcGBSuBBAAK
oUQDQgAEOJb9wq5BOGI4rD1fbAkHqc+cgHmDJWTDq5zmfaSwYoVXisJw72JuYpLC
TCkP8FeSbd4CvfFmG9L4n9RBcDE1bA==
-----END EC PRIVATE KEY-----)";

// openssl ec -in secp256k1-key.pem -pubout -out public.pem
const static std::string secp256PubKeyPem = R"(-----BEGIN PUBLIC KEY-----
MFYwEAYHKoZIzj0CAQYFK4EEAAoDQgAEOJb9wq5BOGI4rD1fbAkHqc+cgHmDJWTD
q5zmfaSwYoVXisJw72JuYpLCTCkP8FeSbd4CvfFmG9L4n9RBcDE1bA==
-----END PUBLIC KEY-----)";

// openssl dgst -sha256 -sign secp256k1-key.pem -out sha256_out.txt test_test_foobar.txt
const static std::vector<uint8_t> signature_sha256 = {
  0x30, 0x46, 0x02, 0x21, 0x00, 0xc8, 0xcb, 0xef, 0xbe, 0x5a, 0x87, 0x97,
  0xdc, 0xdb, 0xea, 0xc1, 0x02, 0x75, 0xf5, 0xbb, 0x42, 0x0a, 0xf6, 0xe5,
  0x2e, 0xce, 0xf0, 0x94, 0x79, 0xdd, 0x77, 0x63, 0x08, 0xec, 0xfe, 0x58,
  0xa8, 0x02, 0x21, 0x00, 0xe4, 0x38, 0xe1, 0x2e, 0x14, 0xce, 0xa8, 0xe5,
  0xb5, 0x6e, 0x4a, 0x9a, 0x87, 0x9c, 0x10, 0xa6, 0x58, 0x3f, 0x40, 0xa4,
  0xf4, 0x25, 0xd5, 0x73, 0x88, 0x4e, 0xe6, 0x3e, 0x88, 0x2f, 0x65, 0x02
};

// openssl dgst -sha1 -sign secp256k1-key.pem -out sha1_out.txt test_test_foobar.txt
const static std::vector<uint8_t> signature_sha1 = {
  0x30, 0x44, 0x02, 0x20, 0x2b, 0xb8, 0x1f, 0xb4, 0xec, 0x24, 0x2d, 0x52,
  0x19, 0x0b, 0x92, 0x36, 0x4f, 0xf5, 0x6f, 0x0f, 0x5e, 0x0f, 0xee, 0x06,
  0x18, 0x9e, 0x07, 0xdf, 0x2e, 0x4a, 0x51, 0x8d, 0x25, 0x04, 0x73, 0x57,
  0x02, 0x20, 0x0a, 0xf3, 0x24, 0x4f, 0xb9, 0x73, 0x9b, 0x24, 0xf2, 0x06,
  0xcb, 0x60, 0x8d, 0xa5, 0xeb, 0x5d, 0x81, 0xc2, 0x11, 0x4b, 0x1b, 0xc9,
  0x02, 0x3f, 0x70, 0x4b, 0xfd, 0x22, 0x59, 0xa5, 0x0b, 0x22
};

}}} // namespace so { namespace ut { namespace data {

#endif