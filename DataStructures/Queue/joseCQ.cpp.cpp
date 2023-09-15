#include "CQueueArr.hpp"
//#include "circular_queue.hpp"

int main(){
    freopen("jos_in.txt", "r", stdin);
    freopen("jos_out.txt", "w", stdout);

    int num;
    cin >> num; 
    int pulse;
    cin >> pulse; 
    CQueue q(num+2);
    //CirQ q(num + 2);

    for (int i = 1; i <= num; i++)    q.push(i);
    int ct=0;
    while (!q.isEmpty()){
        if (q.size() == 1){
            cout << "The remaining one: " << q.Front() << endl;
            break;
        } ct++;
        int p = q.pop();
        if (ct == pulse){
            ct = 0;
            continue;
        } q.push(p);
    } return 0;
}