```cpp
// Single argument
template <typename T>
void print(const char* name, const T& value) {
    if constexpr (std::is_same<T, std::vector<int>>::value) {
        std::cout << name << "={";
        for (size_t i = 0; i < value.size(); ++i) {
            std::cout << value[i];
            if (i + 1 < value.size()) std::cout << ",";
        }
        std::cout << "}\n";
    } else {
        std::cout << name << "=" << value << "\n";
    }
}

// Multiple arguments
template <typename T, typename... Args>
void print(const char* name, const T& value, const char* names_rest, const Args&... rest) {
    if constexpr (std::is_same<T, std::vector<int>>::value) {
        std::cout << name << "={";
        for (size_t i = 0; i < value.size(); ++i) {
            std::cout << value[i];
            if (i + 1 < value.size()) std::cout << ",";
        }
        std::cout << "}, ";
    } else {
        std::cout << name << "=" << value << ", ";
    }
    print(names_rest, rest...);
}

// Macro to capture variable names
#define PRINT(...) print(#__VA_ARGS__, __VA_ARGS__)
```

Eksempler:
```cpp
  PRINT(N);
  return ((N%2 && N<=1)) ? N : task_21(N-2);
```

```cpp
  PRINT(N);
  PRINT(task_17(5));
    int X = 5, K = 10, q = 99;
    char c = 'A';
    std::string s = "hello";
    std::vector<int> arr = {1,2,3,4};

    PRINT(X, K);        // X=5, K=10
    PRINT(X, q, K);     // X=5, q=99, K=10
    PRINT(c, s);        // c=A, s=hello
    PRINT(arr);         // arr={1,2,3,4}
```