#include <cstdio>
#include <vector>
#include <set>
#include <list>

void simulate(int, std::vector<std::list<int>>&);

int main()
{
    int N, p;
    scanf("%d", &N);
    std::vector<std::list<int>> pl(N); /* indexが目的地であるリスト */
    for (int i = 0; i < N; i++) {
        scanf("%d", &p);
        pl[p - 1].push_back(i + 1);
    }
    simulate(N, pl);    
    return 0;
}

void simulate(int N, std::vector<std::list<int>>& pl)
{
    std::vector<int> seats(N, -1); /* 最終的な座席表 */
    
    std::set<int> next;
    std::set<int> vacant_seats; /* 空席の集合 */
    
    for (int i = 0; i < N; i++) {
        if (!pl[i].empty()) {
            next.insert(i);
        }
        vacant_seats.insert(i);
    }
    
    while (!vacant_seats.empty()) {
        int n = *next.begin();        
        
        next.erase(n);
        seats[n] = pl[n].front();       
        pl[n].pop_front();

        vacant_seats.erase(n);
        auto it = vacant_seats.upper_bound(n);
        if (it == vacant_seats.end()) {
            it = vacant_seats.begin();
        }
                
        if (!pl[n].empty()) {
            pl[*it].splice(pl[*it].end(), pl[n]);
            next.insert(*it);
        }
    }

    for (int num : seats) {
        printf("%d\n", num);
    }
}
