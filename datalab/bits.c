/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  return ~((~x)&(~y));
  //집합에서 두 여집합(~x, ~y)의 교집합(&)을 구하고 그것의 여집합을 구하면 합집합(OR)이 나온다.(드모르간)
  //bit 연산의 x, y를 일종의 0과 1의 집합으로 보고 이를 이용하였다.
}
/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {
  int mask = (0xAA << 8) + 0xAA; //0101010101010101
  return ((mask << 16) + mask); // 01010101010101010101010101010101
  //01010101을 구하는 것이므로 01010101에 해당하는 0xAA에 단순 shift연산을 써서 구해준다.
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
  int tmax = ~(1<<31); //0111...111
  int rightShift = 32 + (~n); //적당한 수준의 0000....1111 형태의 right number mask를 만들 수 있다.

  int leftMask = ~0<<n; //~를 써서 1111...000 형태의 mask 만들기
  int rightMask = tmax>>rightShift;
  int leftNum = (x << n) & leftMask; //mask씌우고 shift해서 기존의 왼쪽에 있던 숫자를 오른쪽으로 옮긴다
  int rightNum = (x >> (rightShift+1)) & rightMask; //마찬가지로 기존에 오른쪽 숫자를 왼쪽으로 옮긴다.
  return (leftNum|rightNum); //합치면 rotate한 효과와 동일하게 나온다.
}
/*
 * bitReverse - Reverse bits in a 32-bit word
 *   Examples: bitReverse(0x80000002) = 0x40000001
 *             bitReverse(0x89ABCDEF) = 0xF7D3D591
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int bitReverse(int x) {
  
  int mask_16 = ((0xFF<<8)|(0xFF)); //3 0x0000FFFF

  int mask_8 = ((0xFF<<16)|(0xFF)); //00FF00FF
  
  int mask_4_low = (0x0F<<8)|(0x0F); // 0F0F0F0F
  int mask_4 = (mask_4_low<<16)|mask_4_low;
  
  int mask_2_low = (0x33<<8)|(0x33); //33333333
  int mask_2 = (mask_2_low<<16)|mask_2_low; //33333333
  
  int mask_1_low = (0x55<<8)|(0x55); //55555555
  int mask_1 = (mask_1_low<<16)|mask_1_low; //55555555

  
  x = ((x >> 16)& mask_16)|(((x & mask_16)<< 16)); 
  x = ((x >> 8)& mask_8)|(((x & mask_8) << 8)); 
  x = ((x >> 4)& mask_4)|(((x & mask_4) << 4)); 
  x = ((x >> 2)& mask_2)|(((x & mask_2) << 2)); 
  x = ((x >> 1)& mask_1)|(((x & mask_1) << 1));
  
  //맨 처음에는 11111111111111110000000000000000과 00000000000000001111111111111111 를 mask로 쓰고, 두 위치의 숫자들의 자리를 바꾼다.
  //그 다음에는 11111111000000001111111100000000과 00000000111111110000000011111111 를 mask로 써서 두 위치의 숫자들의 자리를 바꾼다.
  //다음으로는 11110000111100001111000011110000과 00001111000011110000111100001111 을 구해서 자리를 바꾼다.
  //0, 1을 2개씩 묶은 형태, 0과 1이 번갈아 나타나는 형태의 mask에 대해서도 이 과정을 반복한다.
  //이 경우 숫자의 위치가 뒤집힌다. 이는 주석보다 코드로 보는 것이 이해하기 빠르다.

  return x;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  //오로지 숫자 0만 ~x+1 했을 때 자기 자신이 나옴을 이용한다.
  int negX = ~x+1;
  int sign = (x|negX)>>31; //0이면 0이 나오고 0이 아니면 111....111(=-1) 이 나온다.
  return sign+1; //1을 더하면 0이면 1이 나오고 0이 아니면 0이 나온다.
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  return (~(1<<31));
  //맨 앞 비트가 sign bit이므로 0111...111이 가장 큰 수이고 이는 100...000을 ~해주면 나온다.
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ((~x)+1);
  //two's complement에서 음수를 구하는 개념을 이용하면 바로 구할 수 있다.
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int shift_val = 32+(~n+1);
  int shifted_x = (x<<shift_val)>>shift_val;

  return !(x^shifted_x);
}
/* 
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: dividePower2(15,1) = 7, dividePower2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int dividePower2(int x, int n) {
    //Power2를 구하기, Power2보다 크면 n만큼 >>
    return (x + ((x >> 31) & ((1 << n) + ~0))) >> n;
}   
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int xIsZero = (~(!x)+1); //x가 0이 아니면 000...000 x가 0이면 111...111
  int xIsNotZero = ~xIsZero; //위의 inverse

  return (xIsNotZero&y)|(xIsZero&z); //000..000 111..111 mask를 상황에 따라 사용해서 OR연산 시킨다.
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  //등호가 없음에 주의해야 한다.
  //초과 보다는 이상/이하를 구하는게 훨씬 쉬우므로 y가 x이상인 경우를 구하고 ~시킨다
  int opp = ((x^y)>>31); //x, y 부호 비교, 부호가 같으면 0 다르면 1
  int is_x_neg = x>>31; // x가 neg인 경우
  int sub_val = ( ~ ((y + (~x + 1)) >> 31 ) ); // 부호가 같으면 뺄셈연산을 수행한다. y가 크면 1 작거나 같으면 0
  return !((!!(is_x_neg&opp)) | (!!(sub_val&(~opp))));
}
/*
 * intLog2 - return floor(log base 2 of x), where x > 0
 *   Example: intLog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int intLog2(int x) {

    int sr_16 = !!(x >> 16); //x가 2^16보다 크면 1 작으면 0
    int sl_16 = sr_16 << 4; 
    int sr_8 = !!(x >> (8 + sl_16)); //sl_16값에 따라 왼쪽 혹은 오른쪽 절반 탐색
    int sl_8 = (sr_8 << 3) + sl_16;
    int sr_4 = !!(x >> (4 + sl_8)); //같은 방법으로 이진탐색 형태로 반복한다. 
    int sl_4 = (sr_4 << 2) + sl_8; 
    int sr_2 = !!(x >> (2 + sl_4));
    int sl_2 = (sr_2 << 1) + sl_4;
    int sr_1 = (x >> (1 + sl_2));
    return sr_1 + sl_2;

    //Log2함수는 다르게 작거나 같은 최대의 2의 N승의 N을 찾는 함수이다.
    //이는 다르게 말하면 전체 수에서 가장 왼쪽에 있는 1의 위치를 찾는 것과 마찬가지이다.
    //각 단계에서 적절한 값만큼 shift해서 0이 나오는지 아닌지를 기준으로 더 왼쪽에 1이 있는지 아닌지를 판단한다
    //만약 더 왼쪽에 1이 있으면 다음 단계에는 bias를 붙여주어 왼쪽 부분을 탐색하게 하고 그렇지 않으면 오른쪽을
    //탐색하게 한다. 이는 일종의 이진탐색 알고리즘과 비슷하다.
  }
/* 
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf) {
  unsigned absMask = 0x7FFFFFFF; //sign비트를 제외한 31비트 mask이다.
  unsigned isNaN = 0x7F800001;
  unsigned absVal = uf & absMask;		// 31bit mask로 부호를 양수로 만든다. 이미 실수인 경우의 절댓값은 계산되었다.
  
  // NaN이 나오는 경우 주어진 조건대로 uf를 그대로 return한다
  if (isNaN <= absVal)
  {
    return uf;
  }
  else
  {
    return absVal; //그렇지 않으면 절댓값을 반환한다.
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
 */
int floatFloat2Int(unsigned uf) {
  unsigned sign = uf >> 31;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac =(uf & 0x7FFFFF);
  unsigned bias = 0x7F;
  unsigned result = frac;
  
  // 먼저 NaN과 inf에 대해 예외 처리를 해준다. 이 때 exp=255(최대값)이다. 
  if (exp == 0xFF) 
  {
    return 0x80000000u;
  } 
  
  // exp가 bias보다 작은 경우는 절댓값이 1보다 작은 소수들이고 모두 0으로 만든다.
  if (exp < bias) 
  {
    return 0;
  }
  
  // exp가 bias보다는 큰 경우에 대해 overflow를 계산해야 하고 bias를 빼준다. 
  exp = exp-bias;
  
  // 32bit int에서 나타낼 수 있는 수는 2^32를 넘길 수 없으므로 exp가 31이상이면 overflow가 발생한다. 예외처리한다.
  if (exp >= 31) 
  {
    return 0x80000000u;
  } 
  
  // fraction이 기본으로 22번째 자리까지 있으므로 exponent 값에 따라 위치를 조정해준다. (2^exp-127을 frac에 곱하는 과정)
  if (exp > 22) 
  {
    result = frac << (exp - 23);
  } 
  else 
  {
    result = frac >> (23 - exp);
  }

  // normalized number에 대해 1<<exp를 더해준다. 
  result = result + (1 << exp);
  
  // 부호에 따라 결과값 부호를 바꾸어준다. 
  if (sign) {
    result = -result;
  }
  
  return result;

}
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
 */
unsigned floatScale2(unsigned uf) {
  unsigned expoMask =0x7f800000; //exponent부분만 남기는 마스크
  unsigned signMask = 0x80000000; //sign부분만 남기는 마스크
  int is_signed = 0;
  unsigned result;
  int uf_invert = ~uf;

  if (((uf & signMask)^signMask) == 0){
    is_signed = -1;
  }

  //입력값의 exponent가 255인 경우(inf or NaN) 혹은 입력 값이 0인 경우 그대로 반환한다.
  if ((((uf & expoMask)^expoMask) == 0) || (uf==0)) //앞선 expoMask의 계산결과 0이 나오면 111...11이란 뜻이다.
  {
    return uf;
  }

  // denormal number는 exponent가 0이고, 이 수식의 계산 결과 반드시 0이 나오면 exponent가 0이라는 뜻이다. 
  if (((uf_invert & expoMask)^expoMask) == 0)
  {
      result = uf<<1;
      if (is_signed<0){
        result = signMask | result;
      } //signed인 경우 부호를 추가해준다.
  }
  else{
    result = 0x00800000 + uf;
  }
  return result;
}
