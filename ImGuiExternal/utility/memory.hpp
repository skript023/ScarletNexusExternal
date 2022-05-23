#pragma once
#include "memory/process.hpp"

namespace ellohim::memory
{
	
    inline uintptr_t readPointer(uintptr_t addr, std::vector<uint32_t> offsets)
	{
        auto ptr = g_process->read<uintptr_t>(addr);

        if (!ptr) return NULL;

        auto level = offsets.size();

        for (auto i = 0; i < level; i++)
        {
            if (i == level - 1)
            {
                ptr += offsets[i];
                if (!ptr) return NULL;
                return ptr;
            }
            else
            {
                ptr = g_process->read<uintptr_t>(ptr + offsets[i]);
                if (!ptr) return NULL;
            }
        }
        return ptr;
	}

    template<typename T>
    T read(uintptr_t addr, std::vector<uint32_t> offsets = {})
    {
        return g_process->read<T>(readPointer(addr, offsets));
    }

    template<typename T>
    void write(uintptr_t addr, std::vector<uint32_t> offsets, T value)
    {
        g_process->write(readPointer(addr, offsets), value);
    }
}