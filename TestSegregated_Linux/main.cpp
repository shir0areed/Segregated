#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <functional>
#include <algorithm>

#include "Header.h"

template<typename T>
void Measure()
{
	using namespace std;
	using namespace std::chrono;

	mt19937 rnd;
	constexpr size_t size = 10000000;
	vector<int> rnds(size);
	for (size_t i = 0; i < size; ++i)
		rnds[i] = static_cast<int>(rnd() % 12);

	int sum = 0;
	auto start = steady_clock::now();
	for (size_t i = 0; i < size; ++i)
	{
		T foobar{};
		sum += foobar.Calc(rnds[i]);
	}
	auto end = steady_clock::now();
	auto period = end - start;
	cout << sum / 10000 << " man yen / " << size / 365 << " years" << endl;
	cout << duration_cast<microseconds>(period).count() << " usec." << endl;
	cout << endl;
}

int main()
{
	using namespace std;

	//CHoge hoge;
	//printf("%d\n", hoge.Func(23));

	Measure<Hoge::CFoobar0>();
	Measure<Hoge::CFoobar1>();
	Measure<Hoge::CFoobar2>();
}
