#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Base.h"
#include "Logger.h"

#ifndef BIT
    #define BIT(x) (1<<x)
#endif

#ifdef CR_PLATFORM_WINDOWS
    #include <Windows.h>
#endif