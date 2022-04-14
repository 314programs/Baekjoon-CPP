#include <bits/stdc++.h>
using namespace std;

int Number_List[26];
stack<double> s;

int main(void){
    int Numbers;
    string Equation;
    cin >> Numbers;
    cin >> Equation;

    for(int i = 0; i < Numbers; i++){
        //Number_List serves as a sort of dictionary to get values
        double num;
        cin >> num;
        Number_List[i] = num;
    }

    for(auto ch: Equation){
        if((int)'A' <= (int)ch && (int)ch <= (int)'Z'){
            //Put into stack if it is a variable
            s.push(Number_List[(int)ch - (int)'A']);
        }
        else{
            //Else calculate 2 numbers in top of the stack and push the value back into the stack
            double num1 = s.top(); s.pop();
            double num2 = s.top(); s.pop();

            if(ch == '+'){
                s.push(num2 + num1);
            }
            else if(ch == '-'){
                s.push(num2 - num1);
            }
            else if(ch == '*'){
                s.push(num2 * num1);
            }
            else if(ch == '/'){
                s.push(num2/num1);
            }

        }
    }
    
    //Format to 2 decimal places
    cout << setprecision(2) << fixed;
    cout << s.top();


}
