#include <iostream>
#include <initializer_list>
#include <deque>
template < class T, class Container = std::deque<T>>
class stack
{
public:
    using container_type = Container;
    using value_type = typename container_type::value_type;
    using size_type = typename Container::size_type;
    using reference	= typename Container::reference;
    using const_reference = typename Container::const_reference;
private:
    container_type storage;
public:

    stack() = default;
    stack(std::initializer_list<value_type> _list)
    {
        for(typename std::initializer_list<value_type>::iterator i = _list.begin(); i != _list.end(); ++i)
            storage.push_back(*i);
    }
    reference top()
    {
        return storage.front();
    }
    bool empty() const
    {
        return storage.empty();
    }
    size_type size() const
    {
        return storage.size();
    }
    void push(const value_type& value)
    {
        storage.push_front(value);
    }
    void pop()
    {
        storage.pop_front();
    }
    void swap(stack<value_type>& other) noexcept
    {
        stack<value_type> temp;
        temp = other;
        other = *this;
        *this = temp;
    }
};


int main()
{
    stack<int> arr{1,1,1,1,1,1};


    stack<int> arr1{2,2,2,2,2,2};
    arr.swap(arr1);
    std::cout << arr1.top() << "\n";
    std::cout << arr.top();
    return 0;
}
