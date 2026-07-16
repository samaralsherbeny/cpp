#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

    int main() {
        string s = "Hello";

        s.assign("Code");          
        cout << s.at(1) << endl;     
        cout << s.front() << endl;  
        cout << s.back() << endl;   
        cout << s.c_str() << endl;   

        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            cout << *it;            
        }
        cout << endl;

        reverse(s.begin(), s.end()); 
        cout << s << endl;

        return 0;
    }
