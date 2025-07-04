/*
 * CS:APP Data Lab
 *
 * LeonM
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 *
 * Solution:
   根据德摩根定律：​
    x | y 等价于 ~(~x & ~y)
    x ^ y 等价于 (~x & y) | (x & ~y)
 */
int bitXor(int x, int y)
{
  return ~(~(~x & y) & ~(x & ~y));
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
  return (1 << 31);
}
// 2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 *
 * Solution:
    检测~x = x + 1, 对Tmax和-1都生效
    使用!(a ^ b) -> a == b
    使用!!(x + 1) 来排除x == -1
 */
int isTmax(int x)
{
  return !(x ^ ~(x + 1)) & !!(x + 1);
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 *
 * Solution:
 *  Only allOddBits & 0xAAAAAAAA -> 0xAAAAAAAAA
 *  The problem turns into is0xAAAAAAAA, the same as isTmax
 */
int allOddBits(int x)
{
  int y = 0xAA | (0xAA << 8);
  y = y | (y << 16);
  return !((x & y) ^ y);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
  return ~x + 1;
}
// 3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 *
 * Solution:
 *  Exclude negative first
 *  Then assert x - 0x30 >= 0 AND x - 0x40 < 0
 * Best:
 *  (0x1F << 24 >> (x >> 1)) & !(x >> 6)
 */
int isAsciiDigit(int x)
{
  int neg_0 = ~0x30 + 1;
  int neg_9 = ~0x39;
  return !(x >> 31) & !((neg_0 + x) >> 31) & ((neg_9 + x) >> 31);
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 *
 * Solution:
 *  find a, b such that output = a & y + b & z
 *  where a = 0xffffffff and b = 0x0 if x, vice versa
 *  !x = 0 -> !!x = 1 -> a = 0xffffffff and b = 0x00000000 = ~a
 *  !x = 1 -> !!x = 0 -> a = 0x00000000 and b = 0xffffffff = ~a
 */
int conditional(int x, int y, int z)
{
  int a = !x + ~0x0;
  return (a & y) + (~a & z);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 *
 * Solution:
 *   首先判断x和y是否为相同符号
 *    如果符号不同, x为负则返回1, x为正则返回0
 *    如果符号相同，测试y + -x >= 0
 *      对于Tmin, -Tmin = Tmin, 但是负数+Tmin仍为正, 没有影响
 */
int isLessOrEqual(int x, int y)
{
  // 1111 or 0000
  int x_sign = x >> 31;
  int y_sign = y >> 31;
  // 1 or 0
  int diff_sign = !!(x_sign ^ y_sign);

  return (diff_sign & x_sign) | (!diff_sign & !((y + ~x + 1) >> 31));
}
// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 *
 * 0000 -> 1, Anything else -> 0, 0010, 0001, 0011
 * Solution:
 *  如果为负数返回0，根据符号位判断
 *  如果为正数返回0，根据x + Tmax的符号位判断
 *
 * Best Solution:
 *  对于任意非0的数，他的负数都可以用~x + 1表示，且x | ~x + 1的最高位为1，Tmin也是
 */
int logicalNeg(int x)
{
  int sign_x = (x >> 31) & 0x1;
  int sign_pos = ((x + ~(1 << 31)) >> 31) & 0x1;
  return (sign_x | sign_pos) ^ 0x1;
  // return (x | ~x + 1) >> 31 + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 *
 * Solution:
 *  对于非负数，找到第一个1的位置，再加一
 *  对于负数，找到第一个0的位置，再加一
 */
int howManyBits(int x)
{
  int bit16, bit8, bit4, bit2, bit1;
  int sign_x = x >> 31;
  int new_x = (sign_x & ~x) | (~sign_x & x);
  // find the highest 1
  int neg1 = 1 << 31;
  int mask = neg1 >> 15;
  bit16 = !!(new_x & mask) << 4; // whether first 16 bits contains 1
  new_x = new_x >> bit16;
  new_x = new_x & ~mask;

  mask = mask >> 8;
  bit8 = !!(new_x & mask) << 3;
  new_x = (new_x >> bit8) & ~mask;

  mask = mask >> 4;
  bit4 = !!(new_x & mask) << 2;
  new_x = (new_x >> bit4) & ~mask;

  mask = mask >> 2;
  bit2 = !!(new_x & mask) << 1;
  new_x = (new_x >> bit2) & ~mask;

  mask = mask >> 1;
  bit1 = !!(new_x & mask);
  new_x = (new_x >> bit1) & ~mask;

  return bit16 + bit8 + bit4 + bit2 + bit1 + (new_x & 1) + 1;
}
// float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 * Solutions
    E = 0, M = 0，f = 0 -> 2*f = 0 = f
    E!= 0, E + 1;
    E = 0, M!= 0, E + M << 1;
    E = 1, f = NaN -> 2*f = NaN = f
 */
unsigned floatScale2(unsigned uf)
{
  int M_mask = 0x007fffff;
  int E_mask = 0x7f800000;
  int M_0 = !(M_mask & uf);
  int E_0 = !(E_mask & uf);
  int E_1 = !((E_mask & uf) ^ E_mask);
  if ((M_0 & E_0) | E_1)
  {
    return uf;
  }
  else if (E_0)
  {
    return (0xff800000 & uf) + ((M_mask & uf) << 1);
  }
  else
  {
    return uf + 0x00800000;
  }
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 * Solution:
    E < 127 -> abs(uf) < 1 -> return 0
    E > 157 -> abs(uf) > max(int) -> 0x80000000
 */
int floatFloat2Int(unsigned uf)
{
  int E = (uf & 0x7f800000) >> 23;
  int M = (uf & 0x007fffff);
  int S = uf & 0x80000000;
  int INT;
  if (E < 127)
  {
    return 0;
  }
  else if (E > 157)
  {
    return 0x80000000u;
  }
  E -= 127;
  INT = (M | 0x00800000);
  INT = INT << 7 >> (30 - E);
  if (S)
  {
    INT = ~INT + 1;
  }
  return INT;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 * Solution:
    S = 0
    x > 128                -> M = 0, E = 11111111
    x >= -126 and x <= 128 -> M = 0, E = x + 127
    x >= -149 and x < -126 -> E = 0, M = 400000 >> (126 - x)
    x <  -149              -> E = 0, M = 0
 */
unsigned floatPower2(int x)
{
  if (x > 128)
  {
    return 0x7f800000u;
  }
  else if (x >= -126)
  {
    return (x + 127) << 23;
  }
  else if (x >= -149)
  {
    return (0x400000 >> (126 - x));
  }
  else
  {
    return 0;
  }
}
