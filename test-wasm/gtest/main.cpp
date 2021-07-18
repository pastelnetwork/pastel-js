#include <gtest/gtest.h>
#include <libsnark/common/default_types/r1cs_ppzksnark_pp.hpp>
#include <libsnark/zk_proof_systems/ppzksnark/r1cs_ppzksnark/r1cs_ppzksnark.hpp>

#include <emscripten/bind.h>

using namespace emscripten;

int run_all_tests()
{
  libsnark::default_r1cs_ppzksnark_pp::init_public_params();
  libsnark::inhibit_profiling_info = true;
  libsnark::inhibit_profiling_counters = true;

  testing::InitGoogleTest();
  auto ret = RUN_ALL_TESTS();
  return ret;
}

EMSCRIPTEN_BINDINGS(GTEST)
{
  function("RunAllTests", &run_all_tests);
}
