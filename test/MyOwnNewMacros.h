// CppUTest: Confilicts with operator new macros (STL!)
// https://cpputest.github.io/manual.html#memory_leak_detection

// include stl
#include <set>
#include <array>
#include <memory>

// cpputest MemoryLeakDetectorNewMacros
#include "CppUTest/MemoryLeakDetectorNewMacros.h"
