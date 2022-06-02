#include <iostream>
using namespace std;


struct hashdata{
    int key;
    int data;
};

class CH{
private:
    struct node{
        int data;
        node * next;
        node(int d, node * n = nullptr){
            data = d;
            next = n;
        };
    };

    node * data[811];
    int count; // overall number of elements
    int hash(int key){
        return key%811;
    };
    void clear(){
        count = 0;
        for (int i = 0; i < 811; i++){
            while (data[i]){
                node * t = data[i];
                data[i] = data[i] -> next;
                delete t;
            }
        }
    }
    void init(){
        for (int i = 0; i < 811; i++){
            data[i] = nullptr;
        }
        count = 0;
    }

    node* copy(node *& other){ //we can't use assignment operator with const
                                     //we should make another function with const
        node * p_other = other;
        node * result = nullptr; // if p_other is nullptr we should return nullptr
        node * pcun = nullptr;

        while (p_other){
            if (!pcun){
                result = pcun = new node(p_other->data);
            }else{
                pcun = pcun->next = new node(p_other->data);
            }
            p_other = p_other -> next;
        }
        return result;
    }

    node* _find(const hashdata& x){
        int loc = hash(x.data);
        node * p = data[loc];

        while (p && p->data != x.data){
            p = p->next;
        }
        return p;
    }
public:
    CH(){
        for (int i = 0; i < 811; i++){
            data[i] = nullptr;
        }
        count = 0;
    }

    ~CH(){
        clear();
    }

    CH& operator =(CH& other){
        if (this == &other) return *this;
        clear();

        for (int i = 0; i < 811; i++){
            data[i] = copy(other.data[i]);
        }
        count = other.count;
        return *this;
    } 

    CH(CH& other){
        init();
        *this = other;
    }

    void add(const hashdata& x){
        int loc = hash(x.key);
        int i = loc;
        data[i] = new node(x.data, data[i]);
        count++;
    }

    bool find(const hashdata& x){
        return _find(x);
    }

    void remove(const hashdata& x){
        int loc = hash(x.key);
        node * p = _find(x);

        if (p){
            node * pprev = data[loc];
            if (p == pprev){
                data[loc] = data[loc] -> next;
                delete p;
            }else{
                while (pprev -> next != p){
                    pprev = pprev -> next;
                }
                pprev->next = p->next;
                delete p;
            }
            count--;
        }
    }
};