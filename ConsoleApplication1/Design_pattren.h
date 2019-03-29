#include<iostream>
using namespace std;

/***
***********************1.单例模式*******************************
1.一个类只允许创建唯一的对象
2.禁止在类的外部创建对象：私有化构造函数：private或protected
3.类的内部维护唯一对象：静态成员变量
4.提供访问单例对象的方法：静态成员函数，返回在类内部唯一构造的实例
-----------创建方式
1.饿汉式：单例对象无论用或不用，程序启动即创建。
2.懒汉式：单例对象在用的时候再创建，不用即销毁。
***/
//饿汉式
class Singleton{
private:
	Singleton(){};
	static Singleton* pSingleton;
public:
	static Singleton* GetSingleton(){
		return pSingleton;
	}
	int m_count = 1;
};
Singleton* Singleton::pSingleton = new Singleton();

//懒汉式
class Singleton1{
private:
	Singleton1(){};
	static Singleton1* pSingleton1;
public:
	static Singleton1* GetSingleton1(){
		if (pSingleton1 == NULL)
			pSingleton1 = new Singleton1();
		return pSingleton1;
	}
	static void DestorySingleton1(){
		if (pSingleton1 != NULL){
			delete pSingleton1;
			pSingleton1 = NULL;
		}
	}
	int m_count = 1;
};
Singleton1* Singleton1::pSingleton1 = NULL;

/***
***********************2.工厂模式*******************************
1.需要在工厂类中做判断，从而创造相应的产品，
2.当增加新产品时，需要修改工厂类。
***/
typedef enum
{
	T80 = 1,
	T99
}TankType;

class Tank
{
public:
	virtual void message() = 0;
};

class Tank80 :public Tank
{
public:
	void message()
	{
		cout << "Tank80" << endl;
	}
};

class Tank99 :public Tank
{
public:
	void message()
	{
		cout << "Tank99" << endl;
	}
};

class TankFactory
{
public:
	Tank* createTank(TankType type)
	{
		switch (type)
		{
		case 1:
			return new Tank80();
		case 2:
			return new Tank99();
		default:
			return NULL;
		}
	}
};

/***
***********************3.策略模式*************************
是指定义一系列的算法，把它们一个个封装起来，并且使它们可以互相替换。
使得算法可以独立于使用它的客户而变化，也就是说这些算法所完成的功能是一样的，
对外接口是一样的，只是各自现实上存在差异。
***/

/***
*********************4.适配器模式********************
将一个类的接口转换成客户希望的另一个接口，使得原本由于接口不兼容而不能一起工作的哪些类可以一起工作。
主要解决在软件系统中，常常要将一些"现存的对象"放到新的环境中，而新环境要求的接口是现对象不能满足的。
***/

/***
*********************5.原型模式********************
用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。
1).我们的对象类型不是开始就能确定的，而这个类型是在运行期确定的话，
那么我们通过这个类型的对象克隆出一个新的对象比较容易一些；
2).有的时候，我们需要一个对象在某个状态下的副本，此时，我们使用原型模式是最好的选择；
例如：一个对象，经过一段处理之后，其内部的状态发生了变化；
这个时候，我们需要一个这个状态的副本，如果直接new一个新的对象的话,但是它的状态是不对的，
此时，可以使用原型模式，将原来的对象拷贝一个出来，
这个对象就和之前的对象是完全一致的了；
3).当我们处理一些比较简单的对象时，并且对象之间的区别很小，
可能就几个属性不同而已，那么就可以使用原型模式来完成，省去了创建对象时的麻烦了；
4).有的时候，创建对象时，构造函数的参数很多，而自己又不完全的知道每个参数的意义，
就可以使用原型模式来创建一个新的对象，不必去理会创建的过程。
***/
class Clone
{
public:
	Clone()
	{
	}
	virtual ~Clone()
	{
	}
	virtual Clone* clone() = 0;
	virtual void show() = 0;
};

class Sheep :public Clone
{
public:
	Sheep(int id, string name) :Clone(), m_id(id), m_name(name)
	{
		cout << "Sheep() id add:" << &m_id << endl;
		cout << "Sheep() name add:" << &m_name << endl;
	}
	~Sheep()
	{
	}

	Sheep(const Sheep& obj)
	{
		this->m_id = obj.m_id;
		this->m_name = obj.m_name;
		cout << "Sheep(const Sheep& obj) id add:" << &m_id << endl;
		cout << "Sheep(const Sheep& obj) name add:" << &m_name << endl;
	}

	Clone* clone()
	{
		return new Sheep(*this);
	}
	void show()
	{
		cout << "id  :" << m_id << endl;
		cout << "name:" << m_name.data() << endl;
	}
private:
	int m_id;
	string m_name;
};
//
//int main()
//{
//	Clone* s1 = new Sheep(1, "abs");
//	s1->show();
//	Clone* s2 = s1->clone();
//	s2->show();
//	delete s1;
//	delete s2;
//	return 0;
//}

/***
***********************6.模板模式*************************
定义一个操作中的算法的骨架，而将一些步骤延迟到子类中。
模板方法使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。
多个子类有相同的方法，并且逻辑相同，细节有差异。
对重要，复杂的算法，将核心算法设计为模板方法，周边细节由子类实现，
重构时，经常使用的方法，将相同的代码抽象到父类，通过钩子函数约束行为。
关键代码：在抽象类实现通用接口，细节变化在子类实现。
***/
class Computer
{
public:
	void product()
	{
		installCpu();
		installRam();
		installGraphicsCard();
	}

protected:
	virtual void installCpu() = 0;
	virtual void installRam() = 0;
	virtual void installGraphicsCard() = 0;

};

class ComputerA :public Computer
{
protected:
	void installCpu() override
	{
		cout << "ComputerA install Inter Core i5" << endl;
	}

	void installRam() override
	{
		cout << "ComputerA install 2G Ram" << endl;
	}

	void installGraphicsCard() override
	{
		cout << "ComputerA install Gtx940 GraphicsCard" << endl;
	}
};

class ComputerB :public Computer
{
protected:
	void installCpu() override
	{
		cout << "ComputerB install Inter Core i7" << endl;
	}

	void installRam() override
	{
		cout << "ComputerB install 4G Ram" << endl;
	}

	void installGraphicsCard() override
	{
		cout << "ComputerB install Gtx960 GraphicsCard" << endl;
	}
};