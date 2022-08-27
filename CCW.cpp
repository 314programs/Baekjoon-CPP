int CCW(int x1, int y1, int x2, int y2, int x3, int y3){
    int temp = x1*y2 + x2*y3 + x3*y1;
    temp -= x2*y1 + x3*y2 + x1*y3;
    //Straight line
    if(temp == 0) return 0;
    //Clockwise
    else if(temp < 0) return -1;
    //Counter clockwise
    else return 1;
}
