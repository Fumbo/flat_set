#ifndef FLAT_SET_HXX
# define FLAT_SET_HXX

# include "flat_set.hh"

namespace std {


    // CONSTRUCTORS

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline flat_set<Key, Compare, Allocator>::flat_set(const Compare& comp,
                      const Allocator& alloc)
      : elts_(std::vector<Key, Allocator>()), compare_(comp)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline flat_set<Key, Compare, Allocator>::flat_set( const Allocator& alloc )
      : elts_(std::vector<Key, Allocator>())
    {

    }

    template<typename Key,
             typename Compare,
             typename Allocator>
    template<class InputIt>
    inline flat_set<Key, Compare, Allocator>::flat_set(InputIt first, InputIt last,
         const Compare& comp,
         const Allocator& alloc)
        : elts_(std::vector<Key, Allocator>(first, last)), compare_(comp)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline flat_set<Key, Compare, Allocator>::flat_set(const flat_set& other )
      : elts_(std::vector<Key, Allocator>(other.elts_, std::allocator_traits<allocator_type>::select_on_copy_construction(other))), compare_(other.compare_)
    {
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline flat_set<Key, Compare, Allocator>::flat_set(const flat_set& other,
        const Allocator& alloc)
      : elts_(std::vector<Key, Allocator>(other.elts_, alloc)), compare_(other.compare_)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline flat_set<Key, Compare, Allocator>::flat_set(flat_set&& other)
      : elts_(std::vector<Key, Allocator>(other.elts_, std::allocator_traits<allocator_type>::select_on_copy_construction(other))), compare_(other.compare_)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline flat_set<Key, Compare, Allocator>::flat_set(flat_set&& other,
        const Allocator& alloc)
      : elts_(std::vector<Key, Allocator>(other.elts_, alloc)), compare_(other.compare_)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline flat_set<Key, Compare, Allocator>::flat_set(initializer_list<value_type> init,
         const Compare& comp,
         const Allocator& alloc)
        : elts_(std::vector<Key, Allocator>(init)), compare_(comp)
    {

    }
/*
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
*/
 template<typename Key,
         typename Compare,
         typename Allocator>
   inline bool flat_set<Key, Compare, Allocator>::empty() const
    {
      return elts_.empty();
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline size_t flat_set<Key, Compare, Allocator>::size() const
    {
      return elts_.size();
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline size_t flat_set<Key, Compare, Allocator>::max_size() const
    {
      return elts_.max_size();
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline void flat_set<Key, Compare, Allocator>::clear()
    {
      elts_.clear();
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline pair<typename vector<Key>::iterator, bool>
        flat_set<Key, Compare, Allocator>::insert(const Key& value)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline pair<typename vector<Key>::iterator, bool>
        flat_set<Key, Compare, Allocator>::insert(Key&& value)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::iterator
        flat_set<Key, Compare, Allocator>::insert(typename vector<Key>::iterator hint,
                                                  const Key& value)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::iterator
      flat_set<Key, Compare, Allocator>::insert(typename vector<Key>::const_iterator hint,
                                                const Key& value)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::iterator
         flat_set<Key, Compare, Allocator>::insert(typename vector<Key>::const_iterator hint,
                                                   Key&& value)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    template<class InputIt>
    inline void flat_set<Key, Compare, Allocator>::insert(InputIt first,
                                                          InputIt last)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline void
      flat_set<Key, Compare, Allocator>::insert(initializer_list<value_type> ilist)
    {

    }




}

#endif // !FLAT_SET_HXX
