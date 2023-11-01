## Task Description
Floating-point numbers are stored in memory in a specific format, often using the IEEE 754 standard. 

**Your task is to write a C function that accepts a pointer to the first element of an array of length 32 (composed of 0s and 1s) and converts it into the corresponding single-precision floating-point number (float)**.

When a floating-point number is stored in 32 bits of memory, it is divided into three sections: the **Sign bit**, the **Exponent**, and the **Mantissa**.

![image](https://lh3.googleusercontent.com/pw/ADCreHfSLUerktKDC9GNRjmBJW5QkOWRSVpZthQTP_8b8faSFDWj3O6hBFveX6A9EJe8-oHXl0rXusoyDcuPNBoxR3gCiN531HxNCDW1we3W-ugPqpVmJls=w1200)

The first bit (at index 0) is called the sign bit, which represents the sign of this float. A value of 0 indicates that the float is positive, while a value of 1 indicates that the float is negative.

The next 8 bits (index 1 to index 8) are called the Exponent, representing the exponent part of this float.

The remaining bits (index 9 to index 31) are called the Mantissa, representing the decimal fraction part of this float.

The idea of converting these 32 bits to a float is to first convert the Exponent and Mantissa parts to decimal. Then, the following formula is used to calculate the floating-point number.

$$Float = (-1)\ ^{Sign\ bit} \times (1 + Mantissa) \times 2\ ^ {(Exponent - 127)} $$

When converting the Exponent and Mantissa from binary to decimal, it is important to consider the weight of each bit. In the Exponent part, **the bit at index 8 has the smallest weight, which is $2^0$, and the bit at index 1 has the largest weight, which is $2^7$**. In the Mantissa, **the bit at index 9 has the largest weight, which is $2^{-1}$, and the bit at index 31 has the smallest weight, which is $2^{-23}$**. The following displays the calculation results shown in the above diagram.

![image](https://lh3.googleusercontent.com/pw/ADCreHeSWLlEs2-Jg58aSqXI-tToQuwcKIEYLtOF8NJZyxYtKfKEeqPZa_OtfNG4yil1YH1AKQQ9oNKuX_MdxT2MsZy6Mc00T1ifhH92S80DD-hohC5PjhY=w800)

The `main.c` is as follows:
```c
#include<stdio.h>
#include"ConvertToFloat.h"
#define REG_SIZE 32
int main(){
  int *reg_ptr, reg[REG_SIZE];
  reg_ptr = reg;
  for (int i = 0; i < REG_SIZE; i++) scanf("%d", &(reg[i]));
  printf("%.6f\n", ConvertToFloat(reg_ptr));
  return 0;
}
```
You need to implement the function in `ConvertToFloat.c` as following:
```c
 float ConvertToFloat(int *reg){
   float result;
   // Your code
   return result;
 }
```

## Input Format
The input consists of a sequence composed of 32 elements representing the values of each bit in memory. Each element is separated by spaces and consists of either 0 or 1.
## Output Format
One floating-point number represented by these 32 bits and display it with six decimal places.
## Sample Input 1
```
1 1 0 0 0 0 0 0 1 1 0 0 0 1 0 0 0 0 1 1 0 1 0 0 1 0 0 0 0 1 0 1
```

## Sample Output 1
```
-6.131411
```
Explanation:

$Sign\ bit$ = 1 ==> negative

$Exponent$ = (10000001) in binary = (129) in decimal

$Mantissa$ = (10001000011010010000101) in binary = (0.5328527688980103) in decimal

$Result$ = $-1 * (1 + 0.5328527688980103)$ * $2^2$ = $-6.1314110755920412$ $\approx$ $-6.131411$




## Sample Input 2
```
0 1 0 0 0 0 0 0 0 1 0 0 1 0 0 1 0 0 0 0 1 1 1 1 1 1 0 1 1 0 1 1
```
## Sample Output 2
```
3.141593
```
Explanation:

$Sign\ bit$ = 0 ==> positive

$Exponent$ = (10000000) in binary = (128) in decimal

$Mantissa$ = (10010010000111111011011) in binary = (0.5707963705062866) in decimal


$Result$ = $1 * (1 + 0.5707963705062866)$ * $2^1$ = $3.1415927410125732$ $\approx$ $3.141593$


