#include "Core/Public/Debug/Exception/Exception.h"

#include <sstream>

namespace Forge {
	namespace Debug
	{
		Exception::Exception(PCCHAR line, PCCHAR func, PCCHAR file, PCCHAR desc)
			: m_line(line), m_func(func), m_file(file)
		{
			m_additional_info = nullptr;

			std::stringstream ss;
			ss << "Typename" << ": "<< desc << " in '" << func << "' at '" << file << "' (line " << line << ").";
			
			Memory::MemoryCopy(m_description, const_cast<PCHAR>(ss.str().c_str()), ss.str().size());
		}
		Exception::Exception(PCCHAR line, PCCHAR func, PCCHAR file, PCCHAR desc, PCCHAR add_info)
			: m_line(line), m_file(file), m_func(func)
		{
			m_additional_info = add_info;

			std::stringstream ss;
			ss << "Typename" << ": " << desc << " in '" << func << "' at '" << file << "' (line " << line << "). " << m_additional_info << ".";

			Memory::MemoryCopy(m_description, const_cast<PCHAR>(ss.str().c_str()), ss.str().size());
		}
	}
}