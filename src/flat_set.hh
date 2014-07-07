#ifndef FLAT_SET_HH
# define FLAT_SET_HH

# include <vector>
# include <utility>
# include <functional>
# include <memory>
# include <initializer_list>

namespace std
{
template<typename Key,
         typename Compare = less<Key>,
         typename Allocator = allocator<Key>>
class flat_set
{

  public:
    /* Types */
    typedef Key                   key_type;
    typedef Key                   value_type;
    typedef Compare               key_compare;
    typedef Compare               value_compare;
    typedef Allocator             allocator_type;
    typedef value_type&           reference;
    typedef const value_type&     const_reference;

    typedef typename vector<Key>::iterator               iterator;
    typedef typename vector<Key>::const_iterator         const_iterator;
    typedef typename vector<Key>::reverse_iterator       reverse_iterator;
    typedef typename vector<Key>::const_reverse_iterator const_reverse_iterator;

    typedef size_t                                     size_type;
    typedef ptrdiff_t                                  difference_type;
    typedef typename allocator_traits<Allocator>::pointer       pointer;
    typedef typename allocator_traits<Allocator>::const_pointer const_pointer;

    /* CONSTRUCTORS */
    flat_set();
    explicit flat_set( const Allocator& alloc );
    template<class InputIt>
    flat_set(InputIt first, InputIt last,
         const Compare& comp = Compare(),
         const Allocator& alloc = Allocator());
    flat_set(const flat_set& other );
    flat_set(const flat_set& other, const Allocator& alloc);
    flat_set(flat_set&& other);
    flat_set(flat_set&& other, const Allocator& alloc);
    flat_set(initializer_list<value_type> init,
         const Compare& comp = Compare(),
         const Allocator& alloc = Allocator());

    /* DESTRUCTOR */
    ~flat_set();

    /* OPERATOR EQUALS */
    flat_set& operator=( const flat_set& other );
    flat_set& operator=( flat_set&& other );
    flat_set& operator=( initializer_list<value_type> ilist );

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

    /* CAPACITY */
    bool empty() const;
    size_type size() const;
    size_type max_size() const;

    /* MODIFIERS */
    void clear();

    pair<iterator,bool> insert(const value_type& value);
    pair<iterator, bool> insert(value_type&& value);
    iterator insert(iterator hint, const value_type& value);
    iterator insert(const_iterator hint, const value_type& value);
    iterator insert(const_iterator hint, value_type&& value);
    template<class InputIt>
    void insert(InputIt first, InputIt last);
    void insert(initializer_list<value_type> ilist);

    template<class... Args>
    pair<iterator, bool> emplace(Args&&... args);
    template <class... Args>
    iterator emplace_hint(const_iterator hint, Args&&... args);

    void erase(iterator position);
    iterator erase(const_iterator position);
    void erase(iterator first, iterator last);
    iterator erase(const_iterator first, const_iterator last);
    size_type erase(const key_type& key);

    void swap( flat_set& other );

    /* LOOKUP */
    size_type count(const Key& key) const;

    iterator find(const Key& key);
    const_iterator find( const Key& key) const;

    pair<iterator,iterator> equal_range(const Key& key);
    pair<const_iterator,const_iterator> equal_range(const Key& key) const;

    iterator lower_bound(const Key& key);
    const_iterator lower_bound(const Key& key) const;

    iterator upper_bound(const Key& key);
    const_iterator upper_bound(const Key& key) const;

    /* OBSERVATORS */
    key_compare key_comp() const;
    value_compare value_comp() const;

    private:
      vector<Key> elts;

};

template< class Key, class Compare, class Alloc >
bool operator==( const flat_set<Key,Compare,Alloc>& lhs,
                 const flat_set<Key,Compare,Alloc>& rhs );
template< class Key, class Compare, class Alloc >
bool operator!=( const flat_set<Key,Compare,Alloc>& lhs,
                 const flat_set<Key,Compare,Alloc>& rhs );
template< class Key, class Compare, class Alloc >
bool operator<( const flat_set<Key,Compare,Alloc>& lhs,
                const flat_set<Key,Compare,Alloc>& rhs );
template< class Key, class Compare, class Alloc >
bool operator<=( const flat_set<Key,Compare,Alloc>& lhs,
                 const flat_set<Key,Compare,Alloc>& rhs );
template< class Key, class Compare, class Alloc >
bool operator>( const flat_set<Key,Compare,Alloc>& lhs,
                const flat_set<Key,Compare,Alloc>& rhs );
template< class Key, class Compare, class Alloc >
bool operator>=( const flat_set<Key,Compare,Alloc>& lhs,
                 const flat_set<Key,Compare,Alloc>& rhs );

template< class Key, class Compare, class Alloc >
void swap( flat_set<Key,Compare,Alloc>& lhs,
           flat_set<Key,Compare,Alloc>& rhs );

}
#endif /* FLAT_flat_set_HH */
