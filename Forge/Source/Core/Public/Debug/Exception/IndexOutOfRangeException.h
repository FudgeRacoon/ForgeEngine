#ifndef INDEX_OUT_OF_RANGE_EXCEPTION_H
#define INDEX_OUT_OF_RANGE_EXCEPTION_H

#include "Exception.h"

namespace Forge {
	namespace Debug
	{
		class IndexOutOfRangeException : public Exception
		{
		public:
			IndexOutOfRangeException(PCCHAR line, PCCHAR func, PCCHAR file)
				: Exception(line, func, file, "Index is out of range of the array") {}

			IndexOutOfRangeException(PCCHAR line, PCCHAR func, PCCHAR file, PCCHAR add_info)
				: Exception(line, func, file, "Index is out of range of the array", add_info) {}
		};
	}
}

#endif // INDEX_OUT_OF_RANGE_EXCEPTION_H
