#include <iostream>
#include <string>
#include <graphviz/gvc.h>

using namespace std;

int main() {
    // Initialize graph
    Agraph_t *g;
    GVC_t *gv;
    gv = gvContext();
    g = agopen((char*)"G", Agstrictundirected, 0);

    // Create nodes
    Agnode_t* nodes[10];
    for(int i = 0; i < 10; i++) {
        string label = "Node " + to_string(i);
        nodes[i] = agnode(g, NULL, true);
        agsafeset(nodes[i], (char*)"label", label.c_str(), "");
    }

    // Create edges
    for(int i = 0; i < 5; i++) {
        agedge(g, nodes[i], nodes[2 * i + 1], NULL, true);
        agedge(g, nodes[i], nodes[2 * i + 2], NULL, true);
    }

    // Layout graph
    gvLayout(gv, g, "dot");

    // Render graph
    FILE *fp;
    fp = fopen("binary_tree.png", "w");
    gvRender(gv, g, "png", fp);
    fclose(fp);

    // Free graph
    agclose(g);
    gvFreeContext(gv);

    return 0;
}
