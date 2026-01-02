    std::cout<<"-------------------- Priority Queue--------------------"<<std::endl;
    std::priority_queue<int> pq;  // MAX-heap (default)

    int H1[] = {32, 10, 8, 1, 9, 7, 6}; // level-order array representation

    std::cout << "Inserting Values:" << std::endl;
    for (int x : H1)
    {
        std::cout << x << std::endl;
        pq.push(x); // insert
    }

    std::cout << "top (max): " << pq.top() << std::endl; // findMax

    int a = pq.top();  // get max
    pq.pop();          // deleteMax

    std::cout << "popped: " << a << std::endl;

    std::cout << "new top: " << pq.top() << std::endl;

    std::cout << "isEmpty: " << pq.empty() << std::endl;

![[Pasted image 20251215145116.png]]
