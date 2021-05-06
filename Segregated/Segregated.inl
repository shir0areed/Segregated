#ifndef SEGREGATED_SEGREGATED_INL
#define SEGREGATED_SEGREGATED_INL
#include "Segregated.h"

#include <new>
#include <utility>

template<typename TImpl, typename TLayout>
inline Segregated::CSegregated<TImpl, TLayout>::CSegregated()
{
	new(buf)TImpl;
}

template<typename TImpl, typename TLayout>
inline Segregated::CSegregated<TImpl, TLayout>::CSegregated(const CSegregated& a)
{
	new(buf)TImpl(*a.get());
}

template<typename TImpl, typename TLayout>
inline Segregated::CSegregated<TImpl, TLayout>& Segregated::CSegregated<TImpl, TLayout>::operator=(const CSegregated& a)
{
	*get() = *a.get();
	return *this;
}

template<typename TImpl, typename TLayout>
inline Segregated::CSegregated<TImpl, TLayout>::CSegregated(CSegregated&& a)
{
	new(buf)TImpl(std::move(*a.get()));
}

template<typename TImpl, typename TLayout>
inline Segregated::CSegregated<TImpl, TLayout>& Segregated::CSegregated<TImpl, TLayout>::operator=(CSegregated&& a)
{
	*get() = std::move(*a.get());
	return *this;
}

template<typename TImpl, typename TLayout>
template<typename... Args>
inline Segregated::CSegregated<TImpl, TLayout>::CSegregated(Args&&... args)
{
	new(buf)TImpl(std::forward<Args>(args)...);
}

template<typename TImpl, typename TLayout>
inline TImpl* Segregated::CSegregated<TImpl, TLayout>::get() noexcept
{
	return reinterpret_cast<TImpl*>(buf);
}

template<typename TImpl, typename TLayout>
inline Segregated::CSegregated<TImpl, TLayout>::~CSegregated()
{
	static_assert(sizeof(TLayout) == sizeof(TImpl), "size not match");
	static_assert(alignof(TLayout) == alignof(TImpl), "align not match");
	reinterpret_cast<TImpl*>(buf)->~TImpl();
}
#endif
