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
        { "Beauty", "Financ", "Housek", "Charac"}
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

void printMatrix(double (&mat)[4][6]){
    std::cout << "\t\t";
    for (int i = 0; i < 4; i++){
        std::cout << "\t" <<  names_parametrs[0][i] << "\t";
    }
    std::cout << "\tSUM   \t\tNORMAL\n";
    for (int i = 0; i < 4; i++){
        std::cout << names_parametrs[0][i] << "\t";
        for(int j = 0; j < 6; j++){
            std::cout << "\t" << mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void printMatrixKreet(double (&mat)[4][6]){
    std::cout << "\t\t";
    for (int i = 0; i < 4; i++){
        std::cout << "\t" <<  names_parametrs[1][i] << "\t";
    }
    std::cout << "\tSUM   \t\tNORMAL\n";
    for (int i = 0; i < 4; i++){
        std::cout << names_parametrs[1][i] << "\t";
        for(int j = 0; j < 6; j++){
            std::cout << "\t" << mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void printMatrix4x4(int (&mat)[4][4]){
    std::cout << "\t\t";
    for (int i = 0; i < 4; i++){
        std::cout << "\t" <<  names_parametrs[1][i] << "\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < 4; i++){
        std::cout << names_parametrs[0][i] << "\t";
        for(int j = 0; j < 4; j++){
            std::cout << "\t\t"<< mat[i][j] << "\t" ;
        }
        std::cout << std::endl;
    }
}
double soglasov(double Lmax, double SI){
    double IS = (Lmax - 4)/3;
    double OS = IS/SI;
    return OS;
}
double LmaxCounter(double (&mat)[4][6]){
    double Lmax = 0;
    double sumCol[4] = {0, 0, 0, 0};
    for (int col = 0; col < 4; col++){
        for (int raw = 0; raw < 4; raw++){
            sumCol[col] += mat[raw][col];
        }
    }
    for(int i = 0; i < 4; i++){
        Lmax += (sumCol[i] * mat[i][5]);
    }
    double OS = soglasov(Lmax, 0.9);
    return OS;
}
void Task1(){

    size_t major_col = 0;
    std::cout << "Major rate: " << names_parametrs[1][0] << std::endl;
    double Financial = 0.2;
    double Housekeeping = 0.5;
    double Character = 0.4;
    printMatrix4x4(objects_rate_task1);
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
    std::cout << "Normalizes: \n";
    std::cout << "\t\t";
    for (int i = 0; i < 4; i++){
        std::cout << "\t" <<  names_parametrs[1][i] << "\t";
    }
    std::cout << "\n";
    for (size_t raws = 0; raws < 4; raws++){
        std::cout << names_parametrs[0][raws] << "\t";
        for(size_t col = 0; col < 4; col++){
            maxSum[raws]+= normolized_task1[raws][col];
            std::cout << std::fixed << std::setprecision(3) << "\t" <<normolized_task1[raws][col] << "\t";
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
}

void Task2(){
    std::cout << "Main Housekeeping && Character;\n\n";
    size_t HouseIndex = 2;
    size_t CharIndex = 3;
    int best_x = 0;
    int best_y = 0;
    std::string name;
    for(size_t i = 0; i < 4; i++) {
        if( objects_rate_task1[i][HouseIndex] >= best_x && objects_rate_task1[i][CharIndex] >= best_y ){
            best_x = objects_rate_task1[i][HouseIndex];
            best_y = objects_rate_task1[i][CharIndex];
        }
    }
    for(size_t i = 0; i < 4; i++) {
        std::cout << names_parametrs[0][i] << "  (" << objects_rate_task1[i][HouseIndex] << "; " << objects_rate_task1[i][CharIndex] << ")\n";
        if(objects_rate_task1[i][HouseIndex] == best_x && objects_rate_task1[i][CharIndex] == best_y){
            name = names_parametrs[0][i];
        }
    }
    std::cout << "Best alternative: " << name << "\n\n";
}

void Task3(){
    double weights_from_gamma[4] = {0, 0, 0, 0};
    double weights_from_gamma_normal[4];
    printMatrix4x4(objects_rate_task1);
    std::cout << "\nNormalised:\n";
    normalisation();
    std::cout << "\t\t";
    for (int i = 0; i < 4; i++){
        std::cout << "\t" <<  names_parametrs[1][i] << "\t";
    }
    std::cout << "\n";
    for(size_t i = 0; i < 4; i++){
        std::cout << names_parametrs[0][i] << "\t";
        for(size_t j = 0; j < 4; j++){
            std::cout << "\t" << normalized_4[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\nGamma: \n";
    std::cout << "\t\t";
    for (int i = 0; i < 4; i++){
        std::cout << "\t" <<  names_parametrs[1][i] << "\t";
    }
    std::cout << "\n";
    for(size_t i = 0; i < 4; i++){
        std::cout << names_parametrs[1][i] << "\t";
        for(size_t j = 0; j < 4; j++){
            std::cout << "\t" << gamma_[i][j] << "\t";
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
        std::cout << names_parametrs[0][col] << "\t" << weights_from_gamma[col] <<"\n";
    }
    std::cout << "\n";
    std::cout << "Weights gamma normalized:\n";

    for(size_t col = 0; col < 4; col++){
        weights_from_gamma_normal[col] = weights_from_gamma[col] / gammaMax;
        std::cout << names_parametrs[0][col] << "\t" << weights_from_gamma_normal[col] <<"\n";
    }
    std::cout << "\nResult:\n";
    double result[4] = {0, 0, 0, 0};
    for(size_t raw = 0; raw < 4; raw++){
        for(size_t col = 0; col < 4; col++){
            result[raw]+= normalized_4[raw][col] * weights_from_gamma_normal[col];
        }
        std::cout << names_parametrs[0][raw] << "\t" << result[raw] <<"\n";
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
}

void Task4(){
    double SI = 0.9;      // const

    double mat_1[4][6] ={ //beauty
            {1,       0.5,    7,  4,    0, 0},
            {2,       1,      7,  3,    0, 0},
            {0.1423,  0.1423, 1,  0.5,  0, 0},
            {0.25,    0.33,   2,  1,    0, 0}
    };

    double mat_2[4][6] ={  //financial
            {1,    0.25,  0.33,    2, 0, 0},
            {4,  1,  2, 7, 0, 0},
            {3, 0.5,  1,    3,  0, 0},
            {0.5,    0.1423,  0.33,    1,    0, 0}
    };
    double mat_3[4][6] ={ //housekeeping
            {1,       2,  0.2, 0.33, 0, 0},
            {0.5,    1, 0.1423,  0.2, 0, 0},
            {5,       7,    1,    2, 0, 0},
            {3,  5,    0.5,    1, 0, 0}
    };
    double mat_4[4][6] ={ //character
            {1,    0.25,  0.33, 2, 0, 0},
            {4,    1,    2,    7, 0, 0},
            {3,    0.5, 1,    5, 0, 0},
            {0.5, 0.1423, 0.2,  1, 0, 0}
    };
    double kreet[4][6] ={ //beauty
            {1,      3,    5,    7,    16,    0.507},
            {0.33,   1,    3,    5,    9.33,  0.295},
            {0.2,   0.33,  1,    3,    12.2,  0.144},
            {0.14,  0.2,   0.33, 1,    1.676, 0.053}
    };

    for (int raw = 0; raw < 4; raw++){
        for (int col = 0; col < 4; col++){
            mat_1[raw][4] += mat_1[raw][col];
            mat_2[raw][4] += mat_2[raw][col];
            mat_3[raw][4] += mat_3[raw][col];
            mat_4[raw][4] += mat_4[raw][col];
        }
    }

    double sumCol1[4] = {0,0,0,0};
    double sumCol2[4] = {0,0,0,0};
    double sumCol3[4] = {0,0,0,0};
    double sumCol4[4] = {0,0,0,0};
    for (int raw = 0; raw < 4; raw++){
        for (int col = 0; col < 4; col++){
            sumCol1[raw] += mat_1[raw][col];
            sumCol2[raw] += mat_2[raw][col];
            sumCol3[raw] += mat_3[raw][col];
            sumCol4[raw] += mat_4[raw][col];
        }
    }
    double maxSum1 =0;
    double maxSum2 =0;
    double maxSum3 =0;
    double maxSum4 =0;
    for (int iter = 0; iter < 4; iter++){
        maxSum1 += sumCol1[iter];
        maxSum2 += sumCol2[iter];
        maxSum3 += sumCol3[iter];
        maxSum4 += sumCol4[iter];
    }
    for (int iter = 0; iter < 4; iter++){
        mat_1[iter][5] = sumCol1[iter] / maxSum1;
        mat_2[iter][5] = sumCol2[iter] / maxSum2;
        mat_3[iter][5] = sumCol3[iter] / maxSum3;
        mat_4[iter][5] = sumCol4[iter] / maxSum4;
    }
    printMatrix(mat_1);
    std::cout << "OC: " << LmaxCounter(mat_1) << "\n\n";
    printMatrix(mat_2);
    std::cout << "OC: " << LmaxCounter(mat_2) << "\n\n";
    printMatrix(mat_3);
    std::cout << "OC: " << LmaxCounter(mat_3) << "\n\n";
    printMatrix(mat_4);
    std::cout << "OC: " << LmaxCounter(mat_4) << "\n\n";
    printMatrixKreet(kreet);
    std::cout << "OC: " << LmaxCounter(kreet) << "\n\n";

    double result_matrix_normal[4][4];
    for(int raw = 0; raw < 4; raw++){
        result_matrix_normal[raw][0] = mat_1[raw][5];
        result_matrix_normal[raw][1] = mat_2[raw][5];
        result_matrix_normal[raw][2] = mat_3[raw][5];
        result_matrix_normal[raw][3] = mat_4[raw][5];
    }


    std::cout << "\nResult:\n";
    double result[4] = {0, 0, 0, 0};
    for(size_t raw = 0; raw < 4; raw++){
        for(size_t col = 0; col < 4; col++){
            result[raw]+= result_matrix_normal[raw][col] * kreet[col][5];
        }
        std::cout << names_parametrs[0][raw] << "\t" << result[raw] <<"\n";
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
}
int main() {
    std::cout << "\n=====================================[ Task1 ]=====================================\n\n";
    Task1();
    std::cout << "\n=====================================[ Task2 ]=====================================\n\n";
    Task2();
    std::cout << "=====================================[ Task3 ]=====================================\n\n";
    Task3();
    std::cout << "\n=====================================[ Task4 ]=====================================\n\n";
    Task4();

    return 0;
}
