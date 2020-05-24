class ReferenceCount
{
private:
    int m_RefCount{ 0 };
public:
    void Increment()
    {
        ++m_RefCount;
    }
    int Decrement()
    {
        return --m_RefCount;
    }
    int GetCount() const
    {
        return m_RefCount;
    }
};

template <typename T>
class smart_ptr
{
private:
    T* m_Object
    {
      nullptr
    };
    ReferenceCount* m_ReferenceCount
    {
      nullptr
    };

public:
    smart_ptr()
    {
    } 
    smart_ptr(T* object) : m_Object{ object }, m_ReferenceCount{ new ReferenceCount() }
    {
        m_ReferenceCount->Increment();
        cout << "Created smart_ptr! Ref count is " << m_ReferenceCount->GetCount() << endl;
    } 
    virtual ~smart_ptr()
    {
        if (m_ReferenceCount)
        {
            int decrementedCount = m_ReferenceCount->Decrement();
            cout << "Destroyed smart_ptr! Ref count is " << decrementedCount << endl;
            if (decrementedCount <= 0)
            {
                delete m_ReferenceCount;
                delete m_Object;
                m_ReferenceCount = nullptr;
                m_Object = nullptr;
            }
        }
    } 
    smart_ptr(const smart_ptr<T>& other) : m_Object{ other.m_Object }, m_ReferenceCount{ other.m_ReferenceCount }
    {
        m_ReferenceCount->Increment();
        cout << "Copied smart_ptr! Ref count is "
            << m_ReferenceCount->GetCount() << endl;
    }
    // Overloaded Assignment Operator
    smart_ptr<T>& operator=(const smart_ptr<T>& other)
    {
        if (this != &other)
        {
            if (m_ReferenceCount && m_ReferenceCount->Decrement() == 0)
            {
                delete m_ReferenceCount;
                delete m_Object;
            }
            m_Object = other.m_Object;
            m_ReferenceCount = other.m_ReferenceCount;
            m_ReferenceCount->Increment();
        }
        cout << "Assigning smart_ptr! Ref count is " << m_ReferenceCount->GetCount() << endl;
        return *this;
    }
    //Dereference operator
    T& operator*()
    {
        return *m_Object;
    }
    //Member Access operator
    T* operator->()
    {
        return m_Object;
    }
};