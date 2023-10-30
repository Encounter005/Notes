# html语法

<!--toc:start-->

- [html语法](#html语法)
  - [基础骨架](#基础骨架)
  - [标题](#标题)
  - [段落、换行、分割线](#段落换行分割线)
  - [图片](#图片)
  - [超文本链接](#超文本链接)
  - [文本标签](#文本标签)
  <!--toc:end-->

## 基础骨架

```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>nima</title>
  </head>

  <body></body>
</html>
```

## 标题

有1-6级标题`h1~h6`，关于位置有一个属性叫`align`

关于align的值:

- "left"
- "right"
- "center"

```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>nima</title>
  </head>

  <body>
    <h1 align="center">标题</h1>
  </body>
</html>
```

## 段落、换行、分割线

段落用`<p></p>`表示  
换行用`<br>`表示  
分割线用`<hr align="" width="" size="">`表示

关于分割线的几种属性

- align 只有`left`和`right`
- width 调整宽度
- size 调整大小

```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>nima</title>
  </head>

  <body>
    <h1 align="center">标题</h1>
    <p>我是一个段落</p>
    <p>我要成为境界<br />天火高手</p>
    <hr color="green" width="30" size="2px" align="right" />
    <h2 align="right">awda</h2>
    <p>新的一个段落</p>
  </body>
</html>
```

## 图片

图片使用`<img>`表示
`<img src="" alt="" title="" width="" height="">`

属性：

- src 路径
- alt 规定图像的替代文本
- width 规定图像的官渡
- height 规定图像的高度
- title 鼠标悬停在图片上的提示

```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Document</title>
  </head>
  <body>
    <img src="./img/123.jpg" alt="EMT" width="300px" title="EMT" />
    <br />
    <img src="./img/1.jpg" alt="chewan" width="100px" />
  </body>
</html>
```

## 超文本链接

超文本链接用`<a></a>`表示
`<a href="url"> 链接文本 </a>`

超文本链接可以是一个字、词、图片

```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Document</title>
  </head>
  <body>
    <a href="https://www.youtube.com">test</a>
    <br />
    <a href="https://www.pixiv.net/">
      <img src="./img/1.jpg" alt="" width="200px" />
    </a>
  </body>
</html>
```

## 文本标签

常用文本标签

| 标签       | 描述               |
| ---------- | ------------------ |
| `<em>`     | 定义着重文字       |
| `<b>`      | 定义粗体文字       |
| `<i>`      | 定义斜体文字       |
| `<strong>` | 定义加重语气       |
| `<del>`    | 定义删除字         |
| `<span>`   | 元素没有特定的含义 |

```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Document</title>
  </head>

  <body>
    <p>p baicai</p>
    <em>em baicai</em>
    <br />
    <i>i baicai</i>
    <br />
    <b>b baicai</b>
    <br />
    <del>del baicai</del>
    <br />
    <strong>strong baicai</strong>
    <br />
    <span>span baicai</span>
  </body>
</html>
```

## 列表

### 有序列表

有序列表是一列项目，列表项目使用数字进行标记。有序列表始于`<ol>`标签。每个列表始于`<li>`标签

type属性

> \<ol>的属性type

1. `1`表示用数字标号
2. `a`表示用小写字母标号
3. `A`表示用大写字母标号
4. `i`表示用小写罗马字母标号
5. `I`表示用大写罗马字母标号

```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Document</title>
  </head>

  <body>
    <ol type="i">
      <li>youtube</li>
      <li>pornhub</li>
      <li>corhub</li>
    </ol>

    <!-- 可以嵌套 -->
    <ol type="A">
      <li>youtube</li>
      <li>pornhub</li>
      <ol>
        <li>bilibli</li>
        <li>awdawd</li>
      </ol>
      <li>corhub</li>
    </ol>

    <ol type="a">
      <li>youtube</li>
      <li>pornhub</li>
      <li>corhub</li>
    </ol>
  </body>
</html>
```

### 无序列表

无序列表是一个项目的列表，词项目使用粗体原点进行标记

无序列表使用`<ul></ul>`标签

type属性

> \<ul>的属性type拥有的选项

- disc 默认实心圆
- circle 空心圆
- squre 小方块
- none 不显示

```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Document</title>
  </head>

  <body>
    <ul type="disc">
      <li>生活真好</li>
      <li>nima</li>
    </ul>
    <ul type="circle">
      <li>生活真好</li>
      <ul type="disc">
        <li>真不哈</li>
        <li>aaaaaa</li>
      </ul>
      <li>nima</li>
    </ul>
    <ul type="square">
      <li>生活真好</li>
      <li>nima</li>
    </ul>
    <ul type="none">
      <li>生活真好</li>
      <li>nima</li>
    </ul>
  </body>
</html>
```

## 表格

表格标签

- 表格 `<table>`
- 行 `<tr>`
- 单元格（列）`<td>`

属性

- border
- width
- height

```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Document</title>
  </head>

  <body>
    <table width="400px" height="300px">
      <tr>
        <td>单元格</td>
        <td>单元格</td>
        <td>单元格</td>
        <td>单元格</td>
      </tr>
      <tr>
        <td>单元格</td>
        <td>单元格</td>
        <td>单元格</td>
        <td>单元格</td>
      </tr>
      <tr>
        <td>单元格</td>
        <td>单元格</td>
        <td>单元格</td>
        <td>单元格</td>
      </tr>
    </table>
  </body>
</html>
```

合并单元格

- 水平合并：colspan
- 垂直合并：rowspan

