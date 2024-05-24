//https://codeforces.com/problemset/problem/734/C
//C. Anton and Making Potions

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

#define lld long long int

using namespace std;

void binary_search(vector <pair <lld, lld> > & spell_2, lld l, lld r, lld mana, pair <lld, lld> & result)
{
    if(l >= r)
        return;

    lld middle = l + (r - l) / 2;

    if(spell_2[middle].second <= mana){
        if(spell_2[middle].first > result.first 
            || (spell_2[middle].first == result.first && spell_2[middle].second < result.second))
            result = spell_2[middle];
        binary_search(spell_2, middle + 1, r, mana, result);
    }
    else
        binary_search(spell_2, l, middle, mana, result);
    return;
}

int main(void)
{
    lld n, m, k;
    cin >> n >> m >> k;
    lld x, s;
    cin >> x >> s;
    vector < pair <lld, lld> > spell_1(m);//mana second
    vector < pair <lld, lld> > spell_2(k);//mana second

    for(lld i = 0; i < m; ++i) 
        cin >> spell_1[i].first;
    for(lld i = 0; i < m; ++i)
        cin >> spell_1[i].second;
    for(lld i = 0; i < k; ++i)
        cin >> spell_2[i].first;
    for(lld i = 0; i < k; ++i)
        cin >> spell_2[i].second;

    lld min_time = n * x;
    lld sp1_time = x, sp1_mana;
    pair <lld, lld> potion2;
    binary_search(spell_2, 0, k, s, potion2);

    if(potion2.first >= n)
        min_time = 0;
    else
        for(lld i = 0; i < m; ++i)
            if(spell_1[i].second <= (s - potion2.second))
                sp1_time = min(sp1_time, spell_1[i].first);

    min_time = min(min_time, sp1_time * (n - potion2.first));

    for(lld i = 0; i < m; ++i){
        sp1_time = spell_1[i].first;
        sp1_mana = spell_1[i].second;

        if(sp1_mana > s)
            continue;

        lld remain_mana = max((lld)0, s - sp1_mana);
        potion2.first = potion2.second = 0;
        binary_search(spell_2, 0, k, remain_mana, potion2);
        min_time = min(min_time, (sp1_time * (n - potion2.first)));
    }
    cout << min_time << endl;

    return 0;
}

