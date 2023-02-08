# 关于 boost 库

[boost库说明](http://zh.highscore.de/cpp/boost/)

查看auto类型
样例：

```c++
#include<iostream>
#include<boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;

int main()
{
    auto i = 100;
    std::cout << type_id_with_cvr<decltype(i)>().pretty_name() << std::endl;

    return 0;
}

```
