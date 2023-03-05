#include <iostream>
#include <string>


using namespace std;


//��Ա�����ͳ�Ա�����ֿ��洢
//��C++�У����ڵĳ�Ա�����ͳ�Ա�����ֿ��洢
//ֻ�зǾ�̬��Ա������������Ķ�����

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
	//�ն���ռ�õ��ڴ�ռ�Ϊ�� 1���ֽ�
	//C++���������ÿ���ն������һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	cout << "size of p" << sizeof(p) << endl;
}

void test02()
{
	Person p;
	//�����в��գ��зǾ�̬�ĳ�Ա�������ͷ���Ǿ�̬��Ա�������ֽڿռ�
	//�Ǿ�̬��Ա����������Ķ���
	cout << "size of p:" << sizeof(p) << endl;
}


//this ָ�����
//C++ͨ���ṩ�������ָ�룬thisָ�룬ָ�򱻵��õĳ�Ա���������Ķ���
//thisָ��������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��
//thisָ�벻��Ҫ���壬ֱ��ʹ�ü���

//thisָ�����;
//���βκͳ�Ա����ͬ��ʱ������thisָ��������
//����ķǾ�̬��Ա�����з��ض�������ʹ��return *this

class Student
{
public:
	Student(int age)
	{
		//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
		this->age = age;//�����ʹ��thisָ�룬�����������
	}
	int age;
	//����ֵ������  Student  ,  Student&
	//����ֵ��Studentʱ��ֻ�Ƿ�����һ������������ԭ���Ķ�����
	//����ֵ��Student&�����صľ���������󣬺���ĸ��Ļ�ʹԭ�������ı�
	Student& sAdda(Student& p)//
	{
		this->age += p.age;
		return *this;
	}
};

void test03()
{
	Student p(12);
	cout << "p1��������" << p.age << endl;
}

void test04()
{
	Student p1(10);

	Student p2(12);
	//��ʽ���˼��
	p2.sAdda(p1).sAdda(p1);
	cout << "p2������" << p2.age << endl;
}

//��ָ����ʳ�Ա����
//C++�п�ָ��Ҳ�ǿ��Ե��ó�Ա�����ģ�����Ҫע����û���õ�thisָ��
//����õ�thisָ�룬��Ҫ�����жϱ�֤����Ľ�׳��

class Men
{
public:
	void showClassName()
	{
		cout << "this is Men Class" << endl;
	}

	void showPersonAge()
	{
		cout << "age = " << m_Age << endl;//�൱��this->m_Age
	}
	int m_Age;
};

void test05()
{
	Men* p = NULL;//����һ����ָ�� 
	p->showClassName();
	//p->showPersonAge();//��һ�е��û������Ϊ��ָ��û�������Ա����
	cout << sizeof(*p) << endl;//��Ȼ���ܵ���m_Age��������Ȼ�������ĸ��ֽڵĿռ�
}


//const���γ�Ա����
//����������Ա�������const�����ǳ��������Ϊ������
//�������ڲ������޸ĳ�Ա����
//��Ա��������ʱ�ӹؼ���mutable���ڳ���������Ȼ�����޸�

class Teacher
{
public:
	 
	//thisָ��ı��� ��ָ�볣�� ָ���ָ���ǲ������޸ĵ�
	//�ڳ�Ա���������const,�����������ε�thisָ�룬��thisָ��ָ�����ֵ�������޸�
	void showTeacher() const//��const���Ϊ���������������ڲ������޸ĳ�Ա����
	{
		this->m_B = 100;//����mutable���ڳ�������Ҳ���޸�
		//this->m_A = 100;
	}
	void func()
	{

	}
	int m_A;
	mutable int m_B;//�����������ʹ�ڳ�������Ҳ�����޸����ֵ
};

//��������������ǰ��const�Ƹö���Ϊ������
//������ֻ�ܵ��ó�����

void test06()
{
	const Teacher p;//�ڶ���ǰ��const��Ϊ������
	//p.m_A = 100;//�������������޸ĳ�Ա������ֵ
	p.m_B = 100;//����mutable��Ϳ��Խ����޸���
	//������ֻ�ܵ��ó�����
	//p.func();//����������ֻ�ܵ��ó�����,�����Ե�����ͨ��Ա��������Ϊ��ͨ��Ա���������޸ĳ�Ա������ֵ

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