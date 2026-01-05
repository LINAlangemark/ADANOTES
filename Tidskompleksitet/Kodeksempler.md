## O(1) — konstant tid

```
int getFirst(int[] a) {
	return a[0]; 
}
```

## O(log n) — logaritmisk (binær søgning)

```
int binarySearch(int[] a, int x) {
    int l = 0, r = a.length - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) return mid;
        if (a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

```
## O(√n) -- Kvadratisk

```
boolean hasFactor(int n) {
    for (int i = 2; i <= Math.sqrt(n); i++) {
        if (n % i == 0) return true;
    }
    return false;
}

```

## O(n) — lineær

```
int sum(int[] a) {
    int s = 0;
    for (int x : a) s += x;
    return s;
}

```

## O(n log n) — klassisk sortering (merge sort-idé)

```
void mergeSort(int[] a) {
    if (a.length <= 1) return;
    // split -> sortér halvdele -> læg sammen (merge)
}
```

## O(n²) — to nestede løkker

```
void printPairs(int[] a) {
    for (int i = 0; i < a.length; i++) {
        for (int j = 0; j < a.length; j++) {
            System.out.println(a[i] + "," + a[j]);
        }
    }
}

```

## O(n³) — tre nestede løkker

```
void tripleLoop(int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                ; // gør noget
}

```

## O(2ⁿ) — rekursion med to grene (subset / fib)

```
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

```

## O(n!) — alle permutationer

```
void permute(String s, String built) {
    if (s.isEmpty()) {
        System.out.println(built);
        return;
    }
    for (int i = 0; i < s.length(); i++) {
        permute(s.substring(0,i) + s.substring(i+1),
                built + s.charAt(i));
    }
}

```

