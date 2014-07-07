#ifndef FLAT_SET_HXX
# define FLAT_SET_HXX

# include <flat_set.hh>

namespace std {


    // CONSTRUCTORS
    explicit flat_set(const Compare& comp = Compare(),
                      const Allocator& alloc = Allocator())
    {

    }

    explicit flat_set( const Allocator& alloc )
    {

    }

    template<class InputIt>
    flat_set(InputIt first, InputIt last,
         const Compare& comp = Compare(),
         const Allocator& alloc = Allocator())
    {

    }

    flat_set(const flat_set& other )
    {

    }

    flat_set(const flat_set& other, const Allocator& alloc)
    {

    }

    flat_set(flat_set&& other)
    {

    }

    flat_set(flat_set&& other, const Allocator& alloc)
    {

    }

    flat_set(initializer_list<value_type> init,
         const Compare& comp = Compare(),
         const Allocator& alloc = Allocator())
    {

    }

    // ITERATORS
    inline iterator flat_set::begin()
    {

    }

    inline const_iterator flat_set::begin() const
    {

    }

    inline const_iterator flat_set::cbegin() const
    {
    }

    inline iterator flat_set::end()
    {

    }

    inline const_iterator flat_set::end() const
    {

    }

    inline const_iterator flat_set::cend() const
    {

    }

    inline reverse_iterator flat_set::rbegin()
    {

    }

    inline const_reverse_iterator flat_set::rbegin() const
    {

    }

    inline const_reverse_iterator flat_set::crbegin() const
    {

    }

    inline reverse_iterator flat_set::rend()
    {

    }

    inline const_reverse_iterator flat_set::rend() const
    {

    }

    inline const_reverse_iterator flat_set::crend() const
    {

    }

}

#endif // !FLAT_SET_HXX
