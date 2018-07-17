#include <iostream>
#include <string>
using namespace std;
int main(){
	string s1, s2;
	while (true){
		cin >> s1;
		if (s1 == "q"){
			cout << "quit" << endl;
            break;
		}
		if (s1 == "no"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "so"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "ea"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "we"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "ne"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "nw"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "se"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "sw"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "s"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "d"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "v"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "g"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "t"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "f"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "r"){
            cout << s1 << endl;
        }   else if (s1 == "u"){
            cin >> s2;
            cout << s1 << " " << s2 << endl;
        }   else if (s1 == "a"){
            cin >> s2;
            cout << s1 << " " << s2 << endl;
        }
    }
}
