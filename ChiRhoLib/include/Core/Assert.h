#pragma once

#include "Core/Base.h"
#include "Core/Logger.h"
#include <filesystem>

#ifdef CR_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define CR_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { VM##type##ERROR(msg, __VA_ARGS__); CR_DEBUG_BREAK(); } }
	#define CR_INTERNAL_ASSERT_WITH_MSG(type, check, ...) CR_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define CR_INTERNAL_ASSERT_NO_MSG(type, check) CR_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", CR_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define CR_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define CR_INTERNAL_ASSERT_GET_MACRO(...) CR_EXPAND_MACRO( CR_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, CR_INTERNAL_ASSERT_WITH_MSG, CR_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define CR_ASSERT(...) CR_EXPAND_MACRO( CR_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define CR_CORE_ASSERT(...) CR_EXPAND_MACRO( CR_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define CR_ASSERT(...)
	#define CR_CORE_ASSERT(...)
#endif