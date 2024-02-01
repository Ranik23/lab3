#include "../include/set.h"

#define ISET_TEMPLATE template<class _Key, class _Container, class _Compare>

ISET_TEMPLATE
void ISet<_Key, _Container, _Compare>::insert(const _Key& x) {
    c.insert(x);
    _size += 1;
}

ISET_TEMPLATE
template<class...Args>
void ISet<_Key, _Container, _Compare>::emplace(Args&&... args) {
    c.insert(*(new _Key(std::forward<Args>(args)...)));
    _size += 1;
}

ISET_TEMPLATE
size_t ISet<_Key, _Container, _Compare>::size() const {
    return _size;
}

ISET_TEMPLATE
bool ISet<_Key, _Container, _Compare>::contains(const _Key& x) {
    return c.find(x);
}
