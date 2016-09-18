#include <set>
#include <string>
#include <fstream>

using namespace std;

bool isCharacter(const char& character) {
    return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
}

bool isWord(const string& word) {
    char firstCharacter = word[0];
    
    return isCharacter(firstCharacter);
}

void stripWord(string& word) {
    for ( ; isCharacter(word[word.length()-1]) == false; ) {
        word.resize(word.length()-1);
    }
}

int main() {
    fstream in("task.in", fstream::in);
    fstream out("task.out", fstream::out);
    set<string> words;
    
    for ( string word; in.peek() != EOF; ) {
        in >> word;
        
        if ( isWord(word) ) {
            stripWord(word);
            words.insert(word);
        }
    }
    in.close();
    
    for ( set<string>::iterator it = words.begin(); it != words.end(); it++ ) {
        out << *it << endl;
    }
    out.close();
    
    return 0;
}
