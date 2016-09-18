#include <map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

bool isCharacter(const char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    fstream in("task.in", fstream::in);
    fstream out("task.out", fstream::out);
    map<string, int> words;
    
    for ( ; in.peek() != EOF; ) {
        string word;
        char initialCharacter = in.get();
        bool isChar = isCharacter(initialCharacter);
        
        for ( bool notEnd = true; notEnd && isChar; ) {
            char wordCharacter = in.get();
            notEnd = isCharacter(wordCharacter);
            
            if ( notEnd ) {
                word.push_back(wordCharacter);
            } else {
                word.insert(0, &initialCharacter);
            }
        }
        
        if ( isChar && words.find(word) == words.end() ) {
            words.insert(pair<string, int>(word, 1));
        } else if ( isChar ) {
            words[word] += 1;
        }
    }
    in.close();
    
    for ( map<string, int>::iterator it = words.begin(); it != words.end(); it++ ) {
        out << it->first << " = " << it->second << endl;
    }
    out.close();
    
    return 0;
}
