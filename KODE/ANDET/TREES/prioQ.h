#ifndef PRIO_Q_H
#define PRIO_Q_H

#include <vector>

class PrioQ
{
public:
    bool isEmpty() const;
    int top() const;

    void push(int x);
    void pop();

    void changePriority(int fromP, int toP);

private:
    std::vector<int> heap;

    // helper-funktioner
    void percolateUp(int index);
    void percolateDown(int index);

    int parent(int i) const { return (i - 1) / 2; }
    int left(int i)   const { return 2 * i + 1; }
    int right(int i)  const { return 2 * i + 2; }
};

#endif
