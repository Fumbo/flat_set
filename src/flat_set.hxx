#ifndef FLAT_SET_HXX
# define FLAT_SET_HXX

# include "flat_set.hh"

namespace std
{

    // CONSTRUCTORS
    template<typename K, typename C, typename A>
    inline flat_set<K, C, A>::flat_set(const C&, const A&)
      : elts_(std::vector<K, A>())
    {
    }

    template<typename K, typename C, typename A>
    inline flat_set<K, C, A>::flat_set(const A& alloc)
      : elts_(std::vector<K, A>(alloc))
    {
    }

    template<typename K, typename C, typename A>
    template<class InputIt>
    inline flat_set<K, C, A>::flat_set(InputIt first, InputIt last, const C&, const A&)
        : elts_(std::vector<K, A>(first, last))
    {
    }

    template<typename K, typename C, typename A>
    inline flat_set<K, C, A>::flat_set(const flat_set& other)
      : elts_(std::vector<K, A>(other.elts_, allocator_type()))
    {
    }

    template<typename K, typename C, typename A>
    inline flat_set<K, C, A>::flat_set(const flat_set& other, const A& alloc)
      : elts_(std::vector<K, A>(other.elts_, alloc))
    {
    }

    template<typename K, typename C, typename A>
    inline flat_set<K, C, A>::flat_set(flat_set&& other)
      : elts_(move(other.elts_))
    {
    }

    template<typename K, typename C, typename A>
    inline flat_set<K, C, A>::flat_set(flat_set&& other, const A& alloc)
      : elts_(std::vector<K, A>(other.elts_, alloc))
    {
    }

    template<typename K, typename C, typename A>
    inline flat_set<K, C, A>::flat_set(initializer_list<value_type> init, const C&,
                                       const A&)
    {
      insert(init);
    }

    /* DESTRUCTOR */
    template<typename K, typename C, typename A>
    inline flat_set<K, C, A>::~flat_set()
    {
    }

    /* OPERATOR EQUALS */
    template<typename K, typename C, typename A>
    flat_set<K, C, A>& flat_set<K, C, A>::operator=(const flat_set& other)
    {
        elts_ = other.elts_;
        return *this;
    }

    template<typename K, typename C, typename A>
    flat_set<K, C, A>& flat_set<K, C, A>::operator=(flat_set&& other)
    {
        elts_ = other.elts_;
        return *this;
    }

    template<typename K, typename C, typename A>
    flat_set<K, C, A>& flat_set<K, C, A>::operator=(initializer_list<value_type> ilist)
    {
        // TODO
        elts_ = vector<K, A>(ilist);
        return *this;
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

    template<typename K, typename C, typename A>
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

    /* MODIFIERS */
    template<typename K, typename C, typename A>
    inline void flat_set<K, C, A>::clear()
    {
      elts_.clear();
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::insert(const K& value) -> pair<iterator, bool>
    {
      if (elts_.begin() == elts_.end() )
      {
        elts_.push_back(value);
        return std::pair<iterator, bool>(elts_.begin(), true);
      }

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
      if (elts_.begin() == elts_.end() )
      {
        elts_.push_back(value);
        return std::pair<iterator, bool>(elts_.begin(), true);
      }

      iterator low;
      low = std::lower_bound(elts_.begin(), elts_.end(), value, key_compare());
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
      if (elts_.begin() == elts_.end() )
      {
        elts_.push_back(value);
        return elts_.begin();
      }


      if (find(value) != elts_.end())
        return elts_.end();
      elts_.insert(hint, value);
      if (is_sorted(elts_.begin(), elts_.end(), key_compare()))
        return hint;
      else
      {
        sort(elts_.begin(), elts_.end(), key_compare());
        return find(value);
      }
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::insert(const_iterator hint, const K& value) -> iterator
    {
      if (elts_.begin() == elts_.end() )
      {
        elts_.push_back(value);
        return elts_.begin();
      }

      if (find(value) != elts_.end())
        return elts_.end();
      elts_.insert(hint, value);
      if (is_sorted(elts_.begin(), elts_.end(), key_compare()))
        return hint;
      else
      {
        sort(elts_.begin(), elts_.end(), key_compare());
        return find(value);
      }
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::insert(const_iterator hint, K&& value) -> iterator
    {
      if (elts_.begin() == elts_.end() )
      {
        elts_.push_back(value);
        return elts_.begin();
      }
      if (find(value) != elts_.end())
        return elts_.end();
      elts_.insert(hint, value);
      if (is_sorted(elts_.begin(), elts_.end(), key_compare()))
        return hint;
      else
      {
        sort(elts_.begin(), elts_.end(), key_compare());
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
        insert(it);
    }

    template<typename K, typename C, typename A>
    template<class... Args>
    inline auto
    flat_set<K, C, A>::emplace(Args&&... args) -> pair<iterator, bool>
    {
        return insert(K(forward<Args>(args)...));
    }

    template<typename K, typename C, typename A>
    template <class... Args>
    inline auto
    flat_set<K, C, A>::emplace_hint(const_iterator hint, Args&&... args) -> iterator
    {
        return insert(K(forward<Args>(args)...));
    }

    template<typename K, typename C, typename A>
    void flat_set<K, C, A>::erase(iterator position)
    {
      elts_.erase(position);
    }

    template<typename K, typename C, typename A>
    auto flat_set<K, C, A>::erase(const_iterator position)
        -> iterator
    {
      return elts_.erase(position);
    }

    template<typename K, typename C, typename A>
    void flat_set<K, C, A>::erase(iterator first, iterator last)
    {
        elts_.erase(first, last);
    }

    template<typename K, typename C, typename A>
    auto flat_set<K, C, A>::erase(const_iterator first,
        const_iterator last)
        -> iterator
    {
      elts_.erase(first, last);
    }

    template<typename K, typename C, typename A>
    auto flat_set<K, C, A>::erase(const key_type& key)
        -> size_type
    {
      auto it = find(key);
      if (it != elts_.end())
        elts_.erase(it);
      return elts_.size();
    }

    template<typename K, typename C, typename A>
    void flat_set<K, C, A>::swap( flat_set& other )
    {
      flat_set tmp = flat_set(*this);
      *this = other;
      other = tmp;
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
        auto it = std::lower_bound(elts_.begin(), elts_.end(), key, key_compare());
        if (it != elts_.end() && *it == key)
            return it;
        else
            return elts_.end();
    }

    template<typename K, typename C, typename A>
    inline auto
    flat_set<K, C, A>::find(const K& key) const -> const_iterator
    {
        auto it = std::lower_bound(elts_.cbegin(), elts_.cend(), key, key_compare());
        if (it != elts_.end() && *it == key)
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
        return std::lower_bound(elts_.begin(), elts_.end(), key, key_compare());
    }

    template<typename K, typename C, typename A>
    inline auto flat_set<K, C, A>::lower_bound(const K& key) const -> const_iterator
    {
        return std::lower_bound(elts_.cbegin(), elts_.cend(), key, key_compare());
    }

    template<typename K, typename C, typename A>
    inline auto flat_set<K, C, A>::upper_bound(const K& key) -> iterator
    {
        return std::upper_bound(elts_.begin(), elts_.end(), key, key_compare());
    }

    template<typename K, typename C, typename A>
    inline auto flat_set<K, C, A>::upper_bound(const K& key) const -> const_iterator
    {
        return std::upper_bound(elts_.cbegin(), elts_.cend(), key, key_compare());
    }


    /* OBSERVATORS */
    template<typename K, typename C, typename A>
    inline auto flat_set<K, C, A>::key_comp() const -> key_compare
    {
      return key_compare();
    }

template< class K, class C, class A >
bool operator==( const flat_set<K,C,A>& lhs,
                 const flat_set<K,C,A>& rhs )
{
   return lhs.elts_ == rhs.elts_;
}

template< class K, class C, class A >
bool operator!=( const flat_set<K,C,A>& lhs,
                 const flat_set<K,C,A>& rhs )
{
   return lhs.elts_ != rhs.elts_;
}

template< class K, class C, class A >
bool operator<( const flat_set<K,C,A>& lhs,
                const flat_set<K,C,A>& rhs )
{
   return lhs.elts_ < rhs.elts_;
}

template< class K, class C, class A >
bool operator<=( const flat_set<K,C,A>& lhs,
                 const flat_set<K,C,A>& rhs )
{
   return lhs.elts_ <= rhs.elts_;
}

template< class K, class C, class A >
bool operator>( const flat_set<K,C,A>& lhs,
                const flat_set<K,C,A>& rhs )
{
   return lhs.elts_ > rhs.elts_;
}

template< class K, class C, class A >
bool operator>=( const flat_set<K,C,A>& lhs,
                 const flat_set<K,C,A>& rhs )
{
   return lhs.elts_ >= rhs.elts_;
}

template< class K, class C, class A >
void swap( flat_set<K, C, A>& lhs,
               flat_set<K, C, A>& rhs )
{
   return lhs.swap(rhs);
}


}

#endif // !FLAT_SET_HXX
