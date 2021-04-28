#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <functional>
#include <algorithm>
#include <thread>

#include "Header.h"

using namespace std;
using namespace std::chrono;

template<typename T>
int64_t Exec(const vector<int>& rnds, int wage)
{
	int64_t sum = 0;
	T foobar{ wage };
	for (size_t i = 0; i < rnds.size(); ++i)
	{
		sum += foobar.Calc(rnds[i]);
	}
	return sum;
}

void Measure(const vector<int>& rnds, int wage, int64_t* ret, int64_t Exec(const vector<int>& rnds, int wage))
{
	auto start = steady_clock::now();
	auto sum = Exec(rnds, wage);
	auto end = steady_clock::now();
	auto period = end - start;
	cout << sum / 10000 << " man yen / " << rnds.size() / 365 << " years" << endl;
	*ret = duration_cast<microseconds>(period).count();
}

int main()
{
	//CHoge hoge;
	//printf("%d\n", hoge.Func(23));

	mt19937 rnd;
	constexpr size_t size = 10000000;
	vector<int> rnds(size);
	for (size_t i = 0; i < rnds.size(); ++i)
		rnds[i] = static_cast<int>(rnd() % 12);

	const auto wage = static_cast<int>(rnd() % 5000);

	for (int i = 0; i < 3; ++i)
	{
		int64_t measure0 = 0;
		int64_t measure1 = 0;
		int64_t measure2 = 0;
		auto th0 = thread{ Measure, rnds, wage, &measure0, Exec<Hoge::CFoobar0> };
		auto th1 = thread{ Measure, rnds, wage, &measure1, Exec<Hoge::CFoobar1> };
		auto th2 = thread{ Measure, rnds, wage, &measure2, Exec<Hoge::CFoobar2> };
		th0.join();
		th1.join();
		th2.join();
		cout << measure0 << " usec." << endl;
		cout << measure1 << " usec." << endl;
		cout << measure2 << " usec." << endl;
		cout << endl;
	}
}
