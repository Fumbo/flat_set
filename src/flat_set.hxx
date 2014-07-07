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
    inline typename vector<Key>::iterator
         flat_set<Key, Compare, Allocator>::insert(typename vector<Key>::const_iterator hint,
                                                   Key&& value)
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

    /* LOOKUP */
    template<typename Key,
         typename Compare,
         typename Allocator>
    inline size_t flat_set<Key, Compare, Allocator>::count(const Key& key) const
    {
        if (find(key) != elts_.end())
            return 1;
        else
            return 0;
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::iterator
    flat_set<Key, Compare, Allocator>::find(const Key& key)
    {
        auto it = lower_bound(elts_.begin(), elts_.end(), key, compare_);
        if (*it == key)
            return it;
        else
            return elts_.end();
    }

    template<typename Key,
         typename Compare,
         typename Allocator>
    inline typename vector<Key>::const_iterator
    flat_set<Key, Compare, Allocator>::find(const Key& key) const
    {
        auto it = lower_bound(elts_.cbegin(), elts_.cend(), key, compare_);
        if (*it == key)
            return it;
        else
            return elts_.end();
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::equal_range(const K& key) -> pair<iterator, iterator>
    {
        auto it = find(key);
        if (it != elts_.begin())
            return pair<iterator, iterator>(it, it);
        else
            return pair<iterator, iterator>(elts_.end(), elts_.begin());
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::equal_range(const K& key) const -> pair<const_iterator, const_iterator>
    {
        auto it = find(key);
        if (it != elts_.begin())
            return pair<const_iterator, const_iterator>(it, it);
        else
            return pair<const_iterator, const_iterator>(elts_.end(), elts_.begin());
    }

    template<typename K, typename C, typename A>
    inline auto flat_set<K, C, A>::lower_bound(const K& key) -> iterator
    {
        return lower_bound(elts_.begin(), elts_.end(), key, compare_);
    }

    template<typename K, typename C, typename A>
    inline auto flat_set<K, C, A>::lower_bound(const K& key) const -> const_iterator
    {
        return lower_bound(elts_.cbegin(), elts_.cend(), key, compare_);
    }

    template<typename K, typename C, typename A>
    inline auto flat_set<K, C, A>::upper_bound(const K& key) -> iterator
    {
        return upper_bound(elts_.begin(), elts_.end(), key, compare_);
    }

    template<typename K, typename C, typename A>
    inline auto flat_set<K, C, A>::upper_bound(const K& key) const -> const_iterator
    {
        return upper_bound(elts_.cbegin(), elts_.cend(), key, compare_);
    }

}

#endif // !FLAT_SET_HXX
