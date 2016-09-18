#include <map>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    fstream in("task.in", fstream::in);
    fstream out("task.out", fstream::out);
    map<char, int> symbols;
    
    for ( ; in.peek() != EOF; ) {
        char c = in.get();
        bool isChar = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        
        if ( symbols.find(c) == symbols.end() && isChar ) {
            symbols.insert(pair<char, int>(c, 1));
        } else if ( isChar ) {
            symbols[c] += 1;
        }
    }
    in.close();
    
    for ( map<char, int>::iterator it = symbols.begin(); it != symbols.end(); it++ ) {
        out << it->first << " = " << it->second << endl;
    }
    out.close();
    
    return 0;
}
