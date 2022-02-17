// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <future>

void fibonacci(int terms)
{
    int x = 1;
    int y = 1;
    int z = 0;
    for (int i = 0; i < terms; i++) {
        z = x + y;
        y = x;
        x = z;

        std::cout << z;
        std::cout << "\n";
    }
    return;
}

void findPrimes(int limit)
{
    int i;
    int j;
    std::vector<int> primes = {2};
    for (i = 3; i <= limit; i++) {
        bool isPrime = true;
        if (i > 10) {
            if (i % 10 == 0 || i % 10 == 2 || i % 10 == 4 || i % 10 == 5 || i % 10 == 6 || i % 10 == 8) {
                isPrime = false;
            }
        }
        if (isPrime) {
            for (j = 2; j < i / 2; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime) {
            primes.push_back(i);
        }
    }
    int k = primes.size();
    for (int l = 0; l < k; l++) {
        std::cout << primes[l];
        std::cout << "\n";
    }
    std::cout << primes.size();
    return;
}

std::vector<int> findPrimesThreading(int limit, bool ascend)
{
    std::vector<int> primes = {2};
    int i;
    int m;
    int j;
    if (ascend) {
        i = 3;
        m = limit / 2;
     }
    else {
        i = limit / 2;
        m = limit;
    }
    for (i; i < m; i++) {
        bool isPrime = true;
        if (i > 10) {
            if (i % 10 == 0 || i % 10 == 2 || i % 10 == 4 || i % 10 == 5 || i % 10 == 6 || i % 10 == 8) {
                isPrime = false;
            }
        }
        if (isPrime) {
            for (j = 2; j < i / 2; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime) {
            primes.push_back(i);
        }
    }

    return primes;
}

void twoThreadPrimeSearch(int limit) 
{
    std::vector<int> firstVec;
    std::vector<int> secondVec;
    std::cout << "Starting threads...\n";
    auto future1 = async(findPrimesThreading, limit , true);
    auto future2 = async(findPrimesThreading, limit, false);
    std::cout << "Getting data from thread 1\n";
    firstVec = future1.get();
    std::cout << "Getting data from thread 2\n";
    secondVec = future2.get();

    std::cout << "Combining vectors...\n";
    std::vector<int> AB;
    AB.reserve(firstVec.size() + secondVec.size()); // preallocate memory
    AB.insert(AB.end(), firstVec.begin(), firstVec.end());
    AB.insert(AB.end(), secondVec.begin(), secondVec.end());

    std::cout << "Printing Primes...\n";
    //std::sort(AB.begin(), (AB.begin() + (AB.size() / 2)));
    int x = AB.size();
    for (int l = 0; l < x; l++) {
        std::cout << AB[l];
        std::cout << "\n";
    }
    std::cout << AB.size();

}




std::vector<int> findPrimesBetween(int start, int end)
{
    std::vector<int> primes = {};
    int i;
    int j;

    for (i = start; i < end; i++) {
        bool isPrime = true;
        if (i < 2) {
            isPrime = false;
        }
        if (i > 10) {
            if (i % 10 == 0 || i % 10 == 2 || i % 10 == 4 || i % 10 == 5 || i % 10 == 6 || i % 10 == 8) {
                isPrime = false;
            }
        }
        if (isPrime) {
            for (j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (i == 2) {
            isPrime = true;
        }
        if (isPrime) {
            primes.push_back(i);
        }
    }
    /*
    int k = primes.size();
    for (int l = 0; l < k; l++) {
        std::cout << primes[l];
        std::cout << "\n";
    }
    std::cout << primes.size();*/

    return primes;
}

void threadPrimeSearch()
{
    std::vector<int> vec1;
    std::vector<int> vec2;
    std::vector<int> vec3;
    std::vector<int> vec4;
    std::vector<int> vec5;
    std::vector<int> vec6;
    std::vector<int> vec7;
    std::vector<int> vec8;
    std::vector<int> vec9;
    std::vector<int> vec10;
    std::cout << "Starting threads...\n";
    auto future1 = async(findPrimesBetween, 1, 1000000);
    auto future2 = async(findPrimesBetween, 1000001,2000000);
    auto future3 = async(findPrimesBetween, 2000001, 3000000);
    auto future4 = async(findPrimesBetween, 3000001, 4000000);
    auto future5 = async(findPrimesBetween, 4000001, 5000000);
    auto future6 = async(findPrimesBetween, 5000001, 6000000);
    auto future7 = async(findPrimesBetween, 6000001, 7000000);
    auto future8 = async(findPrimesBetween, 7000001, 8000000);
    auto future9 = async(findPrimesBetween, 8000001, 9000000);
    auto future10 = async(findPrimesBetween, 9000001, 10000000);
    std::cout << "Getting data from thread 1\n";
    vec1 = future1.get();
    std::cout << "Getting data from thread 2\n";
    vec2 = future2.get();
    std::cout << "Getting data from thread 3\n";
    vec3 = future3.get();
    std::cout << "Getting data from thread 4\n";
    vec4 = future4.get();
    std::cout << "Getting data from thread 5\n";
    vec5 = future5.get();
    std::cout << "Getting data from thread 6\n";
    vec6 = future6.get();
    std::cout << "Getting data from thread 7\n";
    vec7 = future7.get();
    std::cout << "Getting data from thread 8\n";
    vec8 = future8.get();
    std::cout << "Getting data from thread 9\n";
    vec9 = future9.get();
    std::cout << "Getting data from thread 10\n";
    vec10 = future10.get();

    std::cout << "Combining vectors...\n";
    std::vector<int> vec;
    vec.reserve(vec1.size() + vec2.size() + vec3.size() + vec4.size() + vec5.size() + vec6.size() + vec7.size() + vec8.size() + vec9.size() + vec10.size()); // preallocate memory
    vec.insert(vec.end(), vec1.begin(), vec1.end());
    vec.insert(vec.end(), vec2.begin(), vec2.end());
    vec.insert(vec.end(), vec3.begin(), vec3.end());
    vec.insert(vec.end(), vec4.begin(), vec4.end());
    vec.insert(vec.end(), vec5.begin(), vec5.end());
    vec.insert(vec.end(), vec6.begin(), vec6.end());
    vec.insert(vec.end(), vec7.begin(), vec7.end());
    vec.insert(vec.end(), vec8.begin(), vec8.end());
    vec.insert(vec.end(), vec9.begin(), vec9.end());
    vec.insert(vec.end(), vec10.begin(), vec10.end());

    std::cout << "Printing Primes...\n";
    int x = vec.size();
    for (int l = 0; l < x; l++) {
        std::cout << vec[l];
        std::cout << "\n";
    }
    std::cout << vec.size();
    return;
}

void multithreadPrimes(int ths, int start, int end)
{
    int rng = end - start +1;
    int partitionLength = rng / ths;
    int newPoint = start;
    std::vector<int> points;
    std::vector<std::future<std::vector<int>>> futures;
    std::vector<int> primes;
    futures.reserve(ths);

    for (int x = 0; x < ths; x++) {
        newPoint += partitionLength;
        if (x == 0) {
            points.push_back(start);
        }
        if (newPoint > end) {
            std::cout << newPoint;
            points.push_back(end);
            break;
        }
        else {
            points.push_back(newPoint);
        }

    }
    for (int y = 0; y < ths; y++) {

        futures.push_back(async(findPrimesBetween, points[y], points[y + 1]));

    } 
    int primesSize = 0;
    for (int z = 0; z < futures.size(); z++) {
        std::cout << "Getting data from thread " << z << "\n";
        std::vector<int> a = futures[z].get();
        primesSize += a.size();
        primes.reserve(primesSize);
        primes.insert(primes.end(), a.begin(), a.end());
    }

    /*std::cout << "Printing Primes...\n";
    int x = primes.size();
    for (int l = 0; l < x; l++) {
        std::cout << primes[l];
        std::cout << "\n";
    }*/
    std::cout << primes.size();
    return;
}


int main()
{
    //fibonacci(15);
    //findPrimes(10);
    //twoThreadPrimeSearch(1000000);
    //findPrimesBetween(1, 1000000);
    //threadPrimeSearch();
    multithreadPrimes(24,1,1000000);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
