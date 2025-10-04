
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]){
    int len;
    cin >> len;
    cin.ignore();

    char input[len];
    cin.getline(input, len);

    char remove[len];
    while (cin >> remove && strcmp(remove, "stop") != 0){
        // cout << "Remove: " << remove << endl;
        // if (strcmp(remove, "stop") == 0) break;
        
        char* result = strstr(input, remove);

        while (result != nullptr){
            // cout << "Result: " << result << endl;
            // cout << "Input: " << input << endl;
            // cout << "Remove: " << remove << endl;
            // cout << "Start index: " << result - input << endl;
            // cout << "Length of remove: " << strlen(remove) << endl;
            
            const size_t startIndex = result - input;

            for (size_t i = 0; i < startIndex; i++){
                result[i] = '/';
            }

            result += startIndex; // optimization
            

        }
        
        // if (strcmp(input, remove) == 0) continue;

        // for (size_t i = startIndex; i < startIndex + strlen(remove); i++){
        //     input[i] = '/';
        // }
        
        for (size_t i = 0; i < strlen(input); i++){
            
            if (input[i] != '/'){
                cout << input[i];
            }
        }
        
    }
    

    return 0;
}
