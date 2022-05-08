using namespace std;


class PQ{ // priority queue
private:
    struct data{
        int d; // data
        int p; // priority
    };
    data * q;
    unsigned int count;
    unsigned int capacity;
    void incCapacity();
public:
    PQ();
    ~PQ();
    PQ(const PQ&);
    PQ& operator=(const PQ&);
    int front();
    void dequeue();
    void enqueeu(int d, int p = 999);
    unsigned int size();
    bool empty();
};

int PQ::front(){
    return q[0].d; //return data
}

void PQ::dequeue(){
    q[0] = q[--count];
    int k = 0;

    while (k <= (count -2)/2){
        int lc = lchild(k); int smaller;
        if (lc + 1 >= count)
            smaller = lc;
        else if (q[lc].p < q[lc+1].p)
            smaller = lc;
        else
            smaller = lc + 1;

        if (q[k].p > q[smaller].p)
            swap(q[k], q[smaller]);
        else
            break;
        k = smaller;
    }
}

void PQ::enqueeu(int d, int p){
    data tmp;
    tmp.d = d; tmp.p = p;
    if (count == capacity)
        incCapacity();

    q[count] = tmp; count++;
    int k = count -1;

    while (k > 0){
        int pi = parent(k);
        if (q[pi].p > q[k].p)
            swap(q[pi], q[k]);
        else 
            break;
        k = pi;
    }
}