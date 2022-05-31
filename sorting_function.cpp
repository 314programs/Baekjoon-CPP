struct meeting{
    int start;
    int end;
};

//Comparing function that returns a bool
//Takes in 2 sorting values and returns a bool based on conditions
bool compare(const meeting &u, const meeting &v){
    if(u.end == v.end){
        return u.start < v.start;
    }
    else{
        return u.end < v.end;
    }
}

//Soring code
sort(meets.begin(), meets.end(), compare);

