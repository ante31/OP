/*.
1. (20) Napišite klasu money i potrebne operatore tako da bi sljede´ci program:
int main ()
{
money papers (6 , 50) , coffee (5 , 70) , sugar (1) ;
money bill ;
bill = papers + coffee + sugar ;
std :: cout << " Total : " << bill << std :: endl ;
}
ispisivao:
Total : 13 kuna , 20 lipa
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class money {
public:
    int kune;
    int lipe;

    money() {
        kune = 0;
        lipe = 0;
    }

    money(int a) {
        kune = a;
        lipe = 0;
    }

    money(int a, int b) {
        kune = a;
        lipe = b;
    }

    money operator+ (const money m) {
        money result;
        result.kune = this->kune + m.kune;
        result.lipe = this->lipe + m.lipe;
        if (lipe >= 100) {
            result.lipe -= 100;
            result.kune += 1;
        }
        return result;
    }
};

ostream& operator<<(ostream& out, const money& m) {
    out << m.kune <<endl;
    out << m.lipe <<endl;
    return out;
}

int main() {
    money papers(6, 50), coffee(5, 70), sugar(1);
    money bill;
    bill = papers + coffee + sugar;
    cout << " Total : " << bill << std::endl;
}
