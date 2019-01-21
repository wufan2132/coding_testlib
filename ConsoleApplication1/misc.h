#pragma once
#include <unordered_map>

class misc
{
public:
	misc();
	~misc();
#pragma region 쳲���������
	static std::unordered_map<int, int> m;
	static int last1, last2;
	//������ʽ
	static int Fibonacci(int N){
		int i, last, NextTolast, Answer;
		if (N <= 1)
			return 1;
		last = NextTolast = 1;
		for (i = 2; i < N; i++)
		{
			Answer = last + NextTolast;
			NextTolast = last;
			last = Answer;
		}
		return Answer;
	}
	//�ݹ鷽ʽ��ʹ��hashset���ٶ���ĵݹ�
	static int Fib_opti(int N){
		if (N <= 1)
		{
			return m[N] = 1;
		}
		else
		{
			int n_1, n_2;
			if (m.count(N - 1))
				n_1 = m[N - 1];
			else
				n_1 = Fib_opti(N - 1);
			if (m.count(N - 2))
				n_2 = m[N - 2];
			else
				n_2 = Fib_opti(N - 2);
			return m[N] = n_1 + n_2;
		}
	}
	//��ͨ�ݹ鷽ʽ
	static int Fib(int N){
		if (N <= 1)
		{
			return 1;
		}
		else
		{
			return Fib(N - 1) + Fib(N - 2);
		}
	}

	//���÷��ι�ʽ
	static int Fib_divide(int N)
	{
		if (N <= 1) return m[N] = 1;
		static int n_1, n_2, n_3, n_4;
		if (m.count(N / 2))
			n_1 = m[N / 2];
		else
			n_1 = Fib_divide(N / 2);
		if (m.count(N - N / 2))
			n_2 = m[N - N / 2];
		else
			n_2 = Fib_opti(N - N / 2);
		if (m.count(N / 2 - 1))
			n_3 = m[N / 2 - 1];
		else
			n_3 = Fib_divide(N / 2 - 1);
		if (m.count(N - N / 2 - 1))
			n_4 = m[N - N / 2 - 1];
		else
			n_4 = Fib_opti(N - N / 2 - 1);
		return m[N] = n_1 * n_2 + n_3 * n_4;
	}
#pragma endregion

#pragma region NumberOf1Between1AndN_Solution
public:
int NumberOf1Between1AndN_Solution(int n)
{
	if (n == 0) return 0;
	int sum = 0;
	int zeronum = 0;
	int tennum = 1;
	while (n >= tennum){
		int bitnum = (n % (tennum * 10) - n % (tennum)) / tennum;
		if (bitnum == 0){
			int yushu = n % tennum;
			int zhengshu = n / (tennum * 10) * tennum -1;
			sum += zhengshu + yushu + 1;
		}
		else if (bitnum == 1){
			int yushu = n % tennum;
			int zhengshu = n / (tennum * 10) * tennum;
			sum += zhengshu + yushu + 1;
		}
		else {
			int zhengshu = n / (tennum * 10) * tennum;
			sum += zhengshu + tennum;
		}
		zeronum++;
		tennum *= 10;
	}
	return sum;
}
#pragma endregion

#pragma region isPrime_number

#pragma endregion


//��ֻ����������2��3��5��������������Ugly Number��
#pragma region GetUglyNumber_Solution
public:
	int GetUglyNumber_Solution(int index) {

	}
#pragma endregion

};



//int N = 2000;
//clock_t start = clock();
////misc::Fib(N);
//clock_t ends = clock();
//cout << "Running Time1 : " << (double)(ends - start) / CLOCKS_PER_SEC << endl;
//start = clock();
//misc::Fibonacci(N);
//ends = clock();
//cout << "Running Time2 : " << (double)(ends - start) / CLOCKS_PER_SEC << endl;
//start = clock();
//misc::Fib_opti(N);
//ends = clock();
//cout << "Running Time3 : " << (double)(ends - start) / CLOCKS_PER_SEC << endl;