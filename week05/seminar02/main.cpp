#include <iostream>
#include <cassert>
using namespace std;


struct hashdata{
    int key;
    int data;
};

class bag{
private:
    int data[811];
    int count;
    const int CAP = 811;
    int hash(int key){ return key%CAP; };
    int next(int i){ return (i+1)%CAP; };
public:
    bag():count(0){
        for (int i = 0; i < CAP; i++){
            data[i] = -1; // we can use nullptr or MAX_INT
        }
    }
    // we don't need copy constructor because the default one is good
    // it will clone
    // for pointers we need a copy constructor and destructor
    void add(const hashdata& x){
        assert (count < CAP);
        int loc = hash(x.key);
        if (data[loc] == -1){
            data[loc] = x.data;
        }else{
            int i = next(loc);
            while (data[i] != -1){
                i = next(i);
            }
            data[i] = x.data;
        }
        count++;
    }

    int _find(const hashdata& x){
        int loc = hash(x.key);
        int a = 1; // to complete loop

        while (a <= CAP){
            if (data[loc] == x.data){
                return loc;
            }else{
                loc = next(loc);
                a++;
            }
        }
        return -1;
    }

    bool find(const hashdata& x){
        int a = _find(x);
        return (a != -1);
    }

    void remove(const hashdata& x){
        int loc = _find(x);
        if (loc != -1){
            data[loc] = -1;
        }
    }
};
