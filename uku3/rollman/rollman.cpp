#include <bits/stdc++.h>
using namespace std;


struct Contact{
    int blightness;
    vector< set< Contact* > > cld_light;
    vector<Contact*> parent;
    vector<Contact*> children;
    Contact(){
        blightness = 0;
        cld_light = vector< set< Contact* > >(10);
        children = vector<Contact*>(0);
        parent = vector<Contact*>(0);
    }
    void add_cld(Contact* v){
        cld_light[0].insert(v);
        children.push_back(v);
        v->parent.push_back(this);
    }
};

typedef Contact* Cont_P;

struct Tree{
    vector<Contact> nodes;
    Tree(int n){
        nodes = vector<Contact>(n);
    }
    void add_cable(int u, int v){
        nodes[u].add_cld(&nodes[v]);
    }
    /* Bug
     *  This is wrong up r because this copies all of cld[x]
     */
    void change(int r, int x, int y){
        for(set<Cont_P>::iterator it = nodes[r].cld_light[x].begin(); it != nodes[r].cld_light[x].end(); it++){
            Contact cld = **it;
            while(&cld != &nodes[0]){
                cld.blightness = y;
                for(int i = 0; i < cld.parent.size(); i++){
                    cld.parent[i]->cld_light[y].insert(cld.parent[i]->cld_light[x].begin(),cld.parent[i]->cld_light[x].end());
                }
            }
        }
    }
    void count(int r, int x, int y){
        
    }
};
