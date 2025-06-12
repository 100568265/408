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





## 第三方包

**GOROOT**位置：`/usr/local/go`



 **go mod：**`go mod`命令生成一个go.mod文件管理项目的依赖。

**1.初始化项目**

```shell
go mod init 项目名
```

**2.下载包**

在代码里`import`需要的第三方包，然后执行`go mod tidy`自动下载缺失的包







# 基本语法



## 变量&常量

**变量**

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



**常量**

一般用法

```go
const a int = 10
```

枚举

```go
//const来定义枚举类型
const (
    //可以在const()添加一个关键字 iota，每行的iota都会累加1，第一行的iota默认是0
    BEIJING = iota	//0
    SHANGHAI		//1
    SHENZHEN		//2
)
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

**原有切片后追加值**

```go
var emps = make([]string,3,5)	//开辟切片，长度为3，容量为5
emps[0] = "张三"
emps[1] = "李四"
emps[2] = "王五"

emp2 := append(emp1,"赵六")
```



**首位置添加一个值**

```go
var s = []int{1, 2, 3, 4, 5}
ret := append([]int{100}, s...)	//用 ... 	把 切片s 打散
fmt.Println(ret)
```





### append(插入)

任意位置添加一个值或切片

```go
//在2和3之间插入1000
var s = []int{1, 2, 3, 4, 5}
temp := append([]int{1000}, s[2:]...)
s2 := append(s[:2], temp...)
fmt.Println(s2)
```





### append(删除)

```go
//删除索引为2的数据
var s = []int{100,200,300,400,500}
ret := append(s[:2],s[3:]...)
fmt.Println(ret)
```







## 【4】map



**map的声明和初始化**

`var map名称 map[键类型]类型`

```go
//声明再初始化
var stu map[string]string
stu["name"] = "yuan"
stu["age"] = "18"

//声明并初始化
var stu2 = map[string]string{"name":"yuan","age":"18"}
```

**map的基本操作**

```go
//查看键值
stu["name"]
for key,val := range stu{
    fmt.Println(key,val) //打印键值对
}

//删除键值
delete(stu,"age")

//添加&更新键值对
stu["weight"] = "70kg"
```





**map的进阶使用**

如果把每个map看成一个对象，如果要把多个对象管理保存起来，可以使用容器将每个map对象存起来。

```go
//切片嵌套map
var stu01 = map[string]string{"name":"张三","age":"23","gender":"male"}
var stu02 = map[string]string{"name":"李四","age":"30","gender":"female"}
var stu03 = map[string]string{"name":"王五","age":"28","gender":"male"}

var students []map[string]string{stu01,stu02,stu03}		//切片嵌套map

//找到第二个学生的名字
students[1]["name"]
```

```go
//map嵌套map
var stu01 = map[string]string{"name":"张三","age":"23","gender":"male"}
var stu02 = map[string]string{"name":"李四","age":"30","gender":"female"}
var stu03 = map[string]string{"name":"王五","age":"28","gender":"male"}

var students = map[int]map[string]string{1001:stu01,1002:stu02,1003:stu03}

//查询学号为1002的学生的姓名
fmt.Println(students[1002]["name"])
```

```go
//map嵌套切片
var stu01 = map[string]interface{}{"name":"张三","age":23,"gender":"male","hobby":[]string{"抽烟","喝酒","烫头"}}
var students = []map[string]interface{}{stu01}	//这是一个切片，数据类型是map[string]interface{}
```





# 函数

`func add(参数名 参数类型) 返回值类型{`
    `//函数逻辑`
    `return 返回值`
`}`

```go
func add(x,y int) int{
    return x+y
}
```





## 作用域&全局变量

**全局变量：**函数外面的就是全局变量

```go
var x = 100

func main(){
    //...
}
```





## 可变长参数

```go
func add(nums ...int){
    ret := 0
    for_,num := range nums{
        ret += num
    }
    fmt.Println(ret)
}
```





## 多返回值

返回多个值的时候需要把**返回值类型**用括号括起来

```go
//函数声明
func query()(string,int){
    return "zjs",28
}

//函数调用
name,age := query()
```





## 返回值命名

函数定义时可以给返回值命名，并在函数体中直接使用这些变量，最后通过`return`关键字返回。

```go
func calc(x,y int)(sum,sub int){
    sum = x + y
    sub = x - y
    return			//相当于return sum, sub
}
```







# 文件操作

磁盘只能存储`二进制`。

因此，写文件的时候需要编码，读文件的时候需要解码。

go语言默认编码是`UTF-8`



go语言中，`byte`数据类型就是`uint8`

```go
var s byte
s = 'a'
fmt.Println(s)				//97
fmt.Println(string(s))		//a
```





## 读文件

**获取文件句柄**

```go
import "os"

func main(){
    file,err := os.Open("文件名.txt")
    if err != nil{
        fmt.Println("err:",err)
    }
    fmt.Println(file)
}
```



**按照字节读**

```go
func readBytes(file *os.File) {
	data := make([]byte, 1024)
	file.Read(data)
	fmt.Println(data)
}
```



**按照行读字符串**

```go
func readByLine(file *os.File) {
	reader := bufio.NewReader(file)
	for true {
		line, err := reader.ReadString('\n')	//读取字符串，以换行符为终点
		if err == io.EOF {
			break
		}
		fmt.Print(line)
	}
}
```





**读取整个文件**

```go
//打开文件+读文件
func readFile(){
    data,_ := os.ReadFile("text.txt")
    fmt.Println(string(data))
}
```





## 写文件



**打开文件**

```go
func main(){
    file,err := os.OpenFile("text.txt", os.O_WRONLY|os.O_CREATE|os.O_APPEND,0666)
    if err!= nil{
        fmt.Println("err:",err)
    }
}
```



**写字符串/字节串**

```go
func writeBytesOrStr(file *os.File){
    s := "怒发冲冠，凭栏处、潇潇雨歇。"
    file.Write([]byte(s))
    //file.WriteString(s)
}
```



**写文件**

```go
func writeFile(){
    data,_ := os.ReadFile("满江红2.txt")	//从文件读出数据
    os.WriteFile("满江红3",data,0666)		//将数据写入文件
}
```





## 序列化

**序列化：**通过某种方式把数据结构或对象写入到磁盘文件中或通过网络传到其他节点的过程。

**反序列化：**把磁盘中对象或者把网络节点中传输的数据恢复为数据对象的过程。



| go语言数据类型 | JSON支持的数据类型 |
| -------------- | ------------------ |
| 整型，浮点型   | 整型，浮点型       |
| 字符串         | 字符串             |
| 逻辑值         | 逻辑值             |
| 数组，切片     | 数组(方括号)       |
| map            | 对象(花括号)       |
| nil            | null               |



**JSON序列化：**

`json.Marshal`：将`go的数据类型`序列化成`字节数组`

```go
var stu01 = map[string]string{"name": "张三", "age": "23", "gender": "male"}
var stu02 = map[string]string{"name": "李四", "age": "30", "gender": "female"}
var stu03 = map[string]string{"name": "王五", "age": "28", "gender": "male"}

var stus = []map[string]string{stu01, stu02, stu03}	//将三个map对象放入到切片中

ret,_ := json.Marshal(stus)			//json序列化
fmt.Println(string(ret))
os.WriteFile("stus.json",ret,0666)	//写入到磁盘
```

**JSON反序列化：**

`json.Unmarshal`：将`字节数组`反序列化成`go的数据类型`

```go
ret,_ := os.ReadFile("stus.json")
var data []map[string]string
json.Unmarshal(ret,&data)	//把从文件中读取的ret反序列化成切片然后存入到data中
```







# 面向对象



## struct定义

结构体属于值类型



`type`关键字

```go
//声明一种新的数据类型 myint，是int的一个别名
type myint int
```



`struct`关键字

**定义一个结构体**

```go
type Book struct{
    title string
    author string
}
```

**实例化结构体-方法1**

```go
func main(){
    var book1 Book
    book1.title = "Golang"
    book1.author = "zjs"
}
```

**实例化结构体-方法2**

```go
func main(){
    var book2 = new(Book)
    book2.title = "Golang"
    book2.author = "zjs"
}
```

**实例化结构体-方法3**

```go
var book3 = &Book{}
book3.title = "Golang"
book3.author = "zjs"
```

**实例化结构体-方法4**

```go
var book4 = Book{
    title:"Golang",
    author:"zjs"
}
```





## struct方法

**给结构体定义方法**

```go
func (接收者变量 接收者类型) 方法名(参数列表)(返回值类型){
    
}
```



```go
type Person struct{
    Name string
    Age int
    Height int
}

func (p Person) PrintInfo(){
    fmt.Printf("姓名: %\v 年龄:%v\n",p.Name,p.Age)
}

//修改的时候必须使用结构体指针去修改结构体里的属性
func (p *Person) SetInfo(name string, age int){
    p.Name = name
    p.Age = age
}
```



**重点：**

- 如果方法对结构体进行写操作，接收者类型必须使用`指针`去访问

- 如果类的属性首字母大写，表示该属性是对外能够访问的，否则只能在结构体内部使用






## struct继承(嵌套)

```go
type Animal struct{
    Name string
    
}

type Dog struct{
    Age string
    Animal	//结构体嵌套，继承
}

func main(){
    var d = Dog{
        Age:20,
        Animal:Animal{
            Name:"阿奇"
        }
    }
}
```







## 接口

```go
type Usber interface{
    start()
    stop()
}

//如果接口里有方法，必须通过结构体实现这个接口
type Phone struct{
    Name string
}

func(p Phone) start(){
    //启动
}

func(p Phone) stop(){
    //关机
}

func main(){
    p := Phone{
        Name:"myphone"
    }
    p.start()
}
```





### **空接口**

表示没有任何约束，任意的类型都可以实现空接口。



空接口可以作为**函数的参数**，表示可以接收任意类型。

```go
func show(a interface{}){
    fmt.Printf("值:%v 类型:%T\n",a,a)
}
```



空接口可以作为**map的类型**

```go
var m1 = make(map[string]interface{})	//value为空接口类型
m1["username"] = "张三"
m1["age"] = 20
m1["married"] = true
```





空接口可以作为**切片的类型**

```go
var s1 = []interface{}{1,2,"你好",true}
```





### **类型断言**

**语法：**`v.(T)`

```go
func main(){
    var a interface{}
    a = "你好golang"
    v,ok := a.(string)
    if ok{
        fmt.Println("a是一个string类型,值为: ",a)
    }else{
        fmt.Println("断言失败,a不是string类型")
    }
}
```





**例：**定义一个方法，可以传入任意数据类型，根据不同类型实现不同的功能

```go
//x.(type)判断一个变量的类型，这个语句只能用在switch里面
func MyPrint(x interface{}){
    switch x.(type){
    case int:
        fmt.Println("int类型")
    case string:
        fmt.Println("string类型")
    case bool:
        fmt.Println("bool类型")
    default:
        fmt.Println("传入错误")
    }
}
```





# 协程

关键词`go`来创建并运行协程

函数`runtime.Goexit()`退出协程

```go
func newTask(){
    i := 0
    for{
        i++
        fmt.Printf("new Goroutine : i = %d\n",i)
        time.Sleep(1*time.Second)
    }
}

func main(){
    //子线程
    go newTask()
    
    //主线程
    i := 0
    for{
        i++
        fmt.Printf("main routine : i = %d\n",i)
        time.Sleep(1*time.Second)
    }
}
```

















































































