#ifndef GUN_H
#define GUN_H

#define DEFAULT_MAGAZINE 7

class GunException {
    public:
        int code;
        GunException(const int);
};

class Gun {
    private:
        int capacity;
        int bullets;
        
    public:
        Gun();
        Gun(const int);
        int getCapacity() const;
        int getBullets() const;
        void recharge(const int);
        void shoot();
};

#endif // GUN_H
