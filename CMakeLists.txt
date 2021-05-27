cmake_minimum_required(VERSION 3.16)

project(Pastel)

set(CMAKE_C_COMPILER "emcc")
set(CMAKE_CXX_COMPILER "em++")

set(CMAKE_CXX_STANDARD 17)

include_directories(
    src
    libs/include
)

# Univalue
add_library(univalue 
    src/univalue/lib/univalue.cpp
    src/univalue/lib/univalue_read.cpp
    src/univalue/lib/univalue_write.cpp
)
target_include_directories(univalue PRIVATE src/univalue/include)

# Leveldb
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
)
target_include_directories(leveldb PRIVATE src/leveldb src/leveldb/include)
target_compile_definitions(leveldb PUBLIC LEVELDB_PLATFORM_POSIX LEVELDB_ATOMIC_PRESENT)

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
    src/keystore.cpp
    src/key_io.cpp
    src/netbase.cpp
    src/primitives/block.cpp
    src/primitives/transaction.cpp
    src/protocol.cpp
    src/pubkey.cpp
    src/scheduler.cpp
    src/script/interpreter.cpp
    src/script/script.cpp
    src/script/script_error.cpp
    src/script/sigcache.cpp
    src/script/sign.cpp
    src/script/standard.cpp
    src/transaction_builder.cpp
    src/uint256.cpp
    src/utiltest.cpp
)
target_include_directories(bitcoin_common PRIVATE src/univalue/include src/secp256k1/include)
target_compile_definitions(bitcoin_common PUBLIC HAVE_CXX_STDHEADERS)

# Pastel wallet
add_library(bitcoin_wallet
    src/utiltest.cpp
    src/wallet/asyncrpcoperation_mergetoaddress.cpp
    src/wallet/asyncrpcoperation_sendmany.cpp
    src/wallet/asyncrpcoperation_shieldcoinbase.cpp
    src/wallet/crypter.cpp
    src/wallet/db.cpp
    src/wallet/rpcdisclosure.cpp
    src/wallet/rpcdump.cpp
    src/wallet/rpcwallet.cpp
    src/wallet/wallet.cpp
    src/wallet/walletdb.cpp
    src/wallet/wallet_ismine.cpp
    src/zcbenchmarks.cpp
)
target_include_directories(bitcoin_wallet PRIVATE src/univalue/include src/leveldb/include)
target_compile_definitions(bitcoin_wallet PUBLIC HAVE_CXX_STDHEADERS)