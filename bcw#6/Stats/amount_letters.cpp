#include <map>
#include <fstream>

using namespace std;

int main() {
    fstream in("task.in", fstream::in);
    fstream out("task.out", fstream::out);
    map<char, int> symbols;
    
    for ( char character; in.peek() != EOF; ) {
        bool isChar = false;
        
        in >> character;
        
        if ( character >= 'A' && character <= 'Z' ) {
            character -= 'A' - 'a';
            isChar = true;
        } else if ( character >= 'a' && character <= 'z' ) {
            isChar = true;
        }
        
        if ( isChar && symbols.count(character) == 0 ) {
            symbols.insert(pair<char, int>(character, 1));
        } else if ( isChar ) {
            symbols[character] += 1;
        }
    }
    in.close();
    
    for ( map<char, int>::iterator it = symbols.begin(); it != symbols.end(); it++ ) {
        out << it->first << " = " << it->second << endl;
    }
    out.close();
    
    return 0;
}
