#ifndef FLAT_SET_HH
# define FLAT_SET_HH

# include <std::vector>

class Flat_flat_set {

  public:
    /* CONSTRUCTORS */
    explicit flat_set(const Compare& comp = Compare(),
              const Allocator& alloc = Allocator());
    explicit flat_set( const Allocator& alloc );
    flat_set(const flat_set& other, const Allocator& alloc);
    flat_set(flat_set&& other);
    flat_set(const flat_set& other);
    flat_set(flat_set&& other, const Allocator& alloc);
    flat_set(std::initializer_list<value_type> init,
      const Compare& comp = Compare(),
                  const Allocator& alloc = Allocator());

    template<class InputIt>
    flat_set(InputIt first, InputIt last, const Compare& comp = Compare(),
        const Allocator& alloc = Allocator());

    /* DESTRUCTOR */
    ~flat_set();

    /* OPERATORS & ALLOCATOR*/
    set& operator=(const set& other);
    set& operator=(set&& other);
    template<>
    bool operator==(set<>& lhs, set<>& rhs);
    template<>
    bool operator!=(set<>& lhs, set<>& rhs);
    template<>
    bool operator<(set<>& lhs, set<>& rhs);
    template<>
    bool operator<=(set<>& lhs, set<>& rhs);
    template<>
    bool operator>(set<>& lhs, set<>& rhs);
    template<>
    bool operator>=(set<>& lhs, set<>& rhs);

    allocator_type get_allocator() const;

    /* ITERATORS */
    iterator begin();
    const_iterator begin() const;
    const_iterator cbegin() const;

    iterator end();
    const_iterator end() const;
    const_iterator cend() const;

    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator crbegin() const;

    reverse_iterator rend();
    const_reverse_iterator rend() const;
    const_reverse_iterator crend() const;

    /* COMPLEXITY */
    bool empty() const;
    size_type size() const;
    size_type max_size() const;

    /* MODIFICATORS */
    void clear();

    std::pair<iterator,bool> insert(const value_type& value);
    std::pair<iterator, bool> insert(value_type&& value);
    iterator insert(iterator hint, const value_type& value);
    iterator insert(const_iterator hint, const value_type& value);
    iterator insert(const_iterator hint, value_type&& value);
    template<class InputIt>
    void insert(InputIt first, InputIt last);
    void insert(std::initializer_list<value_type> ilist);

    template<class... Args>
    std::pair<iterator, bool> emplace(Args&&... args);
    template <class... Args>
    iterator emplace_hint(const_iterator hint, Args&&... args);

    void erase(iterator position);
    iterator erase(const_iterator position);
    void erase(iterator first, iterator last);
    iterator erase(const_iterator first, const_iterator last);
    size_type erase(const key_type& key);

    void swap( set& other );

    /* LOOKUP */
    size_type count(const Key& key) const;

    iterator find(const Key& key);
    const_iterator find( const Key& key) const;

    std::pair<iterator,iterator> equal_range(const Key& key);
    std::pair<const_iterator,const_iterator> equal_range(const Key& key) const;

    iterator lower_bound(const Key& key);
    const_iterator lower_bound(const Key& key) const;

    iterator upper_bound(const Key& key);
    const_iterator upper_bound(const Key& key) const;

    /* OBSERVATORS */
    key_compare key_comp() const;
    std::set::value_compare value_comp() const;


  private:
  // ?
};

#endif /* FLAT_SET_HH */
