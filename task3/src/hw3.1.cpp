#include "../included/src/hw3.1.hpp"



int HW31::service()
{
  // define binomial model
  BinomialModel my_model(std::exp(0.3 * std::sqrt(0.5 / 20)), 1.0 / std::exp(0.3 * std::sqrt(0.5 / 20)), 0.03, 30.0);

  // define the call option
  Call my_call(32.0); // initialize with strike price
  unsigned int steps_expiry = 20;
  AmericanVanilla my_optionAC(steps_expiry, my_call);

  //define the put option
  Put my_put(30.0); // initialize with strike price
  AmericanVanilla my_optionAP(steps_expiry, my_put);

  //define the strangle option
  Strangle my_strangle(30.0,32.0);
  AmericanVanilla my_optionAS(steps_expiry, my_strangle);

  // output price
  
  
  std::cout << "American Call option price under binomial model:" << my_optionAC.price_Snell(my_model) << std::endl;

  
  
  std::cout << "American Put option price under binomial model:" << my_optionAP.price_Snell(my_model) << std::endl;

  
  
  std::cout << "American Strangle option price under binomial model:" << my_optionAS.price_Snell(my_model) << std::endl;

  return 0;
}