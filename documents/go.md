# 环境准备



## 编译器

安装完编译器后在命令行输入`go env`，能找到`GOROOT`则表示安装成功。





## 编译go程序



**一个程序必须得声明一个主包**

```go
//hello.go

package main

import "fmt"

func main(){
    fmt.Println("Hello Go")
}
```



**编译go程序：**

找到代码所在目录，然后执行：

```go
go build [-o 程序名]
```

*go build会去找目录里.go文件的主包，然后去编译*



编译+执行：

```go
go run hello.go
```





## GoLand配置

**GOROOT**位置：`/usr/local/go`

 





# 基本语法



## 变量

```go
// 一般写法
var x = 100
var y int8 = 200

//简写形式
z := 300 //相当于 var z = 300

//多个赋值
var x,y,z = 10,20,30

//匿名变量(接收函数返回值的时候用)
var x, _ = foo()
```





## 基本数据类型



**1.整型**



**2.浮点型**

`float32`， `float64`



**3.布尔类型**

只有`true`和`false`两种值



**4.字符串类型**

单个字符用单引号

字符串用双引号



(1)基本操作

```go
s := "hello yuan"
c1 := 'a'

//1.索引操作
a := s[2]

//2.切片操作(和python一样,左闭右开)
b := s[6:]	//缺省写法
c := s[:5]	//缺省写法 

//3.字符串拼接
name1 := "rain"
name2 := "alvin"
name := name1 + name2
```



(2)strings包操作

```go
package main
import "strings"

// 1.字符串转大写
s := "hello yuan"
new_string := strings.ToUpper(s)
fmt.Println(new_string)

// 2.是否以xxx开头,结尾,包含
name := "张三"
flag := strings.HasPrefix(name,"张")
flag := strings.HasSuffix(name,"张")
flag := strings.Contains(name,"张")

// 3.去除字符串两端匹配的内容
username := "     Watson    "
new_name := strings.Trim(username," ")

// 4.索引函数
s2 := "rain alvin eric"
fmt.Println(strings.Index(s2,"alvin"))

// 5.分割字符串
citys := "北京 上海 深圳 广州"
ret := strings.Split(citys," ")
fmt.Println(len(ret)) //打印切片的长度

// 6.拼接字符串
ret2 := strings.join(ret,";")	//用分号把切片里的内容拼接起来
```





**类型转换**

```go
// 数字转换
var x int8
x = 100
var y = 200
fmt.Println(int(x) + y)

//字符串转数字
var a = "1"
var b = "2"
value, _ := strconv.Atoi(a)

//数字转字符串
var height = 182
ret := strconv.Itoa(height)

//浮点型字符串转float
v2, _ := strconv.ParseFloat("3.14",64) //参数:要转换的字符串,转换后的数据类型
```







## if语法

```go
var age = 12
if age > 18 {
  //语句1
} else if age < 10 {
  //语句2
} else {
  //语句3
}
```





## switch语法

go语言的switch语句不用加break

```go
choice := 2
switch choice{
case 1:
	//语句1
case 2,3,4,5:
  //语句2
default:
  //非法输入
} 
```



## for循环

**语法：**

`for condition {`
  `//循环体代码`
`}`

```go
var count = 1
for count <= 100{
  fmt.Println(count)
  count++
}
```

```go
for count:=0;count<100;count++{
  //循环语句体
}
```



**退出循环：**

```go
for count:=0;count<100;count++{
  if count == 88{
    continue 	//跳过88
  }
  if count == 95{
    break 		//退出循环
  }
}
```





# 高级数据类型



## 【1】指针类型

```go
var x int
x = 100

var p *int
p = &x	//指针p保存地址
v := *p	//解引用取值 
```



**new函数**

```go
var p *int = new(int)	//开辟一个空间 
*p = 100
```





## 【2】数组

**1.声明数组**

```go
var 数组名 [元素数量]元素类型
```

```go
//先声明
var names[3]string
//再赋值
var[0] = "张三"
var[1] = "李四"
var[2] = "王五"


//声明+赋值
var stuAges = [3]int{22,23,24}

//省略长度
arr := [...]int{1,2,3,4,5,6,7}
```





**2.数组遍历**

```go
//for range
for i,v := range names{	//i代表索引, v代表元素值
  fmt.Println(i,names[i])
}
```





## 【3】切片

切片是一个**动态数组**



**切片的构建方式**

1.对数组切片得到一个切片



2.直接声明切片

```go
var s = []int{1,2,3,4,5}
```





**make函数**

```go
var y = make([]int,3,6)	//开辟切片，长度为3，容量为6
```



### **append(追加)**

原有切片后追加值

```go
var emps = make([]string,3,5)	//开辟切片，长度为3，容量为5
emps[0] = "张三"
emps[1] = "李四"
emps[2] = "王五"

emp2 := append(emp1,"赵六")
```





### 插入













