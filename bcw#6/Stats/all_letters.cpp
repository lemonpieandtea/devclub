#include <set>
#include <fstream>

using namespace std;

int main() {
    fstream in("task.in", fstream::in);
    fstream out("task.out", fstream::out);
    set<char> symbols;
    
    for ( char character; in.peek() != EOF; ) {
        bool isChar = false;
        
        in >> character;
        
        if ( character >= 'A' && character <= 'Z' ) {
            character -= 'A' - 'a';
            isChar = true;
        } else if ( character >= 'a' && character <= 'z' ) {
            isChar = true;
        }
        
        if ( isChar ) {
            symbols.insert(character);
        }
    }
    in.close();
    
    for ( set<char>::iterator it = symbols.begin(); it != symbols.end(); it++ ) {
        out << *it << endl;
    }
    out.close();
    
    return 0;
}
