#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <functional>
#include <algorithm>

#include "Header.h"

using namespace std;
using namespace std::chrono;

template<typename T>
void Measure(const vector<int>& rnds)
{
	int sum = 0;
	auto start = steady_clock::now();
	for (size_t i = 0; i < rnds.size(); ++i)
	{
		T foobar{};
		sum += foobar.Calc(rnds[i]);
	}
	auto end = steady_clock::now();
	auto period = end - start;
	cout << sum / 10000 << " man yen / " << rnds.size() / 365 << " years" << endl;
	cout << duration_cast<microseconds>(period).count() << " usec." << endl;
	cout << endl;
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

	for (int i = 0; i < 3; ++i)
	{
		Measure<Hoge::CFoobar0>(rnds);
		Measure<Hoge::CFoobar1>(rnds);
		Measure<Hoge::CFoobar2>(rnds);
	}
}
