#ifndef FLAT_SET_HXX
# define FLAT_SET_HXX

# include "flat_set.hh"

namespace std
{

    // CONSTRUCTORS

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline flat_set<Key, Compare, Allocator>::flat_set(const Compare& comp,
                      const Allocator& alloc)
      : elts_(std::vector<Key, Allocator>(alloc)), compare_(comp)
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

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline flat_set<Key, Compare, Allocator>::~flat_set()
    {
    }

    // ITERATORS
    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::iterator
    flat_set<Key, Compare, Allocator>::begin()
    {
        return elts_.begin();
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::const_iterator
    flat_set<Key, Compare, Allocator>::begin() const
    {
        return elts_.begin();
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::const_iterator
    flat_set<Key, Compare, Allocator>::cbegin() const
    {
        return elts_.cbegin();
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::iterator
    flat_set<Key, Compare, Allocator>::end()
    {
        return elts_.end();
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::const_iterator
    flat_set<Key, Compare, Allocator>::end() const
    {
        return elts_.end();
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::const_iterator
    flat_set<Key, Compare, Allocator>::cend() const
    {
        return elts_.cend();
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::reverse_iterator
    flat_set<Key, Compare, Allocator>::rbegin()
    {
        return elts_.rbegin();
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::const_reverse_iterator
    flat_set<Key, Compare, Allocator>::rbegin() const
    {
        return elts_.rbegin();
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::const_reverse_iterator
    flat_set<Key, Compare, Allocator>::crbegin() const
    {
        return elts_.crbegin();
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::reverse_iterator
    flat_set<Key, Compare, Allocator>::rend()
    {
        return elts_.rend();
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::const_reverse_iterator
    flat_set<Key, Compare, Allocator>::rend() const
    {
        return elts_.rend();
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::const_reverse_iterator
    flat_set<Key, Compare, Allocator>::crend() const
    {
        return elts_.crend();
    }

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
      typename std::vector<Key>::iterator low;
      low = std::lower_bound(elts_.begin(), elts_.end(), value);
      if (*low != value)
      {
        elts_.insert(low, value);
        return std::pair<typename vector<Key>::iterator, bool>(low, true);
      }
      return std::pair<typename vector<Key>::iterator, bool>(low, false);
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline pair<typename vector<Key>::iterator, bool>
        flat_set<Key, Compare, Allocator>::insert(Key&& value)
    {
      typename std::vector<Key>::iterator low;
      low = std::lower_bound(elts_.begin(), elts_.end(), value, compare_);
      if (*low != value)
      {
        elts_.insert(low, value);
        return std::pair<typename vector<Key>::iterator, bool>(low, true);
      }
      return std::pair<typename vector<Key>::iterator, bool>(low, false);
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::iterator
        flat_set<Key, Compare, Allocator>::insert(typename vector<Key>::iterator hint,
                                                  const Key& value)
    {
      if (find(value) != elts_.end())
        return elts_.end();
      elts_.insert(hint, value);
      if (is_sorted(elts_.begin(), elts_.end(), compare_))
        return hint;
      else
      {
        sort(elts_.begin(), elts_.end(), compare_);
        return find(value);
      }
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::iterator
      flat_set<Key, Compare, Allocator>::insert(typename vector<Key>::const_iterator hint,
                                                const Key& value)
    {
      if (find(value) != elts_.end())
        return elts_.end();
      elts_.insert(hint, value);
      if (is_sorted(elts_.begin(), elts_.end(), compare_))
        return hint;
      else
      {
        sort(elts_.begin(), elts_.end(), compare_);
        return find(value);
      }
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline auto
        flat_set<Key, Compare, Allocator>::insert(typename vector<Key>::const_iterator hint,
                                                   Key&& value) -> iterator
    {
      if (find(value) != elts_.end())
        return elts_.end();
      elts_.insert(hint, value);
      if (is_sorted(elts_.begin(), elts_.end(), compare_))
        return hint;
      else
      {
        sort(elts_.begin(), elts_.end(), compare_);
        return find(value);
      }
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    template<class InputIt>
    inline void flat_set<Key, Compare, Allocator>::insert(InputIt first,
                                                          InputIt last)
    {
      InputIt it = first;
      while (it != last)
      {
        insert(*it);
        it++;
      }
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline void
      flat_set<Key, Compare, Allocator>::insert(initializer_list<value_type> ilist)
    {
      for (auto it : ilist)
        insert(*it);
    }

/*
    template<typename Key,
         typename Compare,
         typename Allocator>
    template<class... Args>
    pair<iterator, bool> flat_set<Key, Compare, Allocator>::emplace(Args&&... args)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    template <class... Args>
    iterator flat_set<Key, Compare, Allocator>::emplace_hint(const_iterator hint, Args&&... args)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    void flat_set<Key, Compare, Allocator>::erase(iterator position)
    {
      elts_.erase(position);
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    iterator flat_set<Key, Compare, Allocator>::erase(const_iterator position)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    void flat_set<Key, Compare, Allocator>::erase(iterator first, iterator last)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    iterator flat_set<Key, Compare, Allocator>::erase(const_iterator first, const_iterator last)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    size_type flat_set<Key, Compare, Allocator>::erase(const key_type& key)
    {

    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    void flat_set<Key, Compare, Allocator>::swap( flat_set& other )
    {

    }
*/


}

#endif // !FLAT_SET_HXX
