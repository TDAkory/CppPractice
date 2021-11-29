//
// Created by zhaojieyi on 2021/11/29.
//
#ifndef MEM_DETECTOR_MEM_DETECTOR_H
#define MEM_DETECTOR_MEM_DETECTOR_H

#include <stddef.h>

// 重载版本: operator new/new[]( ), operator delete/delete[]( ) 的声明
void* operator new( size_t size, char* file, size_t line );
void* operator new[]( size_t size, char* file, size_t line );

void operator delete(void *ptr);
void operator delete[](void *ptr);

#ifndef NEW_OVERLOAD_IMPLEMENTATION_
#define new new(__FILE__, __LINE__)
#endif

class LeakDetector {
public:
    static size_t call_count_;

    LeakDetector() { call_count_++; }
    ~LeakDetector() {
        if (0 == --call_count_) {
            _LeakDetector();
        }
    }

private:
    static void _LeakDetector();
};

static LeakDetector exitCounter;

#endif //MEM_DETECTOR_MEM_DETECTOR_H
