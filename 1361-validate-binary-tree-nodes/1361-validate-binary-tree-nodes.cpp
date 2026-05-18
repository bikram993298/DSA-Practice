class Solution {
public:
// valid binary tree must satisfy:

// 1. One root
// 2. No node has 2 parents
// 3. No cycle
// 4. All nodes connected
// 5. edges = n - 1
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool Union(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        // cycle detected
        if (pu == pv)
            return false;

        parent[pv] = pu;

        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        vector<int> indegree(n, 0);

        int edges = 0;

        for (int i = 0; i < n; i++) {

            // left child
            if (leftChild[i] != -1) {

                int child = leftChild[i];

                // node cannot have 2 parents
                indegree[child]++;

                if (indegree[child] > 1)
                    return false;

                // cycle check
                if (!Union(i, child))
                    return false;

                edges++;
            }

            // right child
            if (rightChild[i] != -1) {

                int child = rightChild[i];

                indegree[child]++;

                if (indegree[child] > 1)
                    return false;

                if (!Union(i, child))
                    return false;

                edges++;
            }
        }

        // valid tree must have exactly n-1 edges
        if (edges != n - 1)
            return false;

        return true;
    }
};

// For a graph to be a **valid binary tree**, these are the conditions:

// ---

// # ✅ Condition 1: Exactly One Root

// A root is a node with **no parent**.

// So:

// * only ONE node should have indegree = 0

// Example:

// ```text id="3e6clx"
// 0
// / \
// 1  2
// ```

// `0` has no parent → root ✅

// If multiple roots exist ❌

// ---

// # ✅ Condition 2: Every Node Has At Most One Parent

// No node can be child of two nodes.

// Invalid:

// ```text id="7v6r40"
// 0 -> 2
// 1 -> 2
// ```

// Node `2` has 2 parents ❌

// Condition:

// ```text id="swj4zs"
// indegree[node] <= 1
// ```

// ---

// # ✅ Condition 3: No Cycle

// Tree cannot loop.

// Invalid:

// ```text id="7vf9k9"
// 0 -> 1
// 1 -> 0
// ```

// Cycle ❌

// In Union Find:

// ```cpp id="0pc0z6"
// if(find(u) == find(v))
//     return false;
// ```

// ---

// # ✅ Condition 4: Fully Connected

// All nodes must belong to one component.

// Equivalent condition for tree:

// If:

// * no cycle
// * connected

// then edges must be:

// \text{edges} = n-1

// If edges are smaller → disconnected
// If larger → cycle

// ---

// # Final Summary

// A valid binary tree must satisfy:

// ```text id="7j9l7m"
// 1. One root
// 2. No node has 2 parents
// 3. No cycle
// 4. All nodes connected
// 5. edges = n - 1
// ```
