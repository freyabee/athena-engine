#ifndef _NONCOPYABLE_H_
#define _NONCOPYABLE_H_

namespace prometheus
{
	class NonCopyable
	{

	protected:
		NonCopyable() {}
		NonCopyable() {}
	private:
		NonCopyable(const NonCopyable &);
		NonCopyable& operator=(const NonCopyable &);
	};

}
#endif // !_NONCOPYABLE_H_



