//
// Created by msullivan on 9/7/24.
//

#pragma once
#include <cassert>
#include <vector>

template<typename T>
class CList {
    std::vector<T> m_List;

public:
    [[nodiscard]] long size() const { return m_List.size(); }
    [[nodiscard]] bool empty() const { return m_List.empty(); }
    [[nodiscard]] auto begin() { return m_List.begin(); }
    [[nodiscard]] auto end() { return m_List.end(); }

    void emplace(T t)
    {
        m_List.emplace(t);
    }

    void emplace_back(T t)
    {
        m_List.emplace_back(t);
    }

    // Child elements are not deleted, but will cause a crash.
    void remove(int n)
    {
        assert(n >= 0 && n < m_List.size() && "Index out of range");
        if (m_List[n] != nullptr)
        {
            if (m_List[n] != nullptr) delete m_List[n];
            m_List.erase(m_List.begin() + n);
        }
    }

    void clear()
    {
        for (auto item : m_List)
            delete item;
        m_List.clear();
    }

    T get(int n)
    {
        assert(n >= 0 && n < m_List.size() && "Index out of range");
        return m_List[n];
    }

    T operator[](int n)
    {
        assert(n >= 0 && n < m_List.size() && "Index out of range");
        return m_List[n];
    }

    [[nodiscard]] bool contains(T* t)
    {
        for (auto item : m_List)
            if (item == t) return true;
        return false;
    }
};