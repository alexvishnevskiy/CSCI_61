#include "node.h"


node::node(){
    data_ = 0;
    link_ = nullptr;
}

node::node(const int & initdata, node * initlink){
    data_ = initdata;
    link_ = initlink;
}

node::~node(){
    link_ = nullptr;
}

int node::data() const{
    return data_;
}

node * node::link(){
    return link_;
}

const node * node::link() const{
    return link_;
}

void node::set_data(const int & newdata){
    data_ = newdata;
}

void node::set_link(node * newlink){
    link_ = newlink;
}
