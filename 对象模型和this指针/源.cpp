#include <iostream>
#include <string>


using namespace std;


//成员变量和成员函数分开存储
//在C++中，类内的成员变量和成员函数分开存储
//只有非静态成员变量才属于类的对象上

class Person
{
	int m_A;
	static int m_B;

	void func()
	{

	}
};
int Person::m_B = 10;
void test01()
{
	Person p;
	//空对象占用的内存空间为： 1个字节
	//C++编译器会给每个空对象分配一个字节空间，是为了区分空对象占内存的位置
	//每个空对象也应该有一个独一无二的内存地址
	cout << "size of p" << sizeof(p) << endl;
}

void test02()
{
	Person p;
	//对象中不空，有非静态的成员变量，就分配非静态成员变量的字节空间
	//非静态成员变量属于类的对象
	cout << "size of p:" << sizeof(p) << endl;
}


//this 指针概念
//C++通过提供特殊对象指针，this指针，指向被调用的成员函数所属的对象
//this指针是隐含每一个非静态成员函数内的一种指针
//this指针不需要定义，直接使用即可

//this指针的用途
//当形参和成员变量同名时，可用this指针来区分
//在类的非静态成员函数中返回对象本身，可使用return *this

class Student
{
public:
	Student(int age)
	{
		//this指针指向被调用的成员函数所属的对象
		this->age = age;//如果不使用this指针，编译器会混淆
	}
	int age;
	//返回值的类型  Student  ,  Student&
	//返回值是Student时，只是返回了一个拷贝，不是原来的对象了
	//返回值是Student&，返回的就是这个对象，后面的更改会使原对象发生改变
	Student& sAdda(Student& p)//
	{
		this->age += p.age;
		return *this;
	}
};

void test03()
{
	Student p(12);
	cout << "p1的年龄是" << p.age << endl;
}

void test04()
{
	Student p1(10);

	Student p2(12);
	//链式编程思想
	p2.sAdda(p1).sAdda(p1);
	cout << "p2的年零" << p2.age << endl;
}

//空指针访问成员函数
//C++中空指针也是可以调用成员函数的，但是要注意有没有用到this指针
//如果用到this指针，需要加以判断保证代码的健壮性

class Men
{
public:
	void showClassName()
	{
		cout << "this is Men Class" << endl;
	}

	void showPersonAge()
	{
		cout << "age = " << m_Age << endl;//相当于this->m_Age
	}
	int m_Age;
};

void test05()
{
	Men* p = NULL;//定义一个空指针 
	p->showClassName();
	//p->showPersonAge();//这一行调用会出错，因为空指针没有年龄成员变量
	cout << sizeof(*p) << endl;//虽然不能调用m_Age，但是仍然保留了四个字节的空间
}


//const修饰成员函数
//常函数：成员函数后加const后我们称这个函数为常函数
//常函数内不可以修改成员属性
//成员属性声明时加关键字mutable后，在常函数中依然可以修改

class Teacher
{
public:
	 
	//this指针的本质 是指针常量 指针的指向是不可以修改的
	//在成员函数后面加const,本质上是修饰的this指针，让this指针指向的数值不可以修改
	void showTeacher() const//加const后变为常函数，常函数内不可以修改成员属性
	{
		this->m_B = 100;//加上mutable，在常函数中也能修改
		//this->m_A = 100;
	}
	void func()
	{

	}
	int m_A;
	mutable int m_B;//特殊变量，即使在常函数中也可以修改这个值
};

//常对象：声明对象前加const称该对象为常对象
//常对象只能调用常函数

void test06()
{
	const Teacher p;//在对象前加const变为常对象
	//p.m_A = 100;//报错，常对象不能修改成员变量的值
	p.m_B = 100;//加上mutable后就可以进行修改了
	//常对象只能调用常函数
	//p.func();//报错，常对象只能调用常函数,不可以调用普通成员函数，因为普通成员函数可以修改成员变量的值

}

int main()
{
	//test01();
	//test03();
	//test04();
	test05();
	system("pause");
	return 0;
}