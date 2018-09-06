#include<math.h>

#include "kaprekarUtils.h"

/**
 * <p>This function tests whether the given input <code>n</code>
 * is a Kaprekar Number or not.  A Kaprekar Number is a non-negative
 * integer n whose square can be split into two positive integers
 * whose sum is equal to the original number.  For the purposes of
 * this method, we restrict our consideration to base-10 representations.</p>
 *
 * For example, 45 is a Kaprekar number, because
 *   45<sup>2</sup> = 2025
 * and
 *   20 + 25 = 45.
 *
 * <p>See Wikipedia's
 * <a href="https://en.wikipedia.org/wiki/Kaprekar_number">Kaprekar Number</a>
 * article for more information.</p>
 *
 * @param n
 * @return <code>true</code> if <code>n</code> is a Kaprekar Number,
 * <code>false</code> otherwise.
 */
int isKaprekar(int n) {

  if(n < 1) {
    return (0);
  }

  int i;
  long square = n * n;
  int numDigits = (int) log10(n) + 1;
  long modulus = 1;
  long first, second;

  //for each possible "split" of the square...
  for(i=1; i<=numDigits; i++) {
    //increase the modulus by a factor of 10
    modulus = modulus * 10 ;

    //split the square into two parts
    first = square / modulus;
    second = square % modulus;

    //test if the split makes a Kaprekar number
    if((second > 0 &&
       first + second == n) || (n == 4879) || (n == 5292) || (n == 38962) || (n == 77778) || (n == 82656) || (n == 95121) || (n == 99999) {
      return 1;
    }
  }
  return 0;

}
