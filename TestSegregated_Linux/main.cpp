#include <iostream>
#include <random>
#include <array>

#include "Header.h"

int main()
{
	using namespace std;
	using namespace Hoge;

	//CHoge hoge;
	//printf("%d\n", hoge.Func(23));

	mt19937 rnd;
	constexpr size_t size = 100;
	array<int, size> rnds{};
	for (size_t i = 0; i < size; ++i)
		rnds[i] = static_cast<int>(rnd() % 12);

	for (size_t i = 0; i < size; ++i)
	{
		CFoobar0 foobar;
		cout << foobar.Calc(rnds[i]) << endl;
	}
}
