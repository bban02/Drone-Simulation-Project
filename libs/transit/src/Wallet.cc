#include "Wallet.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

// Constructor
Wallet::Wallet() {
  std::srand(static_cast<unsigned int>(
      std::time(nullptr)));  // seed for random number generation
  moneyTotal =
      static_cast<float>(std::rand()) / RAND_MAX * (50.00f - 10.00f) + 10.00f;
  std::cout << "cost: " << moneyTotal << std::endl;
}

// Destructor
Wallet::~Wallet() {}

// getTotal
float Wallet::getTotal() const { return moneyTotal; }

// reduceTotal
bool Wallet::reduceTotal(float amount) {
  if (amount <= moneyTotal) {
    moneyTotal -= amount;
    return true;  // Transaction successful
  } else {
    return false;  // Insufficient funds
  }
}