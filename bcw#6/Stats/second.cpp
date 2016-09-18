#include <set>
#include <fstream>

using namespace std;

int main() {
    fstream in("task.in", fstream::in);
    fstream out("task.out", fstream::out);
    set<char> symbols;
    
    for ( ; in.peek() != EOF; ) {
        char c = in.get();
        bool isChar = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        
        if ( isChar ) {
            symbols.insert(c);
        }
    }
    in.close();
    
    for ( set<char>::iterator it = symbols.begin(); it != symbols.end(); it++ ) {
        out << *it;
    }
    out << endl;
    out.close();
    
    return 0;
}
