#ifndef SIMPL_SIMPL_H
#define SIMPL_SIMPL_H
#include <cstddef>

namespace Segregated
{
	template<typename T, size_t size>
	struct SSImpl
	{
		char buf[size]{};

		SSImpl();
		SSImpl(const SSImpl&);
		SSImpl& operator =(const SSImpl&);
		SSImpl(SSImpl&&);
		SSImpl& operator =(SSImpl&&);

		template<typename... Args>
		explicit SSImpl(Args&&... args);

		T* get() noexcept;
		const T* get() const noexcept { return const_cast<SSImpl*>(this)->get(); }
		T* operator -> () noexcept { return get(); }
		const T* operator -> () const noexcept { return get(); }
		T& operator * () noexcept { return *get(); }
		const T& operator * () const noexcept { return *get(); }

		~SSImpl();
	};
}
#endif
