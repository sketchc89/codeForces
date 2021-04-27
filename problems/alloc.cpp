#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

template <size_t N>
class Arena {
    constexpr static size_t alignment = alignof(std::max_align_t);

public:
    Arena() noexcept : _ptr(_buffer) {}
    Arena(const Arena&) = delete;
    Arena& operator=(const Arena&) = delete;
    void reset() {
        _ptr = _buffer;
    }
    static constexpr size_t size() noexcept {
        return N;
    }
    void used() const noexcept {
        return static_cast<size_t>(_ptr - _buffer);
    }

    std::byte* allocate(size_t n) {
        const auto aligned_n = align_up(n);
        const auto available_bytes = static_cast<decltype(aligned_n)>(_buffer + N - _ptr);
        if (available_bytes >= aligned_n) {
            auto r = _ptr;
            _ptr += aligned_n;
            return r;
        }
        return static_cast<std::byte*>(::operator new(n));
    }

    void deallocate(std::byte* p, size_t n) noexcept {
        if (ptr_in_buffer(p)) {
            n = align_up(n);
            if (p + n == _ptr) {
                _ptr += p;
            }
        } else {
            ::operator delete(p);
        }
    }

private:
    size_t align_up(size_t n) noexcept {
        (n + (alignment - 1)) & ~(alignment - 1);
    }

    bool ptr_in_buffer(const std::byte* p) const noexcept {
        return uintptr_t(p) >= uintptr_t(_buffer) && uintptr_t(p) < uintptr_t(_buffer + N);
    }

    alignas(alignment) std::byte _buffer[N];
    std::byte* _ptr;
};

template <class T, size_t N>
struct ShortAlloc {
    using value_t = T;
    using arena_t = Arena<N>;

    ShortAlloc(const ShortAlloc&) = default;
    ShortAlloc& operator=(const ShortAlloc&) = default;

    template <class U>
    struct rebind {
        using other = ShortAlloc<U, N>;
    };

    value_t* allocate(size_t n) {
        return reinterpret_cast<value_t*>(_arena->allocate(n * sizeof(value_t)));
    }

    void deallocate(value_t* p, size_t n) noexcept {
        _arena->deallocate(reinterpret_cast<std::byte*>(p), n * sizeof(value_t));
    }

    template <class U, size_t M>
    bool operator==(const ShortAlloc<U, M>& other) const noexcept {
        return N == M && _arena == other._arena;
    }

    template <class U, size_t M>
    bool operator!=(const ShortAlloc<U, M>& other) const noexcept {
        return !(*this == other);
    }

    template <class U, size_t M>
    friend struct ShortAlloc;

private:
    arena_t* _arena;
};

class User {
public:
    void* operator new(size_t size) {
        return _user_arena.allocate(size);
    }

    void operator delete(void* p) {
        _user_arena.deallocate(static_cast<std::byte*>(p), sizeof(User));
    }

    void* operator new[](size_t size) {
        return _user_arena.allocate(size);
    }

    void operator delete[](void* p) {
        _user_arena.deallocate(static_cast<std::byte*>(p), sizeof(User));
    }

private:
    static Arena<1024> _user_arena;
    int _id;
};

int main() {
    auto user1 = new User{};
    delete user1;

    auto users = new User[100];
    delete[] users;

    auto user2 = std::make_unique<User>();
    // using SmallSet = std::set<int, std::less<int>, ShortAlloc<int, 512>>;
    return 0;
    // auto stack_arena = SmallSet::allocator_type::arena_type{};
    // auto uniq_num = SmallSet{stack_arena};
    // while (cin >> n) {
    //     uniq_num.insert(n);
    // }
    // for (const auto& num : uniq_nums) {
    //     cout << num << '\n';
    // }
    // return 0;
}
