#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;
//Exercicio 1
vector<int> vet_to_vector(int* v, int n){
    vector<int> vec(n);

    copy(v, v + n, vec.begin());

    return vec;
}
//Exercicio 2
list<int> vet_to_flist(int* v, int n){
    list<int> lista;

    for (int i = 0; i < n; i++)
    {
        lista.push_back(v[i]);
    }
    return lista;
}
//Exercicio 3
stack<int> vet_to_stack(int* v, int n){
    stack<int> pilha;

    for(int i = n - 1; i >= 0; i--){
        pilha.push(v[i]);
    }
    return pilha;
}
//Exercicio 4
vector<int> list_concat(list<int>& list1,list<int>& list2){
    vector<int> result;
    
    result.reserve(list1.size() + list2.size());

    result.insert(result.end(), list1.begin(), list1.end());

    result.insert (result.end(), list2.begin(), list2.end());

    return result;
}
//Exercicio 5
bool check_brackets(string expression){
    stack<char> pilha;

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            pilha.push(c);  
        } 
        else if (c == ')' || c == ']' || c == '}') {
            if (pilha.empty()) {
                return false;  
            }

            char topo = pilha.top();
            pilha.pop();

            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{')) {
                return false;  
            }
        }
    }

    return pilha.empty();
}


int main(){
    // int v[] = {1, 2, 3, 4, 5};
    // int n = sizeof(v)/sizeof(v[0]);

    // vector<int> vec = vet_to_vector(v, n);
    // list<int> minhaLista = vet_to_flist(v, n);
    // stack<int> minhaPilha = vet_to_stack(v, n);
    
    // for(int i : minhaLista){
    //     cout << i << " ";
    // }

    // while(!minhaPilha.empty()){
    //     cout << minhaPilha.top() << " ";
    //     minhaPilha.pop();
    // }
    // cout << "\n";
    // return 0;
    // std::list<int> f1 = {1, 2, 3, 4};
    // std::list<int> f2 = {5, 6};

    // std::vector<int> vec = list_concat(f1, f2);

    // // Exibir os elementos do vetor resultante
    // for (int num : vec) {
    //     std::cout << num << " ";
    // }
    std::string expressao;
    std::cout << "Digite uma expressão: ";
    std::getline(std::cin, expressao);

    if (check_brackets(expressao)) {
        std::cout << "Expressão correta!" << std::endl;
    } else {
        std::cout << "Expressão incorreta!" << std::endl;
    }

    return 0;
}
