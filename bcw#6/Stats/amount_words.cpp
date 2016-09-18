#include <map>
#include <string>
#include <fstream>
#include <iostream>

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
    map<string, int> words;
    
    for ( string word; in.peek() != EOF; ) {
        in >> word;
        
        if ( isWord(word) && words.count(word) == 0 ) {
            stripWord(word);
            words.insert(pair<string, int>(word, 1));
        } else if ( isWord(word) ) {
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
