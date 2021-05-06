#include "Header.h"

#include "Segregated.inl"

#include <array>

namespace Hoge
{
	using namespace std;

	struct CHoge::Impl
	{
		Impl()
			: values{ 0, 8 }
		{

		}
		Impl(int v1, int v2)
			: values{ v1, v2 }
		{

		}
		~Impl()
		{

		}
		array<int, 2> values;
	};

	CHoge::CHoge()
		: impl{ 1800, 8 }
	{
	}

	CHoge::~CHoge() = default;

	int CHoge::Func(int a) const
	{
		//constexpr auto realSize = sizeof(CHoge::Impl);
		return a * impl->values[0] * impl->values[1];
	}
}
