struct Deque{
    int queue[25000];
    int begin;
    int end;

    Deque(){
        begin = 12500;
        end = 12501;
    }

    void push_front(int data){
        queue[begin--] = data;
    }

    void push_back(int data){
        queue[end++] = data;
    }

    void pop_front(){
        queue[begin++] = 0;
    }

    void pop_back(){
        queue[end--] = 0;
    }
    
    int size(){
        return end-begin-1;
    }

    bool empty(){
        if(size() == 0) return true;
        return false;
    }

    int front(){
        return queue[begin+1];
    }

    int back(){
        return queue[end-1];
    }

};
