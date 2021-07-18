cmake_minimum_required(VERSION 3.16)

project(Pastel)

set(CMAKE_C_COMPILER "emcc")
set(CMAKE_CXX_COMPILER "em++")

set(CMAKE_CXX_STANDARD 17)

option(DEBUG "debug version of wasm with -g2 level" OFF)

include_directories(src libs/include)

# Univalue
set(UNIVALUE_INCLUDE "src/univalue/include")
add_library(univalue 
    src/univalue/lib/univalue.cpp
    src/univalue/lib/univalue_get.cpp
    src/univalue/lib/univalue_read.cpp
    src/univalue/lib/univalue_write.cpp
)
target_include_directories(univalue PRIVATE ${UNIVALUE_INCLUDE})

# Leveldb
set(LEVEL_DB_FLAGS "LEVELDB_PLATFORM_POSIX" "LEVELDB_ATOMIC_PRESENT" "HAVE_CXX_STDHEADERS")
set(LEVEL_DB_INCLUDE "src/leveldb/include")
add_library(leveldb 
    src/leveldb/db/builder.cc
    src/leveldb/db/c.cc
    src/leveldb/db/dbformat.cc
    src/leveldb/db/db_impl.cc
    src/leveldb/db/db_iter.cc
    src/leveldb/db/dumpfile.cc
    src/leveldb/db/filename.cc
    src/leveldb/db/log_reader.cc
    src/leveldb/db/log_writer.cc
    src/leveldb/db/memtable.cc
    src/leveldb/db/repair.cc
    src/leveldb/db/table_cache.cc
    src/leveldb/db/version_edit.cc
    src/leveldb/db/version_set.cc
    src/leveldb/db/write_batch.cc
    src/leveldb/helpers/memenv/memenv.cc
    src/leveldb/port/port_posix.cc
    src/leveldb/table/block.cc
    src/leveldb/table/block_builder.cc
    src/leveldb/table/filter_block.cc
    src/leveldb/table/format.cc
    src/leveldb/table/iterator.cc
    src/leveldb/table/merger.cc
    src/leveldb/table/table.cc
    src/leveldb/table/table_builder.cc
    src/leveldb/table/two_level_iterator.cc
    src/leveldb/util/arena.cc
    src/leveldb/util/bloom.cc
    src/leveldb/util/cache.cc
    src/leveldb/util/coding.cc
    src/leveldb/util/comparator.cc
    src/leveldb/util/crc32c.cc
    src/leveldb/util/env.cc
    src/leveldb/util/env_win.cc
    src/leveldb/util/filter_policy.cc
    src/leveldb/util/hash.cc
    src/leveldb/util/histogram.cc
    src/leveldb/util/logging.cc
    src/leveldb/util/options.cc
    src/leveldb/util/status.cc
    src/leveldb/util/testharness.cc
    src/leveldb/util/testutil.cc
    src/leveldb/util/env_posix.cc
)
target_include_directories(leveldb PRIVATE src/leveldb src/leveldb/include)
target_compile_definitions(leveldb PUBLIC ${LEVEL_DB_FLAGS})

# Pastel common
add_library(bitcoin_common
    src/amount.cpp
    src/arith_uint256.cpp
    src/base58.cpp
    src/bech32.cpp
    src/chainparams.cpp
    src/coins.cpp
    src/compressor.cpp
    src/consensus/upgrades.cpp
    src/core_read.cpp
    src/core_write.cpp
    src/hash.cpp
    src/key.cpp
    src/key_io.cpp
    src/keystore.cpp
    src/netbase.cpp
    src/primitives/block.cpp
    src/primitives/transaction.cpp
    src/protocol.cpp
    src/pubkey.cpp
    src/scheduler.cpp
    src/script/interpreter.cpp
    src/script/script.cpp
    src/script/script_error.cpp
    src/script/sign.cpp
    src/script/standard.cpp
    src/transaction_builder.cpp
    src/utiltest.cpp
)
target_include_directories(bitcoin_common PRIVATE src/univalue/include src/secp256k1/include ${LEVEL_DB_INCLUDE})
target_compile_definitions(bitcoin_common PUBLIC ${LEVEL_DB_FLAGS})

# Pastel wallet
add_library(bitcoin_wallet
    src/zcbenchmarks.cpp 
    src/wallet/asyncrpcoperation_mergetoaddress.cpp 
    src/wallet/asyncrpcoperation_sendmany.cpp 
    src/wallet/asyncrpcoperation_shieldcoinbase.cpp 
    src/wallet/crypter.cpp 
    src/wallet/db.cpp 
    src/wallet/paymentdisclosure.cpp 
    src/wallet/paymentdisclosuredb.cpp 
    src/wallet/rpcdisclosure.cpp 
    src/wallet/rpcdump.cpp 
    src/wallet/rpcwallet.cpp 
    src/wallet/wallet.cpp 
    src/wallet/wallet_ismine.cpp 
    src/wallet/walletdb.cpp 
)
target_include_directories(bitcoin_wallet PRIVATE src/univalue/include ${LEVEL_DB_INCLUDE})
target_compile_definitions(bitcoin_wallet PUBLIC ${LEVEL_DB_FLAGS})

# Pastel util
add_library(bitcoin_util
    src/support/lockedpool.cpp 
    src/chainparamsbase.cpp 
    src/clientversion.cpp 
    src/compat/glibc_sanity.cpp 
    src/compat/glibcxx_sanity.cpp 
    src/compat/strnlen.cpp 
    src/random.cpp 
    src/rpc/protocol.cpp 
    src/support/cleanse.cpp 
    src/sync.cpp 
    src/uint256.cpp 
    src/util.cpp 
    src/utilmoneystr.cpp 
    src/ascii85.cpp 
    src/utilstrencodings.cpp 
    src/utiltime.cpp 
)
target_include_directories(bitcoin_util PRIVATE src/univalue/include)
target_compile_definitions(bitcoin_util PUBLIC SODIUM_STATIC)

# Pastel crypto
add_library(bitcoin_crypto
    src/crypto/equihash.cpp
    src/crypto/hmac_sha256.cpp
    src/crypto/hmac_sha512.cpp
    src/crypto/ripemd160.cpp
    src/crypto/sha1.cpp
    src/crypto/sha256.cpp
    src/crypto/sha512.cpp
)

# Pastel cli
add_library(bitcoin_cli
    src/rpc/client.cpp
)
target_include_directories(bitcoin_cli PRIVATE src/univalue/include)

set(BITCOIN_SERVER_FLAGS "ENABLE_WALLET")
# Pastel server
add_library(bitcoin_server
    src/sendalert.cpp
    src/addrman.cpp
    src/alert.cpp
    src/asyncrpcoperation.cpp
    src/asyncrpcqueue.cpp
    src/bloom.cpp
    src/chain.cpp
    src/checkpoints.cpp
    src/deprecation.cpp
    src/httprpc.cpp
    src/httpserver.cpp
    src/init.cpp
    src/dbwrapper.cpp
    src/main.cpp
    src/merkleblock.cpp
    src/metrics.cpp
    src/miner.cpp
    src/net.cpp
    src/noui.cpp
    src/policy/fees.cpp
    src/pow.cpp
    src/rest.cpp
    src/rpc/blockchain.cpp
    src/rpc/mining.cpp
    src/rpc/misc.cpp
    src/rpc/net.cpp
    src/rpc/rawtransaction.cpp
    src/rpc/server.cpp
    src/script/sigcache.cpp
    src/timedata.cpp
    src/torcontrol.cpp
    src/txdb.cpp
    src/txmempool.cpp
    src/validationinterface.cpp
    src/mnode/mnode-config.cpp
    src/mnode/mnode-active.cpp
    src/mnode/mnode-manager.cpp
    src/mnode/mnode-masternode.cpp
    src/mnode/mnode-msgsigner.cpp
    src/mnode/mnode-requesttracker.cpp
    src/mnode/mnode-sync.cpp
    src/mnode/mnode-rpc.cpp
    src/mnode/mnode-validation.cpp
    src/mnode/mnode-payments.cpp
    src/mnode/mnode-governance.cpp
    src/mnode/mnode-messageproc.cpp
    src/mnode/mnode-pastel.cpp
    src/mnode/ticket-processor.cpp
    src/mnode/mnode-notificationinterface.cpp
    src/mnode/mnode-controller.cpp
)
target_include_directories(bitcoin_server PRIVATE src/univalue/include ${LEVEL_DB_INCLUDE} src/leveldb/helpers/memenv src/secp256k1/include src/snark)
target_compile_definitions(bitcoin_server PUBLIC ${LEVEL_DB_FLAGS} ${BITCOIN_SERVER_FLAGS})

set(BITCOIN_ZMQ_FLAGS "ENABLE_ZMQ" "ZMQ_STATIC")
# Pastel zmq
add_library(bitcoin_zmq
    src/zmq/zmqabstractnotifier.cpp
    src/zmq/zmqnotificationinterface.cpp
    src/zmq/zmqpublishnotifier.cpp
)
target_compile_definitions(bitcoin_zmq PUBLIC ${BITCOIN_ZMQ_FLAGS})

# Secp256k1
add_library(secp256k1
    src/secp256k1/src/secp256k1.c
)
target_include_directories(secp256k1 PRIVATE src/secp256k1 src/secp256k1/src)
target_compile_definitions(secp256k1 PUBLIC ENABLE_MODULE_ECDH ENABLE_MODULE_RECOVERY USE_NUM_GMP USE_FIELD_10X26 USE_FIELD_INV_BUILTIN USE_SCALAR_INV_BUILTIN USE_SCALAR_8X32)

# Snark 
set(SNARK_INCLUDE "src/snark/libsnark" "src/snark")
set(SNARK_FLAGS "CURVE_ALT_BN128" "NO_PROCPS" "NO_SUPERCOP" "MONTGOMERY_OUTPUT" "NO_COPY_DEPINST" "NO_GTEST")
add_library(snark
    src/snark/libsnark/algebra/curves/alt_bn128/alt_bn128_g1.cpp
    src/snark/libsnark/algebra/curves/alt_bn128/alt_bn128_g2.cpp
    src/snark/libsnark/algebra/curves/alt_bn128/alt_bn128_init.cpp
    src/snark/libsnark/algebra/curves/alt_bn128/alt_bn128_pairing.cpp
    src/snark/libsnark/algebra/curves/alt_bn128/alt_bn128_pp.cpp
    src/snark/libsnark/common/profiling.cpp
    src/snark/libsnark/common/utils.cpp
    src/snark/libsnark/gadgetlib1/constraint_profiling.cpp
)
target_include_directories(snark PRIVATE ${SNARK_INCLUDE} src/snark )
target_compile_definitions(snark PUBLIC ${SNARK_FLAGS})

set(ZCASH_FLAGS "BOOST_SPIRIT_THREADSAFE" "STATIC")
add_library(zcash
    src/zcash/IncrementalMerkleTree.cpp
    src/zcash/NoteEncryption.cpp
    src/zcash/Address.cpp
    src/zcash/address/sapling.cpp
    src/zcash/address/sprout.cpp
    src/zcash/address/zip32.cpp
    src/zcash/JoinSplit.cpp
    src/zcash/Proof.cpp
    src/zcash/Note.cpp
    src/zcash/prf.cpp
    src/zcash/util.cpp
)
target_include_directories(zcash PRIVATE ${SNARK_INCLUDE})
target_compile_definitions(zcash PUBLIC SODIUM_STATIC ${ZCASH_FLAGS} ${SNARK_FLAGS})

set(PASTELD_FLAGS "ENABLE_WALLET")
set(PASTELD_EMCC_FLAGS "--bind -s ALLOW_MEMORY_GROWTH=1 -s WASM=1 -s EXIT_RUNTIME=0 -s INVOKE_RUN=0 -s MODULARIZE=1 -s DISABLE_EXCEPTION_CATCHING=0 --post-js ${CMAKE_CURRENT_SOURCE_DIR}/js/pastel-post.js -s EXPORT_NAME=Pastel -O2")

if (DEBUG)
    set(PASTELD_EMCC_FLAGS "${PASTELD_EMCC_FLAGS} -g2")
endif()

add_executable(pasteld
    src/pasteld.cpp
    port/port.cpp
    port/bind.cpp
)
target_include_directories(pasteld PRIVATE ${UNIVALUE_INCLUDE} ${LEVEL_DB_INCLUDE})
target_compile_definitions(pasteld PUBLIC ${BITCOIN_ZMQ_FLAGS} ${PASTELD_FLAGS})
target_link_directories(pasteld PRIVATE libs/)
target_link_libraries(pasteld bitcoin_server bitcoin_wallet bitcoin_common bitcoin_zmq bitcoin_crypto bitcoin_util bitcoin_cli zcash snark secp256k1 leveldb univalue)
target_link_libraries(pasteld sodium rustzcash event event_core event_pthreads gmp gmpxx boost_thread boost_chrono boost_program_options boost_system boost_filesystem db_cxx db zmq ssl crypto)
set_target_properties(pasteld PROPERTIES LINK_FLAGS ${PASTELD_EMCC_FLAGS})

# Pastel tests

set(GTEST_EMCC_FLAGS "--bind -s ALLOW_MEMORY_GROWTH=1 -s WASM=1 -s EXIT_RUNTIME=0 -s INVOKE_RUN=0 -s MODULARIZE=1 -s DISABLE_EXCEPTION_CATCHING=0 --post-js ${CMAKE_CURRENT_SOURCE_DIR}/js/pastel-post.js -s EXPORT_NAME=Pastel -O2")

if (DEBUG)
    set(GTEST_EMCC_FLAGS "${GTEST_EMCC_FLAGS} -g2")
endif()

set(GTEST_FLAGS "BOOST_SPIRIT_THREADSAFE" "MONTGOMERY_OUTPUT" "CURVE_ALT_BN128" "BINARY_OUTPUT" "ZMQ_STATIC" "ENABLE_ZMQ" "ENABLE_WALLET")
add_executable(pastel_gtest
    src/gtest/test_random.cpp
    src/gtest/test_txid.cpp
    src/gtest/test_proofs.cpp
    src/gtest/json_test_vectors.cpp
    src/gtest/test_sapling_note.cpp
    src/gtest/test_metrics.cpp
    src/gtest/test_equihash.cpp
    # src/gtest/test_transaction.cpp
    src/gtest/utils.cpp
    test-wasm/gtest/main.cpp
    port/port.cpp
)
target_include_directories(pastel_gtest PRIVATE ${UNIVALUE_INCLUDE} ${LEVEL_DB_INCLUDE} ${SNARK_INCLUDE})
target_compile_definitions(pastel_gtest PUBLIC ${BITCOIN_ZMQ_FLAGS} ${PASTELD_FLAGS})
target_link_directories(pastel_gtest PRIVATE libs/)
target_link_libraries(pastel_gtest event bitcoin_server bitcoin_wallet bitcoin_common univalue bitcoin_util bitcoin_zmq bitcoin_crypto zcash snark secp256k1 leveldb crypto sodium rustzcash gmp gmpxx gtest gmock boost_program_options boost_filesystem boost_thread boost_chrono db_cxx db)
set_target_properties(pastel_gtest PROPERTIES LINK_FLAGS ${GTEST_EMCC_FLAGS})