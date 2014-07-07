#ifndef FLAT_SET_HXX
# define FLAT_SET_HXX

# include "flat_set.hh"

namespace std
{

    // CONSTRUCTORS
    template<typename K, typename C, typename A>
    inline flat_set<K, C, A>::flat_set(const C& comp, const A& alloc)
      : elts_(std::vector<K, A>(alloc)), compare_(comp)
    {
    }

    template<typename K, typename C, typename A>
    inline flat_set<K, C, A>::flat_set( const A& alloc )
      : elts_(std::vector<K, A>())
    {
    }

    template<typename K, typename C, typename A>
    template<class InputIt>
    inline flat_set<K, C, A>::flat_set(InputIt first, InputIt last,
         const C& comp,
         const A& alloc)
        : elts_(std::vector<K, A>(first, last)), compare_(comp)
    {

    }

    template<typename K, typename C, typename A>
    inline flat_set<K, C, A>::flat_set(const flat_set& other )
      : elts_(std::vector<K, A>(other.elts_, std::allocator_traits<allocator_type>::select_on_copy_construction(other))), compare_(other.compare_)
    {
    }

    template<typename K, typename C, typename A>
    inline flat_set<K, C, A>::flat_set(const flat_set& other,
        const A& alloc)
      : elts_(std::vector<K, A>(other.elts_, alloc)), compare_(other.compare_)
    {
    }

    template<typename K, typename C, typename A>
    inline flat_set<K, C, A>::flat_set(flat_set&& other)
      : elts_(std::vector<K, A>(other.elts_, std::allocator_traits<allocator_type>::select_on_copy_construction(other))), compare_(other.compare_)
    {
    }

    template<typename K, typename C, typename A>
    inline flat_set<K, C, A>::flat_set(flat_set&& other, const A& alloc)
      : elts_(std::vector<K, A>(other.elts_, alloc)), compare_(other.compare_)
    {
    }

    template<typename K, typename C, typename A>
    inline flat_set<K, C, A>::flat_set(initializer_list<value_type> init, const C& comp,
                                       const A& alloc)
        : elts_(std::vector<K, A>(init)), compare_(comp)
    {

    }

    template<typename K, typename C, typename A>
    inline flat_set<K, C, A>::~flat_set()
    {
    }

    // ITERATORS
    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::begin() -> iterator
    {
        return elts_.begin();
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::begin() const -> const_iterator
    {
        return elts_.begin();
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::cbegin() const -> const_iterator
    {
        return elts_.cbegin();
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::end() -> iterator
    {
        return elts_.end();
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::end() const -> const_iterator
    {
        return elts_.end();
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::cend() const -> const_iterator
    {
        return elts_.cend();
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::rbegin() -> reverse_iterator
    {
        return elts_.rbegin();
    }

    template<typename K,
         typename C,
         typename A>
    inline auto
    flat_set<K, C, A>::rbegin() const -> const_reverse_iterator
    {
        return elts_.rbegin();
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::crbegin() const -> const_reverse_iterator
    {
        return elts_.crbegin();
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::rend() -> reverse_iterator
    {
        return elts_.rend();
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::rend() const -> const_reverse_iterator
    {
        return elts_.rend();
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::crend() const -> const_reverse_iterator
    {
        return elts_.crend();
    }

    template<typename K, typename C, typename A>
    inline bool flat_set<K, C, A>::empty() const
    {
      return elts_.empty();
    }

    template<typename K, typename C, typename A>
    inline size_t flat_set<K, C, A>::size() const
    {
      return elts_.size();
    }

    template<typename K, typename C, typename A>
    inline size_t flat_set<K, C, A>::max_size() const
    {
      return elts_.max_size();
    }

    template<typename K, typename C, typename A>
    inline void flat_set<K, C, A>::clear()
    {
      elts_.clear();
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::insert(const K& value) -> pair<iterator, bool>
    {
      iterator low;
      low = std::lower_bound(elts_.begin(), elts_.end(), value);
      if (*low != value)
      {
        elts_.insert(low, value);
        return std::pair<iterator, bool>(low, true);
      }
      return std::pair<iterator, bool>(low, false);
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::insert(K&& value) -> pair<iterator, bool>
    {
      iterator low;
      low = std::lower_bound(elts_.begin(), elts_.end(), value, compare_);
      if (*low != value)
      {
        elts_.insert(low, value);
        return std::pair<iterator, bool>(low, true);
      }
      return std::pair<iterator, bool>(low, false);
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::insert(iterator hint, const K& value) -> iterator
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

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::insert(const_iterator hint, const K& value) -> iterator
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

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::insert(const_iterator hint, K&& value) -> iterator
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

    template<typename K, typename C, typename A>
    template<class InputIt>
    inline void flat_set<K, C, A>::insert(InputIt first, InputIt last)
    {
      InputIt it = first;
      while (it != last)
      {
        insert(*it);
        it++;
      }
    }

    template<typename K, typename C, typename A>
    inline void
    flat_set<K, C, A>::insert(initializer_list<value_type> ilist)
    {
      for (auto it : ilist)
        insert(*it);
    }

    /* LOOKUP */
    template<typename K, typename C, typename A>
    inline size_t flat_set<K, C, A>::count(const K& key) const
    {
        if (find(key) != elts_.end())
            return 1;
        else
            return 0;
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::find(const K& key) -> iterator
    {
        auto it = lower_bound(elts_.begin(), elts_.end(), key, compare_);
        if (*it == key)
            return it;
        else
            return elts_.end();
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::find(const K& key) const -> const_iterator
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
