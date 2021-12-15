#include <tuple>
#include "core.h"
#include <iostream> 
#include <math.h>       /* ceil */

uint64_t compute_transfer(uint128_t token1, uint128_t token2, uint128_t quantity, uint128_t exchange_fee)
{
  const uint128_t coefficient = ceil((token1 * token2 * 1.0) / (token1 + quantity));
  uint128_t transfer = token2 - coefficient;

  std::cout << "Token 1: ";
  print_u128_u(token1);
  std::cout << std::endl << "Token 2: ";
  print_u128_u(token2);
  std::cout << std::endl << "Quantity: ";
  print_u128_u(quantity);
  std::cout << std::endl << "Exchange fee: ";
  print_u128_u(exchange_fee);
  std::cout << std::endl << "Coefficient: ";
  print_u128_u(coefficient);
  std::cout << std::endl << "Transfer 1: ";
  print_u128_u(transfer);

  transfer -= (transfer * exchange_fee) / FEE_FACTOR;


  std::cout << std::endl << "Transfer 2: ";
  print_u128_u(transfer);

  std::cout << std::endl << "Transfer 3: " << static_cast<uint64_t>(transfer) << std::endl;

  return static_cast<uint64_t>(transfer);
}
