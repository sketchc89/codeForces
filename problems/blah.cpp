#include <bits/stdc++.h>
using namespace std;

void* aligned_malloc2(size_t align, size_t size = sizeof(max_align_t)) {
    return nullptr;
}

/* aligned malloc will allocate space requested plus space to store offset and extra space to meet alignment
 */
void* aligned_malloc(size_t n) {
    if (n == 0) {
        return nullptr;
    }

    int offset = sizeof(max_align_t) - 1;
    void* ptr = nullptr;  // pointer to data
    void* p = malloc(n + sizeof(uintptr_t) + offset);
    if (p != nullptr) {
        ptr = reinterpret_cast<void*>((reinterpret_cast<size_t>(p) + offset) & ~offset);
        // store the offset from malloc to data in first byte, sizeof(ptrdiff_t) behind data
        *(reinterpret_cast<uintptr_t*>(p) - 1) =
                static_cast<uintptr_t>(reinterpret_cast<uintptr_t*>(ptr) - reinterpret_cast<uintptr_t*>(p));
        // reinterpret_cast<ptrdiff_t>(reinterpret_cast<uintptr_t>(ptr) - reinterpret_cast<uintptr_t>(p));
    }
    return ptr;
}

void aligned_free(void* ptr) {
    assert(ptr);
    auto offset = *(reinterpret_cast<uintptr_t*>(ptr) - 1);
    void* p = reinterpret_cast<void*>(reinterpret_cast<uintptr_t*>(ptr) - offset);
    free(p);
}


int main() {
    auto a = aligned_malloc(1);
    auto b = aligned_malloc(2);
    auto c = aligned_malloc(3);
    auto d = aligned_malloc(4);
    auto e = aligned_malloc(5);
    auto f = aligned_malloc(6);
    auto g = aligned_malloc(7);
    auto h = aligned_malloc(8);
    auto i = aligned_malloc(9);
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\t' << e << '\t';
    cout << f << '\t' << g << '\t' << h << '\t' << i << '\n';
    aligned_free(a);
    aligned_free(b);
    return 0;
}
