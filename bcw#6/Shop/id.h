#ifndef ID_H
#define ID_H

#define INITIAL_ID 1

class Id {
    private:
        static int lastId;
        int id;
        
    public:
        Id();
        Id(const Id& originalId);
        const int& getId() const;
        static const int& getLastId();
        ~Id();
};

#endif
