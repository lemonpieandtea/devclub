#include <set>
#include <fstream>

using namespace std;

int main() {
    fstream in("task.in", fstream::in);
    fstream out("task.out", fstream::out);
    set<char> symbols;
    
    for ( char c; in.peek() != EOF; ) {
        in >> c;
        symbols.insert(c);
    }
    in.close();
    
    for ( set<char>::iterator it = symbols.begin(); it != symbols.end(); it++ ) {
        out << *it;
    }
    out << endl;
    out.close();
    
    return 0;
}
