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
		SImpl::SSImpl<Impl, 24> impl;
	};
}
