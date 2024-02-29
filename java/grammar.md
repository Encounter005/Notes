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

## 数组

### 创建数组

```java
        /*
        *   NOTE: 创建数组
        *   dataType[] array
        *   dataType[] array = new dataType[size]
        * */
        Integer[] arr = {1 , 2 , 3 , 4 , 5};
        Integer[] arr2 = new Integer[100];

```

### 遍历数组及访问数组

```java
        // NOTE: 遍历数组
        for(int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
        // NOTE: 范围遍历 for_each
        for(Integer value : arr) {
            System.out.println(value);
        }
```

### 数组作为函数参数

```java
    public static void printArray(Integer[] arr) {
        for(Integer value : arr) {
            System.out.println(value);
        }
    }
    printArray(new Integer[]{10 , 20 , 30 , 40});
```

### 数组作为返回值

```java
    public static Integer[] reverse(Integer[] arr) {
        Integer[] res = new Integer[arr.length];
        for(int i = 0, j = arr.length - 1; i < arr.length; i++ , j--) {
            res[i] = arr[j];
        }
        return res;
    }
    printArray(reverse(arr));
```

### 多维数组

```java
        /*
        *  NOTE: type[][] typeName = new type[length][length]
        * */

        String[][] arr = new String[20][30];

```

### Arrays类

> 包含了排序、查找、打印等内容

要先`import java.util.Arrays`

1. 打印数组

```java
        int [] a = {1 , 2 , 3,  4,  5};
        System.out.println(a);
        System.out.println(Arrays.toString(a)); // 打印数组元素的值

```

2. 升序排序

```java
        int [] b = {2 , 56  ,12893 ,12 , 23 ,3  , 5 , 67123};
        System.out.println(Arrays.toString(b)); // 打印数组元素的值
        Arrays.sort(b);
        System.out.println(Arrays.toString(b)); // 打印数组元素的值

```

3. 数组元素是引用类型的排序

```java
import java.util.Arrays;

class Man implements Comparable{
    int age , id;
    String name;
    public Man(int age , String name) {
        super(); // 父类型特征，先初始化父类型特征，再初始化子类
        this.age = age;
        this.name = name;
    }

    public int compareTo(Object o) {
        Man man = (Man) o;
        if(this.age < man.age) {
            return -1;
        } else if(this.age > man.age) {
            return 1;
        } else {
            return 0;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Man[] msMans = {new Man(3, "a"), new Man(60, "b"),new Man(2, "c")};
        Arrays.sort(msMans);
        System.out.println(Arrays.toString(msMans));
    }
}

```

```java
        Integer[] arr = {10 , 20 , 30 , 40 , 50 , 60 , 70};
        int x = Arrays.binarySearch(arr , 30);
        System.out.println(x);

```

5. 填充数组

```java
        int[] a = {1,2,323,23,543,12,59};
        System.out.println(Arrays.toString(a));
        Arrays.fill(a , 10);
        System.out.println(Arrays.toString(a));
```

## 方法


1. 定义

```java
修饰符 返回值类型 方法名(参数类型 参数名){
    ...
    方法体
    ...
    return 返回值;
}
```

2. 可变参数

```java
    public static void print(double... args) {
        if(args.length == 0) {
            System.out.println("No argument passed");
        }

        for(double val : args) {
            System.out.print(val + ' ');
        }
        System.out.println();
    }
    public static void main(String[] args) {
        print(10.1 , 2.1 , 3.2);
    }
```

3. finalize()方法 (弃用)

> 这种方法在对象被垃圾收集器析构前调用，用来清除回收对象

在finalize()方法里，必须指定在对象销毁时候要执行的操作  
一般格式是
```java
protected void finalize() {
    // NOTE: terminate your code
}
```
实例
```java
    class Cake extends Object{
        private int id;
        public Cake(int id) {
            this.id = id;
            System.out.println("Cake Object " + id + "is created");
        }

        protected void finalize() throws java.lang.Throwable {
            super.finalize();
            System.out.println("Cake Object " + id + "is disposed");
        }
    }
    public static void main(String[] args) {
        Cake c1 = new Cake(1);
        Cake c2 = new Cake(2);
        Cake c3 = new Cake(3);

        c2 = c3 = null;
        System.gc();
    }
```
