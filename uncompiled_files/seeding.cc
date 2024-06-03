#include <iostream> // declaration of cin and cout
#include <cstdlib> // void srand(unsigned int), int rand(void)

int main(){
    unsigned int seed;
    int n1, n2, n3;

    std::cout << "         ----RND Generator----         \n" << std::endl;
    std::cout << "Initialise the random number generator\n"
            << "Please type in a seed: ";
    std::cin >> seed; // read user input and write into variable, casted as 0 or int, if needed

    // initialise rnd gen with seed
    srand(seed);
    n1 = rand();
    n2 = rand();
    n3 = rand();
    
    std::cout << "\nThree random numbers based on seed " << seed << ":\n"
    << n1 << "   " << n2 << "   " << n3 << "   " << std::endl;


    


}