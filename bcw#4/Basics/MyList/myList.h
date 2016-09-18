#ifndef MYLIST_H
#define MYLIST_H

class ListError {
    public:
        int code;
        ListError(int);
};

class MyList {
    private:
        int size;
        int* array;
        void arrayCopy(int*, int, int, int);
    
    public:
        MyList();
        MyList(int*, int);
        ~MyList();
        int getSize() const;
        int getValue() const;
        int getValue(const int) const;
        void putValue(const int&);
        void putValue(const int&, const int);
        void putMultiple(const int*, const int);
        void remove();
        void remove(const int);
        void trimm(const int);
        void operator+=(const int&);
        void operator-=(const int&);
};

std::ostream& operator<<(std::ostream&, const MyList&);

#endif // MYLIST_H
