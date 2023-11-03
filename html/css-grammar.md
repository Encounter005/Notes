# css

<!--toc:start-->

- [css](#css)
  - [语法](#语法)
  - [引入方式](#引入方式)
  - [选择器](#选择器)
  - [字体属性](#字体属性)
  <!--toc:end-->

## 语法

CSS规则有主要两个部分构成：选择器，以及一条或多条声明

`object {property: value; property: value}`

```html
<body>
  <style>
    h1 {
      color: blue;
      font-size: 30px;
    }
  </style>
  <h1>nihao</h1>
</body>
```

## 引入方式

外部引入

`<link rel="stylesheet" href="./style.css">`

## 选择器

全局选择器

```css
* {
  margin: 0;
  padding: 0;
}
```

**元素选择器**

HTML中的文档元素`p b div a img body`

> 注意
> 所有的标签，都可以是选择器。比如ul li label dt dl input div
> 无论这个标签藏得有多深，都可以被选择上
> 选择的所有，只有一个

**类选择器**

规定用原点`.`来定义，针对你想要的所有标签使用

```css
.oneclass {
  width: 800px;
  color: blue;
}
```

```html
<h3 class="oneclass">awjdlkawjdkl</h3>
```

**特点**

1. 类选择器可以多种标签使用
2. 类名不能以数字开头
3. 同一个标签可以使用多个类选择器，用空格隔开

`<h3 class="awd awdjklawdjklwa"> q3weruio3qhrq </h3>`

**ID选择器**

针对某一特定的标签来使用，只能使用一次，`css`中的id选择器用`#`来定义

```css
* {
  font-size: 14px;
}

#test {
  color: blue;
  font-size: 30px;
}
```

```html
<p>djwakd</p>
<p id="test">awjdklawdjkawlwdjkal</p>
```

**注意**

> ID是唯一的
> ID不能以数字开头

**合并选择器**

作用：提取共同的样式，减少重复代码

```css
.header,
.footer {
  height: 30px;
}
```

**选择器优先级**

css中选择器用数字衡量

| 选择器         | 权重 |
| -------------- | ---- |
| 元素选择器     | 1    |
| class选择器    | 10   |
| id选择器       | 100  |
| 内联样式选择器 | 1000 |

> 优先级从高到低

## 字体属性

CSS字体属性定义字体、颜色、大小、加粗等

color font-size

```css
p {
  font-size: 12px;
  color: rgb(255, 120, 0);
  color: rgba(255, 0, 255, 0.6);
  color: red;
  color: #fff;
}
```

font-weight

> 设置文本的粗细

| 值      | 描述                                       |
| ------- | ------------------------------------------ |
| bold    | 定义粗体字符                               |
| bolder  | 定义更粗的字符                             |
| lighter | 定义更细的字符                             |
| 100-900 | 定义由细到粗 400 等同默认，而700等同于bold |

font-style

> 指定文本的样式

| 值     | 描述       |
| ------ | ---------- |
| normal | 默认值     |
| italic | 定义斜体字 |

font-family

> font-family属性指定一个元素的字体

**注意**

> 每个值要用逗号隔开
> 如果字体名称包含空格，必须加上引号

```css
p {
  font-size: 40px;
  font-weight: 900;
  font-style: italic;
  font-family: "Impact";
}
```

## 背景属性

CSS的背景属性主要有以下几个

| 属性                | 描述                 |
| ------------------- | -------------------- |
| background-color    | 设置背景颜色         |
| background-image    | 设置背景图片         |
| background-position | 设置背景图片显示位置 |
| background-repeat   | 设置背景图片如何填充 |
| background-size     | 设置背景图片大小属性 |

```css
.box {
  width: 400px;
  height: 400px;
  background-color: blueviolet;
  background-image: url("img/1.jpg");
  background-size: auto;
}
```

```html
<div class="box"></div>
```

background-repeat

> 该属性设置如何平铺背景图像

| 值        | 描述             |
| --------- | ---------------- |
| repeat    | 默认值           |
| repeat-x  | 只向水平方向平铺 |
| repeat-y  | 只向垂直方向平铺 |
| no-repeat | 不平铺           |

background-size

> 该属性设置背景图像大小

| 值         | 描述                                                                                     |
| ---------- | ---------------------------------------------------------------------------------------- |
| length     | 设置背景图片的宽度和高度，第一个值是宽度，第二个值是高度，如果只是设置一个，第二值`auto` |
| percentage | 计算相对位置区域的百分比，第一个值宽度，第二个值高度，如果只是设置一个，第二值`auto`     |
| cover      | 保持图平纵横比并将图片完全覆盖背景区域的最小大小                                         |
| contain    | 保持图平纵横比并将图片缩放成适合背景定位区域的最大大小                                   |
