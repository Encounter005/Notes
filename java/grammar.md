# The grammar of java

## 数据类型

byte:

- 数据类型是8位

short:

- 数据类型是16位

int:

- 数据类型是32位

long:

- 数据类型是64位

float:

- 单精度浮点数

double:

- 双精度浮点数

boolean:

- 存储bool量

char:

- 存储任何字符

## Number & Math类

### Number子类

> Java为每一个数据类型都封装了对应的包装类

| 包装类    | 基本数据类型 |
| --------- | ------------ |
| Booleans  | boolean      |
| Byte      | byte         |
| Short     | short        |
| Integer   | int          |
| Long      | long         |
| Character | char         |
| Float     | float        |
| Double    | double       |

```java
public class Main {
    public static void main(String[] args) {
        Integer x = 5;
        System.out.println(x);
    }
}
```

一些基本方法

| 名称        | 描述                                 |
| ----------- | ------------------------------------ |
| xxxValue()  | 将Number对象转换为xxx数据类型并返回  |
| compareTo() | 将Number对象与参数比较               |
| equals()    | 判断Number对象是否与参数相等         |
| valueOf()   | 返回一个Number对象指定的内置数据类型 |
| toString()  | 以字符串形式返回值                   |
| paraseInt() | 将字符串解析为int类型                |

用法

paraseInt()

```java
public class Main {
    public static void main(String[] args) {
        String re = "10.0";
        double x = Double.parseDouble(re);
        System.out.println(x);
    }
}
```

### Math类

> Math类包含了基本的数学运算
> Math类的方法都被定义为`static`形式，可以在主函数直接调用

```java
public class Main {
    public static void main(String[] args) {
        System.out.println("The sin value of 90 degree is: " + Math.sin(Math.PI / 2.0));
        System.out.println("The cos value of 0 degree is: " + Math.cos(0));
        System.out.println("The tan value of 60 degree is: " + Math.tan(Math.PI / 3.0));
        System.out.println("The degree of PI / 2 is: " + Math.toDegrees(Math.PI / 2));
    }
}
```

基本方法

| 名称     | 描述                                     |
| -------- | ---------------------------------------- |
| abs()    | 返回参数的绝对值                         |
| ceil()   | 返回向上取整的给定参数的整数             |
| floor()  | 返回向下取整的给定参数的整数             |
| rint()   | 返回与参数最接近的整数，返回类型为double |
| round()  | 表示四舍五入 Math.floor(x + 0.5)         |
| min()    | 返回两个参数中的最小值                   |
| max()    | 返回两个参数中的最大值                   |
| pow()    | 返回第一个参数的第二个参数的次方         |
| sqrt()   | 返回参数的算术平方根                     |
| random() | 返回一个随机数                           |

## Character类

```java
public class Main {
    public static void main(String[] args) {
        //NOTE: 定义一个字符串数组
        char[] test = {'h' , 'e' , 'l' , 'l' , 'o'};
        for(char ch : test) {
            System.out.print(ch);
        }
        System.out.println();
        char ch = 'h';
        System.out.println(ch);
        //NOTE: Character字符串数组
        Character[] test_2 = {'h' , 'e' , 'l' , 'l' , 'o'};
        System.out.println(test_2[1]);
    }
}
```

基本方法

| 方法           | 说明                                  |
| -------------- | ------------------------------------- |
| isLetter()     | 是否是一个字母                        |
| isDigit()      | 是否是一个数字字符                    |
| isWhiteSpace() | 是否是一个空白字符                    |
| isUpperCase()  | 是否是大写字母                        |
| isLowerCase()  | 是否是小写字母                        |
| toString()     | 返回字符的字符串形式，字符串的长度为1 |

## String类

> Java提供了String类来创建和操作字符串

字符串创建

```java
        //NOTE: 创建字符串
        String tmp = "noob";
        String tmp2 = new String("awdawd");
        System.out.println(tmp);
        System.out.println(tmp2);
        //NOTE: 用字符串数组创建字符串
        char[] hello = {'h' , 'e' , 'l' , 'l' , 'o'};
        String tmp3 = new String(hello);
        System.out.println(tmp3);
        String tmp4 = tmp2; // NOTE: 这种创建方式是引用

```

求字符串长度

> length()

```java
        //NOTE: 求字符串长度
        String world = "world";
        System.out.println(world.length());

```

连接字符串

> concat(String) 返回一个连接好字符串

```java
        //NOTE: 连接字符串
        String s1 = "hello, " , s2 = "world!";
        String s3 = s1.concat(s2);
        System.out.println(s3);

```

创建格式化字符串

String类使用静态方法format()返回一个String对象而不是PrintStream对象
String类的静态方法format()能用来创建可复用的格式化字符串

```java
        //NOTE: 创建格式化字符串
        String fs;
        fs = String.format("float is: " + "%f , int is: " + "%d , String is: " + "%s" , 10.1 , 12 , s3);
        System.out.println(fs);
```

基本方法

| 名称                                           | 描述                                                                           |
| ---------------------------------------------- | ------------------------------------------------------------------------------ |
| char charAt(int index)                         | 返回指定索引处的char值                                                         |
| int compareTo(String anotherString)            | 按字典序比较两个字符串                                                         |
| int compareToIgnoreCase(String str)            | 按字典序比较两个字符串(忽略大小写)                                             |
| boolean contentEquals(StringBuffer sb)         | 当且仅当字符串与指定的StringBuffer有相同顺序的字符时候返回真。                 |
| int indexOf(String str)                        | 返回指定子字符串在此字符串中第一次出现处的索引。                               |
| int indexOf(String str , int from index)       | 返回指定子字符串在此字符串中第一次出现处的索引，从指定的索引开始。             |
| int lastIndexOf(int ch)                        | 返回指定字符在此字符串中最后一次出现处的索引。                                 |
| int lastIndexOf(int ch, int fromIndex)         | 返回指定字符在此字符串中最后一次出现处的索引，从指定的索引处开始进行反向搜索。 |
| int lastIndexOf(String str)                    | 返回指定子字符串在此字符串中最右边出现处的索引。                               |
| int lastIndexOf(String str, int fromIndex)     | 返回指定子字符串在此字符串中最后一次出现处的索引，从指定的索引开始反向搜索。   |
| String toUpperCase()                           | 使用默认语言环境的规则将此 String 中的所有字符都转换为大写。                   |
| String toLowerCase()                           | 使用默认语言环境的规则将此 String 中的所有字符都转换为小写。                   |
| char[] toCharArray()                           | 将此字符串转换为一个新的字符数组。                                             |
| String substring(int beginIndex, int endIndex) | 返回一个新字符串，它是此字符串的一个子字符串。                                 |
| String substring(int beginIndex)               | 返回一个新的字符串，它是此字符串的一个子字符串。                               |


## StringBuffer & String Builder类

> 在使用 StringBuffer 类时，每次都会对 StringBuffer 对象本身进行操作，而不是生成新的对象，所以如果需要对字符串进行修改推荐使用 StringBuffer。
> 在不要求线程安全的情况下，使用String Builder类，String Builder会比StringBuffer快。


```java
        // NOTE: 先创建一个大小为10的空字符串
        StringBuilder sb = new StringBuilder(10);
        System.out.println(sb);
        // NOTE: 从尾部填充字符串
        sb.append("Runoob..");
        System.out.println(sb);
        sb.append("!");
        System.out.println(sb);
        // NOTE: 从指定索引处开始填充字符串，不足部分会扩容
        sb.insert(8 , "java");
        System.out.println(sb);
        // NOTE: 删除指定区间的字符串
        sb.delete(5 , 8);
        System.out.println(sb);
```
