#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    //Had to type every zodiac...
    map<string, int> zodiac;
    zodiac["Ox"] = 0; zodiac["Tiger"] = 1; zodiac["Rabbit"] = 2;
    zodiac["Dragon"] = 3; zodiac["Snake"] = 4; zodiac["Horse"] = 5;
    zodiac["Goat"] = 6; zodiac["Monkey"] = 7; zodiac["Rooster"] = 8;
    zodiac["Dog"] = 9; zodiac["Pig"] = 10; zodiac["Rat"] = 11; 

    int n;
    cin >> n;
    map<string, pair<int, string>> cow;
    cow["Bessie"] = make_pair(0, "Ox");
    
    //String inputs like these are annoying...
    for(int i = 0; i < n; i++){
        string c1, c2;
        string t, z;
        for(int j = 0; j < 8; j++){
            string s;
            cin >> s;
            if(j == 0) c1 = s;
            if(j == 3) t = s;
            if(j == 4) z = s;
            if(j == 7) c2 = s;
        }
        
        //The conditions were slightly tedious, but it was alright
        //The reason I got it wrong was cause I wrote c2 as c1...
        if(t == "previous"){
            int year;
            if(zodiac[z] < zodiac[cow[c2].second]){
                year = zodiac[cow[c2].second] - zodiac[z];
            }
            else{
                year = 12 - zodiac[z] + zodiac[cow[c2].second];
            }
            cow[c1] = make_pair(cow[c2].first - abs(year), z);
        }
        else{
            int year;
            if(zodiac[z] > zodiac[cow[c2].second]){
                year = zodiac[z] - zodiac[cow[c2].second];
            }
            else{
                year = 12 - zodiac[cow[c2].second] + zodiac[z];
            }
            cow[c1] = make_pair(cow[c2].first + abs(year), z);
        }
    }

    cout << abs(cow["Elsie"].first);




}
