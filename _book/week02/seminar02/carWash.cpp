#include <iostream>
#include <random>
#include <queue>
using namespace std;


class Washer{
unsigned int time;
public:
    Washer(){ time = 0; }
    void startWash(unsigned int t){ time = t; }
    void run(){ time--; }
    bool done() { return (time == 0); }
};

class Source{
private:
    double probability;
public:
    Source(double p):probability(p){}
    unsigned int car(){
        if (rand() / RAND_MAX <= probability){
            if (rand() / RAND_MAX < 0.5){
                return 5;
            }else{
                return 7;
            }
        }
        return 0;
    }
};

void controller(){
    Washer w;
    Source s(0.1);
    queue<unsigned int> q;
    // for two hours
    for (int time = 1; time <= 120; time++){
        unsigned int t = s.car();
        if (t > 0){
            q.push(t);
        }
        if (!q.empty()){
            if (w.done()){
                w.startWash(q.front());
                q.pop();
            }else{
                w.run();
            }
        }else{
            if (!w.done())
                w.run();
        }
    }
}