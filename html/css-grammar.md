# css

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
.oneclass{
    width: 800px;
    color: blue;
}
```

```html
<h3 class="oneclass">awjdlkawjdkl</h3>
```

特点  

1. 类选择器可以多种标签使用
2. 类名不能以数字开头
3. 同一个标签可以使用多个类选择器，用空格隔开

`<h3 class="awd awdjklawdjklwa"> q3weruio3qhrq </h3>`

