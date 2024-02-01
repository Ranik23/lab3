#ifndef LAB3_1_SET_H
#define LAB3_1_SET_H

#include <splay_tree.h>

template<
    class _Key,
    class _Container = SplayTree<_Key>,
    class _Compare = std::less<_Key>
> class ISet {

    public:

        using value_compare = _Compare;
        using value_type = _Key;
        using size_type = size_t;
        using reference = _Key&;
        using node_type = _Key;
        using const_reference = const _Key&;

    private:

        size_type _size;
        _Container c;
        _Compare comp;

    public:
        
        ISet() : _size(0) {};
       
        void insert(const _Key& __x);
        
        template<class...Args>
        void emplace(Args&&... args);

        size_t size() const;

        bool empty() const {
            return _size == 0;
        }

        _Key max_size() const {
            return std::numeric_limits<_Key>::max();
        }

        bool contains(const _Key& x);

        size_t count() const {
            return _size;
        }

        void generate() {
            c.generateDotFile("current_splay_tree");
        }
};

#include "../tpp_files/set.tpp"

#endif
