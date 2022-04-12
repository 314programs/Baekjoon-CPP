struct Queue{
    int data[10000];
    int start, end;

    Queue(){
        start = 0;
        end = 0;
    }

    void push(int data_){
        data[end] = data_;
        end +=1;
    }

    void pop(){
        data[start] = 0;
        start += 1;
    }

    int size(){
        return end - start;
    }

    bool empty(){
        if(size() == 0){
            return true;
        }
        else{
            return false;
        }
    }

    int front(){
        return data[start];
    }

    int back(){
        return data[end-1];
    }

};
