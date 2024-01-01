// Copyright(C) EzicMan, tmp64 2023
// Distributed under WTFPL license
#pragma once
#include <iterator>

struct IntrusiveListItem {
    IntrusiveListItem* next = nullptr;
    IntrusiveListItem* prev = nullptr;
    void* currentObject = nullptr;

    IntrusiveListItem() = delete;

    IntrusiveListItem(void* objptr) {
        currentObject = objptr;
    }
};

template<typename T>
class IntrusiveList {
public:
    struct iterator {
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;  // or also value_type*
        using reference = T&;  // or also value_type&
        T& operator*()const {
            return *reinterpret_cast<T*>(ptr->currentObject);
        }

        iterator& operator++() {
            ptr = ptr->next;
            return *this;
        }
        iterator operator++(int) {
            auto copy = *this;
            ptr = ptr->next;
            return copy;
        }

        iterator& operator--() {
            ptr = ptr->prev;
            return *this;
        }
        iterator operator--(int) {
            auto copy = *this;
            ptr = ptr->prev;
            return copy;
        }

        IntrusiveListItem* to_ptr() { return ptr; }

        // auto operator<=>(const my_iterator&) const = default;
        bool operator==(const iterator& other)const {
            return ptr == other.ptr;
        }
        bool operator!=(const iterator& other)const {
            return ptr != other.ptr;
        }

        iterator() = default;
        iterator(IntrusiveListItem* p) : ptr(p) { }
        iterator(IntrusiveListItem& p) : iterator(&p) { }

    private:
        IntrusiveListItem* ptr = nullptr;
    };

    IntrusiveList()
    {
        beginptr = fakelast;
        endptr = fakelast;
        fakefirst.next = &fakelast;
        fakefirst.prev = &fakefirst;
        fakelast.next = &fakelast;
        fakelast.prev = &fakefirst;
    }

    void add(IntrusiveListItem& item) {
        if (beginptr == iterator(fakelast)) {
            endptr = (beginptr = iterator(item));
            fakelast.prev = &item;
            fakelast.next = &fakelast;
            item.next = &fakelast;
            fakefirst.next = &item;
            fakefirst.prev = &fakefirst;
            item.prev = &fakefirst;
            return;
        }
        endptr.to_ptr()->next = &item;
        item.prev = fakelast.prev;
        item.next = &fakelast;
        endptr = iterator(item);
        fakelast.prev = &item;
    }

    void remove(IntrusiveListItem& item) {
        item.next->prev = item.prev;
        item.prev->next = item.next;
        if (beginptr == endptr && beginptr == iterator(item)) {
            beginptr = (endptr = iterator(fakelast));
        }
        else if (beginptr == iterator(item)) {
            beginptr++;
        }
        else if (endptr == iterator(item)) {
            endptr--;
        }
        item.next = nullptr;
        item.prev = nullptr;
    }

    void remove(iterator item) { remove(*item.to_ptr()); }

    iterator begin() const { return beginptr; }

    iterator end() const { return &const_cast<IntrusiveListItem&>(fakelast); }

    bool empty() const { return begin() == end(); }

private:
    IntrusiveListItem fakefirst = IntrusiveListItem(nullptr);
    iterator beginptr;
    iterator endptr;
    IntrusiveListItem fakelast = IntrusiveListItem(nullptr);
};
