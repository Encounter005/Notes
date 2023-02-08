# c++ setprecision用法详解
> 浮点值可以四舍五入到若干位有效数或精度，这是出现在小数点前后的总位数。可以通过使用 setprecision 操作符来控制显示浮点数值的有效数的数量。



```c++
#include <iostream>
#include <iomanip> // Header file needed to use setprecision
using namespace std;
int main()
{
    double number1 = 132.364, number2 = 26.91;
    double quotient = number1 / number2;
    cout << quotient << endl;
    cout << setprecision(5) << quotient << endl;
    cout << setprecision(4) << quotient << endl;
    cout << setprecision(3) << quotient << endl;
    cout << setprecision(2) << quotient << endl;
    cout << setprecision(1) << quotient << endl;
    return 0;
}
```
> result
```
4.91877
4.9188
4.919
4.92
4.9
5

```

## attention
请注意，与 setw 不同的是，setprecision 不计算小数点。例如，当使用 setprecision(5) 时，输出包含 5 位有效数，但是需要 6 个位置来显示 4.9188。


如果一个数字的值可以由少于 setprecision 指定的精度位数来表示，则操作符将不起作用。在以下语句中，dollars 的值只有 4 位数字，所以 2 个 cout 语句显示的数字都是 24.51
```
double dollars = 24.51;
cout << dollars << endl;  // 显示 24.51
cout << setprecision (5) << dollars << endl; // 显示 24.51
```

|数字|操作符|显示的值|
|:----|:------:|-------:|
|28.92786|setprecision(3)|28.9|
|21.40|setprecision(5)|21.4|
|109.50|setprecision(4)|109.5|
|34.78596|setprecision(2)|35|
