#include<iostream>
using namespace std;

/***
***********************1.����ģʽ*******************************
1.һ����ֻ������Ψһ�Ķ���
2.��ֹ������ⲿ��������˽�л����캯����private��protected
3.����ڲ�ά��Ψһ���󣺾�̬��Ա����
4.�ṩ���ʵ�������ķ�������̬��Ա���������������ڲ�Ψһ�����ʵ��
-----------������ʽ
1.����ʽ���������������û��ã�����������������
2.����ʽ�������������õ�ʱ���ٴ��������ü����١�
***/
//����ʽ
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

//����ʽ
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
***********************2.����ģʽ*******************************
1.��Ҫ�ڹ����������жϣ��Ӷ�������Ӧ�Ĳ�Ʒ��
2.�������²�Ʒʱ����Ҫ�޸Ĺ����ࡣ
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
***********************3.����ģʽ*************************
��ָ����һϵ�е��㷨��������һ������װ����������ʹ���ǿ��Ի����滻��
ʹ���㷨���Զ�����ʹ�����Ŀͻ����仯��Ҳ����˵��Щ�㷨����ɵĹ�����һ���ģ�
����ӿ���һ���ģ�ֻ�Ǹ�����ʵ�ϴ��ڲ��졣
***/

/***
*********************4.������ģʽ********************
��һ����Ľӿ�ת���ɿͻ�ϣ������һ���ӿڣ�ʹ��ԭ�����ڽӿڲ����ݶ�����һ��������Щ�����һ������
��Ҫ��������ϵͳ�У�����Ҫ��һЩ"�ִ�Ķ���"�ŵ��µĻ����У����»���Ҫ��Ľӿ����ֶ���������ġ�
***/

/***
*********************5.ԭ��ģʽ********************
��ԭ��ʵ��ָ��������������࣬����ͨ��������Щԭ�ʹ����µĶ���
1).���ǵĶ������Ͳ��ǿ�ʼ����ȷ���ģ��������������������ȷ���Ļ���
��ô����ͨ��������͵Ķ����¡��һ���µĶ���Ƚ�����һЩ��
2).�е�ʱ��������Ҫһ��������ĳ��״̬�µĸ�������ʱ������ʹ��ԭ��ģʽ����õ�ѡ��
���磺һ�����󣬾���һ�δ���֮�����ڲ���״̬�����˱仯��
���ʱ��������Ҫһ�����״̬�ĸ��������ֱ��newһ���µĶ���Ļ�,��������״̬�ǲ��Եģ�
��ʱ������ʹ��ԭ��ģʽ����ԭ���Ķ��󿽱�һ��������
�������ͺ�֮ǰ�Ķ�������ȫһ�µ��ˣ�
3).�����Ǵ���һЩ�Ƚϼ򵥵Ķ���ʱ�����Ҷ���֮��������С��
���ܾͼ������Բ�ͬ���ѣ���ô�Ϳ���ʹ��ԭ��ģʽ����ɣ�ʡȥ�˴�������ʱ���鷳�ˣ�
4).�е�ʱ�򣬴�������ʱ�����캯���Ĳ����ܶ࣬���Լ��ֲ���ȫ��֪��ÿ�����������壬
�Ϳ���ʹ��ԭ��ģʽ������һ���µĶ��󣬲���ȥ��ᴴ���Ĺ��̡�
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
***********************6.ģ��ģʽ*************************
����һ�������е��㷨�ĹǼܣ�����һЩ�����ӳٵ������С�
ģ�巽��ʹ��������Բ��ı�һ���㷨�Ľṹ�����ض�����㷨��ĳЩ�ض����衣
�����������ͬ�ķ����������߼���ͬ��ϸ���в��졣
����Ҫ�����ӵ��㷨���������㷨���Ϊģ�巽�����ܱ�ϸ��������ʵ�֣�
�ع�ʱ������ʹ�õķ���������ͬ�Ĵ�����󵽸��࣬ͨ�����Ӻ���Լ����Ϊ��
�ؼ����룺�ڳ�����ʵ��ͨ�ýӿڣ�ϸ�ڱ仯������ʵ�֡�
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