## Strongly Connected Component:

### Overview:
- Topo sort
- Reverse edge
- DFS

### Proof:
All strongly connected components of the graph form a DAG. If not there would have been a cycle and entire graph would have been a SCC.

C1 -> C2 -> C3

In a DAG we have a vertex with no incoming edge and a vertex with no outgoing edge. Lets call them source(C1) and sink(C3) respectively.
Also, we can see that if we do DFS, end time of a node from source will always be more than that of sink.

Hence we can see that if do a toposort we get to know the source.
And then if we reverse the graph C1 <- C2 <-C3 and do DFS according to the output of toposort, we will get our SCC from each DFS.

reference: https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/tutorial/