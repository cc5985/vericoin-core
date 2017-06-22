// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The VeriCoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;

#include "chainparamsseeds.h"

/**
 * Main network
 */
/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.nMaxReorganizationDepth = 500;
        consensus.nMajorityEnforceBlockUpgrade = 750;
        consensus.nMajorityRejectBlockOutdated = 950;
        consensus.nMajorityWindow = 1000;
        consensus.powLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.posLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.posLimitV2 = uint256S("000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nTargetTimespan = 16 * 60; // 16 mins
        consensus.nTargetSpacing = 60;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.nLastPOWBlock = 20160;
        consensus.nStakeTimestampMask = 0xf;
        /** 
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
        pchMessageStart[0] = 0x70;
        pchMessageStart[1] = 0x35;
        pchMessageStart[2] = 0x22;
        pchMessageStart[3] = 0x05;
        vAlertPubKey = ParseHex("047eba500c7134efcaf721e9f438f25b948ceaa5f059b877b3a64f6fa2cf0ea6f41091bd9b1ff9448727db97e4ad44d49496dc41949c677c49fe632d1d7996a515");
        nDefaultPort = 58684;
        nMinerThreads = 0;
        nMaxTipAge = 24 * 60 * 60;
        nPruneAfterHeight = 100000;

        // Genesis block

        // MainNet:

        // CBlock(hash=34125fc48033d7284178f16d16c0851e1cd75906e65b499cca66e5407c60ae65, ver=1, hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000, hashMerkleRoot=60424046d38de827de0ed1a20a351aa7f3557e3e1d3df6bfb34a94bc6161ec68, nTime=1399690945, nBits=1e0fffff, nNonce=222826, vtx=1, vchBlockSig=)
        // Coinbase(hash=60424046d3, nTime=1399690945, ver=1, vin.size=1, vout.size=1, nLockTime=0)
        //  CTxIn(COutPoint(0000000000, 4294967295), coinbase 00012a3639204d6179203230313420555320706f6c6974696369616e732063616e2061636365707420626974636f696e20646f6e6174696f6e73)
        //  CTxOut(empty)
        // vMerkleTree: 60424046d3

        const char* pszTimestamp = "9 May 2014 US politicians can accept bitcoin donations";
        CMutableTransaction txNew;
        txNew.nTime = 1399690945;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 0 << CScriptNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].SetEmpty();
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock.SetNull();
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1399690945;
        genesis.nBits    = 0x1e0fffff;
        genesis.nNonce   = 612416;

        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x000004da58a02be894a6c916d349fe23cc29e21972cafb86b5d3f07c4b8e6bb8"));
        assert(genesis.hashMerkleRoot == uint256S("0x60424046d38de827de0ed1a20a351aa7f3557e3e1d3df6bfb34a94bc6161ec68"));

        vSeeds.push_back(CDNSSeedData("vericoin.info", "dnsseed.vericoin.info"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,70);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,132);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,198);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = false;

        checkpointData = (Checkpoints::CCheckpointData) {
            boost::assign::map_list_of
            ( 2700,    uint256S("0x52f0119bd2252422ea4aebb25273a98155972cf25a6ef267a7ef35103b5466c3") )
            ( 5700,    uint256S("0x000000001c3865f29140f49217c99ad985e80e89ca4d1e6a518a47f6961d6f16") )
            ( 10080,   uint256S("0x00000000023212158c4a50727711ffc9ddbcb246e7c34e8a6668c49aad3b5390") )
            ( 16346,   uint256S("0x0000000002963467ff7c61f53f2a141819e8dcd04b5320e1e78f50d52e4d312e") )
            ( 24533,   uint256S("0xccec1c9940fcc78e95ecb75213469a8220280e23bab4976d2132e0b5513798cb") )
            ( 26196,   uint256S("0x84d6eac78587fad5c11a0475ee6085bbff505e3d3be78734c6be2908c5154849") )
            ( 27159,   uint256S("0x9bad4fb0cdc3a774981d53eef6fda7fb3fe720b2f847dbb9b6eafba72f535571") )
            ( 107670,  uint256S("0xcbe5acc625d669c603943daa26e7bac3fcacb8f95d4a8fa2b00092ad22407a1a") )
            ( 107671,  uint256S("0x61d59bbc7cbced427d0c4c6d779c1a7ad327bf788890b2cf4d3e2abdf11979e6") )
            ( 107672,  uint256S("0x704197d86f68ec75a3a15e32ad6dc1a956400671a88eb2926e9bb78136cc8e0b") )
            ( 107699,  uint256S("0xd4f67d88408ce3c268dc35478b10821f0bb787a7d131bdb57e94bd5c1b02078d") )
            ( 107700,  uint256S("0x426cf03d395d0578d943a16e2dade3ae791d3d8759395fea99a98db62a778037") )
            ( 107720,  uint256S("0x32d622ffeac54b872a04fb18df90807cb11e28452597acd410237ee05c89fb45") )
            ( 107738,  uint256S("0xf0d742fd0a1aeaadf432f8af19276d5ecbb07a0706284d6cc0a70fb270a3d697") )
            ( 130932,  uint256S("0xdced5f5ee627cb8af12c3439eb7e7f049f83235459377bf5981e8b906e1a945f") )
            ( 137725,  uint256S("0xce241207536b7eada68b247edcfc1240e46dbf216385f102ade02645be07f6ef") )
            ( 239355,  uint256S("0xe662449e6b86f473777749add48c2b6d33900227d4c283a9366d845a4dd92a71") )
            ( 239526,  uint256S("0x4d07e6a7b3b1fda725d1e113eb2f04b188286a053b04833431ee81373de1ff58") )
            ( 241527,  uint256S("0x80afc89cbee28cfc516b9c88c9d74446caa9a284bdcbe4e1655abd911044ac71") )
            ( 242108,  uint256S("0x5fd020de15dff256b9136b9c874d11e2db25d960a546606c8d936afcefd2516a") )
            ( 295000,  uint256S("0xc441ac33032db312b6fd7e62fe9774ad4f9d8d23c61c2047734b71667319999c") )
            ( 914000,  uint256S("0xdeb31aa6af3b8d4e370faab196bbc8701146b900b93102ef432b23cd1d23dcb6") )
            ( 1417780, uint256S("0xa5a4ae40a0f1c0a3517dc5e2e60a3020247c0f9878b40720099477609635a652") )
            ( 1417877, uint256S("0x3c509ffd917975972001651a1cf666bb18112d9e31e4f484c2b2d922779e0755") )
            ( 1418062, uint256S("0xf529c1f076221cc45e6c1f2003f4e1813330587597184444b43cc74042d241eb") )
            ( 1418635, uint256S("0xde3adb390cd9a95bcec4a2e40b74821f364c6f8a71728f37f4249155cd92dabc") ),
            1476866612, // * UNIX timestamp of last checkpoint block
            2774767,    // * total number of transactions between genesis and last checkpoint
                        //   (the tx=... number in the SetBestChain debug.log lines)
            3500.0      // * estimated number of transactions per day after checkpoint
        };
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        strNetworkID = "test";
        consensus.nMajorityEnforceBlockUpgrade = 51;
        consensus.nMajorityRejectBlockOutdated = 75;
        consensus.nMajorityWindow = 100;
        consensus.powLimit = uint256S("0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.nLastPOWBlock = 20160;
        pchMessageStart[0] = 0xcd;
        pchMessageStart[1] = 0xf2;
        pchMessageStart[2] = 0xc0;
        pchMessageStart[3] = 0xef;
        vAlertPubKey = ParseHex("0471dc165db490094d35cde15b1f5d755fa6ad6f2b5ed0f340e3f17f57389c3c2af113a8cbcc885bde73305a553b5640c83021128008ddf882e856336269080496");
        nDefaultPort = 48684;
        nMinerThreads = 0;
        nMaxTipAge = 0x7fffffff;
        nPruneAfterHeight = 1000;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = 0x1f00ffff;
        genesis.nNonce = 712750;
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x0000d90349e5898a5cb76775e93f8774138d48cd2d763c7707ce87d42af0f66a"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        checkpointData = (Checkpoints::CCheckpointData) {
            boost::assign::map_list_of
            ( 0, uint256S("0x0000d90349e5898a5cb76775e93f8774138d48cd2d763c7707ce87d42af0f66a")),
            0,
            0,
            0
        };

    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        strNetworkID = "regtest";
        consensus.nMajorityEnforceBlockUpgrade = 750;
        consensus.nMajorityRejectBlockOutdated = 950;
        consensus.nMajorityWindow = 1000;
        consensus.powLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        nMinerThreads = 1;
        nMaxTipAge = 24 * 60 * 60;
        genesis.nTime = 1411111111;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 2;
        consensus.hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 48684;
        assert(consensus.hashGenesisBlock == uint256S("0x0000d90349e5898a5cb76775e93f8774138d48cd2d763c7707ce87d42af0f66a"));
        nPruneAfterHeight = 1000;

        vFixedSeeds.clear(); //! Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();  //! Regtest mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;

        checkpointData = (Checkpoints::CCheckpointData){
            boost::assign::map_list_of
            ( 0, uint256S("0x0000d90349e5898a5cb76775e93f8774138d48cd2d763c7707ce87d42af0f66a")),
            0,
            0,
            0
        };
    }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = 0;

const CChainParams &Params() {
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams &Params(CBaseChainParams::Network network) {
    switch (network) {
        case CBaseChainParams::MAIN:
            return mainParams;
        case CBaseChainParams::TESTNET:
            return testNetParams;
        case CBaseChainParams::REGTEST:
            return regTestParams;
        default:
            assert(false && "Unimplemented network");
            return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network) {
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
