#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#include "exam.h"

Exam::Exam(){
    std::cout<<"exam"<<std::endl;
}

int Exam::LogTwo(int N){

    if(N == 0){
        return -1;
    }
    return  1;

}

int Exam::longestChain(){
    int N = 10000; //N is a number under 10000
    int bestStart = 1; //initial best start
    int chainSize = 0; //initial length
    int n; 
    for(int i = 2; i < N; i++){
        n = i;
        int tmp = 0;
        std::cout<<"n: "<<n<<std::endl;
        while(n != 1){
            if(n%2 == 0){
                n = n/2;
                tmp++;
                std::cout<<"n: "<<n<<std::endl;    
            } else{
                n = n*3+1;
                tmp++;
                std::cout<<"n: "<<n<<std::endl;
            }
            
        }     
       
        if(n == 1 && tmp > chainSize){
            chainSize = tmp;
            bestStart = i;
            tmp = 0;
        }
    }

    std::cout<<"the best starting number is: " << bestStart <<" with chain size = " << chainSize<<std::endl;
    return bestStart;
 
}

int Exam::pythagoreanTriplet() {
    int sum = 1000;
    for (int a = 1; a < sum / 3; ++a) {         
        for (int b = a + 1; b < sum / 2; ++b) { 
            int c = sum - a - b;                

            if (a*a + b*b == c*c) {
                std::cout << "a: " << a << ", b: " << b<< ", c: " << c << "  :  a+b+c = " << (a + b + c) << std::endl;

                return a * b * c;             
            }
        }
    }

    return -1; 
}

int Exam::myMethod( int N ) {
    int x = 0;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N/2; j++)
            for (int k = 1; k < N;){
                x++;
                k *= 2;
                std::cout<<"x: "<<x<<", k: "<<k<<", i:"<<i<<", j: "<<j<<std::endl;
            }
        
    

    return x;
}
int Exam::getNumberEqual(int x[], int n, int val){
    int occ = 0;
    
    for(int i = 0; i < n; i++){
        if(n == 0){
            return occ-1;
        }else{
            if(x[i] == val){
                occ++;
            }
        }    
    }
    return occ;
}


int Exam::myMethod1(int arr[], int arrSize){
    int x = 0;

    std::cout<<"arrSize: "<<arrSize<<std::endl; 
    for (int i = 0; i < arrSize/2; i++)
        for (int j = 0; j < arrSize; j++)
            for (int k = 0; k < arrSize; k++){
                x++;
                 std::cout<<"x: "<<x<<", k: "<<k<<", i:"<<i<<", j: "<<j<<std::endl;
                if (k==arrSize/2)
                    break;
            }
    return x;
}
std::string Exam::mostFrequentWord(std::string s)
{
    std::string s1 = "";
    int noOfWords = 1;

    // Først: lav alt til lowercase og fjern , .  (men behold mellemrum)
    for (std::size_t i = 0; i < s.length(); ++i) {
        char ch = s[i];

        if (ch == ' ')
        {
            noOfWords++;
            s1 += ' ';              // vi gemmer også mellemrum i s1
        }
        else if (ch == ',' || ch == '.')
        {
            continue;               // spring komma og punktum over
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            s1 += static_cast<char>(ch + 32); // A–Z -> a–z
        }
        else
        {
            s1 += ch;
        }
    }

    std::cout << "Words: " << noOfWords << std::endl;

    // Del s1 op i ord
    std::vector<std::string> arr(noOfWords);
    int index = 0;
    for (std::size_t i = 0; i < s1.length(); ++i) {
        std::string s2 = "";

        // NB: tjek længde først, så vi ikke går ud over arrayet
        while (i < s1.length() && s1[i] != ' ') {
            s2 += s1[i];
            ++i;
        }

        arr[index++] = s2;
    }

    // Sorter ordene
    std::sort(arr.begin(), arr.end());

    // Find mest forekommende ord
    std::string word = arr[0];
    int count = 1;
    int max = 0;

    for (int i = 1; i < noOfWords; ++i) {
        if (arr[i] == arr[i - 1]) {
            count++;
            if (count > max) {
                max = count;
                word = arr[i];
            }
        } else {
            count = 0;
        }
    }
    return word;
}

//Når et array bruges som parameter, bliver det automatisk til: int* nums, nums er derfor en pointer og ikke et reelt array

int Exam::mostFrequentNum(int nums[], int noOfNums)
{
    
    std::cout << "Nums: " << noOfNums << std::endl;


    // Sorter tallene
     std::sort(nums, nums + noOfNums);

    // Find mest forekommende ord
    int num = nums[0];
    int count = 1;
    int max = 0;

    for (int i = 1; i < noOfNums; ++i) {
        if (nums[i] == nums[i - 1]) {
            count++;
            std::cout<<"num: "<<nums[i]<<", count: "<<count<<std::endl;
            if (count > max) {
                max = count;
                num = nums[i];
            }
        } else {
            count = 1;
        }
    }
    return num;
}

int Exam::O_N_mostFrequentNum(int nums[], int n)
{
    // 1. Tælle-array (0..100)
    int count[101] = {0};   // alle sat til 0

    // 2. Gå igennem input-arrayet én gang
    for (int i = 0; i < n; ++i) {
        int x = nums[i];
        count[x]++;         // tæller forekomster
    }

    // 3. Find tallet med størst count
    int bestNum = 0;
    int bestCount = count[0];

    for (int v = 1; v <= 100; ++v) {
        if (count[v] > bestCount) {
            bestCount = count[v];
            bestNum   = v;
        }
    }

    // 4. Returnér resultatet
    return bestNum;
}

int Exam::recursiveSum(int N){
    if (N < 1){
        return 0;
    }
    return N + recursiveSum(N-1);
}

//he password always contains six digits [1-9] (zero is not a valid digit).
//• Digits must appear in ascending order (123567 is legal; 124563 is not).
//• The same digit may only occur once.
//Write an algorithm that can calculate the number of possible passwords for this system and state the number

int Exam::binom(int n, int k) {
    if (k == 0 || k == n) return 1;
    return binom(n - 1, k - 1) + binom(n - 1, k);
}

int Exam::evenSquares(int N){
    if (N < 1){
        return 0;
    }
    if(N%2 == 0){
        return N*N + evenSquares(N-2); //N is even
    }else{
        return evenSquares(N-1); //N is odd
    }
    
}
int Exam::oddSum(int N){
    if (N < 1){
        return 0;
    }
    if(N%2 != 0){
        return N + oddSum(N-2); //N is even
    }else{
        return oddSum(N-1); //N is odd
    }
    
}

bool Exam::isAnagram(const std::string& s1, const std::string& s2) {
    if (s1.size() != s2.size()) return false;

    int count[256] = {0};  // eller 26 hvis kun a–z

    for (size_t i = 0; i < s1.size(); ++i) {
        unsigned char c1 = s1[i];
        unsigned char c2 = s2[i];
        count[c1]++;
        count[c2]--;
    }

    for (int c : count) {
        if (c != 0) return false;
    }
    return true;
}