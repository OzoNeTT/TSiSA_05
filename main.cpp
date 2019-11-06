#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
int objects_rate_task1[4][4] = {{4, 3, 3, 3},
                                {5, 5, 2, 5},
                                {2, 4, 5, 4},
                                {3, 2, 4, 2}};

std::string names_parametrs[2][4] = {
        { "Tatiana", "Larisa", "Natalja", "Olga"},
        { "Beauty", "Financial", "Housekeeping", "Character"}
};
double normolized_task1[4][4];
double normalized_4[4][4];
double gamma_[4][4] = {
        {0, 1, 0.5, 0.5},
        {0, 0, 0, 0},
        {0.5, 0, 0, 0},
        {0.5, 1, 1, 0}
};
void normalisation(){
    int sumColumn[4] = {0,0,0,0};
    for (size_t col = 0; col < 4; col++) {
        for(size_t raws = 0; raws < 4; raws++) {
            sumColumn[col] += objects_rate_task1[raws][col];
        }
    }
    for(size_t raws = 0; raws < 4; raws++) {
        for (size_t col = 0; col < 4; col++) {
            normalized_4[raws][col] = (double)objects_rate_task1[raws][col] / sumColumn[col];
        }
    }

}
double normal(size_t raw, size_t col) {
    int Amin = 10;
    int Amax = 0;
    int Aij = objects_rate_task1[raw][col];
    for (size_t raws = 0; raws < 4; raws++) {
        if (objects_rate_task1[raws][col] < Amin) {
            Amin = objects_rate_task1[raws][col];
        }
        if (objects_rate_task1[raws][col] > Amax) {
            Amax = objects_rate_task1[raws][col];
        }
    }
    double result = ((double) (Aij - Amin) / (Amax - Amin));
    return result;
}

int main() {
    std::cout << "========Task1=========\n\n";

    size_t major_col = 0;
    std::cout << "Major rate: " << names_parametrs[1][0] << std::endl;
    double Financial = 0.2;
    double Housekeeping = 0.5;
    double Character = 0.4;
    for(size_t i = 0; i < 4; i++){
        for(size_t j = 0; j < 4; j++){
            std::cout << objects_rate_task1[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    for (size_t raws = 0; raws < 4; raws++){
        for(size_t col = 0; col < 4; col++){
            if(col != major_col)
                normolized_task1[raws][col] = normal(raws, col);
            else{
                normolized_task1[raws][col] = objects_rate_task1[raws][col];
            }
        }
    }
    double maxSum[4] ={0, 0, 0, 0};
    double maxSumRaw = 0;
    size_t maxRawIndex;
    for (size_t raws = 0; raws < 4; raws++){
        for(size_t col = 0; col < 4; col++){
            maxSum[raws]+= normolized_task1[raws][col];
            std::cout << std::fixed << std::setprecision(3) << normolized_task1[raws][col] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "\n";
    for (size_t i = 0; i < 4; i++){
        if(maxSum[i] > maxSumRaw){
            maxSumRaw = maxSum[i];
            maxRawIndex = i;
        }
    }

    std::cout << "Best alternative: " << names_parametrs[0][maxRawIndex] << std::endl;
    std::cout << "========Task2=========\n\n";

    std::cout << "Main Housekeeping && Character;\n\n";
    size_t HouseIndex = 2;
    size_t CharIndex = 3;
    for(size_t i = 0; i < 4; i++) {
        std::cout << names_parametrs[0][i] << "  (" << objects_rate_task1[i][HouseIndex] << "; " << objects_rate_task1[i][CharIndex] << ")\n";
    }

    std::cout << "========Task3=========\n\n";
    double weights_from_gamma[4] = {0, 0, 0, 0};
    double weights_from_gamma_normal[4];
    for(size_t i = 0; i < 4; i++){
        for(size_t j = 0; j < 4; j++){
            std::cout << objects_rate_task1[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\nNormalised:'\n";
    normalisation();
    for(size_t i = 0; i < 4; i++){
        for(size_t j = 0; j < 4; j++){
            std::cout << normalized_4[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\nGamma: \n";

    for(size_t i = 0; i < 4; i++){
        for(size_t j = 0; j < 4; j++){
            std::cout << gamma_[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    double gammaMax = 0;
    for(size_t raws = 0; raws < 4; raws++){
        for(size_t col = 0; col < 4; col++){
            weights_from_gamma[raws] += gamma_[raws][col];
            gammaMax += gamma_[raws][col];
        }

    }

    std::cout << "Weights gamma:\n";
    for(size_t col = 0; col < 4; col++){
        std::cout << weights_from_gamma[col] <<"\t";
    }
    std::cout << "\n";
    std::cout << "Weights gamma normalized:\n";

    for(size_t col = 0; col < 4; col++){
        weights_from_gamma_normal[col] = weights_from_gamma[col] / gammaMax;
        std::cout << weights_from_gamma_normal[col] <<"\t";
    }
    std::cout << "\nResult:\n";
    double result[4] = {0, 0, 0, 0};
    for(size_t raw = 0; raw < 4; raw++){
        for(size_t col = 0; col < 4; col++){
            result[raw]+= normalized_4[raw][col] * weights_from_gamma_normal[col];
        }
        std::cout << result[raw] <<"\t";
    }
    std::cout << "\n";
    double maxFromRes = 0;
    size_t maxFromResIndex = 0;
    for(size_t iter = 0; iter < 4; iter++){
        if(result[iter] > maxFromRes){
            maxFromRes = result[iter];
            maxFromResIndex = iter;
        }
    }

    std::cout << "Winner: " << names_parametrs[0][maxFromResIndex] << std::endl;
    std::cout << "========Task4=========\n\n";
    return 0;
}
