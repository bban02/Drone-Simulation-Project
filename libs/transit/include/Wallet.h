#ifndef WALLET_H
#define WALLET_H

/**
 * @class Wallet
 * @brief Represents a wallet with a total amount of money.
 *
 * The Wallet class allows for managing the total amount of money and reducing
 * it by a specified amount.
 */
class Wallet {
 private:
  float moneyTotal;

 public:
  /**
   * @brief Constructor for the Wallet class.
   *
   * Initializes the total money in the wallet with a random value between 10.00
   * and 50.00.
   */
  Wallet();

  /**
   * @brief Destructor for the Wallet class.
   */
  ~Wallet();

  /**
   * @brief Gets the total money in the wallet.
   * @return The total money in the wallet.
   */
  float getTotal() const;

  /**
   * @brief Reduces the total money in the wallet by a specified amount.
   * @param amount The amount to reduce the total money by.
   * @return True if the reduction was successful, false if the amount is
   * greater than the total money.
   */
  bool reduceTotal(float amount);
};

#endif  // WALLET_H