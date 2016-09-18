#ifndef ARRAYLIST_H
#define ARRAYLIST_H

template <class Type>
class ArrayList {
    private:
        
    public:
        ArrayList();
        ArrayList(size_type n);
        ArrayList(size_type n, Type element);
        
        size_type size() const;
        void resize(size_type newSize);
        size_type capacity() const;
        bool empty() const;
        void reserve (size_type newSize);
        void shrinkToFit();
        
        Type operator[](size_type position);
        Type at(size_type position);
        Type front();
        Type back();
        Type* data();
        
        void push_back(const value_type& val);
        
        ~ArrayList();
};

#endif