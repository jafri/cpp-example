#ifndef CORE_H
#define CORE_H

#include <tuple>
#include <stdio.h>
#include <inttypes.h>

using uint128_t = __uint128_t;

static constexpr uint128_t FEE_PRECISION = 100;
static constexpr uint128_t FEE_FACTOR    = FEE_PRECISION * 100;


/*      UINT64_MAX 18446744073709551615ULL */
#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19

#define STRINGIZER(x)   # x
#define TO_STRING(x)    STRINGIZER(x)

static inline int print_u128_u(uint128_t u128)
{
    int rc;
    if (u128 > UINT64_MAX)
    {
        uint128_t leading  = u128 / P10_UINT64;
        uint64_t  trailing = u128 % P10_UINT64;
        rc = print_u128_u(leading);
        rc += printf("%." TO_STRING(E10_UINT64) PRIu64, trailing);
    }
    else
    {
        uint64_t u64 = u128;
        rc = printf("%" PRIu64, u64);
    }
    return rc;
}

uint64_t compute_transfer(uint128_t token1, uint128_t token2, uint128_t quantity, uint128_t exchange_fee);

#endif
