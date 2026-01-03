## Depth-First Search (DFS)
*Disse metoder er naturligt rekursive og kræver ingen ekstra datastruktur (udover træet)*

DFS bruger rekursion / stack, fordi den går:  så langt ned som muligt — før den går tilbage
	Stack = sidst-ind, først-ud

**Inorder: venstre → root → højre** 
*Pseudokode*
```
void inorder(Node* node) {
    if (node == nullptr) return;

    inorder(node->left);
    cout << node->value << " ";
    inorder(node->right);
}  
```
**Preorder: root → venstre → højre** 
*Pseudokode*
```
void preorder(Node* node) {
    if (node == nullptr) return;

    cout << node->value << " ";
    preorder(node->left);
    preorder(node->right);
}
```

**Postorder: venstre → højre → root**
*Pseudokode*
```
void postorder(Node* node) {
    if (node == nullptr) return;

    postorder(node->left);
    postorder(node->right);
    cout << node->value << " ";
}
```
## Breadth-First Search (BFS)
*kan ikke laves med direkte rekursion, og kræver en ekstern datastruktur i form af en queue*

##### **Level order** -->**niveau for niveau, bruger queue**  
(root → alle børn → alle børnebørn → …)

For at kunne gøre det, skal algoritmen huske:
*Hvilke noder står på tur til at blive besøgt — og i hvilken rækkefølge?”*

--> Dette er  en FIFO Queue 

**Pseudokode**
```
#include <queue>

void levelOrder(Node* root) {
    if (root == nullptr) return;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        cout << node->value << " ";

        if (node->left != nullptr)  q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
    }
}
```