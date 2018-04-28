#include <vector>
#include <algorithm>
#include <numeric>
#include <gtest/gtest.h>
#include <simpleopenssl/simpleopenssl.h>

#include "precalculated.h"

namespace so { namespace ut { namespace evp {

namespace evp = ::so::evp;

TEST(EvpUT, verifySha1_AgainstPrecalculatedSignature)
{
  // GIVEN
  auto maybeKey = evp::pem2PublicKey(data::secp256PubKeyPem);
  ASSERT_TRUE(maybeKey);
  auto key = *maybeKey;
  std::vector<uint8_t> msg(data::signedText.size());
  std::transform(data::signedText.begin(), data::signedText.end(), msg.begin(), [](char chr){return static_cast<uint8_t>(chr);});

  // WHEN
  const auto verified = evp::verifySha1Signature(data::signature_sha1, msg, *key);

  // THEN
  ASSERT_TRUE(verified);
  EXPECT_TRUE(*verified);
}

TEST(EvpUT, signVerifySHA1_AgainstPrecalculatedKey)
{
  // GIVEN
  auto maybeKey = evp::pem2PrivateKey(data::secp256k1PrivKeyPem);
  ASSERT_TRUE(maybeKey);
  auto key = *maybeKey;
  std::vector<uint8_t> msg(data::signedText.size());
  std::transform(data::signedText.begin(), data::signedText.end(), msg.begin(), [](char chr){return static_cast<uint8_t>(chr);});

  // WHEN
  const auto sig = evp::signSha1(msg, *key); 
  ASSERT_TRUE(sig);
  const auto verified = evp::verifySha1Signature(*sig, msg, *key);
  ASSERT_TRUE(verified);

  // THEN
  EXPECT_TRUE(*verified);
}

TEST(EvpUT, verifySha256_AgainstPrecalculatedSignature)
{
  // GIVEN
  auto maybeKey = evp::pem2PublicKey(data::secp256PubKeyPem);
  ASSERT_TRUE(maybeKey);
  auto key = *maybeKey;
  std::vector<uint8_t> msg(data::signedText.size());
  std::transform(data::signedText.begin(), data::signedText.end(), msg.begin(), [](char chr){return static_cast<uint8_t>(chr);});

  // WHEN
  const auto verified = evp::verifySha256Signature(data::signature_sha256, msg, *key);

  // THEN
  ASSERT_TRUE(verified);
  EXPECT_TRUE(*verified);
}

TEST(EvpUT, signVerifySHA256_AgainstPrecalculatedKey)
{
  // GIVEN
  auto maybeKey = evp::pem2PrivateKey(data::secp256k1PrivKeyPem);
  ASSERT_TRUE(maybeKey);
  auto key = *maybeKey;
  std::vector<uint8_t> msg(data::signedText.size());
  std::transform(data::signedText.begin(), data::signedText.end(), msg.begin(), [](char chr){return static_cast<uint8_t>(chr);});

  // WHEN
  const auto sig = evp::signSha256(msg, *key); 
  ASSERT_TRUE(sig);
  const auto verified = evp::verifySha256Signature(*sig, msg, *key);
  ASSERT_TRUE(verified);

  // THEN
  EXPECT_TRUE(*verified);
}

TEST(EvpUT, signVerifySHA1_ApiIntegrity)
{
  // GIVEN
  std::vector<uint8_t> data(256);
  std::iota(data.begin(), data.end(), 0); 
  auto key = ecdsa::generateKey(ecdsa::Curve::sect571r1);
  ASSERT_TRUE(key);

  auto keyUptr = *key;
  auto maybeEvp = ecdsa::key2Evp(*keyUptr);
  ASSERT_TRUE(maybeEvp);
  auto evpKey = *maybeEvp; 
  
  // WHEN
  const auto sig = evp::signSha1(data, *evpKey);
  const auto verResult = evp::verifySha1Signature(*sig, data, *evpKey);

  // THEN
  ASSERT_TRUE(verResult);
  ASSERT_TRUE(*verResult);
}

TEST(EvpUT, signVerifySHA256_ApiIntegrity)
{
  // GIVEN
  std::vector<uint8_t> data(256);
  std::iota(data.begin(), data.end(), 0); 
  auto key = ecdsa::generateKey(ecdsa::Curve::sect571r1);
  ASSERT_TRUE(key);

  auto keyUptr = *key;
  auto maybeEvp = ecdsa::key2Evp(*keyUptr);
  ASSERT_TRUE(maybeEvp);
  auto evpKey = *maybeEvp; 
  
  // WHEN
  const auto sig = evp::signSha256(data, *evpKey);
  const auto verResult = evp::verifySha256Signature(*sig, data, *evpKey);

  // THEN
  ASSERT_TRUE(verResult);
  ASSERT_TRUE(*verResult);
}

}}} // namespace so { namespace ut { namespace evp {