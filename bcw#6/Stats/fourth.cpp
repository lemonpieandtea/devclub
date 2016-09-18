#include <set>
#include <string>
#include <fstream>

using namespace std;

bool isCharacter(const char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    fstream in("task.in", fstream::in);
    fstream out("task.out", fstream::out);
    set<string> words;
    
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
                words.insert(word);
            }
        }
    }
    in.close();
    
    for ( set<string>::iterator it = words.begin(); it != words.end(); it++ ) {
        out << *it << endl;
    }
    out.close();
    
    return 0;
}
