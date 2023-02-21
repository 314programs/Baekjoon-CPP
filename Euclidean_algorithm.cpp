//I should have added this early because I keep forgetting.
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}

//GCD algorithm for negative numbers that I found on stackoverflow
//Thank you stackoverflow
int gcd(int a, int b)
{
    if(a == 0) return b;
    if(b == 0) return a;
    a = abs(a);
    b = abs(b);
    if(a > b) return gcd(b, a);
    return gcd(b%a, a);
}
