#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t SZ>
class RingAllocator {
public:
    static_assert(SZ & (SZ - 1) == 0, "Size must be multiple of two");
    using value_type = T;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    RingAllocator() noexcept : _buffer{}, _front{_buffer.data()} {}

    RingAllocator(const RingAllocator&) noexcept = default;

    template <typename U>
    RingAllocator(const RingAllocator<U>&) noexcept = default;

    ~RingAllocator() noexcept = default;

    size_type max_size() const noexcept;

    pointer allocate(size_t count) {
        auto p = _allocate(count * sizeof(value_type));
        return static_cast<pointer>(p);
    }

    void deallocate(pointer, size_type) {}  // no op
    void construct(pointer, const value_type&);
    void destroy(pointer);
    template <class U>
    struct rebind {
        RingAllocator<U, SZ> other;
    };


private:
    void* _allocate(const size_t size) noexcept {
        lock_guard<mutex> lock(_mtx);
        uint8_t* p = _front;
        _front += size;
        const bool wrapsAround = _front >= &_buffer.data() + SZ;
        if (wrapsAround) {
            p = &_buffer.data();
            _front = p + size;
        }
        return static_cast<void*>(p);
    }

    mutex _mtx;
    array<uint8_t, SZ> _buffer;
    uint8_t* _front;
};

int main() {
    vector<uint8_t, RingAllocator<uint8_t, 128>> vec;
    return 0;
}
