#include <iostream>
#include <string>
#include <unordered_set>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]){
    const unordered_set<string> invalidTabs = {"bg-mama.bg", "planeta.bg", "moodle.com"};
    unordered_set<string> tabs;
    string albumName;

    // get open tabs
    int n;  
    cin >> n;
    for (size_t i = 0; i < n; i++){
        string tab;
        cin >> tab;
        tabs.insert(tab);
    }
    
    // get words from sites
    string word;
    while (cin >> word && word != "STOP") {
        string site;
        cin >> site;
        if (tabs.count(site) && !invalidTabs.count(site)) {
            albumName += word + " ";
        }
    }
    
    // cmds
    string cmd;
    while (cin >> cmd && cmd != "STOP") {
        if (cmd == "REPLACE"){
            string substr, newText;
            cin >> substr >> newText;
            size_t startIndex = albumName.find(substr);
            size_t len = startIndex + substr.length();
            albumName.replace(startIndex, substr.length(), newText);
            cout << startIndex << len << endl;
            continue;
        }

        if (cmd == "REMOVE"){
            string substr;
            cin >> substr;
            size_t startIndex = albumName.find(substr);
            size_t len = startIndex + substr.length();
            albumName.erase(startIndex, substr.length()+1); // +1 to remove the space after the word
            continue;
        }

    }

    cout << albumName << endl;
    return 0;
}
