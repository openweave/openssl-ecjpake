/*
 *
 *    Copyright (c) 2017 Google LLC.
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include <stdio.h>
#include <openssl/err.h>
#include "ecjpake.h"

/* BEGIN ERROR CODES */
#if !defined(OPENSSL_NO_ERR) && !defined(OPENSSL_IS_BORINGSSL)

# define ERR_FUNC(func) ERR_PACK(ERR_LIB_ECJPAKE,func,0)
# define ERR_REASON(reason) ERR_PACK(ERR_LIB_ECJPAKE,0,reason)

static ERR_STRING_DATA ECJPAKE_str_functs[] = {
    {ERR_FUNC(ECJPAKE_F_COMPUTE_KEY), "compute_key"},
    {ERR_FUNC(ECJPAKE_F_EC_POINT_IS_LEGAL), "EC_POINT_is_legal"},
    {ERR_FUNC(ECJPAKE_F_ECJPAKE_CTX_NEW), "ECJPAKE_CTX_new"},
    {ERR_FUNC(ECJPAKE_F_ECJPAKE_STEP1_GENERATE), "ECJPAKE_STEP1_generate"},
    {ERR_FUNC(ECJPAKE_F_ECJPAKE_STEP1_PROCESS), "ECJPAKE_STEP1_process"},
    {ERR_FUNC(ECJPAKE_F_ECJPAKE_STEP2_GENERATE), "ECJPAKE_STEP2_generate"},
    {ERR_FUNC(ECJPAKE_F_ECJPAKE_STEP2_PROCESS), "ECJPAKE_STEP2_process"},
    {ERR_FUNC(ECJPAKE_F_ECJPAKE_STEP3A_PROCESS), "ECJPAKE_STEP3A_process"},
    {ERR_FUNC(ECJPAKE_F_ECJPAKE_STEP3B_PROCESS), "ECJPAKE_STEP3B_process"},
    {ERR_FUNC(ECJPAKE_F_GENERATE_ZKP), "generate_zkp"},
    {ERR_FUNC(ECJPAKE_F_GENRAND), "genrand"},
    {ERR_FUNC(ECJPAKE_F_STEP_PART_GENERATE), "step_part_generate"},
    {ERR_FUNC(ECJPAKE_F_STEP_PART_INIT), "step_part_init"},
    {ERR_FUNC(ECJPAKE_F_VERIFY_ZKP), "verify_zkp"},
    {ERR_FUNC(ECJPAKE_F_ZKP_HASH), "zkp_hash"},
    {0,NULL}
};

static ERR_STRING_DATA ECJPAKE_str_reasons[] = {
    {ERR_REASON(ECJPAKE_R_G_IS_NOT_LEGAL), "Gx is not legal"},
    {ERR_REASON(ECJPAKE_R_G_TO_THE_X3_IS_NOT_LEGAL),
     "Gx to the x3 is not legal"},
    {ERR_REASON(ECJPAKE_R_G_TO_THE_X4_IS_NOT_LEGAL),
     "Gx to the x4 is not legal"},
    {ERR_REASON(ECJPAKE_R_HASH_OF_HASH_OF_KEY_MISMATCH),
     "hash of hash of key mismatch"},
    {ERR_REASON(ECJPAKE_R_HASH_OF_KEY_MISMATCH), "hash of key mismatch"},
    {ERR_REASON(ECJPAKE_R_VERIFY_X3_FAILED), "verify x3 failed"},
    {ERR_REASON(ECJPAKE_R_VERIFY_X4_FAILED), "verify x4 failed"},
    {ERR_REASON(ECJPAKE_R_VERIFY_X4S_FAILED), "verify x4*s failed"},
    {ERR_REASON(ECJPAKE_R_ZKP_VERIFY_FAILED), "zkp verify failed"},
    {0,NULL}
};

#endif

void ERR_load_ECJPAKE_strings(void)
{
#if !defined(OPENSSL_NO_ERR) && !defined(OPENSSL_IS_BORINGSSL)

    if (ERR_func_error_string(ECJPAKE_str_functs[0].error) == NULL) {
        ERR_load_strings(0, ECJPAKE_str_functs);
        ERR_load_strings(0, ECJPAKE_str_reasons);
    }
#endif
}
