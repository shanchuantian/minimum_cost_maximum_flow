#include <iostream>
#include <lemon/smart_graph.h>
#include <lemon/list_graph.h>
#include <lemon/lgf_reader.h>
#include <lemon/lgf_writer.h>
#include <lemon/network_simplex.h>
#include <time.h>
#include <sys/timeb.h>
#include <lemon/concepts/digraph.h>

using namespace lemon;
using namespace std;

int main() {
    // network simplex
    ListDigraph lg;
    ListDigraph::ArcMap<int> lower(lg);
    ListDigraph::ArcMap<int> upper(lg);
    ListDigraph::ArcMap<int> cost(lg);
    ListDigraph::NodeMap<int> sup(lg);
    digraphReader(lg, "gcase0_simplex_lemon.txt").arcMap("lowcap", lower).arcMap("upcap", upper).arcMap("cost", cost).nodeMap("sup", sup).run();
    NetworkSimplex<ListDigraph> ns(lg);

    // run once
    clock_t tbeg = clock();
    ns.lowerMap(lower);
    ns.upperMap(upper);
    ns.costMap(cost);
    ns.supplyMap(sup);
    //ns.supplyType(NetworkSimplex<ListDigraph>::LEQ); // 
    ns.run(); // lemon::NetworkSimplex<ListDigraph>::BLOCK_SEARCH 默认
    clock_t tend = clock();
    cout << ns.totalCost() << endl;
    cout << "time:" << tend - tbeg << "(ms)" << endl;

    // run many times
    /*for (int i = 0; i != 10000; ++i) {
        clock_t tbeg = clock();
        int protype = ns.lowerMap(lower).upperMap(upper).costMap(cost).supplyMap(sup).supplyType(NetworkSimplex<ListDigraph>::GEQ).run(lemon::NetworkSimplex<ListDigraph>::BLOCK_SEARCH);
        clock_t tend = clock();
        cout << ns.totalCost() << endl;
        cout << "time:" << tend - tbeg << "(ms)" << endl;
    }*/

    return 0;
}
