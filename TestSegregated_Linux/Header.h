#include "Segregated.h"

namespace Hoge
{
	class CHoge
	{
	public:
		CHoge();
		~CHoge();
		int Func(int a) const;
	private:
		struct Impl;
		struct Layout { int a[2]; };
		Segregated::CSegregated<Impl, Layout> impl;
	};
}
